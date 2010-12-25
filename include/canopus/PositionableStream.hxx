#ifndef canopus_PositionableStream_hxx
#define canopus_PositionableStream_hxx

#include <canopus/Stream.hxx>


namespace canopus {


    class Bitmap;
    class SequenceableCollection;


    /**
     * カーソルを持つストリームです。
     */
    class PositionableStream : public Stream
    {
        typedef     Stream                  base;
        typedef     PositionableStream      self;

     public:
        /**
         * 指定されたコレクションオブジェクトでストリームを作成します。
         */
        static PositionableStream* const on(SequenceableCollection* const& collection);
        /**
         * コレクションオブジェクトの first_index 番目から last_index 番目の要素でストリームを作成します。
         */
        static PositionableStream* const on(SequenceableCollection* const& collection, int first_index, int last_index);

     public:
        /**
         * 
         */
        virtual ~PositionableStream();

     protected:
        /**
         * 
         */
        PositionableStream();
        /**
         * 
         */
        PositionableStream(SequenceableCollection* const& collection);
        /**
         * 
         */
        PositionableStream(SequenceableCollection* const& collection, int first_index, int last_index);

     public:
        /**
         * 
         */
        virtual String* const className() const;


        /**
         * ストリームのカーソル位置を後ろに 1 つ戻します。
         */
        virtual void back();


        /**
         * ストリームの書き込み内容を返します。
         */
        virtual Object* const contents() const;


        /**
         * content メンバ関数と同じです。
         */
        virtual Object* const contentsOfEntireFile() const {
            return contents();
        }


        /**
         * レシーバの最後の要素を返します。
         */
        virtual Object* const last() const;


        /**
         * 次の n 個の要素をストリームから読み出します。
         */
        virtual SequenceableCollection* const next(int n) const {
            return base::next( n );
        }
        /**
         * 次の n 個の要素をストリームから読み出し、指定されたコレクションに書き出します。
         */
        virtual SequenceableCollection* const next(int n, SequenceableCollection* const collection) const;
        /**
         * 次の n 個の要素をストリームから読み出し、指定されたコレクションに start_index 番目から書き出します。
         */
        virtual SequenceableCollection* const next(int n, SequenceableCollection* const collection, int start_index) const;


        


        /**
         * 終端オブジェクト delimitor までストリームより読み出し、その内容を返します。
         */
        virtual SequenceableCollection* const nextDelimited(const Object* const& delimitor);


        /**
         * ストリームより 1 行読み取り、その内容を返します。現在のカーソルがストリーム終端の場合は nil を返します。
         */
        virtual SequenceableCollection* const nextLine();


        /**
         * ストリームの内容をワード長ベースのバッファ(Bitmap)に big エンディアンで格納します。
         */
        virtual void nextWordsInto(Bitmap* const& bitmap);


        /**
         * ストリームの(コピーでない)内容を返します。
         */
        virtual const SequenceableCollection* const originalContents() const;


        /**
         * カーソルが現在指している要素を読み取って返します。ただし、カーソルは変更しません。
         */
        virtual Object* const peek();


        /**
         * カーソルが現在指している要素より 1 つ前の要素を読み取って返します。ただし、カーソルは変更しません。
         */
        virtual Object* const peekBack();


        /**
         * ストリームの次の位置が that と一致すれば真を返します。
         */
        virtual bool peekFor(const Object* const& that);


        /**
         * ストリームから that が出現するまで読み取り、そこまでの内容を返します。
         */
        virtual SequenceableCollection* const upTo(const Object* const& that);


        /**
         * ストリームから指定されたコレクションと一致するまで読み取り、その内容を返します。
         */
        virtual SequenceableCollection* const upToAll(const Collection* const& collection);


        /**
         * ストリームから最後まで読み取り、その内容を返します。
         */
        virtual SequenceableCollection* const upToEnd();

     protected:
        /**
         * next() が呼び出します。
         */
        virtual Object* const basicNext() const;


        /**
         * nextPut() が呼び出します。
         */
        virtual void basicNextPut(Object* const& replacement);
        /**
         * nextPut() が呼び出します。
         */
        virtual void basicNextPut(int n, Object* const& replacement);

     protected:
        int                         position_;
        int                         read_limit_;
        int                         write_limit_;
        SequenceableCollection*     collection_;
    };


}


#endif  /* canopus_PositionableStream_hxx */
