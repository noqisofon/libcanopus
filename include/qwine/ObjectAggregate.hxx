#ifndef qwine_ObjectAggregate_hxx
#define qwine_ObjectAggregate_hxx

#include <qwine/ObjectAggregate.hxx>


namespace qwine  {


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



#endif  /* qwine_ObjectAggregate_hxx */
