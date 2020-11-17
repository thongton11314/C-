#ifndef _THEATER_MANAGER_
#define _THEATER_MANAGER_
#include <fstream>
#include <iostream>
#include "command.h"
#include "customers_collection.h"
#include "media_movies_collection.h"
using namespace std;

// Class TheaterManager:
//  Description:
//   - This class read file from main to initialize customer, movie, commands
//  Implementation:
//   - Display inventory:
//     - Output all Comedy movies, then all Dramas, then all Classics.
class StoreManager {
    public:
        StoreManager();   // constructor
        ~StoreManager();  // destructor 

        // reads all customers information from text file
        void buildCustomersFromFile(ifstream &inFile);

        // reads all movies command from text file
        void buildMoviesFromFile(ifstream &inFile);

        // process all commands from file
        void processCommandsFromFile(ifstream &inFile);

        // display customer history, commands, or error message
        void report() const;
    private:
        CustomerCollection collectionCustomers;
        MediaMovieCollection collectionMedias;
        // add more data or private function if needed
};

#endif // !THEATER_MANAGER