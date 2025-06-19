#include <iostream>

int main(void)
{
	// AND & ->takes the 1 that is in both numbers
	int and_0_0 = 0 & 0; // 0000 & 0000 = 0000
	int and_0_1 = 0 & 1; // 0000 & 0001 = 0000
	int and_1_0 = 1 & 0; // 0001 & 0000 = 0000
	int and_1_1 = 1 & 1; // 0001 & 0001 = 0001

	std::cout << "  AND" << std::endl;
	std::cout << " 0 & 0 | " << and_0_0 << std::endl;
	std::cout << " 0 & 1 | " << and_0_1 << std::endl;
	std::cout << " 1 & 0 | " << and_1_0 << std::endl;
	std::cout << " 1 & 1 | " << and_1_1 << std::endl;

	std::cout << "___________\n" << std::endl;

	// OR | ->takes the 1 that is in any of the numbers
	int or_0_0 = 0 | 0; // 0000 | 0000 = 0000
	int or_0_1 = 0 | 1; // 0000 | 0001 = 0001
	int or_1_0 = 1 | 0; // 0001 | 0000 = 0001
	int or_1_1 = 1 | 1; // 0001 | 0001 = 0001

	std::cout << "  OR" << std::endl;
	std::cout << " 0 | 0 | " << or_0_0 << std::endl;
	std::cout << " 0 | 1 | " << or_0_1 << std::endl;
	std::cout << " 1 | 0 | " << or_1_0 << std::endl;
	std::cout << " 1 | 1 | " << or_1_1 << std::endl;

	std::cout << "___________\n" << std::endl;

	// XOR ^ ->takes the 1 that is in only 1 of the numbers
	int xor_0_0 = 0 ^ 0; // 0000 ^ 0000 = 0000
	int xor_0_1 = 0 ^ 1; // 0000 ^ 0001 = 0001
	int xor_1_0 = 1 ^ 0; // 0001 ^ 0000 = 0001
	int xor_1_1 = 1 ^ 1; // 0001 ^ 0001 = 0000

	std::cout << "  XOR" << std::endl;
	std::cout << " 0 ^ 0 | " << xor_0_0 << std::endl;
	std::cout << " 0 ^ 1 | " << xor_0_1 << std::endl;
	std::cout << " 1 ^ 0 | " << xor_1_0 << std::endl;
	std::cout << " 1 ^ 1 | " << xor_1_1 << std::endl;

	std::cout << "___________\n" << std::endl;

	// NOT ~ ->flips the bytes, if it's a 1 is a 0  and the other way around
	int not_0 = ~0; // ~ 0000 = 1111
	int not_1 = ~1; // ~ 0001 = 1110

	std::cout << "    NOT" << std::endl;
	std::cout << " ~ 0 | " << not_0 << std::endl;
	std::cout << " ~ 1 | " << not_1 << std::endl;

	std::cout << "___________\n" << std::endl;

	// Left Shift << ->moves the bits one place to the left (*2)
	int left_shift_1 = 1 << 1; // 0001 << 1 = 0010
	int left_shift_2 = 1 << 2; // 0001 << 2 = 0100

	std::cout << " Left Shift" << std::endl;
	std::cout << " 1 << 1 | " << left_shift_1 << std::endl;
	std::cout << " 1 << 2 | " << left_shift_2 << std::endl;

	std::cout << "___________\n" << std::endl;

	// Left Right << ->moves the bits one place to the right (/2)
	int right_shift_1 = 2 >> 1; // 0010 >> 1 = 0001
	int right_shift_2 = 4 >> 2; // 0100 >> 2 = 0001

	std::cout << " Right Shift" << std::endl;
	std::cout << "2 >> 1 | " << right_shift_1 << std::endl;
	std::cout << "4 >> 2 | " << right_shift_2 << std::endl;

	std::cout << "___________\n" << std::endl;

}