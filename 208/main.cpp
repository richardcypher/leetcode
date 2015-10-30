/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月30日 星期五 10时34分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
class TrieNode {
public:
    char val;
    bool end;
    TrieNode* child[26];
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        int i = 0, l = word.length();
        while(i < l) {
            if(!node->child[word[i] - 'a']) {
                node->child[word[i] - 'a'] = new TrieNode();
                node->child[word[i] - 'a']->val = word[i];
            }
            node = node->child[word[i] - 'a'];
            i++;
        }
        node->end = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        int i = 0, l = word.length();
        while(i < l) {
            if(!node->child[word[i] - 'a'])
                return false;
            node = node->child[word[i] - 'a'];
            i++;
        }
        return node->end;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        int i = 0, l = prefix.length();
        while(i < l) {
            if(!node->child[prefix[i] - 'a'])
                return false;
            node = node->child[prefix[i] - 'a'];
            i++;
        }
        return true;
    }
private:
    TrieNode* root;
};

int main() {
    Trie trie;
    trie.insert("abc");
    cout<<trie.search("abc")<<endl;
    cout<<trie.search("ab")<<endl;
    trie.insert("ab");
    cout<<trie.search("ab")<<endl;
    trie.insert("ab");
    cout<<trie.search("ab")<<endl;
    return 0;
}