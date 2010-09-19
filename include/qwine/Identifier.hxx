#ifndef qwine_Identifier_hxx
#define qwine_Identifier_hxx


namespace qwine {


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
        int      id_;
    };
    

};



#endif  /* qwine_Identifier_hxx */
