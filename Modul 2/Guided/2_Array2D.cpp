#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai [i][j] << " ";
        }

        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl;

    return 0;
}