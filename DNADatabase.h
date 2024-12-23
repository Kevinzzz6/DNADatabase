//
//  DNADatabase.h
//  DNADatabase
//

#ifndef DNADATABASE_H
#define DNADATABASE_H

#include "Trie.h"
#include <string>
#include <vector>

namespace cs32
{

class DNADatabase
{
public:
    DNADatabase();
    
    // TODO
    bool findSequence( std::string sequence ) const;
    // TODO
    bool addSequence( std::string sequence );
    // TODO
    bool isValid( std::string sequence ) const;
    int  countAllGs() const;
    // TODO
    int  size() const;
    // TODO
    int  height() const;

private:
    Trie mTrie;
    std::vector<std::string> mSequences;
};

}

#endif
