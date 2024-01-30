#include<iostream>
#include"student.h"
#include"list.h"


using namespace std;

struct Node
{
	//앞뒤로 연결된 노드를 가리키는 포인터
	Node* prev;
	Node* next;

	//타입과 상관없이 가리킨다.
	void* data;
};

struct List
{
	Node* head;
};

List* CreateList()
{
	//헤드 노드를 만들고 초기화한다.
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;

	//List 구조체를 만들고 초기화한다
	List* list = new List;
	list->head = head;

	//List구조체를 반환
	return list;
}

//새로운 노드를 추가한다.
//node: 이 노드 뒤에 새 노드가 추가된다.
//data: 새 노드의 데이터
void InsertNodeAfter(Node* node, void* data)
{
	//삽입되려는 곳의 앞, 뒤 노드를 구해놓으면 읽기 쉬운 소스코드를 만들 수 있다.
	Node* before = node;
	Node* after = node->next;

	//세 노드를 만들고 초기화
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	//node의 뒤에 있던 노드가 새 노드를 가리키도록 함
	after->prev = newNode;

	//매개 변수 node가 새 노드를 가리키게 함
	before->next = newNode;
}

//노드를 제거한다.
//node: 제거할 노드
//deleteData: treu이면 노드가 가리키는 데이터도 제거한다.
void RemoveNode(Node* node, bool deleteData)
{
	//node의 앞, 뒤를 구하면 읽기 쉬운 코드를 만들 수 있다.
	Node* before = node->prev;
	Node* after = node->next;

	//node의 이전 노드와 다음 노드를 연결해준다.
	before->next = after;
	after->prev = before;

	//node데이터와 node 자신을 제거한다
	if (deleteData)
		delete node->data;
	delete node;

}

void ShowNames(List* students)
{
	//페드 노드의 다음 노드부터 시작
	Node* current = students->head->next;

	while (current!=students->head)
	{
		//현재 노드의 데이터를 꺼내온다
		const Student* std = (Student*)current->data;
		
		//해당 학생의 이름을 출력한다.
		cout << std->name << endl;

		//다음 노드를 가리킨다
		current = current->next;
	}
}

//리스트를 제거한다
//리스트의 모든 노드와 데이터도 제거한다.
//list : 리스트
//deleteData : true 면 노드의 데이터도 제거한다.
void RemoveList(List* list, bool deleteData)
{
	//head 노드부터 마지막 노드까지 제거한다.
	Node* current = list->head;

	do
	{
		//현재 노드를 제거할 것이므로 다음노드 구현
		Node* current = list->head;
		
		//현재 노드와 노드의 데이터를 제거한다.
		if (deleteData)
			delete current->data;
		delete current;

		//현재 노드를 갱신한다.
		current = next;
	}
	while (current!= list->head)
	
		//while문에 도달해서 list->head가 가리키는 메모리는 해제되었지만 주소는 사용할 수 있다.
		//rmrhtdml fltmxm wprj
		delete list;
}