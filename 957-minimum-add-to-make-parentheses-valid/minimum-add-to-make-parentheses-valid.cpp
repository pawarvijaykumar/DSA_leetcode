

class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;
        int ans = 0;

        for(int i = 0; i < s.length(); i++) {

            char ch = s[i];

            // Opening bracket
            if(ch == '(') {
                st.push(ch);
            }

            // Closing bracket
            else {
                if(!st.empty()) {
                    st.pop();
                }
                else {
                    ans++;
                }
            }
        }

        return ans + st.size();
    }
};

        
    
