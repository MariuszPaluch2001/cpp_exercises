#include <iostream>

int is_abundant(int number){
	int sum = 0;
	for (int i = 2; i < number; i++){
		if (number % i == 0)
			sum += i;
	}
	
	return (sum > number ? sum : 0);
}

int main(){
	int number;
	std::cout << "Enter a number: ";
	std::cin >> number;
	int abund;
	for (int i = 2; i < number; i++){
		abund = is_abundant(i);
		if (abund != 0)
			std::cout << "Number: " << i << " , ab: " << abund << std::endl;
	}
	return 0;
}
