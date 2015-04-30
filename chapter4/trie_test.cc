// Test case for trie.cc
// Author windscope <windscope@gmail.com>
#include "trie.h"

int main() {
    std::vector<std::string> data = {"hello", "goodbye", "hi", "good"};
    crack::Trie trie(data);
    trie.dfs_traversal();
    return 0;
}
