#include <iostream>
using namespace std;

int main() {
    int myNumbers[5] = {1, 2, 4, 7, 9};
    for (int i : myNumbers){
        cout << i << ' ';
    }
    cout << "\n";
    return 0;
}