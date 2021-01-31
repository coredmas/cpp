#include <iostream>

int GetValue()
{
    return 10;
}
int& GetRefValue()
{
    static int ret = 10;
    return ret;
}
void SetValue(int a)
{

}

void SetRefValue(int& a)
{

}

void SetConstRefValue(const int& a)
{

}

void PrintNameTest0(std::string& name)
{

}
void PrintNameTest1(std::string& name)
{

}
void PrintNameTest1(const std::string& name)
{

}

void PrintNameTest2(const std::string& name)
{
    std::cout << "void PrintNameTest2(const std::string& name)" << std::endl;
}
void PrintNameTest2(std::string&& name)
{
    std::cout << "void PrintNameTest2(std::string&& name)" << std::endl;
}

void PrintNameTest3(std::string& name)
{
    std::cout << "void PrintNameTest3(std::string& name)" << std::endl;
}
void PrintNameTest3(const std::string& name)
{
    std::cout << "void PrintNameTest3(const std::string& name)" << std::endl;
}
void PrintNameTest3(std::string&& name)
{
    std::cout << "void PrintNameTest3(std::string&& name)" << std::endl;
}

int main() {
    int i = 10; //literals - rvalue
    int j = GetValue();//value that is returned from function -  rvalue
    //GetValue() = 10; // lvalue required as left operand of assignment

    int k = GetRefValue(); //lvalue ref
    GetRefValue() = 10;

    SetValue(i);//call function with lvalue
    SetValue(10);//call function with rvalue

    //func can take only lvalue ref
    SetRefValue(i);
    //int& x  = 10; //cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    const int& xx = 10;
    //SetRefValue(10);//cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

    //func can take both lvalue ref and rvalue
    SetConstRefValue(i);
    SetConstRefValue(10);

    std::string first_name = "Dmas "; //lvalue is from left side ,rvalue - right side
    std::string last_name = " Core";
    std::string full_name = first_name + last_name; //binary operators create rvalue
    PrintNameTest0(first_name);
    //PrintNameTes0(first_name + last_name);//cannot bind non-const lvalue reference of type ‘std::__cxx11::string& {aka std::__cxx11::basic_string<char>&}’ to an rvalue of type ‘std::__cxx11::basic_string<char>’
    PrintNameTest1(first_name);
    PrintNameTest1(first_name + last_name);

    PrintNameTest2(first_name);
    PrintNameTest2("Test");
    PrintNameTest2(first_name + last_name);
    //result
//    void PrintNameTest2(const std::string& name)
//    void PrintNameTest2(std::string&& name)
//    void PrintNameTest2(std::string&& name)

    PrintNameTest3(first_name);
    PrintNameTest3("Test");
    PrintNameTest3(first_name + last_name);
    //result
//    void PrintNameTest3(std::string& name)
//    void PrintNameTest3(std::string&& name)
//    void PrintNameTest3(std::string&& name)
    return 0;
}
