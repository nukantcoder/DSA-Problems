class Solution {
public:
string RLE(string ans)
{
    int n = ans.size();
    string result = "";
    int count = 1;
    for(int i = 1;i < n;i++)
    {
        if(ans[i] != ans[i - 1])
        {
            result = result + to_string(count) + ans[i-1];
            count = 1;
        }
        else
        {
            count++;
        }
    }
    if(count != 0)
    {
        result = result + to_string(count) + ans[n-1];
    }
    return result;
}
    string countAndSay(int n) {
        
        string answer = "";
        for(int i = 1;i <= n;i++)
        {
            if(i == 1)
            {
                answer += "1";
            }
            else
            {
                answer = RLE(answer);
            }
        }
        return answer;
    }
};