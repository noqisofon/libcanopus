/**
 * @since 2010-10-15T00:48:02+0900
 */
#ifndef canopus_Cloneable_hxx
#define canopus_Cloneable_hxx


namespace canopus {


    /**
     * 2 �̃C���X�^���X�����������ǂ����𔻕ʂ��邽�߂̎�@��񋟂��܂��B
     */
    class Cloneable
    {
     public:
        /**
         * ���V�[�o�̃R�s�[���쐬���ĕԂ��܂��B
         */
        virtual Cloneable* const clone() const = 0;
    };


}


#endif  /* canopus_Cloneable_hxx */
