void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(36,OUTPUT);
  pinMode(37,OUTPUT);
  pinMode(38,OUTPUT);
  pinMode(25,OUTPUT);
}
bool flag=true;
void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(36))
  {
    Serial.println("Button1");
    }
  if(!digitalRead(37))
  {
    Serial.println("Button2");
    }
  if(!digitalRead(38))
  {
    if(flag)
    {
      digitalWrite(25,HIGH);
      flag=false;
      }
    else
    {
      digitalWrite(25,LOW);
      flag=true;
      }
    }
}
