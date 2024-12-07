#include <iostream>
#include <string>
#include <cassert>
#include "TrieNode.h"
#include "Trie.h"
#include "DNADatabase.h"

int main()
{
    using namespace std;
    using namespace cs32;
     
    // Tests for TrieNodes
    TrieNode* node = new TrieNode(); 
    TrieNode* node2 = new TrieNode();
    
    assert(node->size() == 1);
    assert(node->height() == 0);
    assert(node->howManyWords() == 0);
    assert(node->howManyNonWords() == 1);
    assert(!node->isEndOfWord());
    assert(!node->dataExists('c'));
    
    node->setMapNode('c', node2);
    node2->setEndOfWord();
    assert(node2->isEndOfWord());
    assert(node->size() == 2);
    assert(node->height() == 1);
    assert(node->howManyWords() == 1);
    assert(node->howManyNonWords() == 1);
    assert(node->dataExists('c'));
    assert(!node2->dataExists('c'));
    
    std::map<char, TrieNode*>::const_iterator iter = node->find('c');
    assert(iter->first == 'c');

    delete node;

    // Tests for Tries
    Trie trie;
    assert(!trie.contains("howard"));
    assert(trie.howManyWords() == 0);
    assert(trie.howManyNonWords() == 1);
    assert(trie.size() == 1);
    assert(trie.height() == 0);
    
    trie.insert("howard");
    assert(trie.howManyWords() == 1);
    assert(trie.howManyNonWords() == 6);
    assert(trie.size() == 7);
    assert(trie.height() == 6);
    assert(trie.contains("howard"));
    assert(!trie.contains("pixie"));
    assert(!trie.contains("how"));
    
    trie.insert("how");
    assert(trie.howManyWords() == 2);
    assert(trie.howManyNonWords() == 5);
    assert(trie.size() == 7);
    assert(trie.height() == 6);

    // Tests for DNADatabase
    DNADatabase database;
    assert(database.countAllGs() == 0);
    assert(database.size() == 1);
    assert(database.height() == 0);
    assert(database.isValid("AGCT"));
    assert(!database.isValid("agct"));
    assert(!database.isValid("AGrCT"));
    assert(!database.findSequence("howard"));
    assert(!database.findSequence("AGCT"));
    
    assert(database.addSequence("AGCT"));
    assert(database.size() == 5);
    assert(database.height() == 4);
    assert(!database.addSequence("howard"));
    assert(database.findSequence("AGCT"));
    assert(database.size() == 5);
    assert(database.height() == 4);
    assert(database.countAllGs() == 0);
    
    assert(database.addSequence("G"));
    assert(database.countAllGs() == 1);
    assert(database.addSequence("GG"));
    assert(database.countAllGs() == 2);

    cout << "all tests passed!" << endl;
    return(0);
}