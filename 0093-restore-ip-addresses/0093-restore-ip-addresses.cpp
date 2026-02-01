class Solution {
public:
    bool isValid(string temp) {
        if(stoi(temp) > 255) return false;

        return !(temp.size() > 1 && temp[0] == '0');
    }
    void helper(vector<string> &ans, vector<string> &ip, int idx, string &s) {

        if(ip.size() == 4 && idx >= s.size()){            
            string valid = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];

            ans.push_back(valid);
        }

        for(int i = 1; i <= 3; i++){

            if(idx + i > s.size()) break;

            string temp = s.substr(idx, i);

            if(isValid(temp)){
                ip.push_back(temp);

                helper(ans, ip, idx+i, s);

                ip.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> ip;

        helper(ans, ip, 0, s);

        return ans;
    }
};