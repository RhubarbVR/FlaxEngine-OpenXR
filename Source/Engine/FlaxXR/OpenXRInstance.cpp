#include "OpenXRInstance.h"
#include "Engine\Engine\Globals.h"
#include "Engine\Debug\DebugLog.h"
#include "Engine\Core\Config\GameSettings.h";
#include "Engine\Engine\Engine.h"
#include "Engine\Core\Log.h"
#include "FlaxXR.h"
#include "Engine\Graphics\RenderTask.h"
#include "Engine\Profiler\Profiler.h"

#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
void OpenXRInstance::UpdateResultMSG(XrResult result) {
    if (XR_SUCCEEDED(result)) {
        msg = "";
        return;
    }
    msg = "Error: ";
    if (result == XR_TIMEOUT_EXPIRED) {
        msg += "XR_TIMEOUT_EXPIRED";
    }
    else if (result == XR_SESSION_LOSS_PENDING) {
        msg += "XR_SESSION_LOSS_PENDING";
    }
    else if (result == XR_EVENT_UNAVAILABLE) {
        msg += "XR_EVENT_UNAVAILABLE";
    }
    else if (result == XR_SPACE_BOUNDS_UNAVAILABLE) {
        msg += "XR_SPACE_BOUNDS_UNAVAILABLE";
    }
    else if (result == XR_SESSION_NOT_FOCUSED) {
        msg += "XR_SESSION_NOT_FOCUSED";
    }
    else if (result == XR_FRAME_DISCARDED) {
        msg += "XR_FRAME_DISCARDED";
    }
    else if (result == XR_ERROR_VALIDATION_FAILURE) {
        msg += "XR_ERROR_VALIDATION_FAILURE";
    }
    else if (result == XR_ERROR_RUNTIME_FAILURE) {
        msg += "XR_ERROR_RUNTIME_FAILURE";
    }
    else if (result == XR_ERROR_OUT_OF_MEMORY) {
        msg += "XR_ERROR_OUT_OF_MEMORY";
    }
    else if (result == XR_ERROR_API_VERSION_UNSUPPORTED) {
        msg += "XR_ERROR_API_VERSION_UNSUPPORTED";
    }
    else if (result == XR_ERROR_INITIALIZATION_FAILED) {
        msg += "XR_ERROR_INITIALIZATION_FAILED";
    }
    else if (result == XR_ERROR_FUNCTION_UNSUPPORTED) {
        msg += "XR_ERROR_FUNCTION_UNSUPPORTED";
    }
    else if (result == XR_ERROR_FEATURE_UNSUPPORTED) {
        msg += "XR_ERROR_FEATURE_UNSUPPORTED";
    }
    else if (result == XR_ERROR_EXTENSION_NOT_PRESENT) {
        msg += "XR_ERROR_EXTENSION_NOT_PRESENT";
    }
    else if (result == XR_ERROR_LIMIT_REACHED) {
        msg += "XR_ERROR_LIMIT_REACHED";
    }
    else if (result == XR_ERROR_SIZE_INSUFFICIENT) {
        msg += "XR_ERROR_SIZE_INSUFFICIENT";
    }
    else if (result == XR_ERROR_HANDLE_INVALID) {
        msg += "XR_ERROR_HANDLE_INVALID";
    }
    else if (result == XR_ERROR_INSTANCE_LOST) {
        msg += "XR_ERROR_INSTANCE_LOST";
    }
    else if (result == XR_ERROR_SESSION_RUNNING) {
        msg += "XR_ERROR_SESSION_RUNNING";
    }
    else if (result == XR_ERROR_SESSION_NOT_RUNNING) {
        msg += "XR_ERROR_SESSION_NOT_RUNNING";
    }
    else if (result == XR_ERROR_SESSION_LOST) {
        msg += "XR_ERROR_SESSION_LOST";
    }
    else if (result == XR_ERROR_SYSTEM_INVALID) {
        msg += "XR_ERROR_SYSTEM_INVALID";
    }
    else if (result == XR_ERROR_PATH_INVALID) {
        msg += "XR_ERROR_PATH_INVALID";
    }
    else if (result == XR_ERROR_PATH_COUNT_EXCEEDED) {
        msg += "XR_ERROR_PATH_COUNT_EXCEEDED";
    }
    else if (result == XR_ERROR_PATH_FORMAT_INVALID) {
        msg += "XR_ERROR_PATH_FORMAT_INVALID";
    }
    else if (result == XR_ERROR_PATH_UNSUPPORTED) {
        msg += "XR_ERROR_PATH_UNSUPPORTED";
    }
    else if (result == XR_ERROR_LAYER_INVALID) {
        msg += "XR_ERROR_LAYER_INVALID";
    }
    else if (result == XR_ERROR_LAYER_LIMIT_EXCEEDED) {
        msg += "XR_ERROR_LAYER_LIMIT_EXCEEDED";
    }
    else if (result == XR_ERROR_SWAPCHAIN_RECT_INVALID) {
        msg += "XR_ERROR_SWAPCHAIN_RECT_INVALID";
    }
    else if (result == XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED) {
        msg += "XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED";
    }
    else if (result == XR_ERROR_ACTION_TYPE_MISMATCH) {
        msg += "XR_ERROR_ACTION_TYPE_MISMATCH";
    }
    else if (result == XR_ERROR_SESSION_NOT_READY) {
        msg += "XR_ERROR_SESSION_NOT_READY";
    }
    else if (result == XR_ERROR_SESSION_NOT_STOPPING) {
        msg += "XR_ERROR_SESSION_NOT_STOPPING";
    }
    else if (result == XR_ERROR_TIME_INVALID) {
        msg += "XR_ERROR_TIME_INVALID";
    }
    else if (result == XR_ERROR_REFERENCE_SPACE_UNSUPPORTED) {
        msg += "XR_ERROR_REFERENCE_SPACE_UNSUPPORTED";
    }
    else if (result == XR_ERROR_FILE_ACCESS_ERROR) {
        msg += "XR_ERROR_FILE_ACCESS_ERROR";
    }
    else if (result == XR_ERROR_FILE_CONTENTS_INVALID) {
        msg += "XR_ERROR_FILE_CONTENTS_INVALID";
    }
    else if (result == XR_ERROR_FORM_FACTOR_UNSUPPORTED) {
        msg += "XR_ERROR_FORM_FACTOR_UNSUPPORTED";
    }
    else if (result == XR_ERROR_FORM_FACTOR_UNAVAILABLE) {
        msg += "XR_ERROR_FORM_FACTOR_UNAVAILABLE";
    }
    else if (result == XR_ERROR_API_LAYER_NOT_PRESENT) {
        msg += "XR_ERROR_API_LAYER_NOT_PRESENT";
    }
    else if (result == XR_ERROR_CALL_ORDER_INVALID) {
        msg += "XR_ERROR_CALL_ORDER_INVALID";
    }
    else if (result == XR_ERROR_GRAPHICS_DEVICE_INVALID) {
        msg += "XR_ERROR_GRAPHICS_DEVICE_INVALID";
    }
    else if (result == XR_ERROR_POSE_INVALID) {
        msg += "XR_ERROR_POSE_INVALID";
    }
    else if (result == XR_ERROR_INDEX_OUT_OF_RANGE) {
        msg += "XR_ERROR_INDEX_OUT_OF_RANGE";
    }
    else if (result == XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED) {
        msg += "XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED";
    }
    else if (result == XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED) {
        msg += "XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED";
    }
    else if (result == XR_ERROR_NAME_DUPLICATED) {
        msg += "XR_ERROR_NAME_DUPLICATED";
    }
    else if (result == XR_ERROR_NAME_INVALID) {
        msg += "XR_ERROR_NAME_INVALID";
    }
    else if (result == XR_ERROR_ACTIONSET_NOT_ATTACHED) {
        msg += "XR_ERROR_ACTIONSET_NOT_ATTACHED";
    }
    else if (result == XR_ERROR_ACTIONSETS_ALREADY_ATTACHED) {
        msg += "XR_ERROR_ACTIONSETS_ALREADY_ATTACHED";
    }
    else if (result == XR_ERROR_LOCALIZED_NAME_DUPLICATED) {
        msg += "XR_ERROR_LOCALIZED_NAME_DUPLICATED";
    }
    else if (result == XR_ERROR_LOCALIZED_NAME_INVALID) {
        msg += "XR_ERROR_LOCALIZED_NAME_INVALID";
    }
    else if (result == XR_ERROR_GRAPHICS_REQUIREMENTS_CALL_MISSING) {
        msg += "XR_ERROR_GRAPHICS_REQUIREMENTS_CALL_MISSING";
    }
    else if (result == XR_ERROR_RUNTIME_UNAVAILABLE) {
        msg += "XR_ERROR_RUNTIME_UNAVAILABLE";
    }
    else if (result == XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR) {
        msg += "XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR";
    }
    else if (result == XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR) {
        msg += "XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR";
    }
    else if (result == XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT) {
        msg += "XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT";
    }
    else if (result == XR_ERROR_SECONDARY_VIEW_CONFIGURATION_TYPE_NOT_ENABLED_MSFT) {
        msg += "XR_ERROR_SECONDARY_VIEW_CONFIGURATION_TYPE_NOT_ENABLED_MSFT";
    }
    else if (result == XR_ERROR_CONTROLLER_MODEL_KEY_INVALID_MSFT) {
        msg += "XR_ERROR_CONTROLLER_MODEL_KEY_INVALID_MSFT";
    }
    else if (result == XR_ERROR_REPROJECTION_MODE_UNSUPPORTED_MSFT) {
        msg += "XR_ERROR_REPROJECTION_MODE_UNSUPPORTED_MSFT";
    }
    else if (result == XR_ERROR_COMPUTE_NEW_SCENE_NOT_COMPLETED_MSFT) {
        msg += "XR_ERROR_COMPUTE_NEW_SCENE_NOT_COMPLETED_MSFT";
    }
    else if (result == XR_ERROR_SCENE_COMPONENT_ID_INVALID_MSFT) {
        msg += "XR_ERROR_SCENE_COMPONENT_ID_INVALID_MSFT";
    }
    else if (result == XR_ERROR_SCENE_COMPONENT_TYPE_MISMATCH_MSFT) {
        msg += "XR_ERROR_SCENE_COMPONENT_TYPE_MISMATCH_MSFT";
    }
    else if (result == XR_ERROR_SCENE_MESH_BUFFER_ID_INVALID_MSFT) {
        msg += "XR_ERROR_SCENE_MESH_BUFFER_ID_INVALID_MSFT";
    }
    else if (result == XR_ERROR_SCENE_COMPUTE_FEATURE_INCOMPATIBLE_MSFT) {
        msg += "XR_ERROR_SCENE_COMPUTE_FEATURE_INCOMPATIBLE_MSFT";
    }
    else if (result == XR_ERROR_SCENE_COMPUTE_CONSISTENCY_MISMATCH_MSFT) {
        msg += "XR_ERROR_SCENE_COMPUTE_CONSISTENCY_MISMATCH_MSFT";
    }
    else if (result == XR_ERROR_DISPLAY_REFRESH_RATE_UNSUPPORTED_FB) {
        msg += "XR_ERROR_DISPLAY_REFRESH_RATE_UNSUPPORTED_FB";
    }
    else if (result == XR_ERROR_COLOR_SPACE_UNSUPPORTED_FB) {
        msg += "XR_ERROR_COLOR_SPACE_UNSUPPORTED_FB";
    }
    else if (result == XR_ERROR_SPACE_COMPONENT_NOT_SUPPORTED_FB) {
        msg += "XR_ERROR_SPACE_COMPONENT_NOT_SUPPORTED_FB";
    }
    else if (result == XR_ERROR_SPACE_COMPONENT_NOT_ENABLED_FB) {
        msg += "XR_ERROR_SPACE_COMPONENT_NOT_ENABLED_FB";
    }
    else if (result == XR_ERROR_SPACE_COMPONENT_STATUS_PENDING_FB) {
        msg += "XR_ERROR_SPACE_COMPONENT_STATUS_PENDING_FB";
    }
    else if (result == XR_ERROR_SPACE_COMPONENT_STATUS_ALREADY_SET_FB) {
        msg += "XR_ERROR_SPACE_COMPONENT_STATUS_ALREADY_SET_FB";
    }
    else if (result == XR_ERROR_UNEXPECTED_STATE_PASSTHROUGH_FB) {
        msg += "XR_ERROR_UNEXPECTED_STATE_PASSTHROUGH_FB";
    }
    else if (result == XR_ERROR_FEATURE_ALREADY_CREATED_PASSTHROUGH_FB) {
        msg += "XR_ERROR_FEATURE_ALREADY_CREATED_PASSTHROUGH_FB";
    }
    else if (result == XR_ERROR_FEATURE_REQUIRED_PASSTHROUGH_FB) {
        msg += "XR_ERROR_FEATURE_REQUIRED_PASSTHROUGH_FB";
    }
    else if (result == XR_ERROR_NOT_PERMITTED_PASSTHROUGH_FB) {
        msg += "XR_ERROR_NOT_PERMITTED_PASSTHROUGH_FB";
    }
    else if (result == XR_ERROR_INSUFFICIENT_RESOURCES_PASSTHROUGH_FB) {
        msg += "XR_ERROR_INSUFFICIENT_RESOURCES_PASSTHROUGH_FB";
    }
    else if (result == XR_ERROR_UNKNOWN_PASSTHROUGH_FB) {
        msg += "XR_ERROR_UNKNOWN_PASSTHROUGH_FB";
    }
    else if (result == XR_ERROR_RENDER_MODEL_KEY_INVALID_FB) {
        msg += "XR_ERROR_RENDER_MODEL_KEY_INVALID_FB";
    }
    else if (result == XR_RENDER_MODEL_UNAVAILABLE_FB) {
        msg += "XR_RENDER_MODEL_UNAVAILABLE_FB";
    }
    else if (result == XR_ERROR_MARKER_NOT_TRACKED_VARJO) {
        msg += "XR_ERROR_MARKER_NOT_TRACKED_VARJO";
    }
    else if (result == XR_ERROR_MARKER_ID_INVALID_VARJO) {
        msg += "XR_ERROR_MARKER_ID_INVALID_VARJO";
    }
    else if (result == XR_ERROR_SPATIAL_ANCHOR_NAME_NOT_FOUND_MSFT) {
        msg += "XR_ERROR_SPATIAL_ANCHOR_NAME_NOT_FOUND_MSFT";
    }
    else if (result == XR_ERROR_SPATIAL_ANCHOR_NAME_INVALID_MSFT) {
        msg += "XR_ERROR_SPATIAL_ANCHOR_NAME_INVALID_MSFT";
    }
    else if (result == XR_RESULT_MAX_ENUM) {
        msg += "XR_RESULT_MAX_ENUM";
    }
    else if (result == XR_TIMEOUT_EXPIRED) {
        msg += "XR_RESULT_MAX_ENUM";
    }

    else
    {
        char resultString[XR_MAX_RESULT_STRING_SIZE];
        xrResultToString(instance, result, resultString);
        msg += resultString;
    }
}
#endif // ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
// returns the preferred swapchain format if it is supported
// else:
// - if fallback is true, return the first supported format
// - if fallback is false, return -1
int64_t OpenXRInstance::Get_Swapchain_Format(XrInstance instance,
    XrSession session,
    int64_t preferred_format,
    bool fallback)
{
    XrResult result;

    uint32_t swapchain_format_count;
    result = xrEnumerateSwapchainFormats(session, 0, &swapchain_format_count, NULL);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to create XR instance";
        return false;
    }

    printf("Runtime supports %d swapchain formats\n", swapchain_format_count);
    int64_t* swapchain_formats = (int64_t*)malloc(sizeof(int64_t) * swapchain_format_count);
    result = xrEnumerateSwapchainFormats(session, swapchain_format_count, &swapchain_format_count,
        swapchain_formats);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to create XR instance";
        return false;
    }

    int64_t chosen_format = fallback ? swapchain_formats[0] : -1;

    for (uint32_t i = 0; i < swapchain_format_count; i++) {
        if (swapchain_formats[i] == preferred_format) {
            chosen_format = swapchain_formats[i];
            break;
        }
    }


    free(swapchain_formats);

    return chosen_format;
}
#endif // ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)

