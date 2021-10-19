#include <OneWire.h>
#include <DS18B20.h>

// Numer pinu do którego podłaczasz czujnik
#define ONEWIRE_PIN 2
float maxi(float mala[18]){
  float a=-273.15;

  for (int i=0;i<18;i++){
    if (mala[i]>a) a=mala[i];
  }
  return a;
  }
float mini(float mala[18]){
  float a=1000000.0;

  for (int i=0;i<18;i++){
    if (mala[i]<a) a=mala[i];
  }
  return a;
  }
float srednia(float mala[18]){
  float a=0;

  for (int i=0;i<18;i++){
     a+=mala[i];
  }
  a=(a-mini(mala)-maxi(mala))/16;
  return a;
  }
// Adres czujnika
byte address[8] = {0x28,0xFF,0x77,0x29,0xA2,0x17,0x4,0xCD};

OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);
float mala[18]={0.0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0};
short int numer=0;
void setup() {
  while(!Serial);
  Serial.begin(9600);

  sensors.begin();
  sensors.request(address);
}

void loop() {
  if (sensors.available())
  {
    float temperature = sensors.readTemperature(address);
    mala[numer]=temperature;
    if (numer==17){
      Serial.print(srednia(mala));
      Serial.println(F(" 'C"));
      numer=0;
      }else numer++;
    sensors.request(address);
    delay(100);
  }

  // tu umieść resztę twojego programu
  // Będzie działał bez blokowania
}
