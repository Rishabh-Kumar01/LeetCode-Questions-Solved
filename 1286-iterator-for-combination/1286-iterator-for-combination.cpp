class CombinationIterator {
private:
    vector<string> combinations;
    int index;

    void helper(string& s, vector<string>& combinations, int start,
                const int& k, string& curr) {
        if (curr.size() == k) {
            combinations.push_back(curr);
            // return;
        }

        for (int i = start; i < s.size(); i++) {
            curr.push_back(s[i]);
            helper(s, combinations, i + 1, k, curr);
            curr.pop_back();
        }
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        index = 0;
        string curr = "";

        helper(characters, combinations, 0, combinationLength, curr);
    }

    string next() { return combinations[index++]; }

    bool hasNext() { return index < combinations.size(); }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */