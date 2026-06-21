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
    int n, m;
    cout << "Введите количество вершин и рёбер: ";
    cin >> n >> m;

    // Вариант с файлом:
    // ifstream f("input.txt");
    // f >> n >> m;
    // vector<vector<int>> graph(n);
    // for (int i = 0; i < m; i++) {
    //     int u, v; f >> u >> v;
    //     graph[u].push_back(v); // ориентированный
    // }
    // int start; f >> start;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Введите ребро (u v): ";
        cin >> u >> v;
        graph[u].push_back(v); // ориентированный — только в одну сторону
    }

    int start;
    cout << "Начальная вершина: ";
    cin >> start;

    vector<bool> visited(n, false);
    dfs(graph, start, visited);

    cout << "Достижимые вершины из " << start << ": ";
    for (int i = 0; i < n; i++) {
        if (visited[i] && i != start)
            cout << i << " ";
    }

    return 0;
}