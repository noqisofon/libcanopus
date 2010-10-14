#ifndef canopus_Releaseable_hxx
#define canopus_Releaseable_hxx


namespace canopus {


    /**
     * 
     */
    class Releaseable
    {
     public:
        /**
         *
         */
        virtual unsigned int ref_count() const = 0;


        /**
         *
         */
        virtual void add_ref() = 0;


        /**
         *
         */
        virtual void release() = 0;
    };


}


#endif  /* canopus_Releaseable_hxx */
