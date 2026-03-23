#include "bencode.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int main(){
		
		
		std::ifstream input( "bunny.torrent", std::ios::binary );	
		 	
		std::stringstream buffer;
		buffer << input.rdbuf();
		std::string contents = buffer.str();

		bencode::data data = bencode::decode(contents);
		auto& root = std::get<bencode::dict>(data);

		auto& created_by = std::get<bencode::string>(root.at("created by"));
		std::cout << "created by : " << created_by << std::endl;

		auto& creation_date = std::get<bencode::integer>(root.at("creation date"));
		std::cout << "creation date : " << creation_date << std::endl;

		auto& encoding = std::get<bencode::string>(root.at("encoding"));
		std::cout << "encoding: " << encoding << std::endl;

		

		auto& info = std::get<bencode::dict>(root.at("info"));
		for (auto& [key,value]: info){
				std::cout << key << std::endl;
		}
		return 0;

}
