#include "priority_Q.h"
#include <queue>
#include <iostream>

using my_std::priority_queue;
using std::cout;
using std::endl;

int main() {
    priority_queue<float> pq;
    pq.push(5.1);
    pq.push(10.4);
    pq.push(3.7);
    pq.push(8.3);

    cout << pq << endl;

    cout << "Priority Queue: ";
    for (auto it = pq.begin(); it != pq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "After pop, top element: " << pq.top() << endl;

    cout << "Size of priority queue: " << pq.get_size() << endl;
    cout << "Is empty: " << (pq.empty() ? "Yes" : "No") << endl;
    cout << "Clearing the priority queue..." << endl;
    pq.clear();
    cout << "Is empty after clear: " << (pq.empty() ? "Yes" : "No") << endl;
    cout << "Size after clear: " << pq.get_size() << endl;

    return 0;
}