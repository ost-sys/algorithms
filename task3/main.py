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

# Вариант с файлом:
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     n, m = map(int, lines[0].split())
#     graph = {i: [] for i in range(n)}
#     for line in lines[1:m+1]:
#         u, v = map(int, line.split())
#         graph[u].append(v)
#     start = int(lines[m+1])

n, m = map(int, input("Введите количество вершин и рёбер: ").split())
graph = {i: [] for i in range(n)}
for _ in range(m):
    u, v = map(int, input("Введите ребро (u v): ").split())
    graph[u].append(v)  # ориентированный — только в одну сторону

start = int(input("Начальная вершина: "))
reachable = find_reachable(graph, start)
print("Достижимые вершины:", reachable)