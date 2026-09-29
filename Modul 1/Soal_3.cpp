#include <iostream>
using namespace std;

int main () {
    int x;

    cout << "Input: ";
    cin >> x;
    
    cout << "\nOutput: " << endl;

    int spasi = 3;

    for (int i = x; i >= 0; i--) {
        for (int s = 0; s < spasi + 2 * (x - i); s++) {
            cout << " ";
        }
      
    for (int j = i; j >= 1; j--) {
        cout << j << " ";
    }
    
    cout << "*";
       
    for (int j = 1; j <= i; j++) {
        cout << " " << j;
    }
    
        cout << endl;

    }

    return 0;

}