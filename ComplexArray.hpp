/**
 * @file ComplexArray.hpp
 * @brief Header file for the ComplexArray class
 *
 * A dynamic array of Complex numbers supporting deep copy semantics.
 */

#ifndef COMPLEXARRAY_HPP
#define COMPLEXARRAY_HPP

#include "Complex.hpp"
#include <string>
#include <iostream>

namespace complex_math {

    /**
     * @brief ComplexArray class - dynamic array of Complex numbers
     */
    class ComplexArray {
    private:
        Complex* data;      // COMPOSITION: Dynamic array of Complex objects
        int size;           // Current number of elements
        int capacity;       // Maximum capacity
        
        // Static members
        static int totalArraysCreated;
        static int currentArrayCount;

        /**
         * @brief Resize the internal array when capacity is exceeded
         */
        void resize();

    public:
        // ============ Constructors & Destructor ============

        /**
         * @brief Default constructor
         * Creates empty array with capacity 10
         */
        ComplexArray();

        /**
         * @brief Parameterized constructor
         * @param initialCapacity Initial capacity
         */
        ComplexArray(int initialCapacity);

        /**
         * @brief Constructor with initial values
         * @param values Array of complex numbers
         * @param count Number of elements
         */
        ComplexArray(const Complex* values, int count);

        /**
         * @brief DEEP COPY CONSTRUCTOR
         * @param other ComplexArray to copy from
         */
        ComplexArray(const ComplexArray& other);

        /**
         * @brief Destructor
         */
        ~ComplexArray();

        // ============ Getters (Inline) ============

        /**
         * @brief Get size - const method
         * @return Number of elements
         */
        inline int getSize() const {
            return size;
        }

        /**
         * @brief Get capacity - const method
         * @return Maximum capacity
         */
        inline int getCapacity() const {
            return capacity;
        }

        /**
         * @brief Check if empty - const method
         * @return true if no elements
         */
        inline bool isEmpty() const {
            return size == 0;
        }

        // ============ Static Methods ============

        static int getTotalArraysCreated();
        static int getCurrentArrayCount();

        // ============ Array Operations (Outline) ============

        /**
         * @brief Add element to end of array
         * @param value Complex number to add
         */
        void add(const Complex& value);

        /**
         * @brief Insert element at index
         * @param index Index to insert at
         * @param value Complex number to insert
         * @return true if successful
         */
        bool insert(int index, const Complex& value);

        /**
         * @brief Remove element at index
         * @param index Index to remove
         * @return true if successful
         */
        bool remove(int index);

        /**
         * @brief Clear all elements (doesn't deallocate)
         */
        void clear();

        /**
         * @brief Find first occurrence of value
         * @param value Value to find
         * @return Index if found, -1 otherwise
         */
        int find(const Complex& value) const;

        /**
         * @brief Check if array contains value
         * @param value Value to check
         * @return true if found
         */
        bool contains(const Complex& value) const;

        // ============ Mathematical Operations ============

        /**
         * @brief Calculate sum of all elements
         * @return Sum
         */
        Complex sum() const;

        /**
         * @brief Calculate average (mean) of all elements
         * @return Average
         */
        Complex average() const;

        /**
         * @brief Find element with maximum magnitude
         * @return Complex number with max magnitude
         */
        Complex max() const;

        /**
         * @brief Find element with minimum magnitude
         * @return Complex number with min magnitude
         */
        Complex min() const;

        /**
         * @brief Calculate magnitude of all elements as vector
         * @return Magnitude
         */
        double vectorMagnitude() const;

        // ============ BRACKET OPERATOR [] ============

        /**
         * @brief Access element by index (non-const)
         * @param index Index
         * @return Reference to element
         * @throws std::out_of_range if index invalid
         */
        Complex& operator[](int index);

        /**
         * @brief Access element by index (const version)
         * @param index Index
         * @return Const reference to element
         * @throws std::out_of_range if index invalid
         */
        const Complex& operator[](int index) const;

        // ============ PARENTHESES OPERATOR () ============

