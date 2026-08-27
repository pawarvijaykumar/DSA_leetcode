class Solution {
public:
    bool isPossible(vector<int> nums ,int k,int mid){
        int studentCount=1;
        int pageSum=0;//the start sum 0 to means 0,10,20,30
        for(int i=0;i<nums.size();i++){
            if(pageSum+nums[i]<=mid){//mid 50<=move right +++
                pageSum+=nums[i];//++

            }else{
                studentCount++;//second student
                if(studentCount>k||nums[i]>mid){
                    return false;

                }
                //pageSum=0;
                pageSum=nums[i];
            }
        }
        return true;
    }
    

    
    int splitArray(vector<int>& nums, int k) {
        
        int start=0;
        int sum=0;
        //int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

        }
        int ans=-1;
        int end=sum;
        while(start<=end){
            int mid=(start+end)/2;
            if(isPossible(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
            //mid=(start+end)/2;

        }
        return ans ;
    }
};