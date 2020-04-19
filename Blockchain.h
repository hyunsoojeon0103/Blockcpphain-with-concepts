#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "Block.h"
#include "json.hpp"

class Blockchain
{
public:
    Blockchain(const uint32_t difficulty = 6);
    ~Blockchain();
    void add_block(Block b_new);
    void set_n_difficulty(const uint32_t difficulty);
    uint32_t get_n_difficulty() const;
    size_t size() const;
    Block &operator[](const uint32_t idx);
    const Block &operator[](const uint32_t idx) const;
    std::vector<Block>::iterator begin();
    std::vector<Block>::iterator end();
    std::vector<Block>::const_iterator cbegin() const;
    std::vector<Block>::const_iterator cend() const;
    bool valid() const;
    friend std::ostream &operator<<(std::ostream &out, const Blockchain &bc);

private:
    std::vector<Block> v_chain;
    uint32_t n_difficulty;
    Block get_last_block() const;
};