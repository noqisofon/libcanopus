/**
 * @since 2010-10-14T23:23:54+0900
 */
#ifndef canopus_Equalable_hxx
#define canopus_Equalable_hxx


namespace canopus {


    class Object;


    /**
     * 2 つのインスタンスが等しいかどうかを判別するための手法を提供します。
     */
    class Equalable
    {
     public:
        /**
         * レシーバが other と同値かどうかを判別します。
         */
        virtual bool equals(const Object& other) const = 0;
        /**
         * レシーバが other と同値かどうかを判別します。
         */
        virtual bool equals(const Object* const& other) const = 0;
    };


}


#endif  /* canopus_Equalable_hxx */
