package java_impl;

import java.util.LinkedList;

/**
 * Program to implement BFS algorithm
 * 
 * @author Manish
 *
 */
public class Graph {

	private int NUM_VERTICES; // num of vertices
	private LinkedList<Integer> adj[]; // adj list

	// constructor
	public Graph(int num) {
		NUM_VERTICES = num;
		adj = new LinkedList[NUM_VERTICES];
		for (int i = 0; i < NUM_VERTICES; i++) {
			adj[i] = new LinkedList<Integer>(); // create node
		}
	}

	public static void main(String[] args) {
		Graph graph = new Graph(4);

		graph.addEdge(0, 1);
		graph.addEdge(0, 2);
		graph.addEdge(0, 3);
		graph.addEdge(1, 2);
		graph.addEdge(2, 0);
		graph.addEdge(2, 3);
		graph.addEdge(3, 3);

		System.out.println("Breadth First Traversal starting from vertex 1");

		graph.bfs(1);
	}

	/**
	 * Add edge between two nodes
	 * 
	 * @param from
	 * @param to
	 */
	void addEdge(int from, int to) {
		adj[from].add(to);// adding edge in the list
	}

	/**
	 * Mark each vertex not visited
	 * 
	 * @return array of boolean
	 */
	boolean[] markAllNodeNotVisited() {
		boolean visited[] = new boolean[NUM_VERTICES];
		for (int i = 0; i < NUM_VERTICES; i++) {
			visited[i] = false;
		}
		return visited;
	}

	/**
	 * Method to print BFS
	 * @param startnode
	 */
	void bfs(int startnode) {
		boolean[] visited = markAllNodeNotVisited();
		LinkedList<Integer> queue = new LinkedList<Integer>(); // create a queue
																// for BFS
		// mark the start vertex visited
		visited[startnode] = true;
		queue.add(startnode); // add first node to queue
		int temp;
		while (!queue.isEmpty()) {
			// dequeue a vertex from queue
			temp = queue.poll();
			System.out.print(temp + "  "); // print node

			// loop through each adjecent node
			for (int node : adj[temp]) {
				if (visited[node] == false) {
					visited[node] = true;
					queue.add(node);
				}
			}
		}

	}

}
