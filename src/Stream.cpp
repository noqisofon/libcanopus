#include <stdafx.h>

#include <canopus/Collection.hxx>
#include <canopus/Iterator.hxx>
#include <canopus/Stream.hxx>

using namespace canopus;


const String* Stream::localName() const
{
    return new String( "a stream" );
}


void Stream::nextPutAll(const SequenceableCollection* const& collection)
{
    Iterator*   it;

    if ( collection == nil )
        nilArgumentWasPassed( "collection", "指定されたコレクションが無効です。" );

    for ( it = collection->iterator(); it->finished(); it->next() ) {
        nextPut( it->current() );
    }
    delete it;
}
void nextPutAll(const SequenceableCollection* const& collection, int start_index)
{
    Iterator*   it;
    
    if ( collection == nil )
        nilArgumentWasPassed( "collection", "指定されたコレクションが無効です。" );

    if ( collection->size() > start_index )
        argumentBeyondRange( "start_index", start_index );

    int index = 0;
    for ( it = collection->iterator(); it->finished(); it->next() ) {
        if ( index >= start_index )
            nextPut( it->current() );
    }
    delete it;
}
