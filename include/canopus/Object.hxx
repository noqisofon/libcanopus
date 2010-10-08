#ifndef canopus_Object_hxx
#define canopus_Object_hxx


namespace canopus {


    class String;
    class ObjectAggregate;


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
        explicit Object(ObjectAggregate* const& parent);
        /**
         *
         */
        Object(const Object& other);
        /**
         *
         */
        Object(const String& name, ObjectAggregate* const& parent);


        /**
         *
         */
        virtual ~Object();

     public:
        /**
         *
         */
        virtual String* const toString() const;


        /**
         *
         */
        virtual String* const className() const;


        /**
         *
         */
        virtual const String* const getName() const;


        /**
         *
         */
        virtual void getName(const String& newname);


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
        virtual bool is_identity(const Object* const& other) const;


        /**
         *
         */
        virtual int hash() const;


        /**
         * レシーバが nil かどうか調べます。常に false を返します。
         */
        virtual bool is_nil() const { return false; }


        /**
         * Collection か、そのサブクラスなら真を返します。
         */
        virtual bool is_Collection() const { return false; }


        /**
         *
         */
        virtual void setParent(ObjectAggregate* const& newparent);


        /**
         *
         */
        virtual ObjectAggregate* const& parent() const;

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
        virtual void fastenParent(ObjectAggregate* const& newparent);


        /**
         *
         */
        virtual void unfastenParent();


        /**
         *
         */
        virtual void raise( const char* const&  message,
                            const char* const&  filename,
                            int                 line_number,
                            const char* const&  function_name
                            );

     private:
        Object* parent_;
        String* name_;
    };


}


#endif  /* canopus_Object_hxx */
