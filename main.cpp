#include <limits.h>
#include <iostream>
#define V 9  // Number of vertices (nodes) fixed to 9
using namespace std;

// Function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the constructed distance array
int printSolution(int dist[], int n)
{
    for (int i = 0; i < V; i++) {
        printf("Shortest time from node 8 to %d is: %d minutes\n", i, dist[i]);
        if(dist[i] < 0) {
            cout << "Time cannot be negative!!" << endl;
            exit(0);
        }
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];  // The output array. dist[i] will hold the shortest distance from src to i

    bool sptSet[V];  // sptSet[i] will be true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if it is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is smaller
            // than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main()
{
    // Naming nodes for better understanding (not used in calculations)
    string node0 = "Gebze";
    string node1 = "Kavacik";
    string node2 = "Dudullu";
    string node3 = "Hacihalil";
    string node4 = "Kadikoy";
    string node5 = "Umraniye";
    string node6 = "Tuzla";
    string node7 = "Darica";
    string node8 = "Uskudar";

    cout << endl;
    cout << "Gebze: 0\nKavacik: 1\nDudullu: 2\nHacihalil: 3\nKadikoy: 4\nUmraniye: 5\nTuzla: 6\nDarica: 7\nUskudar: 8\n\n";

    // Distance adjacency matrix between nodes
    int graph[V][V] = { {  0 , 51, 54, 13, 73, 38, 13, 23, 25},
                        { 51,  0, 30, 44, 22, 13, 53, 79, 26},
                        { 54, 30,  0, 41, 52, 43, 67, 73, 56},
                        { 13, 44, 41,  0, 66, 57, 26, 32, 87},
                        { 73, 22, 52, 66,  0, 35, 75, 57, 48},
                        { 38, 13, 43, 57, 35,  0, 66, 68, 13},
                        { 13, 53, 67, 26, 75, 66,  0, 32, 87},
                        { 23, 79, 73, 32, 57, 68, 32,  0, 55},
                        { 25, 26, 56, 87, 48, 13, 87, 55,  0}
                      };

    dijkstra(graph, 8);  // Start from node 8 (Uskudar)

    return 0;
}

