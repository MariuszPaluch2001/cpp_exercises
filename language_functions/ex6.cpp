#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

template <class C, typename T>
bool contain(C const & c, T const & value){
	return std::find(std::begin(c), std::end(c), value) != std::end(c);
}

template <class C, typename... T>
bool contain_all(C const & c, T &&... value){
	return (... && contain(c, value));
}

template <class C, typename... T>
bool contain_any(C const & c, T &&... value){
	return (... || contain(c, value));
}

template <class C, typename... T>
bool contain_none(C const & c, T &&... value){
	return !contain_any(c, std::forward<T>(value)...);
}

int main(){
	std::vector<int> v{1,2,3,4,5,6,7};
	
	assert(contain_all(v, 1,2,3));
	assert(contain_any(v, 1,8,12));
	assert(contain_none(v, -1,-2,-3));
	return 0;
}
