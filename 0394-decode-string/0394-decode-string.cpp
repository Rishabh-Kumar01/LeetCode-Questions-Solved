class Solution {
public:
    string multiplier(string s, int mul) {
        string ans = "";

        while(mul != 0) {
            ans += s;
            mul--;
        }

        return ans;
    }
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strings;

        int n = s.size();

        int currNum = 0;
        string currString = "";

        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                currNum = currNum * 10 + (s[i] - '0');
            }
            else if(s[i] == '[') {
                nums.push(currNum);
                strings.push(currString);
                currString = "";
                currNum = 0;
            } else if(s[i] == ']'){
                int mul = nums.top();
                nums.pop();
                string temp = strings.top();
                strings.pop();

                string afterMul = multiplier(currString, mul);

                currString = temp + afterMul;
            } else {
                currString += s[i];
            }
        }


        return currString;
    }
};