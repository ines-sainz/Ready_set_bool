#include <iostream>
#include <cstdint>

// int32_t : standard 32-bit integer in <cstdint> c++ and <stdint.h> in c
// MAX 4294967295

//Time complexity: O(1) → Your solution must finish in constant time,
// not grow with input size.
//Space complexity: O(1) → You can’t use extra memory like arrays or big data structures.

auto adder = [](uint32_t num1, uint32_t num2)
{
	uint32_t	xor_n;
	uint32_t	carry = 1;
	while (carry != 0)
	{
		xor_n = num1 ^ num2;
		carry = num1 & num2;
		if (carry == 0)
		{
			return (xor_n);
		}
		carry = carry << 1;
		num1 = xor_n;
		num2 = carry;
	}
	return (xor_n);
};

auto multiplier = [](uint32_t num1, uint32_t num2)
{
	uint32_t	result = 0;

	while (num2 != 0)
	{
		if (num2 & 1)
			result = adder(result, num1);
		num1 = num1 << 1;
		num2 = num2 >> 1;
	}
	return (result);
};

int main(void)
{
	uint32_t num1 = 7;
	uint32_t num2 = 6;

	std::cout << num1 << " * " << num2 << " = " << multiplier(num1, num2) << std::endl;
}

// 01 & 1 = 1
// 00 & 1 = 0
// 10 & 10 = 1
// 01 & 10 = 0
// 100 & 100 = 1
// 011 & 100 = 0

// 5  0101
// 3  0011
// *
// 15 1111

//    0101
// *  0011
// ---------
//    0101
//   0101
//  0000
// 0000
// ---------
// 0001111

// RESULT = 0;
//           3     1   1
// 1º-> AND 0011 & 1 = 1
//          RES     5      5
// 2º-> SUM  0 '+' 0101 = 0101
//       3
// 3º-> 0011 -> SHIFT RIGHT 0001
//       5
// 4º-> 0101 -> SHIFT LEFT 01010

//           >>3
// 5º-> AND 0001 & 1 = 1
//          RES        5<<
// 6º-> SUM 0101 '+' 01010 = 1111
//       >>3
// 7º-> 0001 -> SHIFT RIGHT 0000
//         <<5
// 8º-> 01010 -> SHIFT LEFT 010100

//            >>3
// 9º-> AND 0000 & 1 = 0
//       >>3
// 10º-> 0000 -> SHIFT RIGHT 0000
//         <<5
// 11º-> 010100 -> SHIFT LEFT 0101000

//            >>3
// 12º-> AND 0000 & 1 = 0
//       >>3
// 13º-> 0000 -> SHIFT RIGHT 0000
//         <<5
// 14º-> 0101000 -> SHIFT LEFT 01010000

//           15
// RESULT = 1111