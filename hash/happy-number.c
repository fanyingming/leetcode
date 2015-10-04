class Solution {
public:
    int square_digits(int n) {
        int sum = 0;
        while (n) {
            int v= n%10;//last digits
            sum += v*v;
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> htable;

        if (n <= 0) return false;

        while (1) {
            n = square_digits(n);
            if (n == 1)
                return true;
            if (htable.find(n) == htable.end()) {
                htable.insert(n);
            } else {
                return false;
            }
        }
    }
};