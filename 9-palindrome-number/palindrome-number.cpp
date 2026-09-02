class Solution {
public:
    int palindrom(string s){
        
        int start =0;
        int end=s.size()-1;
        while(start<=end){
            if(s[start]!=s[end]){
                return 0;

            }else{
                start++;
                end--;
            }
        }
        return 1;
    }
bool isPalindrome(int x) {
    if(x<0){
        return 0;
    }
    string s = to_string(x);

    return palindrom(s);
    }
};