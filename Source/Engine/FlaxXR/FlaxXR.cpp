#include "FlaxXR.h"
#include "Engine\Core\Config\GameSettings.h"
#include "FlaxEngine.Gen.h"
#include "Engine\Engine\EngineService.h"
#include "Engine\Graphics\RenderBuffers.h"
#include "Engine\Level\Actors\Camera.h"
#include "Engine\Graphics\RenderTask.h"
#include "Engine\Profiler\Profiler.h"

class FlaxXRService : public EngineService
{
public:

    FlaxXRService()
        : EngineService(TEXT("FlaxXR"), -60)
    {
    }

    bool Init() override;
    void Update() override;
    void Dispose() override;
};
FlaxXRService FlaxXRServiceInstance;


bool FlaxXRService::Init() {
    if (!GameSettings::Get()->OpenXRStartAtStartUp) {
        return false;
    }
    bool OpenXRSupported = FlaxXR::IsOpenXRSupported();
    if (OpenXRSupported)
    {
        LOG(Info, "OpenXR Supported");
#if !FLAX_EDITOR
        FlaxXR::StartOpenXR();
#endif
    }
    else
    {
        LOG(Info, "OpenXR not Supported on this platform");
        FlaxXR::RunningStateChange(false);
    }
    return false;
}

bool renderedThisFrame = false;

void FlaxXRService::Update() {
    PROFILE_GPU_CPU("FlaxXR");
    if (renderedThisFrame) {
        PROFILE_GPU_CPU("FlaxXR End Frame");
        if (FlaxXR::OpenXRRunning()) {
            FlaxXR::GetOpenXRInstance()->EndUpdate();
        }
    }
    renderedThisFrame = false;
    if (FlaxXR::OpenXRRunning()) {
        renderedThisFrame = FlaxXR::GetOpenXRInstance()->BeginUpdate();
    }
    auto mainCam = Camera::GetMainCamera();
    if (mainCam != nullptr) {
        PROFILE_GPU_CPU("FlaxXR Start Frame");
        if (!mainCam->GetUseXRRendering()) {
            mainCam = nullptr;
        }
        if (FlaxXR::OpenXRRunning()) {
            for (size_t i = 0; i < FlaxXR::GetOpenXRInstance()->view_count; i++)
            {
                for (size_t j = 0; j < FlaxXR::GetOpenXRInstance()->swapchain_lengths[i]; j++)
                {
                    auto renderTask = FlaxXR::GetOpenXRInstance()->renderTasks[i][j];
                    renderTask->Enabled = renderedThisFrame && (mainCam != nullptr);
                    if (renderTask->Enabled) {
                        renderTask->ActorsSource = MainRenderTask::Instance->ActorsSource;
                        renderTask->CustomActors = MainRenderTask::Instance->CustomActors;
                        renderTask->CustomPostFx = MainRenderTask::Instance->CustomPostFx;
                        renderTask->View = MainRenderTask::Instance->View;
                    }
                }
            }
        }
    }
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
            mainOpenXRInstance->Stop();
            mainOpenXRInstance = nullptr;
        }
        RunningStateChange(result);
        return result;
        }
    msg = TEXT("OpenXR already loaded");
    return false;
#else // OPENXR_SUPPORT
    return false;
#endif // OPENXR_SUPPORT
    }
Delegate<bool> FlaxXR::RunningStateChange;

bool FlaxXR::StopOpenXR() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    if (mainOpenXRInstance != nullptr) {
        bool result = mainOpenXRInstance->Stop();
        if (!result) {
            msg = mainOpenXRInstance->msg;
        }
        mainOpenXRInstance = nullptr;
        RunningStateChange(false);
        return result;
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
    return ((OpenXRInstance*)mainOpenXRInstance)->session != XR_NULL_HANDLE;
#else // OPENXR_SUPPORT
    return false;
#endif // OPENXR_SUPPORT
}

