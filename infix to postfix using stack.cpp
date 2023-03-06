class Solution {
public:
    void solve(string digits,string ans,string map[],vector<string> &output,int index){
        if(index >= digits.length()){
            output.push_back(ans);
            return ;
        }

        int number = digits[index] - '0';
        string value = map[number];

        for(int i = 0 ; i<value.length();i++){
            ans.push_back(value[i]);
            solve(digits,ans,map,output,index+1);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string ans = "";
        vector<string> output;
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index = 0;
        if(digits[index]==0){
            return output;
        }
        solve(digits,ans,map,output,index);
        return output;
    }
};