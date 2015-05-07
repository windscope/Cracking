// Author windscope <windscope@gamil.com>
// All right reserverd. 04/27/2015
#include "trie.h"

#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>


namespace crack {

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

void bfs(Trie::TrieNode* node) {
    if (node != nullptr) {
        std::queue<Trie::TrieNode*> node_queue;
        std::set<Trie::TrieNode*> node_set;
        std::cout << node->value();
        node_queue.push(node);
        while (!node_queue.empty()) {
            Trie::TrieNode* current_node = node_queue.front();
            node_queue.pop();
            for (auto it = current_node->kids_dict()->begin();
                        it != current_node->kids_dict()->end(); ++it) {
                if (node_set.find(it->second) == node_set.end()) {
                node_queue.push(it->second);
                node_set.insert(it->second);
                std::cout << it->first;
                }
            }
        }
    }
}

} // anonymous namespace

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
        for (auto it = node->mutable_kids_dict()->begin(); it != node->mutable_kids_dict()->end();
                    ++it) {
            free_nodes(it->second);
        }
        node->mutable_kids_dict()->clear();
        // For debugging
        // std::cout << "now freeing " << node->value() << std::endl;
        delete node;
    }
}

void Trie::bfs_traversal() {
    bfs(_root);
}

void Trie::dfs_traversal() {
    std::set<TrieNode*> node_set;
    dfs(&node_set, _root);
}

void Trie::print_words() {
    std::unordered_map<TrieNode*, std::string> str_dict;
    std::queue<TrieNode*> node_queue;
    node_queue.push(_root);
    std::string init_str;
    str_dict[_root] = init_str;
    while (!node_queue.empty()) {
        TrieNode* current_node = node_queue.front();
        node_queue.pop();
        if (current_node->type() == TrieNode::END) {
            // check the node is stored in the dict
            assert(str_dict.find(current_node) != str_dict.end());
            std::cout << str_dict[current_node] << std::endl;
        }
        for (auto it = current_node->kids_dict()->begin();
                it != current_node->kids_dict()->end(); ++it) {
            if (str_dict.find(it->second) == str_dict.end()) {
                std::string it_str = str_dict[current_node];
                it_str.push_back(it->second->value());
                str_dict[it->second] = it_str;
            }
            node_queue.push(it->second);
        }
        // after handling all the kids for the current node, we can get rid of its string from dict
        str_dict.erase(current_node);
    }


}

} // namespace crack
