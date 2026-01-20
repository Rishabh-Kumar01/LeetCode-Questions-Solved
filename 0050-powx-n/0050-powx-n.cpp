class Solution {
public:
    double myPow(double x, int n) {
        // Edge case: anything to power 0 is 1
        if (n == 0) return 1.0;
        
        // Handle negative exponent
        // x^(-n) = 1 / x^n
        // Use long to avoid overflow when n = INT_MIN
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        return fastPow(x, N);
    }
    
private:
    double fastPow(double x, long n) {
        // Base case
        if (n == 0) return 1.0;
        if (n == 1) return x;
        
        // Recursive case: Binary Exponentiation
        if (n % 2 == 0) {
            // Even: x^n = (x^(n/2))^2
            double half = fastPow(x, n / 2);
            return half * half;
        } else {
            // Odd: x^n = x * x^(n-1)
            return x * fastPow(x, n - 1);
        }
    }
};