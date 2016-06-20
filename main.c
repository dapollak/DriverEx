#include "ImageLoadNotify.h"
#include "CallGateInstaller.h"

VOID DriverUnload(PDRIVER_OBJECT  DriverObject);
NTSTATUS DriverEntry(PDRIVER_OBJECT  pDriverObject, PUNICODE_STRING  pRegistryPath);

#pragma alloc_text(INIT, DriverEntry)
#pragma alloc_text(INIT, DriverUnload)

NTSTATUS DriverEntry(PDRIVER_OBJECT  pDriverObject, PUNICODE_STRING  pRegistryPath)
{	
	DbgPrint("Driver Entry\n");
	pDriverObject->DriverUnload = DriverUnload;

	installCallGate();
	return STATUS_SUCCESS;
}

VOID DriverUnload(PDRIVER_OBJECT  DriverObject)
{
	DbgPrint("hey from unload func\n");
}




