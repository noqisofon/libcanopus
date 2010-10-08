#ifndef canopus_Array_hxx
#define canopus_Array_hxx

#include <canopus/ArrayedCollection.hxx>


namespace canopus {


    /**
     * 
     */
    class Array : public ArrayedCollection
    {
     public:
        /**
         *
         */
        static Collection* ofSize(size_t size);


        /**
         *
         */
        static Collection* with(Object* const& _0);
        /**
         *
         */
        static Collection* with(Object* const& _0, Object* const& _1);
        /**
         *
         */
        static Collection* with(Object* const& _0, Object* const& _1, Object* const& _2);
        /**
         *
         */
        static Collection* with(Object* const& _0, Object* const& _1, Object* const& _2, Object* const& _3);

     public:
        /**
         *
         */
        
    };


}


#endif  /* canopus_Array_hxx */
