void setup() {
  pinMode(8, OUTPUT); //Diode
  pinMode(7, INPUT_PULLUP); //Button
  digitalWrite(8, LOW); //Turn off diode
}
 
void loop()
{
  int ON = 0;
  if (digitalRead(7) == LOW) {
    ON =1;
}
  while(ON==1){
    digitalWrite(8, HIGH);
    delay(300);
    digitalWrite(8, LOW);
    delay(300);
  }
}