#include <stdafx.h>

#include <canopus/Collection.hxx>
#include <canopus/Stream.hxx>

#include <canopus/Array.hxx>
using namespace canopus;


Collection* Array::ofSize(size_t size)
{
    if ( size == 0 )
        size   = 1;
    
    Collection* ret   = new Array( size );

    for ( size_t i = 0; i < size; ++ i ) {
        ret->put( i, nil );
    }
    return ret;
}


Collection* Array::with(Object* const& _0)
{
    Collection*   ret   = new Array();

    ret->put( 0, _0 );

    return ret;
}
Collection* Array::with(Object* const& _0, Object* const& _1)
{
    Collection*   ret   = new Array( 2 );

    ret->put( 0, _0 );
    ret->put( 1, _1 );

    return ret;
}
Collection* Array::with(Object* const& _0, Object* const& _1, Object* const& _2)
{
    Collection*   ret   = new Array( 3 );

    ret->put( 0, _0 );
    ret->put( 1, _1 );
    ret->put( 2, _2 );

    return ret;
}
Collection* Array::with(Object* const& _0, Object* const& _1, Object* const& _2, Object* const& _3)
{
    Collection*   ret   = new Array( 4 );

    ret->put( 0, _0 );
    ret->put( 1, _1 );
    ret->put( 2, _2 );
    ret->put( 3, _3 );

    return ret;
}
