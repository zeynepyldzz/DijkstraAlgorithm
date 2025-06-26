#include <limits.h>
#include <iostream>
#include <stdio.h>
#define V 9    // Number of vertices in the graph
using namespace std;
// A helper function to find the vertex with the minimum distance value
// set of vertices that are not yet included in the shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize minimum value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
// A helper function to print the generated distance array
int printSolution(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single-source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // Output array. dist[i] holds the shortest one
// distance from src to i

	bool sptSet[V]; // sptSet[i] is true if vertex i is included in the shortest 
	// path tree or shortest distance from src to i is terminated


	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

// Distance of source vertex from itself is always 0	dist[src] = 0;

	// Find the shortest path for all corners
	for (int count = 0; count < V - 1; count++) {
		// select minimum distance vertex from set of non-existent vertices
// just processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet);
// Initialize all distances to INFINITE and stpSet[] to false
// Mark the selected vertex as processed
		sptSet[u] = true;

		// Update the dist value of adjacent vertices of the selected vertex.
		for (int v = 0; v < V; v++)

		// update dist[v] only if not in sptSet, if there is an edge from there
// total weight of path from u to v and src from v to u
// less than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the generated distance array
	printSolution(dist, V);
}

// driver program to test the above function
int main()
{
		string satir1; string satir2; string satir3;string satir4;string satir5;string satir6;string satir7;
		string sutun1;string sutun2;string sutun3;string sutun4;string sutun5;string sutun6;string sutun7;
	    satir1=sutun1="Home";
	    satir2=sutun2="Beykoz Univercity";
	    satir3=sutun3="Atasehir";
	    satir4=sutun4="Kadikoy";
	    satir5=sutun5="Uskudar";
	    satir6=sutun6="Tepeustu";
	    satir7=sutun7="Mecidiyekoy";

	
	int graph[V][V] = { { 0 , 57, 54, 13, 76, 87, 13,23,25},
						{ 25, 0, 55, 35, 20, 20, 30 },
						{ 15, 55, 0, 20, 35,20, 53 },
						{ 30, 35,20, 0, 15, 35, 33 },
						{ 24,20, 35, 15, 0, 29, 18 },
						{ 5, 20, 20, 35, 29, 0, 47 },
						{ 42,30, 53, 33, 18, 47, 0 }
						 };
    
	dijkstra(graph, 0);


	return 0;
}

