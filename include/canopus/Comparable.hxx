/**
 * @since 2010-10-14T23:44:09+0900
 */
#ifndef canopus_Comparable_hxx
#define canopus_Comparable_hxx


namespace canopus {


    class Object;


    /**
     * 共通したそのオブジェクト特有の比較メソッドを提供します。
     */
    class Comparable
    {
     public:
        /**
         * レシーバと other を比較して、大きいか小さいか、または同じかを表す整数値を返します。
         */
        virtual int compareTo(const Object& other) const = 0;
    };


}


#endif  /* canopus_Comparable_hxx */
