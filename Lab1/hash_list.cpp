#include "hash_list.h"

hash_list::hash_list() {
    head = nullptr;
    iter_ptr = nullptr;
    size = 0;
}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) {
    if (size == 0) {
        head = new node(key, value);
        size += 1;
    }
    else {
        bool is_updated = false;
        node *prev_node = head;
        for (node *end_node = head; end_node != nullptr; end_node = end_node->next) {
            if (end_node -> key == key) {
                end_node -> value = value;
                is_updated = true;
            }
            prev_node = end_node;
        }

        if (!is_updated) {
            node *new_node = new node(key, value);
            prev_node -> next = new_node;
            size += 1;
        }
    }
}

std::optional<float> hash_list::get_value(int key) const {
    for (node *end_node = head; end_node != nullptr; end_node = end_node->next) {
        if (end_node -> key == key) {
            return end_node -> value;
        }
    }

    return std::nullopt;
}

bool hash_list::remove(int key) {
    node *prev_node = nullptr;
    for (node *end_node = head; end_node != nullptr; end_node = end_node->next) {
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

size_t hash_list::get_size() const {
    return size;
}

hash_list::~hash_list() {
    while (head != nullptr) {
        node *next = head->next;
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

hash_list::hash_list(const hash_list &other) {}

hash_list &hash_list::operator=(const hash_list &other) { return *this; }

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
