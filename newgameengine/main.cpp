#include "engine.h"

class test : public GameEngine
{
public:
	test() = default;

public:
	
};

int main()
{
	test t;
	if (t.ConstructWindow(400, 500, 1, 1))
	{
		t.Start();
	}


	return 0;
}