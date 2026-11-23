
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> st;

        // Traverse string
        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') {
                st.push(i);
            }

            else if(s[i] == ')') {

                if(!st.empty()) {
                    st.pop();
                }
                else {
                    s[i] = '*';
                }
            }
        }

        // Remove unmatched opening brackets
        while(!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }

        // Build answer
        string ans = "";

        for(int i = 0; i < s.length(); i++) {

            if(s[i] != '*') {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};