        /**
         * @brief Get subarray [start, end)
         * @param start Start index (inclusive)
         * @param end End index (exclusive)
         * @return New ComplexArray with subarray
         */
        ComplexArray operator()(int start, int end) const;

        /**
         * @brief Get first n elements
         * @param n Number of elements
         * @return New ComplexArray with first n elements
         */
        ComplexArray operator()(int n) const;

        // ============ ARITHMETIC OPERATORS ============

        /**
         * @brief Add scalar to all elements
         * @param value Complex number to add
         * @return New array with modified elements
         */
        ComplexArray operator+(const Complex& value) const;

        /**
         * @brief Element-wise addition of two arrays
         * @param other Array to add
         * @return New array with sums
         */
        ComplexArray operator+(const ComplexArray& other) const;

        /**
         * @brief Subtract scalar from all elements
         * @param value Complex number to subtract
         * @return New array with modified elements
         */
        ComplexArray operator-(const Complex& value) const;

        /**
         * @brief Element-wise subtraction
         * @param other Array to subtract
         * @return New array with differences
         */
        ComplexArray operator-(const ComplexArray& other) const;

        /**
         * @brief Multiply all elements by scalar
         * @param value Complex number to multiply
         * @return New array with products
         */
        ComplexArray operator*(const Complex& value) const;

        /**
         * @brief Scalar multiplication
         * @param scalar Real scalar
         * @return New array scaled by scalar
         */
        ComplexArray operator*(double scalar) const;

        /**
         * @brief Divide all elements by scalar
         * @param value Complex number to divide by
         * @return New array with quotients
         */
        ComplexArray operator/(const Complex& value) const;

        // ============ COMPOUND ASSIGNMENT OPERATORS ============

        ComplexArray& operator+=(const Complex& value);
        ComplexArray& operator+=(const ComplexArray& other);
        ComplexArray& operator-=(const Complex& value);
        ComplexArray& operator*=(const Complex& value);
        ComplexArray& operator*=(double scalar);

        // ============ ASSIGNMENT OPERATOR (Deep Copy) ============

        /**
         * @brief Assignment operator - performs deep copy
         * @param other ComplexArray to assign from
         * @return Reference to this
         */
        ComplexArray& operator=(const ComplexArray& other);

        // ============ COMPARISON OPERATORS ============

        /**
         * @brief Equality comparison (element-wise)
         * @param other Array to compare
         * @return true if all elements equal
         */
        bool operator==(const ComplexArray& other) const;

        /**
         * @brief Inequality comparison
         * @param other Array to compare
         * @return true if any element differs
         */
        bool operator!=(const ComplexArray& other) const;

        // ============ STREAM OPERATORS ============

        /**
         * @brief Output stream operator
         * Format: [c1, c2, c3, ...]
         * @param os Output stream
         * @param arr Array to output
         * @return Reference to output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const ComplexArray& arr);

        /**
         * @brief Input stream operator
         * @param is Input stream
         * @param arr Array to input into
         * @return Reference to input stream
         */
        friend std::istream& operator>>(std::istream& is, ComplexArray& arr);

        // ============ FRIEND FUNCTIONS ============

        /**
         * @brief Calculate dot product of two arrays (as vectors)
         * @param arr1 First array
         * @param arr2 Second array
         * @return Dot product
         */
        friend Complex dotProduct(const ComplexArray& arr1, const ComplexArray& arr2);

        /**
         * @brief Check if arrays have same size
         * @param arr1 First array
         * @param arr2 Second array
         * @return true if same size
         */
        friend bool sameSize(const ComplexArray& arr1, const ComplexArray& arr2);

        // ============ Utility Methods ============

        /**
         * @brief Print array to output stream
         * @param os Output stream (default: std::cout)
         */
        void print(std::ostream& os = std::cout) const;

        /**
         * @brief Reverse the array in-place
         */
        void reverse();

        /**
         * @brief Sort by magnitude (ascending)
         */
        void sort();
    };

} // namespace complex_math

#endif // COMPLEXARRAY_HPP