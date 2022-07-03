#include <iostream>
#include <cmath>

#define BORDER 1000000

int sum_proper_divisors(int const number){
	int result = 1;
	for (int i = 2; i*i <= number; i++){
		if (number % i == 0){
			result += (i == (number / i)) ? i : (i + number/ i);
		}
	}
	
	return result;
}

void print_amicable_numbers(int const limit){
	for (int number = 4; number < limit; number++){
		int sum1 = sum_proper_divisors(number);
		if (sum1 < limit){
			int sum2 = sum_proper_divisors(sum1);
			if (sum2 == number && number != sum1){
				std::cout << number << "," << sum1 <<std::endl;
			}
		}
	}
}
int main(){
	int first_n;
	int second_n;
	int n = 1;
	std::cout << "Amicable numbers: " << std::endl;
	print_amicable_numbers(BORDER);
	
	return 0; 
}
