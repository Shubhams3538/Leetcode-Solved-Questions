//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	// approach applied the LIS function once from start and once from back then calculated the dp for the 
	// iterations and adding the two dp index by ind will give the LIS bitonic 
	// time is O(N*N) and space is O(N)+O(N) // for the two dp arrays
	int LongestBitonicSequence(vector<int>nums)
	{
	   int n=nums.size();
	   vector<int>dp1(n,1),dp2(n,1);
	   for(int i=0;i<n;i++){
	       for(int prev=0;prev<i;prev++){
	           if(nums[prev]<nums[i] && dp1[prev]+1>dp1[i]){
	               dp1[i]=1+dp1[prev];
	           }
	       }
	   }
	   for(int i=n-1;i>=0;i--){
	       for(int prev=n-1;prev>i;prev--){
	           if(nums[i]>nums[prev] && dp2[i]<1+dp2[prev]){
	               dp2[i]=1+dp2[prev];
	           }
	       }
	   }
	   int maxi=0;
	   for(int i=0;i<n;i++){
	       maxi=max(maxi,(dp1[i]+dp2[i]-1)); // subtracting one because there is one common element 
	   }
	   return maxi;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends