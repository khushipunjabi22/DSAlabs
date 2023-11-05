#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
int adjMatrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;
// Function to add an edge to the adjacency matrix
void addEdge(int from, int to) {
adjMatrix[from][to] = 1;
}
// Function to perform Breadth-First Search (BFS)
void BFS(int start, int numNodes) {
printf("Breadth-First Search (BFS):\n");
int i, current;
front = rear = -1;
for (i = 0; i < numNodes; i++) {
visited[i] = 0;
}
visited[start] = 1;
enqueue(start);
while (!isEmpty()) {
current = dequeue();
printf("%d ", current);
for (i = 0; i < numNodes; i++) {
if (adjMatrix[current][i] && !visited[i]) {
visited[i] = 1;
enqueue(i);
}
}
}
printf("\n");
}
// Function to perform Depth-First Search (DFS)
void DFS(int node, int numNodes) {
int i;
printf("%d ", node);
visited[node] = 1;
for (i = 0; i < numNodes; i++) {
if (adjMatrix[node][i] && !visited[i]) {
DFS(i, numNodes);
}
}
}
// Function to enqueue an element in the queue
void enqueue(int node) {
if (rear == MAX_NODES - 1) {
printf("Queue is full!\n");
} else {
if (front == -1) {
front = 0;
}
rear++;
queue[rear] = node;
}
}
// Function to dequeue an element from the queue
int dequeue() {
int node;
if (front == -1) {
printf("Queue is empty!\n");
return -1;
} else {
node = queue[front];
front++;
if (front > rear) {
front = rear = -1;
}
return node;
}
}
// Function to check if the queue is empty
int isEmpty() {
return front == -1;
}
int main() {
int numNodes, numEdges, choice;
printf("Enter the number of nodes: ");
scanf("%d", &numNodes);
printf("Enter the number of edges: ");
scanf("%d", &numEdges);
// Initialize the adjacency matrix with zeros
for (int i = 0; i < numNodes; i++) {
for (int j = 0; j < numNodes; j++) {
adjMatrix[i][j] = 0;
}
}
// Input the edges
for (int i = 0; i < numEdges; i++) {
int from, to;
printf("Enter edge %d (from to): ", i + 1);
scanf("%d %d", &from, &to);
if (from < 0 || from >= numNodes || to < 0 || to >= numNodes) {
printf("Invalid node numbers. Edge ignored.\n");
continue;
}
addEdge(from, to);
}

printf("\nAdjacency Matrix:\n");
for (int i = 0; i < numNodes; i++) {
    for (int j = 0; j < numNodes; j++) {
        printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
}

do {
printf("\nMenu:\n");
printf("1. Perform Breadth-First Search (BFS)\n");
printf("2. Perform Depth-First Search (DFS)\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the starting node for BFS: ");
int startNode;
scanf("%d", &startNode);
BFS(startNode, numNodes);
break;
case 2:
for (int i = 0; i < numNodes; i++) {
visited[i] = 0;
}
printf("Enter the starting node for DFS: ");
int startNodeDFS;
scanf("%d", &startNodeDFS);
printf("Depth-First Search (DFS):\n");
DFS(startNodeDFS, numNodes);
printf("\n");
break;
case 3:
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 3);
return 0;
}
