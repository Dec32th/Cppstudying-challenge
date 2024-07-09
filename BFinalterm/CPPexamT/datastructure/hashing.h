//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//
//// 해시 함수를 정의합니다.
//int hashFunction(int key, int tableSize) {
//    return key % tableSize;
//}
//
//// 버킷 방식 해시 테이블 클래스
//class BucketHashTable {
//private:
//    int tableSize;
//    std::vector<std::list<int>> table; // 각 버킷은 리스트로 구현합니다.
//
//public:
//    BucketHashTable(int size) : tableSize(size), table(size) {}
//
//    void insert(int key) {
//        int index = hashFunction(key, tableSize);
//        table[index].push_back(key);
//    }
//
//    bool search(int key) {
//        int index = hashFunction(key, tableSize);
//        for (int item : table[index]) {
//            if (item == key) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void remove(int key) {
//        int index = hashFunction(key, tableSize);
//        table[index].remove(key);
//    }
//
//    void display() {
//        for (int i = 0; i < tableSize; ++i) {
//            std::cout << "Bucket " << i << ": ";
//            for (int item : table[i]) {
//                std::cout << item << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
//};
//
//int main() {
//    BucketHashTable ht(7); // 크기가 7인 해시 테이블 생성
//
//    ht.insert(10);
//    ht.insert(20);
//    ht.insert(15);
//    ht.insert(7);
//    ht.insert(17);
//
//    ht.display();
//
//    std::cout << "Searching 15: " << (ht.search(15) ? "Found" : "Not Found") << std::endl;
//    std::cout << "Searching 21: " << (ht.search(21) ? "Found" : "Not Found") << std::endl;
//
//    ht.remove(15);
//    ht.display();
//
//    return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//
//// 해시 함수를 정의합니다.
//int hashFunction(int key, int tableSize) {
//    return key % tableSize;
//}
//
//// 체인 방식 해시 테이블 클래스
//class ChainHashTable {
//private:
//    int tableSize;
//    std::vector<std::list<int>> table; // 각 체인은 리스트로 구현합니다.
//
//public:
//    ChainHashTable(int size) : tableSize(size), table(size) {}
//
//    void insert(int key) {
//        int index = hashFunction(key, tableSize);
//        table[index].push_back(key);
//    }
//
//    bool search(int key) {
//        int index = hashFunction(key, tableSize);
//        for (int item : table[index]) {
//            if (item == key) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void remove(int key) {
//        int index = hashFunction(key, tableSize);
//        table[index].remove(key);
//    }
//
//    void display() {
//        for (int i = 0; i < tableSize; ++i) {
//            std::cout << "Chain " << i << ": ";
//            for (int item : table[i]) {
//                std::cout << item << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
//};
//
//int main() {
//    ChainHashTable ht(7); // 크기가 7인 해시 테이블 생성
//
//    ht.insert(10);
//    ht.insert(20);
//    ht.insert(15);
//    ht.insert(7);
//    ht.insert(17);
//
//    ht.display();
//
//    std::cout << "Searching 15: " << (ht.search(15) ? "Found" : "Not Found") << std::endl;
//    std::cout << "Searching 21: " << (ht.search(21) ? "Found" : "Not Found") << std::endl;
//
//    ht.remove(15);
//    ht.display();
//
//    return 0;
//}
