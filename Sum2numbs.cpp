// sum of two numbers

#include<iostream>
using namespace std;

int addNumbers( int num1 , int num2){
    if(num2 == 0 ){
        return num1;
    }else{
        return addNumbers(num1 + 1, num2 - 1);
    }
}

int main( int argc , char * argv[]){
    if(argc != 3){
        cout << "Usage: " << argv[0] << " <n> <n>" << endl;
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int sum = addNumbers(num1, num2);
    cout<< "sum :" << sum << endl;
    return 0; 

}
  
