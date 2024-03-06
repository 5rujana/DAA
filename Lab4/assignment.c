#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10

int mincost = INT_MAX;
int minAssignment[MAX];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculateCost(int cost[MAX][MAX], int assignment[MAX], int n , int current){
    if(current == n){
        int currentCost = 0;
        for (int i = 0; i < n; i++) {
            currentCost += cost[i][assignment[i]];
        }

        if (currentCost < mincost) {
            mincost = currentCost;
            for (int i = 0; i < n; i++) {
                minAssignment[i] = assignment[i];
            }
        }
        return;
    }

    for(int i = current; i < n; i++){
        swap(&assignment[i], &assignment[current]);
        calculateCost(cost, assignment, n, current+1);
        swap(&assignment[i], &assignment[current]);
    }
}


int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    int cost[MAX][MAX];
    printf("Enter the cost matrix: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    int assignment[MAX];
    for(int i = 0; i < n; i++){
        assignment[i] = i;
    }
    calculateCost(cost, assignment, n, 0);
    printf("Minimum cost: %d\n", mincost);
    printf("Assignment: ");
    for(int i = 0; i < n; i++){
        printf("%d ", minAssignment[i]);
    }
    printf("\n");
    return 0;
}
   