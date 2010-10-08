#ifndef canopus_Stream_hxx
#define canopus_Stream_hxx

#include <canopus/Object.hxx>


namespace canopus {


    class Collection;
    class OrederedCollection;
    class String;


    /**
     * 
     */
    class Stream : public Object
    {
     public:
        /**
         * ストリームの内容を返します。
         */
        virtual Object* const contents() const = 0;


        /**
         * デフォルトでは何もしません。
         */
        virtual void flush() {}


        /**
         * "a stream" を返します。
         */
        virtual const String* localName() const;


        /**
         * 現在カーソルが指しているオブジェクトを返し、カーソルを進めます。
         */
        virtual Object* const next() const {
            return basicNext();
        }
        /**
         * 現在のカーソルから n 個のオブジェクトを OrderedCollection オブジェクトにして返し、n 個分カーソルを進めます。
         */
        virtual OrederedCollection* const next(int n) const = 0;


        /**
         * このストリームの内容が collection と一致するなら真を返します。
         */
        virtual bool nextMatchAll(const Collection* const& collection) const = 0;


        /**
         * that と次のカーソルの位置のオブジェクトが一致すれば真を返します。
         */
        virtual bool nextMatchFor(const Object* const& that) const = 0;


        /**
         * 次のカーソルの位置に element を書き込みます。
         */
        virtual void nextPut(Object* const& element) {
            basicNextPut( element );
        }


        /**
         * collection の全ての要素をストリームに書き出します。
         */
        virtual void nextPutAll(const Collection* const& collection);


     protected:
        /**
         * next() が呼び出します。
         */
        virtual Object* const basicNext() const = 0;


        /**
         * nextPut() が呼び出します。
         */
        virtual void basicNextPut(Object* const& replacement) = 0;
        /**
         * nextPut() が呼び出します。
         */
        virtual void basicNextPut(int n, Object* const& replacement) = 0;
    };


}


#endif  /* canopus_Stream_hxx */
