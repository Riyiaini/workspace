#include "vectorString.h"
#include <utility>

vectorString::vectorString() noexcept 
    :logicalSize(0), allocatedSize(kInitialSize) 
{
    //std::cout << "Hello from the default constructor!" << std::endl;
    elems = new std::string[allocatedSize];
}

vectorString::vectorString(size_type n, const std::string& val) noexcept :
    logicalSize(n), allocatedSize(2*n) 
{
    //std::cout << "Hello from the fill constructor!" << std::endl;
    elems = new std::string[allocatedSize];
    std::fill(begin(), end(), val);
}

vectorString::vectorString(const vectorString& other) noexcept
    :logicalSize(other.logicalSize), allocatedSize(other.allocatedSize)
{
    //std::cout << "Hello from the copy constructor!" << std::endl;
    elems = new std::string[allocatedSize];
    std::copy(other.begin(), other.end(), begin());
}

vectorString& vectorString::operator=(const vectorString& rhs) noexcept {
    //std::cout << "Hello from the copy assignment oparator!" << std::endl;
    if (this != &rhs) {
        delete[] elems;
        logicalSize = rhs.logicalSize;
        allocatedSize = rhs.allocatedSize;
        elems = new std::string[allocatedSize];
        std::copy(rhs.begin(), rhs.end(), begin());
    }
    return *this;
}

vectorString::vectorString(vectorString&& other) noexcept :
    logicalSize(std::move(other.logicalSize)),
    allocatedSize(std::move(other.allocatedSize)),
    elems(std::move(other.elems)) 
{
    //std::cout << "Hello from the move constructor!" << std::endl;
    other.elems = nullptr;
}

vectorString& vectorString::operator=(vectorString&& rhs) noexcept {
    //std::cout << "Hello from the move assignment operator!" << std::endl;
    if (this != &rhs) {
        delete[] elems;
        logicalSize = std::move(rhs.logicalSize);
        allocatedSize = std::move(rhs.allocatedSize);
        elems = std::move(rhs.elems);
        rhs.elems = nullptr;
    }
    return *this;
}

vectorString::~vectorString() noexcept {
    //std::cout << "Hello from the destructor!" << std::endl;
    delete[] elems;
}

vectorString::size_type vectorString::size() const {
    return logicalSize;
}

bool vectorString::empty() const {
    return logicalSize == 0;
}