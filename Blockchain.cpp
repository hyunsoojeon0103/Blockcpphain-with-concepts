#include "Blockchain.h"
Blockchain::Blockchain(const uint32_t difficulty)
    : n_difficulty(difficulty)
{
    add_block(Block());
}

Blockchain::~Blockchain()
{
}
void Blockchain::add_block(Block b_new)
{
    b_new.mine_block(n_difficulty);
    b_new.set_prev_hash(v_chain.size() > 0 ? get_last_block().get_hash() : "0");
    b_new.set_n_index(v_chain.size());
    v_chain.push_back(b_new);
}
void Blockchain::set_n_difficulty(const uint32_t difficulty)
{
    assert(difficulty >= 0 && difficulty < 64);
    n_difficulty = difficulty;
}
uint32_t Blockchain::get_n_difficulty() const
{
    return n_difficulty;
}
size_t Blockchain::size() const
{
    return v_chain.size();
}
Block &Blockchain::operator[](const uint32_t idx)
{
    assert(idx < v_chain.size());
    return v_chain[idx];
}
const Block &Blockchain::operator[](const uint32_t idx) const
{
    assert(idx < v_chain.size());
    return v_chain[idx];
}
std::vector<Block>::iterator Blockchain::begin()
{
    return v_chain.begin();
}
std::vector<Block>::iterator Blockchain::end()
{
    return v_chain.end();
}
std::vector<Block>::const_iterator Blockchain::cbegin() const
{
    return v_chain.begin();
}
std::vector<Block>::const_iterator Blockchain::cend() const
{
    return v_chain.end();
}
bool Blockchain::valid() const
{
    std::string difficulty(n_difficulty, '0');
    std::string prevHash = "0";
    uint32_t n = 0;
    for (auto &block : v_chain)
    {
        /* generate hash out of the block and compare*/
        auto curr = block.get_hash();
        auto prev = block.get_prev_hash();
        if (curr.substr(0, n_difficulty) != difficulty ||
            block.get_index() != n || prevHash != prev)
            return false;
        prevHash = curr;
    }
    return true;
}
Block Blockchain::get_last_block() const
{
    return v_chain.back();
}
std::ostream &operator<<(std::ostream &out, const Blockchain &bc)
{
    for (size_t i = 0; i < bc.size(); ++i)
        out << bc[i] << (i != bc.size() - 1 ? "\n" : "");
    return out;
}
