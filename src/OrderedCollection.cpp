#include <stdafx.h>

#include <canopus/OrderedCollection.h>
using namespace canopus;

String* const OrderedCollection::className() const
{
    return new String( "OrderedCollection" );
}


bool OrderedCollection::add(Object* const& item)
{
    return addLast( item );
}


Iterator* const OrderedCollection::iterator() const
{
}


Collection* const OrderedCollection::copy() const
{
    return new OrderedCollection( *this );
}


Collection* const OrderedCollection::copyEmpty() const
{
    return new OrderedCollection();
}


Object* const OrderedCollection::remove(const Object* const& old_item, Object* const absent)
{
    int         stop    = last_index_;
    Object*     temp;

    for ( int i = first_index_; i <= stop; ++ i ) {
        temp    = content_->at( i );
        if ( temp->equals( old_item ) ) {
            removeIndex( i );

            return temp;
        }
    }
    return absent;
}


Object* OrderedCollection::at(int index, Object* const& absent) const
{
    return content_->at( index, absent );
}


void OrderedCollection::put(int index, Object* const& replacement)
{
    return content_->put( index, replacement );
}


int OrderedCollection::identityIndexOf(const Object* const& element, int absent) const
{
    Iterator*   it;
    Object*     tmp;

    if ( element == nil ) {
        for ( int i = 0, it = iterator(); it->finished(); ++ i, it->next() ) {
            if ( i < start_index )
                continue;

            if ( it->current() == nil )
                return i;
        }
    } else {
        for ( int i = 0, it = iterator(); it->finished(); ++ i, it->next() ) {
            if ( i < start_index )
                continue;

            tmp = it->current();
            if ( tmp != nil || tmp->isIdentity( element ) )
                return i;
        }
    }
    return absent;
}


int OrderedCollection::indexOf(const Object* const& element, int start_index, int absent) const
{
    Iterator*   it;
    Object*     tmp;

    if ( element == nil ) {
        for ( int i = 0, it = iterator(); it->finished(); ++ i, it->next() ) {
            if ( i < start_index )
                continue;

            if ( it->current() == nil )
                return i;
        }
    } else {
        for ( int i = 0, it = iterator(); it->finished(); ++ i, it->next() ) {
            if ( i < start_index )
                continue;

            tmp = it->current();
            if ( tmp != nil || tmp->equals( element ) )
                return i;
        }
    }
    return absent;
}


int OrderedCollection::indexOfSubCollection(const SequenceableCollection* const& sub_collection, int start_index, int absent) const
{
}


int OrderedCollection::lastIndexOf(const Object* const& that, int start_index, int absent) const
{
    
    Iterator*   it;
    Object*     tmp;
    int         found = -1;

    if ( element == nil ) {
        for ( int i = 0, it = iterator(); it->finished(); ++ i, it->next() ) {
            if ( i < start_index )
                continue;

            if ( it->current() == nil )
                found = i;
        }
    } else {
        for ( int i = 0, it = iterator(); it->finished(); ++ i, it->next() ) {
            if ( i < start_index )
                continue;

            tmp = it->current();
            if ( tmp != nil || tmp->equals( element ) )
                found = i;
        }
    }

    return found != -1? found: absent;
}


SequenceableCollection* const OrderedCollection::concat(const SequenceableCollection* const& concatee) const
{
}


SequenceableCollection* OrderedCollection::shallowCopy() const
{
}
