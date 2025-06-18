//[capture-clause] (parameters) -> return-type { 
//    // definition
//}

#include <iostream>

int main(void)
{
	//lamda without parameters
	auto	hi = []() {
		std::cout << "without parameters and capture variables: Hi!" << std::endl;
	};
	hi();

	//lamda without parameters by value
	int w=44;
	auto	no_val = [=]() {
		std::cout << "No param by value: w = " << w << std::endl;
	};
	w=1;
	no_val();


	//lamda without parameters by reference
	int x=44;
	auto	no_ref = [&]() {
		std::cout << "No param by reference: x = " << x << std::endl;
	};
	x=1;
	no_ref();

	//lambda with parameters
	int i = 2;
	auto	num_param = [](int i) {
		std::cout << "with parameters: num = " << i << std::endl;
	};
	i = 3;
	num_param(2);

	//lamda with capture variables by value
	int j = 3;
	auto	num_value = [j]() {
		std::cout << "value: j = " << j << std::endl;
	};
	j = 5;
	num_value();

	//lambda with capture variables by reference
	int k = 4;
	auto	ref = [&k]() {
		std::cout << "reference with variables: k = " << k << std::endl;
	};
	k = 7;
	ref();

	//lambda with values by capture reference
	int l = 2;
	auto	ref_val = [&](int l) {
		std::cout << "reference with values: l = " << l << std::endl;
	};
	l = 4;
	ref_val(l);

	//lambda with everything by value but n by reference
	int m = 5;
	int n = 5;
	auto	everything_val = [=, &n]() {
		std::cout << "everything by value: m = " << m << " n = " << n << std::endl;
	};
	m = 9;
	n = 9;
	everything_val();

}