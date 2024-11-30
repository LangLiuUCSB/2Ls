#ifndef BOXARRAY_HPP
#define BOXARRAY_HPP

#include <stddef.h>

namespace _2Ls
{
    template <typename T>
    class BoxArray
    {
        T *_data;
        size_t _max_size, _end = 0;

    public:
        BoxArray(const size_t &size) noexcept
            : _data(new T[size]), _max_size(size) {}              // Parameterized constructor
        BoxArray() : _data(nullptr), _max_size(0) {}              // Default constructor
        BoxArray(const BoxArray &) noexcept = default;            // Copy constructor
        BoxArray(BoxArray &&) noexcept = default;                 // Move constructor
        BoxArray &operator=(const BoxArray &) noexcept = default; // Copy assignment
        BoxArray &operator=(BoxArray &&) noexcept = default;      // Move assignment
        ~BoxArray() { delete[] _data; };                          // Default destructor

        virtual T *begin() noexcept { return _data; }
        virtual const T *begin() const noexcept { return _data; }
        T *end() noexcept { return _data + _end; }
        const T *end() const noexcept { return _data + _end; }
        std::reverse_iterator<T *> rbegin() noexcept { return std::reverse_iterator<T *>(end()); }
        std::reverse_iterator<const T *> rbegin() const noexcept { return std::reverse_iterator<const T *>(end()); }
        std::reverse_iterator<T *> rend() noexcept { return std::reverse_iterator<T *>(begin()); }
        std::reverse_iterator<const T *> rend() const noexcept { return std::reverse_iterator<const T *>(begin()); }
        const T *cbegin() const noexcept { return begin(); }
        const T *cend() const noexcept { return end(); }
        std::reverse_iterator<const T *> crbegin() const noexcept { return rbegin(); }
        std::reverse_iterator<const T *> crend() const noexcept { return rend(); }

        virtual size_t size() const noexcept { return _end; }
        size_t max_end() const noexcept { return _max_size; }
        virtual bool empty() const noexcept { return _end == 0; }
        bool full() const noexcept { return _end == _max_size; }

        T &operator[](const size_t &index) noexcept { return _data[index]; }
        const T &operator[](const size_t &index) const noexcept { return _data[index]; }
        virtual T &at(const size_t &index)
        {
            if (index >= _end)
                throw std::out_of_range("_2Ls::BoxArray::at out of range");
            return _data[index];
        }
        virtual const T &at(const size_t &index) const
        {
            if (index >= _end)
                throw std::out_of_range("_2Ls::BoxArray::at out of range");
            return _data[index];
        }
        virtual T &front() noexcept { return _data[0]; }
        virtual const T &front() const noexcept { return _data[0]; }
        T &back() noexcept { return _data[_end - 1]; }
        const T &back() const noexcept { return _data[_end - 1]; }
        T *data() noexcept { return _data; }
        const T *data() const noexcept { return _data; }

        virtual void push(const T &value)
        {
            if (_end == _max_size)
                throw std::overflow_error("_2Ls::BoxArray::push overflow");
            _data[_end++] = value;
        }
        virtual void pop()
        {
            if (_end == 0)
                throw std::underflow_error("_2Ls::BoxArray::pop overflow");
            --_end;
        }

        T &extract() = 0;
        const T &extract() = 0;

        template <typename... Args>
        void emplace(Args &&...args) = 0;
    };
}

#endif
