#include <iostream>

class myData{
    public:

    myData(){
        ID = 0;
        std::cout<< "default constructor"<<std::endl;
    }

    myData(int ID){
        std::cout<< "paramtised constructor"<<std::endl;
        this->ID = ID;
    }
    int ID;
    void setter(int ID){
        this->ID = ID;
    }
};

int main(){
    //myData obj;
    myData obj(1);
    myData obj2 = myData();
    std::cout << "ID1: " << obj.ID << std::endl;
    std::cout << "ID2: " << obj2.ID << std::endl;
    myData obj3 = myData(3);
    myData obj4{4}; //aggregate initialization
    std::cout << "ID3: " << obj3.ID << std::endl;
    std::cout << "ID4: " << obj4.ID << std::endl;

    return 0;  
}