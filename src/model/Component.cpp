


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





void Object::setParent(ObjectAggregate* const& newparent)
{
    if ( parent_ != NULL )
        unfastenParent();

    fastenParent( newparent );
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
