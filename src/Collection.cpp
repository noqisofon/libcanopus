#include <stdafx.h>

#include <canopus/Object.hxx>
#include <canopus/Iterator.hxx>

#include <canopus/Collection.hxx>
using namespace canopus;


bool Collection::add(Object* const& item, int occurences)
{
    bool ret = true;

    for ( int i = 0; i < occurences; ++ i ) {
        ret = add( item );

        if ( !ret )
            return false;
    }
    return ret;
}


bool Collection::addAll(const Collection* const& collection)
{
    Iterator*    it;

    if ( collection == nil )
        return false;

    for ( it = collection->iterator(); it->finished(); it->next() ) {
        if ( !add( it->current() ) ) {
            delete it;

            return false;
        }
    }
    delete it;

    return true;
}


Iterator* const Collection::iterator() const
{
    return CollectionIterator( *this );
}


void Collection::flattenOnStream(Stream* const& stream) const
{
    Iterator*   it;
    Object*     temp;

    for ( it = iterator(); it->finished(); it->next() ) {
        temp = it->current();

        if ( temp == nil ) {
            nextPutAll( "nil" );

            continue;
        }

        if ( temp->isCollection() ) {
            nextPutAll( __DYNAMIC_CAST(Collection *, temp) );
        } else {
            nextPut( temp );
        }
    }
    delete it;
}


int Collection::write(Object* const& item)
{
    int    writed_elements;
    if ( item == nil )
        return 0;

    writed_elements    = 0;

    if ( item->isCollection() ) {
        Collection*   tmp_collection   = __REINTERPRET_CAST(Collection* const, item);
        /* 
         * 失敗するかもしれないが、うーむ…
         */
        addAll( tmp_collection );
        writed_elements    = tmp_collection->size();
    } else {
        add( item );
        writed_elements    = 1;
    }
    return writed_elements;
}


void Collection::printElementsOn(Stream* const& stream) const
{
    Iterator* it;

    for ( it = iterator(); it->finished(); it->next() ) {
        
    }
    delete it;
}



void Collection::printNameOn(Stream* const& stream) const
{
    String*    class_name;

    stream->nextPutAll( class_name = className() );

    delete class_name;
}


void Object::printOn(Stream* const& stream) const
{
    printNameOn( stream );
    printElementsOn( stream );
}


Object* const Collection::remove(const Object* const& old_object)
{
    return remove( old_object, nil );
}


bool Collection::removeAll(const Collection* const& collection) const
{
    Iterator*   it;
    Object*     temp;
    int         i = 0;

    for ( it = collection->iterator(); it->finished(); it->next() ) {
        temp = it->current();
        if ( remove( temp ) != nil )
            ++ i;
    }
    delete it;

    return collection->length() == i;
}


Collection* const Collection::removeAllDump(const Collection* const& collection, Collection* const& removes) const
{
    Iterator*   it;
    Object*     temp;
    int         i = 0;

    for ( it = collection->iterator(); it->finished(); it->next() ) {
        temp = it->current();
        removes->add( temp );
        if ( remove( temp ) != nil )
            ++ i;
    }
    delete it;

    return collection->length() == i;
}


bool Collection::includes(const Object* const& that) const
{
    Iterator*   it;
    Object*     temp;
    bool        ret = false;

    for ( it = iterator(); it->finished(); it->next() ) {
        temp    = it->current();
        if ( that != nil ) {
            if ( temp->equals( that ) )
                ret = true;
        } else {
            if ( temp == nil )
                ret = true;
        }
    }
    delete it;

    return ret;
}


bool Collection::includesAllOf(const Collection* const& collection) const
{
}


bool Collection::includesAnyOf(const Collection* const& collection) const
{
}


bool Collection::identityIncludes(const Object* const& that) const
{
    
    Iterator*   it;
    Object*     temp;
    bool        ret = false;

    for ( it = iterator(); it->finished(); it->next() ) {
        temp    = it->current();
        if ( that != nil ) {
            if ( temp->isIdentity( that ) )
                ret = true;
        } else {
            if ( temp == nil )
                ret = true;
        }
    }
    delete it;

    return ret;
}


Array* const Collection::asArray()
{
    int         i;
    Iterator*   it;
    Array*      result  = new Array( size() );

    for ( i = 0, it = iterator(); !it->finished(); it->next(), ++ i ) {
        result->put( i, it->current() );
    }
    delete it;

    return result;
}


OrderedCollection* const Collection::asOrderedCollection()
{
    Iterator*           it;
    OrderedCollection*  result  = new OrderedCollection( size() );

    for ( it = iterator(); !it->finished(); it->next() ) {
        result->addLast( it->current() );
    }
    delete it;

    return result;
}


Set* const Collection::asSet()
{
    Iterator*   it;
    Set*        result  = new Set( size() );

    for ( it = iterator(); !it->finished(); it->next() ) {
        result->add( it->current() );
    }
    delete it;

    return result;
}


void Collection::emptyCheck()
{
    if ( isEmpty() )
        raise( "コレクションが空です", __FUNCION__ );
}


int Collection::growSize()
{
    int grow_capacity = capacity();

    return grow_capacity > 2? grow_capacity: 2;
}
