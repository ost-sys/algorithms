# Вариант с файлом:
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     n, m = map(int, lines[0].split())
#     graph = {i: [] for i in range(n)}
#     for line in lines[1:m+1]:
#         u, v = map(int, line.split())
#         graph[u].append(v)

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

n, m = map(int, input("Введите количество вершин и рёбер: ").split())
graph = {i: [] for i in range(n)}
for _ in range(m):
    u, v = map(int, input("Введите ребро (u v): ").split())
    graph[u].append(v)

result = find_universal_source(graph, n)
if result != -1:
    print(f"Вершина {result} достигает все остальные")
else:
    print("Такой вершины нет")