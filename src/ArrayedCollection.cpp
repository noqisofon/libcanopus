#include <stdafx.h>

#include <canopus/ArrayedCollection.h>
using namespace canopus;


ArrayedCollection::ArrayedCollection()
     : tally_(0)
{
    assign_empty();
}
ArrayedCollection::ArrayedCollection(size_t size, Object* const& value)
     : tally_(size)
{
    assign( size, value ):
}
ArrayedCollection::ArrayedCollection(const Collection* const& collection)
     : tally_(0)
{
    if ( !collection )
        assign_empty();
    else {
        tally_ = collection->size();
        assign_from( collection );
    }
}


void ArrayedCollection::storeOn(Stream* const& stream)
{
    size_t  len;

    len = size();
    stream->nextPutAll( "#(" );
    for ( size_t i = 0; i < len; ++ i ) {
        at( i )->printOn( stream );
        if ( i < len - 1 )
            stream->nextPut( ' ' );
    }
    stream->nextPutAll( ")" );
}


void ArrayedCollection::writeOn(Stream* const& stream) const
{
}
