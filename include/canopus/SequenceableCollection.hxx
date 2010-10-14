#ifndef canopus_SequenceableCollection_hxx
#define canopus_SequenceableCollection_hxx

#include <canopus/Collection.hxx>


namespace canopus {


    class Array;
    class String;
    class WriteStream;
    class ReadStream;


    /**
     * 
     */
    class SequenceableCollection : public Collection
    {
     public:
        /**
         * 指定されたオブジェクトの後の要素を返します。
         */
        virtual Object* after(const Object* const& that) const {
            return after( that, nil );
        }
        /**
         * 指定されたオブジェクトの後の要素を返します。末尾の要素だった場合など、
         * 後ろの要素がない場合、absent を返します。
         */
        virtual Object* after(const Object* const& that, Object* const& absent) const;


        /**
         * that 直前の要素を返します。
         */
        virtual Object* before(const Object* const& that) const {
            return before( that, nil );
        }
        /**
         * that 直前の要素を返します。無ければ absent を返します。
         */
        virtual Object* before(const Object* const& that, Object* const& absent) const;


        /**
         * 最初の要素を除外したサブコレクションをコピーして返します。
         */
        virtual SequenceableCollection* const allButFirst() const {
            return allButFirst( 0 );
        }

        /**
         * 0..n までの要素を除外したサブコレクションをコピーして返します。
         */
        virtual SequenceableCollection* const allButFirst(int n) const;


        /**
         * 最後の要素を除外したサブコレクションをコピーして返します。
         */
        virtual SequenceableCollection* const allButLast() const {
            return allButlast( 0 );
        }
        /**
         * n..size-1 までの要素を除外したサブコレクションをコピーして返します。
         */
        virtual SequenceableCollection* const allButLast(int n) const;


        /**
         * 最初の要素を返します。
         */
        virtual Object* anyOne() const;


        /**
         * index 番目の要素を返します。
         */
        virtual Object* at(int index) const {
            return at( index, nil );
        }
        /**
         * index 番目の要素を返します。要素がない場合は absent を返します。
         */
        virtual Object* at(int index, Object* const& absent) const = 0;


        /**
         * 最後の要素から index_from_end 番目の要素を返します。
         */
        virtual Object* atLast(int index_from_end) const;
        /**
         * 最後の要素から index_from_end 番目の要素を返します。index_from_end が
         * 現在の要素数より大きい場合は absent を返します。
         */
        virtual Object* atLast(int index_from_end, Object* const& absent) const;


        /**
         * index 番目の要素を返します。index が要素数より大きい場合は 最後の要素、
         * 1 より小さい場合は最初の要素を返します。
         */
        virtual Object* atPin(int index) const;


        /**
         * index 番目の要素を返します。 index が要素範囲を超えるときは
         * wrap around されます。
         */
        virtual Object* atWrap(int index) const {
            return at( index % size() );
        }


        /**
         * index_array の要素の値をインデックスとみなし、レシーバからそのインデックス番目の要素を返します。
         */
        virtual SequenceableCollection* const atAll(const SequenceableCollection* const& index_array) const;


        /**
         * 全要素を that に置き換えます。
         */
        virtual void atAllPut(Object* const& that);


        /**
         * index 番目の要素を replacement で置き換えます。
         */
        virtual void put(int index, Object* const& replacement) = 0;


        /**
         * 最後の要素から index_from_end 番目の要素を replacement で置き換えます。
         */
        virtual void putLast(int index_from_end, Object* const& replacement);


        /**
         * index 番目の要素を replacement で置き換えます。index が要素範囲を超え
         * るときは wrap around されます。
         */
        virtual void putWrap(int index, Object* const& replacement) {
            put( index % size(), replacement );
        }


        /**
         * start_index から end_index 番目までの要素を replacement で置き換えます。
         */
        virtual void putRange(int start_index, int end_index, Object* const& replacement);


        /**
         * このコレクションに element と同一の要素が含まれていればそのインデック
         * スを返します。なければ -1 を返します。
         */
        virtual int identityIndexOf(const Object* const& element) const {
            return identityIndexOf( element, -1 );
        }
        /**
         * このコレクションに element と同一の要素が含まれていればそのインデック
         * スを返します。なければ absent を返します。
         */
        virtual int identityIndexOf(const Object* const& element, int absent) const = 0;


        /**
         * このコレクションに element と同値の要素があれば、(最小の)インデックス
         * を返します。
         */
        virtual int indexOf(const Object* const& element) const {
            return indexOf( element, 0, -1 );
        }
        /**
         * このコレクションに element と同値の要素があれば、(最小の)インデックス
         * を返します。
         */
        virtual int indexOf(const Object* const& element, int absent) const {
            return indexOf( element, 0, absent );
        }
        /**
         * このコレクションに element と同値の要素があれば、(最小の)インデックス
         * を返します。探索開始を start_index からとします。
         */
        virtual int indexOf(const Object* const& element, int start_index, int absent) const = 0;


        /**
         * 探索開始位置を start_index 番目からとして、sub_collection の要素と同
         * 値となるインデックスを返します。
         */
        virtual int indexOfSubCollection(const SequenceableCollection* const& sub_collection, int start_index) const {
            return indexOfSubCollection( sub_collection, start_index, -1 );
        }
        /**
         * 探索開始位置を start_index 番目からとして、sub_collection の要素と同
         * 値となるインデックスを返します。無い場合は absent を返します。
         */
        virtual int indexOfSubCollection(const SequenceableCollection* const& sub_collection, int start_index, int absent) const = 0;


