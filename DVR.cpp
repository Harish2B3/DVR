#include <stdio.h>
#define MAX_NODES 20

struct Router {
    unsigned dis[MAX_NODES];
    unsigned nextHop[MAX_NODES];
} routers[MAX_NODES];

int main() {
    int i, j, k, numNodes, updated;
    int costMatrix[MAX_NODES][MAX_NODES];

    printf("Enter the number of routers: ");
    scanf("%d", &numNodes);

    printf("Enter the cost matrix details:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            scanf("%d", &costMatrix[i][j]);
            routers[i].dis[j] = costMatrix[i][j];
            routers[i].nextHop[j] = j;
        }
    }

    // Start with updated as 1 to enter the loop
    updated = 1;

    while (updated) {
        updated = 0;
        for (i = 0; i < numNodes; i++) {
            for (j = 0; j < numNodes; j++) {
                for (k = 0; k < numNodes; k++) {
                    if (routers[i].dis[j] > costMatrix[i][k] + routers[k].dis[j]) {
                        routers[i].dis[j] = costMatrix[i][k] + routers[k].dis[j];
                        routers[i].nextHop[j] = k;
                        updated = 1;
                    }
                }
            }
        }
    }

    for (i = 0; i < numNodes; i++) {
        printf("Router %d:\n", i + 1);
        for (j = 0; j < numNodes; j++) {
            printf("To node %d via %d, distance: %d\n", j + 1, routers[i].nextHop[j] + 1, routers[i].dis[j]);
        }
    }

    return 0;
}

