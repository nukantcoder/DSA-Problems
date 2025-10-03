class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.size();
        unordered_map<char,int> values = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
    };

        int answer = 0;
        for(int i = 0;i < n;i++)
        {
            if(values[s[i]] >= values[s[ i + 1]] || i == n - 1)
            {
                answer += values[s[i]];
            }
            else
            {
                answer -= values[s[i]];
            }
        }
        return answer;
    }
};