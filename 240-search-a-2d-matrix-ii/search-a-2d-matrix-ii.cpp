class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        

        int rowIndex=0;
        int colIndex=col-1;
        //int mid=(start+end)/2;
        while(rowIndex<row && colIndex>=0){
            int element=matrix[rowIndex][colIndex];
            if(element==target){
                return 1;

            }else if(element<target){
                //start=mid+1;
                rowIndex++;
            }else{
                colIndex--;
            }
           // mid=(start+end)/2;
        }
        return 0;
        
        
    }
};