//Practice 12 #3 Smart pointer(shared pointer) 

//smartpointer 중에서도 공유해서 사용할 수 있는 shared ppinter가 어떻게 동작하는지를 structure를 이용해서 확인한다.

#include <iostream>
#include <vector>
#include <algorithm>

//동작을 확인하기 위한 structure 소멸자 Destr.: x 를 출력해서 값과 소멸함을 알려준다.
struct Data {
    int x;
    Data(int x = 0) : x(x) {}
    ~Data() {
        std::cout << "Destr.: " << x << std::endl;
    }
};

//<<operator overloading ostream 객체인 os에 값을 전달해서 그 값을 출력하도록함.
std::ostream& operator << (std::ostream& os, const Data& d) {
    os << d.x;
    return os;
}


//template을 이용해서 shared pointer의 타입을 유동적으로 사용할 수 있도록 한다.
template <class T>
class A {
    std::shared_ptr<T> p;
public:
    A(int x = 0) : p(new T(x)) {}
    //get함수를 통해서 새로운 값을 생성하는 것이 아니라 기존의 값을 가져온다.
    T& get() const {
        return *p;
    }

    //copy함수를 이용해서 p의 값이 x를 가리키도록 한다. 추가로 a는 새로 만들어진다. 
    //copy함수를 쓸 때마다, 새로 instance가 생성된다.
    A copy() {
        A a(p->x);
        return a;
    }
};

//main함수에서 값이 없을 경우 0이 되고, copy로 새로운 instance를 만들어서 그것을 가리키게 되는 경우에는 기존 값이 소멸한다.
int main() {
    A<Data> a1, a2(10), a3(20), a4(30);
    std::cout << a1.get() << std::endl;
    std::cout << a2.get() << std::endl;
    std::cout << a3.get() << std::endl;
    std::cout << a4.get() << std::endl;
    a1 = a2.copy();

    //대입을 통해서 가리키는 경우에는 shared pointer가 기존에 가리키던 값을 자동으로 소멸시키고 공통으로 a4의 값을 가리키게 하기 때문에 가능하다.
    a3 = a4;
    std::cout << a1.get() << std::endl;
    std::cout << a2.get() << std::endl;
    std::cout << a3.get() << std::endl;
    std::cout << a4.get() << std::endl;
    //stack이기 때문에 가장 나중에 생성된 a4부터 삭제된다.
}
