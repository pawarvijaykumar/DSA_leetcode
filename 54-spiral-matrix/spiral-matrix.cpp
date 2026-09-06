class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();

        int Count=0;
        int total=row*col;

        //index initialisation
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;

        while(Count<total){
            for(int index=startingCol;Count<total && index<=endingCol;index++){
                ans.push_back(matrix[startingRow][index]);
                Count++;

            }
            startingRow++;

            for(int index=startingRow;Count<total && index<=endingRow;index++){
                ans.push_back(matrix[index][endingCol]);
                Count++;

            }
            endingCol--;

            for(int index=endingCol;Count<total && index>=startingCol;index--){
                ans.push_back(matrix[endingRow][index]);
                Count++;

            }
            endingRow--;


            for(int index=endingRow;Count<total && index>=startingRow;index--){
                ans.push_back(matrix[index][startingCol]) ;
                Count++;

            }
           startingCol++;



        }
        return ans;




        
    }
};