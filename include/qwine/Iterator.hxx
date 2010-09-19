#ifndef qwine_Iterator_hxx
#define qwine_Iterator_hxx


namespace qwine {


    class Object;


    /**
     * 
     */
    class Iterator
    {
    public:
        /**
         * イテレータがコレクションの末尾にあるときに真を返します。
         */
        virtual bool finished() const = 0;


        /**
         * イテレータをコレクションの次の要素に移動させます。
         */
        virtual void next() = 0;


        /**
         * イテレータが指している要素を返します。
         */
        virtual Object* current() const = 0;
    };


}


#endif  /* qwine_Iterator_hxx */
