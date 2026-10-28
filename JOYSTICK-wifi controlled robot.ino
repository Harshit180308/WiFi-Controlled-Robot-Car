#define BLYNK_TEMPLATE_ID "TMPL3naEuX1E1"
#define BLYNK_TEMPLATE_NAME "JOYSTICK"
#define BLYNK_AUTH_TOKEN "jnBkij0kh3FtszJwrUljhpwkIry84KuB"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[]="HARSHIT";
char pass[]="harshit@";

#define IN1 5
#define IN2 4

#define IN3 14
#define IN4 12

int x = 50;
int y = 50;


void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN ,ssid,pass);
}
 void loop()
 {
  Blynk.run();

  if(y >=70)
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);    
  }
  else if(y<30)
  {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  }
  else if (x >= 70)
  {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  }

else if(x<30)
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
else
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
 }

  BLYNK_WRITE(V0)
  {
   x = param[0].asInt();
  }

  BLYNK_WRITE(V1)
  {
    y = param[0].asInt();
  }