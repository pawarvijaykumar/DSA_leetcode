class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row(matrix.size(),0);
        vector<int> col(matrix[0].size(),0); 
        for(int i=0; i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;

                }
            }
  
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){   
                if(row[i]==1||col[j]==1) {//agar dono nnme ek =1 hogaye toh turan hi matrix se ==0 hojata hai
                    matrix[i][j]=0;
                }
            }
        }



        
    }
};
//;https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg$0