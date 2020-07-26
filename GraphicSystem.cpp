#include "GraphicSystem.h"
#include "D3DUtil.h"
#include <assert.h>

bool GraphicSystem::Initialize(const GraphicSystemInitParameters& param)
{
	mClientHeight = param.height;
	mClientWidth = param.width;
	mFullscreen = param.fullscreen;
	mMSAAEnabled = param.enableMSAA;

	if (!InitDeviceAndContext())
	{
		return false;
	}

	if (!CreateSwapChain())
	{
		Shutdown();
		return false;
	}
	return true;
}

void GraphicSystem::Shutdown()
{
	ReleaseCOM(md3dImmediateContext);
	ReleaseCOM(md3dDevice);
}

bool GraphicSystem::InitDeviceAndContext()
{
	UINT createDeviceFlags = 0;
#if defined(DEBUG) || defined (_DEBUG)
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
	md3dDriverType = D3D_DRIVER_TYPE_HARDWARE;
	D3D_FEATURE_LEVEL featureLevel;
	// TODO : No enumerations, use default device for now
	HRESULT hr = D3D11CreateDevice(0, md3dDriverType, 0, createDeviceFlags, 0, 0, D3D11_SDK_VERSION, &md3dDevice, &featureLevel, &md3dImmediateContext);

	if (FAILED(hr))
	{
		MessageBox(0, L"Failed to create a hardware D3D11 device", 0, 0);
	}

	if (featureLevel != D3D_FEATURE_LEVEL_11_0)
	{
		MessageBox(0, L"Direct3D feature level 11 unsupported", 0, 0);
	}

	return true;
}

bool GraphicSystem::CreateSwapChain()
{
	// Check for MSAA support even if not required.
	UINT      MSAAQuality4x;
	HRESULT hr = md3dDevice->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &MSAAQuality4x);
	if (FAILED(hr))
	{
		return false;
	}
	assert(MSAAQuality4x > 0);			// D3D11 feature level *always* supports this
	return true;
}