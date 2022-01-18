#include <Ultrasonic.h> //This calls upon the libray for the Ultrasonic sensor

Ultrasonic ultrasonic (9, 10);/*Says that the Trig pin is pin 9 and the Echo pin is pin 10. It also gives the sensor a name. In this case, the name is ultrasonic.*/

const int right_irsensor = 8;/*Says that the right IR sensor is connected to pin 8. const is for saying that it will always be connected to pin 8. int is for integer. 8 is an integer, so we use int. After int, a variable or a constant is declared. In this case, it is a constant. A variable can change values while a constant cannot.*/
const int left_irsensor = 7;
const int motor_rightFront = 3;//the wire of the right motor which controls its forward motion is connected to pin 3
const int motor_rightBack = 2;//the wire of the motor which controls its backward motion is connected to pin 3
const int motor_leftFront = 5;//The varables can be named however you want. I decided to go along with simple names.
const int motor_leftBack = 4;
const int buzzer = 11;
int x;
int y;/*x and y are two variables that I will be using in order to declare inputs and outputs. This method is not necessary, but it is easier than the conventional method*/

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
for(x = 2; x<6; x++){//As long as x starts at 2 and increases by 1 each time and remains less than 6. In other words, pins 1 to 5.
pinMode(x, OUTPUT);/*Declaring x as an output. The pinMode() function is used to do this. In short, pins 2 to 5 are outputs. This makes sense since motors are control devices, to which commands are given.*/
}
for(y=7; y<9 ; y++){
pinMode(y, INPUT);//The two IR sensors are declared as inputs. The sensors give values, so this also makes sense.
pinMode(buzzer, OUTPUT);
}
}

void loop() {
// put your main code here, to run repeatedly:
int right_sensor = digitalRead(right_irsensor);/*declaring a variable called right_sensor to take the reading from the right IR sensor. We are using digitalRead() since it is only a white and black surface. It will read LOW for black and HIGH for white.*/
int left_sensor = digitalRead(left_irsensor);
int reading = ultrasonic.read();//Declaring a variable for the Ultrasonic sensor to read. Here, the name you gave to the sensor has to be used for the command. So, <your name>.read
Serial.println("Cm"); 
Serial.println(reading);
delay (100);
if(reading>29){ //If the reading is more than 29 cm, then the robot can run.
if(right_sensor == HIGH && left_sensor == LOW){/*The right sensor detects white and the left sensor detects black.*/
left();//turn left. 
}
if(right_sensor == LOW && left_sensor == HIGH){
right();
}
if(right_sensor == LOW && left_sensor == LOW){
yay();
}
if(right_sensor == HIGH && left_sensor == HIGH){
forward();
}
}
else{
yay();//if it is not more than 29 cm, then it will stop. yay() is defined as a function below. 
}
}

void right(){//void is used to define functions. This function will make the robot turn right.
/*digitalWrite() is used to make things work or stop based on digital signals given to it in the form of HIGH and LOW.HIGH is to make something work while LOW is to stop it.*/ 
digitalWrite(motor_rightFront, LOW);//make the right motor stop moving forward
digitalWrite(motor_rightBack,LOW );//make the right motor stop moving backward
digitalWrite(motor_leftFront, LOW);//make the left motor stop moving forward
digitalWrite(motor_leftBack, HIGH);//make the left motor stop moving backward
}

void left(){
digitalWrite(motor_rightFront, LOW);
digitalWrite(motor_rightBack, HIGH);
digitalWrite(motor_leftFront, LOW);
digitalWrite(motor_leftBack, LOW);

}

void forward(){
digitalWrite(motor_rightFront, LOW);
digitalWrite(motor_rightBack, HIGH);
digitalWrite(motor_leftFront, LOW);
digitalWrite(motor_leftBack, HIGH);

}

void yay(){ //This is to make it stop. stop is a function on its own, so I could not name this function stop.
digitalWrite(motor_rightFront, LOW);
digitalWrite(motor_rightBack, LOW);
digitalWrite(motor_leftFront, LOW);
digitalWrite(motor_leftBack, LOW);
tone(buzzer, 1000); // Send 1KHz sound signal...
}

void backward(){
digitalWrite(motor_rightFront, HIGH);
digitalWrite(motor_rightBack, LOW);
digitalWrite(motor_leftFront, HIGH);
digitalWrite(motor_leftBack, LOW);
 

}
