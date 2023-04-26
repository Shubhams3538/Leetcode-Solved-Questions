//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    // using tabulation+space optimization  time is O(N*N) and space is O(N)
    public:
int lcs(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<int> prev(m+1,0), cur(m+1,0);
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev= cur;
    }
    
    return prev[m];
}
  public:
    int longestPalinSubseq(string s) {
      string t = s;
    reverse(s.begin(),s.end());
    return lcs(s,t);    
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends