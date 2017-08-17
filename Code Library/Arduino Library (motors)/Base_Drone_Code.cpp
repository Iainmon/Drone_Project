#include <Servo.h>
#include <IRremote.h>

//little elegoo remote
#define up 0xFF629D   //turn on all lift motors at 3%
#define down 0xFFA857  //turn off for lift motors 0%
#define left 0xFF22DD  //for future
#define right 0xFFC23D //for future 
#define center 0xFF02FD //for future
#define zero 0xFF6897 //0 for 0%
#define one 0xFF30CF //1 for 1%
#define two 0xFF18E7 //2 for 20%
#define three 0xFF7A85 //3 for 30%
#define four 0xFF10EF //4 for 40%
#define five 0xFF38C7 //5 for 50%
#define six 0xFF5AA5 //6 for 60%
#define seven 0xFF42BD //7 for 70%
#define eight 0xFF4AB5 //8 for 80%
#define nine 0xFF52AD //9 for 90%

//big plane remote
#define p0p 0xA3C730E3
#define p5p 0xAB9D6FB3
#define p10p 0xEA10EF93
#define p15p 0x30312AD3
#define p20p 0x1AB61D33
#define p25p 0x414C3F5B
#define p30p 0x75D82DB3
#define p35p 0xBBF868F3
#define p40p 0xF27BA3AA
#define p45p 0x1911C5D2
#define p50p 0x578545B2
#define p55p 0x9DA580F2
#define p60p 0x4062AAEA
#define p65p 0x66F8CD12
#define p70p 0x9B84BB6A

int RECV_PIN = 7; //plug in ir receiver to pin 7
Servo ESCFL;
Servo ESCFR;
Servo ESCBL;
Servo ESCBR;

IRrecv irrecv(RECV_PIN); 
decode_results results; //decodes hexadecimal values to actual values

void arm(){
  setSpeed(0, 5); //Sets speed variable 
  delay(1000);
  startsequence(); //Starts loop
}

void setSpeed(int speed, int motornum){
  int flangle = map(speed - 1, 0, 100, 1000, 2000); //Sets servo positions to different speeds
  int frangle = map(speed - 1, 0, 100, 1000, 2000); //Sets servo positions to different speeds
  int blangle = map(speed, 0, 100, 1000, 2000); //Sets servo positions to different speeds
  int brangle = map(speed, 0, 100, 1000, 2000); //Sets servo positions to different speeds

  //Motor Control
  if(motornum == 1){
    ESCFL.writeMicroseconds(flangle); //1
  }
  if(motornum == 2){
    ESCFR.writeMicroseconds(frangle); //2
  }
  if(motornum == 3){
    ESCBL.writeMicroseconds(blangle); //3
  }
  if(motornum == 4){
    ESCBR.writeMicroseconds(brangle); //4
  }
  //All is 5
  if(motornum == 5){
    ESCFL.writeMicroseconds(flangle); //1
    ESCFR.writeMicroseconds(frangle); //2
    ESCBL.writeMicroseconds(blangle); //3
    ESCBR.writeMicroseconds(brangle); //4
  }
}

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  ESCFL.attach(8); //Adds ESC to certain pin.
  ESCFR.attach(9); //Adds ESC to certain pin.
  ESCBL.attach(10); //Adds ESC to certain pin. 
  ESCBR.attach(11); //Adds ESC to certain pin. 
  arm();
}

void startsequence(){
  delay(5000);
  setSpeed(0, 5); //ready to launch
  delay(500);
  setSpeed(8, 5); //8 percent power
  delay(2000);
  setSpeed(0, 5); //back to 0 percent `             
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

  if (results.value == up) //press up button
    {
      setSpeed(3,5); //all 4 motors goes to 3%
    }

  if (results.value == down) //press down button
    {
      setSpeed(0,5); //all 4 motors goes down to 0%
    }

  if (results.value == zero) //press 0 button
    {
      setSpeed(0,5); //all 4 motors stay at 0%
    }

  if (results.value == one) //press 1 button
    {
      setSpeed(5,5); //all 4 motors goes to 5%
    }

  if (results.value == two) //press 2 button
    {
      setSpeed(10,5); //all 4 motors goes to 10%
    }

  if (results.value == three) //press 3 button
    {
      setSpeed(15,5); //all 4 motors goes to 15%
    }
    
    
  if (results.value == four) //press 4 button
    {
      setSpeed(20,5); //all 4 motors goes to 20%
    }

    if (results.value == five) //press 5 button
    {
      setSpeed(25,5); //all 4 motors goes to 25%
    }

    if (results.value == six) //press 6 button
    {
      setSpeed(30,5); //all 4 motors goes to 30%
    }

    if (results.value == seven) //press 7 button
    {
      setSpeed(35,5); //all 4 motors goes to 35%
    }
    
    if (results.value == eight) //press 8 button
    {
      setSpeed(40,5); //all 4 motors goes to 40%
    }
    
    if (results.value == nine) //press 9 button
    {
      setSpeed(45,5); //all 4 motors goes to 45%
    }

 
    if (results.value == p0p)
    {
      setSpeed(0,5); //all 4 motors goes to 0%
    }

    if (results.value == p5p)
    {
      setSpeed(5,5); //all 4 motors goes to 5%
    }

    if (results.value == p10p)
    {
      setSpeed(10,5); //all 4 motors goes to 10%
    }

    if (results.value == p15p)
    {
      setSpeed(15,5); //all 4 motors goes to 15%
    }

    if (results.value == p20p)
    {
      setSpeed(20,5); //all 4 motors goes to 20%
    }

    if (results.value == p25p)
    {
      setSpeed(25,5); //all 4 motors goes to 25%
    }

    if (results.value == p30p)
    {
      setSpeed(30,5); //all 4 motors goes to 30%
    }

    if (results.value == p35p) 
    {
      setSpeed(35,5); //all 4 motors goes to 35%
    }

    if (results.value == p40p) 
    {
      setSpeed(40,5); //all 4 motors goes to 40%
    }

    if (results.value == p45p) 
    {
      setSpeed(45,5); //all 4 motors goes to 45%
    }

    if (results.value == p50p) 
    {
      setSpeed(50,5); //all 4 motors goes to 50%
    }

    if (results.value == p55p) 
    {
      setSpeed(55,5); //all 4 motors goes to 55%
    }

    if (results.value == p60p)
    {
      setSpeed(60,5); //all 4 motors goes to 60%
    }

    if (results.value == p65p)
    {
      setSpeed(65,5); //all 4 motors goes to 65%
    }

    if (results.value == p70p)
    {
      setSpeed(70,5); //all 4 motors goes to 70%
    }
    
  }
  delay(20);          //General speed
}
