#pragma once

#include "OpenXRInstance.h"
#include "Engine/Core/Delegate.h"
#include "Engine/Core/Collections/Array.h"
#include "Engine/Scripting/ScriptingType.h"

/// <summary>
/// FlaxOpenXR Function Library
/// </summary>
API_CLASS(Static) class FLAXENGINE_API FlaxXR
{
    DECLARE_SCRIPTING_TYPE_MINIMAL(FlaxXR);
public:
    static OpenXRInstance* mainOpenXRInstance;
    static String msg;

    API_EVENT() static Delegate<bool> RunningStateChange;

    /// <summary>
    /// used for debuging and telling what error when Starting/Stoping OpenXR
    /// </summary>
    /// <returns></returns>
    API_FUNCTION() static String ErrorMessage();

    /// <summary>
    /// Checks If OpenXR is Supported On This Platform
    /// </summary>
    API_FUNCTION() static bool IsOpenXRSupported();

    /// <summary>
    /// Sets up OpenXR instance if one is not already running
    /// </summary>
    API_FUNCTION() static bool StartOpenXR();
    
    /// <summary>
    /// Stops OpenXR instance if one is running
    /// </summary>
    API_FUNCTION() static bool StopOpenXR();

    /// <summary>
    /// Starts OpenXR Instance
    /// </summary>
    API_FUNCTION() static bool OpenXRRunning();

};
