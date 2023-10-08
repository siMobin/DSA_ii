![MasterHead](https://res.cloudinary.com/practicaldev/image/fetch/s--rjxO02ux--/c_imagga_scale,f_auto,fl_progressive,h_420,q_auto,w_1000/https://dev-to-uploads.s3.amazonaws.com/uploads/articles/w4qxi1gsnhuey77654qj.png)

<h1 align=center> Sorting Algorithms Included</h1>

### Insertion Sort

- Start with the first element as a sorted subarray.
- Iterate through the unsorted part of the array.
- For each element, compare it to the elements in the sorted subarray and insert it in the correct position.
- Repeat this process until the entire array is sorted.

---

### Selection Sort

- Divide the array into two subarrays: sorted and unsorted.
- Find the smallest (or largest) element in the unsorted subarray.
- Swap it with the leftmost element in the unsorted subarray, effectively expanding the sorted subarray.
- Repeat this process until the entire array is sorted.

---

### Bubble Sort

- Start at the beginning of the array.
- Compare adjacent elements and swap them if they are in the wrong order.
- Continue this process, moving one step to the right each time, until no more swaps are needed in a pass.
- Repeat the above steps until the entire array is sorted.

---

### Merge Sort

- Divide the array into two halves.
- Recursively sort each half using the Merge Sort algorithm.
- Merge the two sorted halves back together to create a single sorted array.
- Repeat this process until the entire array is sorted.

---

### Quick Sort

- Choose a pivot element from the array.
- Partition the array into two subarrays: elements less than the pivot and elements greater than the pivot.
- Recursively apply the Quick Sort algorithm to the two subarrays.
- Concatenate the sorted subarrays and the pivot to form the final sorted array.
- Repeat this process until the entire array is sorted.

---

### Heap Sort

Heap Sort is a comparison-based sorting algorithm that leverages a binary heap data structure. It efficiently sorts an array in ascending order by repeatedly extracting the maximum element from a binary heap and placing it at the end of the array.

##### _Steps_

#### 1. Build Max Heap (Heapify)

- Start with the given array, considering it as a binary tree.
- Begin with the last non-leaf node in the binary tree, typically at index `(n/2) - 1`, where `n` is the number of elements in the array.
- For each non-leaf node, compare it with its children (left and right).
- Swap the node with the largest child if the node is smaller than any of its children.
- Continue this process for each non-leaf node, moving up towards the root of the tree.
- After heapifying the entire array, the largest element will be at the root of the binary tree (index 0).

#### 2. Sorting

- Swap the root element (the largest element) with the last element in the array, effectively moving the largest element to the end of the unsorted portion of the array.
- Reduce the heap size (consider the last element as sorted) and heapify the remaining heap (excluding the last element) to maintain the max-heap property.
- Repeat the above step until the entire array is sorted.

#### 3. Continue Sorting

- Continue steps 2 until the entire array is sorted in ascending order.

##

##

<h1 align=center>Searching Algorithms Included</h1>

### BFS Algorithm

**Step 1:** Start at the initial node.

**Step 2:** Initialize a queue and enqueue the initial node.

**Step 3:** Mark the initial node as visited.

**Step 4:** While the queue is not empty:

- Dequeue a node from the front of the queue.
- Explore all unvisited neighboring nodes of the dequeued node.
- Enqueue these neighboring nodes and mark them as visited.

**Step 5:** Repeat steps 4 until the queue is empty or the target node is found.

---

### DFS Algorithm

**Step 1:** Start at the initial node.

**Step 2:** Initialize a stack and push the initial node onto it.

**Step 3:** Mark the initial node as visited.

**Step 4:** While the stack is not empty:

- Pop a node from the top of the stack.
- Explore all unvisited neighboring nodes of the popped node.
- Push these neighboring nodes onto the stack and mark them as visited.

**Step 5:** Repeat steps 4 until the stack is empty or the target node is found.

---

### Dijkstra's Algorithm with Smallest Edge

**Step 1:** Initialize a priority queue (min-heap) and enqueue the initial node with a distance of 0.

**Step 2:** Initialize a distance array to track the shortest distance to each node. Set the initial node's distance to 0 and all other nodes' distances to infinity.

**Step 3:** While the priority queue is not empty:

- Dequeue a node from the priority queue.
- For each unvisited neighbor of the dequeued node:
  - Calculate the potential new distance from the initial node to this neighbor through the dequeued node.
  - If the new distance is smaller than the current recorded distance to the neighbor, update the distance and enqueue the neighbor with the new distance.

**Step 4:** Repeat step 3 until the priority queue is empty or the target node is reached.

---

### Dijkstra's Algorithm (without considering smallest edge)

**Step 1:** Initialize a priority queue (min-heap) and enqueue the initial node with a distance of 0.

**Step 2:** Initialize a distance array to track the shortest distance to each node. Set the initial node's distance to 0 and all other nodes' distances to infinity.

**Step 3:** While the priority queue is not empty:

- Dequeue a node from the priority queue.
- For each unvisited neighbor of the dequeued node:
  - Calculate the potential new distance from the initial node to this neighbor through the dequeued node.
  - If the new distance is smaller than the current recorded distance to the neighbor, update the distance and enqueue the neighbor with the new distance.

**Step 4:** Repeat step 3 until the priority queue is empty or the target node is reached.

---

### Prim's algorithm (Find minimum spanning tree)

1. **Initialization:**

   - Create an empty set to keep track of the vertices included in the Minimum Spanning Tree (MST).

2. **Choose a Starting Vertex:**

   - Select an arbitrary vertex as the starting point and add it to the MST set.

3. **Initialize a Priority Queue:**

   - Create a priority queue (min-heap) to store edges along with their weights. Initially, it contains all edges connected to the chosen vertex.

4. **Main Loop:**

   - Repeat the following steps until the MST set includes all vertices:

   a. **Remove Ineligible Edges:**

   - For each edge (u, v) with weight w in the priority queue:
     - If one end vertex (u) is in the MST set and the other end vertex (v) is not, remove this edge from the priority queue.

   b. **Choose Minimum Weight Edge:**

   - Select the edge with the minimum weight from the priority queue. This edge will be added to the MST.

   c. **Add Vertex to MST Set:**

   - Add the chosen vertex (v) from the selected edge to the MST set.

5. **Completion:**

   - Continue the above steps until all vertices are included in the MST set, forming the minimum spanning tree.

6. **Result:**
   - The MST set now contains all vertices and a subset of the original graph's edges, forming the Minimum Spanning Tree.

> [!IMPORTANT]  
> The choice of the starting vertex can affect the resulting MST, but the overall structure of the tree and its weight will be the same. Prim's algorithm guarantees a minimum spanning tree with the minimum total edge weight.

---

### Bellman-Ford Algorithm Explanation

The Bellman-Ford algorithm is a widely used algorithm in graph theory and computer science for finding the shortest path from a single source vertex to all other vertices in a weighted, directed graph. It can handle graphs with negative weight edges and detect negative weight cycles. The algorithm was named after its inventors, Richard Bellman and Lester Ford, who independently developed it.

#### **_Algorithm Overview_**

1. **Initialization:**

   - Create an array to store the minimum distance from the source vertex to each vertex in the graph.
   - Initialize the distance to the source vertex as 0 and the distance to all other vertices as infinity.
   - Set the predecessor of all vertices to be undefined initially.

2. **Relaxation:**

   - Repeat the following process for the number of vertices in the graph minus one times (|V| - 1 times), where |V| is the number of vertices:
     - For each edge (u, v) in the graph, where u is the source vertex and v is the destination vertex:
       - Relax the edge by updating the distance to v if a shorter path from the source vertex to v through u is found:
         - If `distance[u] + weight(u, v) < distance[v]`, update `distance[v]` to `distance[u] + weight(u, v)`.
         - Also, set the predecessor of v to be u, indicating that the shortest path from the source to v goes through u.

3. **Detection of Negative Cycles:**

   - After |V| - 1 iterations, if there are still updates occurring during the relaxation step, it indicates the presence of a negative weight cycle in the graph. This is because in a graph with no negative weight cycles, the shortest path cannot have more than |V| - 1 edges.

4. **Shortest Path Retrieval:**
   - If there are no negative weight cycles detected, you can retrieve the shortest paths from the source vertex to all other vertices by backtracking from the destination vertex to the source using the predecessor information.

The Bellman-Ford algorithm is less efficient than some other shortest path algorithms, such as Dijkstra's algorithm or the Floyd-Warshall algorithm, but it has the advantage of being able to handle graphs with negative weight edges and detecting negative weight cycles. It's commonly used in scenarios where these features are required or when the graph is sparse, and Dijkstra's algorithm is less efficient.

---

> [!NOTE]  
> Don't trust my code. I'm learning!
