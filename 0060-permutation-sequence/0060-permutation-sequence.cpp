class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> input;
        int fact = 1;

        for (int i = 1; i < n; i++) {
            input.push_back(i);
            fact *= i;
        }
        input.push_back(n);

        string ans = "";
        k = k - 1;

        while (true) {
            int group = k / fact;
            ans += to_string(input[group]);
            input.erase(input.begin() + group);

            if (input.size() == 0)
                break;

            k = k % fact;

            fact /= input.size();
        }

        return ans;
    }
};