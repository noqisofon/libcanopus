/**
 * @since 2010-10-15T00:47:50+0900
 */
#ifndef canopus_ObjectProtocol_hxx
#define canopus_ObjectProtocol_hxx


namespace canopus {


    class String;
    class Stream;


    /**
     * 
     */
    class ObjectProtocol {
     public:
        /**
         *
         */
        virtual bool equals(const ObjectProtocol* const& other) const = 0;
        /**
         *
         */
        virtual bool equals(const ObjectProtocol& other) const = 0;


        /**
         *
         */
        virtual bool is_identity(const ObjectProtocol* const& other) const = 0;
        /**
         *
         */
        virtual bool is_identity(const ObjectProtocol& other) const = 0;


        /**
         * レシーバのコピーを作成して返します。
         */
        virtual ObjectProtocol* const clone() const = 0;


        /**
         *
         */
        virtual int hash() const = 0;


        /**
         * レシーバが nil かどうか調べます。常に false を返します。
         */
        virtual bool is_nil() const = 0;


        /**
         * 指定されたストリームにこのオブジェクトを書き込みます。
         *      @param  stream 指定したストリーム。
         */
        virtual void printOn(Stream* const& stream) const = 0;


        /**
         * このオブジェクトの文字列表現を返します。
         *      @return このオブジェクトの文字列表現。
         */
        virtual String* const printString() const = 0;


        /**
         *
         */
        virtual String* const toString() const  = 0;


        /**
         * レシーバのクラス名を返します。
         */
        virtual String* const className() const = 0;


        /**
         * このオブジェクトが Association のインスタンスかどうか判別します。
         *      @return Association のインスタンスなら真。
         */
        virtual bool is_Association() const = 0;


        /**
         * このオブジェクトが Boolean のインスタンスかどうか判別します。
         *      @return Boolean のインスタンスなら真。
         */
        virtual bool is_Boolean() const = 0;


        /**
         * このオブジェクトが Character のインスタンスかどうか判別します。
         *      @return Character のインスタンスなら真。
         */
        virtual bool is_Character() const = 0;


        /**
         * このオブジェクトが Number のインスタンスかどうか判別します。
         *      @return Number のインスタンスなら真。
         */
        virtual bool is_Number() const = 0;


        /**
         * このオブジェクトが String のインスタンスかどうか判別します。
         *      @return String のインスタンスなら真。
         */
        virtual bool is_String() const = 0;


        /**
         * 
         */
        virtual bool is_Stream() const = 0;

     protected:
        /**
         *
         */
        virtual void finalize() = 0;


        /**
         *
         */
        virtual void raise(const String* const& message) = 0;
        /**
         *
         */
        virtual void raise( const String* const&    message,
                            const String* const&    selector
                            ) = 0;
        /**
         *
         */
        virtual void raise( const String* const&    message,
                            const String* const&    selector,
                            Object* const&          parameter
                            ) = 0;
        /**
         *
         */
        virtual void raise(const _TCHAR* const& message) = 0;
        /**
         *
         */
        virtual void raise( const _TCHAR* const&    message,
                            const _TCHAR* const&    selector
                            ) = 0;
        /**
         *
         */
        virtual void raise( const _TCHAR* const&    message,
                            const _TCHAR* const&    selector,
                            Object* const&          parameter
                            ) = 0;


        /**
         * 実装していない関数で呼び出されます。
         */
        virtual void shouldNotImplement(const char* const& selector) const = 0;
        /**
         * 実装していない関数で呼び出されます。
         */
        virtual void shouldNotImplement(String* const& selector) const = 0;
    };


}


#endif  /* canopus_ObjectProtocol_hxx */
