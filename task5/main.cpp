#include <iostream>
#include <vector>
#include <stack>
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
    int n = 5;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {3};
    graph[2] = {3};
    graph[3] = {4};
    graph[4] = {};

    for (int v = 0; v < n; v++) {
        if (countReachable(graph, v, n) == n) {
            cout << "Вершина " << v << " достигает все остальные" << endl;
            return 0;
        }
    }

    cout << "Такой вершины нет" << endl;
    return 0;
}