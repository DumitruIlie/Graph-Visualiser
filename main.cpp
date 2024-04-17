// Ilie Dumitru
#include<graphics.h>
#include"Graph.h"

bool isKeyPressed(int key)
{
	return GetKeyState(key) & 0x80000;
}

const int WindowWidth = GetSystemMetrics(SM_CXSCREEN), WindowHeight = GetSystemMetrics(SM_CYSCREEN);

int main()
{
	int window = initwindow(WindowWidth, WindowHeight, "Graph Visualiser", -3, -26, true);
	bool appRunning = true;
	Graph G;

	if(!G.loadFromFile("graph.in"))
	{
		closegraph(window);
		return 0;
	}

	G.initPositions(vec2i(WindowWidth / 2, WindowHeight / 2), 100, true);

	do
	{
		appRunning ^= isKeyPressed(VK_ESCAPE);

		setbkcolor(WHITE);
		cleardevice();

		if(!G.render(window))
			appRunning = false;

		swapbuffers();
	}while(appRunning);

	closegraph(window);
	return 0;
}