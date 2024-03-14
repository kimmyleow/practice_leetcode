#include <stdio.h>

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize) {
    int totalGas, totalCost, tank, start, i;
    start = 0;
    tank = 0;
    totalGas = 0;
    totalCost = 0;
    
    for(i=0; i<gasSize; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];
        
        if(tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    
    if(totalCost > totalGas) return -1;
    
    return start;
}

int main() {
    int gas[] = {1,2,3,4,5};
    int cost[] = {3,4,5,1,2};
    int gasSize = sizeof(gas)/sizeof(gas[0]);
    int costSize = sizeof(cost)/sizeof(cost[0]);
    
    int result = canCompleteCircuit(gas, gasSize, cost, costSize);
    printf("Starting gas station index: %d\n", result);
    
    return 0;
}