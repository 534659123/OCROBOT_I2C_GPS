#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OCROBOT_I2C_GPS.h>                                                                                                                                                                                    
GPS GPS(4);
LiquidCrystal_I2C lcd(0x20,16,2);

byte hh,mm,ss,ms;
byte y,m,d;
uint16_t delayTime = 3000;
void setup() {
  Wire.begin();
  lcd.init();  
  lcd.backlight();

}

void loop() {
  /*��ʾʱ��*/
  GPS.UtcDate(y,m,d);
  GPS.UtcTime(hh,mm,ss,ms);
  lcd.setCursor(0, 0);
  lcd.print("DATE:");
  lcd.print("20");
  lcd.print(y);
  lcd.print("/");
  lcd.print(m);
  lcd.print("/");
  lcd.print(d);
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  lcd.print(hh + 8);  //��������������ʾ����ʱ��
  lcd.print(":");
  lcd.print(mm);
  lcd.print(":");
  lcd.print(ss);
  lcd.print(":");
  lcd.print(ms);
  delay(delayTime);
  lcd.clear();
  /*��ʾγ�Ⱦ���*/  
  lcd.setCursor(0, 0);
  lcd.print(GPS.LatitudeDirection());  //γ��
  lcd.print(":");
  lcd.print(GPS.Latitude(),4);

  lcd.setCursor(0, 1);
  lcd.print(GPS.LongitudeDirection()); //����
  lcd.print(":");
  lcd.print(GPS.Longitude(),4);
  delay(delayTime);
  lcd.clear();
  /*��λ״̬����Ч����*/
  lcd.setCursor(0, 0);
  lcd.print("Pos:");
  lcd.print(GPS.Positioning()); //��λ״̬ 0:�޶�λ  1:SPS ģʽ��λ  2:��֡�SPSģʽ��λ 3 :PPS ģʽ��λ
  lcd.setCursor(0, 1);
  lcd.print("Sat:");
  lcd.print(GPS.Satellite()); //��Ч��������
  delay(delayTime);
  lcd.clear();
  /*ˮƽ��λ����������߶�*/
  lcd.setCursor(0, 0);
  lcd.print("HDOP:");
  lcd.print(GPS.HDOP()); //ˮƽ���� ��λ��
  lcd.setCursor(0, 1);
  lcd.print("MSL:");
  lcd.print(GPS.MSL()); //����ߣ���λ��
  delay(delayTime);
  lcd.clear();
  /*�������ٶ�*/
  lcd.setCursor(0, 0);
  lcd.print("Course:");
  lcd.print(GPS.Course()); // ���� ��λ��
  lcd.setCursor(0, 1);
  lcd.print("Speed:");
  lcd.print(GPS.Speed()); //�ٶȣ���λǧ��/Сʱ
  lcd.print("km/h");
  delay(delayTime);                    
  lcd.clear();
  /*��ƽ���*/
  lcd.setCursor(0, 0);
  lcd.print("SeaLevel:");
  lcd.print(GPS.SeaLevel()); // ��ƽ��ߣ���λ��
  delay(delayTime);
  lcd.clear();
}