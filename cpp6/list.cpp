#include <iostream>
#include <string>

class Node{
public:  
  int data;  
  Node *next;
  
  Node(int data) {  
    this->data = data;  
    this->next = nullptr;  
  }

  void addBack(int nextData);

};

void Node::addBack(int nextData){
	Node *_next = new Node(nextData);

    if (this->next == nullptr) {
        this->next = _next;
    } else { 
        Node *temp = this->next;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = _next;
    }
}

void invertList(Node **head) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return;
    }

    Node *prev = nullptr;
    Node *current = *head;
    Node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main(){
    Node list(1);

    list.addBack(2);
    list.addBack(3);
    list.addBack(4);
    list.addBack(5);
    list.addBack(6);
    list.addBack(7);

    std::cout << "______ASCENDENT_ORDER_____" << std::endl;
    Node *current = &list;
    while (current){
        std::cout << current->data;
        if (current->next != nullptr){
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;

    current = &list; 
    invertList(&current);

    std::cout << "_____DESCENDENT_ORDER_____" << std::endl;
    while (current){
        std::cout << current->data;
        if (current->next != nullptr){
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}