// Author windscope <windscope@gamil.com>
// All right reserverd. 04/27/2015
#include "trie.h"

#include <cassert>
#include <set>
#include <string>
#include <iostream>

namespace crack {
Trie::Trie(const std::vector<std::string>& words) {
    // root neeed tobe nullptr
    _root = new TrieNode(TrieNode::ROOT);
    insert_words(words);
}

Trie::~Trie() {
    free_nodes();
}

void Trie::insert_words(const std::vector<std::string>& words) {
    for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it) {
        insert_word(_root, *it, it->begin(), 0);
    }
}

void Trie::insert_word(TrieNode* node, const std::string& word,
        std::string::const_iterator str_it, const size_t step) {
    if (node != nullptr) {
        // If the word is finished insertion
        if (step > word.size())
            return;
        // Assuming this is a CHAR node
        TrieNode::Type type = TrieNode::CHAR;
        // Changed into END node if this is an end node
        if (str_it == word.end()) {
            type = TrieNode::END;
        }
        // debug
        // std::cout<< " now in step: " << step << " " << *str_it << std::endl;
        auto kid = node->kids_dict()->find(*str_it);
        if (kid == node->kids_dict()->end()) {
            TrieNode* new_kid = new TrieNode(*str_it, type, node);
            node->add_kid(new_kid);
            kid = node->kids_dict()->find(*str_it);
            assert(kid != node->kids_dict()->end());
        }
        insert_word(kid->second, word, str_it + 1, step + 1);
    }
}

void Trie::free_nodes() {
    if (_root != nullptr) {
        free_nodes(_root);
    }
}

void Trie::free_nodes(TrieNode* node) {
    if (node != nullptr) {
        for(auto it = node->mutable_kids_dict()->begin(); it != node->mutable_kids_dict()->end();
                    ++it) {
            free_nodes(it->second);
        }
        node->mutable_kids_dict()->clear();
        std::cout << "now freeing " << node->value() << std::endl;
        delete node;
    }
}

namespace {
void dfs(std::set<Trie::TrieNode*>* node_set, Trie::TrieNode* node) {
    if (node != nullptr) {
        // This node set is actually unnecessary for node test, since it is a tree not a DAG
        if (node_set->find(node) == node_set->end()) {
            node_set->insert(node);
            std::cout << node->value();
            for (auto it = node->kids_dict()->begin(); it != node->kids_dict()->end(); ++it) {
                dfs(node_set, it->second);
            }
        }
    }
}
}// anonymous namespace

void Trie::bfs_traversal() {
}

void Trie::dfs_traversal() {
    std::set<TrieNode*> node_set;
    dfs(&node_set, _root);
}

void Trie::print_words() {

}

} // namespace crack
