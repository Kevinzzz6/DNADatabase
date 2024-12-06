 //
//  TrieNode.h
//  DNADatabase
//

#ifndef TRIENODE_H
#define TRIENODE_H

#include <map>
#include <string>

namespace cs32
{

class TrieNode
{
public:
    // constructor
    TrieNode();
    // destructor
    ~TrieNode();
    
    // return a map iterator for the desired character parameter
    std::map< char, TrieNode * >::const_iterator find( char c ) const;
    
    // TODO
    // is the character parameter already present in the nextNodeMap of this node?
    bool dataExists( char c ) const;
    // TODO
    // set the character parameter into the nextNodeMap of this node
    void setMapNode( char c, TrieNode * node );
    
    // TODO
    // is this TrieNode the end of a word?
    bool isEndOfWord() const;
    // TODO
    // set this TrieNode to be the end of a word
    void setEndOfWord();
    
    // TODO
    // including this node, how many nodes of this TrieNode have an EndOfWord value that is true
    int  howManyWords() const;
    // TODO
    // including this node, how many nodes in this TrieNode have an EndOfWord value that is false
    int  howManyNonWords() const;
    // TODO
    // what is the size of this TrieNode
    // how many nodes are there in this TrieNode?
    int  size() const;
    // TODO
    // what is the height of this TrieNode
    // how far away is the further away leaf in this TrieNode?
    int  height() const;
    
    // stringify this TrieNode and all of its children nodes
    std::string to_string() const;
private:
    bool mEndOfWord; // is this a leaf node
    std::map< char, TrieNode * > nextNodeMap;  // all the child nodes of this TrieNode
    
    const int INDENTATION = 5;  // how far to indent with each new level
    std::string to_string( int indentLevel, char theData ) const;

};

}



#endif