        /**
         * 最初の要素を返します。
         */
        virtual Object* first() const {
            return at( 0 );
        }
        /**
         * 0..n までの要素からなる新しいコレクションを返します。
         */
        virtual SequenceableCollection* const first(int n) const;


        /**
         * 最後の要素を返します。
         */
        virtual Object* const last() const {
            return at( size() - 1 );
        }
        /**
         * n..length-1 までの要素からなる新しいコレクションを返します。
         */
        virtual SequenceableCollection* const last(int n) const;


        /**
         * このコレクションに that と同値の要素があれば、その(最大の)インデック
         * スを返します。
         */
        virtual int lastIndexOf(const Object* const& that) const {
            return lastIndexOf( that, 0, -1 );
        }
        /**
         * このコレクションに that と同値の要素があれば、その(最大の)インデックス
         * を返します。無い場合は absent を返します。
         */
        virtual int lastIndexOf(const Object* const& that, int absent) const {
            return lastIndexOf( that, 0, absent );
        }
        /**
         * このコレクションに that と同値の要素があれば、その(最大の)インデックス
         * を返します。要素の探索範囲を start_index からとし、無い場合は absent を返します。
         */
        virtual int lastIndexOf(const Object* const& that, int start_index, int absent) const = 0;


        /**
         * 中央の要素を返します。
         */
        virtual Object* const middle() const { return at( size() / 2 ); }


        /**
         * old_item と同値の全要素を replacement に置き換えます。
         */
        virtual void replaceAll(const Object* const& old_item, Object* const& replacement);


        /**
         * レシーバの start 番目から stop 番目の要素を replacements で置き換えます。
         */
        virtual void replaceFrom(int start, int stop, SequenceableCollection* const& replacements) {
            replaceFrom( start, stop, replacements, 0 );
        }
        /**
         * レシーバの start 番目から stop 番目の要素を replacements の rep_start から始まる要素で置き換えます。
         */
        virtual void replaceFrom(int start, int stop, SequenceableCollection* const& replacements, int rep_start);


        /**
         * one_index 番目の要素と another_index 番目の要素と入れ替えます。
         */
        virtual void swap(int one_index, int another_index);


        /**
         * レシーバと other を比較します。要素数が一致し、各要素の値が一致していれば真を返します。
         */
        virtual bool equals(const SequenceableCollection* const& other) const;


        /**
         * レシーバと other で同値の要素があるかどうか調べます。
         */
        virtual bool hasEqualsElements(const SequenceableCollection* const& other) const;


        /**
         * Array オブジェクトに変換して返します。
         */
        virtual Array* asArray() const;


        /**
         * 順序集合である場合、真を返します。
         */
        virtual bool is_sequenceable() const { return true; }


        /**
         * このコレクションを含んだ ReadStream オブジェクトを作成して返します。
         */
        virtual ReadStream* const readStream() const;


        /**
         * このコレクションを反転させたものを返します。
         */
        virtual SequenceableCollection* const reverse() const;


        /**
         * このコレクションを含んだ WriteStream オブジェクトを作成して返します。
         */
        virtual WriteStream* const writeStream() const;


        /**
         * このコレクションと指定されたコレクションを連結した新しいコレクションを返します。
         */
        virtual SequenceableCollection* const concat(const SequenceableCollection* const& concatee) const = 0;


        /**
         * このコレクションの浅いコピーを作成して返します。
         */
        virtual Collection* const copy() const {
            return copy( 0, size() - 1 );
        }
        /**
         * このコレクションの start 番目から stop 番目の要素からなるコレクションを返します。
         */
        virtual Collection* const copy(int start, int stop) const = 0;


        /**
         * このコレクション内の最初の要素から that と合致するまでの要素からなる新しいコレクションを返します。
         * 要素がない場合は全要素を返します。
         */
        virtual Collection* const copyUpTo(const Object* const& that) const {
            int index = indexOf( that );

            if ( index != -1 )
                return copy( 0, index - 1 );
            else
                return copy();
        }


        /**
         * このコレクション内の最後の要素から that と合致するまでの要素からなる新しいコレクションを返します。
         * 合致する要素がない場合は全要素を返します。
         */
        virtual Collection* const copyUpToLast(const Object* const& that) const {
            int index = lastIndexOf( that );

            if ( index != -1 )
                return copy( 0, index - 1 );
            else
                return copy();
        }


        /**
         * element をこのコレクションの末尾に追加した新しいコレクションを返します。
         */
        virtual Collection* const copyWith(Object* const& element) const;


        /**
         * element をこのコレクションの先頭に追加した新しいコレクションを返します。
         */
        virtual Collection* const copyWithFirst(Object* const& element) const;


        /**
         * このコレクションの要素数を newlength にします。このコレクションの要素数より大きい場合には padding_element を最後に追加します。
         * このコレクションの要素数より小さい場合には先頭の要素から newlength 個に切り詰めたコレクションになります。
         */
        virtual const SequenceableCollection* const forceTo(size_t newlength, Object* const& padding_element);


        /**
         * このコレクションの浅いコピーを返します。
         */
        virtual SequenceableCollection* shallowCopy() const = 0;


        /**
         * other の全要素とこのコレクションの要素が前方一致すれば真を返します。
         */
        virtual bool beginsWith(const SequenceableCollection* const& other) const;


        /**
         * other の全要素とこのコレクションの要素が後方一致すれば真を返します。
         */
        virtual bool endsWith(const SequenceableCollection* const& other) const;
    };
    
}


#endif  /* canopus_SequenceableCollection_hxx */