bool OpenXRInstance::BeginUpdate() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    PROFILE_GPU_CPU("OpenXR Instance Begin Update");
    {
        PROFILE_GPU_CPU("Poll Events");
        XrEventDataBuffer runtime_event = { XR_TYPE_EVENT_DATA_BUFFER };
        auto result = xrPollEvent(instance, &runtime_event);
        if (!XR_SUCCEEDED(result))
        {
            msg = "PollEvent was not successful";
            return false;
        }

        switch (runtime_event.type) {
        case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED: {
            XrEventDataSessionStateChanged* event = (XrEventDataSessionStateChanged*)&runtime_event;
            switch (event->state) {
            case XR_SESSION_STATE_MAX_ENUM: // must be a bug
            case XR_SESSION_STATE_IDLE:
            case XR_SESSION_STATE_UNKNOWN: {
                return false;
                break;
            }
            case XR_SESSION_STATE_FOCUSED:
            case XR_SESSION_STATE_SYNCHRONIZED:
            case XR_SESSION_STATE_VISIBLE: {
                break;
            }
            case XR_SESSION_STATE_STOPPING: {
                FlaxXR::StopOpenXR();
                return false;
                break;
            }
            case XR_SESSION_STATE_READY: {
                // start session only if it is not running, i.e. not when we already called xrBeginSession
                // but the runtime did not switch to the next state yet
                if (!session_running) {
                    XrSessionBeginInfo session_begin_info = { XR_TYPE_SESSION_BEGIN_INFO };
                    session_begin_info.primaryViewConfigurationType = view_type;
                    result = xrBeginSession(session, &session_begin_info);
                    if (!XR_SUCCEEDED(result))
                    {
                        FlaxXR::StopOpenXR();
                        return false;
                    }
                    session_running = true;
                }
                return false;
            }
            case XR_SESSION_STATE_LOSS_PENDING:
            case XR_SESSION_STATE_EXITING:
                FlaxXR::StopOpenXR();
                return false;
                break;
            }
            break;
        }
        default:
            break;
        }
    }

    if (!session_running) {
        return false;
    }
    {
        PROFILE_GPU_CPU("xr Wait Frame");
        frame_state = { XR_TYPE_FRAME_STATE };
        XrFrameWaitInfo frame_wait_info = { XR_TYPE_FRAME_WAIT_INFO };
        auto result = xrWaitFrame(session, &frame_wait_info, &frame_state);
        if (!XR_SUCCEEDED(result))
        {
            msg = "xrWaitFrame() was not successful";
            return false;
        }
    }
    {
        PROFILE_GPU_CPU("XR Begin frame");

        // --- Begin frame
        XrFrameBeginInfo frame_begin_info = { XR_TYPE_FRAME_BEGIN_INFO };
        auto result = xrBeginFrame(session, &frame_begin_info);
        if (!XR_SUCCEEDED(result))
        {
            msg = "failed to begin frame!";
            return false;
        }
        {
            PROFILE_GPU_CPU("Acquire swapchain images");
            for (uint32_t i = 0; i < view_count; i++) {

                if (!frame_state.shouldRender) {
                    continue;
                }

                XrSwapchainImageAcquireInfo acquire_info = { XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO };

                uint32_t acquired_index;
                result = xrAcquireSwapchainImage(swapchains[i], &acquire_info, &acquired_index);
                if (!XR_SUCCEEDED(result))
                {
                    msg = "failed to acquire swapchain image!";
                    return false;
                }

                XrSwapchainImageWaitInfo wait_info = { XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO };
                wait_info.timeout = 1000;
                result = xrWaitSwapchainImage(swapchains[i], &wait_info);
                if (!XR_SUCCEEDED(result))
                {
                    msg = "failed to wait for swapchain image!";
                    return false;
                }

                uint32_t depth_acquired_index = UINT32_MAX;
                if (depth_supported) {
                    XrSwapchainImageAcquireInfo depth_acquire_info = { XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO };
                    result = xrAcquireSwapchainImage(depth_swapchains[i], &depth_acquire_info,
                        &depth_acquired_index);
                    if (!XR_SUCCEEDED(result))
                    {
                        msg = "failed to acquire swapchain image!";
                        return false;
                    }
                    XrSwapchainImageWaitInfo depth_wait_info = { XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO };
                    depth_wait_info.timeout = 1000;
                    result = xrWaitSwapchainImage(depth_swapchains[i], &depth_wait_info);
                    if (!XR_SUCCEEDED(result))
                    {
                        msg = "failed to wait for swapchain image!";
                        return false;
                    }
                }
            }
        }

        //{
        //    PROFILE_GPU_CPU("XR Locate View frame");
        //    XrViewLocateInfo view_locate_info = { XR_TYPE_VIEW_LOCATE_INFO };
        //    view_locate_info.viewConfigurationType = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO;
        //    view_locate_info.displayTime = frame_state.predictedDisplayTime;
        //    view_locate_info.space = play_space;

        //    view_state = { XR_TYPE_VIEW_STATE };
        //    auto result = xrLocateViews(session, &view_locate_info, &view_state, view_count, &view_count, views);
        //    if (!XR_SUCCEEDED(result))
        //    {
        //        msg = "Could not locate views";
        //        return false;
        //    }
        //}
    }

    return true;
