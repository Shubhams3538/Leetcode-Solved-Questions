class Solution {
    private:
    void solve(vector<int> nums , vector<int>temp,int index,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(nums,temp,index+1,ans);
        int element=nums[index];
        temp.push_back(element);
        solve(nums,temp,index+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        solve(nums,temp,index,ans);
        return ans;

    }
};