


PositionableStream* const PositionableStream::on(SequenceableCollection* const& collection)
{
    return on( collection, 0, collection->size() );
}
PositionableStream* const PositionableStream::on(SequenceableCollection* const& collection, int first_index, int last_index)
{
}


PositionableStream::PositionableStream()
     : position_(0),
       read_limit_(0),
       write_limit_(0),
       collection_(nil)
{
}
PositionableStream::PositionableStream(SequenceableCollection* const& collection)
     : position_(0),
       read_limit_( collection->size() ),
       write_limit_( collection->size() ),
       collection_(collection)
{
}
PositionableStream::PositionableStream(SequenceableCollection* const& collection, int first_index, int last_index)
     : position_(0),
       read_limit_( collection->size() ),
       write_limit_( collection->size() ),
       collection_(collection)
{
}


String* const PositionableStream::className() const
{
    return new String( "PositionableStream" );
}


void PositionableStream::back()
{
    if ( position_ > 0 )
        -- position_;
}


Object* const PositionableStream::contents() const
{
    return __DYNAMIC_CAST(SequenceableCollection *, collection_->copy( 0, read_limit_ - 1 ) );
}


Object* const PositionableStream::last() const
{
    return collection_->last();
}


void PositionableStream::nextPutAll(const SequenceableCollection* const& collection)
{
}
void PositionableStream::nextPutAll(const SequenceableCollection* const& collection, int start_index)