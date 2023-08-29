#include "platform.h"

rcode Platform::ApplicationStartUp()
{
    return rcode();
}

rcode Platform::ApplicationCleanUp()
{
    return rcode();
}

rcode Platform::ThreadStartUp()
{
    return rcode();
}

rcode Platform::ThreadCleanUp()
{
    return rcode();
}

rcode Platform::CraeteGraphics(bool fullscreen, bool enablevsync, const vi2d& viewpos, const vi2d& viewsize)
{
    return rcode();
}

rcode Platform::MakeWindow(const vi2d& windowpos, vi2d& windowsize, bool fullscreeen)
{
    WNDCLASS window_class;
    window_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    window_class.hInstance = GetModuleHandle(nullptr);
    window_class.lpfnWndProc = WindowEvent;
    window_class.cbClsExtra = 0;
    window_class.cbWndExtra = 0;
    window_class.lpszMenuName = nullptr;
    window_class.hbrBackground = nullptr;
    window_class.lpszClassName = L"game engine";

    RegisterClass(&window_class);

    DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
    DWORD dwStyle = WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_THICKFRAME;

    vi2d TopLeft = windowpos;

    RECT WndRect = { 0,0, WindowSize.x, WindowSize.y };
    AdjustWindowRectEx(&WndRect, dwStyle, FALSE, dwExStyle);
    int width = WndRect.right - WndRect.left;
    int height = WndRect.bottom - WndRect.top;

    window = CreateWindowEx(dwExStyle, L"game engine", L"", dwStyle, TopLeft.x, TopLeft.y, width, height,
        NULL, NULL, GetModuleHandle(nullptr), this);

    return rcode::OK;

}

rcode Platform::SetWindowTitle(std::string& s)
{
    return rcode();
}

rcode Platform::HandleSystemEvent()
{
    return rcode();
}

LRESULT Platform::WindowEvent(HWND window, UINT Message, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(window, Message, wParam, lParam);
}

void Platform::UpdateWindowSize(int32_t x, int32_t y)
{
    WindowSize = { x, y };

}

void Platform::UpdateViewPort()
{

}

