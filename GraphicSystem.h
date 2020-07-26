#pragma once
#include<Windows.h>
#include<d3d11.h>

struct GraphicSystemInitParameters
{
	int width;
	int height;
	bool fullscreen;
	bool enableMSAA;		// TODO : Will need more advanced MSAA controls
	HWND windowHandle;
};

class GraphicSystem
{
public:
	GraphicSystem() {};
	~GraphicSystem() {};

	bool Initialize(const GraphicSystemInitParameters& p);
	void Shutdown();

private:
	// Private Data
	UINT mClientWidth;
	UINT mClientHeight;
	bool mFullscreen;
	bool mMSAAEnabled;

	// D3D Data
	ID3D11Device* md3dDevice;
	ID3D11DeviceContext* md3dImmediateContext;
	D3D_DRIVER_TYPE md3dDriverType;

	// Private functions
	bool InitDeviceAndContext();
	bool CreateSwapChain();

};

