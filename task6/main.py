from collections import deque
# Вариант с файлом:
# from collections import deque
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     n, m = map(int, lines[0].split())
#     graph = {i: [] for i in range(n)}
#     for line in lines[1:m+1]:
#         u, v = map(int, line.split())
#         graph[u].append(v)
#         graph[v].append(u)
#     start = int(lines[m+1])

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

n, m = map(int, input("Введите количество вершин и рёбер: ").split())
graph = {i: [] for i in range(n)}
for _ in range(m):
    u, v = map(int, input("Введите ребро (u v): ").split())
    graph[u].append(v)
    graph[v].append(u)

start = int(input("Начальная вершина: "))
bfs(graph, start)