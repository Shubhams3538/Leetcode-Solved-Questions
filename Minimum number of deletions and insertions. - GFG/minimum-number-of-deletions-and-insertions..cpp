//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		   // we first found the max common substring between the two words and now the no of alphabets we need to remove from word1 is equal to length of word1-longest common substring and the number of alphabets we need to insert is the length of second word minus the length of longest common subsequence  
    // solved using tabulation + space optimization time is O(N*N) and space is O(N) // prev array
    private:
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
	int minOperations(string word1, string word2) 
	{ 
	   int n=word1.length();
        int val=lcs(word1,word2);
        return n-val+(word2.length()-val); // no of delete op to perform + no of insert
        // operation to be performed
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends