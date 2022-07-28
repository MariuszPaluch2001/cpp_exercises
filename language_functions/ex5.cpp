#include <vector>
#include <iostream>
#include <iterator>
template<class C, typename... Args>
void push_back(C& c, Args&&... args){
	(c.push_back(args), ...);
} 
int main(){
	std::vector<int> v;
	push_back(v, 1,2,3,4,5);
	std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}
