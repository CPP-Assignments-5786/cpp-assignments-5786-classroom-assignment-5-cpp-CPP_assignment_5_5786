/**
 * @file Complex.hpp
 * @brief Header file for the Complex class
 *
 * Complex numbers can be represented as:
 * - Rectangular form: a + bi
 * - Polar form: r∠θ or r*e^(iθ)
 * - String: "a+bi"
 * - Magnitude: |z| = √(a² + b²)
 */

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <string>
#include <iostream>
#include <cmath>

namespace complex_math {

    /**
     * @brief Complex class representing a complex number in rectangular form
     * z = a + bi where a is real part, b is imaginary part
     */
    class Complex {
    private:
        double real;      // Real part (a)
        double imag;      // Imaginary part (b)
        
        // Static members
        static int totalComplexCreated;
        static int currentComplexCount;
        static double epsilon;  // For floating-point comparison

    public:
        // ============ Constructors & Destructor ============
        
        /**
         * @brief Default constructor - creates 0 + 0i
         */
        Complex();

        /**
         * @brief Parameterized constructor (real only)
         * Creates a + 0i (real number)
         * @param real Real part
         */
        Complex(double real);

        /**
         * @brief Parameterized constructor (real and imaginary)
         * Creates a + bi
         * @param real Real part
         * @param imag Imaginary part
         */
        Complex(double real, double imag);

        /**
         * @brief Copy constructor
         * @param other Complex number to copy from
         */
        Complex(const Complex& other);

        /**
         * @brief Destructor
         */
        ~Complex();

        // ============ Getters & Setters (Inline) ============

        /**
         * @brief Get real part - const method
         * @return Real part
         */
        inline double getReal() const {
            return real;
        }

        /**
         * @brief Get imaginary part - const method
         * @return Imaginary part
         */
        inline double getImag() const {
            return imag;
        }

        /**
         * @brief Set real part
         * @param r New real part
         */
        inline void setReal(double r) {
            this->real = r;
        }

        /**
         * @brief Set imaginary part
         * @param i New imaginary part
         */
        inline void setImag(double i) {
            this->imag = i;
        }

        // ============ Complex Number Properties (Outline) ============

        /**
         * @brief Calculate magnitude (modulus) |z| = √(a² + b²)
         * @return Magnitude
         */
        double magnitude() const;

        /**
         * @brief Calculate phase (argument) θ = atan2(b, a)
         * @return Phase in radians
         */
        double phase() const;

        /**
         * @brief Get complex conjugate:  if z = a+bi, then z* = a-bi
         * @return Conjugate complex number
         */
        Complex conjugate() const;

        /**
         * @brief Check if complex number is zero
         * @return true if both real and imag are near zero
         */
        bool isZero() const;

        /**
         * @brief Check if complex number is real (imag ≈ 0)
         * @return true if imaginary part is near zero
         */
        bool isReal() const;

        /**
         * @brief Check if complex number is imaginary (real ≈ 0)
         * @return true if real part is near zero
         */
        bool isImaginary() const;

        // ============ Static Methods ============

        static int getTotalComplexCreated();
        static int getCurrentComplexCount();
        static void setEpsilon(double eps);
        static double getEpsilon();

        /**
         * @brief Create complex number from polar form
         * @param magnitude Magnitude r
         * @param phase Phase θ in radians
         * @return Complex number in rectangular form
         */
        static Complex fromPolar(double magnitude, double phase);

        // ============ CONVERSION OPERATORS (NEW - Assignment 5) ============

        /**
         * @brief Convert to double (returns magnitude)
         * @return Magnitude of complex number
         */
        operator double() const;

        /**
         * @brief Convert to float (returns magnitude)
         * @return Magnitude as float
         */
        operator float() const;

        /**
         * @brief Convert to bool (check if non-zero)
         * @return true if complex number is not zero
         */
        operator bool() const;

        /**
         * @brief Convert to string in rectangular form "a+bi"
         * @return String representation
         */
        operator std::string() const;

        /**
         * @brief Convert to int (returns magnitude rounded to nearest integer using std::round)
         * @return Magnitude as integer
         */
        operator int() const;

        // ============ String Representations ============

        /**
         * @brief Get string in rectangular form "a+bi"
         * @return String in format "a+bi"
         */
        std::string toRectangularString() const;

        /**
         * @brief Get string in polar form "r∠θ" or "r(cos θ + i sin θ)"
         * @param degrees If true, use degrees; otherwise radians
         * @return String in polar form
         */
        std::string toPolarString(bool degrees = true) const;

        // ============ ARITHMETIC OPERATORS ============

        /**
         * @brief Addition:  (a+bi) + (c+di) = (a+c) + (b+d)i
         * @param other Complex number to add
         * @return Sum
         */
        Complex operator+(const Complex& other) const;

        /**
         * @brief Add real number
         * @param real Real number to add
         * @return Sum
         */
        Complex operator+(double real) const;

        /**
         * @brief Subtraction: (a+bi) - (c+di) = (a-c) + (b-d)i
         * @param other Complex number to subtract
         * @return Difference
         */
        Complex operator-(const Complex& other) const;

        /**
         * @brief Subtract real number
         * @param real Real number to subtract
         * @return Difference
         */
        Complex operator-(double real) const;

        /**
         * @brief Multiplication:  (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
         * @param other Complex number to multiply
         * @return Product
         */
        Complex operator*(const Complex& other) const;

