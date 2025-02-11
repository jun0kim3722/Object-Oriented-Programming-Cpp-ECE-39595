#include "hash_map.h"
#include <iostream>

hash_map::hash_map(size_t capacity) {
    _size = 0;
    _capacity = capacity;
    _head = new hash_list[capacity];
}

hash_map::hash_map(const hash_map &other) {
    _size = other._size;
    _capacity = other._capacity;
    _head = new hash_list[_capacity];
    std::copy(other._head, other._head + other._capacity, _head);
}

hash_map &hash_map::operator=(const hash_map &other) {
    if (this == &other) {
        return *this;
    }

    hash_map temp(other);

    _size = temp._size;
    _capacity = temp._capacity;

    hash_list *new_head = this->_head;
    this->_head = temp._head;
    temp._head = new_head;

    return *this;
}

int hash(int key) {
    return key;
}

void hash_map::insert(int key, float value) {
    int bucket_idx = hash(key) % _capacity;
    size_t prev_size = _head[bucket_idx].get_size();
    _head[bucket_idx].insert(key, value);

    if (prev_size < _head[bucket_idx].get_size()) {
        _size++;
    }
}

std::optional<float> hash_map::get_value(int key) const {
    int bucket_idx = hash(key) % _capacity;
    return _head[bucket_idx].get_value(key);
}

bool hash_map::remove(int key) {
    int bucket_idx = hash(key) % _capacity;
    bool is_removed = _head[bucket_idx].remove(key);

    if (is_removed) {
        _size--;
    }
    return is_removed;
}

size_t hash_map::get_size() const {
    return _size;
}

size_t hash_map::get_capacity() const {
    return _capacity;
}

void hash_map::get_all_keys(int *keys) {
    int key_idx = 0;
    for (size_t i = 0; i < _capacity; i++) {
        _head[i].reset_iter();

        while (!_head[i].iter_at_end()) {
            std::optional<std::pair<const int *, float *>> values = _head[i].get_iter_value();
            int *key = const_cast<int*>(values.value().first);
            keys[key_idx] = *key;
            
            key_idx++;
            _head[i].increment_iter();
        }
    }
}

void hash_map::get_bucket_sizes(size_t *buckets) {
    for (size_t i = 0; i < _capacity; i++) {
        buckets[i] = _head[i].get_size();
    }
}

hash_map::~hash_map() {
    delete[] _head;
    _head = nullptr;
    _size = 0;
    _capacity = 0;
}