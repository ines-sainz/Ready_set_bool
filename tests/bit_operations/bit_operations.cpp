#include <iostream>

int main(void)
{
	// AND & ->takes the 1 that is in both numbers
	int and_0_0 = 0 & 0; // 0000 & 0000 = 0000
	int and_0_1 = 0 & 1; // 0000 & 0001 = 0000
	int and_1_0 = 1 & 0; // 0001 & 0000 = 0000
	int and_1_1 = 1 & 1; // 0001 & 0001 = 0001

	std::cout << " AND" << std::endl;
	std::cout << "0 & 0 | " << and_0_0 << std::endl;
	std::cout << "0 & 1 | " << and_0_1 << std::endl;
	std::cout << "1 & 0 | " << and_1_0 << std::endl;
	std::cout << "1 & 1 | " << and_1_1 << std::endl;


}