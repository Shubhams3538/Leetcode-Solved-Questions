//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    // using memoization dp and time complexity is O(N*4)*3 // running a
   // for loop for every state of size 3 so multiplied by 3 and there is total 
   // n*4 states or elements i.e O(N*12) === O(N) // 
    // and  space complexity of O(N)+O(N*4) i.e stack space + dp vector 
    int find_max(vector<vector<int>>&points,int index,int last_task,vector<vector<int>>&dp){
        if(index==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=last_task){
                    maxi=max(maxi,points[0][i]);
                } 
            }
            return maxi;
        }
        if(dp[index][last_task]!=-1) return dp[index][last_task];
        int maxi=0;
        for(int i=0;i<3;i++){
            if(last_task!=i){
               int point=points[index][i]+find_max(points,index-1,i,dp);
               maxi=max(maxi,point);
            }
        }
        return  dp[index][last_task]=maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
       vector < vector < int > > dp(n, vector < int > (4, -1));
       return find_max(points,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends