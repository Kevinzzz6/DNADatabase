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

}

// TODO
// determine if this word is already in this Trie
// each letter should be found in nextNodeMap value of a TrieNode hanging off the root of this Trie
// and in addition the last letter should be marked with an EndOfWord value that is true
bool Trie::contains( std::string word ) const
{
    bool result = false;
    
    // Starting from the root, traverse nodes for each char in the string.

    return( result );
}

// TODO
// determine if this partial word is already in this Trie
// each letter should be found in nextNodeMap value of a TrieNode hanging off the root of this Trie
bool Trie::prefixExists( std::string prefix ) const
{
    bool result = false;
    
    // Starting from the root, traverse nodes for each char in the string.
    
    return( result );
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
    int result = -1;
    // how many words are there in this trie?
    return( result );
}

// TODO
// how many nodes in this Trie have an EndOfWord value that is false
int  Trie::howManyNonWords() const
{
    int result = -1;
    // how many nonwords are there in this trie?
    return( result );
}

// TODO
// what is the size of this Trie
// how many nodes are there in this Trie?
int  Trie::size() const
{
    int result = -1;
    // how many nodes are there in this trie?
    return( result );
}

// TODO
// what is the height of this Trie
// how far away is the further away leaf in this Trie?
int  Trie::height() const
{
    int result = -1;
    // how far away is the further away leaf in this trie?
    return( result );
}

}
