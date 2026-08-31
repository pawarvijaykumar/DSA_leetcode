class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m+n);
        int i=0;
        int j=0;
        int k=0;
        // int n=nums1.size()-1;
        // int m=nums2.size()-1;
        // int k=nums3.size()-1;
         
        
       
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                nums3[k]=nums1[i];
                k++;
                i++;
            }else{
                nums3[k]=nums2[j];
                k++;
                j++;

            }
       

        }
        while(i<m){
            nums3[k]=nums1[i];
            i++;
            k++;

        }
        while(j<n){
            nums3[k]=nums2[j];
            j++;
            k++;

        
        }
        for(int x=0;x<m+n;x++){
            nums1[x]=nums3[x];
        }

    }
};