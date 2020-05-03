template <class T>
Blockchain<T>::Blockchain(const uint64_t difficulty)
    : n_difficulty(difficulty)
{
    add_block(Block<T>());
}

template <class T>
Blockchain<T>::~Blockchain()
{
}

template <class T>
void Blockchain<T>::add_block(Block<T> b_new)
{
    b_new.mine_block(n_difficulty);
    b_new.set_prev_hash(v_chain.size() > 0 ? get_last_block().get_hash() : T());
    b_new.set_n_index(v_chain.size());
    v_chain.push_back(b_new);
}
template <class T>
void Blockchain<T>::set_n_difficulty(const uint64_t difficulty)
{
    assert(difficulty >= 0 && difficulty < 64);
    n_difficulty = difficulty;
}
template <class T>
uint64_t Blockchain<T>::get_n_difficulty() const
{
    return n_difficulty;
}
template <class T>
size_t Blockchain<T>::size() const
{
    return v_chain.size();
}
template <class T>
Block<T>& Blockchain<T>::operator[](const uint64_t idx)
{
    assert(idx < v_chain.size());
    return v_chain[idx];
}
template <class T>
const Block<T>& Blockchain<T>::operator[](const uint64_t idx) const
{
    assert(idx < v_chain.size());
    return v_chain[idx];
}
template <class T>
std::vector<Block<T>>::iterator Blockchain<T>::begin()
{
    return v_chain.begin();
}
template <class T>
std::vector<Block<T>>::iterator Blockchain<T>::end()
{
    return v_chain.end();
}
template <class T>
std::vector<Block<T>>::const_iterator Blockchain<T>::cbegin() const
{
    return v_chain.begin();
}
template <class T>
std::vector<Block<T>>::const_iterator Blockchain<T>::cend() const
{
    return v_chain.end();
}
template <class T>
bool Blockchain<T>::valid() const
{
    /*
    std::string difficulty(n_difficulty, '0');
    std::string prevHash = "0";
    uint32_t n = 0;
    for (auto &block : v_chain)
    {
        auto curr = block.get_hash();
        auto prev = block.get_prev_hash();
        if (curr.substr(0, n_difficulty) != difficulty ||
            block.get_index() != n || prevHash != prev)
            return false;
        prevHash = curr;
    }*/
    return true;
}
template <class T>
Block<T> Blockchain<T>::get_last_block() const
{
    return v_chain.back();
}

template <class U>
std::ostream &operator<<(std::ostream &out, const Blockchain<U> &bc)
{
    for (size_t i = 0; i < bc.size(); ++i)
        out << bc[i] << (i != bc.size() - 1 ? "\n" : "");
    return out;
}
