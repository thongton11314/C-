#ifndef _DRAMA_
#define _DRAMA_
#include "media_movie.h"

// Class Drama:
//  Description:
//   - This class create a drama type movie
//  Implementation:
//   - Create Drama:
//     - Create and set movie name and type related to the file
class Drama : public Movie {

    // operator<<
    friend ostream& operator<<(ostream &, const Drama &);
    
public:

    // constructor
    Drama();

    // copy constructor
    Drama(const Drama &drama);

    // set data
    bool setData(ifstream & infile);

    // deconstructor
    virtual ~Drama();

    // getter
    virtual MovieType getMovieType() const;
    void print(ostream & out) const;

    // arithmetic operator, sort by director and then title
    virtual bool operator<(const Media&) const;
    virtual bool operator<=(const Media&) const;
    virtual bool operator>(const Media&) const;
    virtual bool operator>=(const Media&) const;
    virtual bool operator==(const Media&) const;
    virtual bool operator!=(const Media&) const;
    virtual Media & operator=(const Media&);
};
#endif //!_DRAMA_