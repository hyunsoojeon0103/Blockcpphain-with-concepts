#include <iostream>
#include <string>
#include "Block.h"
#include "Blockchain.h"
#include "sha256.h"
#include "json.hpp"
#include "uint256.h"

using Json = nlohmann::json;

int main()
{
    typedef uint256 T;
    //typedef uint160 T;
    /* TODO 
     * 
     * 1) Make it into a tunable template with different SHA functions
     * If Blockchain class somehow can have sha function stored in a pointer
     * That would be ideal. Refer to vim ./sandbox/main.cpp
     * Now, calculate_hash() function uses the global SHA256
     *
     * 
     * 3) launch all of these chains onto a network so that
     * nodes can talk to each other and identify the longest
     * blockchain and implement broadcast()
     *
     */
    // make it tunable with differnet sha fuc
    typedef Blockchain<T> Chain;
    typedef Block<T> Block;
     
    Chain bc(1);
     
    bc.add_block(Block("Test Block 1"));
    bc.add_block(Block("Test Block 2"));
    bc.add_block(Block("Test Block 3"));
    
	std::cout << bc;
    
	return 0;
}
