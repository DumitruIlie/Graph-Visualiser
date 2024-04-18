// Ilie Dumitru
#include"Graph.h"
#include<cmath>
#include<fstream>
#include<graphics.h>

bool Graph::loadFromFile(const std::string& fileName, std::ostream& errorStream)
{
	std::ifstream in(fileName.c_str());

	if(!in.is_open())
	{
		// The file could not be opened
		errorStream << "The graph could not be loaded because file \"" << fileName << "\" could not be loaded. Possible fix: Check if the file is in the right directory\n" << std::flush;
		return false;
	}

	reset();

    int N /*nodes*/, M /*edges*/;
    int i, a, b;

    in >> N >> M;
    if(in.fail())
	{
		errorStream << "The file does not start with the number of nodes followed by the number of edges. Possible issue: The file is in an old format\n" << std::flush;
		return false;
	}
    edges.resize(N);
    positions.resize(N);

    for(i = 0;i < M;++i)
	{
		in >> a >> b;
		if(in.fail())
		{
			errorStream << "Edge number " << i + 1 << " is wrong. Possible fix: Decrease the number of edges (second number in the file)\n" << std::flush;
			reset();
			return false;
		}
		edges[a].push_back(b);
	}

	return true;
}

bool Graph::render(int window, std::ostream& errorStream) const
{
	int i, j, N = (int)positions.size();

	if(N != (int)edges.size())
	{
		errorStream << "There was an error. The graph contains 2 different node counts\n" << std::flush;
		return false;
	}

	setfillstyle(1, WHITE);
	setcolor(BLACK);
	setlinestyle(0, 0, 3);

	for(i = 0;i < N;++i)
	{
		for(j = 0;j < (int)edges[i].size();++j)
		{
			// TODO: make arrow representation to show direction
			line(positions[i].x, positions[i].y, positions[edges[i][j]].x, positions[edges[i][j]].y);
		}
	}

	for(i = 0;i < N;++i)
	{
		// TODO: factor out the radius of the node
		fillellipse(positions[i].x, positions[i].y, 16, 16);

		std::stringstream label;
		label << i;
		outtextxy(positions[i].x - textwidth((char*)label.str().c_str()) / 2, positions[i].y - textheight((char*)label.str().c_str()) / 2, (char*)label.str().c_str());
	}

	return true;
}

void Graph::processMouseInput(vec2i prev, vec2i curr, bool pressed)
{
	int i, N = (int)positions.size();

	if(pressed)
	{
		for(i = 0;i < N;++i)
		{
			// TODO: factor out the radius of the node
			if((positions[i] - prev).lengthSquared() < 16 * 16)
			{
				positions[i] += curr - prev;
				break;
			}
		}
	}
}

void Graph::reset()
{
	edges.clear();
	positions.clear();
}

void Graph::initPositions(vec2i center, int radius, bool clockwise)
{
	int i, N = (int)edges.size(), dir = clockwise ? -1 : 1;
	const double PI = atan2(1, 0) * 2;

	positions.clear();
	positions.resize(edges.size());
	for(i = 0;i < N;++i)
		positions[i] = vec2i(center.x + radius * cos(PI * 2 * i / N * dir), center.y + radius * sin(PI * 2 * i / N * dir));
}