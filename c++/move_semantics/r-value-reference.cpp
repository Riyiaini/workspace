#include <iostream>
#include <chrono>
#include <utility>
#include "vectorString.cpp"

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;

template<typename T>
void swap(T&& a, T&& b){
	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

template<typename T>
void swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

int main(){
	vectorString a(5, "Hello");
	vectorString b(4, "World");

	auto start = high_resolution_clock::now();
	
	for(int i = 0; i < 100000; i++)
		swap(std::move(a), std::move(b));

	auto end = high_resolution_clock::now();
	std:: chrono::duration<double> elapsed = end - start;

	cout << "Time taken for r-value reference swap: " << elapsed.count() << " seconds" << endl;

	start = high_resolution_clock::now();

	for(int i = 0; i < 100000; i++)
		swap(a, b);

	end = high_resolution_clock::now();
	elapsed = end - start;
	cout << "Time taken for l-value reference swap: " << elapsed.count() << " seconds" << endl;
}