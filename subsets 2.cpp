class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(res, subset, nums, 0);
        return res;  
    }

    void dfs(vector<vector<int>>& subsets, vector<int>& subset, vector<int>& nums, int index) {
        subsets.push_back(subset);

        for(int i = index; i < nums.size(); ++i) {
            if(i > index && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            dfs(subsets, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};