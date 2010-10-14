#include <stdafx.h>

#include <stddef.h>

#include <canopus/String.hxx>
#include <canopus/ObjectAggregate.hxx>

#include <canopus/Object.hxx>

using namespace canopus;


Object::Object()
    : parent_(NULL), name_(NULL)
{
}
Object::Object(ObjectAggregate* const& parent)
    : parent_(parent), name_(NULL)
{
}
Object::Object(const Object& other)
    : parent_(other.parent_), name_(other.name_)
{
}
Object::Object(const String& name, ObjectAggregate* const& parent)
    : parent_(parent), name_(name)
{
}


Object::~Object()
{
    finalize();
}


String* const Object::toString() const
{
}


String* const Object::className() const
{
    return new String( "Object" );
}


const String* const Object::getName() const
{
    return name_;
}


void Object::setName(String* const& newname)
{
    name_->release();
    name_ = newname;
    name_->add_ref();
}


bool Object::equals(const Object* const& other) const
{
    return is_identity( other );
}
bool Object::equals(const Object& other) const
{
    return equals( &other );
}


bool Object::is_identity(const Object* const& other) const
{
    return this == other;
}
bool Object::is_identity(const Object& other) const
{
    return is_identity( &other );
}


int Object::hash() const
{
    return __STATIC_CAST( int, __REINTERPRET_CAST(void *, this) );
}


void Object::setParent(ObjectAggregate* const& newparent)
{
    if ( parent_ != NULL )
        unfastenParent();

    fastenParent( newparent );
}


void Object::finalize()
{
    if ( name_ != NULL )
        delete name_;

    parent_->removeChild( this );
}


Object* const Object::clone() const
{
    return new Object( this );
}


void Object::fastenParent(ObjectAggregate* const& newparent)
{
    parent_ = newparent;
}


void const Object::unfastenParent()
{
    if ( parent_ == NULL )
        return ;

    parent_->removeChild( this );
    parent_->release();
}
