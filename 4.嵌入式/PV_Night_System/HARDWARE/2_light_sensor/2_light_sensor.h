#ifndef __2_LIGHT_SENSOR_H
#define __2_LIGHT_SENSOR_H

#include "sys.h"

//PE3为DO,读取光敏传感器传入的TTL电平
//注意光敏传感器输出的TTL电平是5V的,因此要注意引脚的选择要选择"FT"的

#define Light_Sensor PEin(3)


void Light_Sensor_Init(void);	//光敏传感器初始化



#endif




