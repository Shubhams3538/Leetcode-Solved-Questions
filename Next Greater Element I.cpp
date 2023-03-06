class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>sol;
        stack<int>st;
        unordered_map<int,int>mp;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            int el=nums2[i];
            while(!st.empty() && st.top()<=el ){
                st.pop();
            }
            int res=(st.empty())? -1 : st.top();
            mp.insert({el,res});
            st.push(el);
        }
      for(auto it:nums1){
          sol.push_back(mp[it]);
      }
      return sol;
    }
};