/**
 * @since 2010-10-15T00:48:02+0900
 */
#ifndef canopus_Cloneable_hxx
#define canopus_Cloneable_hxx


namespace canopus {


    /**
     * 2 つのインスタンスが等しいかどうかを判別するための手法を提供します。
     */
    class Cloneable
    {
     public:
        /**
         * レシーバのコピーを作成して返します。
         */
        virtual Cloneable* const clone() const = 0;
    };


}


#endif  /* canopus_Cloneable_hxx */
