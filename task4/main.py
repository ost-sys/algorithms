def dfs_directed(graph, start, visited=None):
    if visited is None:
        visited = set()

    visited.add(start)
    print(start, end=" ")

    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs_directed(graph, neighbor, visited)

    return visited

graph = {
    0: [1, 2],
    1: [3],
    2: [1],
    3: [4],
    4: []
}

dfs_directed(graph, 0)