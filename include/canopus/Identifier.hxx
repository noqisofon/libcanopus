#ifndef canopus_Identifier_hxx
#define canopus_Identifier_hxx


namespace canopus {


    /**
     * 
     */
    class Identifier
    {
     public:
        /**
         *
         */
        Identifier();
        /**
         *
         */
        Identifier(const Identifier& other);


        /**
         *
         */
        virtual ~Identifier();

     public:
        /**
         *
         */
        virtual int object_id() const;


        /**
         *
         */
        virtual bool is_identity(const Identifier* const& other) const;
        /**
         *
         */
        virtual bool is_identity(const Identifier& other) const {
            return is_identity( &other );
        }

     private:
        /**
         *
         */
        int __id__() const;

     private:
        int      object_id_;
    };
    

};


#endif  /* canopus_Identifier_hxx */
