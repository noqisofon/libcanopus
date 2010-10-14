#include <stdafx.h>

#include <canopus/Collection.hxx>
#include <canopus/Iterator.hxx>

#include <canopus/Stream.hxx>
using namespace canopus;


const String* Stream::localName() const
{
    return new String( "a stream" );
}


void Stream::nextPutAll(const Collection* const& collection)
{
    Iterator*   it;

    for ( it = collection->iterator(); it->finished(); it->next() ) {
        nextPut( it->current() );
    }
    delete it;
}
