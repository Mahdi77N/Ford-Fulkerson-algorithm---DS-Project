# Ford-Fulkerson-algorithm---DS-Project
This is **Forf-Fulkerson-algorithm** to find max-flow in a graph between two desired nodes(Source and Sink)<br/>
This is how the algorithm works:
```
1. Start with initial flow as 0.
2. While there is a augmenting path from source to sink. Add this path-flow to flow.
3. Return flow.
```
The queue used for [BFS algorithm](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/) in this project is self-implemented with the following futures:
```
- push in the queue
- pop from the queue
- return the front element in the queue
- is the queue empty?
```
Each of the futures are accessible by a function.
And this is how the code works:
```
- First it gets the number of nodes
- Then it makes the graph and gets the weight between each of two nodes form the client
- Then it gets the number of source and sink nodes from client
- At the end it runs the ford-flukerson function and shows up the paths to reach the max-flow in the graph
```
My implementation of ford-fulkerson Algorithm is called Edmonds-Karp Algorithm.
<br/>
The idea of Edmonds-Karp is to use BFS in ford-fulkerson implementation as BFS always picks a path with minimum number of edges.
<br/>
When BFS is used, the worst case time complexity can be reduced to O(VE2).
<br/>
My implementation uses adjacency matrix representation though where BFS takes O(V2) time, 
the time complexity of my implementation is O(EV3).<br/>
<br/>For better understanding of the algorithm you can watch [this video](https://www.youtube.com/watch?v=hmIrJCGPPG4/) on [youtube](https://www.youtube.com/).
