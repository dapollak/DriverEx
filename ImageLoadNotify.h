#pragma once

#include "common.h"

typedef VOID
(*PLOAD_IMAGE_NOTIFY_ROUTINE) (
	IN PUNICODE_STRING  FullImageName,
	IN HANDLE  ProcessId, // where image is mapped
	IN PIMAGE_INFO  ImageInfo
	);

VOID ImageCallback(PUNICODE_STRING fullImageName, HANDLE processId, PIMAGE_INFO imageInfo);

#pragma alloc_text(PAGE, ImageCallback)