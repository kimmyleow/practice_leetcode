#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // Special cases:
    // If the number is negative or ends with 0 but not 0 itself, it can't be a palindrome
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversed = 0;
    // Revert half of the number
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // If the length of the original number is odd, we can ignore the middle digit
    // For example, when the input is 12321, at the end of the loop we get x = 12, reversed = 123.
    // To handle this case, we need to divide reversed by 10 to remove the last digit.
    return x == reversed || x == reversed / 10;
}