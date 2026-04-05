#include "bencode.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "sha1.hpp"
#include <set>
#include <algorithm>


int main(){
		

			
		

		
		std::ifstream input( "bunny.torrent", std::ios::binary );	
		

		 	
			
		
		std::vector<char> buffer(std::istreambuf_iterator<char>(input), {});	
		std::string raw(buffer.begin(), buffer.end());
		auto info_pos = raw.find("4:infod") + 6;

	
		std::cout << "info posiiton:" << info_pos << std::endl;

		bencode::data data = bencode::decode(raw);
		auto& root = std::get<bencode::dict>(data);

		auto& info = std::get<bencode::dict>(root.at("info"));
		
		std::string info_bencoded = bencode::encode(info);

		SHA1 sha1;
		sha1.update(info_bencoded);
		std::string hash = sha1.final();
		

	
	
		
		

		
		
/*		


		bencode::data data = bencode::decode(contents);
		auto& root = std::get<bencode::dict>(data);

		auto& created_by = std::get<bencode::string>(root.at("created by"));
		std::cout << "created by : " << created_by << std::endl;

		auto& creation_date = std::get<bencode::integer>(root.at("creation date"));
		std::cout << "creation date : " << creation_date << std::endl;

		auto& encoding = std::get<bencode::string>(root.at("encoding"));
		std::cout << "encoding: " << encoding << std::endl;


			*/
		



		
		return 0;

}
