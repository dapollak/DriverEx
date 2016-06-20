#include "ImageLoadNotify.h"

VOID ImageCallback(PUNICODE_STRING fullImageName, HANDLE processId, PIMAGE_INFO imageInfo)
{
	DbgPrint("hey from image load callback\n");
	DbgPrint("base address - %x\n", imageInfo->ImageBase);
}