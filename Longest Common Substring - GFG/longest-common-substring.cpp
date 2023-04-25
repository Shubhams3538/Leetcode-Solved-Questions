//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // using tabulation + space optimization time is O(M*N) ans space is O(M)
    int longestCommonSubstr (string S1, string S2, int n, int m){
   vector<int> prev(m+1,0), cur(m+1,0);
    int ans = 0; // to store the maximum substring length
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S1[i-1]==S2[j-1]){ // if the value matches then we can take the value of prev and add it
                int val = 1 + prev[j-1];
                cur[j] = val;
                ans = max(ans,val);
            }
            else
                cur[j] = 0; // if the element doesn't match we can simply fill dp with 0
        }
        prev=cur;
    }
    
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends