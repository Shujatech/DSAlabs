#include <iostream>
using namespace std;

int main() {
    int rollNumbers[] = {101, 110, 125, 132, 150, 175, 200};
    int size = 7; 
    int choice, target, resultIndex = -1;
    cout << "--- Student Record System ---" << endl;
    cout << "1. Linear Search (Check every slot)" << endl;
    cout << "2. Binary Search (Fast search for sorted list)" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cout << "Enter Roll Number to find: ";
    cin >> target;
    if (choice == 1) {
        for (int i = 0; i < size; i++) {
            if (rollNumbers[i] == target) {
                resultIndex = i;
                break; 
            }
        }
    } 
    else if (choice == 2) {
        int low = 0;
        int high = size - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (rollNumbers[mid] == target) {
                resultIndex = mid;
                break;
            } else if (rollNumbers[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    if (resultIndex != -1) {
        cout << "Student found at record index: " << resultIndex << endl;
    } else {
        cout << "Student not found in the system." << endl;
    }
    return 0;
}
