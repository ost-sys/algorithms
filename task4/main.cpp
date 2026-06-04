#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

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
    graph[2] = {1};
    graph[3] = {4};
    graph[4] = {};

    vector<bool> visited(n, false);
    dfs(graph, 0, visited);

    return 0;
}