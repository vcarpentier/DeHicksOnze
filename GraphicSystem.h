#pragma once
#include<Windows.h>

struct GraphicSystemInitParameters
{
	int width;
	int height;
	bool fullscreen;
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

};

