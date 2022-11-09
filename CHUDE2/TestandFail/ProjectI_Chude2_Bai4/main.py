from numpy import random
from datetime import datetime
import numpy as np

# Kruskal's algorithm without Disjoint-set Data structure


# Find set of vertex i
def find(i):
    while parent[i] != i:
        i = parent[i]
    return i


# Does union of i and j. It returns
# false if i and j are already in same
# set.
def union(i, j):
    a = find(i)
    b = find(j)
    parent[a] = b


# Finds MST using Kruskal's algorithm
def kruskalMST(cost):
    mincost = 0  # Cost of min MST

    # Initialize sets of disjoint sets
    for i in range(V):
        parent[i] = i

    # Include minimum weight edges one by one
    edge_count = 0
    while edge_count < V - 1:
        min = INF
        a = -1
        b = -1
        for i in range(V):
            for j in range(V):
                if find(i) != find(j) and cost[i][j] < min:
                    min = cost[i][j]
                    a = i
                    b = j
        union(a, b)
        print('Edge {}:({}, {}) cost:{}'.format(edge_count, a, b, min))
        edge_count += 1
        mincost += min

    print("Minimum cost= {}".format(mincost))


# Driver code
# Let us create the following graph
#         2 3
#     (0)--(1)--(2)
#     | / \ |
#     6| 8/ \5 |7
#     | /     \ |
#     (3)-------(4)
#         9

V = 1000
parent = [i for i in range(V)]
INF = 20
# cost = [[INF, 2, INF, 6, INF],
#         [2, INF, 3, 8, 5],
#         [INF, 3, INF, INF, 7],
#         [6, 8, INF, INF, 9],
#         [INF, 5, 7, 9, INF]]

cost = random.randint(1, 100, size = (V,V))

for i in range(V):
    cost[i][i] = INF

# Print the solution

start1 = datetime.now()
kruskalMST(cost)
end1 = datetime.now()

print("Time: ", end1 - start1)

