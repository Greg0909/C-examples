/*
	Example of the algorithm "Breadth first search"
*/

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	//      0  1  2  3  4
	//	   ---------------
	//  0 | 0  1  1  0  0       
	//  1 | 0  0  1  0  0      
	//  2 | 1  0  0  1  0      
	//  3 | 0  0  0  1  1
	//  4 | 0  0  0  1  0

															//This is a graph connection map which serves to know what
															//element is conected to other elements. Each 1 represents 
															//a conection between the lable above with the lable on the
															//side, in this specific direction (above -> side) not
															//(side -> above)
	bool graph_conections[5][5] = 
							{{0,1,1,0,0},
							 {0,0,1,0,0},
							 {1,0,0,1,0},
							 {0,0,0,1,1},
							 {0,0,0,1,0}};
							 								//Creation of a deque (a queue with fordward and backward
							 								//conections). This will save the elements/nodes that will
							 								//be analised.
	std::deque<int> nodeList;

	int length = sizeof(*graph_conections)/sizeof(bool);
															//Saves if an elements have already been visited, it uses 
															//the array index to know which element is refering the 1
															//(visited) or 0 (not visited). An element or node cannot 
															//be added to de deque if itas marked as visited.
	bool visited[length] = {0,0,0,0,0};
	int actual_node = 0;
	nodeList.push_back(actual_node);
															//The actual_node (in this case 0) is marked as visited.
	visited[actual_node] = 1;
	cout<< "size " << length << endl;
															//The graph will be analised until the deque list is empty
	while(nodeList.empty() != true)
	{
		cout << actual_node <<" ";
															//Runs through all the connections of the actual_node to 
															//search for new nodes, the node enters to the nodeList 
															//if there is a connection and it havent been visited.
		for(int h = 0; h< length; h++){
			if(graph_conections[actual_node][h]==1 && visited[h]==0){
				nodeList.push_back(h);
				visited[h]=1;
			}
		}
															//The front node of the deque is the analized node, so when
															//the analise is finished, it is poped from the nodeList and 
															//the next element becomes the new actual_node until the 
															//nodeList is empty.
		nodeList.pop_front();
		actual_node = nodeList.front();

	}

	return 0;
}