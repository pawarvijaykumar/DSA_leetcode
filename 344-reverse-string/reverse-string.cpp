class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int end=s.size()-1;
        for(int i=0;i<end;i++){
            while(start<=end){
                swap(s[start],s[end]);
                start++;
                end--;
            }
        }
        
    //return s;
    }
};