# Вариант с файлом:
# import sys
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     n, m = map(int, lines[0].split())
#     graph = {i: [] for i in range(n)}
#     for line in lines[1:m+1]:
#         u, v = map(int, line.split())
#         graph[u].append(v)
#     start = int(lines[m+1])

def dfs_directed(graph, start, visited=None):
    if visited is None:
        visited = set()

    visited.add(start)
    print(start, end=" ")

    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs_directed(graph, neighbor, visited)

    return visited

n, m = map(int, input("Введите количество вершин и рёбер: ").split())
graph = {i: [] for i in range(n)}
for _ in range(m):
    u, v = map(int, input("Введите ребро (u v): ").split())
    graph[u].append(v)

start = int(input("Начальная вершина: "))
dfs_directed(graph, start)