#ifndef PLATFORM_H
#define PLATFORM_H
#include <windows.h>
#include "utils.h"
#include <string>
#include <iostream>
#include <streambuf>
#include <sstream>
#include <chrono>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <fstream>
#include <map>
#include <functional>

#include <array>
#include <cstring>


class Platform
{
public:
	Platform() = default;
	~Platform() = default;
	rcode ApplicationStartUp();
	rcode ApplicationCleanUp();
	rcode ThreadStartUp();
	rcode ThreadCleanUp();
	rcode CraeteGraphics(bool fullscreen, bool enablevsync, const vi2d& viewpos, const vi2d& viewsize);
	rcode MakeWindow(const vi2d& windowpos, vi2d& windowsize, bool fullscreeen);
	rcode SetWindowTitle(std::string& s);
	rcode HandleSystemEvent();
	static LRESULT CALLBACK WindowEvent(HWND window, UINT Message, WPARAM wParam, LPARAM lParam);
	void UpdateWindowSize(int32_t x, int32_t);
	void UpdateViewPort();

public:
	bool PixelCohesion = false;
	vi2d ScreenSize;
	vf2d InvScreenSize = { 1.0f / 256.0f, 1.0f / 240.0f };
	vi2d WindowSize;
	bool FullScreen = false;
	bool EnableVsync = false;
	vf2d Pixel = { 0.0f, 0.0f };
	vi2d PixelSize = { 0, 0 };

	HWND window;
 
};

#endif // 


