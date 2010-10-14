/**
 * @since 2010-10-14T23:21:46+0900
 */
#ifndef canopus_Disposeable_hxx
#define canopus_Disposeable_hxx


namespace canopus {


    /**
     * 割り当てられたリソースを開放するためのメソッドを提供します。
     */
    class Disposeable
    {
     public:
        /**
         * 割り当てられたリソースを開放します。
         */
        virtual void dispose() = 0;
    };


}


#endif  /* canopus_Disposeable_hxx */