#endif // ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    return false;
}


bool OpenXRInstance::EndUpdate() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    PROFILE_GPU_CPU("OpenXR Instance End Update");
    {
        PROFILE_GPU_CPU("Release Swapchain");
        for (uint32_t i = 0; i < view_count; i++) {

            XrSwapchainImageReleaseInfo release_info = { XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO };
            auto result = xrReleaseSwapchainImage(swapchains[i], &release_info);
            if (!XR_SUCCEEDED(result))
            {
                msg = "failed to release swapchain image!";
                return false;
            }

            if (depth_supported) {
                XrSwapchainImageReleaseInfo depth_release_info = { XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO };
                result = xrReleaseSwapchainImage(depth_swapchains[i], &depth_release_info);
                if (!XR_SUCCEEDED(result))
                {
                    msg = "failed to release swapchain image!";
                    return false;
                }
            }
        }
    }
    {
        PROFILE_GPU_CPU("End Frame");
        XrCompositionLayerProjection projection_layer = { XR_TYPE_COMPOSITION_LAYER_PROJECTION };
        projection_layer.layerFlags = 0;
        projection_layer.space = play_space;
        projection_layer.viewCount = view_count;
        projection_layer.views = projection_views;

        int submitted_layer_count = 1;
        const XrCompositionLayerBaseHeader* submitted_layers[1] = {
            (const XrCompositionLayerBaseHeader* const)&projection_layer };

        if ((view_state.viewStateFlags & XR_VIEW_STATE_ORIENTATION_VALID_BIT) == 0) {
            submitted_layer_count = 0;
        }

        if (!frame_state.shouldRender) {
            submitted_layer_count = 0;
        }

        XrFrameEndInfo frameEndInfo = { XR_TYPE_FRAME_END_INFO };
        frameEndInfo.displayTime = frame_state.predictedDisplayTime;
        frameEndInfo.layerCount = submitted_layer_count;
        frameEndInfo.layers = submitted_layers;
        frameEndInfo.environmentBlendMode = XR_ENVIRONMENT_BLEND_MODE_OPAQUE;
        
        auto result = xrEndFrame(session, &frameEndInfo);
        if (!XR_SUCCEEDED(result))
        {
            msg = "failed to end frame!";
            return false;
        }
    }
    return true;
