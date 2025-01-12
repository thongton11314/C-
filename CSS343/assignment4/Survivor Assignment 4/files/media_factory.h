#ifndef _MEDIA_FACTORY_
#define _MEDIA__FACTORY_
#include "media_movie_factory.h"

// Class MediaFactory:
//  Description:
//   - This factory create DVD type movie
//  Implementation:
//   - Create Hashtable:
//     - Create DVD type movie for the system
class MediaFactory {
public:
    static Media * createDVDMovie(ifstream & infile);
    // further media type add here
};
#endif //!_MEDIA_FACTORY_