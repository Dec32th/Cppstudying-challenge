#pragma once
//singlylinkedlist - unsorted
//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int data) : data(data), next(nullptr) {}
//};
//
//class UnsortedSinglyLinkedList {
//private:
//    Node* head;
//
//public:
//    UnsortedSinglyLinkedList() : head(nullptr) {}
//
//    void insert(int data) {
//        Node* newNode = new Node(data);
//        newNode->next = head;
//        head = newNode;
//    }
//
//    void makeEmpty() {
//        Node* current = head;
//        while (current) {
//            Node* next = current->next;
//            delete current;
//            current = next;
//        }
//        head = nullptr;
//    }
//
//    Node* find(int data) {
//        Node* current = head;
//        while (current && current->data != data) {
//            current = current->next;
//        }
//        return current;
//    }
//
//    void remove(int data) {
//        Node* current = head;
//        Node* previous = nullptr;
//        while (current && current->data != data) {
//            previous = current;
//            current = current->next;
//        }
//        if (current == nullptr) return;
//        if (previous == nullptr) {
//            head = head->next;
//        }
//        else {
//            previous->next = current->next;
//        }
//        delete current;
//    }
//
//    void printList() {
//        Node* current = head;
//        while (current) {
//            cout << current->data << " -> ";
//            current = current->next;
//        }
//        cout << "NULL\n";
//    }
//
//    ~UnsortedSinglyLinkedList() {
//        makeEmpty();
//    }
//};




//singlylinked - sorted
// 
//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data; // 노드가 저장할 데이터
//    Node* next; // 다음 노드를 가리키는 포인터
//
//    Node(int data) : data(data), next(nullptr) {}
//};
//
//class SortedSinglyLinkedList {
//private:
//    Node* head; // 리스트의 첫 번째 노드를 가리키는 포인터
//
//public:
//    SortedSinglyLinkedList() : head(nullptr) {}
//
//    void insert(int data) {
//        Node* newNode = new Node(data);
//        if (!head || data < head->data) {
//            newNode->next = head;
//            head = newNode;
//        }
//        else {
//            Node* current = head;
//            while (current->next && current->next->data < data) {
//                current = current->next;
//            }
//            newNode->next = current->next;
//            current->next = newNode;
//        }
//    }
//
//    void makeEmpty() {
//        Node* current = head;
//        while (current) {
//            Node* next = current->next;
//            delete current;
//            current = next;
//        }
//        head = nullptr;
//    }
//
//    Node* find(int data) {
//        Node* current = head;
//        while (current && current->data != data) {
//            current = current->next;
//        }
//        return current; // 반환된 포인터를 통해 찾은 노드에 접근하거나 nullptr 검사 가능
//    }
//
//    void remove(int data) {
//        Node* current = head;
//        Node* previous = nullptr;
//        while (current && current->data != data) {
//            previous = current;
//            current = current->next;
//        }
//        if (current == nullptr) return; // 데이터를 찾지 못한 경우
//        if (previous == nullptr) {
//            head = head->next; // 삭제할 노드가 헤드인 경우
//        }
//        else {
//            previous->next = current->next; // 중간 노드나 마지막 노드 삭제
//        }
//        delete current;
//    }
//
//    void printList() {
//        Node* current = head;
//        while (current) {
//            cout << current->data << " -> ";
//            current = current->next;
//        }
//        cout << "NULL\n";
//    }
//
//    ~SortedSinglyLinkedList() {
//        makeEmpty();
//    }
//};
//
//int main() {
//    SortedSinglyLinkedList list;
//    list.insert(30);
//    list.insert(20);
//    list.insert(40);
//    list.insert(10);
//    list.printList(); // 출력: 10 -> 20 -> 30 -> 40 -> NULL
//    list.remove(20);
//    list.printList(); // 출력: 10 -> 30 -> 40 -> NULL
//    list.makeEmpty();
//    list.printList(); // 출력: NULL
//    return 0;
//}



//doubly - unsorted

//#include <iostream>
//using namespace std;
//
//class DNode {
//public:
//    int data;
//    DNode* prev;
//    DNode* next;
//
//    DNode(int data) : data(data), prev(nullptr), next(nullptr) {}
//};
//
//class UnsortedDoublyLinkedList {
//private:
//    DNode* head;
//
//public:
//    UnsortedDoublyLinkedList() : head(nullptr) {}
//
//    void insert(int data) {
//        DNode* newNode = new DNode(data);
//        newNode->next = head;
//        if (head) {
//            head->prev = newNode;
//        }
//        head = newNode;
//    }
//
//    void makeEmpty() {
//        DNode* current = head;
//        while (current) {
//            DNode* next = current->next;
//            delete current;
//            current = next;
//        }
//        head = nullptr;
//    }
//
//    DNode* find(int data) {
//        DNode* current = head;
//        while (current && current->data != data) {
//            current = current->next;
//        }
//        return current;
//    }
//
//    void remove(int data) {
//        DNode* current = find(data);
//        if (!current) return;
//
//        if (current->prev) {
//            current->prev->next = current->next;
//        }
//        else {
//            head = current->next;
//        }
//
//        if (current->next) {
//            current->next->prev = current->prev;
//        }
//
//        delete current;
//    }
//
//    void printList() {
//        DNode* current = head;
//        while (current) {
//            cout << current->data << " <-> ";
//            current = current->next;
//        }
//        cout << "NULL\n";
//    }
//
//    ~UnsortedDoublyLinkedList() {
//        makeEmpty();
//    }
//};




//doubly - sorted
//#include <iostream>
//using namespace std;
//
//class DNode {
//public:
//    int data;
//    DNode* prev;
//    DNode* next;
//
//    DNode(int data) : data(data), prev(nullptr), next(nullptr) {}
//};
//
//class SortedDoublyLinkedList {
//private:
//    DNode* head;
//
//public:
//    SortedDoublyLinkedList() : head(nullptr) {}
//
//    void insert(int data) {
//        DNode* newNode = new DNode(data);
//        if (!head || data < head->data) {
//            newNode->next = head;
//            if (head) {
//                head->prev = newNode;
//            }
//            head = newNode;
//        }
//        else {
//            DNode* current = head;
//            while (current->next && current->next->data < data) {
//                current = current->next;
//            }
//            newNode->next = current->next;
//            if (current->next) {
//                current->next->prev = newNode;
//            }
//            newNode->prev = current;
//            current->next = newNode;
//        }
//    }
//
//    void makeEmpty() {
//        DNode* current = head;
//        while (current) {
//            DNode* next = current->next;
//            delete current;
//            current = next;
//        }
//        head = nullptr;
//    }
//
//    DNode* find(int data) {
//        DNode* current = head;
//        while (current && current->data != data) {
//            current = current->next;
//        }
//        return current; // 반환된 포인터를 통해 찾은 노드에 접근하거나 nullptr 검사 가능
//    }
//
//    void remove(int data) {
//        DNode* current = find(data);
//        if (!current) return; // 데이터를 찾지 못한 경우
//
//        if (current->prev) {
//            current->prev->next = current->next;
//        }
//        else {
//            head = current->next; // 삭제할 노드가 헤드인 경우
//        }
//
//        if (current->next) {
//            current->next->prev = current->prev;
//        }
//
//        delete current;
//    }
//
//    void printList() {
//        DNode* current = head;
//        while (current) {
//            cout << current->data << " <-> ";
//            current = current->next;
//        }
//        cout << "NULL\n";
//    }
//
//    ~SortedDoublyLinkedList() {
//        makeEmpty();
//    }
//};
//
//int main() {
//    SortedDoublyLinkedList list;
//    list.insert(30);
//    list.insert(20);
//    list.insert(40);
//    list.insert(10);
//    list.printList(); // 출력: 10 <-> 20 <-> 30 <-> 40 <-> NULL
//    list.remove(20);
//    list.printList(); // 출력: 10 <-> 30 <-> 40 <-> NULL
//    list.makeEmpty();
//    list.printList(); // 출력: NULL
//    return 0;
//}

template<typename T>
struct NodeType
{
	T data;
	NodeType* next;
};

template<typename T>
class SinglyLinkedList
{
public:

private:
	NodeType* pFirst;
	NodeType* pCurrent;
};



//pointer array를 동적 할당하여 사용하는 Sorted List를 구현하시오.생성자에서 최대 아이템의 개수를 입력 받아 pointer array를 동적 할당하고 각 아이템의 삽입 시에는 동적 할당한 아이템을 pointer가 가리키도록 하시오. (40점)
//
//
//Que를 활용하여 12번의 가위바위보 승부 예측 게임 점수 계산 프로그램을 작성하시오. (100점)
//
//
//Red팀의 가위 바위 보는 각각 4개씩이며 내는 순서가 미리 결정되어 있다.
//Red팀의 가위 바위 보를 내는 순서는 기본적으로 미리 공개되어 있지만 그 중 4개는 비공개로 직접 가위바위보를 실행한 후에 확인할 수 있다.
//Red팀의 알려진 가위 바위 보 순서를 토대로 Blue팀의 가위 바위 보 제출 순서를 결정한다.이 때 Blue팀 역시 가위바위보 각각을 4개씩으로 구성해야 한다.
//기본적으로 가위 바위 보에서 Blue팀이 승리하면 1점, 비기면 0점, 지면 ?1점을 얻는다.
//다만, 연승 보너스가 적용되어 Blue팀이 승리할 경우 이전까지 연승수가 점수에 추가된다.비기면 연승이 증가하진 않지만 연승 보너스는 유지되며 지게 될 경우 연승 보너스는 초기화되어 0부터 다시 시작된다.
//위 사항을 참고하여 Red팀의 공개된 Blue팀의 12개 가위바위보 순서를 모두 결정하면 승부 예측 단계에 들어간다.
//가위 바위 보가 실행되기 전 Blue팀을 기준으로 승, 무, 패 예측을 진행하며 맞출 경우 각각 승리 시 1, 무승부 시 2, 패배 시 3점의 보너스 점수를 얻게 된다.
//
//
//예시) Red 팀 입력이 다음과 같고(큰 따옴표로 묶인 것이 비공개)
//
//[가위, “바위”, 가위, 바위, 보, “보”, 가위, 보, 가위, 보, “바위”, “바위”]
//
//Blue 팀 입력을 아래와 같이 결정했을 때
//
//[바위, 보, 바위, 보, 가위, 보, 바위, 가위, 바위, 가위, 보, 가위]
//
//1번째 가위 바위 보는 결과가 공개되어 있어 승을 미리 예측할 수 있고, 두 번째는 비공개인 결과를 예측해야 한다.아래와 같이 매 가위 바위 보 전 승부 예측을 했다고 할 때
//
//[승, 무, 승, 승, 승, 무, 승, 승, 승, 승, 무, 무]
//
//가위바위보 결과로 1 + 2(1 + 연승1) + 3 + 4 + 5 + 0 + 5 + 6 + 7 + 8 + 9 ?1 = 49에 승부 예측 점수 1 + 0 + 1 + 1 + 1 + 2 + 1 + 1 + 1 + 1 + 0 + 0 = 10, 최종 점수는 59점이 된다.
//
//
//
//(보너스)가능한 최대 점수를 얻을 수 있도록 Blue팀 가위바위보 순서와 승부 예측을 진행하는 함수를 구현하시오. (30점)