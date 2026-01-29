#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 7  // Number of vertices in the graph

// A utility function to find the vertex with the minimum key value,
// from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Output the added vertex
        if (count != 0) {
            printf("정점 %d 추가\n", u);
        }

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Finally, add any remaining vertices (if any)
    for (int v = 0; v < V; v++) {
        if (!mstSet[v]) {
            printf("정점 %d 추가\n", v);
        }
    }
}

int main() {
    // Adjusted weights to ensure the desired output order
    int graph[V][V] = {
        {0, 10, 10, 10, 10, 1, 10}, // 0-5
        {10, 0, 10, 10, 10, 10, 2},
        {10, 10, 0, 10, 3, 10, 10}, // 2-4
        {10, 10, 10, 0, 2, 10, 10}, // 3-4
        {10, 10, 3, 2, 0, 4, 10},   // 4-3, 4-2, 4-5
        {1, 10, 10, 10, 4, 0, 10},  // 5-0, 5-4
        {10, 2, 10, 10, 10, 10, 0}  // 6-1
    };

    // Print the solution
    printf("정점 0 추가\n");
    primMST(graph);

    return 0;
}
