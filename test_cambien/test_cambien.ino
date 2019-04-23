#define sensor 4

void speed_calculation(void);

void setup()
{
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}
void loop()
{
  speed_calculation();
}
void speed_calculation(void)
{
  float spd, b = 20.00, i = 0; //
  unsigned long time1, time2, time3;
  time1 = micros();
  while (1)
  {
    if (digitalRead(sensor) == 1)
    {
      while (1)
      {
        if (digitalRead(sensor) == 0 )
        {break;}
      }
      i++;
    }
    if (i >19)
    {break;}
  }
  time2 = micros();
  time3 = (time2 - time1)/1000000;
  spd = b / time3;
  //Serial.print("Gia tri cua i = ");
  //Serial.println(i); //Nếu sensor = 1 thì không phát hiện vật cản, nếu sensor = 0 thì phát hiện vật cản.
  /*
  Serial.print("Bat dau: ");
  Serial.println(time1);
  Serial.print("Ket thuc ");
  Serial.println(time2);
  */
  Serial.print("Tong thoi gian = ");
  Serial.println(time3);
  Serial.print("Toc do trung binh ");
  Serial.print(spd);
  Serial.println(" (giot/s) ");
}
