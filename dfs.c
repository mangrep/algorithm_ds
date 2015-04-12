/* Depth First Search Algorithm
 * using Adjacency Lists
 *
 * Authored by,
 * Manish Kumar
 */
 
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int val;
    struct node * next;
};
 
struct node * add(struct node * head, int num)
{
    /* We use Head Insertion for inserting vertices
     * into Linked List for O(1) Insertion.
     */
      
    struct node * p = (struct node *) malloc(sizeof(struct node));
     
    p->val = num;
    p->next = head;
     
    return p;
}
 
void depth_first_search_explore(struct node * list[], int parent[], int vertex, int status[])
{   
    if (parent[vertex] != -1) {
        //un-visited vertex
        struct node * temp = list[vertex];
        status[vertex] = 1;
         
        //recursively visit all vertices accessible from this Vertex
        while (temp != NULL) {
             
            if (parent[temp->val] == -1) {
                parent[temp->val] = vertex;
                //We started exploring from Vertex -'vertex',
                //so the Vertex - temp->val, it's
                //parent should be our initial vertex
                 
                depth_first_search_explore(list, parent, temp->val, status);
                //Then we recursively visit everything from the child vertex
            } else {
                //Checking if the edge is a Backward Edge
                if (status[temp->val] == 1) {
                    printf("\n%d ---> %d is a Backward Edge\n", vertex, temp->val);
                }
            }
             
            temp = temp->next;
            //After finishing, move on to next Vertex adjacent to
            //Vertex - 'vertex'
        }
         
        status[vertex] = 0;
    }
}
 
void depth_first_search(struct node * list[], int length, int parent[], int status[])
{
    int i;
     
    for (i = 1; i <= length; ++i) {
         
        if (parent[i] == -1) {
            parent[i] = 0;
            //It is a completely un-visited vertex and we start
            //our DFS from here, so it has no parent, but just
            //to mark it that we visited this node, we assign 0
             
            depth_first_search_explore(list, parent, i, status);
            //By this we begin to explore all the vertices reachable
            //from Vertex i
        }
    }
}
 
int main()
{
    int vertices, edges, i, j, v1, v2;
     
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);
     
    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);
     
    struct node * adjacency_list[vertices + 1];
    int parent[vertices + 1];
    int status[vertices + 1];
    //Size is made (vertices + 1) to use the
    //array as 1-indexed, for simplicity
     
    //Must initialize your array
    for (i = 0; i <= vertices; ++i) {
        adjacency_list[i] = NULL;
        parent[i] = -1;
        status[i] = 0;
    }
     
    printf("\n");
     
    for (i = 1; i <= edges; ++i) {
        scanf("%d%d", &v1, &v2);
        adjacency_list[v1] = add(adjacency_list[v1], v2);       //Adding edge v1 ------> v2
    }
  
    //Printing Adjacency List
    printf("\nAdjacency List -\n\n");
    for (i = 1; i <= vertices; ++i) {
        printf("adjacency_list[%d] -> ", i);
         
        struct node * temp = adjacency_list[i];
         
        while (temp != NULL) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
         
        printf("NULL\n");
    }
     
    depth_first_search(adjacency_list, vertices, parent, status);
     
    printf("\nParent Array -\n");
    for (i = 1; i <= vertices; ++i) {
        printf("Parent of Vertex %d = %d\n", i, parent[i]);
    }
     
    return 0;
}
