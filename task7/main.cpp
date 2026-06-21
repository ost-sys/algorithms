#include <iostream>
#include <vector>
#include <queue>
#include <climits>
// Вариант с файлом:
// #include <fstream>
using namespace std;

typedef pair<int,int> pii;

vector<int> dijkstra(vector<vector<pii>>& graph, int start, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [weight, neighbor] : graph[node]) {
            int new_dist = dist[node] + weight;
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cout << "Введите количество вершин и рёбер: ";
    cin >> n >> m;

    // Вариант с файлом:
    // ifstream f("input.txt");
    // f >> n >> m;
    // vector<vector<pii>> graph(n);
    // for (int i = 0; i < m; i++) {
    //     int u, v, w; f >> u >> v >> w;
    //     graph[u].push_back({w, v});
    // }
    // int start; f >> start;

    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cout << "Введите ребро (u v вес): ";
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    int start;
    cout << "Начальная вершина: ";
    cin >> start;

    vector<int> distances = dijkstra(graph, start, n);
    for (int i = 0; i < n; i++)
        cout << "До вершины " << i << ": " << distances[i] << endl;

    return 0;
}