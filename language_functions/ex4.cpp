#include <iostream>

template<typename T>
T minimum(T arg1, T arg2){
	if (arg1 > arg2)
		return arg2;
	else
		return arg1;
}

template<typename T, typename... Args>
T minimum(T t, Args... args){
	return minimum(t, minimum(args...));
}

template<class Comp, typename T>
T bin_minimum(Comp cmp, T arg1, T arg2){
	if (cmp(arg1, arg2))
		return arg1;
	else
		return arg2;
}

template<class Comp, typename T, typename... Args>
T bin_minimum(Comp cmp, T t, Args... args){
	return bin_minimum(cmp,t, bin_minimum(cmp, args...));
}
int main(){
	std::cout << "Min value: " << minimum(1,2,3,4,5,-1) << std::endl;
	std::cout << "Binary min value: " << bin_minimum(std::less<>(), 1,2,3,4,5,-1) << std::endl;
	return 0;
}
