#include <iostream>
#include <cmath>
void print_amstrong_numbers(){
	int numb;
	int sum_cub_numb;
	for (int a = 1; a < 10; a++){
		for (int b = 0; b < 10; b++){
			for (int c = 0; c < 10; c++){
				numb = 100 * a + 10 * b + c;
				sum_cub_numb = pow(a,3) + pow(b,3) + pow(c,3);
				if (numb == sum_cub_numb)
					std::cout << numb << std::endl;
			}
		}
	}
}

int main(){
	std::cout << "Amstrong numbers list: " << std::endl;
	print_amstrong_numbers();
	return 0;
}
