#include <iostream>
#include <vector>
#include <queue>
// Вариант с файлом:
// #include <fstream>
using namespace std;

void bfs(vector<vector<int>>& graph, int start, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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

    bfs(graph, start, n);

    return 0;
}