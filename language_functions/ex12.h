#include <array>
#include <iostream>
#include <sstream>      // std::stringstream

#ifndef IPV4
#define IPV4
class ipv4 {
private:
	std::array<unsigned char, 4> address;
public:
	constexpr ipv4() : address{{0}} {}
	constexpr ipv4(unsigned char const a,unsigned char const b,
	               unsigned char const c,unsigned char const d) : address{{a,b,c,d}} {}
	explicit constexpr ipv4(unsigned long a) : address{{static_cast<unsigned char>((a >> 24) & 0xFF),
	                                                    static_cast<unsigned char>((a >> 16) & 0xFF),
	                                                    static_cast<unsigned char>((a >> 8) & 0xFF),
	                                                    static_cast<unsigned char>(a & 0xFF) } } {}
	
	ipv4(ipv4 const & other) noexcept : address(other.address) {}
	
	ipv4& operator=(ipv4 const  & other) noexcept;
	
	ipv4& operator++();
	
	ipv4& operator++(int);
	
	std::string to_string() const;
	
	constexpr unsigned long to_unsigned_long() const noexcept;

	friend std::ostream& operator<<(std::ostream& os, ipv4 const & a){
		os << static_cast<int>(a.address[0]) << '.'
		   << static_cast<int>(a.address[1]) << '.'
		   << static_cast<int>(a.address[2]) << '.'
		   << static_cast<int>(a.address[3]);
		return os;
	};
	
	friend std::istream& operator>>(std::istream& is, ipv4& a){
		char sep1, sep2, sep3;
		int n1, n2, n3, n4;
		is >> n1 >> sep1 >> n2 >> sep2 >> n3 >> sep3 >> n4;
		if (sep1 == '.' && sep2 == '.' && sep3 == '.')
			a = ipv4(n1,n2,n3,n4);
		else
			is.setstate(std::ios_base::failbit);
		return is;
	};

	friend bool operator==(ipv4 const  & ip1, ipv4 const  & ip2) noexcept{
		return ip1.address == ip2.address;
	};
	
	friend bool operator!=(ipv4 const  & ip1, ipv4 const  & ip2) noexcept{
		return ip1.address != ip2.address;
	};
	
	friend bool operator>(ipv4 const  & ip1, ipv4 const  & ip2) noexcept{
		return ip1.to_unsigned_long() > ip2.to_unsigned_long();
	};
	
	friend bool operator<(ipv4 const  & ip1, ipv4 const  & ip2) noexcept{
		return ip2 > ip1;
	};
	
	friend bool operator>=(ipv4 const  & ip1, ipv4 const  & ip2) noexcept{
		return !(ip1 < ip2);
	};
	
	friend bool operator<=(ipv4 const  & ip1, ipv4 const  & ip2) noexcept{
		return !(ip1 > ip2);
	};
};

#endif
