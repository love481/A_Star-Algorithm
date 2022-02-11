# A* and dijkstra Algorithms
This repo consists of the code for implementing a shortest path using heuristic approach called A* and  dijkstra. SFML is used to visualize the operation of searching and tracing the shortest path in the grid map.

## Installation
Use a following command to clone the repository.

```bash
git clone https://github.com/love481/A_Star-Algorithm.git
```
```bash
sudo apt install cmake
```

## Usage
Navigate to the folder and run:
```bash 
cmake .
make && ./a_star
```
In order to run as dijkstra algorithm go to file aStar.cpp and comment line 81 and uncomment line 82 as :
```C++
//f_map[i][j] = g_map[i][j] + calculateHeuristicValue(i, j); //A* algorithms
f_map[i][j] = g_map[i][j]; //Dijkstra algorithms
```

# Demo 
**A_Star-Algorithm**

![image](https://user-images.githubusercontent.com/54012619/123632238-6b4de500-d837-11eb-9702-954516b3ba04.png)


**Dijkstra-Algorithm**

![Screenshot from 2022-02-11 14-02-45](https://user-images.githubusercontent.com/54012619/153559747-356bac30-3575-46ee-8ad8-63f6357731c3.png)
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[Apache](https://choosealicense.com/licenses/apache/)

