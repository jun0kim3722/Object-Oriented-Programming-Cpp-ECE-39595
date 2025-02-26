#include "hash_list.h"

template <typename K, typename V>
hash_list<K,V>::hash_list() {
    head = nullptr;
    iter_ptr = nullptr;
    size = 0;
}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

template <typename K, typename V>
void hash_list<K,V>::insert(K key, V value) {
    if (size == 0) {
        head = new node <K, V>(key, value);
        size += 1;
    }
    else {
        bool is_updated = false;
        node<K, V>* prev_node = head;
        for (node<K, V>* end_node = head; end_node != nullptr; end_node = end_node->next) {
            if (end_node -> key == key) {
                end_node -> value = value;
                is_updated = true;
            }
            prev_node = end_node;
        }

        if (!is_updated) {
            node<K, V>* new_node = new node<K, V>(key, value);
            prev_node -> next = new_node;
            size += 1;
        }
    }
}

template <typename K, typename V>
std::optional<V> hash_list<K,V>::get_value(K key) const {
    for (node<K, V>* end_node = head; end_node != nullptr; end_node = end_node->next) {
        if (end_node -> key == key) {
            return end_node -> value;
        }
    }

    return std::nullopt;
}

template <typename K, typename V>
bool hash_list<K,V>::remove(K key) {
    node<K, V>* prev_node = nullptr;
    for (node<K, V>* end_node = head; end_node != nullptr; end_node = end_node->next) {
        if (end_node -> key == key) {
            if (prev_node != nullptr) {
                prev_node -> next = end_node -> next;
            }
            else {
                head = end_node -> next;
            }
            delete end_node;
            size -= 1;

            return true;
        }
        prev_node = end_node;
    }
    
    return false;
}

template <typename K, typename V>
size_t hash_list<K,V>::get_size() const {
    return size;
}

template <typename K, typename V>
hash_list<K,V>::~hash_list() {
    while (head != nullptr) {
        node<K, V>* next = head->next;
        delete head;
        head = next;
    }
    size = 0;
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

template <typename K, typename V>
hash_list<K,V>::hash_list(const hash_list<K,V> &other) {
    size = other.size;

    // make new list
    if (other.head != nullptr) {
        head = new node<K, V>(other.head);
        node<K, V>* prev_node = head;
        if (other.iter_ptr == other.head) {
            iter_ptr = head;
        }

        for (node<K, V>* end_node = other.head->next; end_node != nullptr; end_node = end_node->next) {
            prev_node->next = new node<K, V>(end_node);
            prev_node = prev_node->next;

            if (other.iter_ptr == end_node) {
                iter_ptr = prev_node;
            }
        }
    }
    else {
        head = nullptr;
        iter_ptr = nullptr;
    }
}

template <typename K, typename V>
hash_list<K,V> &hash_list<K,V>::operator=(const hash_list<K,V> &other) {
    if (this == &other) {
        return *this;
    }

    hash_list<K,V> temp(other);

    size = temp.size;

    node<K, V>* new_head = this->head;
    this->head = temp.head;
    temp.head = new_head;

    node<K, V>* new_iter_ptr = this->head;
    this->iter_ptr = temp.iter_ptr;
    temp.iter_ptr = new_iter_ptr;

    return *this;
}

template <typename K, typename V>
void hash_list<K,V>::reset_iter() {
    iter_ptr = head;
}


template <typename K, typename V>
void hash_list<K,V>::increment_iter() {
    if (iter_ptr != nullptr) {
        iter_ptr = iter_ptr->next;
    }
}


template <typename K, typename V>
std::optional<std::pair<const K *, V *>> hash_list<K,V>::get_iter_value() {
    if (iter_ptr == nullptr) {
        return std::nullopt;
    }

    return std::make_pair(&iter_ptr -> key, &iter_ptr -> value);
}


template <typename K, typename V>
bool hash_list<K,V>::iter_at_end() {
    if (iter_ptr == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
