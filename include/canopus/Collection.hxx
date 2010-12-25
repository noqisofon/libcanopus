#ifndef canopus_Collection_hxx
#define canopus_Collection_hxx

#include <canopus/Object.hxx>


namespace canopus {


    class Iterator;
    class Stream;
    class Array;
    class OrderedCollection;
    class Set;


    /**
     * コレクション階層の基底クラスです。
     */
    class Collection : public Object
    {
     public:
        /**
         * 先頭に格納されている要素を返します。
         */
        virtual const Object* const anyOne() const = 0;


        /**
         * 下記、size() と同じです。
         */
        virtual size_t capacity() const {
            return size();
        }


        /**
         * 格納されている要素の数を求めます。
         */
        virtual size_t size() const = 0;


        /**
         * 指定された要素をコレクションに追加します。
         */
        virtual bool add(Object* const& item) = 0;
        /**
         * 指定されたオブジェクトを occurences 回追加します。
         */
        virtual bool add(Object* const& item, int occurences);


        /**
         * 指定されたコレクションの要素を全てこのコレクションに追加します。
         */
        virtual bool addAll(const Collection* const& collection);


        /**
         * this を返します。
         */
        virtual const Collection* const contents() const {
            return this;
        }


        /**
         *
         */
        virtual Iterator* const iterator() const;


        /**
         * このコレクションの浅いコピーを作成して返します。
         */
        virtual Collection* const copy() const = 0;


        /**
         * このコレクションと同じサイズで空の新しいコレクションを作成して返します。
         */
        virtual Collection* const copyEmpty() const = 0;


        /**
         * 指定されたストリームにコレクションを書き出します。
         */
        virtual void flattenOnStream(Stream* const& stream) const;


        /**
         * 指定されたオブジェクトを追加します。
         */
        virtual int write(Object* const& item);


        /**
         * 要素を stream に列挙します。書式はスペース区切りで出力します。
         */
        virtual void printElementsOn(Stream* const& stream) const;


        /**
         * クラス名を stream に文字列で出力します。
         */
        virtual void printNameOn(Stream* const& stream) const;


        /**
         * クラス名と要素を stream に文字列で出力します。
         */
        virtual void printOn(Stream* const& stream) const;


        /**
         * 指定された要素を削除します。
         */
        virtual Object* const remove(const Object* const& old_object);
        /**
         * 指定された要素を削除します。存在しなかった場合は absent を返します。
         */
        virtual Object* const remove(const Object* const& old_object, Object* const absent) = 0;


        /**
         * 指定されたコレクションの要素と一致する要素を削除します。
         */
        virtual bool removeAll(const Collection* const& collection) const;


        /**
         * 指定されたコレクションの要素と一致する要素を削除します。削除した要素を removees に格納します。
         */
        virtual Collection* const removeAllDump(const Collection* const& collection, Collection* const& removees) const;


        /**
         * that が要素の一つである場合、真を返します。
         */
        virtual bool includes(const Object* const& that) const;


        /**
         * collection の全ての要素が含まれる場合、真を返します。
         */
        virtual bool includesAllOf(const Collection* const& collection) const;


        /**
         * collection の何れかの要素が含まれる場合、真を返します。
         */
        virtual bool includesAnyOf(const Collection* const& collection) const;


        /**
         * that が要素の一つと同一である場合、真を返します。
         */
        virtual bool identityIncludes(const Object* const& that) const;


        /**
         * Collection か、そのサブクラスなら真を返します。
         */
        virtual bool isCollection() const { return true; }


        /**
         * 格納している要素がない場合、真を返します。
         */
        virtual bool isEmpty() const { return size() == 0; }


        /**
         * Collection では isEmpty() と同じです。
         */
        virtual bool isEmptyOrNil() const { return isEmpty(); }


        /**
         * 順序集合である場合、真を返します。
         */
        virtual bool isSequenceable() const { return false; }


        /**
         * 格納している要素がある場合、真を返します。
         */
        virtual bool notEmpty() const { return !isEmpty(); }


        /**
         * このコレクションの要素で that と同じものの数を返します。
         */
        virtual int occrrencesOf(const Object* const& that) const;


        /**
         * Array に変換して返します。
         *      @return Array オブジェクト。
         */
        virtual Array* const asArray();


        /**
         * OrderedCollection に変換して返します。
         *      @return OrderedCollection オブジェクト。
         */
        virtual OrderedCollection* const asOrderedCollection();


        /**
         * Set に変換して返します。
         *      @return Set オブジェクト。
         */
        virtual Set* const asSet();

     protected:
        /**
         *
         */
        virtual Object* const nextForIterator(CollectionIterator* it) const = 0;


        /**
         * 空かどうか調べます。
         */
        virtual void emptyCheck();


        /**
         *
         */
        virtual int growSize();
    };


}


#endif  /* canopus_Collection_hxx */
