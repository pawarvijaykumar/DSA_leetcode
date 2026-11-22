class Solution {
public:
    bool isValid(string s) {

    

    stack<char> st;

    for(int i = 0; i < s.length(); i++) {

        char ch = s[i];

        // Opening brackets
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        else {
            // Check if stack is empty
            if(!st.empty()) {

                char top = st.top();

                // Match opening and closing brackets
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    // Check stack after completing the loop
    if(st.empty())
       return true;
    else
       return false;
  
   
    }
        

};