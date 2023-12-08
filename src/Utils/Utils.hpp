#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <vector>
class Elemento {
private:
    int value;
    Elemento *next_value;
    Elemento *prev_value;
    Elemento (int v);
public:
    void set_next_elem(Elemento *elem_ptr);
    Elemento *get_next_elem();
};

class LinkedList {
private:
    Elemento *head;
    Elemento *tail;
    int total_elems;
public:
    void insert(Elemento *elem_ptr);
    int get(int i);
    vector<int> to_vec();
}

vector<int> find_all(string str, char c);

#endif