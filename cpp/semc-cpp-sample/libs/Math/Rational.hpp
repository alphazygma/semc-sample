#ifndef _Rational_hpp
#define _Rational_hpp

namespace Math {
    /**
     * Simple class interface to handle fractions
     * @author Alejandro B. Salazar
     */
    class Rational {
    private:
        int _n = 0;
        int _d = 1;
    
    public:
        /**
         * Base Constructor
         * @param numerator Default 0 if no parameters are supplied
         * @param denominator Default 1 is denominator is not supplied
         */
        Rational ( int numerator = 0, int denominator = 1 );
        
        /**
         * Copy constructor
         * @param rhs Creates a new Rational object copying the numerator and denominator from the
         *            supplied object.
         */
        Rational ( const Rational & rhs );
        
        // Destructor
        ~Rational ();
        
        /**
         * Getter to retrieve the numerator
         * @return The defined numerator
         */
        int numerator() const;
        /**
         * Getter to retrieve the denominator
         * @return The defined denominator
         */
        int denominator() const;
        
        // Operator overloadig for the Rational class
        Rational & operator = ( const Rational & );
        Rational operator + ( const Rational & ) const;
        Rational operator - ( const Rational & ) const;
        Rational operator * ( const Rational & ) const;
        Rational operator / ( const Rational & ) const;
    };
}

// Overload to allow printing the Rational object through `cout`
std::ostream & operator << (std::ostream & o, const Math::Rational & r);

#endif /* _Rational_hpp */
