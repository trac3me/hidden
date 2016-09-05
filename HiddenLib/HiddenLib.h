#pragma once

typedef unsigned int HidStatus;

#define HID_STATUS_SUCCESSFUL(status) (status & 1)
#define HID_STATUS_CODE(status)       (status >> 1)

#define HID_SET_STATUS(state, code)   (code << 1 | (state ? 1 : 0))

typedef void*       HidContext;
typedef HidContext* PHidContext;

typedef unsigned long long HidObjId;

typedef unsigned long HidProcId;

enum HidActiveState 
{
	StateDisabled = 0,
	StateEnabled
};

enum HidPsInheritTypes
{
	WithoutInherit = 0,
	InheritAlways,
	InheritOnce,
	InheritMax
};

HidStatus Hid_Initialize(PHidContext pcontext);
void Hid_Destroy(HidContext context);

HidStatus Hid_SetState(HidContext context, HidActiveState state);
HidStatus Hid_GetState(HidContext context, HidActiveState* pstate);

// Fs\Reg

HidStatus Hid_AddHiddenRegKey(HidContext context, wchar_t* regKey, HidObjId* objId);
HidStatus Hid_RemoveHiddenRegKey(HidContext context, HidObjId objId);
HidStatus Hid_RemoveAllHiddenRegKeys(HidContext context);

HidStatus Hid_AddHiddenRegValue(HidContext context, wchar_t* regValue, HidObjId* objId);
HidStatus Hid_RemoveHiddenRegValue(HidContext context, HidObjId objId);
HidStatus Hid_RemoveAllHiddenRegValues(HidContext context);

HidStatus Hid_AddHiddenFile(HidContext context, wchar_t* filePath, HidObjId* objId);
HidStatus Hid_RemoveHiddenFile(HidContext context, HidObjId objId);
HidStatus Hid_RemoveAllHiddenFiles(HidContext context);

HidStatus Hid_AddHiddenDir(HidContext context, wchar_t* dirPath, HidObjId* objId);
HidStatus Hid_RemoveHiddenDir(HidContext context, HidObjId objId);
HidStatus Hid_RemoveAllHiddenDirs(HidContext context);

// Ps

HidStatus Hid_AddExcludedImage(HidContext context, wchar_t* imagePath, HidPsInheritTypes inheritType, HidObjId* objId);
HidStatus Hid_RemoveExcludedImage(HidContext context, HidObjId objId);
HidStatus Hid_RemoveAllExcludedImages(HidContext context);
HidStatus Hid_GetExcludedState(HidContext context, HidProcId procId, HidActiveState* state, HidPsInheritTypes* inheritType);
HidStatus Hid_AttachExcludedState(HidContext context, HidProcId procId, HidPsInheritTypes inheritType);
HidStatus Hid_RemoveExcludedState(HidContext context, HidProcId procId);

HidStatus Hid_AddProtectedImage(HidContext context, wchar_t* imagePath, HidPsInheritTypes inheritType, HidObjId* objId);
HidStatus Hid_RemoveProtectedImage(HidContext context, HidObjId objId);
HidStatus Hid_RemoveAllProtectedImages(HidContext context);
HidStatus Hid_GetProtectedState(HidContext context, HidProcId procId, HidActiveState* state, HidPsInheritTypes* inheritType);
HidStatus Hid_AttachProtectedState(HidContext context, HidProcId procId, HidPsInheritTypes inheritType);
HidStatus Hid_RemoveProtectedState(HidContext context, HidProcId procId);