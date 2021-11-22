#include <vector>
#include <string>
#include <ostream>
#include <algorithm>
#include <iostream>

void condition_print_pred(std::string& current_str){

    if(current_str.length()==0)
        return;

    if(current_str[0] % 2 == 0){
        std::cout<<"odd one "<< current_str <<std::endl;
    }else{
        std::cout<<"even one "<< current_str <<std::endl;
    }
}

bool condition_sort_pred(const std::string& first_str,const std::string& second_str){

    if(first_str[0] % 2 == 0 && second_str[0] % 2 != 0){
        return true;
    }else  if(first_str[0] % 2 != 0 && second_str[0] % 2 == 0){
        return false;
    }
    return false;
}

void print_vec(std::vector<std::string>& list_of_names)
{
    std::for_each(list_of_names.begin(),list_of_names.end(),condition_print_pred);
}

void swap_str(std::vector<std::string>::iterator left_str,std::vector<std::string>::iterator right_str)
{
    std::string tmp = *left_str;
    *left_str = *right_str;
    *right_str = tmp;
    int i = 0;
}

void swap_test(std::vector<std::string>& list_of_names){
    auto begin_left = list_of_names.begin();
    auto begin_right = list_of_names.end();
    begin_right--;
    while(begin_left < begin_right)
    {
        while(begin_left != list_of_names.end()){
            //try to find even
            if((*begin_left)[0] % 2 == 0){
                begin_left++;
            }else{
                std::cout<<"even "<< *begin_left <<std::endl;
                break;
            }
        }
        while(begin_right != list_of_names.begin()){
            //try to find odd
            if((*begin_right)[0] % 2 != 0){
                begin_right--;
            }else{
                std::cout<<"odd "<< *begin_right <<std::endl;
                break;
            }
        }
        std::cout << "swap  " << *begin_left << " " << *begin_right << std::endl;
        swap_str(begin_left, begin_right);
        begin_left++;
        begin_right--;
    }
}

int main() {

    std::vector<std::string> list_of_names {
            "Tonisha",
            "Tiffiny",
            "Neta",
            "Joshua",
            "Emeline",
            "Catalina",
            "Jessie",
            "Emil",
            "Tammara",
            "Boyd",
            "Marlen",
            "Marianela",
            "Donte",
            "Leonora",
            "Hattie",
            "Shemeka",
            "Katharina",
            "Art",
            "Theresia",
            "Tabetha"
    };
    std::cout<<"start testing"<<std::endl;
    print_vec(list_of_names);
    std::cout<<std::endl;
    std::cout<<"testing..."<<std::endl;
    //std::sort(list_of_names.begin(),list_of_names.end(),condition_sort_pred);
    // std::cout<<std::endl;
    // std::cout<<"result O-log(n)"<<std::endl;
    // print_vec(list_of_names);

    swap_test(list_of_names);
    std::cout<<std::endl;
    std::cout<<"result O-n"<<std::endl;
    print_vec(list_of_names);
    return 0;
}
