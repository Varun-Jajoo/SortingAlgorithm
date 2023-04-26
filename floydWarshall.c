#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define V 4

void printMatrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF) {
                printf("INF ");
            }
            else {
                printf("%d   ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void printPath(int Pi[V][V], int i, int j) {
    if (Pi[i][j] == -1) {
        printf("%d ", j);
    }
    else {
        printPath(Pi, i, Pi[i][j]);
        printf("%d ", j);
    }
}

void printAllShortestPaths(int D[V][V], int Pi[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                printf("Shortest path from %d to %d: ", i, j);
                printf("%d ", i);
                printPath(Pi, i, j);
                printf("\n");
            }
        }
    }
}

void floydWarshall(int graph[V][V]) {
    int D[V][V], Pi[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            D[i][j] = graph[i][j];
            if (i == j || graph[i][j] == INF) {
                Pi[i][j] = -1;
            }
            else {
                Pi[i][j] = i;
            }
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (D[i][k] != INF && D[k][j] != INF && D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    Pi[i][j] = Pi[k][j];
                }
            }
        }
    }

    printf("Final D matrix:\n");
    printMatrix(D);

    printf("\nFinal Pi matrix:\n");
    printMatrix(Pi);

    printf("\nShortest paths:\n");
    printAllShortestPaths(D, Pi);
}

int main() {
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}
