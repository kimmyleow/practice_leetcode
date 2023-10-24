int getSum(int a, int b) {
    while (b != 0) {
        int carry = a & b;  // Calculate the carry bit
        a = a ^ b;          // Add a and b without considering the carry
        b = (unsigned int)(carry) << 1;  // Left-shift the carry to be added in the next iteration
    }
    return a;
}