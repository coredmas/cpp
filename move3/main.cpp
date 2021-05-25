#include <iostream>
#include <memory>

class MyType {

public:
    MyType(){std::cout << "MyType()"<< std::endl;}
    MyType(const MyType& other)
    {
        std::cout << "copy - MyType(const MyType& other)" << std::endl;
    }
    MyType& operator=(const MyType& other){std::cout << "assignment - MyType& operator=(const MyType& other)"<< std::endl;}
    MyType(MyType&& other) {std::cout << "move copy - MyType(MyType&& other)"<< std::endl;}
    MyType& operator=(MyType&& other) {std::cout << "move assignment - MyType& operator=(MyType&& other)"<< std::endl;}
    virtual ~MyType() {std::cout << "~MyType()" << std::endl;}

    virtual void test(){
        std::cout << "MyType->test" << std::endl;
    }
};

class ChildClassOfMyType: public MyType {
public:
    ChildClassOfMyType() {std::cout << "ChildClassOfMyType()"<< std::endl;}
    ChildClassOfMyType(const ChildClassOfMyType& other) { std::cout << "copy - ChildClassOfMyType(const ChildClassOfMyType& other)" << std::endl;}
    ChildClassOfMyType& operator=(const ChildClassOfMyType& other){std::cout << "assignment - ChildClassOfMyType& operator=(const ChildClassOfMyType& other)"<< std::endl;}
    ChildClassOfMyType(ChildClassOfMyType&& other) {std::cout << "move copy - ChildClassOfMyType(ChildClassOfMyType&& other)"<< std::endl;}
    ChildClassOfMyType& operator=(ChildClassOfMyType&& other) {std::cout << "move assignment - ChildClassOfMyType& operator=(ChildClassOfMyType&& other)"<< std::endl;}
    ~ChildClassOfMyType() {std::cout << "~ChildClassOfMyType()" << std::endl;}

    void test() override{
        std::cout << "ChildClassOfMyType->test" << std::endl;
    }
};

std::unique_ptr<MyType> MakeMyTypePtr()
{
    std::unique_ptr<ChildClassOfMyType> ptr(new ChildClassOfMyType{});
    // This call to std::move() is needed to convert from a pointer-to-the
    // child class to a pointer-to-the parent.
    return std::move(ptr);
    //return ptr;
}

MyType MakeMyType()
{
    ChildClassOfMyType ptr;
    // This call to std::move() is needed to convert from a pointer-to-the
    // child class to a pointer-to-the parent.
    //return std::move(ptr);
    return ptr;
}

//int main() {
//    std::unique_ptr<MyType> prt = MakeMyTypePtr();
//    std::unique_ptr<MyType> prt2;
//    std::unique_ptr<MyType> prt3;
//    prt2 = MakeMyTypePtr();
//    prt->test();
//    prt2->test();
//    prt3 = std::move(prt2);
//    return 0;
//}

int main() {
    MyType prt (MakeMyType());
//    MyType prt2;
//    MyType prt3;
//    prt2 = MakeMyType();
//    prt3 = std::move(prt2);
    return 0;
}