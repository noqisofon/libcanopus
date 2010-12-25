#ifndef canopus_OrderedCollection_hxx
#define canopus_OrderedCollection_hxx

#include <canopus/SequenceableCollection.hxx>


namespace canopus {


    /**
     * 長さが可変なコレクションです。
     */
    class OrderedCollection : public SequenceableCollection {
        typedef     SequenceableCollection      base;
        typedef     OrderedCollection           self;

     public:
        /**
         *
         */
        virtual String* const className() const;


        /**
         * 
         */
        virtual size_t capacity() const {
            return last_index_ - first_index_ + 1;
        }


        /**
         * 格納されている要素の数を求めます。
         */
        virtual size_t size() const {
            return content_->size();
        }


        /**
         * 指定された要素をコレクションに追加します。
         */
        virtual bool add(Object* const& item);


        /**
         *
         */
        virtual Iterator* const iterator() const;


        /**
         * このコレクションの浅いコピーを作成して返します。
         */
        virtual Collection* const copy() const;


        /**
         * このコレクションと同じサイズで空の新しいコレクションを作成して返します。
         */
        virtual Collection* const copyEmpty() const;


        /**
         * 指定された要素を削除します。存在しなかった場合は absent を返します。
         */
        virtual Object* const remove(const Object* const& old_object, Object* const absent);


        /**
         * index 番目の要素を返します。要素がない場合は absent を返します。
         */
        virtual Object* at(int index, Object* const& absent) const;


        /**
         * index 番目の要素を replacement で置き換えます。
         */
        virtual void put(int index, Object* const& replacement);


        /**
         * このコレクションに element と同一の要素が含まれていればそのインデック
         * スを返します。なければ absent を返します。
         */
        virtual int identityIndexOf(const Object* const& element, int absent) const;


        /**
         * このコレクションに element と同値の要素があれば、(最小の)インデックス
         * を返します。探索開始を start_index からとします。
         */
        virtual int indexOf(const Object* const& element, int start_index, int absent) const;


        /**
         * 探索開始位置を start_index 番目からとして、sub_collection の要素と同
         * 値となるインデックスを返します。無い場合は absent を返します。
         */
        virtual int indexOfSubCollection(const SequenceableCollection* const& sub_collection, int start_index, int absent) const;


        /**
         * このコレクションに that と同値の要素があれば、その(最大の)インデックス
         * を返します。要素の探索範囲を start_index からとし、無い場合は absent を返します。
         */
        virtual int lastIndexOf(const Object* const& that, int start_index, int absent) const;


        /**
         * このコレクションと指定されたコレクションを連結した新しいコレクションを返します。
         */
        virtual SequenceableCollection* const concat(const SequenceableCollection* const& concatee) const;


        /**
         * このコレクションの浅いコピーを返します。
         */
        virtual SequenceableCollection* shallowCopy() const;

     protected:
        /**
         * 
         */
        virtual Object* const nextForIterator(CollectionIterator* const& it) const;


        /**
         * 
         */
        virtual void changeCapacity(int new_capacity);

     private:
        SequenceableCollection*     content_;
        int                         first_index_;
        int                         last_index_;
    };


}


#endif  /* canopus_OrderedCollection_hxx */
