#include <stdafx.h>

#include <canopus/Collection.hxx>
#include <canopus/Iterator.hxx>
#include <canopus/Stream.hxx>

using namespace canopus;


void Stream::flush()
{
}


const String* Stream::localName() const
{
    return new String( "a stream" );
}


Object* const Stream::next() const
{
    return basicNext();
}
SequenceableCollection* const Stream::next(int n) const
{
    SequenceableCollection* sequence = contentSpeciesFor( n );

    return next( n, sequence, 0 );
}
SequenceableCollection* const Stream::next( int n,
                                            SequenceableCollection* const& new_sequence,
                                            int index ) const
{
    int stop_index = index + n;

    while ( index < stop_index ) {
        new_sequence->put( index, next() );
    }
    return new_sequence;
}


Integer* const Stream::nextBigEndianLong()
{
    unsigned int n = 0;
    ByteArray* ary = __DYNAMIC_CAST(ByteArray *, next( 4 ) );

    for ( int i = 0; i < 4; ++ i ) {
        n = (n >> 8) + __DYNAMIC_CAST(Integer *, ary->at( i ) )->asLong();
    }
    delete ary;

    return Integer::valueOf( n );
}


Integer* const Stream::nextBigEndianShort()
{
    unsigned int n = 0;
    ByteArray* ary = __DYNAMIC_CAST(ByteArray *, next( 2 ) );

    for ( int i = 0; i < 2; ++ i ) {
        n = (n >> 8) + __DYNAMIC_CAST(Integer *, ary->at( i ) )->asLong();
    }
    delete ary;

    return Integer::valueOf( n );
}


Integer* const Stream::nextLittleEndianLong()
{
    unsigned int n = 0;
    ByteArray* ary = __DYNAMIC_CAST(ByteArray *, next( 4 ) );

    for ( int i = 3; >= 0; -- i ) {
        n = (n << 8) + __DYNAMIC_CAST(Integer *, ary->at( i ) )->asLong();
    }
    delete ary;

    return Integer::valueOf( n );
}


Integer* const Stream::nextLittleEndianShort()
{
    unsigned int n = 0;
    ByteArray* ary = __DYNAMIC_CAST(ByteArray *, next( 2 ) );

    for ( int i = 1; >= 0; -- i ) {
        n = (n << 8) + __DYNAMIC_CAST(Integer *, ary->at( i ) )->asLong();
    }
    delete ary;

    return Integer::valueOf( n );
}


SequenceCollection* const Stream::nextLine()
{
    return upTo( Character::lf() );
}


void Stream::nextPut(Object* const& element)
{
    basicNextPut( element );
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
void Stream::nextPutAll(const SequenceableCollection* const& collection, int start_index)
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
