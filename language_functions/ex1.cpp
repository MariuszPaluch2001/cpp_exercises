#include "ex1.h"

ipv4& ipv4::operator=(ipv4 const & other) noexcept{
		address = other.address;
		return *this;
}

std::string ipv4::to_string() const{
	std::stringstream str_stream;
	str_stream << *this;
	return str_stream.str();
}

constexpr unsigned long ipv4::to_unsigned_long() const noexcept{
		return ((static_cast<unsigned long>(address[0]) << 24) |
		        (static_cast<unsigned long>(address[1]) << 16) | 
		        (static_cast<unsigned long>(address[2]) << 8)  |
		        static_cast<unsigned long>(address[3]));
	};

int main(){
	ipv4 a(192,0,0,1);
	std::string str = a.to_string();
	std::cout << str << std::endl;
	std::cout << a.to_unsigned_long() << std::endl; //3221225473 - 11000000000000000000000000000001 - 192.0.0.1
	ipv4 b(4028803073); // 240.34.168.1 - 11110000001000101010100000000001 - 4028803073
	std::cout << b << std::endl; 
	std::cout << b.to_unsigned_long() << std::endl;
	return 0;
}
