#include <stdio.h>
#include <stdbool.h>

#define MAX_ISLANDS 1000

int graph[MAX_ISLANDS][MAX_ISLANDS];
bool visited[MAX_ISLANDS];

void initializeGraph(int n) {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addBridge(int a, int b) {
    graph[a][b] = 1;
    graph[b][a] = 1;
}

void depthFirstSearch(int island, int n) {
    visited[island] = true;
    for (int i = 1; i <= n; i++) {
        if (graph[island][i] && !visited[i]) {
            depthFirstSearch(i, n);
        }
    }
}

bool isConnected(int n) {
    depthFirstSearch(1, n);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    initializeGraph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addBridge(a, b);
    }

    if (isConnected(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}