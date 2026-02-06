class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            word = "";
        }
    };

    void buildTrie(TrieNode* root, vector<string>& words) {
        // Insert all words into Trie

        for (auto word : words) {
            TrieNode* mover = root;
            for (auto c : word) {

                int idx = c - 'a';

                if (mover->children[idx] == nullptr) {
                    mover->children[idx] = new TrieNode();
                }

                mover = mover->children[idx];
            }

            mover->word = word;
        }
    }

    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* node,
             vector<vector<bool>>& visited, vector<string>& result, const int &maxRow, const int &maxCol) {
        // Explore grid with Trie guidance
        char c = board[row][col];

        // Check if this character exists in Trie
        TrieNode* child = node->children[c - 'a'];
        if (child == nullptr)
            return; // No words continue from here

        // Found a word?
        if (child->word != "") {
            result.push_back(child->word);
            child->word = ""; // Avoid duplicates!
        }

        // Explore 4 directions
        visited[row][col] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = dx[i] + row;
            int newCol = dy[i] + col;

            if (newRow >= 0 && newRow < maxRow && newCol >= 0 &&
                newCol < maxCol && !visited[newRow][newCol]) {

                dfs(board, newRow, newCol, child,
                    visited, result, maxRow, maxCol);
            }
        }

        visited[row][col] = false;
    }

    vector<string> findWords(vector<vector<char>> board, vector<string> words) {
        TrieNode* root = new TrieNode();
        buildTrie(root, words);

        int m = board.size();
        int n = board[0].size();

        vector<string> result;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Try starting from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, visited, result, m, n);
            }
        }

        return result;
    }
};