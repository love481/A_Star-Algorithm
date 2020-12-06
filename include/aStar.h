#pragma once
#ifndef ASTAR_H
#define ASTAR_H
#include"Window.h"
namespace AStar {
	struct Node 
	{ int x, y; 
	float dist;
	Node* next;
	};
	class AStarSearch
	{
	public:
		AStarSearch(struct Node& Start, struct Node& Des,int[row][column]);
		~AStarSearch() { }
		void startSearch(window *);
		void drawRoute(window* ,Node*);
		struct Node* getMinDistNode(void);
		float calculateHeuristicValue(int,int);
		int oned_ind(struct Node*);
		Node* route(void);
		struct Node* twod_ind(int);
		bool isDestination(struct Node*);
		bool isStart(int, int);
		bool isObstacle(int, int);
		bool isValidNode(int, int);
		bool isVisitedNode(int, int);
	private:
		int input_map[row][column];
		float f_map[row][column];
		float g_map[row][column];
		int parent[row][column];
		Node* start,* des;
		static int totalNodeExpanded;

	};
};
#endif //!ASTAR_H