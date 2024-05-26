#include <string>
#include <fstream>
typedef char ItemType;
struct TreeNode;
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
public:
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree); 
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int LengthIs() const; 
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  void GetNextItem (ItemType& item, OrderType order, 
       bool& finished);
  void Print(std::ofstream& outFile) const;
  TreeNode* GetRoot() const;
  bool Imp_IsBST(TreeNode* tree, ItemType &min, ItemType &max);
  //노드가 가지고 있는 값을 비교하여 binary search tree인지 binary tree인지를 검사
  bool IsBST();

private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

