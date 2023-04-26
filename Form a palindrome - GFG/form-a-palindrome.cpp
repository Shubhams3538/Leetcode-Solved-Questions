//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
       public:
    // simple approach is that we find the longest common pallindrome between the string and reverse of the string and if we subtract the size of string with the length of longest common pallidrome then the value is equal to the no of insertions we need to make to a string pallidrome 
    // this is solved using tabulation + space optimization (very similar to finding the longest common substring and pallindrome)
 // time is O(N*N) and space is O(N) for the prev arrray used.........
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
    int countMin(string s){
    int n=s.size();
         string t = s;
    reverse(s.begin(),s.end());
    return n-lcs(s,t);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends