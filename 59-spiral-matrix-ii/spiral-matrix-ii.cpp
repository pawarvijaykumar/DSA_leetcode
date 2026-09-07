class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
         int startingRow=0;
        int startingCol=0;
        int endingRow=n-1;
        int endingCol=n-1;

        int value=1;

        while(startingRow <= endingRow &&
              startingCol <= endingCol){//Jab tak valid row aur valid column dono available hain, spiral filling continue karo
            for(int index=startingCol;index<=endingCol;index++){
                matrix[startingRow][index]=value++;
               // Count++;

            }
            startingRow++;

            for(int index=startingRow;index<=endingRow;index++){
               matrix[index][endingCol]=value++;
               // Count++;

            }
            endingCol--;

            for(int index=endingCol;index>=startingCol;index--){
                matrix[endingRow][index]=value++;
                //Count++;

            }
            endingRow--;


            for(int index=endingRow;index>=startingRow;index--){
                matrix[index][startingCol]=value++ ;
               // Count++;

            }
           startingCol++;



        }
        return matrix;

        
    }
};