        /**
         * @brief Multiply by real number
         * @param real Real number to multiply
         * @return Product
         */
        Complex operator*(double real) const;

        /**
         * @brief Division: (a+bi) / (c+di) = [(ac+bd) + (bc-ad)i] / (c²+d²)
         * @param other Complex number to divide by
         * @return Quotient
         * @throws std::invalid_argument if dividing by zero
         */
        Complex operator/(const Complex& other) const;

        /**
         * @brief Divide by real number
         * @param real Real number to divide by
         * @return Quotient
         */
        Complex operator/(double real) const;

        /**
         * @brief Unary negation: -(a+bi) = -a-bi
         * @return Negated complex number
         */
        Complex operator-() const;

        // ============ COMPOUND ASSIGNMENT OPERATORS ============

        Complex& operator+=(const Complex& other);
        Complex& operator+=(double real);
        Complex& operator-=(const Complex& other);
        Complex& operator-=(double real);
        Complex& operator*=(const Complex& other);
        Complex& operator*=(double real);
        Complex& operator/=(const Complex& other);
        Complex& operator/=(double real);

        // ============ INCREMENT/DECREMENT (Suffix) OPERATORS ============

        /**
         * @brief Prefix increment (++z) - increments real part
         * @return Reference to this
         */
        Complex& operator++();

        /**
         * @brief Postfix increment (z++) - increments real part
         * @param dummy Dummy parameter
         * @return Copy before increment
         */
        Complex operator++(int dummy);

        /**
         * @brief Prefix decrement (--z) - decrements real part
         * @return Reference to this
         */
        Complex& operator--();

        /**
         * @brief Postfix decrement (z--) - decrements real part
         * @param dummy Dummy parameter
         * @return Copy before decrement
         */
        Complex operator--(int dummy);

        // ============ COMPARISON OPERATORS ============

        /**
         * @brief Equality comparison (compares both real and imag parts)
         * @param other Complex number to compare
         * @return true if equal (within epsilon)
         */
        bool operator==(const Complex& other) const;

        /**
         * @brief Inequality comparison
         * @param other Complex number to compare
         * @return true if not equal
         */
        bool operator!=(const Complex& other) const;

        /**
         * @brief Less than comparison (compares magnitudes)
         * @param other Complex number to compare
         * @return true if |this| < |other|
         */
        bool operator<(const Complex& other) const;

        /**
         * @brief Greater than comparison (compares magnitudes)
         * @param other Complex number to compare
         * @return true if |this| > |other|
         */
        bool operator>(const Complex& other) const;

        /**
         * @brief Less than or equal (compares magnitudes)
         * @param other Complex number to compare
         * @return true if |this| <= |other|
         */
        bool operator<=(const Complex& other) const;

        /**
         * @brief Greater than or equal (compares magnitudes)
         * @param other Complex number to compare
         * @return true if |this| >= |other|
         */
        bool operator>=(const Complex& other) const;

        // ============ ASSIGNMENT OPERATOR ============

        /**
         * @brief Assignment operator
         * @param other Complex number to assign from
         * @return Reference to this
         */
        Complex& operator=(const Complex& other);

        // ============ STREAM OPERATORS ============

        /**
         * @brief Output stream operator
         * Format: "a+bi" or "a-bi"
         * @param os Output stream
         * @param c Complex number to output
         * @return Reference to output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Complex& c);

        /**
         * @brief Input stream operator
         * Expected format: "a+bi" or "a-bi" or just "a"
         * @param is Input stream
         * @param c Complex number to input into
         * @return Reference to input stream
         */
        friend std::istream& operator>>(std::istream& is, Complex& c);

        // ============ NON-MEMBER ARITHMETIC OPERATORS ============

        /**
         * @brief Add real number to complex (reverse order)
         * @param real Real number
         * @param c Complex number
         * @return Sum
         */
        friend Complex operator+(double real, const Complex& c);

        /**
         * @brief Subtract complex from real number
         * @param real Real number
         * @param c Complex number
         * @return Difference
         */
        friend Complex operator-(double real, const Complex& c);

        /**
         * @brief Multiply real number by complex (reverse order)
         * @param real Real number
         * @param c Complex number
         * @return Product
         */
        friend Complex operator*(double real, const Complex& c);

        /**
         * @brief Divide real number by complex
         * @param real Real number
         * @param c Complex number
         * @return Quotient
         */
        friend Complex operator/(double real, const Complex& c);

        // ============ FRIEND FUNCTIONS ============

        /**
         * @brief Calculate distance between two complex numbers
         * @param c1 First complex number
         * @param c2 Second complex number
         * @return Distance |c1 - c2|
         */
        friend double distance(const Complex& c1, const Complex& c2);

        /**
         * @brief Check if two complex numbers have same magnitude
         * @param c1 First complex number
         * @param c2 Second complex number
         * @return true if |c1| ≈ |c2|
         */
        friend bool sameMagnitude(const Complex& c1, const Complex& c2);

        /**
         * @brief Calculate dot product (treating as 2D vectors)
         * @param c1 First complex number
         * @param c2 Second complex number
         * @return Dot product:  a1*a2 + b1*b2
         */
        friend double dotProduct(const Complex& c1, const Complex& c2);
    };

} // namespace complex_math

#endif // COMPLEX_HPP