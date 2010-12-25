#include <stdafx.h>

#include <stddef.h>

#include <canopus/String.hxx>
#include <canopus/ObjectAggregate.hxx>

#include <canopus/Object.hxx>

using namespace canopus;


Object::Object()
{
}
Object::Object(const Object& other)
{
}


Object::~Object()
{
    finalize();
}


String* const Object::className() const
{
    return new String( "Object" );
}


bool Object::equals(const Object* const& other) const
{
    return isIdentity( other );
}
bool Object::equals(const Object& other) const
{
    return equals( &other );
}


bool Object::isIdentity(const Object* const& other) const
{
    return this == other;
}
bool Object::isIdentity(const Object& other) const
{
    return isIdentity( &other );
}


void Object::printOn(Stream* const& stream) const
{
    String*  title   = className();

    if ( __DYNAMIC_CAST( Character *, title->first() )->is_vowel() )
        stream->nextPutAll( "an " );
    else
        stream->nextPutAll( "a " );

    stream->nextPutAll( title );
}


String* const Object::printString() const
{
    WriteStream    stream( new String( 16 ) );
    printOn( stream );

    return __DYNAMIC_CAST( String *, stream.contents() );
}


int Object::hash() const
{
    return __STATIC_CAST(int, __REINTERPRET_CAST(void *, this));
}


void Object::finalize()
{
    if ( name_ != NULL )
        delete name_;

    parent_->removeChild( this );
}


Object* const Object::clone() const
{
    return new Object( *this );
}
