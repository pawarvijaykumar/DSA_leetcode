class Solution {
public:
    string getPermutation(int n, int k) {

        string numbers = "";

        // 123...n
        for (int i = 1; i <= n; i++) {
            numbers += to_string(i);
        }

        // (n-1)!
        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
        }

        // Convert k to 0-based
        k--;

        string ans = "";

        while (n > 0) {

            int index = k / fact;

            ans += numbers[index];

            numbers.erase(numbers.begin() + index);

            k = k % fact;

            n--;

            if (n > 0) {
                fact /= n;
            }
        }

        return ans;
    }
};