//point array를 동적할당하여 사용하는 Sorted list 구현
#include <iostream>
using namespace std;

class SortedList {
private:
    int** arr;
    int capacity;
    int size;

public:
    SortedList(int max_items) {
        capacity = max_items;
        size = 0;
        arr = new int* [capacity];
    }

    ~SortedList() {
        for (int i = 0; i < size; ++i) {
            delete arr[i];
        }
        delete[] arr;
    }

    void insert(int item) {
        if (size == capacity) {
            cout << "List is full." << endl;
            return;
        }

        int* newItem = new int(item);
        int i;
        for (i = size - 1; i >= 0; --i) {
            if (*arr[i] > item) {
                arr[i + 1] = arr[i];
            }
            else {
                break;
            }
        }
        arr[i + 1] = newItem;
        ++size;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << *arr[i] << " ";
        }
        cout << endl;
    }
};

//2. que를 활용한 12번 가위바위보 승부 예측 게임 점수 계산 프로그램
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int getScore(string red, string blue) {
    if (red == blue) return 0;
    if ((red == "가위" && blue == "보") || (red == "바위" && blue == "가위") || (red == "보" && blue == "바위")) return -1;
    return 1;
}
//
//int main() {
//    vector<string> red = { "가위", "바위", "가위", "바위", "보", "보", "가위", "보", "가위", "보", "바위", "바위" };
//    vector<string> blue = { "바위", "보", "바위", "보", "가위", "보", "바위", "가위", "바위", "가위", "보", "가위" };
//
//    int score = 0;
//    int consecutiveWins = 0;
//
//    for (int i = 0; i < 12; ++i) {
//        int result = getScore(red[i], blue[i]);
//        if (result == 1) {
//            score += (1 + consecutiveWins);
//            ++consecutiveWins;
//        }
//        else {
//            consecutiveWins = 0;
//        }
//        score += result;
//    }
//
//    cout << "최종 점수: " << score << endl;
//    return 0;
//}

//3. 우선순위 큐를 이용한 일정관리 프로그램
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Task {
public:
    string name;
    int priority;

    Task(string n, int p) : name(n), priority(p) {}

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

class PriorityQueue {
private:
    priority_queue<Task> pq;

public:
    void insert(string task, int priority) {
        pq.push(Task(task, priority));
    }

    void remove() {
        if (pq.empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        pq.pop();
    }

    void display() {
        priority_queue<Task> copy = pq;
        while (!copy.empty()) {
            Task t = copy.top();
            cout << "Task: " << t.name << ", Priority: " << t.priority << endl;
            copy.pop();
        }
    }
};

//int main() {
//    PriorityQueue pq;
//    pq.insert("Task1", 1);
//    pq.insert("Task2", 3);
//    pq.insert("Task3", 2);
//
//    pq.display();
//    cout << "---" << endl;
//
//    pq.remove();
//    pq.display();
//
//    return 0;
//}

//4. 회문 확인 프로그램
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    if (start >= end) return true;
    if (tolower(str[start]) != tolower(str[end])) return false;
    return isPalindrome(str, start + 1, end - 1);
}

//int main() {
//    string input;
//    cout << "문자열을 입력하시오: ";
//    getline(cin, input);
//
//    // 공백과 특수문자 제거
//    input.erase(remove_if(input.begin(), input.end(), [](char c) { return !isalnum(c); }), input.end());
//
//    if (isPalindrome(input, 0, input.length() - 1)) {
//        cout << "회문입니다." << endl;
//    }
//    else {
//        cout << "회문이 아닙니다." << endl;
//    }
//    return 0;
//}


//5. DFS와 deleteedge구현 
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    list<int>* adj;

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void removeEdge(int v, int w) {
        adj[v].remove(w);
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        DFSUtil(v, visited);
        cout << endl;
    }
};

//int main() {
//    Graph g(5);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 0);
//    g.addEdge(2, 3);
//    g.addEdge(3, 3);
//
//    cout << "DFS starting from vertex 2:\n";
//    g.DFS(2);
//
//    g.removeEdge(2, 0);
//    cout << "DFS after removing edge 2-0:\n";
//    g.DFS(2);
//
//    return 0;
//}


