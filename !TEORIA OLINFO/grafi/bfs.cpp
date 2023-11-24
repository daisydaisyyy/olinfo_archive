/*Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph) and explores the neighbor nodes first, before moving to the next level neighbors.

In BFS, you start at the root node and explore each neighboring node before moving on to any of their children. This means that you will explore all of a node's neighbors before exploring any of its children. This makes BFS a useful algorithm for finding the shortest path between two nodes in a graph, as it will always find the path with the fewest number of edges.

Here's how the algorithm works:

Start at the root node.

Explore all of the neighbor nodes of the root node, adding them to a queue.

Take the first node from the queue and explore all of its neighbor nodes. Add any unexplored neighbors to the queue.

Repeat step 3 until the queue is empty.

By following this process, you will explore the nodes of the graph in a breadth-first manner, meaning that you will explore all of the nodes at one depth level before moving on to the next depth level. This is why the algorithm is called breadth-first search.

I hope this helps! Let me know if you have any other questions.*/





#include <iostream>
#include <queue>
#include <unordered_map>

// This function performs a BFS search on a graph represented
// by an adjacency list, starting at the given source vertex.
void BFS(const std::unordered_map<int, std::vector<int>>& adj_list, int source)
{
    // Create a queue for storing the vertices that need to be
    // visited, and insert the source vertex into it.
    std::queue<int> q;
    q.push(source);

    // Create a map for storing the distances of the vertices
    // from the source vertex. Initially, all distances are
    // set to -1, except for the source vertex, which is set
    // to 0.
    std::unordered_map<int, int> distances;
    for (const auto& [vertex, neighbors] : adj_list) {
        distances[vertex] = -1;
    }
    distances[source] = 0;

    // Perform the BFS search.
    while (!q.empty()) {
        // Pop the front vertex from the queue and print it.
        int vertex = q.front();
        q.pop();
        std::cout << vertex << " ";

        // Get the neighbors of the current vertex and iterate
        // over them.
        const auto& neighbors = adj_list.at(vertex);
        for (int neighbor : neighbors) {
            // If the current neighbor has not been visited yet,
            // update its distance from the source vertex and
            // add it to the queue.
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[vertex] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    // Create an adjacency list for a graph with 5 vertices.
    std::unordered_map<int
