#include <iostream>

int calc_GCD(int first_numb, int second_numb){
	int mod_res;
	while(second_numb){
		mod_res = first_numb % second_numb;
		first_numb = second_numb;
		second_numb = mod_res;
	}
	return first_numb;
}

int euclides_GCD(int a, int b){
	return b == 0 ? a : euclides_GCD(b, a % b);
}

int calc_LCM(int a, int b){
	return a * b / euclides_GCD(a,b);
}
int main(){
	int first_numb, second_numb;
	std::cout << "Type first number: ";
	std::cin >> first_numb;
	std::cout << "Type second number: ";
	std::cin >> second_numb;
	std::cout << "Searched GCD: "  << calc_GCD(first_numb, second_numb) << std::endl;
	std::cout << "Recursive GCD: " << euclides_GCD(first_numb, second_numb) << std::endl;
	std::cout << "Searched LCM: " << calc_LCM(first_numb, second_numb) << std::endl;
}
