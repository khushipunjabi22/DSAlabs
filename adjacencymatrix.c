#include <stdio.h>
#define MAX_NODES 100
int adjMatrix[MAX_NODES][MAX_NODES];
void addEdge(int from, int to) {
adjMatrix[from][to] = 1;
adjMatrix[to][from] = 1;
}
int main() {
int numNodes, numEdges;
printf("Enter the number of nodes: ");
scanf("%d", &numNodes);
printf("Enter the number of edges: ");
scanf("%d", &numEdges);
for (int i = 0; i < numNodes; i++) {
for (int j = 0; j < numNodes; j++) {
adjMatrix[i][j] = 0;
}
}
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
return 0;
}
