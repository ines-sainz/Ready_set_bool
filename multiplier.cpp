#include <iostream>
#include <cstdint>

// int32_t : standard 32-bit integer in <cstdint> c++ and <stdint.h> in c
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


// 2  0010
// 3  0011
// +
// 5  0101


// 5  0101
// 3  0011
// +
// 8  1000

//           5      3       6
// 1º-> XOR 0101 ^ 0011 = 0110
//           5      3       1                  2
// 2º-> AND 0101 & 0011 = 0001 -> SHIFT LEFT 0010

//           6      2       4
// 3º-> XOR 0110 ^ 0010 = 0100
//           6      2       2                  4
// 4º-> AND 0110 & 0010 = 0010 -> SHIFT LEFT 0100

//           4      4       0
// 5º-> XOR 0100 ^ 0100 = 0000
//           4      4       4                  8
// 6º-> AND 0100 & 0100 = 0100 -> SHIFT LEFT 1000

//           0      8       8
// 7º-> XOR 0000 ^ 1000 = 1000
//           0      8       0
// 8º-> AND 0000 & 1000 = 0000 ->CARRY IS 0 -> RESULT = 8