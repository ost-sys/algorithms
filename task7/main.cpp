#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
    int n = 5;
    vector<vector<pii>> graph(n);

    graph[0] = {{10, 1}, {3, 2}};
    graph[1] = {{2, 3}};
    graph[2] = {{4, 1}, {8, 3}};
    graph[3] = {{5, 4}};
    graph[4] = {};

    vector<int> distances = dijkstra(graph, 0, n);
    for (int i = 0; i < n; i++)
        cout << "До вершины " << i << ": " << distances[i] << endl;

    return 0;
}