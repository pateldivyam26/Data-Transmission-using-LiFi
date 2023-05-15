const int LED_PIN = A1;
const int PERIOD = 30;
const char* message = "This was text transmitted using LiFi  ";

int message_length;

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  
  message_length = strlen(message);
}



void loop() 
{
  for (int i = 0; i < message_length; i++)
  {
    send_byte(message[i]);
  }
  delay(1500);
}



void send_byte(char byte_to_send)
{
  digitalWrite(LED_PIN, LOW);
  delay(PERIOD);

  for (int i = 0; i < 8; i++)
  {
    digitalWrite(LED_PIN, (byte_to_send & (0x01 << i)) != 0);
    delay(PERIOD);
  }

  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);
}