#endif // ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    return false;
}




bool OpenXRInstance::Init() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    // --- Create XrInstance
#if (GRAPHICS_API_VULKAN & GRAPHICS_API_DIRECTX12 & GRAPHICS_API_DIRECTX11)
    const int enabled_ext_count = 3;
#elif (GRAPHICS_API_DIRECTX12 & GRAPHICS_API_DIRECTX11)
    const int enabled_ext_count = 2;
#elif (GRAPHICS_API_VULKAN & GRAPHICS_API_DIRECTX11)
    const int enabled_ext_count = 2;
#elif (GRAPHICS_API_VULKAN & GRAPHICS_API_DIRECTX12)
    const int enabled_ext_count = 2;
#elif (GRAPHICS_API_DIRECTX12)
    const int enabled_ext_count = 1;
#elif (GRAPHICS_API_DIRECTX11)
    const int enabled_ext_count = 1;
#elif (GRAPHICS_API_VULKAN)
    const int enabled_ext_count = 1;
#endif
    const char* enabled_exts[enabled_ext_count] =
    {
#ifdef XR_USE_GRAPHICS_API_VULKAN
        XR_KHR_VULKAN_ENABLE_EXTENSION_NAME,
#endif
#ifdef XR_USE_GRAPHICS_API_D3D11
        XR_KHR_D3D11_ENABLE_EXTENSION_NAME,
#endif
#ifdef XR_USE_GRAPHICS_API_D3D12
        XR_KHR_D3D12_ENABLE_EXTENSION_NAME,
#endif
    };
    msg = "Starting OpenXR";




    // xrEnumerate*() functions are usually called once with CapacityInput = 0.
    // The function will write the required amount into CountOutput. We then have
    // to allocate an array to hold CountOutput elements and call the function
    // with CountOutput as CapacityInput.
    uint32_t ext_count = 0;
    auto result = xrEnumerateInstanceExtensionProperties(NULL, 0, &ext_count, NULL);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to enumerate number of extension properties";
        return false;
    }


    XrExtensionProperties* ext_props = (XrExtensionProperties*)malloc(sizeof(XrExtensionProperties) * ext_count);
    for (uint16_t i = 0; i < ext_count; i++) {
        // we usually have to fill in the type (for validation) and set
        // next to NULL (or a pointer to an extension specific struct)
        ext_props[i].type = XR_TYPE_EXTENSION_PROPERTIES;
        ext_props[i].next = NULL;
    }

    result = xrEnumerateInstanceExtensionProperties(NULL, ext_count, &ext_count, ext_props);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to enumerate extension properties";
        return false;
    }

    for (uint32_t i = 0; i < ext_count; i++) {
#ifdef XR_USE_GRAPHICS_API_D3D11
        if (strcmp(XR_KHR_D3D11_ENABLE_EXTENSION_NAME, ext_props[i].extensionName) == 0) {
            dx11_supported = true;
        }
#endif
#ifdef XR_USE_GRAPHICS_API_D3D12
        if (strcmp(XR_KHR_D3D12_ENABLE_EXTENSION_NAME, ext_props[i].extensionName) == 0) {
            dx12_supported = true;
        }
#endif
#ifdef XR_USE_GRAPHICS_API_VULKAN
        if (strcmp(XR_KHR_VULKAN_ENABLE_EXTENSION_NAME, ext_props[i].extensionName) == 0) {
            dx12_supported = true;
        }
#endif
        if (strcmp(XR_KHR_COMPOSITION_LAYER_DEPTH_EXTENSION_NAME, ext_props[i].extensionName) == 0) {
            depth_supported = true;
        }
    }
    free(ext_props);

    if (!(dx11_supported || dx12_supported || vulkan_supported)) {
        msg = "Runtime does not support extensions!";
        return false;
    }


    XrInstanceCreateInfo instance_create_info = { XR_TYPE_INSTANCE_CREATE_INFO };
    instance_create_info.enabledExtensionCount = enabled_ext_count;
    instance_create_info.enabledExtensionNames = enabled_exts;
    auto settings = GameSettings::Get();
    snprintf(instance_create_info.applicationInfo.applicationName, sizeof(instance_create_info.applicationInfo.applicationName), "%ls", settings->ProductName.GetText());
    snprintf(instance_create_info.applicationInfo.engineName, sizeof(instance_create_info.applicationInfo.engineName), "Flax Engine");
    instance_create_info.applicationInfo.apiVersion = XR_CURRENT_API_VERSION;
    instance_create_info.applicationInfo.engineVersion = Globals::EngineBuildNumber;
    instance_create_info.applicationInfo.applicationVersion = 1;
