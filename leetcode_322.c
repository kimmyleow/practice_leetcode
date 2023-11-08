#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    int result = dp[amount] == INT_MAX ? -1 : dp[amount];

    free(dp);

    return result;
}

int main() {
    int coins[] = {1, 2, 5};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    int result = coinChange(coins, coinsSize, amount);
    printf("Fewest number of coins: %d\n", result);

    return 0;
}
