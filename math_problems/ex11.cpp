#include <iostream>
#include <vector>

std::vector<std::pair<unsigned int, std::string>> roman {
	{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
	{90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
	{4, "IV"}, {1, "I"}
};

std::string to_roman(unsigned int numb){
	std::string result;
	for (auto const & elem : roman){
		while (numb >= elem.first){
			result += elem.second;
			numb -= elem.first;
		}
	}
	
	return result;
}


int main(){
	int number;
	
	for (int i = 0; i < 101; i++){
		std::cout << i << " - "<< to_roman(i) << std::endl; 
	}
	std::cout << "Enter a number: ";
	std::cin >> number;
	
	std::cout << "Your number in roman: " << to_roman(number) << std::endl;
	return 0;
	
}
