#include "media_movie_classic.h"

//-----------------------------------------------------------------------------
// constructor
Classic::Classic() {
    this->movieType = MovieType::ClassicType;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->majorActorFirst = DEFAULT_PERSON;
    this->majorActorLast = DEFAULT_PERSON;
    this->month =  DEFAULT_NUM;
    this->year = DEFAULT_NUM;
}

//-----------------------------------------------------------------------------
// copy constructor
Classic::Classic(const Classic & other) {
    this->movieType = other.movieType;
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->majorActorFirst = other.majorActorFirst;
    this->majorActorLast = other.majorActorLast;
    this->month = other.month;
    this->year = other.year;
}

//-----------------------------------------------------------------------------
// destructor
Classic::~Classic() {}

//-----------------------------------------------------------------------------
// setData
// read and store the movie in the system from the file
bool Classic::setData(ifstream & infile) {

    // set up stock
    infile.ignore();
    infile >> this->stock;

    // set up director
    infile.ignore();
    getline(infile >> ws, this->director, ',');

    // set up title
    infile.ignore();
    getline(infile >> ws, this->title, ',');

    // set major actor
    infile.ignore();
    infile >> this->majorActorFirst;
    infile.ignore();
    infile >> this->majorActorLast;

    // set month
    infile.ignore();
    infile >> this->month;

    // set year
    infile.ignore();
    infile >> this->year;

    // end of line
    return true;
}

//-----------------------------------------------------------------------------
// setMajorActorFirst
// set the major actor first name for the movie
void Classic::setMajorActorFirst(string name) {
    this->majorActorFirst = name;
}

//-----------------------------------------------------------------------------
// setMajorActorLast
// set the major actor last name for the movie
void Classic::setMajorActorLast(string name) {
    this->majorActorLast = name;
}

//-----------------------------------------------------------------------------
// setMonth
// set the month for the movie
void Classic::setMonth(int month) {
    this->month = month;
}

//-----------------------------------------------------------------------------
// getMonth
// return the month of the movie
int Classic::getMonth() const {
    return this->month;
}

//-----------------------------------------------------------------------------
// getMajorActorFirst
// return the major actor first name
string Classic::getMajorActorFirst() const {
    return this->majorActorFirst;
}

//-----------------------------------------------------------------------------
// getMajorActorLast
// return the major actor last name
string Classic::getMajorActorLast() const {
    return this->majorActorLast;
}

//-----------------------------------------------------------------------------
// getMovieType
// return the movie type
MovieType Classic::getMovieType() const {
    return this->movieType;
}

//-----------------------------------------------------------------------------
// operator<
// movie comparison operator
// arithmetic operator, sort by release date and major actor
bool Classic::operator<(const Media & other) const {
    if (this->getYear() != dynamic_cast<const Classic&>(other).getYear())
        return 
        this->getYear() < dynamic_cast<const Classic&>(other).getYear();

    if (this->getMonth() != dynamic_cast<const Classic&>(other).getMonth())
        return 
        this->getMonth() < dynamic_cast<const Classic&>(other).getMonth();

    return this->getMajorActorFirst().compare(
        dynamic_cast<const Classic&>(other).getMajorActorFirst()
    ) < 0;
}

//-----------------------------------------------------------------------------
// operator<=
// movie comparison operator
// arithmetic operator, sort by release date and major actor
bool Classic::operator<=(const Media & other) const {
    if (this->getYear() > dynamic_cast<const Classic&>(other).getYear())
        return false;

    if (this->getMonth() > dynamic_cast<const Classic&>(other).getMonth())
        return false;

    return this->getMajorActorFirst().compare(
        dynamic_cast<const Classic&>(other).getMajorActorFirst()
    ) <= 0;
}

//-----------------------------------------------------------------------------
// operator>
// Movie comparison operator
// arithmetic operator, sort by release date and major actor
bool Classic::operator>(const Media & other) const {
    if (this->getYear() != dynamic_cast<const Classic&>(other).getYear())
        return 
        this->getYear() > dynamic_cast<const Classic&>(other).getYear();

    if (this->getMonth() != dynamic_cast<const Classic&>(other).getMonth())
        return 
        this->getMonth() > dynamic_cast<const Classic&>(other).getMonth();

    return 
        this->getMajorActorFirst().compare(
        dynamic_cast<const Classic&>(other).getMajorActorFirst()
    ) > 0;
}

//-----------------------------------------------------------------------------
// operator>=
// Movie comparison operator
// arithmetic operator, sort by release date and major actor
bool Classic::operator>=(const Media & other) const {
    if (this->getYear() < dynamic_cast<const Classic&>(other).getYear())
        return false;

    if (this->getMonth() < dynamic_cast<const Classic&>(other).getMonth())
        return false;

    return this->getMajorActorFirst().compare(
        dynamic_cast<const Classic&>(other).getMajorActorFirst()
    ) >= 0;
}

//-----------------------------------------------------------------------------
// operator==
// movie comparison operator
// arithmetic operator, sort by release date and major actor
bool Classic::operator==(const Media & other) const {

    const Classic& ptrClassic = dynamic_cast<const Classic&>(other);
    return (this->getYear() == dynamic_cast<const Classic&>(other).getYear())
        && (this->getMonth() == dynamic_cast<const Classic&>(other).getMonth()
        && (this->getMajorActorFirst().compare(
            dynamic_cast<const Classic&>(other).getMajorActorFirst()
        ) == 0));
}

//-----------------------------------------------------------------------------
// operator=
// movie comparison operator
Media & Classic::operator=(const Media& other) {
    this->movieType = dynamic_cast<const Classic&>(other).getMovieType();
    this->stock = dynamic_cast<const Classic&>(other).getStock();
    this->director = dynamic_cast<const Classic&>(other).getDirector();
    this->title = dynamic_cast<const Classic&>(other).getTitle();
    this->majorActorFirst = 
        dynamic_cast<const Classic&>(other).getMajorActorFirst();
    this->majorActorLast = 
        dynamic_cast<const Classic&>(other).getMajorActorLast();
    this->month = dynamic_cast<const Classic&>(other).getMonth();
    this->year = dynamic_cast<const Classic&>(other).getYear();
    return *this;
}

//-----------------------------------------------------------------------------
// operator!=
// movie comparison operator
bool Classic::operator!=(const Media & other) const {
    return !(*this == dynamic_cast<const Classic&>(other));
}

//-----------------------------------------------------------------------------
// print
// print out the movie information to the system
void Classic::print(ostream & stream) const {
    cout << (char)this->getMovieType() << ", "
    << this->getStock() << ", "
    << this->getDirector() << ", "
    << this->getTitle() << ", "
    << this->getMajorActorFirst() << " " << this->getMajorActorLast() << ", "
    << this->getMonth() << ", "
    << this->getYear();
}

//-----------------------------------------------------------------------------
// operator<<
// print out to the system operator
ostream & operator<<(ostream & out, const Classic & movie) {
    movie.print(out);
    return out;
}