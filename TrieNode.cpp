//
//  TrieNode.cpp
//  DNADatabase
//

#include "TrieNode.h"
#include <iostream>


namespace cs32
{

// constructor
TrieNode::TrieNode() : mEndOfWord(false)
{
    
}

// destructor
TrieNode::~TrieNode()
{
    // delete all of the new'ed children nodes of this node
    std::map< char, TrieNode* >::const_iterator iter = nextNodeMap.begin();
    while (iter != nextNodeMap.end())
    {
        TrieNode * node = iter->second;
        // delete this node
        // but be careful
        // trying to delete a nullptr value will crash
        if (node != nullptr)
        {
            delete( node );
        }
        ++iter;
    }
}

// return a map iterator for the desired character parameter
std::map< char, TrieNode * >::const_iterator TrieNode::find( char c ) const
{
    // Check if this char has a node created for it already
    std::map< char, TrieNode* >::const_iterator iter = nextNodeMap.find(c);
    return( iter );
}

// TODO
// is the character parameter already present in the nextNodeMap of this node?
bool TrieNode::dataExists( char c ) const
{
    return nextNodeMap.find(c) != nextNodeMap.end();
}

// TODO
// set the character parameter into the nextNodeMap of this node
void TrieNode::setMapNode( char c, TrieNode * node )
{
    nextNodeMap[c] = node;
}

// TODO
// is this TrieNode the end of a word?
bool TrieNode::isEndOfWord() const
{
    return mEndOfWord;
}

// TODO
// set this TrieNode to be the end of a word
void TrieNode::setEndOfWord()
{
    mEndOfWord = true;
}

// stringify this TrieNode and all of its children nodes
std::string TrieNode::to_string() const
{
    return( to_string( 0, ' ' ) );
}

// stringify this TrieNode and all of its children nodes
std::string TrieNode::to_string( int indentLevel, char theData ) const
{
    std::string s;
    for (int i = 0; i < indentLevel; i++)
    {
        s += " ";
    }
    s += "thedata --> ";
    s += theData;
    s += "\tend  --> ";
    if (mEndOfWord)
    {
        s += "true";
    }
    else
    {
        s += "false";
    }
    s += "\n";
    
    std::map< char, TrieNode* >::const_iterator iter = nextNodeMap.begin();
    while (iter != nextNodeMap.end())
    {
        TrieNode * node = iter->second;
        char c = iter->first;
        s += node->to_string( indentLevel + INDENTATION, c );
        ++iter;
    }

    return( s );
}

// TODO
// including this node, how many nodes of this TrieNode have an EndOfWord value that is true
int  TrieNode::howManyWords() const
{
    // how many words are found in this TrieNode plus all of its mapnodes?
    int count = (mEndOfWord ? 1 : 0);
    for(std::map<char, TrieNode*>::const_iterator it = nextNodeMap.begin(); 
        it != nextNodeMap.end(); ++it) {
        if(it->second != nullptr) {
            count += it->second->howManyWords();
        }
    }
    return count;
}

// TODO
// including this node, how many nodes in this TrieNode have an EndOfWord value that is false
int  TrieNode::howManyNonWords() const
{
    // how many nonwords are found in this TrieNode plus all of its mapnodes?
    int count = (mEndOfWord ? 0 : 1);
    for(std::map<char, TrieNode*>::const_iterator it = nextNodeMap.begin(); 
        it != nextNodeMap.end(); ++it) {
        if(it->second != nullptr) {
            count += it->second->howManyNonWords();
        }
    }
    return count;
}

// TODO
// what is the size of this TrieNode
// how many nodes are there in this TrieNode?
int  TrieNode::size() const
{
    // how many TrieNodes are found in this TrieNode plus all of its mapnodes?
    // remember one for itself
    int count = 1;
    for(std::map<char, TrieNode*>::const_iterator it = nextNodeMap.begin(); 
        it != nextNodeMap.end(); ++it) {
        if(it->second != nullptr) {
            count += it->second->size();
        }
    }
    return count;
}

// TODO
// what is the height of this TrieNode
// how far away is the further away leaf in this TrieNode?
int  TrieNode::height() const
{
    // what is the longest path to a leaf node from here?
    if (nextNodeMap.empty()) {
        return 0;
    }

    int max = 0;
    for(std::map<char, TrieNode*>::const_iterator it = nextNodeMap.begin(); 
        it != nextNodeMap.end(); ++it) {
        if(it->second != nullptr) {
            int h = it->second->height();
            if(h > max) {
                max = h;
            }
        }
    }
    return max + 1;
}

}
