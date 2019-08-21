#include <Servo.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>

#define pinCamara 11

//Funcionamiento del LCD
LiquidCrystal_I2C lcd(0x27, 2 ,1, 0, 4, 5 ,6, 7);

//Declaramos la variable para controlar el servo
Servo servoMotor;

//Varibale para varificar registro
byte seguridad = 0;

//Funcionamiento del keypad
const byte Filas = 4;
const byte Columnas = 4;
char keys[Filas][Columnas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
byte pinesFilas[Filas] = {9,8,7,6};
byte pinesColumnas[Columnas] = {5,4,3,2};
Keypad teclado = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas, Filas, Columnas);
char tecla=0;
int i=0;
char password[4];
char initial_password[4],new_password[4];

//Funcion para cambiar la contraseña
void change(){
  int j=0;
  lcd.clear();
  lcd.print("Current Password");
  lcd.setCursor(0,1);
  while(j<4){
     char key=teclado.getKey();
     if(key){
        new_password[j++]=key;
        lcd.print(key);
     }
     key=0; 
  }
  delay(500);
  if((strncmp(new_password, initial_password, 4))){ //Esta linea estima si ambas contraseñas son diferentes
    lcd.clear();
    lcd.print("Wrong Password");
    lcd.setCursor(0,1);
    lcd.print("Try Again");
    delay(1000);
  }
  else{
    j=0;
    lcd.clear();
    lcd.print("New Password:");
    lcd.setCursor(0,1);
    while(j<4){
      char key=teclado.getKey();
      if(key)
      {
        initial_password[j]=key;
        lcd.print(key);
        EEPROM.write(j,key);
        j++;
      }
    }
    lcd.print("Pass Changed");
    delay(1000);
    lcd.clear();
    lcd.print("New Passaword");
    lcd.setCursor(0,1);
    lcd.print("for EDGAR");
    delay(1000);
  }
  lcd.clear();
  lcd.print("Enter Password");
  lcd.setCursor(0,1);
  tecla=0;
}

//Funcion para crear la clave (Esta funcion solo se tiene que ejecutar una vez)
void initialpassword(){
  for(int j=0;j<4;j++)
    EEPROM.write(j, j+49);
  for(int j=0;j<4;j++)
    initial_password[j]=EEPROM.read(j);
} 


void setup() {

  pinMode(pinCamara, OUTPUT);
  digitalWrite(pinCamara, LOW);
  // put your setup code here, to run once:
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  
  servoMotor.attach(10);
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Proyecto 2019");
  lcd.setCursor(0,1);
  lcd.print("Green Box Device");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter Password");
  lcd.setCursor(0,1);
  initialpassword();
}
 
void loop() {
  tecla = teclado.getKey();
  if(tecla == '#'){ //Opcion para cambiar la clave
      change();
    }
  if(tecla == 'A' && seguridad == 1){
     //Prueba para el funcionamiento del Servomotor (Habiendose registrado) ABRIR
     lcd.clear();
     lcd.print("Abriendo Servo");
     servoMotor.write(90);
     delay(1000);
     servoMotor.write(180);
     delay(1000);
     lcd.clear();
     lcd.print("Otra operacion?");
     lcd.setCursor(0,1);
     tecla=0;
  }
  if(tecla == 'B' && seguridad == 1){
     //Prueba para el funcionamiento del Servomotor (Habiendose registrado) CERRAR
     lcd.clear();
     lcd.print("Cerrando Servo");
     servoMotor.write(180);
     delay(1000);
     servoMotor.write(90);
     delay(1000);
     lcd.clear();
     lcd.print("Otra operacion?");
     lcd.setCursor(0,1);
     tecla=0;
  }
  if(tecla == 'C' && seguridad == 1){
    //Prueba para el cierre de sesion de usuario
    seguridad = 0;
    lcd.clear();
    lcd.print("Sesion Cerrada");
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("Hasta luego");
    delay(1000);
    lcd.clear();
    lcd.print("Enter Password");
    lcd.setCursor(0,1);
    tecla=0;
      
  }
  if(tecla == 'D' && seguridad == 1){
    lcd.clear();
    lcd.print("Opcion no valida");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("Volver a intentar");
    delay(1000);
     lcd.clear();
     lcd.print("Otra operacion?");
     lcd.setCursor(0,1);
     tecla=0;
  
  }
  if(tecla == '*' && seguridad == 1){
    lcd.clear();
    lcd.print("Opcion no valida");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("Volver a intentar");
    delay(1000);
     lcd.clear();
     lcd.print("Otra operacion?");
     lcd.setCursor(0,1);
     tecla=0;
  
  }
  if(tecla){
       password[i++]=tecla;
       lcd.print(tecla);
   }
  if(i==4){
    delay(200);
    for(int j=0;j<4;j++)
      initial_password[j]=EEPROM.read(j);
    if(!(strncmp(password, initial_password,4))){
        //La persona ya ha ingresado       
        lcd.clear();
        lcd.print("Pass Accepted");
        delay(2000);
        lcd.setCursor(0,1);
        lcd.print("Posicionando...");
        digitalWrite(pinCamara, HIGH);
        //En este proceso el otro arduino toma la foto
        delay(6000);
        digitalWrite(pinCamara, LOW);
        lcd.clear();
        lcd.print("Bienvenido EDGAR");
        seguridad = 1;
        delay(2000);
        lcd.clear();
        lcd.print("Que vas a hacer?");
        lcd.setCursor(0,1);
        i=0;
      }
     else{
        lcd.clear();
        lcd.print("Wrong Password");
        delay(2000);
        lcd.setCursor(0,1);
        lcd.print("Try again");
        delay(2000);
        lcd.clear();
        lcd.print("Enter Password");
        lcd.setCursor(0,1);
        i=0;
      }
    }
}
