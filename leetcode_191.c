// Method 1: use AND operator by "1"
// Method 2: use mod % by 2

//method 1
int hammingWeight(uint32_t n) {
    int count = 0;
    while(n!=0)
    {
        count += n&1;
        n >>= 1;
    }
    return count;
}

//method 2
/*
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            count++;
        }
        n /= 2;
    }
    return count;
}
*/

int main() {
    uint32_t num = 11; // example input
    printf("Hamming weight of %u is %d\n", num, hammingWeight(num));
    return 0;
}