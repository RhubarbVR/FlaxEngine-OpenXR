#include "FlaxOpenXR.h"
#include "Engine/Core/Config/GameSettings.h"
#include "FlaxEngine.Gen.h"
#include "Engine/Engine/EngineService.h"

class FlaxXRService : public EngineService
{
public:

    FlaxXRService()
        : EngineService(TEXT("FlaxXR"), 50)
    {
}

    bool Init() override;
    void Update() override;
    void Dispose() override;
};
FlaxXRService FlaxXRServiceInstance;


bool FlaxXRService::Init() {
    if(!GameSettings::Get()->OpenXRStartAtStartUp) {
        return false;
    }
    bool OpenXRSupported = FlaxXR::IsOpenXRSupported();
    if (OpenXRSupported)
    {
        LOG(Info,"OpenXR Supported");
#if !FLAX_EDITOR
        FlaxXR::StartOpenXR();
#endif
    }
    else
    {
        LOG(Info, "OpenXR not Supported on this platform");
        //NotifyStateChange(false);
    }
    return false;
}

void FlaxXRService::Update() {

}

void FlaxXRService::Dispose() {

}

OpenXRInstance* FlaxXR::mainOpenXRInstance;
String FlaxXR::msg;

bool FlaxXR::IsOpenXRSupported()
{
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
	return true;
#else // OPENXR_SUPPORT
	return false;
#endif // OPENXR_SUPPORT
}

String FlaxXR::ErrorMessage() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    return msg;
#else // OPENXR_SUPPORT
#if OPENXR_SUPPORT
    return TEXT("OpenXR not supported on this render backends");
#else // OPENXR_SUPPORT
    return TEXT("OpenXR not supported on this platform");
#endif
#endif // OPENXR_SUPPORT
}

bool FlaxXR::StartOpenXR() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    if (mainOpenXRInstance == nullptr) {
        mainOpenXRInstance = new OpenXRInstance();
        bool result = mainOpenXRInstance->Init();
        if (!result) {
            msg = mainOpenXRInstance->msg;
            mainOpenXRInstance = nullptr;
        }
        return result;
    }
    msg = TEXT("OpenXR already loaded");
    return false;
#else // OPENXR_SUPPORT
    return false;
#endif // OPENXR_SUPPORT
}

bool FlaxXR::StopOpenXR() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    if (mainOpenXRInstance != nullptr) {
        
    }
    msg = TEXT("OpenXR already not running");
    return false;
#else // OPENXR_SUPPORT
    return false;
#endif // OPENXR_SUPPORT
}

bool FlaxXR::OpenXRRunning() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    if (mainOpenXRInstance == nullptr) {
        return false;
    }
    return ((OpenXRInstance*)mainOpenXRInstance)->session == XR_NULL_HANDLE;
#else // OPENXR_SUPPORT
    return false;
#endif // OPENXR_SUPPORT
}

