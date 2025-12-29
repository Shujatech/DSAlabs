#include <iostream>
using namespace std;

int main() {
    int salaries[10] = {55000, 32000, 78000, 45000, 67000, 29000, 51000, 63000, 48000, 72000};
    
    cout << "Original salaries: ";
    for(int i=0; i<10; i++) cout << salaries[i] << " ";
    cout << endl;
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9-i; j++) {
            if(salaries[j] > salaries[j+1]) {
                int temp = salaries[j];
                salaries[j] = salaries[j+1];
                salaries[j+1] = temp;
            }
        }
    }
    
    cout << "Sorted salaries: ";
    for(int i=0; i<10; i++) cout << salaries[i] << " ";
    
    return 0;
}
