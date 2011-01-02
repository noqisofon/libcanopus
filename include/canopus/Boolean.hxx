#ifndef canopus_Boolean_hxx
#define canopus_Boolean_hxx

#include <canopus/Object.hxx>


namespace canopus {


    /**
     * 真偽値を表します。
     */
    class Boolean : public Object {
        typedef       Object        base;
        typedef       Boolean       self;

     public:
        /**
         * 
         */
        explicit Boolean(bool b = false);
        /**
         * 
         */
        Boolean(const Boolean& other);


        /**
         * 
         */
        virtual ~Boolean();

     public:

     private:
        bool content_;
    };


}


#endif  /* canopus_Boolean_hxx */
