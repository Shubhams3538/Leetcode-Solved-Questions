//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
typedef long long ll;
class Solution{
    
      int mod = 1003;
private:
    long long solve(int i , int j , int isTrue , string& exp , vector<vector<vector<int>>>& dp){
        if(i > j) return 0;
        if(i == j){
            if(isTrue) return exp[i] == 'T';
            else return exp[i] == 'F';
        }
    
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        ll ways = 0;
    
        for(int cut = i+1; cut <= j-1; cut+=2){
            ll lT = solve(i , cut-1 , 1 , exp , dp);
            ll lF = solve(i , cut-1 , 0 , exp , dp);
            ll rT = solve(cut+1 , j , 1 , exp , dp);
            ll rF = solve(cut + 1 , j , 0 , exp , dp);
    
            if(exp[cut] == '&'){
                if(isTrue) ways = (ways + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (rF * lF) % mod) % mod;
            }
            else if(exp[cut] == '|'){
                if(isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (rT * lT) % mod) % mod;
                else ways = (ways + (lF * rF) % mod) % mod;
            }
            else{
                if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                else ways = (ways + (rF * lF) % mod + (rT * lT) % mod ) % mod;
            }
        }
        return dp[i][j][isTrue] = ways;
    
    }
      public:
      int countWays(int n, string exp) {
        vector<vector<vector<int>>> dp(n , vector<vector<int>> (n , vector<int>(2 , -1)));
        return solve(0 , n-1 , 1 , exp , dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends