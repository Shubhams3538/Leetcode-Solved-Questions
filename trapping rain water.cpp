class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lm=0;
        int rm=0;
        int ans=0;
        int left=0;
        int right=n-1;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=lm){
                    lm=height[left];
                }
                else 
                {
                    ans+=lm-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=rm){
                    rm=height[right];
                }
                else 
                {
                    ans+=rm-height[right];
                }
                right--;    
            }
        }
        return ans;
    }
};