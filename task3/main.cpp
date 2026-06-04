#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {3};
    graph[2] = {3};
    graph[3] = {4};
    graph[4] = {};

    int start = 0;
    vector<bool> visited(n, false);
    dfs(graph, start, visited);

    cout << "Достижимые вершины из " << start << ": ";
    for (int i = 0; i < n; i++) {
        if (visited[i] && i != start)
            cout << i << " ";
    }

    return 0;
}