// Ilie Dumitru
#include<graphics.h>

bool isKeyPressed(int key)
{
	return GetKeyState(key)&0x80000;
}

const int WindowWidth = GetSystemMetrics(SM_CXSCREEN), WindowHeight = GetSystemMetrics(SM_CYSCREEN);

int main()
{
	int window = initwindow(WindowWidth, WindowHeight, "Graph Visualiser", -3, -26, true);
	bool appRunning = true;

	do
	{
		appRunning ^= isKeyPressed(VK_ESCAPE);
	}while(appRunning);

	closegraph(window);
	return 0;
}