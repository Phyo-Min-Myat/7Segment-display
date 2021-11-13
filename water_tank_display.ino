#define d0 2
#define d1 3
#define d2 4
#define a 6
#define b 7
#define c 8
#define d 9 
#define e 10
#define f 5
#define g 11

int digit0 = 0;
int digit1 = 0;
int digit2 = 0;

int want_number = 0;
int deci = 0;

const int segs[7] = {a, b, c, d, e, f, g};
const byte numbers[10] = { 0b0111111,
                           0b0000110,
                           0b1011011,
                           0b1001111,
                           0b1100110,
                           0b1101101,
                           0b1111101,
                           0b0000111,
                           0b1111111,
                           0b1101111};

void setup(){
  pinMode(d2,OUTPUT);
  pinMode(d1,OUTPUT);
  pinMode(d0,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop() {
  want_number = 456;
  digit0 = want_number / 100;
  deci =want_number % 100;
  digit1 = deci / 10;
  digit2 = deci % 10;
  
  lightDigit0(numbers[digit0]);
  delay(5);
  lightDigit1(numbers[digit1]);
  delay(5);
  lightDigit2(numbers[digit2]);
  delay(5);
}

void lightDigit0(byte number){
  digitalWrite(d0,HIGH);
  digitalWrite(d1,LOW);
  digitalWrite(d2,LOW);
  lightSegments(number);
  delay(1);
}

void lightDigit1(byte number){
  digitalWrite(d0,LOW);
  digitalWrite(d1,HIGH);
  digitalWrite(d2,LOW);
  lightSegments(number);
  delay(1);
}

void lightDigit2(byte number){
  digitalWrite(d0,LOW);
  digitalWrite(d1,LOW);
  digitalWrite(d2,HIGH);
  lightSegments(number);
  delay(1);
}

void lightSegments(byte number){
  for (int i = 0; i < 7; i++){
    int Bit = bitRead(number, i);
    digitalWrite(segs[i], Bit);
  }
}
