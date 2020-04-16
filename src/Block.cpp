#include "Block.hpp"
#include "sha256.hpp"
#include <sstream>

Block::Block(uint32_t n_index_in, const string &s_data_in) : n_index(n_index_in), s_data(s_data_in)
{
    n_nonce = -1;
    t_time = time(nullptr);
}

string Block::get_hash()
{
    return s_hash;
}

void Block::mine_block(uint32_t n_difficulty)
{
    char cstr[n_difficulty + 1];

    for (uint32_t i = 0; i < n_difficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[n_difficulty] = '\0';

    string str(cstr);

    do
    {
        n_nonce++;
        s_hash = calculate_hash();

    } while (s_hash.substr(0, n_difficulty) != str);

    cout << "Block mined: " << s_hash << endl;
}

inline string Block::calculate_hash() const
{
    stringstream str_stream;

    str_stream << n_index << t_time << s_data << n_nonce << s_prev_hash;

    return sha256(str_stream.str());
}