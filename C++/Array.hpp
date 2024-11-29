#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>

/*
Radix:
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/array
*/

namespace _2Ls
{
    template <typename T>
    class Array
    {
        T *_data;
        size_t _max_size, _size = 0;

    public:
        Array(const size_t &size) noexcept
            : _data(new T[size]), _max_size(size) {}        // Parameterized constructor
        Array() : _data(nullptr), _max_size(0) {}           // Default constructor
        Array(const Array &) noexcept = default;            // Copy constructor
        Array(Array &&) noexcept = default;                 // Move constructor
        Array &operator=(const Array &) noexcept = default; // Copy assignment
        Array &operator=(Array &&) noexcept = default;      // Move assignment
        ~Array() { delete[] _data; };                       // Default destructor

        T *begin() noexcept { return _data; }
        const T *begin() const noexcept { return _data; }
        T *end() noexcept { return _data + _size; }
        const T *end() const noexcept { return _data + _size; }
        std::reverse_iterator<T *> rbegin() noexcept { return std::reverse_iterator<T *>(end()); }
        std::reverse_iterator<const T *> rbegin() const noexcept { return std::reverse_iterator<const T *>(end()); }
        std::reverse_iterator<T *> rend() noexcept { return std::reverse_iterator<T *>(begin()); }
        std::reverse_iterator<const T *> rend() const noexcept { return std::reverse_iterator<const T *>(begin()); }
        const T *cbegin() const noexcept { return begin(); }
        const T *cend() const noexcept { return end(); }
        std::reverse_iterator<const T *> crbegin() const noexcept { return rbegin(); }
        std::reverse_iterator<const T *> crend() const noexcept { return rend(); }

        size_t size() const noexcept { return _size; }
        size_t max_size() const noexcept { return _max_size; }
        bool empty() const noexcept { return _size == 0; }
        bool full() const noexcept { return _size == _max_size; }

        T &operator[](const size_t &index) noexcept { return _data[index]; }
        const T &operator[](const size_t &index) const noexcept { return _data[index]; }
        T &at(const size_t &index)
        {
            if (index >= _size)
                throw std::out_of_range("_2Ls::Array::at out of range");
            return _data[index];
        }
        const T &at(const size_t &index) const
        {
            if (index >= _size)
                throw std::out_of_range("_2Ls::Array::at out of range");
            return _data[index];
        }
        T &front() noexcept { return _data[0]; }
        const T &front() const noexcept { return _data[0]; }
        T &back() noexcept { return _data[_size - 1]; }
        const T &back() const noexcept { return _data[_size - 1]; }
        T *data() noexcept { return _data; }
        const T *data() const noexcept { return _data; }

        template <typename InputIterator>
        void assign(InputIterator first, InputIterator last)
        {
            const size_t n = std::distance(first, last);
            if (n > _max_size)
                throw std::length_error("Array::assign - size exceeds max_size");
            _size = n;
            std::copy(first, last, _data);
        }
        void assign(const size_t &n, const T &value)
        {
            if (n > _max_size)
                throw std::length_error("Array::assign - size exceeds max_size");
            _size = n;
            std::fill(_data, _data + n, value);
        }
        void assign(std::initializer_list<T> il)
        {
            const size_t n = il.size();
            if (n > _max_size)
                throw std::length_error("Array::assign - size exceeds max_size");
            _size = n;
            std::copy(il.begin(), il.end(), _data);
        }
        void push(const T &value)
        {
            if (_size == _max_size)
                throw std::overflow_error("_2Ls::Stack::push overflow");
            _data[_size++] = value;
        }
        void pop()
        {
            if (_size == 0)
                throw std::underflow_error("_2Ls::Stack::pop overflow");
            --_size;
        }
    };
}

#endif
