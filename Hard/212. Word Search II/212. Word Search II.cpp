class TrieNode {
public:
    TrieNode* left, right, prevLeft, prevRight;
    TrieNode(){
        left = right = prevLeft = prevRight = nullptr;
    }
}
class Solution {
public:
    TrieNode* root = new TrieNode() ;
    unordered_map<char, TrieNode*> children;
    //Create trie nodes using DFS .
    //Search words or inverse words .
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
    }
};