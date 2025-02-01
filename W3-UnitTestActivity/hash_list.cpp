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

hash_list::hash_list(const hash_list &other) {
    size = other.size;

    // make new list
    if (other.head != nullptr) {
        head = new node(other.head);
        node *prev_node = head;
        if (other.iter_ptr == other.head) {
            iter_ptr = head;
        }

        for (node *end_node = other.head->next; end_node != nullptr; end_node = end_node->next) {
            prev_node->next = new node(end_node);
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

hash_list &hash_list::operator=(const hash_list &other) {
    if (this == &other) {
        return *this;
    }

    hash_list temp(other);

    size = temp.size;

    node *new_head = this->head;
    this->head = temp.head;
    temp.head = new_head;

    node *new_iter_ptr = this->head;
    this->iter_ptr = temp.iter_ptr;
    temp.iter_ptr = new_iter_ptr;

    return *this;
}

void hash_list::reset_iter() {
    iter_ptr = head;
}


void hash_list::increment_iter() {
    if (iter_ptr != nullptr) {
        iter_ptr = iter_ptr->next;
    }
}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() {
    if (iter_ptr == nullptr) {
        return std::nullopt;
    }

    return std::make_pair(new int(iter_ptr -> key), new float(iter_ptr -> value));
}


bool hash_list::iter_at_end() {
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
