#include <iostream>
#include <vector>
#include <iterator>

std::vector<int> prime_factors(int n){
	std::vector<int> result;
	while (n % 2 == 0){
		result.push_back(2);
		n /= 2;
	}
	
	for (int i = 3; i*i < n; i += 2){
		while (n % i == 0){
			result.push_back(i);
			n /= i;
		}
	}
	
	if (n > 2){
		result.push_back(n);
	}
	
	return result;
}


int main(){
	int numb;
	std::cout << "Enter number: ";
	std::cin >> numb;
	auto vect = prime_factors(numb);
	std::copy(std::begin(vect), std::end(vect), std::ostream_iterator<int>(std::cout, " "));
}
