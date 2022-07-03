#include <iostream>

bool is_prime(int number){
	if (number < 2)
		return false;
	
	for (int i = 2; i*i <= number; i++){
		if (number % i == 0)
			return false;
	}
	
	return true;

}

bool is_prime_six(int number){
	if (is_prime(number) && is_prime(number + 6))
		return true;
	else
		return false;
}

int main(){
	int number;
	std::cout << "Enter a number: ";
	std::cin >> number;
	for (int i = 1; i < number; i++){
		if (is_prime_six(i))
			std::cout << "Six prime number: " << i << " " << i + 6 << std::endl;
	}
	for (int i = number; i >= 2; i--){
		if (is_prime(i)){
			std::cout << "Highest prime lower than " << number << " is " << i << std::endl;
			return 0;
		}
	}
	return 0;
}
