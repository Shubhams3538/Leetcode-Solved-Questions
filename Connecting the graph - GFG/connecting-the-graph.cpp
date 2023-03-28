//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
public:
// using disjoint sets...
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
    int extraedges=0;
        DisjointSet ds(n);
      for(auto it:edge){
          int node=it[0];
          int adjnode=it[1];
          // fist we find all the extra edges if two nodes parent are same that means that they are already connected directly or indirectly so we take the extraedge
          if(ds.findUPar(node)==ds.findUPar(adjnode)) extraedges++;
          else {
              ds.unionBySize(node,adjnode);
          }
      }
      int ans=0;
      // through this we find all the component of the graph 
      for(int i=0;i<n;i++){
          if(ds.parent[i]==i) ans++;
      }
      // to connect n components we need n-1 edges
      ans=ans-1;
      // if no of edges required is equal to or less than extraedge we can connect them all else not
      if(ans<=extraedges) 
      return ans;
      else return -1;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends