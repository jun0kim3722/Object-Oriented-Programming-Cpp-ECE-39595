#include "hash_map.h"

template <typename K, typename V>
hash_map<K,V>::hash_map(size_t capacity, float upper_load_factor, float lower_load_factor) {
    _size = 0;
    _capacity = capacity;
    _upper_load_factor = upper_load_factor;
    _lower_load_factor = lower_load_factor;
    _head = new hash_list<K,V>[capacity];
}

template <typename K, typename V>
hash_map<K,V>::hash_map(const hash_map &other) {
    _size = other._size;
    _capacity = other._capacity;
    _upper_load_factor = other._upper_load_factor;
    _lower_load_factor = other._lower_load_factor;
    _head = new hash_list<K,V>[_capacity];
    std::copy(other._head, other._head + other._capacity, _head);
}

template <typename K, typename V>
hash_map<K,V> &hash_map<K,V>::operator=(const hash_map &other) {
    if (this == &other) {
        return *this;
    }

    hash_map<K,V> temp(other);

    _size = temp._size;
    _capacity = temp._capacity;
    _upper_load_factor = temp._upper_load_factor;
    _lower_load_factor = temp._lower_load_factor;

    hash_list<K,V> *new_head = this->_head;
    this->_head = temp._head;
    temp._head = new_head;

    return *this;
}

template <typename K, typename V>
void hash_map<K,V>::insert(K key, V value) {
    int bucket_idx = _hash(key) % _capacity;
    size_t prev_size = _head[bucket_idx].get_size();
    _head[bucket_idx].insert(key, value);

    if (prev_size < _head[bucket_idx].get_size()) {
        _size++;
        resize_hash();
    }
}

template <typename K, typename V>
void hash_map<K,V>::insert_wo_update(K key, V value) {
    int bucket_idx = _hash(key) % _capacity;
    size_t prev_size = _head[bucket_idx].get_size();
    _head[bucket_idx].insert(key, value);

    if (prev_size < _head[bucket_idx].get_size()) {
        _size++;
    }
}

template <typename K, typename V>
void hash_map<K,V>::resize_hash() {
    if (_size > _upper_load_factor * _capacity) {
        // up capacity
        size_t len = sizeof(_capacities) / sizeof(_capacities[0]);
        for (size_t i = 0; i < len; i++) {
            if (_capacities[i] > _capacity) {
                rehash(_capacities[i]);
                break;
            }
        }

    }
    else if (_size < _lower_load_factor * _capacity) {
        // down capacity
        size_t len = sizeof(_capacities) / sizeof(_capacities[0]);
        for (size_t i = len; i > 0; i--) {
            if (_capacities[i-1] < _capacity) {
                rehash(_capacities[i-1]);
                break;
            }
        }
    }
}

template <typename K, typename V>
void hash_map<K,V>::rehash(size_t new_capacity) {
    hash_map<K,V> temp(new_capacity, _upper_load_factor, _lower_load_factor);

    for (size_t i = 0; i < _capacity; i++) {
        _head[i].reset_iter();

        while (!_head[i].iter_at_end()) {
            std::optional<std::pair<const K *, V *>> node = _head[i].get_iter_value();
            K *key = const_cast<K*>(node -> first);
            V *value = const_cast<V*>(node -> second);

            temp.insert_wo_update(*key, *value);
            _head[i].increment_iter();
        }
    }
    
    _capacity = temp._capacity;
    hash_list<K,V> *new_head = this->_head;
    this->_head = temp._head;
    temp._head = new_head;
}

template <typename K, typename V>
std::optional<V> hash_map<K,V>::get_value(K key) const {
    int bucket_idx = _hash(key) % _capacity;
    return _head[bucket_idx].get_value(key);
}

template <typename K, typename V>
bool hash_map<K,V>::remove(K key) {
    int bucket_idx = _hash(key) % _capacity;
    bool is_removed = _head[bucket_idx].remove(key);

    if (is_removed) {
        _size--;
        resize_hash();
    }
    return is_removed;
}

template <typename K, typename V>
size_t hash_map<K,V>::get_size() const {
    return _size;
}

template <typename K, typename V>
size_t hash_map<K,V>::get_capacity() const {
    return _capacity;
}

template <typename K, typename V>
void hash_map<K,V>::get_all_keys(K *keys) {
    int key_idx = 0;
    for (size_t i = 0; i < _capacity; i++) {
        _head[i].reset_iter();

        while (!_head[i].iter_at_end()) {
            std::optional<std::pair<const K *, V *>> values = _head[i].get_iter_value();
            K *key = const_cast<K*>(values -> first);
            keys[key_idx] = *key;
            
            key_idx++;
            _head[i].increment_iter();
        }
    }
}

template <typename K, typename V>
void hash_map<K,V>::get_all_sorted_keys(K *keys) {
    if (_size > 0) {
        get_all_keys(keys);
        std::sort(keys, keys + _size);
    }
}


template <typename K, typename V>
void hash_map<K,V>::get_bucket_sizes(size_t *buckets) {
    for (size_t i = 0; i < _capacity; i++) {
        buckets[i] = _head[i].get_size();
    }
}

template <typename K, typename V>
hash_map<K,V>::~hash_map() {
    delete[] _head;
    _head = nullptr;
    _size = 0;
    _capacity = 0;
}