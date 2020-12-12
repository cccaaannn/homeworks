
#define echopin 3          
#define trigpin 2          


int a = 6; // Pinleri tanımlıyoruz
int b = 7;
int c = 9;
int d = 10;
int e = 11;
int f = 5;
int g = 4;


void setup(){
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
Serial.begin(9600);

pinMode(a, OUTPUT); 
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
}

int count = 0;

void loop() {


int distance = get_distance();

Serial.print("Uzaklik: ");  
Serial.println(distance);  

if(distance > 10 && distance < 30){
  count++;
  delay(500);
}


if(count == 0){
  _0();
}
else if(count == 1){
  _1();
}
else if(count == 2){
  _2();  
}
else if(count == 3){
  _3();  
}
else if(count == 4){
  _4();  
}
else if(count == 5){
  _5();  
}
else if(count == 6){
  _6();
}
else if(count == 7){
  _7();
}
else if(count == 8){
  _8();
}
else if(count == 9){
  _9();
}
else if(count > 9){
  _out_of_display();
  Serial.print("out_of_display");  
}


}



void _9(){
// "9" Sayısını yazar.
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
void _8(){
// "8" Sayısını yazar.
digitalWrite(a, LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
void _7(){
// "7" Sayısını yazar.
digitalWrite(a, LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}
void _6(){
// "6" Sayısını yazar.
digitalWrite(a, LOW);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
void _5(){
// "5" Sayısını yazar.
digitalWrite(a, LOW);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
void _4(){
// "4" Sayısını yazar.
digitalWrite(a, HIGH);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
void _3(){
// "3" Sayısını yazar.
digitalWrite(a, LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
}
void _2(){
// "2" Sayısını yazar.
digitalWrite(a, LOW);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
}
void _1(){
// "1" Sayısını yazar.
digitalWrite(a, HIGH);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
}
void _0(){
// "0" Sayısını yazar.
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);
}
void _out_of_display(){
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
}


int get_distance(){

long duration,distance;

digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);

duration = pulseIn(echopin,HIGH);

distance= duration /29.1/2;          

delay(100);

return distance;  
}
