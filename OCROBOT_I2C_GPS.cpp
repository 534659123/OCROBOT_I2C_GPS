#include "OCROBOT_I2C_GPS.h"
#include <Wire.h>
#include "VariableConversion.h"
GPS::GPS(byte Addr)
{
	_addr = Addr;
}


void GPS::UtcTime(byte &UTC_HH, byte &UTC_MM, byte &UTC_SS, byte &UTC_MS)
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(1);              // ����ָ����
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)4);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte UTCdata[4];
	byte s=0;
	while(Wire.available())    // �ж��Ƿ�������
	{ 
		UTCdata[s]= Wire.read(); // ��ȡ����
		s++;
	}
	UTC_HH = UTCdata[0];
	UTC_MM = UTCdata[1];
	UTC_SS = UTCdata[2];
	UTC_MS = UTCdata[3];
}

float GPS::Latitude(void)  //����γ��
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(2);              // ����ָ����(γ������)
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)4);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte LatitudeData[4];
	byte s=0;
	while(Wire.available())    // �ж��Ƿ�������
	{ 
		LatitudeData[s]= Wire.read(); // ��ȡ����
		s++;
	}
	float latitude;
	ByteToFloat(latitude,LatitudeData);
	return latitude;
	
}

char GPS::LatitudeDirection(void) //γ�ȷ���
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(3);              // ����ָ����(γ�ȷ���)
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)1);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	char direction = Wire.read(); // ��ȡ����
	return direction;
}

/*----------------*/

float GPS::Longitude(void)  //���ؾ���
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(4);              // ����ָ����(��������)
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)4);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte longitudeData[4];
	byte s=0;
	while(Wire.available())    // �ж��Ƿ�������
	{ 
		longitudeData[s]= Wire.read(); // ��ȡ����
		s++;
	}
	float longitude;
	ByteToFloat(longitude,longitudeData);
	return longitude;
	
}

char GPS::LongitudeDirection(void) //γ�ȷ���
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(5);              // ����ָ����(γ�ȷ���)
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)1);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	char direction = Wire.read(); // ��ȡ����
	return direction;
}


byte GPS::Positioning(void)   // ��λ���
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(6);              // ����ָ����(��λ״̬)
	Wire.endTransmission();    // ָֹͣ��
	
		/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)1);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte positioning = Wire.read(); // ��ȡ����
	return positioning;
}

byte GPS::Satellite()  //��Ч��������
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(7);              // ����ָ����(��Ч��������)
	Wire.endTransmission();    // ָֹͣ��
	
			/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)1);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte satellite = Wire.read(); // ��ȡ����
	return satellite;
}

float GPS::HDOP(void)
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(8);              // ����ָ����(ˮƽ��λ����) ��λ��
	Wire.endTransmission();    // ָֹͣ��
	
		/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)4);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte HDOPData[4];
	byte s=0;
	while(Wire.available())    // �ж��Ƿ�������
	{ 
		HDOPData[s]= Wire.read(); // ��ȡ����
		s++;
	}
	float Hdop;
	ByteToFloat(Hdop,HDOPData);
	return Hdop;
}

float GPS::MSL(void)
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(9);              // ����ָ����(�����) ��λ��
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)4);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte MSLData[4];
	byte s=0;
	while(Wire.available())    // �ж��Ƿ�������
	{ 
		MSLData[s]= Wire.read(); // ��ȡ����
		s++;
	}
	float Msl;
	ByteToFloat(Msl,MSLData);
	return Msl;
}


float GPS::SeaLevel(void)
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(10);              // ����ָ����(��ƽ��) ��λ��
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)4);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte SeaLevelData[4];
	byte s=0;
	while(Wire.available())    // �ж��Ƿ�������
	{ 
		SeaLevelData[s]= Wire.read(); // ��ȡ����
		s++;
	}
	float seaLevel;
	ByteToFloat(seaLevel,SeaLevelData);
	return seaLevel;
}

void GPS::UtcDate(byte &UTC_YY, byte &UTC_mm, byte &UTC_DD)
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(11);              // ����ָ���루�����գ�
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)3);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte UTCdata[3];
	byte s=0;
	while(Wire.available())    // �ж��Ƿ�������
	{ 
		UTCdata[s]= Wire.read(); // ��ȡ����
		s++;
	}
	UTC_DD = UTCdata[0];
	UTC_mm = UTCdata[1];
	UTC_YY = UTCdata[2];
}


float GPS::Course(void)
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(12);              // ����ָ����(��ƽ��) ��λ��
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)4);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte CourseData[4];
	byte s=0;
	while(Wire.available())    // �ж��Ƿ�������
	{ 
		CourseData[s]= Wire.read(); // ��ȡ����
		s++;
	}
	float ourse;
	ByteToFloat(ourse,CourseData);
	return ourse;
}


float GPS::Speed(void)
{
	Wire.beginTransmission(_addr); //��ָ����ַ�豸��������
	Wire.write(13);              // ����ָ����(�ٶ�) ��λ ǧ��ÿСʱ
	Wire.endTransmission();    // ָֹͣ��
	
	/*���շ�������*/
	Wire.requestFrom((int)_addr, (int)4);    // ��ָ���ĵ�ַ��ȡ4���ֽ�
	byte SpeedData[4];
	byte s=0;
	while(Wire.available())    // �ж��Ƿ�������
	{ 
		SpeedData[s]= Wire.read(); // ��ȡ����
		s++;
	}
	float speed;
	ByteToFloat(speed,SpeedData);
	return speed;
}


