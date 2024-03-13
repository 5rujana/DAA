// knapsack fractional problem
#include <stdio.h>
#define MAX 100

struct Item {
    int weight;
    int value;
};

double max(int a, int b) {
    return (a > b) ? a : b;
}

double fractionalKnapsack(int n , struct Item items[] , int capacity) {
    for(int i = 0 ; i < n ; i++){
        items[i].value = items[i].value / items[i].weight;  
        for(int j =0 ; j <n-i-1;j++){
            if(items[j].value < items[j+1].value){
                struct Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }

    double totalValue = 0;
    for(int i = 0 ; i < n ; i++){
        if(items[i].weight <= capacity){
            totalValue += items[i].value * items[i].weight;
            capacity -= items[i].weight;
        }else{
            totalValue += items[i].value * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[MAX];
    for(int i = 0 ; i < n ; i++){
        printf("Enter the weight and value of item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("The maximum value of the knapsack is: %lf\n", fractionalKnapsack(n, items, capacity));
    return 0;
}
    