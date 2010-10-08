#ifndef canopus_ObjectAggregate_hxx
#define canopus_ObjectAggregate_hxx

#include <canopus/Object.hxx>


namespace canopus  {


    class String;


    /**
     * オブジェクトの集合を表します。
     */
    class ObjectAggregate : public Object
    {
     public:
        /**
         *
         */
        ObjectAggregate();
        /**
         *
         */
        ObjectAggregate(String* const& name);
        /**
         *
         */
        ObjectAggregate(String* const& name, ObjectAggregate* const& parent);


        /**
         *
         */
        virtual ~ObjectAggregate();

     public:
        /**
         *
         */
        virtual String* const toString() const;


        /**
         *
         */
        virtual String* const className() const;
    };


}


#endif  /* canopus_ObjectAggregate_hxx */
