class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using kadane's algorithm(s)
        int sum=0;
        int maxi=INT_MIN;
        for(auto it:nums){
            sum+=it;
            maxi=max(sum,maxi);
            if(sum<0) sum=0;
              
        }
        return maxi;
    }
};