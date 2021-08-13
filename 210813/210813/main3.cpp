#include <iostream>
#include <fstream>

int main()
{
	std::ofstream write;
	write.open("Stream.txt");

	if (write.is_open())
	{
		char Text[128] = {};

		strcat_s(Text, "마마마마마마");

		write.write(Text, strlen(Text));
	}

	write.close();

	// ifstream: 파일을 읽을때 사용한다.
	std::ifstream read;

	read.open("Stream.txt");

	if (read.is_open())
	{
		while (!read.eof())
		{
			char Text[128] = {};
			read.getline(Text, 128);

			std::cout << Text << std::endl;
		}
	}

	read.close();

	return 0;
}