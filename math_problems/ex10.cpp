#include <iostream>
#include <bitset>

unsigned int gray_encode(unsigned int const number){	
	return number ^ (number >> 1);
}

unsigned int gray_decode(unsigned int gray){
	for (unsigned int bit = 1U << 31; bit > 1; bit >>= 1){
		if (gray & bit) gray ^= bit >> 1;
	}
	
	return gray;
}

std::string convert_to_binary(unsigned int value, int const digits){
	return std::bitset<32>(value).to_string().substr(32 - digits, digits);
}

int main(){
	
	for (unsigned int n= 0; n < 32; ++n){
		auto enc = gray_encode(n);
		auto dec = gray_decode(enc);
		
		std::cout << n << " " << convert_to_binary(n,5) << " " 
		<< convert_to_binary(enc,5)<< " " << dec << std::endl;
	}
	return 0;
}
