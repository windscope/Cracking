#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    TrieNode() : _isEnd(false) {}

    void set_isEnd(bool isEnd) {
        _isEnd = isEnd;
    }

    void insert_node(char val) {
        if (_nexts.find(val) == _nexts.end()) {
            _nexts[val] = new TrieNode();
        }
    }

    bool isEnd() {
        return _isEnd;
    }

    TrieNode* get_node_by_val(char val) {
        if (_nexts.find(val) == _nexts.end()) {
            return nullptr;
        } else {
            return _nexts[val];
        }
    }

    ~TrieNode() {
        for (auto& next : _nexts) {
            delete next.second;
        }
    }

private:
    unordered_map<char, TrieNode*> _nexts;
    bool _isEnd;
};

class Trie {
public:
    Trie() : _root(new TrieNode()) {}

    ~Trie() {
        delete _root;
    }

    // Inserts a word into the trie.
    void insert(const string& word) {
        insertWithPos(word, 0, _root);
    }

    // Returns if the word is in the trie.
    bool search(const string& word) {
        return searchWithPos(word, 0, _root, true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return searchWithPos(prefix, 0, _root, false);
    }

private:
    void insertWithPos(const string& word, int pos, TrieNode* node) {
        if (word.size() == pos) {
            node->set_isEnd(true);
            return;
        }
        node->insert_node(word[pos]);
        TrieNode* next_node = node->get_node_by_val(word[pos]);
        insertWithPos(word, pos + 1, next_node);
    }

    bool searchWithPos(const string& word, int pos, TrieNode* node, bool checkComplete) {
        if (word.size() == pos) {
            if (checkComplete) {
                return node->isEnd();
            } else {
                return true;
            }
        }
        TrieNode* next_node = node->get_node_by_val(word[pos]);
        if (next_node == nullptr) {
            return false;
        } else {
            return searchWithPos(word, pos + 1, next_node, checkComplete);
        }
    }


private:
    TrieNode* _root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
    Trie trie;
    trie.insert("good");
    cout << trie.search("good") << endl;
    trie.insert("goodbye");
    cout << trie.search("good") << endl;
    cout << trie.startsWith("goodb") << endl;
    cout << trie.search("goodb") << endl;
    cout << trie.search("goodbye") << endl;

    return 0;
}
