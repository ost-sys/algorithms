import heapq
# Вариант с файлом:
# import heapq
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     n, m = map(int, lines[0].split())
#     graph = {i: [] for i in range(n)}
#     for line in lines[1:m+1]:
#         u, v, w = map(int, line.split())
#         graph[u].append((v, w))
#     start = int(lines[m+1])

def dijkstra(graph, start, n):
    dist = [float('inf')] * n
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        d, node = heapq.heappop(pq)

        if d > dist[node]:
            continue

        for neighbor, weight in graph[node]:
            new_dist = dist[node] + weight
            if new_dist < dist[neighbor]:
                dist[neighbor] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))

    return dist

n, m = map(int, input("Введите количество вершин и рёбер: ").split())
graph = {i: [] for i in range(n)}
for _ in range(m):
    u, v, w = map(int, input("Введите ребро (u v вес): ").split())
    graph[u].append((v, w))

start = int(input("Начальная вершина: "))
distances = dijkstra(graph, start, n)
for i, d in enumerate(distances):
    print(f"До вершины {i}: {d}")