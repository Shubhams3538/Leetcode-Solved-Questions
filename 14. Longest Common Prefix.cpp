class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        // sorting the strings and we just need to compare the smallest and the largest
        // string and whatever is common between them is common among all.
        sort(strs.begin(),strs.end());
        string n=strs[0], m=strs[strs.size()-1];
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]) ans+=n[i];
            else
             return ans;
        }
        return ans;
    }
};