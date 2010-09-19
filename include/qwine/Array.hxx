#ifndef qwine_Array_hxx
#define qwine_Array_hxx

#include <qwine/ArrayedCollection/hxx>


namespace qwine {


    /**
     * 
     */
    class Array : public ArrayedCollection
    {
    public:
        /**
         * 
         */
        Collection* Array::ofSize(size_t size);
        
    };


}


#endif  /* qwine_Array_hxx */
