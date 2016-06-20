#pragma once

#include "common.h"

typedef struct _CALL_GATE
{
	USHORT OffsetLow;
	USHORT Selector;
	UCHAR NumberOfArguments : 5;
	UCHAR Reserved : 3;
	UCHAR Type : 5;
	UCHAR Dpl : 2;
	UCHAR Present : 1;
	USHORT OffsetHigh;
}CALL_GATE, *PCALL_GATE;

void callGateFunc();
void installCallGate();

#pragma alloc_text(PAGE, callGateFunc)
#pragma alloc_text(PAGE, installCallGate)
