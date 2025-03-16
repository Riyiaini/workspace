#ifndef PRIORITY_Q_H
#define PRIORITY_Q_H
#include <vector>
#include <concepts>
#include <sstream>

using std::vector;

namespace my_std
{
    template<typename T1, typename T2, typename Container1, typename Container2>
    concept Convertible1 = std::is_convertible_v<T1, T2> &&
                           std::is_convertible_v<typename Container1::value_type, typename Container2::value_type>;


    template<typename T, typename Container = vector<T>>
    class priority_queue {
    public:
        using value_type = typename Container::value_type;
        using size_type = typename Container::size_type;
        using iterator = typename Container::iterator;
        using const_iterator = typename Container::const_iterator;


        priority_queue() = default;

        template<typename T1, typename Container1 = vector<T1>>
        requires Convertible1<T, T1, Container, Container1>
        explicit priority_queue(priority_queue<T1, Container1>&& other) noexcept;

        explicit priority_queue(priority_queue&& other) noexcept;

        template<typename T1, typename Container1 = vector<T1>>
        requires Convertible1<T, T1, Container, Container1>
        explicit priority_queue(const priority_queue<T1, Container1>& other) noexcept;

        explicit priority_queue(const priority_queue& other) noexcept;

        priority_queue& operator=(const priority_queue& other) = delete;
        priority_queue& operator=(priority_queue&& other) = delete;

        value_type get_size() const noexcept;

        Container get_heap() const noexcept;

        void push(const value_type& value);
        void pop();
        const value_type& top() const;
        bool empty() const noexcept;
        void clear() noexcept;

        iterator begin() noexcept { return _heap.begin(); }
        iterator end() noexcept { return _heap.end(); }
        const_iterator begin() const noexcept { return _heap.begin(); }
        const_iterator end() const noexcept { return _heap.end(); }
        

        template<typename T1, typename Container1>
        friend std::ostream& operator<<(std::ostream& os, const priority_queue<T1, Container1>& pq);


    private:
        Container _heap;
        size_type _size{0};
    };


    
    template<typename T, typename Container>
    template<typename T1, typename Container1>
    requires Convertible1<T, T1, Container, Container1>
    priority_queue<T, Container>::priority_queue(priority_queue<T1, Container1>&& other) noexcept
        :_size(std::move(static_cast<T>(other.get_size())))
    {
        _heap.reserve(other.get_size());
        for (auto it = other.begin(); it != other.end(); ++it) {
            _heap.push_back(static_cast<T>(*it));
        }
        //std::cout << "Move constructor called." << std::endl;
    }

    template<typename T, typename Container>
    template<typename T1, typename Container1>
    requires Convertible1<T, T1, Container, Container1>
    priority_queue<T, Container>::priority_queue(const priority_queue<T1, Container1>& other) noexcept
        :_size(std::move(static_cast<T>(other.get_size())))
    {
        _heap.reserve(other.get_size());
        for (auto it = other.begin(); it != other.end(); ++it) {
            _heap.push_back(static_cast<T>(*it));
        }
        //std::cout << "copy constructor called." << std::endl;
    }

    template<typename T, typename Container>
    priority_queue<T, Container>::priority_queue(priority_queue&& other) noexcept
        : _heap(std::move(other._heap)), _size(std::move(other._size))
    {
        //std::cout << "Move assignment operator called." << std::endl;
        other._size = 0;
        other._heap.clear();
    }

    template<typename T, typename Container>
    priority_queue<T, Container>::priority_queue(const priority_queue& other) noexcept
        : _heap(other._heap), _size(other._size)
    {
        //std::cout << "Copy assignment operator called." << std::endl;
    }

    template<typename T, typename Container>
    typename priority_queue<T, Container>::value_type priority_queue<T, Container>::get_size() const noexcept {
        return _size;
    }

    template<typename T, typename Container>
    Container priority_queue<T, Container>::get_heap() const noexcept {
        return _heap;
    }

    template<typename T, typename Container>
    void priority_queue<T, Container>::push(const value_type& value) {
        _heap.push_back(value);
        std::push_heap(_heap.begin(), _heap.end(), std::greater<T>());
        ++_size;
    }

    template<typename T, typename Container>
    void priority_queue<T, Container>::pop() {
        if (this->empty()) {
            throw std::out_of_range("Priority queue is empty.");
        }
        std::pop_heap(_heap.begin(), _heap.end(), std::greater<T>());
        _heap.pop_back();
        --_size;
    }

    template<typename T, typename Container>
    const typename priority_queue<T, Container>::value_type& priority_queue<T, Container>::top() const {
        if (this->empty()) {
            throw std::out_of_range("Priority queue is empty.");
        }
        return _heap.front();
    }

    template<typename T, typename Container>
    bool priority_queue<T, Container>::empty() const noexcept {
        return _size == 0;
    }

    template<typename T, typename Container>
    void priority_queue<T, Container>::clear() noexcept {
        _heap.clear();
        _size = 0;
    }

    template<typename T, typename Container>
    std::ostream& operator<<(std::ostream& os, const priority_queue<T, Container>& pq) {
        for (const auto& elem : pq.get_heap()) {
            os << elem << " ";
        }
        return os;
    }

}

#endif