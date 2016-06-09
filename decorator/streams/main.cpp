#include <iostream>
#include <string>
#include <cstdint>
#include "MemoryInputStream.h"
#include "FileInputStream.h"

using namespace std;

int main()
{
	/*CMemoryInputStream str({1,2,3,4,5,6,41,42,43});
	std::cout << str.ReadByte() << std::endl;
	std::cout << str.ReadByte() << std::endl;
*/

	std::ifstream ifs("input.txt", std::ifstream::binary | std::fstream::out);
	CFileInputStream fStream(ifs);

	try
	{
		char * str = new char[10];
		while (!fStream.IsEOF())
		{
			std::streamsize s = fStream.ReadBlock((void*)str, 10);
			std::cout << s << std::endl;
			std::cout << str << std::endl;
		}
	}
	catch (std::ios_base::failure & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unexpected error" << std::endl;
	}

	return 0;
}