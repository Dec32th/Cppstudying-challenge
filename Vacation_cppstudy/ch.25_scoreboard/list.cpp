#include"list.h"

//링크드 리스트의 생성자
//fnDelete : 노드의 데이터를 제거할 때 호출할 함수의 주소
//deletedata : true면 노드의 데이터를 함께 제거한다.
List::List(FN_DELETE fnDelete, bool deleteData)
{
	//인자를 보관
	this->fnDel = fnDelete;
	this->deleteData = deleteData;

	//create headnode and initialize
	head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;
}

//linked list destructor
List::~List()
{
	//모든 노드를 제거한다
	RemoveAll();

	//헤드 노드를 제거한다
	delete head;
	head = 0;
}

//리스트의 모든 노드를 제거하고 데이터도 제거한다
void List::RemoveAll()
{
	//헤드 노드의 다음 노드부터 지운다
	//RemoveAll함수를 호출 후에도 List객체를 재사용하기 위함
	Node* current = head->next;

	while (current!= head)
	{
		//현재 노드를 지울 것이므로 다음노드를 구해준다
		Node* next = current->next;

		//현재 노드의 데이터를 제거한다
		if (deleteData)
		{
			if (fnDel)
				(*fnDel)(current->data);
			else
				delete current->data;
		}

		//현재 노드를 제거한다
		delete current;

		//current가 다음 노드를 가리키게 한다.
		current = next;
	}

	//헤드 노드를 초기화한다.
	head->next = head;
	head->prev = head;
}

//첫 번째 노드를 구한다
//반환값 : 리스트의 첫 번째 노드
Node* List::GetTail() const
{
	//헤드 노드의 이전 노드를 반환
	//헤드 ㄴ드 자기 자신도 가능!
	return head->prev;
}

//새로운 노드를 추가
//node : 이 노드 뒤에 새 노드가 추가
//data : 새 노드의 데이터
void List::InsertNodeAfter(Node* node, void* data)
{
	//삽입되려는 곳의 압, 뒤 노드를 구해놓으면 소스코드의 가독성 증가
	Node* before = node;
	Node* after = node->next;

	//새 노드를 만들고 초기화한다
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	//
}