//
//  Trie.cpp
//  DNADatabase
//

#include "Trie.h"

#include <iostream>

namespace cs32
{

// the constructor
Trie::Trie( )
{
    // build the root node
    // we are not referring to the data in the root node at all
    // instead, we are using the root node to hang all the other nodes off of it
    mRoot = new TrieNode();
}

// the destructor
Trie::~Trie()
{
    // delete the root
    // but be careful
    // trying to delete a nullptr value will crash
    if (mRoot != nullptr)
        delete( mRoot );
}

// TODO
// insert a new word into this Trie
// each letter should get broken into its own TrieNode
// the ending TrieNode should be marked with an EndOfWord value that is true
void Trie::insert( std::string word )
{
    TrieNode* current = mRoot;
    for (int i = 0; i < word.length(); i++)
    {
        char c = word[i];
        if (!current->dataExists(c))
        {
            TrieNode* newNode = new TrieNode();
            current->setMapNode(c, newNode);
        }
        current = current->find(c)->second;
    }
    current->setEndOfWord();
}

// TODO
// determine if this word is already in this Trie
// each letter should be found in nextNodeMap value of a TrieNode hanging off the root of this Trie
// and in addition the last letter should be marked with an EndOfWord value that is true
bool Trie::contains( std::string word ) const
{
    TrieNode* current = mRoot;
    for (int i = 0; i < word.length(); i++)
    {
        char c = word[i];
        if (!current->dataExists(c))
        {
            return false;
        }
        current = current->find(c)->second;
    }
    return current->isEndOfWord();
    
    // Starting from the root, traverse nodes for each char in the string.

    
}

// TODO
// determine if this partial word is already in this Trie
// each letter should be found in nextNodeMap value of a TrieNode hanging off the root of this Trie
bool Trie::prefixExists( std::string prefix ) const
{
    TrieNode* current = mRoot;
    
    // Starting from the root, traverse nodes for each char in the string.
    for (int i = 0; i < prefix.length(); i++)
    {
        char c = prefix[i];
        if (!current->dataExists(c))
        {
            return false;
        }
        current = current->find(c)->second;
    }  
    return true;
    
}

// stringify this Trie and all of its TrieNodes
std::string Trie::to_string() const
{
    std::string s;
    if (mRoot != nullptr)
    {
        s = mRoot->to_string();
    }
    return( s );
}

// TODO
// how many nodes in this Trie have an EndOfWord value that is true
int  Trie::howManyWords() const
{
    // how many words are there in this trie?
    return mRoot->howManyWords();
}

// TODO
// how many nodes in this Trie have an EndOfWord value that is false
int  Trie::howManyNonWords() const
{
    // how many nonwords are there in this trie?
    return mRoot->howManyNonWords();
}

// TODO
// what is the size of this Trie
// how many nodes are there in this Trie?
int  Trie::size() const
{
    // how many nodes are there in this trie?
    return mRoot->size();
}

// TODO
// what is the height of this Trie
// how far away is the further away leaf in this Trie?
int  Trie::height() const
{
    // how far away is the further away leaf in this trie?
    return mRoot->height();
}

}
