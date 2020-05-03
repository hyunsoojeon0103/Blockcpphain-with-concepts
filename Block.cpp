template <class T>
Block<T>::Block(const std::string &s_data_in)
    : n_index(0), t_time(time(nullptr)), n_nonce(0)
{
}
template <class T>
Block<T>::~Block()
{
}
template <class T>
T Block<T>::get_hash() const
{
    return hash;
}
template <class T>
void Block<T>::set_prev_hash(const T prev_hash_in)
{
    std::string str = prev_hash.ToString();
    //assert(str.length() == 64);
    prev_hash = prev_hash_in;
}
template <class T>
T Block<T>::get_prev_hash() const
{
    return prev_hash;
}
template <class T>
uint64_t Block<T>::get_index() const
{
    return n_index;
}
template <class T>
void Block<T>::set_n_index(const uint64_t idx)
{
    assert(idx >= 0);
    n_index = idx;
}

template <class T>
void Block<T>::mine_block(const uint64_t n_difficulty)
{
    assert(n_difficulty >= 0 && n_difficulty < 64);
    std::string str(n_difficulty, '0');
    do
    {
        n_nonce++;
        hash = calculate_hash();

    } while (hash.ToString().substr(0, n_difficulty) != str);
}

template <class T>
T Block<T>::calculate_hash() const
{
    std::stringstream str_stream;
    str_stream << byte_size << hash << prev_hash << n_index << t_time << n_nonce;
    return T(sha256(str_stream.str()));
}

template <class U>
std::ostream& operator<<(std::ostream &out, const Block<U>& block)
{
    out << "n_index       : " << block.n_index << '\n'
        << "t_time        : " << block.t_time << '\n'
        << "byte_size     : " << block.byte_size << '\n'
        << "n_nonce       : " << block.n_nonce << '\n'
        << "hash          : " << block.hash << '\n'
        << "previous hash : " << block.prev_hash << '\n';
    return out;
}
