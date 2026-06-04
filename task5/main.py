def find_universal_source(graph, n):
    def dfs(start):
        visited = set()
        stack = [start]
        while stack:
            node = stack.pop()
            if node not in visited:
                visited.add(node)
                for neighbor in graph[node]:
                    if neighbor not in visited:
                        stack.append(neighbor)
        return visited

    for v in range(n):
        reachable = dfs(v)
        if len(reachable) == n:
            return v

    return -1

graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: [4],
    4: []
}

n = 5
result = find_universal_source(graph, n)
if result != -1:
    print(f"Вершина {result} достигает все остальные")
else:
    print("Такой вершины нет")