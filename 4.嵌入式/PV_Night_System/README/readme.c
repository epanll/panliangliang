//光伏PV,夜间照明控制系统

//一.物件准备
//1.开发板:STM32F103ZET6	开发板
//2.显示屏:LCD 1602
//3.光敏传感器
//4.热释电红外传感器
//5.继电器
//6.LED灯

//二.软件准备
//1.keil软件
//2.串口调试软件

//三.控制逻辑
//光敏传感器区分是白天还是夜晚
//
//1.白天关闭系统
//
//2,晚上开启系统
//	
//	红外传感器确认范围内是否存在人
//	
//  3.存在人控制继电器和LED灯照明
//
//	无人
//	
//	4.无人存在时关闭继电器和LED灯
