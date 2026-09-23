class Solution {
private:

    void solve(vector<int>& nums,
               vector<int>& output,
               int index,
               vector<vector<int>>& ans)
    {
        // Store current subset
        ans.push_back(output);

        // Try every element from index
        for(int i = index; i < nums.size(); i++)
        {
            // Skip duplicate elements
            if(i > index && nums[i] == nums[i - 1])
            {
                continue;
            }

            // Include
            output.push_back(nums[i]);

            solve(nums, output, i + 1, ans);

            // Backtrack
            output.pop_back();
        }
    }

public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> output;

        // IMPORTANT: sort first
        sort(nums.begin(), nums.end());

        solve(nums, output, 0, ans);

        return ans;
    }
};