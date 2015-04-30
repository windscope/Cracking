// Implement a simple trie and implement bfs and dfs for this trie.
// The this is a "dict trie.
// Dict trie would take a vector of words and construct the trie
// Author: windscope <windscope@gmail.com>
// All rights reserved. 04/27/2015

#include <vector>
#include <string>

namespace crack {
class Trie {
    typedef std::vector<TrieNode*> TrieNodes;
    tyopo
    class TrieNode {
    public:
        explicit TrieNode(char value) : _value(value), _parent(nullptr) {}
        TrieNode() : _value(NULL), _parent(nullptr) {}
        TrieNode(char value, const std::vector<TrieNode*>& kids, const Node* parent) _value(value), _kids(kids), _parent(parent) {}
        const std::vector<TrieNode>get_kids() { return _kids; }
    private:
        char _value;
        std::vector<TrieNode*> _kids;
        TrieNode* _parent;
    };
public:
    explicit Trie(std::vector<std::string>);
    virtual ~Trie();
    void free_nodes();
    void bfs_traversal();
    void dfs_traversal();

private:

};
} // namespace crack
