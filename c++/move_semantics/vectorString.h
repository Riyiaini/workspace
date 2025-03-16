#ifndef VECTORSTRING_H
#define VECTORSTRING_H

#include <algorithm>
#include <string>

class vectorString {
public:
    using iterator = std::string*;
    using const_iterator = const std::string*;
    using size_type = std::size_t;

    const size_type kInitialSize = 5;
    vectorString() noexcept;
    vectorString(size_type n, const std::string& val) noexcept;
    vectorString(const vectorString& other) noexcept;
    vectorString(vectorString&& other) noexcept;
    vectorString& operator=(const vectorString& other) noexcept;
    vectorString& operator=(vectorString&& other) noexcept;

    ~vectorString() noexcept;

    size_type size() const;
    bool empty() const;

    iterator begin() { return elems; }
    iterator end() { return elems + logicalSize; }
    const iterator begin() const { return elems; }
    const iterator end() const { return elems + logicalSize; }
private:
    size_type logicalSize;
    size_type allocatedSize;
    std::string* elems;
};

#endif

