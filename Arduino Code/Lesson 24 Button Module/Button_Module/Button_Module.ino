#include <Keypad.h>
int led = 10;
int buzzer = 11;
const byte ROWS = 4; // define row 4
const byte COLS = 4; // define column 4
char keys[ROWS][COLS] = {
  {'4','8','C','G'},
  {'3','7','B','F'},
  {'2','6','A','E'},
  {'1','5','9','D'}
};
// connect row ports of the button to corresponding IO ports on the board
byte rowPins[ROWS] = {9,8,7,6};	
// connect column ports of the button to corresponding IO ports on the board
byte colPins[COLS] = {5,4,3,2};
// call class library performance function of Keypad 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(buzzer, OUTPUT);
}

void loop(){
digitalWrite(led, LOW); 
digitalWrite(buzzer, LOW); 
char key = keypad.getKey();
if (key != NO_KEY){
Serial.println(key);
}
if (key =='1')
{
digitalWrite(led, HIGH); 
delay(1000);
}

if (key =='2')
{
digitalWrite(buzzer, HIGH); 
delay(1000);
}
}
