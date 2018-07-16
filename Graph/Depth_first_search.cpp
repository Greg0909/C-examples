/*
	Example of Depth first search algorithm
*/
#include <iostream>
#include <stack>

using namespace std;
                                                            //Class that stores to different methods of making Depth 
                                                            //first search.
class Dfs_Example
{

	//      0  1  2  3  4
	//	   ---------------
	//  0 | 0  1  1  0  0       
	//  1 | 0  0  1  0  0      
	//  2 | 1  0  0  1  0      
	//  3 | 0  0  0  1  1
	//  4 | 0  0  0  1  0
	private:

                                                            //This is a graph connection map which serves to know what
                                                            //element is conected to other elements. Each 1 represents 
                                                            //a conection between the lable above with the lable on the
                                                            //side, in this specific direction (above -> side) not
                                                            //(side -> above)
	const bool graph_conections[5][5] = 
							{{0,1,1,0,0},
							 {0,0,1,0,0},
							 {1,0,0,1,0},
							 {0,0,0,1,1},
							 {0,0,0,1,0}};
	                                                         //This process needs a stack to record the nodes that had
	                                                         //been followed in a straight path until it reachs a dead 
	                                                         //end so it can return to the node that conects to an 
	                                                         //unvisited node, so it can follow a straight path until
	                                                         //it reaches a dead end and repeat this process until the 
	                                                         //stack gets empty.
	stack<int> nodeStack;
	int length = sizeof(*graph_conections)/sizeof(bool);
	
//=====================================================================================================================
	public:
	/*TASK-RECURSIVE*/
                                                            //Recursive method that uses the stack memory instead of a
                                                            //stack created with the standard library. When an 
                                                            //unvisited node is found: it is printed, set as visited
                                                            //and pushed to the stack. The second parameter is a 
                                                            //pointer to the array of visited that will be modified in
                                                            //each iteration of the recursive method.
	void dfs(int index, bool *visitedx){
		cout<< index << " ";
		for(int h=0; h<length; h++){
			if(graph_conections[index][h]==1 && visitedx[h]==0){
				visitedx[h]=1;
				dfs(h, visitedx);
			}
		}
	}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                            //Calls the recursive method giving it the starting node
                                                            //and the array of visited nodes.
	void method2(int start){
		bool visited[length];

		for(int z=0; z<length; z++)
			visited[z] = 0;

		visited[start] = 1; //sets as visited the starting node
		dfs(start, visited);
	}
	/*TASK-END*/

//---------------------------------------------------------------------------------------------------------------------

	/*TASK-WITH_STACK*/
                                                            //Dosent use the memory stack, instead it uses its own 
                                                            //stack to store the path of nodes.
	void method1(int start)
	{
		bool visited[length];
		int actual_node = start;

		nodeStack.push(actual_node);
		visited[actual_node] = 1;
		cout << actual_node << " ";

		while(!nodeStack.empty())
		{
			for(int h=0; h < length && actual_node == nodeStack.top(); h++)
			{
                                                            //If there is a connection to an unvisited node, it is 
                                                            //added to the stack, printed and set as visited,
				if(graph_conections[actual_node][h]==1 && visited[h]==0)
				{
					visited[h] = 1;
					nodeStack.push(h);
					cout << h << " ";
				}
			}
                                                            //When the actual_node and the top node of the stack are 
                                                            //the same it means that a dead end have been reached, so
                                                            //we should return to the previous node poping the top one.
			if(actual_node == nodeStack.top())
				nodeStack.pop();

			actual_node = nodeStack.top();

		}
	}
	/*TASK-END*/
};

//=====================================================================================================================

int main()
{
	Dfs_Example d;
	d.method2(0);
	return 0;
}