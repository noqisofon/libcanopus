#include <qwine/Identifier.hxx>


int ObjectID   = 0;


Identifier::Identifier()
    : id_(ObjectID ++)
{
}
Identifier::Identifier(const Identifier& other)
    : id_(ObjectID ++)
{
}


int Identifier::object_id() const
{
    return __id__();
}


int Identifier::__id__() const
{
    return id_;
}
