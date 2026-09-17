class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        int n=s.size();
       
        for(int i=0;i<n;i++){
            char ch=s[i];

            if(!ans.empty()&& ans.back()==ch){
                ans.pop_back();
            }else{

                ans.push_back(ch);
            }
        }

        return ans;
    }
        
    
};