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
    int n, m;
    cout << "Введите количество вершин и рёбер: ";
    cin >> n >> m;

    // Вариант с файлом:
    // ifstream f("input.txt");
    // f >> n >> m;
    // vector<vector<int>> graph(n);
    // for (int i = 0; i < m; i++) {
    //     int u, v; f >> u >> v;
    //     graph[u].push_back(v);
    //     graph[v].push_back(u);
    // }
    // int start; f >> start;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Введите ребро (u v): ";
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Начальная вершина: ";
    cin >> start;

    vector<bool> visited(n, false);
    dfs(graph, start, visited);

    return 0;
}