#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;
const int max_row = 10;
const int max_colm = 10;
void add_column(int arr[max_row][max_colm], int rows, int& cols, int pos) {

    if (pos < 0 || pos > cols) {
        cout << "Error: Invalid position!" << endl;
        return;
    }
    for (int i = cols; i > pos; i--) {
        for (int j = 0; j < rows; j++) {
            arr[j][i] = arr[j][i - 1];
        }
    }
    for (int i = 0; i < rows; i++) {
        arr[i][pos] = rand() % 100; 
    }
    cols++;
}
int main() {
    srand(time(nullptr)); 
    int arr[max_row][max_colm];
    int rows = 3;
    int cols = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100; 
        }
    }
    add_column(arr, rows, cols, 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
