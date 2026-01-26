class CombinationIterator {
private:
    string s;
    int k;
    vector<int> indices;
    bool hasNextFlag;

public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        k = combinationLength;
        hasNextFlag = true;

        for (int i = 0; i < k; i++)
            indices.push_back(i);
    }

    string next() {
        string ans = "";

        for (int i = 0; i < k; i++) {
            ans += s[indices[i]];
        }

        int i = k - 1;
        while (i >= 0 && indices[i] == s.size() - k + i)
            i--;

        if (i < 0) {
            hasNextFlag = false;
        } else {
            indices[i]++;

            for (int j = i + 1; j < k; j++) {
                indices[j] = indices[j - 1] + 1; // ✅ Set to previous + 1
            }
        }

        return ans;
    }

    bool hasNext() { return hasNextFlag; }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */