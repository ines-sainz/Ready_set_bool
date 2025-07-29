#include <iostream>
#include <cstdint>

// uint32_t : standard 32-bit unsigned integer in <cstdint> c++ and <stdint.h> in c
// MAX 4294967295

//Time complexity: N/A →  Not Applicable or Not Assessed
//Space complexity: N/A →  Not Applicable or Not Assessed

auto gray_code = [](uint32_t num)
{
    uint32_t    result = 0;

    result = num ^ (num >> 1);
	return (result);
};

int main(void)
{
	uint32_t num = 7;

	std::cout << num << " gray code -> " << gray_code(7) << std::endl;
}

// Gray Code (reflected binary code) -> only one bit changes between two consecutive values

// result = n ^ (n >> 1)
//   
// 10->     1010
//       ^
// 10 >> 1  0101
//        --------
// 15->     1111

// 0    0000
// 1	0001
// 2	0011
// 3	0010
// 4	0110
// 5	0111
// 6	0101
// 7	0100
// 8	1100
// 9	1101
// 10	1111
// 11	1110
// 12	1010
// 13	1011
// 14	1001
// 15	1000