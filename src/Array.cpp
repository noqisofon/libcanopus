#include <stdafx.h>

#include <canopus/Collection.hxx>
#include <canopus/Stream.hxx>

#include <canopus/Array.hxx>
using namespace canopus;


Array* Array::ofSize(size_t size)
{
    if ( size == 0 )
        size   = 1;

    Array* ret   = new Array( size );

    for ( size_t i = 0; i < size; ++ i ) {
        ret->put( i, nil );
    }
    return ret;
}


Array* Array::with(Object* const& _0)
{
    Array*   ret   = new Array();

    ret->put( 0, _0 );

    return ret;
}
Array* Array::with(Object* const& _0, Object* const& _1)
{
    Array*   ret   = new Array( 2 );

    ret->put( 0, _0 );
    ret->put( 1, _1 );

    return ret;
}
Array* Array::with(Object* const& _0, Object* const& _1, Object* const& _2)
{
    Array*   ret   = new Array( 3 );

    ret->put( 0, _0 );
    ret->put( 1, _1 );
    ret->put( 2, _2 );

    return ret;
}
Array* Array::with(Object* const& _0, Object* const& _1, Object* const& _2, Object* const& _3)
{
    Array*   ret   = new Array( 4 );

    ret->put( 0, _0 );
    ret->put( 1, _1 );
    ret->put( 2, _2 );
    ret->put( 3, _3 );

    return ret;
}


Array::Array(size_t request_size)
     : base(request_size), capacity_(request_size), content_(NULL)
{
    
}
Array::Array(const Array& other)
{
}


String* const Array::className() const
{
    return new String( "Array" );
}


String* const Array::toString() const
{
}


bool Array::literalEqual(const Array* const& other) const
{
}


Array* const Array::asArray() const
{
    return this;
}


bool Array::isLiteral() const
{
}


void Array::printOn(Stream* const& stream) const
{
}


void Array::storeOn(Stream* const& stream) const
{
}


void Array::byteEncode(Stream* const& stream) const
{
}


Object* Array::at(int index, Object* const& absent) const
{
    if ( index < 0 || index >= tally_ )
        return absent;

    return content_[index];
}


Object* const Array::atWrap(int index) const
{
    return content_[index % tally_];
}


void Array::putWrap(int index, Object* const& item)
{
    content_[index % tally_]    = item;
}


void Array::assign_empty()
{
    assign( 32, nil );
}


void Array::assign(size_t request_size, Object* const& value)
{
    Object**         last;

    tally_      = request_size;
    content_    = new Object*[tally_];

    last        = content_ + tally_;

    for ( Object** it = content_; it != last; ++ it ) {
        *it = value;
    }
}


void Array::assign_from(const Collection* const& collection)
{
    Iterator*   it;
    Object**    p;

    if ( collect == NULL )
        return ;

    tally_      = collection->size();
    content_    = new Object*[tally_];

    for ( it = collection->iterator(), p = content_; it->finished(); it->next() ) {
        *p  = it->current();
    }
    delete [] it;
}


void Array::assign_from_stream(const Stream* const stream)
{
}
