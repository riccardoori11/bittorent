#include "bencode.hpp"
#include <iostream>

int main(){

		bencode::data data = bencode::decode("i42e");	
		std::cout << std::get<bencode::integer>(data) << std::endl;
		
		return 0;

}
