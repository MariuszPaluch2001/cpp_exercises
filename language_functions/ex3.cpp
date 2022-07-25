#include "ex3.h"
#include <stdexcept>
#include <iostream>
#include <iterator>

template <class T, size_t W, size_t K>
constexpr T& Array2d<T, W , K>::at(size_t const w, size_t const k){
	return array.at(w*K + k);
}

template <class T, size_t W, size_t K>
constexpr T const & Array2d<T, W , K>::at(size_t const w, size_t const k) const{
	return array.at(w*K + k);
}

template <class T, size_t W, size_t K>
constexpr T& Array2d<T, W , K>::operator()(size_t const w, size_t const k){
	return array[w*K + k];
}

template <class T, size_t W, size_t K>
constexpr T const & Array2d<T, W , K>::operator()(size_t const w, size_t const k) const{
	return array[w*K + k];
}

template <class T, size_t W, size_t K>
constexpr bool Array2d<T, W , K>::empty() const{
	return W == 0 || K == 0;
}

template <class T, size_t W, size_t K>
constexpr size_t Array2d<T, W , K>::size(int const rank) const{
	if (rank == 1)
		return W;
	else if (rank == 2)
		return K;
	throw std::out_of_range("Position out of range.");
}

template <class T, size_t W, size_t K>
void Array2d<T, W , K>::fill(T const & value){
	std::fill(std::begin(array),std::end(array), value);
}

template <class T, size_t W, size_t K>
void Array2d<T, W , K>::swap(Array2d & other){
	array.swap(other.array);
}

template <class T, size_t W, size_t K>
void print_array2d(Array2d<T,W,K> const & array){
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < K; j++)
		{
			std::cout << array.at(i,j) << ' ';
		}
		std::cout << std::endl;
	}		
}
int main(){
	Array2d<int,2,3> arr {1,2,3,4,5,6};
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			arr.at(i,j) *= 2;
	std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	Array2d<int,2,3> b;
	b.fill(1);
	arr.swap(b);
	std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	Array2d<int,2,3> c(std::move(b));
	std::copy(std::begin(c), std::end(c), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
