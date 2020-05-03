#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <cassert>
#include "sha256.h"
#include "json.hpp"
#include "uint256.h"

template <class T>
class Block
{
public:
    Block(const std::string &s_data_in = std::string());
    ~Block();
    T get_hash() const;
    T get_prev_hash() const;
    uint64_t get_index() const;
    void set_prev_hash(const T prev_hash);
    void set_n_index(const uint64_t idx);
    void mine_block(const uint64_t n_dfficulty);
    template <class U>
    friend std::ostream& operator <<(std::ostream& out, const Block<U>& block);
private:
    T byte_size;
    T hash;
    T prev_hash;
    uint64_t n_index;
    uint64_t t_time;
    uint64_t n_nonce;
    T calculate_hash() const;
};
#include "Block.cpp"
