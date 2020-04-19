#include "Block.h"

Block::Block()
    : n_index(0), n_nonce(-1), t_time(time(nullptr)), s_data("Genesis Block"), s_prev_hash("0")
{
}
Block::Block(const std::string &s_data_in)
    : n_index(0), n_nonce(-1), t_time(time(nullptr)), s_data(s_data_in)
{
}
Block::~Block()
{
}
std::string Block::get_hash() const
{
    return s_hash;
}
void Block::set_prev_hash(const std::string &prev_hash)
{
    assert(prev_hash.length() == 64 || prev_hash == "0");
    s_prev_hash = prev_hash;
}
std::string Block::get_prev_hash() const
{
    return s_prev_hash;
}
uint32_t Block::get_index() const
{
    return n_index;
}
void Block::set_n_index(const uint32_t idx)
{
    assert(idx >= 0);
    n_index = idx;
}
void Block::mine_block(const uint32_t n_difficulty)
{
    assert(n_difficulty >= 0 && n_difficulty < 64);
    std::string str(n_difficulty, '0');
    do
    {
        n_nonce++;
        s_hash = calculate_hash();
    } while (s_hash.substr(0, n_difficulty) != str);
}

std::string Block::calculate_hash() const
{
    std::stringstream str_stream;
    str_stream << n_index << t_time << s_data << n_nonce << s_prev_hash;
    return sha256(str_stream.str());
}

std::ostream &operator<<(std::ostream &out, const Block &block)
{
    out << "n_index       : " << block.n_index << '\n'
        << "n_nonce       : " << block.n_nonce << '\n'
        << "t_time        : " << block.t_time << '\n'
        << "data          : " << block.s_data << '\n'
        << "hash          : " << block.s_hash << '\n'
        << "previous hash : " << block.s_prev_hash << '\n';
    return out;
}