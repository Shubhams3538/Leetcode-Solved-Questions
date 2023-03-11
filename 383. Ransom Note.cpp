class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // took two arrays of size 26 and stored the count of both the strings 
        // and after that compared the element count of ransomeNote with magazine and if
        // any number of element in magazine is lesser than ransomNote then return false...
        vector<int> a(26,0) , b(26,0);
        for(auto it:ransomNote){
            a[it-'a']++;
        }
        for(auto it:magazine){
            b[it-'a']++;
        }
        for(int i=0;i<26;i++){
            if(b[i]<a[i]) return false;
        } 
        return true;
    }
};