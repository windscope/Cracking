// Author windscope <windscope@gamil.com>
// All right reserverd. 04/27/2015
#include "trie.h"

namespace crack {
Trie::Trie(const std::vector<std::string>& words) {
    _root = new TrieNode();
    for (size_t i = 0; i < words.size(); ++i) {
        insert_word(_root, words[i], words[i].bengin());
    }
}

Trie::~Trie() {
    free_node();
}

void Trie::insert_word(const TrieNode* node, const std::string& word,
        const std::string::const_iterator str_it) {
    if (node != nullptr) {
        if (str_it == word.end()) {
            return;
        }
        auto kid = node->kid_dict().find(*str_it);
        if (kid == node->kid_dict().end()) {
            TrieNode* new_kid = new TrieNode(*str_it);
            new_kid->set_parent(node);
            node->insert_into_kids(new_kid);
            node->insert_into_kid_dict(*str_it);
            kid = node->kid_dict().find(*str_it);
            assert(kid != node->kid_dict.end());
        }
        insert_word(*kid, word, str_it + 1);
    }
}

void Trie::free_node() {
    if (_root != nullptr) {
        free_node(_root);
    }
}

void Trie::free_node(TrieNode* node) {
    if (node != nullptr) {
        _parent = nullptr;
        _value = NULL;
        _kid_dict.clear();
        for(auto it = (*node->mutable_kid_dict()).front(); it != (*node->mutable_kid_dict()).end();
                    ++it) {
            free_node(*it);
            (*node->mutable_kid_dict()).erase(it);
        }
    }
}
} // namespace crack
