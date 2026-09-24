class Solution {
public:

    long long fact[101];

    // Count valid permutations after choosing a number
    long long countWays(int odd, int even, int nextParity, long long k) {

        // No numbers left
        if (odd == 0 && even == 0)
            return 1;

        // Next number must be odd
        if (nextParity == 1) {
            if (!(odd == even || odd == even + 1))
                return 0;
        }

        // Next number must be even
        else {
            if (!(even == odd || even == odd + 1))
                return 0;
        }

        // Number of arrangements = odd! * even!
        __int128 ways = (__int128)fact[odd] * fact[even];

        // We only care whether ways is >= k
        if (ways >= k)
            return k;

        return (long long)ways;
    }

    vector<int> permute(int n, long long k) {

        // ------------------------------------------------
        // Calculate factorials safely
        // ------------------------------------------------

        fact[0] = 1;

        for (int i = 1; i <= n; i++) {

            // Prevent overflow
            if (fact[i - 1] > k / i)
                fact[i] = k;
            else
                fact[i] = fact[i - 1] * i;
        }

        // Number of odd and even numbers
        int odd = (n + 1) / 2;
        int even = n / 2;

        vector<int> ans;

        vector<bool> used(n + 1, false);

        // ------------------------------------------------
        // Build answer one position at a time
        // ------------------------------------------------

        for (int pos = 0; pos < n; pos++) {

            bool found = false;

            // Try numbers in increasing order
            for (int x = 1; x <= n; x++) {

                if (used[x])
                    continue;

                // Adjacent numbers must have different parity
                if (!ans.empty() &&
                    (ans.back() % 2 == x % 2)) {
                    continue;
                }

                int newOdd = odd;
                int newEven = even;

                // Remove x
                if (x % 2 == 1)
                    newOdd--;
                else
                    newEven--;

                // Next number must have opposite parity
                int nextParity = 1 - (x % 2);

                // Count how many valid permutations
                // start with this choice
                long long ways = countWays(
                    newOdd,
                    newEven,
                    nextParity,
                    k
                );

                // Skip this entire group
                if (ways < k) {

                    k -= ways;
                }

                // This group contains our k-th answer
                else {

                    ans.push_back(x);
                    used[x] = true;

                    odd = newOdd;
                    even = newEven;

                    found = true;

                    break;
                }
            }

            // k is larger than the number of
            // possible valid permutations
            if (!found)
                return {};
        }

        return ans;
    }
};