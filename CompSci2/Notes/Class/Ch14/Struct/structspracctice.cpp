#include<iostream>
#include<vector>

using namespace std;

struct PayRoll{

    int empNumber;
    double payRate;

};

int main(){
    int x;
    x = 5;
    vector<int> vec1;
    vector<int*> vec2;
    
    PayRoll deptHead;
    deptHead.empNumber = 555;
    
    vector<PayRoll> vec3;
    vec3.push_back(deptHead);
    
    vector<PayRoll*> vec4;
    
    PayRoll * payRollPtr = nullptr;
    payRollPtr = new PayRoll;
    
    (*payRollPtr).empNumber = 55;
    payRollPtr->payRate = 16.50;
    //cout << "payRollPtr empNumber: " << (*payRollPtr).empNumber << endl;
    //cout << "payRollPtr empNumber: " << payRollPtr->empNumber << endl;
    //cout << "payRollPtr payRate: " << payRollPtr->payRate << endl;
    vec4.push_back(payRollPtr);
    
    PayRoll * payRollPtr2 = new PayRoll;
    
    payRollPtr2->empNumber = 5;
    payRollPtr2->payRate = 75.75;
    vec4.push_back(payRollPtr2);
    
    //print out all structs in the vector
    for(int i = 0; i < vec4.size(); i++){
    
        cout << "Employee Number: " << vec4[i]->empNumber << endl;
        cout << "Pay Rate: " << vec4[i]->payRate << endl;
        cout << "--------------------------------" << endl;
    
    }
    
    // delete each struct from the vector
    for(int i = 0; i < vec4.size(); i++){
        
        delete vec4[i];

    }
    
    return 0;
}
