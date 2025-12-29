#include <iostream>
using namespace std;
int main() {
    const int size=30;

    int roll[size]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    
    int PF[size]  = {85,90,75,66,88,92,55,77,81,63,70,86,79,82,69,91,58,73,89,94,60,72,83,95,68,87,74,80,76,99};
    int OOP[size] = {80,82,78,60,92,88,50,75,84,65,72,89,77,81,67,93,55,71,90,96,62,74,85,94,69,86,73,82,79,97};
    int DSA[size] = {79,88,74,58,90,85,52,70,83,62,68,87,76,80,66,92,57,72,88,95,61,73,84,96,67,89,75,81,78,98};

    int searchRoll;
    cout<<"Enter your roll number: ";
    cin>>searchRoll;

    bool found=false;
    int index=-1;
    for (int i=0;i<size;i++){
        if(roll[i]==searchRoll){
            found=true;
            index=i;
            break;
        }
    }

    if (!found){
        cout<<"\nStudent with roll number "<< searchRoll
             << "not found in the record.\n";
        return 0;
    }

    int total=PF[index]+OOP[index]+DSA[index];
    float percentage=(total/300.0f)*100;

    cout<<"Student Result";
    cout<<"Roll Number: "<<searchRoll<<endl;
    cout<<endl;
    cout<<"PF Marks :  "<<PF[index]<<endl;
    cout<<"OOP Marks:  "<<OOP[index]<<endl;
    cout<<"DSA Marks:  " << DSA[index]<<endl;
    cout<<endl;
    cout<<"Total Marks (300): "<<total<<endl;
    cout<<"Percentage:        "<<percentage<<" %\n";
    return 0;
}

