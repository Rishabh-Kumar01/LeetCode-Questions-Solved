class Solution {
public:
    void helper(vector<char> &s, int idx, int size) {

        if(idx > size/2) return;

        char current = s[idx];
        int mirror = size - 1 - idx;
        char mirrorChar = s[mirror];

        helper(s, idx+1,size);

        s[idx] = mirrorChar;
        s[mirror] = current;

    }
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size());
    }
};