#ifdef XR_USE_PLATFORM_ANDROID
    XrInstanceCreateInfoAndroidKHR create_android = { XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR };
    create_android.applicationVM = android_vm;//need to setup for flax
    create_android.applicationActivity = android_activity;//need to setup for flax
    instance_create_info.next = (void*)&create_android;
#endif
    result = xrCreateInstance(&instance_create_info, &instance);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to create XR instance";
        return false;
    }


    XrSystemGetInfo system_get_info = { XR_TYPE_SYSTEM_GET_INFO };
    system_get_info.formFactor = form_factor;
    system_get_info.next = NULL;

    result = xrGetSystem(instance, &system_get_info, &system_id);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to Get XR System";
        return false;
    }
    XrSystemProperties system_props = { XR_TYPE_SYSTEM_PROPERTIES };
    system_props.next = NULL;

    result = xrGetSystemProperties(instance, system_id, &system_props);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to Get XR System Properties";
        return false;
    }

    result = xrEnumerateViewConfigurationViews(instance, system_id, view_type, 0, &view_count, NULL);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to get view configuration view count!";
        return false;
    }

    viewconfig_views = (XrViewConfigurationView*)malloc(sizeof(XrViewConfigurationView) * view_count);
    for (uint32_t i = 0; i < view_count; i++) {
        viewconfig_views[i].type = XR_TYPE_VIEW_CONFIGURATION_VIEW;
        viewconfig_views[i].next = NULL;
    }

    result = xrEnumerateViewConfigurationViews(instance, system_id, view_type, view_count,
        &view_count, viewconfig_views);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to enumerate view configuration views!";
        return false;
    }

    if (GPUDevice::Instance == nullptr) {
        msg = "GPUDevice Instance not set";
        return false;
    }

#ifdef XR_USE_GRAPHICS_API_D3D11
    static PFN_xrGetD3D11GraphicsRequirementsKHR pfnGetD3D11GraphicsRequirementsKHR = NULL;
    XrGraphicsRequirementsD3D11KHR dx11_reqs = { XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR };
#endif
#ifdef XR_USE_GRAPHICS_API_D3D12
    static PFN_xrGetD3D12GraphicsRequirementsKHR pfnGetD3D12GraphicsRequirementsKHR = NULL;
    XrGraphicsRequirementsD3D12KHR dx12_reqs = { XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR };
#endif
#ifdef XR_USE_GRAPHICS_API_VULKAN
    static PFN_xrGetVulkanGraphicsRequirementsKHR pfnGetVulkanGraphicsRequirementsKHR = NULL;
    XrGraphicsRequirementsVulkanKHR vk_reqs = { XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR };
#endif

    void* targetBinding = nullptr;
    auto renderer = GPUDevice::Instance->GetRendererType();
    switch (renderer)
    {
    case RendererType::DirectX11:
#ifdef XR_USE_GRAPHICS_API_D3D11
        result = xrGetInstanceProcAddr(instance, "xrGetD3D11GraphicsRequirementsKHR",
            (PFN_xrVoidFunction*)&pfnGetD3D11GraphicsRequirementsKHR);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to Get xrGetD3D11GraphicsRequirementsKHR function!";
            return false;
        }
        result = pfnGetD3D11GraphicsRequirementsKHR(instance, system_id, &dx11_reqs);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to Get XrGraphics Requirements for D3D11!";
            return false;
        }

        graphics_binding_dx11 = { XR_TYPE_GRAPHICS_BINDING_D3D11_KHR };
        graphics_binding_dx11.device = ((GPUDeviceDX11*)GPUDevice::Instance)->GetDevice();
        targetBinding = &graphics_binding_dx11;
#else
        msg = "DirectX11 is lost";
        return false;
#endif
        break;
    case RendererType::DirectX12:
#ifdef XR_USE_GRAPHICS_API_D3D12
        result = xrGetInstanceProcAddr(instance, "xrGetD3D12GraphicsRequirementsKHR",
            (PFN_xrVoidFunction*)&pfnGetD3D12GraphicsRequirementsKHR);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to Get xrGetD3D12GraphicsRequirementsKHR function!";
            return false;
        }
        result = pfnGetD3D12GraphicsRequirementsKHR(instance, system_id, &dx12_reqs);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to Get XrGraphics Requirements for D3D12!";
            return false;
        }

        graphics_binding_dx12 = { XR_TYPE_GRAPHICS_BINDING_D3D12_KHR };
        graphics_binding_dx12.device = ((GPUDeviceDX12*)GPUDevice::Instance)->GetDevice();
        graphics_binding_dx12.queue = ((GPUDeviceDX12*)GPUDevice::Instance)->GetCommandQueueDX12();

        targetBinding = &graphics_binding_dx12;
#else
        msg = "DirectX12 is lost";
        return false;
#endif
        break;
    case RendererType::Vulkan:
