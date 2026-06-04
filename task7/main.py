import heapq

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

graph = {
    0: [(1, 10), (2, 3)],
    1: [(3, 2)],
    2: [(1, 4), (3, 8)],
    3: [(4, 5)],
    4: []
}

n = 5
distances = dijkstra(graph, 0, n)
for i, d in enumerate(distances):
    print(f"До вершины {i}: {d}")