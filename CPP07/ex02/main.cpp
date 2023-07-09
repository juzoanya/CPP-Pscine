
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cout << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	std::cout << "///////////////////////////////////" << std::endl;


	// Construction with no parameter
	Array<int> emptyArray;
	std::cout << "Empty Array size: " << emptyArray.size() << std::endl;

	// Construction with unsigned int n as a parameter
	Array<int> intArray(5);
	std::cout << "Int Array size: " << intArray.size() << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i) {
		std::cout << "intArray[" << i << "]: " << intArray[i] << std::endl;
	}

	// Construction by copy and assignment operator
	Array<int> copyArray(intArray);
	Array<int> assignedArray;
	assignedArray = intArray;

	// Modifying the original array after copying
	intArray[2] = 42;

	// Displaying the modified and copied arrays
	std::cout << "Modified intArray[2]: " << intArray[2] << std::endl;
	std::cout << "copyArray[2]: " << copyArray[2] << std::endl;
	std::cout << "assignedArray[2]: " << assignedArray[2] << std::endl;
	return 0;
}