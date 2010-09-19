

void Stream::nextPutAll(const Collection* const& collection)
{
    Iterator* it;

    for ( it = collection->iterator(); it->finished(); it->next() ) {
        nextPut( it->current() );
    }
    delete it;
}