//tree 구현. - 삭제, item 삽입
//#include <iostream>
//#include <queue>
//using namespace std;
//
//class TreeNode {
//public:
//    int data;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
//};
//
//class BinaryTree {
//private:
//    TreeNode* root;
//
//public:
//    BinaryTree() : root(nullptr) {}
//
//    void insert(int key) {
//        if (root == nullptr) {
//            root = new TreeNode(key);
//            return;
//        }
//
//        queue<TreeNode*> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            TreeNode* temp = q.front();
//            q.pop();
//
//            if (!temp->left) {
//                temp->left = new TreeNode(key);
//                break;
//            }
//            else {
//                q.push(temp->left);
//            }
//
//            if (!temp->right) {
//                temp->right = new TreeNode(key);
//                break;
//            }
//            else {
//                q.push(temp->right);
//            }
//        }
//    }
//
//    void inorder() {
//        if (root == nullptr) return;
//
//        stack<TreeNode*> stack;
//        TreeNode* curr = root;
//
//        while (curr != nullptr || !stack.empty()) {
//            while (curr != nullptr) {
//                stack.push(curr);
//                curr = curr->left;
//            }
//
//            curr = stack.top();
//            stack.pop();
//
//            cout << curr->data << " ";
//
//            curr = curr->right;
//        }
//    }
//
//    void preorder() {
//        if (root == nullptr) return;
//
//        stack<TreeNode*> stack;
//        stack.push(root);
//
//        while (!stack.empty()) {
//            TreeNode* node = stack.top();
//            stack.pop();
//            cout << node->data << " ";
//
//            if (node->right) stack.push(node->right);
//            if (node->left) stack.push(node->left);
//        }
//    }
//
//    void postorder() {
//        if (root == nullptr) return;
//
//        stack<TreeNode*> stack1, stack2;
//        stack1.push(root);
//
//        while (!stack1.empty()) {
//            TreeNode* node = stack1.top();
//            stack1.pop();
//            stack2.push(node);
//
//            if (node->left) stack1.push(node->left);
//            if (node->right) stack1.push(node->right);
//        }
//
//        while (!stack2.empty()) {
//            cout << stack2.top()->data << " ";
//            stack2.pop();
//        }
//    }
//
//    TreeNode* find(int key) {
//        if (root == nullptr) return nullptr;
//
//        queue<TreeNode*> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            TreeNode* node = q.front();
//            q.pop();
//
//            if (node->data == key) {
//                return node;
//            }
//
//            if (node->left) q.push(node->left);
//            if (node->right) q.push(node->right);
//        }
//
//        return nullptr;
//    }
//
//    void deleteItem(int key) {
//        if (root == nullptr) return;
//
//        queue<TreeNode*> q;
//        q.push(root);
//
//        TreeNode* keyNode = nullptr;
//        TreeNode* temp = nullptr;
//
//        while (!q.empty()) {
//            temp = q.front();
//            q.pop();
//
//            if (temp->data == key) {
//                keyNode = temp;
//            }
//
//            if (temp->left) q.push(temp->left);
//            if (temp->right) q.push(temp->right);
//        }
//
//        if (keyNode != nullptr) {
//            int x = temp->data;
//            deleteDeepest(temp);
//            keyNode->data = x;
//        }
//    }
//
//    void deleteDeepest(TreeNode* delNode) {
//        queue<TreeNode*> q;
//        q.push(root);
//
//        TreeNode* temp;
//        while (!q.empty()) {
//            temp = q.front();
//            q.pop();
//
//            if (temp == delNode) {
//                temp = nullptr;
//                delete delNode;
//                return;
//            }
//
//            if (temp->right) {
//                if (temp->right == delNode) {
//                    temp->right = nullptr;
//                    delete delNode;
//                    return;
//                }
//                else {
//                    q.push(temp->right);
//                }
//            }
//
//            if (temp->left) {
//                if (temp->left == delNode) {
//                    temp->left = nullptr;
//                    delete delNode;
//                    return;
//                }
//                else {
//                    q.push(temp->left);
//                }
//            }
//        }
//    }
//
//    TreeNode* retrieveItem(int key) {
//        return find(key);
//    }
//};
//
//int main() {
//    BinaryTree bt;
//    bt.insert(10);
//    bt.insert(11);
//    bt.insert(7);
//    bt.insert(9);
//    bt.insert(15);
//    bt.insert(8);
//
//    cout << "Inorder traversal: ";
//    bt.inorder();
//    cout << endl;
//
//    cout << "Preorder traversal: ";
//    bt.preorder();
//    cout << endl;
//
//    cout << "Postorder traversal: ";
//    bt.postorder();
//    cout << endl;
//
//    TreeNode* found = bt.find(9);
//    if (found) {
//        cout << "Found node with key 9: " << found->data << endl;
//    }
//    else {
//        cout << "Node with key 9 not found." << endl;
//    }
//
//    bt.deleteItem(7);
//    cout << "Inorder traversal after deleting 7: ";
//    bt.inorder();
//    cout << endl;
//
//    TreeNode* retrieved = bt.retrieveItem(15);
//    if (retrieved) {
//        cout << "Retrieved node with key 15: " << retrieved->data << endl;
//    }
//    else {
//        cout << "Node with key 15 not found." << endl;
//    }
//
//    return 0;
//}

//
