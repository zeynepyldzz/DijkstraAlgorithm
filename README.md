# Dijkstra Shortest Path Algorithm

This project implements Dijkstra's algorithm to find the shortest path from a single source node to all other nodes in a weighted graph. The graph is represented using an adjacency matrix.

![image](https://github.com/user-attachments/assets/609568c6-cdb4-4485-89de-5e505a0043bc)

## Features

- Calculates shortest distances from a given source node.
- Works with weighted graphs having positive edge weights.
- Prints the shortest distance from the source node to every other node.

## Usage

1. Update the adjacency matrix (`graph`) with your own graph data.
2. Set the source node index in the `dijkstra` function call.
3. Compile and run the program.
```bash
g++ dijkstra.cpp -o dijkstra
./dijkstra

Nodes in the Example
Node Index	Location
0	Gebze
1	Kavacik
2	Dudullu
3	Hacihalil
4	Kadikoy
5	Umraniye
6	Tuzla
7	Darica
8	Uskudar (Source)

Notes
Edge weights represent time in minutes between nodes.

Make sure to provide a complete adjacency matrix (size NxN).

License
This project is open-source and free to use.




