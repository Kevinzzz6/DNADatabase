//
//  DNADatabase.cpp
//  DNADatabase
//

#include "DNADatabase.h"
#include <iostream>

namespace cs32
{

DNADatabase::DNADatabase()
{
    
}

// TODO
bool DNADatabase::findSequence( std::string sequence ) const
{
    return mTrie.contains(sequence);
}

// TODO
bool DNADatabase::addSequence( std::string sequence )
{
    if (!isValid(sequence)) {
        return false;
    }

    if (mTrie.contains(sequence)) {
        return false;
    }
    mTrie.insert(sequence);
    mSequences.push_back(sequence);
    return true;
}

// TODO
bool DNADatabase::isValid( std::string sequence ) const
{
    for (char c : sequence) {
        if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
            return false;
        }
    }
    return !sequence.empty();
}

// TODO
int  DNADatabase::size() const
{
    return mTrie.size();
}

// TODO
int  DNADatabase::height() const
{
    return mTrie.height();
}

// TODO
int DNADatabase::countAllGs() const
{
    int count = 0;
    for (const std::string& seq : mSequences) {
        bool isAllG = true;
        for (char c : seq) {
            if (c != 'G') {
                isAllG = false;
                break;
            }
        }
        if (isAllG) {
            count++;
        }
    }
    return count;
}

}
