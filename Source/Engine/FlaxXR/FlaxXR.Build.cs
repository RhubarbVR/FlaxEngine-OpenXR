using Flax.Build;
using Flax.Build.NativeCpp;
using System.IO;
/// <summary>
/// XR module.
/// </summary>
public class FlaxXR : EngineModule
{
    private static bool _logMissingVulkanSDK;

    /// <inheritdoc />
    public override void Setup(BuildOptions options)
    {
        base.Setup(options);

        options.PrivateDependencies.Add("Graphics");
        options.PrivateDependencies.Add("Renderer");
        switch (options.Platform.Target)
        {
            case TargetPlatform.Windows:
                options.PrivateDependencies.Add("GraphicsDeviceNull");
                options.PrivateDependencies.Add("GraphicsDeviceDX11");
                if (VulkanSdk.Instance.IsValid)
                    options.PrivateDependencies.Add("GraphicsDeviceVulkan");
                else
                    Log.WarningOnce(string.Format("Building for {0} without Vulkan rendering backend (Vulkan SDK is missing)", options.Platform.Target), ref _logMissingVulkanSDK);
                var windowsToolchain = options.Toolchain as Flax.Build.Platforms.WindowsToolchain;
                if (windowsToolchain != null && windowsToolchain.SDK != Flax.Build.Platforms.WindowsPlatformSDK.v8_1)
                    options.PrivateDependencies.Add("GraphicsDeviceDX12");
                else
                    Log.WarningOnce(string.Format("Building for {0} without Vulkan rendering backend (Vulkan SDK is missing)", options.Platform.Target), ref _logMissingVulkanSDK);
                break;
            case TargetPlatform.UWP:
                options.PrivateDependencies.Add("GraphicsDeviceDX11");
                break;
            case TargetPlatform.XboxOne:
            case TargetPlatform.XboxScarlett:
                options.PrivateDependencies.Add("GraphicsDeviceDX12");
                break;
            case TargetPlatform.Linux:
                options.PrivateDependencies.Add("GraphicsDeviceNull");
                if (VulkanSdk.Instance.IsValid)
                    options.PrivateDependencies.Add("GraphicsDeviceVulkan");
                else
                    Log.WarningOnce(string.Format("Building for {0} without Vulkan rendering backend (Vulkan SDK is missing)", options.Platform.Target), ref _logMissingVulkanSDK);
                break;
            case TargetPlatform.PS4:
                options.PrivateDependencies.Add("GraphicsDevicePS4");
                break;
            case TargetPlatform.PS5:
                options.PrivateDependencies.Add("GraphicsDevicePS5");
                break;
            case TargetPlatform.Android:
                options.PrivateDependencies.Add("GraphicsDeviceVulkan");
                break;
            case TargetPlatform.Switch:
                options.PrivateDependencies.Add("GraphicsDeviceVulkan");
                break;
            case TargetPlatform.Mac:
                options.PrivateDependencies.Add("GraphicsDeviceNull");
                if (VulkanSdk.Instance.IsValid)
                    options.PrivateDependencies.Add("GraphicsDeviceVulkan");
                else
                    Log.WarningOnce(string.Format("Building for {0} without Vulkan rendering backend (Vulkan SDK is missing)", options.Platform.Target), ref _logMissingVulkanSDK);
                break;
            default: throw new InvalidPlatformException(options.Platform.Target);
        }

        bool platformSupportsOpenXR;
        switch (options.Platform.Target)
        {
            case TargetPlatform.Windows:
                platformSupportsOpenXR = true;
                break;
            case TargetPlatform.UWP:
                platformSupportsOpenXR = true;
                break;
            case TargetPlatform.Linux:
                platformSupportsOpenXR = false;
                break;
            case TargetPlatform.Android:
                platformSupportsOpenXR = true;
                break;
            default:
                platformSupportsOpenXR = false;
                break;
        }
        if (platformSupportsOpenXR)
        {
            var depsRoot = options.DepsFolder;
            options.CompileEnv.PreprocessorDefinitions.Add("OPENXR_SUPPORT");
            switch (options.Platform.Target)
            {
                case TargetPlatform.Windows:
                    options.OutputFiles.Add(Path.Combine(depsRoot, "openxr_loader.lib"));
                    options.DependencyFiles.Add(Path.Combine(depsRoot, "openxr_loader.dll"));
                    break;
                case TargetPlatform.UWP:
                    options.OutputFiles.Add(Path.Combine(depsRoot, "openxr_loader.lib"));
                    options.DependencyFiles.Add(Path.Combine(depsRoot, "openxr_loader.dll"));
                    break;
                case TargetPlatform.Android:
                    options.DependencyFiles.Add(Path.Combine(depsRoot, "libopenxr_loader.so"));
                    break;
                default: throw new InvalidPlatformException(options.Platform.Target);
            }
        }
    }
}
