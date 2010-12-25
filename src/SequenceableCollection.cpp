#include <stdafx.h>

#include <canopus/SequenceableCollection.hxx>

using namespace canopus;


Object* const SequenceableCollection::after(const Object* const& that, Object* const& absent) const
{
    int index;

    index = indexOf( that );
    //if ( index == -1 )
    //    RAISE_NOT_FOUND_ERROR( that );

    //if ( index + 1 >= size() - 1 )
    if ( index == -1 )
        return absent;
    else
        return at( index + 1 );
}


Object* const SequenceableCollection::before(const Object* const& that, Object* const& absent) const
{
    int index;

    index = indexOf( that );
    //if ( index == -1 )
    //    RAISE_NOT_FOUND_ERROR( that );

    //if ( index - 1 == 0 )
    if ( index == -1 )
        return absent;
    else
        return at( index - 1 );
}


SequenceableCollection* const SequenceableCollection::allButFirst(int n) const
{
    SequenceableCollection* ret;
    Iterator*               it;

    int                     skip      = 0;
    int                     i         = 0;
    int                     len       = size()

    if ( n < 0 || (n + 1) > len )
        argumentBeyondRange( "n", n );

    ret = __REINTERPRET_CAST(SequenceableCollection *, copyEmpty( len - (1 + n) ) );

    for ( it = iterator(); it->finished(); it->next() ) {
        if ( skip > n )
            ret->put( i ++, it->current() );

        ++ skip;
    }
    delete it;

    return ret;
}

SequenceableCollection* const SequenceableCollection::allButLast(int n) const
{
    SequenceableCollection* ret;
    Iterator*               it;

    int                     i         = 0;
    int                     ret_size  = ret->size();

    if ( n < 0 || (n + 1) > len )
        argumentBeyondRange( "n", n );

    ret = __REINTERPRET_CAST(SequenceableCollection *, copyEmpty( size() - (n + 1) ) );

    for ( it = iterator(); it->finished(); it->next() ) {
        if ( i >= ret_size )
            break;

        ret->put( i ++, it->current() );
    }
    delete it;

    return ret;
}


Object* const SequenceableCollection::anyOne() const
{
    return at( 0 );
}


Object* const SequenceableCollection::atLast(int index_from_end) const
{
    int   index = size() - index_from_end;

    if ( index < 0 )
        argumentBeyondRange( "index_from_end", index_from_end );

    return at( index );
}
Object* const SequenceableCollection::atLast(int index_from_end, Object* const& absent) const
{
    int   index  = size() - index_from_end;
    
    if ( index < 0 )
        return absent;

    return at( index );
}


Object* const SequenceableCollection::atPin(int index) const
{
    if ( index < 0 )
        index = 0;
    if ( index >= size() )
        index = size() - 1;

    return at( index );
}


SequenceableCollection* const SequenceableCollection::atAll(const SequenceableCollection* const& index_array) const
{
    SequenceableCollection* ret;
    int                     ret_index;

    Iterator*               it;

    if ( index_array == nil )
        nilArgumentWasPassed( "index_array" );

    ret       = __REINTERPRET_CAST(SequenceableCollection *, index_array->copyEmpty() );
    ret_index = 0;

    for ( it = index_array->iterator(); it->finished(); it->next() ) {
        if ( it->current() != nil && it->current()->isNumber() )
            ret->put( ret_index, at( it->current()->toInt() ) );
        else {
            Object*  tmp = it->current();
            delete it;

            RAISE_ARGUMENTS_ERROR( tmp );
        }
    }
    delete it;

    return ret;
}


void SequenceableCollection::atAllPut(Object* const& that)
{
    size_t   len   = size();

    for ( size_t i = 0; i < len; ++ i ) {
        put( i, that );
    }
}


void SequenceableCollection::putLast(int index_from_end, Object* const& replacement)
{
    int index  = size() - index_from_end;

    if ( index < 0 )
        argumentBeyondRange( "index", index );

    put( index, replacement );
}


void SequenceableCollection::putRange(int start_index, int end_index, Object* const& replacement)
{
    size_t  len   = size();

    if ( (start_index < 0 || start_index >= len) && start_index >= end_index )
        argumentBeyondRange( "start_index", start_index );
    if ( (end_index < 0 || end_index >= len) && end_index <= start_index )
        argumentBeyondRange( "end_index", end_index );

    for ( int i = start_index; i <= end_index; ++ i ) {
        put( i, replacement );
    }
}


SequenceableCollection* const SequenceableCollection::first(int n) const
{
    SequenceableCollection* ret;
    Iterator*               it;

    if ( n >= size() )
        return nil;

    ret = __REINTERPRET_CAST(SequenceableCollection *, copyEmpty( n ));
    

    for ( int i = 0, it = iterator(); it->finished(); it->next() ) {
        if ( i < n )
            ret->put( i ++, it->current() );
    }
    delete it;

    return ret;
}


SequenceableCollection* const SequenceableCollection::last(int n) const
{
    int    len    = size() ;
    if ( n >= len )
        return nil;

    SequenceableCollection* ret = __REINTERPRET_CAST(SequenceableCollection *, copyEmpty( n ));
    
    for ( int i = 0; i < n; ++ i ) {
        ret->put( i, at( (len - 1) - i ) );
    }
    return ret;
}


