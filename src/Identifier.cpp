#include <stdafx.h>

#include <canopus/Identifier.hxx>
using namespace canopus;

int ObjectID   = 0;


Identifier::Identifier()
    : object_id_(ObjectID ++)
{
}
Identifier::Identifier(const Identifier& other)
    : object_id_(ObjectID ++)
{
}


int Identifier::object_id() const
{
    return __id__();
}


int Identifier::__id__() const
{
    return object_id_;
}
