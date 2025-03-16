#include <iostream>
#include <memory>

int main() {
    int* a = new int(5);
    std::cout << "Value of a: " << *a << std::endl;
    try
    {
        std::unique_ptr<int> ptr1(a);
        std::cout << "Value of ptr1: " << *ptr1 << std::endl;
        std::unique_ptr<int> ptr2 = std::move(ptr1); // Transfer ownership
        std::cout << "Value of ptr2: " << *ptr2 << std::endl;
        std::cout << "ptr1 is now deleted: " << (ptr1 == nullptr ? "Yes" : "No") << std::endl;
        throw std::runtime_error("Exception occurred");
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "Now value of a: " << *a << std::endl;
    std::cout << std::endl;


    a = new int(5);
    std::cout << "Value of a: " << *a << std::endl;
    try
    {
        throw std::runtime_error("Exception occurred");
        delete a;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "Now value of a: " << *a << std::endl;
}