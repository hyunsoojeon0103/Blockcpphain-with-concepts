#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "Block.h"
#include "json.hpp"
#include "uint256.h"
template <class T>
class Blockchain
{
public:
    Blockchain(const uint64_t difficulty = 6);
    ~Blockchain();
    void add_block(Block<T> b_new);
    void set_n_difficulty(const uint64_t difficulty);
    uint64_t get_n_difficulty() const;
    size_t size() const;
    Block<T>& operator[](const uint64_t idx);
    const Block<T>& operator[](const uint64_t idx) const;
    std::vector<Block<T>>::iterator begin();
    std::vector<Block<T>>::iterator end();
    std::vector<Block<T>>::const_iterator cbegin() const;
    std::vector<Block<T>>::const_iterator cend() const;
    bool valid() const;
    template <class U>
    friend std::ostream& operator<<(std::ostream& out, const Blockchain<U>& bc);

private:
    std::vector<Block<T>> v_chain;
    uint64_t n_difficulty;
    Block<T> get_last_block() const;
};
#include "Blockchain.cpp"
