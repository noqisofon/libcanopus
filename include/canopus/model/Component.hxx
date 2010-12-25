#ifndef canopus_Component_hxx
#define canopus_Component_hxx

#include <canopus/Object.hxx>


namespace canopus {


    class String;


    namespace model {


        class ObjectAggregate;


        /**
         * 
         */
        class Component : public Object
        {
            typedef     Object          base;
            typedef     Component       self;

         public:
            /**
             *
             */
            explicit Component(ObjectAggregate* const& parent);
            /**
             *
             */
            Component(const String& name, ObjectAggregate* const& parent);

         public:
            /**
             *
             */
            virtual const String* const getName() const;


            /**
             *
             */
            virtual void getName(const String& newname);


            /**
             *
             */
            virtual void setParent(ObjectAggregate* const& newparent);


            /**
             *
             */
            virtual ObjectAggregate* const& parent() const;


            /**
             *
             */
            virtual void fastenParent(ObjectAggregate* const& newparent);


            /**
             *
             */
            virtual void unfastenParent();

         private:
            Object* parent_;
            String* name_;
        };


    }


}


#endif  /* canopus_Component_hxx */
