class Solution {
   public:
    double myPow(double x, int n) {
        double a = 1.00;
        if (n >= 0) {
            for (int i = 0; i < n; i++) {
                a = a * x;
            }
        } else {
            for (int i = 0; i > n; i--) {
                a = a / x;
            }
        }
        return a;
    }
};
