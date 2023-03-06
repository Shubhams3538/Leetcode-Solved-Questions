class Solution {
    private:
      void sol(int ind,int target,vector<vector<int>>&ans,vector<int>&ds,vector<int>&candidates){
         if(target==0){
             ans.push_back(ds);
             return;
         }
         for(int i=ind;i<candidates.size();i++){
             if(i>ind && candidates[i]==candidates[i-1]) continue;
             if(candidates[i]>target) break;
             ds.push_back(candidates[i]);
             sol(i+1,target-candidates[i],ans,ds,candidates);
             ds.pop_back();
         }
      }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        sol(0,target,ans,ds,candidates);
        return ans;
    }
};