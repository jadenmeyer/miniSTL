#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <exception>
#include <stdexcept>
template <typename T, std::size_t N> struct array {
    // fail at compile time if we have a N = 0 case (not possible)
    static_assert(N > 0, "miniSTL::array must have size greater than 0");
    static T _data[N]; // interior array we are going to edit
                       // using cppreferenc.com documentation to fill in the rest here

    // aliases for member types
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    // TODO: add in iterators for later

    // This is the implementation for access functions
    constexpr reference at(std::size_t pos) {
        if (pos >= N) {
            throw std::out_of_range("out_of_range"); // throw error if too big
        }
        return _data[pos];
    }
    constexpr const_reference at(std::size_t pos) const {
        if (pos >= N) {
            throw std::out_of_range("out_of_range"); // throw error if too big
        }
        return _data[pos];
    }
    constexpr reference operator[](size_type pos) {
        return _data[pos];
    }
    constexpr const_reference operator[](size_type pos) const {
        return _data[pos];
    }
    constexpr reference front() {
        return _data[0];
    }
    constexpr const_reference back() const {
        return _data[N - 1];
    }
    constexpr reference back() {
        return _data[N - 1];
    }

    // need to cast to pointer (since _data is a static arr)
    // using static_cast for compile time

    constexpr pointer data() noexcept {
        return static_cast<pointer>(_data);
    }
    constexpr const_pointer data() const noexcept {
        return static_cast<pointer>(_data);
    }

    // This is the implementation for Capacity funcitons
    constexpr bool empty() const noexcept {
        return N > 0; // note this is going to be true always with the static assert above
    }
    constexpr size_type size() const noexcept {
        return N;
    }
    constexpr size_type max_size() const noexcept {
        return N;
    }

    // TODO: iterators and fill/swap then that completes the array
};
// TODO: make a seperate template that supports a 0 sized array for
// what im reading as tail-padded structures/stuct hack (optional maybe?)
#endif // !ARRAY_H
