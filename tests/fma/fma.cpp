//-mfma
//-ffp-contract=fast option to allow generation of FMA instructions
//-ffp-contract=off to disallow generation of FMA instructions

#include <iostream>
#include <cmath>

int main (void)
{
	printf("si fma %f\n", std::fma(2.0, 3.0, 4.0));
	printf("no fma %f\n", 2.0 * 3.0 + 4.0);
}
