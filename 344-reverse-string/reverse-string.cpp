class Solution {
public:

//used to recursion
   void reverse(int i,int j, vector<char>& s) {
    
    // cout<<str<<endl;
 
       if(i>=j){
       return;
    }
    swap(s[i++],s[j--]);
    reverse(i,j,s);
}




void reverseString(vector<char>& s) {
        reverse(0,s.size()-1,s);
        //return reverse;
    }
};
       





//its normaln string


//         int start=0;
//         int end=s.size()-1;
//         for(int i=0;i<end;i++){
//             while(start<=end){
//                 swap(s[start++],s[end--]);
//                 //start++;
//                 //end--;
//             }
//         }
        
//     //return s;
//     }
// };