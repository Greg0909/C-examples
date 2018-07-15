#include <iostream>
#include <stack>

using namespace std;
class Dfs_Example{

	//      0  1  2  3  4
	//	   ---------------
	//  0 | 0  1  1  0  0       
	//  1 | 0  0  1  0  0      
	//  2 | 1  0  0  1  0      
	//  3 | 0  0  0  1  1
	//  4 | 0  0  0  1  0
public:

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

	stack<int> nodeStack;
	int length = sizeof(*graph_conections)/sizeof(bool);
	

	void dfs(int index, bool *visitedx){
		cout<< index << " ";
		for(int h=0; h<length; h++){
			if(graph_conections[index][h]==1 && visitedx[h]==0){
				visitedx[h]=1;
				dfs(h, visitedx);
			}
		}
	}

	void method2(int start){
		bool visited[length];

		for(int z=0; z<length; z++)
			visited[z] = 0;
		
		visited[start] = 1;
		dfs(start, visited);
	}

	void method1(int start){
		bool visited[length];
		int actual_node = start;

		nodeStack.push(actual_node);
		visited[actual_node] = 1;
		cout << actual_node << " ";

		while(!nodeStack.empty()){
			for(int h=0; h < length && actual_node == nodeStack.top(); h++){
				if(graph_conections[actual_node][h]==1 && visited[h]==0){
					visited[h] = 1;
					nodeStack.push(h);
					cout << h << " ";
				}
			}
			if(actual_node == nodeStack.top())
				nodeStack.pop();

			actual_node = nodeStack.top();

		}
	}
};

int main(){
	Dfs_Example d;
	d.method2(0);
	return 0;
}