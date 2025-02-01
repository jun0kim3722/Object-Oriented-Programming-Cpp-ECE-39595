#include <iostream>
#include <cassert>

#include "hash_list.h"

// A unit test for a basic constructor
void t_constructor(void){
  hash_list list;

  if(list.get_size() != 0){
    std::cout << "t_constructor: invalid size" << std::endl;
  }
}

/*******
 Unit test to check if insertion into an empty list
 works. More unit tests would be recommended for
 testing insert. Could you think of what other tests one
 might consider?
**********/

void t_insert_empty(void){
  hash_list list;

  list.insert(1, 7.0);
  
  if(list.get_size() != 1){
    std::cout << "t_insert_empty: invalid size" << std::endl;
    return;
  }

  if(!list.get_value(1).has_value()){
    std::cout << "Expected value but says no value" << std::endl;
    return;
  }

  if(!(list.get_value(1).value() == 7.0)){
    std::cout << "Value does not match" << std::endl;
  }
}

void check_copy_size(hash_list &a, hash_list &b) {
  if (a.get_size() != b.get_size()) {
    std::cout << "Size does not match" << std::endl;
  }
}

void check_list(hash_list &a, hash_list &b) {
  node *end_node_b = b.get_head();
  if (end_node_b == nullptr and a.get_head() != nullptr) {
    std::cout << "Adress is not correctly connected" << std::endl;
  }
  for (node *end_node_a = a.get_head(); end_node_a != nullptr; end_node_a = end_node_a->next) {
    if (end_node_a->key != end_node_b->key) {
      std::cout << "Key does not match" << std::endl;
    }
    if (end_node_a->value != end_node_b->value) {
      std::cout << "Key does not match" << std::endl;
    }

    if (end_node_b != nullptr) {
      end_node_b = end_node_b -> next;
    }
    else {
      std::cout << "Adress is not correctly connected" << std::endl;
      break;
    }
  }
}

void unit_test(void) {
  t_constructor();
  t_insert_empty();

  // copy constructer test1
  hash_list list1;
  hash_list list2(list1);
  check_copy_size(list1, list2);
  check_list(list1, list2);

  // copy constructer test2
  list1.insert(1, 1);
  list1.insert(2, 4);
  list1.insert(3, 5);
  hash_list list2_1(list1);
  check_copy_size(list1, list2_1);
  check_list(list1, list2_1);

  // assign opperator test1
  hash_list list3 = list2;
  check_copy_size(list3, list2);
  check_list(list3, list2);

  // assign opperator test2
  list3 = list3;
  check_copy_size(list3, list2);
  check_list(list3, list2);

  // assign opperator test3
  list1.insert(1, 9);
  list1.insert(2, 9);
  list1.insert(3, 9);
  list1.insert(4, 4);
  list1.insert(5, 5);
  list3 = list2 = list1;
  check_copy_size(list1, list2);
  check_list(list1, list2);
  check_copy_size(list1, list3);
  check_list(list1, list3);
  check_copy_size(list3, list2);
  check_list(list3, list2);
  
}

int main(int argc, char *argv[])
{
  t_constructor();
  t_insert_empty();
  unit_test();
}
