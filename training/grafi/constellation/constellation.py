#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())

X = [0] * N
Y = [0] * N
for i in range(N):
    X[i], Y[i] = map(int, input().strip().split())


# insert your code here
# Create an empty graph
graph = {}

# Scan the matrix for 1s and add them to the graph as nodes
for i in range (0,N):
    graph[(Y[i],X[i])]=[]

# print(graph)
# for i in range(matrix.num_rows):
#   for j in range(matrix.num_cols):
#     if matrix[i][j] == 1:
#       graph[(i, j)] = []

# Connect the nodes with edges if there is an L-shaped link between them
for node in graph.keys():
  i, j = node
  if (i-1, j) in graph:
    graph[node].append((i-1, j))
  if (i+1, j) in graph:
    graph[node].append((i+1, j))
  if (i, j-1) in graph:
    graph[node].append((i, j-1))
  if (i, j+1) in graph:
    graph[node].append((i, j+1))

# Use BFS to find all the L-shaped links in the graph
visited = set()

def bfs(node):
  queue = [node]
  while queue:
    curr = queue.pop(0)
    if curr in visited:
      continue
    visited.add(curr)
    for neighbor in graph[curr]:
      queue.append(neighbor)

# Use bfs to find all the L-shaped links
for node in graph.keys():
  bfs(node)



# Count the number of L-shaped links by taking the length of the visited set
num_l_shaped_links = len(visited)
print(num_l_shaped_links)
#print(42)  # print the result