#ifdef XR_USE_GRAPHICS_API_VULKAN
        result = xrGetInstanceProcAddr(instance, "xrGetVulkanGraphicsRequirementsKHR",
            (PFN_xrVoidFunction*)&pfnGetVulkanGraphicsRequirementsKHR);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to Get xrGetVulkanGraphicsRequirementsKHR function!";
            return false;
        }
        result = pfnGetVulkanGraphicsRequirementsKHR(instance, system_id, &vk_reqs);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to Get XrGraphics Requirements for Vulkan!";
            return false;
        }

        graphics_binding_vk = { XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR };
        graphics_binding_vk.device = ((GPUDeviceVulkan*)GPUDevice::Instance)->Device;
        graphics_binding_vk.instance = ((GPUDeviceVulkan*)GPUDevice::Instance)->Instance;
        graphics_binding_vk.physicalDevice = ((GPUDeviceVulkan*)GPUDevice::Instance)->Adapter->Gpu;
        graphics_binding_vk.queueFamilyIndex = ((GPUDeviceVulkan*)GPUDevice::Instance)->GraphicsQueue->GetFamilyIndex();
        graphics_binding_vk.queueIndex = ((GPUDeviceVulkan*)GPUDevice::Instance)->GraphicsQueue->GetQueueIndex();

        targetBinding = &graphics_binding_vk;
#else
        msg = "Vulkan is lost";
        return false;
