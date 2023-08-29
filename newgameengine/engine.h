
//my includes
#include "utils.h"
#include "platform.h"


class GameEngine
{
public:
	GameEngine() = default;
	~GameEngine() = default;

public:
	rcode ConstructWindow(int32_t screenwidth, int32_t screenheight, int32_t pixelwidth, int32_t pixelheight,
		bool fullscreen = false, bool vsync = false);
	rcode Start();
	
	bool CreateByUser();

	bool UpdateByUser(float deltatime);

	void UpdateWindowSize(int32_t x, int32_t y);
private:

	

	Platform* platform;
};


