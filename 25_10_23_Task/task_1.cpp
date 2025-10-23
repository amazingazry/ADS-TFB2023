#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next_ptr;
};


void push(Node*& top, string value) {
    Node* newNode = new Node();   // allocate memory
    newNode->data = value;        // assign data
    newNode->next_ptr = top;      // link new node to previous top
    top = newNode;                // update top pointer
}

void pop(Node*& top) {
    if (top == nullptr) {
        cout << "Stack is empty. Cannot pop." << endl;
        return;
    }

    Node* temp = top;            
    top = top->next_ptr;         
    delete temp;                  
}

void display(Node* top) {
    Node* current = top;
    cout << "Stack contents (top → bottom): ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next_ptr;
    }
    cout << endl;
}

int main() {
    Node* top = nullptr; 

    
    push(top, "test1");
    push(top, "test2");
    push(top, "test3");

    
    display(top);

    
    cout << "Popping top element..." << endl;
    pop(top);

    
    display(top);

    
    while (top != nullptr) {
        pop(top);
    }

    return 0;
}

