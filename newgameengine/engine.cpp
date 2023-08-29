#include "engine.h"

rcode GameEngine::ConstructWindow(int32_t screenwidth, int32_t screenheight, int32_t pixelwidth,
    int32_t pixelheight, bool fullscreen, bool vsync)
{
    //platform->PixelCohesion = cohesion;
    platform->ScreenSize = { screenwidth, screenheight };
    platform->InvScreenSize = { 1.0f / float(screenwidth),1.0f / float(screenheight) };
    platform->PixelSize = { pixelwidth,pixelheight };
    platform->WindowSize = { platform->ScreenSize.x * platform->PixelSize.x,platform->ScreenSize.y * platform->PixelSize.y };

    if (platform->PixelSize.x <= 0 || platform->PixelSize.y <= 0 || platform->ScreenSize.x <= 0 || platform->ScreenSize.y <= 0)
        return rcode::FAIL;
    
    return rcode::OK;
}

rcode GameEngine::Start()
{
    
    if (platform->MakeWindow({ 30,30 }, platform->WindowSize, platform->FullScreen) != rcode::OK) return rcode::FAIL;

    return rcode::OK;
}


