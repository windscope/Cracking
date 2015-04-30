// Implement a simple trie and implement bfs and dfs for this trie.
// The this is a "dict trie.
// Dict trie would take a vector of words and construct the trie
// Author: windscope <windscope@gmail.com>
// All rights reserved. 04/27/2015

#include <vector>
#include <set>
#include <string>

namespace crack {
class Trie {
public:
    class TrieNode {
    public:
    typedef std::set<TrieNode*> TrieNodes;
    typedef std::set<TrieNode*>::const_iterator c_node_it;
    typedef std::set<TrieNode*>::iterator node_it;
    public:
        explicit TrieNode(char value) : _value(value), _parent(nullptr) {}
        TrieNode() : _value('\0'), _parent(nullptr) {}
        TrieNode(char value, TrieNodes& kids,
                const TrieNode* parent) : _value(value), _kids(kids), _parent(parent) {}
        TrieNode(char value, TrieNodes& kids, const TrieNode* parent,
                std::set<char>& kid_dict) : _value(value), _kid_dict(kid_dict),
                _kids(kids), _parent(parent) {}
        // getters
        const TrieNodes kids() const { return _kids; }
        const std::set<char>& kid_dict() const { return _kid_dict; }
        const char value() const { return _value; }
        const TrieNode* parent() const { return _parent; }
        // mutable
        std::set<char>* mutable_kid_dict() { return &kid_dict; }
        // setters
        void set_kids(const TrieNodes& kids) { _kids = kids; }
        void set_parent(const TrieNode* parent) { _parent = parent; }
        void set_value(const char value) { _value = value; }
        void insert_into_kids(const TrieNode* node) { _kids.insert(node); }
        void insert_into_kid_dict(const char c) { _kid_dict.insert(c); }
    private:
        char _value;
        TrieNodes _kids;
        TrieNode* _parent;
        std::set<char> _kid_dict;
    };
    typedef std::set<TrieNode*> TrieNodes;
    typedef std::set<TrieNode*>::const_iterator c_node_it;
    typedef std::set<TrieNode*>::iterator node_it;
public:
    Trie() : _root(nullptr) {}
    explicit Trie(const std::vector<std::string>& words);
    virtual ~Trie();
    void insert_word(const TrieNode* node, const std::string& word,
            const std::string::const_iterator str_it);
    void free_nodes();
    // void bfs_traversal();
    // void dfs_traversal();
    // void print_words();

private:
    void free_nodes(TrieNode* node);
    TrieNode* _root;

};
} // namespace crack
