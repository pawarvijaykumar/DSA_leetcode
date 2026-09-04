class Solution {
public:
    int compress(vector<char>& chars) {

        int i = 0;
        int ans = 0;

        while(i < chars.size()) {

            char current = chars[i];

            int count = 0;

            while(i < chars.size() && chars[i] == current) {
                count++;
                i++;
            }

            chars[ans++] = current;

            if(count > 1) {

                string str = to_string(count);

                for(char ch : str) {
                    chars[ans++] = ch;
                }
            }
        }

        return ans;
    }
};