#ifndef OCROBOT_I2C_GPS_H
#define OCROBOT_I2C_GPS_H

#if defined(ARDUINO) && ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/*请求指令码列表*/


/***************/

class GPS{
	public:
		GPS(byte Addr);
		void UtcTime(byte &UTC_HH, byte &UTC_MM, byte &UTC_SS, byte &UTC_MS);   //获取UTC时间
		float Latitude(void);  //返回纬度
		char LatitudeDirection(void); //返回纬度方向字母，  北纬N,南纬S
		float Longitude(void); // 经度
		char LongitudeDirection(void); // 经度方向   E 东经 W西经
		byte Positioning(void);  //定位状态 0-3  定位可靠性指示  0:无定位  1:SPS 模式定位  2:差分、SPS模式定位 3 :PPS 模式定位
		byte Satellite(void);   //有效卫星数量
		float HDOP(void);  //水平定位精度的(单位 米)
		float MSL(void);  //椭球高，单位米
		float SeaLevel(void); //海平面高， 单位米 -9999 ~ 9999
		void UtcDate(byte &UTC_YY, byte &UTC_mm, byte &UTC_DD);  //获取UTC日期
		float Course(void); //航向  真北偏 度数 0-359
		float Speed(void); //速度 千米每小时
	private:
		byte _addr;
	
};

#endif