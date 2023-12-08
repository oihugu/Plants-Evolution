#include <string>
#include <vector>

using namespace std;

class Elemento {
    int value;
    Elemento *next_value;
    Elemento *prev_value;

    public:
    Elemento (int v){
        next_value = NULL;
        prev_value = NULL;
        value = v;
    }

    void set_next_elem(Elemento *elem_ptr){
        next_value = elem_ptr;
    }

    Elemento *get_next_elem(){
        return next_value;
    }


};

class LinkedList {
    Elemento *head;
    Elemento *tail;
    int total_elems;

    public:

    LinkedList(){
        head = NULL;
        tail = NULL;
        total_elems= 0;
    }

    void insert(Elemento *elem_ptr){
        if (total_elems == 0){
            this->head = elem_ptr;
        }
        else{
            this->tail->set_next_elem(elem_ptr);
        }
        tail = elem_ptr;
        total_elems++;
    }

    int get(int i){
        Elemento *holder = head;
        
        for (int a=0;i<a;a++){
            holder = holder->get_next_elem();
        }

        return i;
    }

    vector<int> to_vec(){
        vector<int> result{total_elems};

        for (int i=0; i<total_elems; i++){
            result[i] = this->get(i);
        }

        return result;
    }
};

vector<int> find_all(string str, char c){
    LinkedList positions;

    for (int i=0; i<str.length(); i++){
        if (str[i] == c){
            Elemento *elem = new Elemento(i);
            positions.insert(elem);
        }
    }

    return positions.to_vec(); 
}
