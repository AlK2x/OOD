#include <iostream>
#include <string>
#include <cstdint>
#include "MemoryInputStream.h"

using namespace std;

int main()
{
	CMemoryInputStream str({1,2,3,4,5,6,41,42,43});
	std::cout << str.ReadByte() << std::endl;
	std::cout << str.ReadByte() << std::endl;
	std::cout << str.ReadByte() << std::endl;
	std::cout << str.ReadByte() << std::endl;
	std::cout << str.ReadByte() << std::endl;
	std::cout << str.ReadByte() << std::endl;
	std::cout << str.ReadByte() << std::endl;
	std::cout << str.ReadByte() << std::endl;
	std::cout << str.ReadByte() << std::endl;
	return 0;
}