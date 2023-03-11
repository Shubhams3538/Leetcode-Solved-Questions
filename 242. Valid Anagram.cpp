class Solution {
public:
    bool isAnagram(string s, string t) {
         vector<int> a(26,0) , b(26,0);
        for(auto it:s){
            a[it-'a']++;
        }
        for(auto it:t){
            b[it-'a']++;
        }
        for(int i=0;i<26;i++){
            if(b[i]!=a[i]) return false;
        } 
        return true;
    }
    
};