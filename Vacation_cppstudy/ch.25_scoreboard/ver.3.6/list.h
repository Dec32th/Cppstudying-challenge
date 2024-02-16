#pragma once

// 하나의 데이터를 보관할 클래스
class Node
{
	//list 클래스에서 모든 멤버에 접근 가능하도록
	friend class List;

public:
	Node* GetNext() const;
	Node* GetPrev() const;
	void* GetData() const;

private:
	Node* prev;			//이전 Node 구조체
	Node* next;			//다음 Node 구조체
	void* data;			//데이터에 대한 포인터
};

//전체 리스트를 관리하는 클래스
class List
{
public:
	//데이터 제거를 위한 함수의 포인터
	typedef void(*FN_DELETE)(void*);

	List(FN_DELETE fnDelet = 0, bool deleteData = true);
	~List();

	void InsertNodeAfter(Node* node, void* data);
	void RemoveNode(Node* node);
	Node* GetHead() const;
	Node* GetTail() const;

	void RemoveAll();

private:
	Node* head;			//헤드(더미) 노드
	bool deleteData;	//리스트, 노드 제거 시 데이터 제거 여부
	FN_DELETE fnDel;	//데이터 제거 시 호출할 함수
};