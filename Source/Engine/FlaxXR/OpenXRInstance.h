#pragma once
#include "Engine\Graphics\GPUDevice.h"
#include "Engine\Graphics\RenderBuffers.h"
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
#define FLAXXR_SUPPORTED
#endif

#if OPENXR_SUPPORT


#if GRAPHICS_API_VULKAN
#define XR_USE_GRAPHICS_API_VULKAN
#define VK_NO_PROTOTYPES
#include "Engine\GraphicsDevice\Vulkan\GPUDeviceVulkan.h"
#include "Engine\GraphicsDevice\Vulkan\GPUAdapterVulkan.h"
#include "Engine\GraphicsDevice\Vulkan\QueueVulkan.h"
#endif // GRAPHICS_API_VULKAN

#if GRAPHICS_API_DIRECTX12
#define XR_USE_GRAPHICS_API_D3D12
#include "Engine\GraphicsDevice\DirectX\DX12\GPUDeviceDX12.h"
#endif // GRAPHICS_API_DIRECTX12

#if GRAPHICS_API_DIRECTX11
#define XR_USE_GRAPHICS_API_D3D11
#include "Engine\GraphicsDevice\DirectX\DX11\GPUDeviceDX11.h"
#endif // GRAPHICS_API_DIRECTX11

#if PLATFORM_ANDROID
#define XR_USE_PLATFORM_ANDROID

#include <android\configuration.h>
#include <android\looper.h>
#include <android\native_activity.h>

#endif

#include <openxr\openxr.h>
#include <openxr\openxr_platform.h>
#include <openxr\openxr_platform_defines.h>
#include <openxr\openxr_reflection.h>

#endif // OPENXR_SUPPORT


class OpenXRInstance
{
public:
    // each physical Display/Eye is described by a view.
    // view_count usually depends on the form_factor / view_type.
    // dynamically allocating all view related structs instead of assuming 2
    // hopefully allows this app to scale easily to different view_counts.
    uint32_t view_count = 0;
    uint32_t* swapchain_lengths = NULL;
    uint32_t* depth_swapchain_lengths = NULL;
#if OPENXR_SUPPORT
	// Changing to HANDHELD_DISPLAY or a future form factor may work, but has not been tested.
	XrFormFactor form_factor = XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY;

	// Changing the form_factor may require changing the view_type too.
	XrViewConfigurationType view_type = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO;

	// Typically STAGE for room scale/standing, LOCAL for seated
	XrReferenceSpaceType play_space_type = XR_REFERENCE_SPACE_TYPE_LOCAL;
	XrSpace play_space = XR_NULL_HANDLE;

	// the instance handle can be thought of as the basic connection to the OpenXR runtime
	XrInstance instance = XR_NULL_HANDLE;
	// the system represents an (opaque) set of XR devices in use, managed by the runtime
	XrSystemId system_id = XR_NULL_SYSTEM_ID;
	// the session deals with the renderloop submitting frames to the runtime
    XrSession session = XR_NULL_HANDLE;
	// the viewconfiguration views contain information like resolution about each view
	XrViewConfigurationView* viewconfig_views = NULL;

	// array of view_count containers for submitting swapchains with rendered VR frames
	XrCompositionLayerProjectionView* projection_views = NULL;
	// array of view_count views, filled by the runtime with current HMD display pose
	XrView* views = NULL;

    XrPosef identity_pose = {};

    XrCompositionLayerDepthInfoKHR* depth_infos;

#ifdef XR_USE_GRAPHICS_API_D3D11
	XrGraphicsBindingD3D11KHR graphics_binding_dx11;
    XrSwapchainImageD3D11KHR** images_dx11 = NULL;
    XrSwapchainImageD3D11KHR** depth_images_dx11 = NULL;
#endif
#ifdef XR_USE_GRAPHICS_API_D3D12
	XrGraphicsBindingD3D12KHR graphics_binding_dx12;
    XrSwapchainImageD3D12KHR** images_dx12 = NULL;
    XrSwapchainImageD3D12KHR** depth_images_dx12 = NULL;
#endif
#ifdef XR_USE_GRAPHICS_API_VULKAN
	XrGraphicsBindingVulkanKHR graphics_binding_vk;
    XrSwapchainImageVulkanKHR** images_vk = NULL;
    XrSwapchainImageVulkanKHR** depth_images_vk = NULL;
#endif

    XrFrameState frame_state;
    XrViewState view_state;

    XrSwapchain* swapchains = NULL;


    XrSwapchain* depth_swapchains = NULL;


    int64_t Get_Swapchain_Format(XrInstance instance,
        XrSession session,
        int64_t preferred_format,
        bool fallback);

	void UpdateResultMSG(XrResult result);


    bool depth_supported = false;
    bool session_running = false;
    bool dx11_supported = false;
    bool dx12_supported = false;
    bool vulkan_supported = false;

#endif

    RenderBuffers*** renderBuffers;
    GPUTexture*** finalSwampChains;
public:
	String msg;
    
    bool Stop();

	bool Init();

    bool BeginUpdate();

    bool EndUpdate();

};

