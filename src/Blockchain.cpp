#include "Blockchain.hpp"

Blockchain::Blockchain()
{
    v_chain.emplace_back(Block(0, "Genesis Block"));
    n_difficulty = 6;
}

void Blockchain::add_block(Block b_new)
{
    b_new.s_prev_hash = get_last_block().get_hash();
    b_new.mine_block(n_difficulty);
    v_chain.push_back(b_new);
}

Block Blockchain::get_last_block() const
{
    return v_chain.back();
}