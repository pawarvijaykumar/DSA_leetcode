// 


class Solution {
public:
    string modifyString(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='?'){
                 for(char ch = 'a'; ch <= 'z'; ch++){
                    if((i == 0 || temp.back() != ch) &&
                       (i == s.length()-1 || s[i+1] != ch)) {

                        temp.push_back(ch);
                        break;
                    }
                }
            }
            
            else{
                temp.push_back(s[i]);


        }

    }
    return temp;

   }
        

};


