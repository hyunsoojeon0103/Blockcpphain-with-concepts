#include <cstdint>
#include <vector>
#include "Block.hpp"

using namespace std;

class Blockchain
{
public:
    Blockchain();

    void add_block(Block b_new);

private:
    uint32_t n_difficulty;
    vector<Block> v_chain;

    Block get_last_block() const;
};