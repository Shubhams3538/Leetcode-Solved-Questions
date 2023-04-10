//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    // using tabulation we will have time O(N) and space O(N) that is the dp arrray
    // but here we have used space optimization that is we don't need the whole array we just need prev two
    // values so now
    
    // time O(N) and space is O(1)
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int prev=arr[0],prev2=0;  // (i-1) && (i-2)
	    for(int i=1;i<n;i++){
	        int take=arr[i];
	        if(i>1) take+=prev2;
	        int nottaken=0+prev;
	        int curr=max(take,nottaken);
	        prev2=prev;
	        prev=curr;
	    }
	    return prev;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends