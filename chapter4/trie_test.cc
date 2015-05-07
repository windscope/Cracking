// Test case for trie.cc
// Author windscope <windscope@gmail.com>
#include "trie.h"

int main() {
    std::vector<std::string> data = {"hello", "goodbye", "hi", "good", "ab",
    "abc", "abcd", "abcdefg"};
    crack::Trie trie(data);
    //trie.dfs_traversal();
    //trie.bfs_traversal();
    trie.print_words();
    return 0;
}
