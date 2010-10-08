#include <stdafx.h>

#include <canopus/SequenceableCollection.hxx>

using namespace canopus;


Object* const SequenceableCollection::after(const Object* const& that, Object* const& absent) const
{
    int index;

    if ( that == nil )
        RAISE_ARGUMENTS_ERROR( that );

    index = indexOf( that );
    if ( index == -1 )
        RAISE_NOT_FOUND_ERROR( that );

    if ( index + 1 >= size() - 1 )
        return absent;
    else
        return at( index + 1 );
}


Object* const SequenceableCollection::before(const Object* const& that, Object* const& absent) const
{
    int index;

    if ( that == nil )
        RAISE_ARGUMENTS_ERROR( that );

    index = indexOf( that );
    if ( index == -1 )
        RAISE_NOT_FOUND_ERROR( that );

    if ( index - 1 == 0 )
        return absent;
    else
        return at( index - 1 );
}


SequenceableCollection* const SequenceableCollection::allButFirst(int n) const
{
    SequenceableCollection* ret       = __REINTERPRET_CAST(SequenceableCollection *, copyEmpty( size() - (1 + n) ) );
    Iterator*               it;

    int                     skip      = 0;
    int                     i         = 0;

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
    SequenceableCollection* ret       = __REINTERPRET_CAST(SequenceableCollection *, copyEmpty( size() - (n + 1) ) );
    Iterator*               it;

    int                     i         = 0;
    int                     ret_size  = ret->size();

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
    int   index  = size() - index_from_end;
    
    if ( index < 0 )
        RAISE_INDEX_OUT_RANGE( index );

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
    SequenceableCollection* ret       = __REINTERPRET_CAST(SequenceableCollection *, index_array->copyEmpty() );
    int                     ret_index = 0;
    Iterator*               it;

    for ( it = index_array->iterator(); it->finished(); it->next() ) {
        if ( it->current() != nil && it->current()->is_Number() )
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
    int   index  = size() - index_from_end;
    
    if ( index < 0 )
        RAISE_INDEX_OUT_RANGE( index );

    put( index, replacement );
}


void SequenceableCollection::putRange(int start_index, int end_index, Object* const& replacement)
{
    size_t  len   = size();
    
    if ( (start_index < 0 || start_index >= len) && start_index >= end_index )
        RAISE_INDEX_OUT_RANGE( start_index );
    if ( (end_index < 0 || end_index >= len) && end_index <= start_index )
        RAISE_INDEX_OUT_RANGE( end_index );

    for ( int i = start_index; i <= end_index; ++ i ) {
        put( i, replacement );
    }
}


SequenceableCollection* const SequenceableCollection::first(int n) const
{
    if ( n >= size() )
        return nil;

    SequenceableCollection* ret = __REINTERPRET_CAST(SequenceableCollection *, copyEmpty( n ));
    Iterator*               it;
    int                     i = 0;

    for ( it = iterator(); it->finished(); it->next() ) {
        if ( i < n )
            ret->put( i, it->current() );
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
    int     len  = size();
    Object* that;

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
        RAISE_INDEX_OUT_RANGE( start );
    if ( (stop < 0 || stop >= len) && stop <= start )
        RAISE_INDEX_OUT_RANGE( stop );

    int rep_index  = 0;
    for ( int i = start_index; i < stop; ++ i, ++ rep_index ) {
        put( i, replacements->at( rep_start + rep_index ) );
    }
}


void SequenceableCollection::swap(int one_index, int another_index)
{
    int len  = size();
    
    if ( one_index == another_index )
        return ;
    if ( one_index < 0 || one_index >= len )
        RAISE_INDEX_OUT_RANGE( one_index );
    if ( another_index < 0 || another_index >= len )
        RAISE_INDEX_OUT_RANGE( another_index );

    Object*  tmp;

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
    if ( other == nil )
        return false;

    Iterator*   it;
    bool        ret = false;
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
    Array*    ret = new Array( size() );
    Iterator* it;

    int       i   = 0;

    for ( it = iterator(); it->finished(); it->next() ) {
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
    SequenceableCollection* const  ret = __REINTERPRET_CAST(SequenceableCollection *, inner_of_size( size() + 1 ) );
    Iterator*                      it;

    int i  = 0;
    ret->put( i ++, element );

    for ( it = iterator(); it->finished(); it->next() ) {
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
    if ( other == nil )
        RAISE_ARGUMENTS_EXCEPTION( other );
    int  len       = size();
    int  other_len = other->size();

    if ( len < other_len )
        RAISE_ARGUMENTS_EXCEPTION( other );

    int j = other_len - 1;
    int c = 0;
    for ( int i = len - 1; i >= 0; -- i ) {
        if ( !at( i )->equals( other->at( j -- ) ) )
            break;

        ++ c;
    }
    return c == other_len;
}
