template <typename T>
class my_unique_ptr {
public:
    // Constructor
    explicit my_unique_ptr(T* ptr = nullptr) : _ptr(ptr) {}

    // Destructor
    ~my_unique_ptr() {
        delete _ptr;
    }

    // Move constructor
    my_unique_ptr(my_unique_ptr&& other) noexcept : _ptr(other._ptr) {
        other._ptr = nullptr;
    }

    // Move assignment operator
    my_unique_ptr& operator=(my_unique_ptr&& other) noexcept {
        if (this != &other) {
            delete _ptr;  // Delete the current resource
            _ptr = other._ptr;  // Transfer ownership
            other._ptr = nullptr;  // Nullify the source pointer
        }
        return *this;
    }

    // Deleted copy constructor and copy assignment operator
    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    // Accessor for the underlying pointer
    T* get() const {
        return _ptr;
    }
    // Dereference operator
    T& operator*() const {
        return *_ptr;
    }
    // Arrow operator
    T* operator->() const {
        return _ptr;
    }
    // Check if the pointer is null
    bool is_null() const {
        return _ptr == nullptr;
    }
    // Release ownership of the pointer
    T* release() {
        T* temp = _ptr;
        _ptr = nullptr;
        return temp;
    }
    // Reset the pointer to a new value
    void reset(T* ptr = nullptr) {
        delete _ptr;  // Delete the old resource
        _ptr = ptr;   // Assign the new resource
    }
    // Swap the contents of two unique pointers
    void swap(my_unique_ptr& other) noexcept {
        std::swap(_ptr, other._ptr);
    }
private:
    T* _ptr;  // Underlying raw pointer
};