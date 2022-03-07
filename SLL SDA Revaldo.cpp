#include<iostream>
using namespace std;

struct node{
    int info;
    node* next;

    node(int value, node* pos = 0)
    : info(value), next(pos){};
};

node* first = new node(1);

node* insertfirst(int value){
    node* n = new node(value);
    n->next = first;
    first = n;
    return n;
}

node* insertlast(int value){
    node* p = first;
    node* n = new node(value);
    while(p->next != NULL){
        p = p->next;
    }
    n->next = NULL;
    p->next = n;
    return p;
}

node* insertbefore(int value , node* pos){
    if (first != pos){
        node* temp;
        node* p = first;
        
        while(p != pos){
            temp = p;
            p = p->next;
        }
        
        node* n = new node(value);
        n->next = temp->next;
        temp->next = n;

        return n;
    } else {
        node* n = new node(value);
        n->next = first;
        first = n;
        return n; 
    }
}

node* insertafter(int value, node* pos){
    node* temp;
    node* p = first;
    
    while(p != pos){
        p = p->next;
    }
    
    node* n = new node(value);
    n->next = p->next;
    p->next = n;

    return n;
}

void deletefirst(){
    node* del = first;
    first = first->next;
    delete del;
}

void deletelast(){
    node* p = first;
    while (p->next->next != NULL){
        p = p->next;
    }
    delete p->next;
    p->next = NULL;
}

node* deleteafter(node* pos){
    node* p = first;
    
    while(p != pos){
        p = p->next;
    }
    pos->next = p->next->next;
    delete p->next;
    return pos;
}

int search(int key){
    node* p = first;
    int i = 1;
    while (p->info != key){
        p = p->next;
        i++;
    }
    return i;
}

void print(node* pos){
    while(pos != NULL){
        cout << pos->info << " ";
        pos = pos->next;
    } cout << endl;
}

int main(){
	cout <<"Data Awal\n";
    print(first);
    cout <<"Insert First(2)\n";
    insertfirst(2);
    print(first);
    cout <<"Insert Last(3)\n";
    insertlast(3);
    print(first);
    cout <<"Insert Before(4)-> sebelum 3\n";
    insertbefore(4 , first->next->next);
    print(first);
    cout <<"Insert After(5)-> Sesudah 1\n";
    insertafter(5 , first->next);
    print(first);
    cout <<"Delete First\n";
    deletefirst();
    print(first);
    cout <<"Delete Last\n";
    deletelast();
    print(first);
	cout <<"Delete After -> Setelah 1\n";
    deleteafter(first);
    print(first);
    cout <<"\nMencari Elemen(Search) = 1\n";
    int key = 1;
    cout << "elemen "<< key <<" ditemukan di data ke-" << search(key);

    return 0;
}
