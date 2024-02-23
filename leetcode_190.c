#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        // Extract the least significant bit of n
        uint32_t bit = (n >> i) & 1;
        // Append the bit to the result after shifting the result to the left
        result = (result << 1) | bit;
    }
    return result;
}

int main() {
    uint32_t num = 43261596; // Example input
    uint32_t reversed = reverseBits(num);
    printf("Reversed bits of %u is %u\n", num, reversed);
    return 0;
}