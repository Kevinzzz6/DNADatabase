//
//  Trie.h
//  DNADatabase
//

#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>

namespace cs32
{

// A Trie data structure based on TrieNode
class Trie{
public:
    // constructor
    Trie();
    // destructor
    ~Trie();
    
    // TODO
    // insert a new word into this Trie
    // each letter should get broken into its own TrieNode
    // the ending TrieNode should be marked with an EndOfWord value that is true
    void insert( std::string word );
    // TODO
    // determine if this word is already in this Trie
    // each letter should be found in nextNodeMap value of a TrieNode hanging off the root of this Trie
    // and in addition the last letter should be marked with an EndOfWord value that is true
    // TODO
    bool contains( std::string word ) const;
    // TODO
    // determine if this partial word is already in this Trie
    // each letter should be found in nextNodeMap value of a TrieNode hanging off the root of this Trie
    bool prefixExists( std::string prefix ) const;
    
    // TODO
    // how many nodes in this Trie have an EndOfWord value that is true
    int  howManyWords() const;
    // TODO
    // how many nodes in this Trie have an EndOfWord value that is false
    int  howManyNonWords() const;
    // TODO
    // what is the size of this Trie
    // how many nodes are there in this Trie?
    int  size() const;
    // TODO
    // what is the height of this Trie
    // how far away is the further away leaf in this Trie?
    int  height() const;
    
    // stringify this Trie and all of its TrieNodes
    std::string to_string() const;
private:
    // the root TrieNode from which all the other TrieNodes are attached
    TrieNode * mRoot;
};


}

#endif 
