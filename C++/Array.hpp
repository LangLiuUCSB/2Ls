#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>

/*
Radix:
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/array
*/

template <typename T>
class Array
{
    T *array;
    size_t size;

public:
    T *begin() noexcept { return array; }
    const T *begin() const noexcept { return array; }
    T *end() noexcept { return array + size; }
    const T *end() const noexcept { return array + size; }
    std::reverse_iterator<T *> rbegin() noexcept { return std::reverse_iterator<T *>(end()); }
    std::reverse_iterator<const T *> rbegin() const noexcept { return std::reverse_iterator<const T *>(end()); }
    std::reverse_iterator<T *> rend() noexcept { return std::reverse_iterator<T *>(begin()); }
    std::reverse_iterator<const T *> rend() const noexcept { return std::reverse_iterator<const T *>(begin()); }
    const T *cbegin() const noexcept { return begin(); }
    const T cend() const noexcept { return end(); }
    std::reverse_iterator<const T *> crbegin() const noexcept { return rbegin(); }
    std::reverse_iterator<const T *> crend() const noexcept { return rend(); }
    size_t size() const noexcept { return size; }
    bool empty() const noexcept { return size == 0; }
    T &operator[](size_t index) noexcept { return array[index]; }
    const T &operator[](size_t index) const noexcept { return array[index]; }
};

#endif
