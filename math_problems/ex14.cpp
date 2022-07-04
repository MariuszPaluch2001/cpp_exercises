#include <iostream>
#include <algorithm>
#include <numeric>
bool is_isbn_10_correct(std::string isbn_code){
	bool is_validate = false;
	
	if (isbn_code.size() == 10 && std::count_if(std::begin(isbn_code), std::end(isbn_code), isdigit) == 10){
		auto w = 10;
		auto sum = std::accumulate(std::begin(isbn_code), std::end(isbn_code), 0, [&w] (int const total, char const c) {return total + w-- * (c - '0');});
		is_validate = !(sum % 11);
	}
	
	return is_validate;

}

int main(){
	std::cout << "Is 0-306-40615-2 validate? " << is_isbn_10_correct("0306406152") << std::endl;
}
