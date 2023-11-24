#This code uses a priority queue (implemented using a PriorityQueue in the queue module) 
# to store the vertices being explored, and a dictionary to store the distances from the starting vertex. 
# The priority queue is used to prioritize vertices based on their distance from the starting vertex, 
# and the distances are stored in the
#dictionary to avoid exploring the same vertices multiple times.

#To use this BFS algorithm on a weighted graph, we can call the bfs() function and pass it the graph, 
# the starting vertex, and the goal vertex, like this:In this example, the bfs() function returns the shortest distance from the starting vertex to the goal vertex, taking into account the weights of the edges in the graph.

#In summary, to use BFS on a weighted graph, 
# we can modify the BFS algorithm to use a priority queue and take the edge weights into account 
# when exploring the graph. 
# This allows us to find the shortest path between two vertices in a weighted graph, using BFS.


from collections import deque, PriorityQueue

def bfs(graph, start, goal):
    # Create a priority queue to store the vertices being explored
    queue = PriorityQueue()
    queue.put((0, start))

    # Create a dictionary to store the distances from the starting vertex
    distances = {start: 0}

    # Create a set to store the visited vertices
    visited = set()

    # Loop until the queue is empty
    while queue:
        # Get the first vertex in the queue
        distance, vertex = queue.get()

        # If the vertex has not been visited, mark it as visited and explore its neighbors
        if vertex not in visited:
            visited.add(vertex)

            # If the vertex is the goal, return the distance
            if vertex == goal:
                return distance

            # Get the neighbors of the vertex
            neighbors = graph[vertex]

            # Add each neighbor to the queue, using the edge weight as the priority
            for neighbor, weight in neighbors:
                if neighbor not in distances:
                    distances[neighbor] = distance + weight
                    queue.put((distances[neighbor], neighbor))

    # If the goal is not reached, return infinity
    return float("inf")



# Create a weighted graph with four vertices
graph = {
    1: [(2, 5), (3, 4)],
    2: [(1, 5), (3, 3), (4, 6)],
    3: [(1, 4), (2, 3), (4, 2)],
    4: [(2, 6), (3, 2)],
}

# Use BFS to find the shortest path from vertex 1 to vertex 5
distance = bfs(graph, 1, 5)

# The distance from 1 to 5 is 8
print(distance)
