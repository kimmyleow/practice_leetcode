#include<stdio.h>
#include<stdlib.h>

int countBitsNum(int num)
{
    int count = 0;
    while(num > 0)
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int *countBits(int n, int* returnSize)
{
    *returnSize = n + 1;
    int *ret = (int*)malloc((*returnSize) * sizeof(int));
    int i = 0;
    
    for(i=0; i<=n; i++)
    {
        ret[i] = countBitsNum(i);
    }
    return ret;
}



int main()
{
    int n = 5;
    int i = 0;
    int returnSize;
    int *ans = countBits(n, &returnSize);
    printf("[");
    
    for (i = 0; i < returnSize; i++) {
        printf("%d", ans[i]);
        if (i != returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(ans);
    return 0;
}