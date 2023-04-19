//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    	public:
	int m = (int)1e9+7;
	int solve(int arr[], int i, int n, int sum, int tar, vector<vector<int>>& dp){
	    if(i==n) {
	        if(sum==tar) return 1;
	        return 0;
	    }
	    if(dp[i][sum]!=-1) return dp[i][sum];
	    int taken = (sum+arr[i]<=tar) ? solve(arr,i+1,n,sum+arr[i],tar,dp) : 0;
	    int nottaken = solve(arr,i+1,n,sum,tar,dp);
	    return dp[i][sum] = (taken+nottaken)%m;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<int> dp(sum+1,0);
        dp[0] = 1;
        for(int i=n-1;i>=0;i--){
            vector<int> curr(sum+1,0);
            for(int j=0;j<=sum;j++){
                int taken = (j-arr[i]>=0) ? dp[j-arr[i]] : 0;
        	    int nottaken = dp[j];
        	    curr[j] = (taken+nottaken)%m;
            }
            dp = curr;
        }
        return dp[sum];
	}
	  
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends