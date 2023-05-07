//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    // using memoization time is O(N*N*N) and space is O(N*N)+O(N) // for the dp and the stack space 
    private:
    int find_min(int i , int j , int arr[] , vector<vector<int>>&dp){
        if(i==j) return 0; // base case 
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+find_min(i,k,arr,dp)+find_min(k+1,j,arr,dp); // main formula need
            // to understand how it came in 
            if(steps<mini) mini=steps;  
        }
        return dp[i][j]=mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
       vector<vector<int>>dp(N,vector<int>(N,-1));
       return find_min(1,N-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends