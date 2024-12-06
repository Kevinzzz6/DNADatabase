//
//  main.cpp
//  DNADatabase
//

#include <iostream>
#include <cassert>
#include "Trie.h"
#include "DNADatabase.h"


int main( ) {
    using namespace cs32;
    using namespace std;
    
    Trie trie;
    DNADatabase database;
    bool endProgram = false;
    
    cout.setf( ios::boolalpha );
    string command, data;
    const string prompt = "(T)rie (D)NADatabase (Q)uit: ";
    const string trieprompt = "(C)ontains howMany(W)ords howMany(N)onWords (S)ize (H)eight (T)oString: ";
    const string databaseprompt = "(C)ountAllGs (A)ddSequence (F)indSequence (I)sValid (S)ize (H)eight: ";
    
    do
    {
        cout << prompt;
        cin  >> command;
        switch( command.at(0) )
        {
            case 'Q':
            case 'q':
                endProgram = true;
                break;
            case 'T':
            case 't':
                cout << trieprompt;
                cin  >> command;
                switch( command.at(0) )
                {
                    case 'C':
                    case 'c':
                        cout << "provide some data: ";
                        cin  >> data;
                        cout << trie.contains( data ) << endl;
                        break;
                    case 'W':
                    case 'w':
                        cout << trie.howManyWords() << endl;
                        break;
                    case 'N':
                    case 'n':
                        cout << trie.howManyNonWords() << endl;
                        break;
                    case 'S':
                    case 's':
                        cout << trie.size() << endl;
                        break;
                    case 'H':
                    case 'h':
                        cout << trie.height() << endl;
                        break;
                    case 'T':
                    case 't':
                        cout << trie.to_string() << endl;
                        break;
                }
                break;
            case 'D':
            case 'd':
                cout << databaseprompt;
                cin  >> command;
                switch( command.at(0) )
                {
                    case 'C':
                    case 'c':
                        cout << database.countAllGs() << endl;
                        break;
                    case 'A':
                    case 'a':
                        cout << "provide some data: ";
                        cin  >> data;
                        cout << database.addSequence( data ) << endl;
                        break;
                    case 'F':
                    case 'f':
                        cout << "provide some data: ";
                        cin  >> data;
                        cout << database.findSequence( data ) << endl;
                        break;
                    case 'S':
                    case 's':
                        cout << database.size() << endl;
                        break;
                    case 'H':
                    case 'h':
                        cout << database.height() << endl;
                        break;
                    case 'I':
                    case 'i':
                        cout << "provide some data: ";
                        cin  >> data;
                        cout << database.isValid( data ) << endl;
                        break;
                }
                break;
        }
    } while( !endProgram );


    return( 0 );
}
