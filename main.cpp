#include "laba17.h"


int main() {
	Set<int> set_1(5);
	std::cout << "Size of integer set 1: " << set_1.size() << std::endl;;
	set_1.insert(2);
	set_1.insert(456);
	set_1.insert(476);
	set_1.insert(258);
	set_1.insert(123);
	set_1.insert(448);
	set_1.insert(45);
	std::cout << "Integer set 1:\n" << set_1;
	Set<int> set_2(2);
	std::cout << "Size of integer set 2: " << set_2.size() << std::endl;;
	set_2.insert(1);
	set_2.insert(780);
	std::cout << "Integer set 2:\n" << set_2;
	Set<int> set_3(5);
	set_3 = set_1.unions(set_2);
	std::cout << "Integer set 1 union set 2:\n" << set_3;
	Set<int> set_4(10);
	try {
		set_3 = set_4.unions(set_2);
	}
	catch (const char *str) {
		std::cout << "Error: " << str << std::endl;
	}
}