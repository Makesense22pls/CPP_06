#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
	Data test;
	test.id = 67;
	test.name = "Test";
	test.value = 3.21;

	std::cout << "Original pointer: " << &test << std::endl;
	
	uintptr_t serialized = Serializer::serialize(&test);
	std::cout << " After serializer (int):  " << serialized << std::endl;
	
	Data	*deserialized = Serializer::deserialize(serialized);
	std::cout << " After deserialized :  " << deserialized << std::endl;

	return (0);
}
