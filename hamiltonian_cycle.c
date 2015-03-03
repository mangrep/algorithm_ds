/*Program to print hamiltomian cycle in a graph
	Author:Manish
	Please report any modification or error to manishchoudhary55@gmail.com

*/

#include<stdio.h>

#define NUMBEROFVERTEX 5
#define NV NUMBEROFVERTEX 

void printSolution(int path[]);


int isSafe(int v, int graph[NV][NV], int path[], int pos){
	int i;
	//if vertex is adjacent vertex
	if( graph[ path[pos-1] ][v] == 0 )
		return 0;  

	//vertex is already in considered in the path
	for ( i = 0; i < pos ; i++){
		if (path[i] == v)
			return 0;
	}
	
	return 1;
}
	
//hamiltonian circuit finder
int hamCycleUtil(int graph[NV][NV], int path[], int pos){
	int i;
	if(pos == NV){
		if (graph [path[pos-1]][path[0]] == 1)
			return 1;
		else
			return 0;	
	}

	for (i = 1 ; i < NV; i++){
		if(isSafe(i, graph, path, pos)){
			path[pos] = i;
			if (hamCycleUtil(graph, path, pos+1) == 1)					return 1;
			//remove the vertex does not lead to solution
			path[pos] = -1;
		}
	}
	//If no vertex can be added to Hamiltonian Cycle return 0
	return 0;
}

int hamCycle(int graph[NV][NV]){
	int i;
	int path[NV];
	for( i = 0; i < NV; i++ )
		path[i] = -1;
	path[0] = 0;
	if ( hamCycleUtil(graph, path, 1) == 0 ) {
		printf("\nSolution does not exists\n");
		return 0;
	}
	printSolution(path);
	return 1;
}

void printSolution(int path[]){
	int i ; 
	printf("Solution exists:\n");
	for ( i = 0; i < NV; i++)
		printf(" %d ",path[i]);
	printf(" %d\n", path[0]);
	
}

int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   int graph1[NV][NV] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 
    // Print the solution
    hamCycle(graph1);
 
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    int graph2[NV][NV] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
 
    // Print the solution
    hamCycle(graph2);
 
    return 0;
}
