/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月01日 星期日 12时52分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

class WordDictionary {
public:
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

    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode* node = root;
        return helper(word, 0, node);
    }

    bool helper(string& word, int start, TrieNode* node) {
        int l = word.length();
        if(start >= l || !node)
            return false;
        if(start == l - 1) {
            if(word[start] == '.') {
                for(int i = 0; i < 26; i++) {
                    if(node->child[i] && node->child[i] ->end)
                        return true;
                }
                return false;
            }
            else {
                return node->child[word[start] - 'a'] && node->child[word[start] - 'a']->end;
            }
        }
        if(word[start] == '.')
        {
            bool result = false;
            for(int i = 0; i < 26; i++) {
                result = helper(word, start + 1, node->child[i]);
                if(result)
                    return true;
            }
            return false;
        }
        else {
            if(!node->child[word[start] - 'a'])
                return false;
            return helper(word, start + 1, node->child[word[start] - 'a']);
        }
    }

private:
    TrieNode* root;
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout<<wordDictionary.search("pad")<<endl;
    cout<<wordDictionary.search("bad")<<endl;
    cout<<wordDictionary.search(".ad")<<endl;
    cout<<wordDictionary.search("b..")<<endl;
    return 0;
}