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
