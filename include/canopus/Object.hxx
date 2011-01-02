#ifndef canopus_Object_hxx
#define canopus_Object_hxx


namespace canopus {


    class String;
    class Stream;


    /**
     * 全てのクラスの基底クラスです。
     */
    class Object
    {
     public:
        /**
         *
         */
        Object();
        /**
         *
         */
        Object(const Object& other);


        /**
         *
         */
        virtual ~Object();

     public:
        /**
         *
         */
        virtual String* const className() const;


        /**
         *
         */
        virtual bool equals(const Object* const& other) const;
        /**
         *
         */
        virtual bool equals(const Object& other) const;


        /**
         *
         */
        virtual bool isIdentity(const Object* const& other) const;
        /**
         *
         */
        virtual bool isIdentity(const Object& other) const;
     
     
        /**
         * 指定されたストリームにこのオブジェクトを書き込みます。
         *      @param  __stream 指定したストリーム。
         */
        virtual void printOn(Stream* const& stream) const;


        /**
         * このオブジェクトの文字列表現を返します。
         *      @return このオブジェクトの文字列表現。
         */
        virtual String* const printString() const;


        /**
         *
         */
        virtual int hash() const;


        /**
         * レシーバが nil かどうか調べます。常に false を返します。
         */
        virtual bool isNil() const { return false; }


        /**
         * Collection か、そのサブクラスなら真を返します。
         */
        virtual bool isCollection() const { return false; }


        /**
         * このオブジェクトが Association のインスタンスかどうか判別します。
         *      @return Association のインスタンスなら真。
         */
        virtual bool isAssociation() const { return false; }


        /**
         * このオブジェクトが Boolean のインスタンスかどうか判別します。
         *      @return Boolean のインスタンスなら真。
         */
        virtual bool isBoolean() const { return false; }


        /**
         * このオブジェクトが Character のインスタンスかどうか判別します。
         *      @return Character のインスタンスなら真。
         */
        virtual bool isCharacter() const { return false; }


        /**
         * このオブジェクトが Number のインスタンスかどうか判別します。
         *      @return Number のインスタンスなら真。
         */
        virtual bool isNumber() const { return false; }


        /**
         * このオブジェクトが String のインスタンスかどうか判別します。
         *      @return String のインスタンスなら真。
         */
        virtual bool isString() const { return false; }


        /**
         * 
         */
        virtual bool isStream() const { return false; }


        /**
         * リテラルのラッパーなら真を返します。
         */
        virtual bool isLiteral() const { return false; }

     protected:
        /**
         *
         */
        virtual void finalize();


        /**
         *
         */
        virtual Object* const clone() const;


        /**
         *
         */
        virtual void raise( const char* const&  message,
                            const char* const&  selector,
                            Object* const&      parameter
                            );
        /**
         *
         */
        virtual void raise( const String* const&  message,
                            const String* const&  selector,
                            Object* const&      parameter
                            );
    };


}


#endif  /* canopus_Object_hxx */
