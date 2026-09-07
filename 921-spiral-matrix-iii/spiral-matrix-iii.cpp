class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> ans;

        int r = rStart;
        int c = cStart;

        // Starting cell
        ans.push_back({r, c});

        int steps = 1;

        while(ans.size() < rows * cols) {

            // RIGHT
            for(int i = 0; i < steps; i++) {
                c++;

                if(r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                }
            }

            // DOWN
            for(int i = 0; i < steps; i++) {
                r++;

                if(r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                }
            }

            steps++;

            // LEFT
            for(int i = 0; i < steps; i++) {
                c--;

                if(r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                }
            }

            // UP
            for(int i = 0; i < steps; i++) {
                r--;

                if(r >= 0 && r < rows && c >= 0 && c < cols) {
                    ans.push_back({r, c});
                }
            }

            steps++;
        }

        return ans;
    }
};