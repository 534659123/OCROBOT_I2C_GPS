#ifndef OCROBOT_I2C_GPS_H
#define OCROBOT_I2C_GPS_H

#if defined(ARDUINO) && ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/*����ָ�����б�*/


/***************/

class GPS{
	public:
		GPS(byte Addr);
		void UtcTime(byte &UTC_HH, byte &UTC_MM, byte &UTC_SS, byte &UTC_MS);   //��ȡUTCʱ��
		float Latitude(void);  //����γ��
		char LatitudeDirection(void); //����γ�ȷ�����ĸ��  ��γN,��γS
		float Longitude(void); // ����
		char LongitudeDirection(void); // ���ȷ���   E ���� W����
		byte Positioning(void);  //��λ״̬ 0-3  ��λ�ɿ���ָʾ  0:�޶�λ  1:SPS ģʽ��λ  2:��֡�SPSģʽ��λ 3 :PPS ģʽ��λ
		byte Satellite(void);   //��Ч��������
		float HDOP(void);  //ˮƽ��λ���ȵ�(��λ ��)
		float MSL(void);  //����ߣ���λ��
		float SeaLevel(void); //��ƽ��ߣ� ��λ�� -9999 ~ 9999
		void UtcDate(byte &UTC_YY, byte &UTC_mm, byte &UTC_DD);  //��ȡUTC����
		float Course(void); //����  �汱ƫ ���� 0-359
		float Speed(void); //�ٶ� ǧ��ÿСʱ
	private:
		byte _addr;
	
};

#endif