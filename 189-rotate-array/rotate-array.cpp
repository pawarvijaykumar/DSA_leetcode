class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());//means reverse the all array
        reverse(nums.begin(),nums.begin()+k);//means roatted array for k index remeain rotate
        reverse(nums.begin()+k,nums.end());//reset the lefted array lement
        
        
    }
};