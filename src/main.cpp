#include"aStar.h"
using namespace AStar;
int input_map[row][column] = {
			 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			 {1,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1},
			 {1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
			 {1,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
			 {1,1,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1},
			 {1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
			 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
			 {1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1},
			 {1,0,0,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,0,1},
			 {1,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,1},
			 {1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1},
             {1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1},
			 {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1},
			 {1,1,1,0,0,1,1,1,0,0,1,1,0,1,1,1,0,0,0,1},
			 {1,0,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1},
			 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int main(void)
{
	window mainWindow;
    Node start = { 1,1,0 ,NULL };
	Node des = { 15,15,0,NULL};
	AStarSearch obj(start,des,input_map);
	while (mainWindow.getWindowHandle()->isOpen())
	{
		while (mainWindow.getWindowHandle()->pollEvent(*mainWindow.getEventHandle()))
		{
			if (mainWindow.getEventHandle()->type == sf::Event::Closed)
			{
				mainWindow.getWindowHandle()->close();
			}
		}
		obj.startSearch(&mainWindow);
		mainWindow.getWindowHandle()->display();
	}
	
}