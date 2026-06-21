#include <iostream>
#include <vector>
#include <stack>
// Вариант с файлом:
// #include <fstream>
using namespace std;

int countReachable(vector<vector<int>>& graph, int start, int n) {
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            visited[node] = true;
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }

    int count = 0;
    for (bool v : visited) if (v) count++;
    return count;
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
    // }

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Введите ребро (u v): ";
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int v = 0; v < n; v++) {
        if (countReachable(graph, v, n) == n) {
            cout << "Вершина " << v << " достигает все остальные" << endl;
            return 0;
        }
    }

    cout << "Такой вершины нет" << endl;
    return 0;
}