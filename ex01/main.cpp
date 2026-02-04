#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
	Data data;
	data.id = 42;
	data.name = "Test";
	data.value = 3.14;

	std::cout << "Original pointer: " << &data << std::endl;
	
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized (int):  " << serialized << std::endl;
	
	Data	*deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized ptr:  " << deserialized << std::endl;

	return (0);
}
