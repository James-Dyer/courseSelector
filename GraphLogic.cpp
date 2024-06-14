#include <iostream>
#include <vector>
#include <stack>
#include "GraphLogic.h"

void Graph::DFS(int startVertex) {
    int V = requirements.size();
    std::vector<bool> visited(V, false); // Mark all vertices as not visited
    std::stack<int> stack;

    visited[startVertex] = true; // Mark the start vertex as visited
    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();
        std::cout << currentVertex << " "; // Process the current vertex

        // Visit all adjacent vertices of the current vertex
        /*
        for (int i = 0; i < requirements[currentVertex]; i++) {
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                stack.push(adjacentVertex);
            }
        }
        */
    }
}