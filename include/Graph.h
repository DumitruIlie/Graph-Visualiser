// Ilie Dumitru
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<string>
#include<vector>
#include"vec2.h"

/** Directed graph. Will change to make both directed and undirected graphs available.
  */
class Graph
{
public:
	std::vector<std::vector<int> > edges;
	std::vector<vec2i> positions;

	/** Loads the graph from a file. This function will change in the future based on graph file representation
	  * @param errorStream - In case of errors the error is specified by writing to the stream
	  * @return true if the graph was loaded or false on error
	  */
	bool loadFromFile(const std::string& fileName, std::ostream& errorStream = std::cerr);

	/** Renders the graph to the screen.
	  * @param errorStream - In case of errors the error is specified by writing to the stream
	  * @return true if the graph was rendered or false on error
	  */
	bool render(int window, std::ostream& errorStream = std::cerr) const;

	/** Processes the mouse movement which will move the nodes around. Currently not implemented.
	  * @param prev - previous mouse coordinates
	  * @param curr - current mouse coordinates
	  * @param pressed - is the left button pressed or not
	  */
	void processMouseInput(vec2i prev, vec2i curr, bool pressed);

	/** Resets the graph data.
	  */
	void reset();

	/** Sets the initial coordinates of the nodes. They are positioned in a circle with center given by the first parameter
	  * with radius given in the second parameter and going clockwise or counterclockwise based on the third parameter.
	  */
	void initPositions(vec2i center, int radius, bool clockwise = true);
};

#endif // GRAPH_H
