
class Solution {
public:
    int minInsertions(string s) {

        stack<char> st;
        int ans = 0;

        for(int i = 0; i < s.length(); i++) {

            // Opening bracket
            if(s[i] == '(') {
                st.push('(');
            }

            else {

                // Check next character
                if(i + 1 < s.length() && s[i+1] == ')') {

                    // Complete closing pair
                    if(!st.empty()) {
                        st.pop();
                    }
                    else {
                        ans++;
                    }

                    i++;
                }

                else {

                    // Insert missing closing bracket
                    ans++;

                    if(!st.empty()) {
                        st.pop();
                    }
                    else {
                        ans++;
                    }
                }
            }
        }

        // Each remaining '(' needs two ')'
        ans += 2 * st.size();

        return ans;
    }
};
