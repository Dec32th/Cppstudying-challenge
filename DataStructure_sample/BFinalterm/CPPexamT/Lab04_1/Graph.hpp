#pragma once

#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void BFS(int start) const {
        std::vector<bool> visited(V, false);
        std::queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            std::cout << v << " ";

            for (int u : adjList[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        std::cout << std::endl;
    }
};


