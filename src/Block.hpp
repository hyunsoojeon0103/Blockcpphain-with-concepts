#include <cstdint>
#include <iostream>

using namespace std;

class Block
{
public:
    string s_prev_hash;
    string get_hash();
    void mine_block(uint32_t n_dfficulty);
    Block(uint32_t n_index_in, const string &s_data_in);

private:
    uint32_t n_index;
    int64_t n_nonce;
    string s_data;
    string s_hash;
    time_t t_time;

    string calculate_hash() const;
};