#endif
        break;
    default:
        msg = "Not supported backend";
        return false;
        break;
    }

    if (targetBinding == nullptr) {
        msg = "Not supported backend";
        return false;
    }

    XrSessionCreateInfo session_create_info = { XR_TYPE_SESSION_CREATE_INFO };
    session_create_info.next = targetBinding;
    session_create_info.systemId = system_id;
    result = xrCreateSession(instance, &session_create_info, &session);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to create session!";
        return false;
    }


    identity_pose = {};
    identity_pose.orientation.x = 0;
    identity_pose.orientation.y = 0;
    identity_pose.orientation.z = 0;
    identity_pose.orientation.w = 1.0;
    identity_pose.position.x = 0;
    identity_pose.position.y = 0;
    identity_pose.position.z = 0;
    XrReferenceSpaceCreateInfo play_space_create_info = { XR_TYPE_REFERENCE_SPACE_CREATE_INFO };
    play_space_create_info.referenceSpaceType = play_space_type;
    play_space_create_info.poseInReferenceSpace = identity_pose;
    result = xrCreateReferenceSpace(session, &play_space_create_info, &play_space);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to create play space!";
        return false;
    }


    // --- Create Swapchains
    uint32_t swapchain_format_count;
    result = xrEnumerateSwapchainFormats(session, 0, &swapchain_format_count, NULL);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to get number of supported swapchain formats";
        return false;
    }

    int64_t* swapchain_formats = (int64_t*)malloc(sizeof(int64_t) * swapchain_format_count);;
    result = xrEnumerateSwapchainFormats(session, swapchain_format_count, &swapchain_format_count,
        swapchain_formats);
    if (!XR_SUCCEEDED(result)) {
        UpdateResultMSG(result);
        msg += " Failed to enumerate swapchain formats";
        return false;
    }
    int64_t color_format = -1;
    int64_t depth_format = -1;

    switch (renderer)
    {
    case RendererType::DirectX11:
#ifdef XR_USE_GRAPHICS_API_D3D11
        color_format = Get_Swapchain_Format(instance, session, DXGI_FORMAT_R8G8B8A8_UNORM_SRGB, true);
        depth_format = Get_Swapchain_Format(instance, session, DXGI_FORMAT_R32_FLOAT, false);
        if (depth_format < 0) {
            depth_supported = false;
        }
#endif
        break;
    case RendererType::DirectX12:
#ifdef XR_USE_GRAPHICS_API_D3D12
        color_format = Get_Swapchain_Format(instance, session, DXGI_FORMAT_R8G8B8A8_UNORM_SRGB, true);
        depth_format = Get_Swapchain_Format(instance, session, DXGI_FORMAT_R32_FLOAT, false);
        if (depth_format < 0) {
            depth_supported = false;
        }
#endif
        break;
    case RendererType::Vulkan:
#ifdef XR_USE_GRAPHICS_API_VULKAN
        color_format = Get_Swapchain_Format(instance, session, VK_FORMAT_R8G8B8A8_SRGB, true);
        depth_format = Get_Swapchain_Format(instance, session, VK_FORMAT_R32_SFLOAT, false);
        if (depth_format < 0) {
            depth_supported = false;
        }
#endif
        break;
    default:
        msg = "Failed to get swapchain formats but it should not be here";
        return false;
        break;
    }


    finalSwampChains = (GPUTexture***)malloc(sizeof(GPUTexture**) * view_count);
    renderBuffers = (RenderBuffers***)malloc(sizeof(RenderBuffers**) * view_count);
    renderTasks = (SceneRenderTask***)malloc(sizeof(SceneRenderTask**) * view_count);
    swapchains = (XrSwapchain*)malloc(sizeof(XrSwapchain) * view_count);
    swapchain_lengths = (uint32_t*)malloc(sizeof(uint32_t) * view_count);
    switch (renderer)
    {
    case RendererType::DirectX11:
#ifdef XR_USE_GRAPHICS_API_D3D11
        images_dx11 = (XrSwapchainImageD3D11KHR**)malloc(sizeof(XrSwapchainImageD3D11KHR*) * view_count);
#endif
        break;
    case RendererType::DirectX12:
#ifdef XR_USE_GRAPHICS_API_D3D12
        images_dx12 = (XrSwapchainImageD3D12KHR**)malloc(sizeof(XrSwapchainImageD3D12KHR*) * view_count);
#endif
        break;
    case RendererType::Vulkan:
#ifdef XR_USE_GRAPHICS_API_VULKAN
        images_vk = (XrSwapchainImageVulkanKHR**)malloc(sizeof(XrSwapchainImageVulkanKHR*) * view_count);
#endif
        break;
    default:
        break;
    }


    for (size_t i = 0; i < view_count; i++)
    {
        XrSwapchainCreateInfo swapchain_create_info = { XR_TYPE_SWAPCHAIN_CREATE_INFO };
        swapchain_create_info.usageFlags = XR_SWAPCHAIN_USAGE_SAMPLED_BIT | XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT;
        swapchain_create_info.createFlags = 0;
        swapchain_create_info.format = color_format;
        swapchain_create_info.sampleCount = viewconfig_views[i].recommendedSwapchainSampleCount;
        swapchain_create_info.width = viewconfig_views[i].recommendedImageRectWidth;
        swapchain_create_info.height = viewconfig_views[i].recommendedImageRectHeight;
        swapchain_create_info.faceCount = 1;
        swapchain_create_info.arraySize = 1;
        swapchain_create_info.mipCount = 1;

        result = xrCreateSwapchain(session, &swapchain_create_info, &swapchains[i]);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to create swapchain";
            return false;
        }
        result = xrEnumerateSwapchainImages(swapchains[i], 0, &swapchain_lengths[i], NULL);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to enumerate swapchains";
            return false;
        }
        renderBuffers[i] = (RenderBuffers**)malloc(sizeof(RenderBuffers*) * swapchain_lengths[i]);
        finalSwampChains[i] = (GPUTexture**)malloc(sizeof(GPUTexture*) * swapchain_lengths[i]);
        renderTasks[i] = (SceneRenderTask**)malloc(sizeof(SceneRenderTask*) * swapchain_lengths[i]);
        for (size_t j = 0; j < swapchain_lengths[i]; j++)
        {
            renderTasks[i][j] = new SceneRenderTask();
            renderTasks[i][j]->Resize(swapchain_create_info.width, swapchain_create_info.height);
            finalSwampChains[i][j] = GPUTexture::New();
            GPUTextureDescription desc = {};
            desc.Width = swapchain_create_info.width;
            desc.Height = swapchain_create_info.height;
            desc.Dimensions = TextureDimensions::Texture;
            desc.MipLevels = swapchain_create_info.mipCount;
            desc.ArraySize = swapchain_create_info.arraySize;
            desc.DefaultClearColor = Color(1, 1, 1);
            desc.Format = PixelFormat::R8G8B8A8_UNorm_sRGB;
            desc.Depth = 1;
            desc.MultiSampleLevel = MSAALevel::None;
            finalSwampChains[i][j]->Init(desc);
            renderTasks[i][j]->Output = finalSwampChains[i][j];
            renderTasks[i][j]->Order = -100;
            renderTasks[i][j]->View.Flags = ViewFlags::DefaultGame;
            renderTasks[i][j]->Enabled = true;
            renderBuffers[i][j] = renderTasks[i][j]->Buffers;
        }
        switch (renderer)
        {
        case RendererType::DirectX11:
#ifdef XR_USE_GRAPHICS_API_D3D11
            images_dx11[i] = (XrSwapchainImageD3D11KHR*)malloc(sizeof(XrSwapchainImageD3D11KHR) * swapchain_lengths[i]);
            for (size_t j = 0; j < swapchain_lengths[i]; j++)
            {
                images_dx11[i][j].type = XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR;
                images_dx11[i][j].next = NULL;
                images_dx11[i][j].texture = (ID3D11Texture2D*)finalSwampChains[i][j]->GetNativePtr();;
            }
            result =
                xrEnumerateSwapchainImages(swapchains[i], swapchain_lengths[i], &swapchain_lengths[i],
                    (XrSwapchainImageBaseHeader*)images_dx11[i]);
            if (!XR_SUCCEEDED(result)) {
                UpdateResultMSG(result);
                msg += " Failed to enumerate swapchain images";
                return false;
            }
#endif
            break;
        case RendererType::DirectX12:
#ifdef XR_USE_GRAPHICS_API_D3D12
            images_dx12[i] = (XrSwapchainImageD3D12KHR*)malloc(sizeof(XrSwapchainImageD3D12KHR) * swapchain_lengths[i]);
            for (size_t j = 0; j < swapchain_lengths[i]; j++)
            {
                images_dx12[i][j].type = XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR;
                images_dx12[i][j].next = NULL;
                images_dx12[i][j].texture = (ID3D12Resource*)finalSwampChains[i][j]->GetNativePtr();
            }
            result =
                xrEnumerateSwapchainImages(swapchains[i], swapchain_lengths[i], &swapchain_lengths[i],
                    (XrSwapchainImageBaseHeader*)images_dx12[i]);
            if (!XR_SUCCEEDED(result)) {
                UpdateResultMSG(result);
                msg += " Failed to enumerate swapchain images";
                return false;
            }
#endif
            break;
        case RendererType::Vulkan:
#ifdef XR_USE_GRAPHICS_API_VULKAN
            images_vk[i] = (XrSwapchainImageVulkanKHR*)malloc(sizeof(XrSwapchainImageVulkanKHR) * swapchain_lengths[i]);
            for (size_t j = 0; j < swapchain_lengths[i]; j++)
            {
                images_vk[i][j].type = XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR;
                images_vk[i][j].next = NULL;
                images_vk[i][j].image = *(VkImage*)finalSwampChains[i][j]->GetNativePtr();
            }
            result =
                xrEnumerateSwapchainImages(swapchains[i], swapchain_lengths[i], &swapchain_lengths[i],
                    (XrSwapchainImageBaseHeader*)images_vk[i]);
            if (!XR_SUCCEEDED(result)) {
                UpdateResultMSG(result);
                msg += " Failed to enumerate swapchain images";
                return false;
            }
#endif
            break;
        default:
            break;
        }
    };


    if (depth_supported) {

        depth_swapchains = (XrSwapchain*)malloc(sizeof(XrSwapchain) * view_count);
        depth_swapchain_lengths = (uint32_t*)malloc(sizeof(uint32_t) * view_count);
        switch (renderer)
        {
        case RendererType::DirectX11:
#ifdef XR_USE_GRAPHICS_API_D3D11
            depth_images_dx11 = (XrSwapchainImageD3D11KHR**)malloc(sizeof(XrSwapchainImageD3D11KHR*) * view_count);
#endif
            break;
        case RendererType::DirectX12:
#ifdef XR_USE_GRAPHICS_API_D3D12
            depth_images_dx12 = (XrSwapchainImageD3D12KHR**)malloc(sizeof(XrSwapchainImageD3D12KHR*) * view_count);
#endif
            break;
        case RendererType::Vulkan:
#ifdef XR_USE_GRAPHICS_API_VULKAN
            depth_images_vk = (XrSwapchainImageVulkanKHR**)malloc(sizeof(XrSwapchainImageVulkanKHR*) * view_count);
#endif
            break;
        default:
            break;
        }


        for (size_t i = 0; i < view_count; i++)
        {
            XrSwapchainCreateInfo swapchain_create_info = { XR_TYPE_SWAPCHAIN_CREATE_INFO };
            swapchain_create_info.usageFlags = XR_SWAPCHAIN_USAGE_SAMPLED_BIT | XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT;
            swapchain_create_info.createFlags = 0;
            swapchain_create_info.format = depth_format;
            swapchain_create_info.sampleCount = viewconfig_views[i].recommendedSwapchainSampleCount;
            swapchain_create_info.width = viewconfig_views[i].recommendedImageRectWidth;
            swapchain_create_info.height = viewconfig_views[i].recommendedImageRectHeight;
            swapchain_create_info.faceCount = 1;
            swapchain_create_info.arraySize = 1;
            swapchain_create_info.mipCount = 1;

            result = xrCreateSwapchain(session, &swapchain_create_info, &depth_swapchains[i]);
            if (!XR_SUCCEEDED(result)) {
                UpdateResultMSG(result);
                msg += " Failed to create swapchain";
                return false;
            }
            result = xrEnumerateSwapchainImages(depth_swapchains[i], 0, &depth_swapchain_lengths[i], NULL);
            if (!XR_SUCCEEDED(result)) {
                UpdateResultMSG(result);
                msg += " Failed to enumerate swapchains";
                return false;
            }
            switch (renderer)
            {
            case RendererType::DirectX11:
#ifdef XR_USE_GRAPHICS_API_D3D11
                depth_images_dx11[i] = (XrSwapchainImageD3D11KHR*)malloc(sizeof(XrSwapchainImageD3D11KHR) * depth_swapchain_lengths[i]);
                for (uint32_t j = 0; j < depth_swapchain_lengths[i]; j++) {
                    depth_images_dx11[i][j].type = XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR;
                    depth_images_dx11[i][j].next = NULL;
                    depth_images_dx11[i][j].texture = (ID3D11Texture2D*)renderBuffers[i][j]->DepthBuffer->GetNativePtr();
                }

                result =
                    xrEnumerateSwapchainImages(depth_swapchains[i], depth_swapchain_lengths[i], &depth_swapchain_lengths[i],
                        (XrSwapchainImageBaseHeader*)depth_images_dx11[i]);
                if (!XR_SUCCEEDED(result)) {
                    UpdateResultMSG(result);
                    msg += " Failed to enumerate swapchain images";
                    return false;
                }
#endif
                break;
            case RendererType::DirectX12:
#ifdef XR_USE_GRAPHICS_API_D3D12
                depth_images_dx12[i] = (XrSwapchainImageD3D12KHR*)malloc(sizeof(XrSwapchainImageD3D12KHR) * depth_swapchain_lengths[i]);
                for (size_t j = 0; j < swapchain_lengths[j]; j++)
                {
                    depth_images_dx12[i][j].type = XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR;
                    depth_images_dx12[i][j].next = NULL;
                    depth_images_dx12[i][j].texture = (ID3D12Resource*)renderBuffers[i][j]->DepthBuffer->GetNativePtr();
                }

                result =
                    xrEnumerateSwapchainImages(depth_swapchains[i], depth_swapchain_lengths[i], &depth_swapchain_lengths[i],
                        (XrSwapchainImageBaseHeader*)depth_images_dx12[i]);
                if (!XR_SUCCEEDED(result)) {
                    UpdateResultMSG(result);
                    msg += " Failed to enumerate swapchain images";
                    return false;
                }
#endif
                break;
            case RendererType::Vulkan:
#ifdef XR_USE_GRAPHICS_API_VULKAN
                depth_images_vk[i] = (XrSwapchainImageVulkanKHR*)malloc(sizeof(XrSwapchainImageVulkanKHR) * depth_swapchain_lengths[i]);
                for (size_t j = 0; j < swapchain_lengths[j]; j++)
                {
                    depth_images_vk[i][j].type = XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR;
                    depth_images_vk[i][j].next = NULL;
                    depth_images_vk[i][j].image = *(VkImage*)renderBuffers[i][j]->DepthBuffer->GetNativePtr();
                }


                result =
                    xrEnumerateSwapchainImages(depth_swapchains[i], depth_swapchain_lengths[i], &depth_swapchain_lengths[i],
                        (XrSwapchainImageBaseHeader*)depth_images_vk[i]);
                if (!XR_SUCCEEDED(result)) {
                    UpdateResultMSG(result);
                    msg += " Failed to enumerate swapchain images";
                    return false;
                }
#endif
                break;
            default:
                break;
            }
        };
    }

    views = (XrView*)malloc(sizeof(XrView) * view_count);
    for (uint32_t i = 0; i < view_count; i++) {
        views[i].type = XR_TYPE_VIEW;
        views[i].next = NULL;
    }

    projection_views = (XrCompositionLayerProjectionView*)malloc(
        sizeof(XrCompositionLayerProjectionView) * view_count);
    for (uint32_t i = 0; i < view_count; i++) {
        projection_views[i].type = XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW;
        projection_views[i].next = NULL;

        projection_views[i].subImage.swapchain = swapchains[i];
        projection_views[i].subImage.imageArrayIndex = 0;
        projection_views[i].subImage.imageRect.offset.x = 0;
        projection_views[i].subImage.imageRect.offset.y = 0;
        projection_views[i].subImage.imageRect.extent.width =
            viewconfig_views[i].recommendedImageRectWidth;
        projection_views[i].subImage.imageRect.extent.height =
            viewconfig_views[i].recommendedImageRectHeight;
    };


    if (depth_supported) {
        depth_infos = (XrCompositionLayerDepthInfoKHR*)malloc(sizeof(XrCompositionLayerDepthInfoKHR) *
            view_count);
        for (uint32_t i = 0; i < view_count; i++) {
            depth_infos[i].type = XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR;
            depth_infos[i].next = NULL;
            depth_infos[i].minDepth = 0.f;
            depth_infos[i].maxDepth = 1.f;
            depth_infos[i].nearZ = 10;
            depth_infos[i].farZ = 40000;

            depth_infos[i].subImage.swapchain = depth_swapchains[i];
            depth_infos[i].subImage.imageArrayIndex = 0;
            depth_infos[i].subImage.imageRect.offset.x = 0;
            depth_infos[i].subImage.imageRect.offset.y = 0;
            depth_infos[i].subImage.imageRect.extent.width =
                viewconfig_views[i].recommendedImageRectWidth;
            depth_infos[i].subImage.imageRect.extent.height =
                viewconfig_views[i].recommendedImageRectHeight;

            // depth is chained to projection, not submitted as separate layer
            projection_views[i].next = &depth_infos[i];
        };
    }



    msg = "Started OpenXR";
    return true;
#else // OPENXR_SUPPORT
    return false;
#endif // OPENXR_SUPPORT
}

bool OpenXRInstance::Stop() {
#if ((GRAPHICS_API_VULKAN | GRAPHICS_API_DIRECTX12 | GRAPHICS_API_DIRECTX11) & OPENXR_SUPPORT)
    if (session != XR_NULL_HANDLE) {
        auto result = xrDestroySession(session);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to exit session!";
            return false;
        }
        session = XR_NULL_HANDLE;
    }

    if (instance != XR_NULL_HANDLE) {
        auto result = xrDestroyInstance(instance);
        if (!XR_SUCCEEDED(result)) {
            UpdateResultMSG(result);
            msg += " Failed to Destroy Instance!";
            return false;
        }
        instance = XR_NULL_HANDLE;
    }


    msg = "Stopped OpenXR";
    return true;
#else // OPENXR_SUPPORT
    return false;
#endif // OPENXR_SUPPORT
}
