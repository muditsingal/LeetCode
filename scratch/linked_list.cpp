#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(): val(0), next(nullptr), prev(nullptr) {}
};

int main()
{
    Node *head, *tail;
    head = new Node();
    tail = new Node();
    // head = tail = nullptr;
    cout << head->val;

    return 0;
}