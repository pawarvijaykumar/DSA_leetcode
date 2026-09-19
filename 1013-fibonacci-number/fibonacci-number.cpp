class Solution {
public:
    int fib(int n) {
        if(n==0|| n==1){
            return n ;


        }
        int smallerValue=fib(n-1);
        int largeValue=fib(n-2);

        int ans=smallerValue+largeValue;
        return ans;
        
    }
};