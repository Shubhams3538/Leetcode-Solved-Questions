//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    // using dp and memorization time complexity O(N) and space is O(N)+O(N) for stack and extra dp array
    int find(vector<int>&height,int index,vector<int>&dp){
        if(index==0) return 0;
        if(dp[index]!=-1) return dp[index];
        int left=find(height,index-1,dp)+abs(height[index]-height[index-1]);
        int right=INT_MAX;
    if(index>1) right=find(height,index-2,dp)+abs(height[index]-height[index-2]);
    return dp[index]=min(left,right);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
      vector<int>dp(n+1,-1);
      return find(height,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends