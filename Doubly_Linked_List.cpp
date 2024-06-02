#include <iostream>

using namespace std;

class Node {
    public:
        Node *prev;
        int data;
        Node *next;
};

class Doubly_Linked_List {
    private:
        Node *head;
        Node *focus;
        int newData;
        int searchData;
        Node *current;
        Node *tail;
    public:
        Doubly_Linked_List () {
            head = NULL;
            tail = NULL;
        }

        void insertFront(int data) {
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = head;
            newNode->prev = NULL;
            
            if (head != NULL) {
                head->prev = newNode;
                
            }
            head = newNode;
            cout << "\nInserted Successfully" << endl;
        }

        void insertEnd(int data) {
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = NULL;

            current = head;
            if (head == NULL) {
                newNode->prev = NULL;
                head = newNode;
                cout << "\nInserted Successfully" << endl;
                return;
            }
            while (current->next != NULL) {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
            cout << "\nInserted Successfully" << endl;
        }

        void addBefore(int searchData, int newData) {
            current = head;

            while (current != NULL) {
                if (current->data == searchData) {
                    Node *newNode = new Node;
                    newNode->data = newData;
                    newNode->prev = current->prev;
                    newNode->next = current;
                    if (current == head) {
                        head = newNode;
                    } else {
                        current->prev->next = newNode;
                    }
                    current->prev = newNode;
                    cout << "\nInserted Successfully" << endl;
                    return;
                }
                current = current->next;
            }
            cout << "\nNode with data " << searchData << " not found in the list." << endl;
        }

        void addAfter(int searchData, int newData) {
            current = head;

            while (current != NULL) {
                if (current->data == searchData) {
                    Node *newNode = new Node;
                    newNode->data = newData;
                    newNode->prev = current;
                    newNode->next = current->next;
                    if (current->next != NULL) {
                        current->next->prev = newNode;
                    }
                    current->next = newNode;
                    cout << "\nInserted Successfully" << endl;
                    return;
                }
                current = current->next;
            }
            cout << "\nNode with data " << searchData << " not found in the list." << endl;
        }

        void removeNode(int searchData) {
            current = head;

            while (current != NULL) {
                if (current->data == searchData) {
                    if (current == head) {
                        head = current->next;
                    } else {
                        current->prev->next = current->next;
                    }
                    if (current->next != NULL) {
                        current->next->prev = current->prev;
                    }
                    delete current;
                    cout << "\nRemove successfully" << endl;
                    return;
                }
                current = current->next;
            }
            cout << "\nNode with data " << searchData << " not found in the list." << endl;
        }

        void display() {
            current = head;
            
            if (current == NULL) {
                cout << "\nDoubly linked List is underflow" << endl;
                system("pause");
                system("cls");
                return;
            }
            while (current != NULL) {
                cout << "[" << current->data << "]" << " ";
                current = current->next;
            }
            cout << endl << endl;
        }

        void focusNode(int searchData) {
            current = head;

            if (current == NULL) {
                cout << "\nDoubly linked list is underflow" << endl;
            }
            while (current != NULL) {
                if (current->data == searchData) {
                    focus = current;
                    cout << "[" << focus->data << "]" << endl;
                    break;
                }
                current = current->next;
            }
        }

        void focusNext() {
            if (focus == NULL) {
                cout << "\nDoubly linked list is underflow" << endl;
                return;
            }
            if (focus->next == NULL) {
                return;
            }
            focus = focus->next;
            cout << "[" << focus->data << "]" << endl;
        }

        void focusPrev() {
            if (focus == NULL) {
                cout << "\nDoubly linked list is underflow" << endl;
                return;
            }
            if (focus->prev == NULL) {
                return;
            }
            focus = focus->prev;
            cout << "[" << focus->data << "]" << endl;
        }

        void sumOfAllNodes() {
            current = head;
            int sum = 0;

            if (current == NULL) {
                cout << "\nDoubly linked list is underflow and the sum is " << sum << endl;
                system("pause");
                system("cls");
                return;
            }

            while (current != NULL) {
                sum += current->data;
                current = current->next;
            }

            cout << "\nThe sum of all nodes is " << sum << endl;
            system("pause");
            system("cls");
        }

        void productOfAllNodes() {
            current = head;
            int product = 1;

            if (current == NULL) {
                cout << "\nDoubly linked list is underflow and the product is 0" << endl;
                system("pause");
                system("cls");
                return;
            }
            
            while (current != NULL) {
                product *= current->data;
                current = current->next;
            }

            cout << "\nThe product of all nodes is " << product << endl;
            system("pause");
            system("cls");
        }

        void containValue(int searchData) {
            current = head;

            while (current != NULL) {
                if (current->data == searchData) {
                    cout << "true" << endl;
                    return;
                    break;
                }
                current = current->next;
            }

            if (head == NULL) {
                cout << "\nDoubly linked list is underflow" <<endl;
            }

            else {
                cout << "false" << endl;
            }
        }

        void switch_Selected(int selected) {
            switch (selected) {
                case 1:
                    cout << "Enter a data: ";
                    cin >> newData;
                    insertFront(newData);
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    cout << "Enter a data: ";
                    cin >> newData;
                    insertEnd(newData);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    cout << "Insert it before: ";
                    cin >> searchData;
                    cout << "Enter a data: ";
                    cin >> newData;
                    addBefore(searchData, newData);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    cout << "Insert it After: ";
                    cin >> searchData;
                    cout << "Enter a data: ";
                    cin >> newData;
                    addAfter(searchData, newData);
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    cout << "Enter the node: ";
                    cin >> searchData;
                    removeNode(searchData);
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    cout << "Enter the node: ";
                    cin >> searchData;
                    focusNode(searchData);
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    focusNext();
                    system("pause");
                    system("cls");
                    break;
                case 8:
                    focusPrev();
                    system("pause");
                    system("cls");
                    break;
                case 9:
                    if (head != NULL) {
                        system ("cls");
                    }
                    display();
                    break;
                case 10:
                    sumOfAllNodes();
                    system("cls");
                    system("pause");
                    break;
                case 11:
                    productOfAllNodes();
                    system("cls");
                    system("pause");
                    break;
                case 12:
                    cout << "Enter the node: ";
                    cin >> searchData;
                    containValue(searchData);
                    break;
            }
        }

        void features() {
            int selected;

            cout << "Doubly Linked List" << endl;
            cout << "1.Add Node in Head\n";
            cout << "2.Add Node in Tail\n";
            cout << "3.Insert Before Node\n";
            cout << "4.Insert After Node\n";
            cout << "5.Remove Node\n";
            cout << "6.Focus on Node\n";
            cout << "7.Next\n";
            cout << "8.Previous\n";
            cout << "9.Show List\n";
            cout << "10.Sum of All Vallues\n";
            cout << "11.Product of All Vallues\n";
            cout << "12.Contain Vallue\n";
            cout << "13.Exit" << endl;
            cout << "Select: ";
            cin >> selected;

            switch_Selected(selected);

            if (selected >= 1 && selected <= 12) {
                return features();
            }
            if (selected < 1 || selected > 13) {
                cout << "\nInvalid Input!" << endl;
                system("pause");
                system("cls");
                return features();
            }
        }
} dll;

int main() {
    dll.features();
    return 0;
}