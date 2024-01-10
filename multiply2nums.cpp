// Find the multiplication of two positive integers
#include<iostream>
using namespace std;

int multiplyNum(int num1 , int num2){
    if(num2 == 1){
        return num1;
    }else{
        return  num1 + multiplyNum(num1,num2-1);
    }
}
int main( int argc , char * argv[]){
    if(argc != 3){
        cout<< "Usage: " << argv[0] << " <n> <n>" << endl;
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int prod = multiplyNum(num1 , num2);

    cout<< "Product : " << prod << endl;

    return 0;
}