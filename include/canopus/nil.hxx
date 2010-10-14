#ifndef canopus_nil_hxx
#define canopus_nil_hxx


static const class
{
 public:
    /**
     * あらゆる型ポインタへの変換を行います。
     */
    template <class _Type> operator _Type* () const { return 0; }


    /**
     * あらゆる型のメンバポインタへの変換を行います。
     */
    template <class _Class, class _Type> operator _Type _Class::*() const { return 0; }

 private:
    void operator&  () const;
} nil;


#endif  /* canopus_nil_hxx */
