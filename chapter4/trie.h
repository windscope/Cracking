// Implement a simple trie and implement bfs and dfs for this trie.
// The this is a "dict trie.
// Dict trie would take a vector of words and construct the trie
// Author: windscope <windscope@gmail.com>
// All rights reserved. 04/27/2015

#ifndef CRACK_TRIE_H
#define CRACK_TRIE_H

#include <vector>
#include <set>
#include <string>
#include <map>

namespace crack {
class Trie {
public:
    class TrieNode {
    public:
    typedef std::vector<TrieNode*> TrieNodes;
    typedef std::vector<TrieNode*>::const_iterator CNodeIterator;
    typedef std::vector<TrieNode*>::iterator NodeIterator;
    typedef std::map<char, TrieNode*> KidsDict;
    // Type of node, root is the root node, char is the value node, END represent a word ending.
    public:
    enum Type {
        ROOT = 0,
        CHAR = 1,
        END = 3
    };

    public:
        explicit TrieNode(Type type) : _value('\n'), _type(type), _parent(nullptr),
                _kids_dict(new KidsDict) {}
        TrieNode(char value, Type type) : _value(value), _type(type), _parent(nullptr),
                        _kids_dict(new KidsDict) {}
        TrieNode(char value, Type type, TrieNode* parent) : _value(value), _type(type),
                _parent(parent), _kids_dict(new KidsDict) {}

        virtual ~TrieNode() {
            _parent = nullptr;
            _value = '\0';
            delete _kids_dict;
        }

        // getters
        const char value() const { return _value; }
        const Type type() const { return _type; }
        const TrieNode* parent() const { return _parent; }
        const KidsDict* kids_dict() const { return _kids_dict; }
        const TrieNode* kid(const char key) const {
            auto it = _kids_dict->find(key);
            return it->second;
        }

        // mutable
        TrieNode* mutable_parent() {return _parent; }
        KidsDict* mutable_kids_dict() { return _kids_dict; }
        TrieNode* mutable_kid(const char key) const {
            auto it = _kids_dict->find(key);
            return it->second;
        }

        // setters
        void set_parent(TrieNode* parent) { _parent = parent; }
        void set_value(char value) { _value = value; }
        void set_kids_dict(KidsDict* kids_dict) { _kids_dict = kids_dict; }

        // convenient functions to manipulate object
        bool add_kid(TrieNode* node) {
            bool success = false;
            if (_kids_dict->find(node->value()) == _kids_dict->end()) {
                (*_kids_dict)[node->value()] = node;
                success = true;
            }
            return success;
        }
    private:
        char _value;
        Type _type;
        TrieNode* _parent;
        KidsDict* _kids_dict;
    };

public:
    Trie() : _root(nullptr) {}
    explicit Trie(const std::vector<std::string>& words);
    virtual ~Trie();

    const TrieNode* root() const { return _root; }

    void insert_words(const std::vector<std::string>& words);
    void insert_word(TrieNode* node, const std::string& word,
            std::string::const_iterator str_it, const size_t depth);
    void free_nodes();
    void bfs_traversal();
    void dfs_traversal();
    void print_words();

private:
    void free_nodes(TrieNode* node);
    TrieNode* _root;

};
} // namespace crack

#endif // CRACK_TRIE_H
