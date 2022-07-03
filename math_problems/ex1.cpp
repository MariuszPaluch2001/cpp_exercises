#include <iostream>

int calc_sum(int number){
	int sum = 0;
	for (int i = 0; i <= number; i++)
		if (i % 3 == 0 || i % 5 == 0) 
			sum += i;
			
	return sum;
}

int main(){
	int number;
	std::cout << "Type a number: ";
	std::cin >> number;
	std::cout << "Searched sum is equal: " << calc_sum(number) << std::endl;
	return 0;
}
