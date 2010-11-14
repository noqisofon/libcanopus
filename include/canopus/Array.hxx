#ifndef canopus_Array_hxx
#define canopus_Array_hxx

#include <canopus/ArrayedCollection.hxx>


namespace canopus {


    class String;


    /**
     * 
     */
    class Array : public ArrayedCollection
    {
     public:
        typedef     ArrayedCollection       base;
        typedef     Array                   self;

     public:
        /**
         *
         */
        static Collection* ofSize(size_t size);


        /**
         *
         */
        static Collection* with(Object* const& _0);
        /**
         *
         */
        static Collection* with(Object* const& _0, Object* const& _1);
        /**
         *
         */
        static Collection* with(Object* const& _0, Object* const& _1, Object* const& _2);
        /**
         *
         */
        static Collection* with(Object* const& _0, Object* const& _1, Object* const& _2, Object* const& _3);

     public:
        /**
         * request_size 個の要素で配列を作成します。
         */
        explicit Array(size_t request_size);
        /**
         * 
         */
        Array(const Array& other);

     public:
        /**
         *
         */
        virtual String* const className() const;


        /**
         * 
         */
        virtual String* const toString() const;


        /**
         * other と全要素が一致すれば真を返します。
         */
        bool literalEqual(const Array* const& other) const;


        /**
         * レシーバを返します。
         */
        virtual Array* const asArray() const;


        /**
         * 全ての要素がリテラルなら真を返します。
         */
        bool isLiteral() const;


        /**
         * stream に #() 形式で要素を出力します。
         */
        virtual void printOn(Stream* const& stream) const;


        /**
         * stream に #() 形式で要素を詳しく出力します。
         */
        virtual void storeOn(Stream* const& stream) const;


        /**
         * stream にバイトを書き出します。
         */
        void byteEncode(Stream* const& stream) const;


        /**
         * index 番目の要素を返します。要素がない場合は absent を返します。
         */
        virtual Object* at(int index, Object* const& absent) const;


        /**
         * index をレシーバの要素数で割った剰り番目の要素を返します。
         */
        virtual Object* const atWrap(int index) const;


        /**
         * index をレシーバの要素数で割った剰り番目の要素を item と置き換えます。
         */
        virtual void putWrap(int index, Object* const& item);

     protected:
        /**
         * サイズ 0 の内部配列を作成します。
         */
        virtual void assign_empty();


        /**
         * 指定サイズで内部配列を作成し、全要素を value で埋めます。
         */
        virtual void assign(size_t request_size, Object* const& value);


        /**
         * コレクション collection で初期化した内部配列を作成します。
         */
        virtual void assign_from(const Collection* const& collection);


        /**
         * stream の内容で初期化した内部配列を作成します。
         */
        virtual void assign_from_stream(const Stream* const stream);


        /**
         * 内部配列を開放します。
         */
        virtual size_t terminate_inner_buffer();

     private:
        Object**    content_;
    };


}


#endif  /* canopus_Array_hxx */
