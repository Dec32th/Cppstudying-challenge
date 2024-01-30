#pragma once

List* CreateList();
void InsertNodeAfter(Node* node, void* data);
void RemoveNode(Node* node, bool deleteData);
void ShowNames(List* students);
void RemoveList(List* list, bool deleteData);