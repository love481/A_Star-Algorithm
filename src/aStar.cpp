#include"aStar.h"
int AStar::AStarSearch::totalNodeExpanded = 0;
void AStar::AStarSearch::drawRoute(window* mainWindow,Node* parentHead)
{    //start routing from the node other than start
	parentHead = parentHead->next;
	while (parentHead->next != NULL)
	{
		for (int i = 0; i < INT_MAX / 10; i++);
		input_map[parentHead->x][parentHead->y] = 7;
		mainWindow->getWindowHandle()->clear(sf::Color::White);
		mainWindow->drawMap(input_map);
		mainWindow->getWindowHandle()->display();
		parentHead = parentHead->next;
	}
}
AStar::AStarSearch::AStarSearch(struct Node& Start, struct Node& Des,int map[row][column])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			g_map[i][j] = (float)INT_MAX;
			f_map[i][j] = (float)INT_MAX;
			parent[i][j] = 0;
			input_map[i][j] = map[i][j];
		}
	}
	start = &Start;
	des = &Des;
	input_map[start->x][start->y] = 5;
	input_map[des->x][des->y] = 6;
	g_map[start->x][start->y] = 0;
	start->dist = 0;
	f_map[start->x][start->y] = calculateHeuristicValue(start->x,start->y);
}
AStar::Node* AStar::AStarSearch::getMinDistNode()
{
	Node* small =new Node();
	long lowCost = LONG_MAX;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (f_map[i][j] < lowCost) {
				small->x = i;
				small->y = j;
				lowCost = f_map[i][j];
			}
		}
	}
	return small;
}
void AStar::AStarSearch::startSearch(window *mainWindow)
{
	    mainWindow->getWindowHandle()->clear(sf::Color::White);
	    mainWindow->drawMap(input_map);
		input_map[start->x][start->y] = 5;
		input_map[des->x][des->y] = 6;
		Node* curr = getMinDistNode();
		if (isDestination(curr) || curr->dist == INT_MAX)
		{  
			Node* parentHead = route();
			drawRoute(mainWindow, parentHead);
			for (int i = 0; i < INT_MAX; i++);
			exit(0);
		}
		input_map[curr->x][curr->y] = 3;
		f_map[curr->x][curr->y] = (float)INT_MAX;
		for (int i = curr->x - 1; i <= curr->x + 1; i++)
		{
			for (int j = curr->y - 1; j <= curr->y + 1; j++)
			{
				if (isValidNode(i, j))
				{
					if (!isVisitedNode(i, j) && !isStart(i, j) && !isObstacle(i, j))
					{
						if (g_map[i][j] > g_map[curr->x][curr->y] + sqrt(pow((curr->x - i), 2) + pow((curr->y - j), 2)))
						{
							g_map[i][j] = static_cast<float>(g_map[curr->x][curr->y] + sqrt(pow((curr->x - i), 2) + pow((curr->y - j), 2)));
							f_map[i][j] = g_map[i][j]+ calculateHeuristicValue(i, j);
							parent[i][j] = oned_ind(curr);
						}
					}
				}
			}
		}
		for (int i = 0; i < INT_MAX / 10; i++);
		totalNodeExpanded++;
		std::cout << "node Expanded:" << totalNodeExpanded << std::endl;
}
// get manhattan heuristic 
float AStar::AStarSearch::calculateHeuristicValue(int i,int j)
{
	return static_cast<float>(fabs(i - des->x) + fabs(j - des->y));
}
// get linear onedimensional index
int AStar::AStarSearch::oned_ind(struct Node* curr)
{
	return curr->x + row * curr->y;
}
// get two dimensional index from single  linearindex
AStar::Node* AStar::AStarSearch::twod_ind(int ind)
{ 
	Node* twod = new Node();
	twod->x = static_cast<int>(ind%row);
	twod->y = static_cast<int>(floor(ind/ row));
	return twod;
}
bool AStar::AStarSearch::isDestination(struct Node* curr)
{
	if ((curr->x == des->x && curr->y == des->y))
	{
		return true;
	}
	return false;
}
bool AStar::AStarSearch::isObstacle(int i, int j)
{  // here i represents row from top to bottom and j as column from left to right
	if (input_map[i][j] == 1)
		return true;
	return false;
}
bool AStar::AStarSearch::isStart(int i, int j)
{  // here x represents row from top to bottom and column from left to right
	if (start->x == i && start->y == j)
		return true;
	return false;
}
bool AStar::AStarSearch::isValidNode(int i,int j)
{
	return (i >= 0) && (i < row) &&
		(j >= 0) && (j < column);
}
bool AStar::AStarSearch::isVisitedNode(int i, int j)
{
	if (input_map[i][j] == 3)
		return true;
	return false;
}
//start tracking the node from the destination to the start node
AStar::Node* AStar::AStarSearch::route(void)
{  
	Node* ptr = new Node();
	ptr = des;
	ptr->next = NULL;
	while (parent[ptr->x][ptr->y] != 0)
	{
		Node* Next = twod_ind(parent[ptr->x][ptr->y]);
		Next->next = ptr;
		ptr = Next;
	}
	return ptr;
}
