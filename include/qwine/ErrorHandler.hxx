#ifndef qwine_ErrorHandler_hxx
#define qwine_ErrorHandler_hxx


namespace qwine {


    /**
     * 
     */
    class ErrorHandler 
    {
    protected:
        /**
         * 
         */
        virtual void raise(const char* const& message) = 0;
        /**
         * 
         */
        virtual void raise( const char* const& message,
                            const char* const& filename
            ) = 0;
        /**
         * 
         */
        virtual void raise( const char* const& message,
                            const char* const& filename,
                            int line_number) = 0;
        /**
         * 
         */
        virtual void raise( const char* const& message,
                            const char* const& filename,
                            int line_number,
                            const char* const& function_name) = 0;
    };
    
}


#endif  /* qwine_ErrorHandler_hxx */
