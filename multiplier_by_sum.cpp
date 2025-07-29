#include <iostream>
#include <cstdint>

// uint32_t : standard 32-bit integer in <cstdint> c++ and <stdint.h> in c
// MAX 4294967295

//Time complexity: O(1) → Your solution must finish in constant time,
// not grow with input size.
//Space complexity: O(1) → You can’t use extra memory like arrays or big data structures.

auto multiplier = [](uint32_t num1, uint32_t num2)
{
	uint32_t	times = 0;
	uint32_t	xor_n;
	uint32_t	carry = 1;
	uint32_t	copy = num2;
	uint32_t	copy2 = num1;
	uint32_t	result = num2;

	if (num1 == 0)
		return (num1);
	while (times < num1 - 1)
	{
		carry = 1;
		while (carry != 0)
		{
			xor_n = result ^ num2;
			carry = result & num2;
			if (carry == 0)
			{
				break;
			}
			carry = carry << 1;
			result = xor_n;
			num2 = carry;
		}
		result = xor_n;
		num2 = copy;
		times++;
	}
	return (result);
};

int main(void)
{
	uint32_t num1 = 0;
	uint32_t num2 = 5;

	std::cout << num1 << " * " << num2 << " = " << multiplier(num1, num2) << std::endl;
}

// 5  0101
// 3  0011
// *
// 15  1000

// RESULT = 0
// 0 + 5 = 5
// 5 + 5 = 10
// 10 + 5 = 15