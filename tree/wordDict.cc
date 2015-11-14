#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class TrieNode {
public:
    TrieNode() : _isEnd(false) {}

    ~TrieNode() {
        for (auto next : _nexts) {
            delete next.second;
        }
    }

    bool isEnd() {
        return _isEnd;
    }

    void set_isEnd(const bool isEnd) {
        _isEnd = isEnd;
    }

    void insert_node(const char val) {
        if (_nexts.count(val) == 0) {
            _nexts[val] = new TrieNode();
        }
    }

    TrieNode* get_node_by_val(const char val) {
        if (_nexts.count(val) > 0) {
            return _nexts[val];
        } else {
            return nullptr;
        }
    }

    vector<TrieNode*> get_all_nodes() {
        vector<TrieNode*> nodes;
        for (auto& next : _nexts) {
            nodes.push_back(next.second);
        }
        return nodes;
    }

private:
    unordered_map<char, TrieNode*> _nexts;
    bool _isEnd;
};

class WordDictionary {
public:
    WordDictionary() : _root(new TrieNode()) {}

    ~WordDictionary() {
        delete _root;
    }

    // Adds a word into the data structure.
    void addWord(const string& word) {
        addWordWithPos(word, 0, _root);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(const string& word) {
        return searchWithPos(word, 0, _root);
    }
private:
    void addWordWithPos(const string& word, int pos, TrieNode* node) {
        if (word.size() == pos) {
            node->set_isEnd(true);
            return;
        }
        node->insert_node(word[pos]);
        TrieNode* next_node = node->get_node_by_val(word[pos]);
        addWordWithPos(word, pos + 1, next_node);
    }

    bool searchWithPos(const string& word, int pos, TrieNode* node) {
        if (word.size() == pos) {
            return node->isEnd();
        }
        if (word[pos] == '.') {
            vector<TrieNode*> nodes = node->get_all_nodes();
            for (auto node : nodes) {
                if (searchWithPos(word, pos + 1, node)) {
                    return true;
                }
            }
            return false;
        } else {
            TrieNode* next_node = node->get_node_by_val(word[pos]);
            if (next_node == nullptr) {
                return false;
            } else {
                return searchWithPos(word, pos + 1, next_node);
            }
        }
    }
private:
    TrieNode* _root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


int main(void) {
    WordDictionary wd;
    wd.addWord("good");
    cout << wd.search("g..d") << endl;
    cout << wd.search("good") << endl;
    cout << wd.search("g") << endl;
    return 0;
}
