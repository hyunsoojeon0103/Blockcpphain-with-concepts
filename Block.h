#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <cassert>
#include "sha256.h"
#include "json.hpp"

class Block
{
public:
    Block();
    Block(const std::string &s_data_in);
    ~Block();
    std::string get_hash() const;
    std::string get_prev_hash() const;
    uint32_t get_index() const;
    void set_prev_hash(const std::string &prev_hash);
    void set_n_index(const uint32_t idx);
    void mine_block(const uint32_t n_dfficulty);
    friend std::ostream &operator<<(std::ostream &out, const Block &block);
private:
    uint32_t n_index;
    int64_t n_nonce;
    time_t t_time;
    std::string s_data;
    std::string s_hash;
    std::string s_prev_hash;
    std::string calculate_hash() const;
};