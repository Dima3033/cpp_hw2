#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;
const int max_row = 10;
const int max_colm = 10;

void remove_column(int arr[max_row][max_colm], int rows, int& cols, int pos) {
    if (pos < 0 || pos >= cols) {
        cout << "Erorr try again" << endl;
        return;
    }
    for (int i = pos; i < cols - 1; i++) {
        for (int j = 0; j < rows; j++) {
            arr[j][i] = arr[j][i + 1];
        }
    }
    cols--;
}
int main() {
    srand(time(nullptr)); 
    int arr[max_row][max_colm];
    int rows = 3;
    int cols = 4;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    cout << "Starter ->" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    remove_column(arr, rows, cols, 1);
    cout << "\nRemove ||" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
