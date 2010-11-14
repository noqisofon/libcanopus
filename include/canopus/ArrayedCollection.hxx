/**
 * @since 2010-10-07T00:23:30+0900
 */
#ifndef canopus_ArrayedCollection_hxx
#define canopus_ArrayedCollection_hxx

#include <canopus/SequenceableCollection.hxx>


namespace canopus {


    /**
     * 配列の抽象クラスです。
     */
    class ArrayedCollection : public SequenceableCollection
    {
     public:
        /**
         * サイズ 0 のインスタンスを作成します。
         */
        ArrayedCollection();
        /**
         * 指定されたサイズでインスタンスを作成し、全要素を value で埋めます。
         */
        ArrayedCollection(size_t size, Object* const& value);
        /**
         * 
         */
        ArrayedCollection(const Collection* const& collection);
        /**
         * 
         */
        ArrayedCollection(Stream* const& stream);


        /**
         * 
         */
        virtual ~ArrayedCollection();

     public:
        /**
         * 要素数を返します。
         */
        virtual size_t size() const { return tally_; }


        /**
         *
         */
        virtual bool add(Object* const& item) = 0;


        /**
         * stream に要素を文字列で列挙します。
         */
        virtual void storeOn(Stream* const& stream);


        /**
         * レシーバのバイトサイズを返します。
         */
        virtual size_t byteSize() const { return tally_ * bytesPerBasicElement(); }


        /**
         * 1 つの要素を格納するために必要なバイト数を返します。
         */
        virtual int bytesPerBasicElement() const { return sizeof(intptr_t); }


        /**
         * 1 つの要素を格納するために必要なバイト数を返します。
         */
        virtual int bytesPerElement() const { return bytesPerBasicElement(); }


        /**
         * リトルエンディアンシステムの場合、ストリームから読み取ったバイトをビッグエンディアンに戻します。
         */
        virtual void restoreEndianness() = 0;


        /**
         * stream にレシーバの内容をバイナリで書き出します。
         */
        virtual void writeOn(Stream* const& stream) const;

     protected:
        /**
         * サイズ 0 の内部配列を作成します。
         */
        virtual void assign_empty() = 0;


        /**
         * 指定サイズで内部配列を作成し、全要素を value で埋めます。
         */
        virtual void assign(size_t request_size, Object* const& value) = 0;


        /**
         * コレクション collection で初期化した内部配列を作成します。
         */
        virtual void assign_from(const Collection* const& collection) = 0;


        /**
         * stream の内容で初期化した内部配列を作成します。
         */
        virtual void assign_from_stream(const Stream* const stream) = 0;


        /**
         * 内部配列を開放します。
         */
        virtual size_t terminate_inner_buffer() = 0;

     protected:
        size_t      tally_;
    };


}


#endif  /* canopus_ArrayedCollection_hxx */
