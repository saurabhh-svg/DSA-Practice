#include "TrieNode.h"
#include <string>
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertHelper(TrieNode* root,string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]) ;
            root->children[index] = child;
        }
        insertHelper(child, word.substr(1));
    }
    void insertWord( string word)
    {
        
        insertHelper(child, word.substr(1));
    }
};