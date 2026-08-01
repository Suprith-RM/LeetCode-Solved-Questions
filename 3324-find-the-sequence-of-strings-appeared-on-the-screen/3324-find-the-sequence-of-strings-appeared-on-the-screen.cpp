class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string temp = "";
        for(char ch: target){
            temp.push_back('a');
            ans.push_back(temp);
            while(temp.back() != ch){
                temp.back() = temp.back() + 1;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};