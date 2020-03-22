//
//  No.208.Trie.h
//  LeetCode
//
//  208. 实现 Trie (前缀树)
//  https://leetcode-cn.com/problems/implement-trie-prefix-tree/
//  Created by baiya on 2020/3/22.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_208_Trie_h
#define No_208_Trie_h

#include <string>

#define MAX_APLHE_COUNT (26)

// TODO 前缀树
class Trie {
private:
    bool is_string = false;
    Trie* next[MAX_APLHE_COUNT] = {nullptr};
    
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    ~Trie() {
        for (int i = 0; i < MAX_APLHE_COUNT; i++)
        {
            if (next[i] == nullptr) continue;
            delete(next[i]);
            next[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* t = this;
        for (auto c : word) {
            if (t->next[c - 'a'] == nullptr) {
                t->next[c - 'a'] = new Trie();
            }
            t = t->next[c - 'a'];
        }
        t->is_string = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* t = this;
        for (char c : word) {
            if (t->next[c - 'a'] == nullptr) {
                return false;
            }
            t = t->next[c - 'a'];
        }
        return t->is_string;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* t = this;
        for (char c : prefix) {
            if (t->next[c - 'a'] == nullptr) {
                return false;
            }
            t = t->next[c - 'a'];
        }
        return true;
    }
};
#endif /* No_208_Trie_h */
