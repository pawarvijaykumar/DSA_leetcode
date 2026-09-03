class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int start=0;
        //int end=n-1;
        for(int i=0;i<=s.size();i++){
            if(i==s.size()||s[i]==' ' ){
                reverse(s.begin()+start,s.begin()+i);
                start=i+1;
                
            }

        }
        
        
      
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != ' ') {
                ans += s[i];
            }
            else if (!ans.empty() && ans.back()   != ' ') {
                ans += ' ';
            }
        }

        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};