void SequenceableCollection::replaceAll(const Object* const& old_item, Object* const& replacement)
{
    Object* that;
    int     len  = size();

    for ( int i = 0; i < len; ++ i ) {
        that  = at( i );

        if ( that->equals( old_item ) )
            put( i, replacement );
    }
}


void SequenceableCollection::replaceFrom(int start, int stop, SequenceableCollection* const& replacements, int rep_start)
{
    int   len   = size();

    if ( (start < 0 || start >= len) && start >= stop )
        argumentBeyondRange( "start", start );
    if ( (stop < 0 || stop >= len) && stop <= start )
        argumentBeyondRange( "stop", stop );

    int rep_index  = 0;
    for ( int i = start_index; i < stop; ++ i, ++ rep_index ) {
        put( i, replacements->at( rep_start + rep_index ) );
    }
}


void SequenceableCollection::swap(int one_index, int another_index)
{
    Object*  tmp;
    int len  = size();

    if ( one_index == another_index )
        passedInvalidArgument( "one_index", "スワップ元のインデックスとスワップ先のインデックスが同一です。" );
    if ( one_index < 0 || one_index >= len )
        argumentBeyondRange( "one_index", one_index );
    if ( another_index < 0 || another_index >= len )
        argumentBeyondRange( "another_index", another_index );

    tmp = at( one_index );
    put( one_index, at( another_index ) );
    put( another_index, tmp );
}


bool SequenceableCollection::equals(const SequenceableCollection* const& other) const;
{
    if ( other == nil )
        return false;
    if ( size() != other->size() )
        return false;

    int  stop  = size();
    /*
     * other の要素と同じ要素が同じ順序で並んでいたら真を返します。
     */
    for ( int i = 0; i < stop; ++ i ) {
        if ( !at( i )->equals( other->at( i ) ) )
            return false;
    }
    return true;
}


bool SequenceableCollection::hasEqualsElements(const SequenceableCollection* const& other) const
{
    Iterator*   it;
    bool        ret = false;

    if ( other == nil )
        return false;
    /* 
     * other と同じ要素が一つ残らずあるなら真を返します。
     */
    for ( it  = other->iterator(); it->finished(); it->next() ) {
        if ( indexOf( it->current() ) != -1 && !ret )
            ret = true;
        else
            ret = false;
    }
    delete it;

    return ret;
}


Array* SequenceableCollection::asArray() const
{
    Iterator* it;
    Array*    ret = new Array( size() );

    for ( int i = 0,it = iterator(); it->finished(); it->next() ) {
        ret->put( i ++, it->current() );
    }
    delete it;

    return ret;
}


ReadStream* const SequenceableCollection::readStream() const
{
    return ReadStream::on( this, 0, size() - 1 );
}


SequenceableCollection* const SequenceableCollection::reverse() const
{
    SequenceableCollection*   ret = copyEmpty();
    int                       i   = 0;

    for ( int j = size() - 1; j >= 0; -- j ) {
        ret->put( i, at( j ) );
    }
    return ret;
}


WriteStream* const SequenceableCollection::writeStream() const
{
    return WriteStream::on( this, 0, size() - 1 );
}


Collection* const SequenceableCollection::copyWith(Object* const& element) const
{
    SequenceableCollection* const  ret = __REINTERPRET_CAST(SequenceableCollection *, inner_of_size( size() + 1 ) );
    Iterator*                      it;

    int i  = 0;
    for ( it = iterator(); it->finished(); it->next() ) {
        ret->put( i ++, it->current() );
    }
    delete it;

    ret->put( i, element );

    return ret;
}


Collection* const SequenceableCollection::copyWithFirst(Object* const& element) const
{
    Iterator*                      it;
    SequenceableCollection* const  ret = __REINTERPRET_CAST(SequenceableCollection *, inner_of_size( size() + 1 ) );

    for ( int i  = 0, it = iterator(); it->finished(); it->next() ) {
        if ( i == 0 )
            ret->put( i ++, element );
        else
            ret->put( i ++, it->current() );
    }
    delete it;

    return ret;
}


bool SequenceableCollection::beginsWith(const SequenceableCollection* const& other) const
{
    Iterator*    self_it;
    Iterator*    other_it;
    int          i     = 0;

    if ( other == nil )
        nilArgumentWasPassed( "other" );

    for ( self_it = iterator(), other_it = other->iterator();
          self_it->finished() || other_it->finished();
          self_it->next(), other_it->next()
        ) {
        if ( !self_it->current()->equals( other_it->current() ) )
            break;

        ++ i;
    }
    delete self_it;
    delete other_it;

    return i == other->size();
}


bool SequenceableCollection::endsWith(const SequenceableCollection* const& other) const
{
    int len, other_len;
    int j, c;

    if ( other == nil )
        nilArgumentWasPassed( "other" );

    len       = size();
    other_len = other->size();

    if ( len < other_len )
        argumentBeyondRange( "other", other );

    c = 0;
    j = other_len - 1;
    for ( int i = len - 1; i >= 0; -- i ) {
        if ( !at( i )->equals( other->at( j -- ) ) )
            break;

        ++ c;
    }
    return c == other_len;
}
