#ifndef canopus_OrderedCollection_hxx
#define canopus_OrderedCollection_hxx

#include <canopus/SequenceableCollection.hxx>


namespace canopus {


    /**
     * �������ςȃR���N�V�����ł��B
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
         * �i�[����Ă���v�f�̐������߂܂��B
         */
        virtual size_t size() const {
            return content_->size();
        }


        /**
         * �w�肳�ꂽ�v�f���R���N�V�����ɒǉ����܂��B
         */
        virtual bool add(Object* const& item);


        /**
         *
         */
        virtual Iterator* const iterator() const;


        /**
         * ���̃R���N�V�����̐󂢃R�s�[���쐬���ĕԂ��܂��B
         */
        virtual Collection* const copy() const;


        /**
         * ���̃R���N�V�����Ɠ����T�C�Y�ŋ�̐V�����R���N�V�������쐬���ĕԂ��܂��B
         */
        virtual Collection* const copyEmpty() const;


        /**
         * �w�肳�ꂽ�v�f���폜���܂��B���݂��Ȃ������ꍇ�� absent ��Ԃ��܂��B
         */
        virtual Object* const remove(const Object* const& old_object, Object* const absent);


        /**
         * index �Ԗڂ̗v�f��Ԃ��܂��B�v�f���Ȃ��ꍇ�� absent ��Ԃ��܂��B
         */
        virtual Object* at(int index, Object* const& absent) const;


        /**
         * index �Ԗڂ̗v�f�� replacement �Œu�������܂��B
         */
        virtual void put(int index, Object* const& replacement);


        /**
         * ���̃R���N�V������ element �Ɠ���̗v�f���܂܂�Ă���΂��̃C���f�b�N
         * �X��Ԃ��܂��B�Ȃ���� absent ��Ԃ��܂��B
         */
        virtual int identityIndexOf(const Object* const& element, int absent) const;


        /**
         * ���̃R���N�V������ element �Ɠ��l�̗v�f������΁A(�ŏ���)�C���f�b�N�X
         * ��Ԃ��܂��B�T���J�n�� start_index ����Ƃ��܂��B
         */
        virtual int indexOf(const Object* const& element, int start_index, int absent) const;


        /**
         * �T���J�n�ʒu�� start_index �Ԗڂ���Ƃ��āAsub_collection �̗v�f�Ɠ�
         * �l�ƂȂ�C���f�b�N�X��Ԃ��܂��B�����ꍇ�� absent ��Ԃ��܂��B
         */
        virtual int indexOfSubCollection(const SequenceableCollection* const& sub_collection, int start_index, int absent) const;


        /**
         * ���̃R���N�V������ that �Ɠ��l�̗v�f������΁A����(�ő��)�C���f�b�N�X
         * ��Ԃ��܂��B�v�f�̒T���͈͂� start_index ����Ƃ��A�����ꍇ�� absent ��Ԃ��܂��B
         */
        virtual int lastIndexOf(const Object* const& that, int start_index, int absent) const;


        /**
         * ���̃R���N�V�����Ǝw�肳�ꂽ�R���N�V������A�������V�����R���N�V������Ԃ��܂��B
         */
        virtual SequenceableCollection* const concat(const SequenceableCollection* const& concatee) const;


        /**
         * ���̃R���N�V�����̐󂢃R�s�[��Ԃ��܂��B
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
