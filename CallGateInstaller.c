#include "CallGateInstaller.h"

void __declspec(naked) callGateFunc() {
	//DbgPrint("hey from call gate");
	__asm {
		retf
	}
}

void installCallGate() {
	int i;
	char *gdtPtr;
	CALL_GATE callGate;
	short csSelector;
	unsigned callGateOffsetAddr;

	char buff[6] = { 0 };
	__asm {
		sgdt buff
		mov csSelector, cs
	}

	RtlCopyMemory(&gdtPtr, buff + 2, 4);
	RtlZeroMemory(&callGate, sizeof(CALL_GATE));
	callGateOffsetAddr = (unsigned)callGateFunc;

	callGate.Dpl = 3;
	callGate.NumberOfArguments = 0;
	callGate.Selector = csSelector;
	callGate.Type = 12;
	callGate.OffsetLow = callGateOffsetAddr & 0x0000FFFF;
	callGate.OffsetHigh = callGateOffsetAddr >> 16;
	callGate.Present = 1;

	RtlCopyMemory(gdtPtr + 14 * 8, &callGate, sizeof(callGate));
}