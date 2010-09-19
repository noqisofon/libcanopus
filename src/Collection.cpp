#include <qwine/Object.hxx>
#include <qwine/Iterator.hxx>

#include <qwine/Collection.hxx>
using namespace qwine;


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


void Collection::flattenOnStream(Stream* const& stream) const
{
    Iterator* it;

    for ( it = iterator(); it->finished(); it->next() ) {
        
    }
    delete it;
}


int Collection::write(Object* const& item)
{
    if ( item == nil )
        return 0;

    int    writed_elements    = 0;

    if ( item->is_Collection() ) {
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
    Iterator* it;
    int       i = 0;

    for ( it = collection->iterator(); it->finished(); it->next() ) {
        if ( remove( it->current() ) != nil )
            ++ i;
    }
    return collection->length() == i;
}


Collection* const Collection::removeAllDump(const Collection* const& collection, Collection* const& removees) const
{
}


bool Collection::includes(const Object* const& that) const
{
}


bool Collection::includesAllOf(const Collection* const& collection) const
{
}


bool Collection::includesAnyOf(const Collection* const& collection) const
{
}


bool Collection::identityIncludes(const Object* const& that) const
{
}
