class Solution {
public:
// when we found a character that doesn't match with the end we made another pallindrome check
// function and  pass them if any result come as true that means a valid else invalid
bool is_valid(string s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]) return false;
        start++;
        end--;
    }
    return true;
}
    bool validPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<end){
           if(s[start]==s[end]){
                start++;
           end--;
           }
         else 
         {
             // the element which needs to be delted can be any either first or last so
             // we made a function call for both of them and check if any is valid....
             return (is_valid(s,start+1,end) || is_valid( s,start,end-1));
         }
       }
       return true;
    }
};