class Solution {
public:
    string getPermutation(int n, int k) {
        list<int> input; // Use list instead of vector
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

            // Iterator-based removal: O(n) to find, O(1) to remove
            auto it = input.begin();
            advance(it, group);
            ans += to_string(*it);
            input.erase(it);

            if (input.size() == 0)
                break;

            k = k % fact;
            fact /= input.size();
        }

        return ans;
    }
};