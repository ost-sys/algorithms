def find_reachable(graph, start):
    visited = set()

    def dfs(node):
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                dfs(neighbor)

    dfs(start)
    visited.discard(start)
    return visited

graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: [4],
    4: []
}

reachable = find_reachable(graph, 0)
print("Достижимые вершины:", reachable)