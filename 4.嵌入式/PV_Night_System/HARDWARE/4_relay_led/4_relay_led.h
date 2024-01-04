#ifndef __RELAY_LED_H
#define __RELAY_LED_H

#include "sys.h"

#define DAY_LED		PBout(5)
#define NIGHT_LED	PEout(5)
#define RELAY_CONTROL	PBout(7)
#define NIGHT_LIGHTING	PBout(6)


void Relay_Led_Init(void);









#endif














