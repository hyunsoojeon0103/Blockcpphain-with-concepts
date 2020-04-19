#include <iostream>
#include "Block.h"
#include "Blockchain.h"
#include "sha256.h"
#include "json.hpp"

using Json = nlohmann::json;

int main()
{
	Blockchain bc(1);

	bc.add_block(Block("Test Block 1"));
	bc.add_block(Block("Test Block 2"));
	bc.add_block(Block("Test Block 3"));

	std::cout << bc;

	Json json;

	json["string"] = "hello world";
    json["int"] = 5;
    json["bool"] = false;
	json["double"] = 5.8;

	std::cout << json << '\n';

	return 0;
}
