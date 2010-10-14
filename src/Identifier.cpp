#include <stdafx.h>

#include <canopus/Identifier.hxx>
using namespace canopus;

int ObjectID   = 0;


/**
 * 指定された引数のアドレスを T 型の値に変換して返します。
 *      @param u [in] 指定した変数。
 *
 *      @return 指定された引数のアドレスを T 型の値に変換した値。
 */
template <class _Type1, class _Type2> inline
typename _Type1 get_address(typename _Type2& u) { return *__REINTERPRET_CAST(typename _Type1 *, &u); }


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
    return get_address<int>( this );
}


bool Identifier::is_identity(const Identifier* const& other) const
{
    if ( !other )
        return false;

    return object_id() == other->object_id();
}
