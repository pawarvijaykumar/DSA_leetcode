class Solution {
public:

    int gcd(int a, int b) {

        while(b != 0) {

            int rem = a % b;

            a = b;
            b = rem;
        }

        return a;
    }

    bool hasGroupsSizeX(vector<int>& deck) {

        // Step 1: Count frequency
        unordered_map<int, int> freq;

        for(int x : deck) {
            freq[x]++;
        }

        // Step 2: Find GCD of all frequencies
        int g = 0;

        for(auto it : freq) {

            g = gcd(g, it.second);

            // If GCD becomes 1, grouping is impossible
            if(g == 1) {
                return false;
            }
        }

        // Step 3: GCD must be at least 2
        return g >= 2;
    }
};