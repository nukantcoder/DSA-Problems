class Solution {
public:
void solve(int ind,string digits,string temp,vector<string> &result, unordered_map<char,string> mp)
{
    if(ind >= digits.size())
    {
        result.push_back(temp);
        return;
    }

    char ch = digits[ind];
    string s = mp[ch];

    for(int i = 0;i < s.size();i++)
    {
        temp.push_back(s[i]);
        solve(ind + 1,digits,temp,result,mp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> result;
        string temp = "";
        solve(0,digits,temp,result,mp);
        return result;
    }
};