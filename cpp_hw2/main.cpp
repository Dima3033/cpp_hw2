#include <iostream>
#include <vector>
using namespace std;
void fill_matrix(vector<vector<int>>& matrix, int m, int n) {
    matrix.resize(m, vector<int>(n, 0));
    int count = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = count;
            count++;
        }
    }
}
void shift_rows(vector<vector<int>>& matrix, int m, int n, int k, int direction) {
    k %= m;
    if (direction == 0) {
        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].begin() + k);
            reverse(matrix[i].begin() + k, matrix[i].end());
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    else if (direction == 1) { 
        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end() - k);
            reverse(matrix[i].end() - k, matrix[i].end());
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
}
void shift_columns(vector<vector<int>>& matrix, int m, int n, int k, int direction) {
    k %= n;
    if (direction == 0) {
        for (int j = 0; j < n; j++) {
            vector<int> temp(m, 0);
            for (int i = 0; i < m; i++) {
                temp[i] = matrix[(i - k + m) % m][j];
            }
            for (int i = 0; i < m; i++) {
                matrix[i][j] = temp[i];
            }
        }
    }
    else if (direction == 1) { 
        for (int j = 0; j < n; j++) {
            vector<int> temp(m, 0);
            for (int i = 0; i < m; i++) {
                temp[i] = matrix[(i + k) % m][j];
            }
            for (int i = 0; i < m; i++) {
                matrix[i][j] = temp[i];
            }
        }
    }
}
void print_matrix(vector<vector<int>>& matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int m = 4, n = 5;
    vector<vector<int>> matrix;
    fill_matrix(matrix, m, n);
    print_matrix(matrix, m, n);
    shift_rows(matrix, m, n, 2, 0);
    print_matrix(matrix, m, n);
    shift_columns(matrix, m, n, 3, 1);
    print_matrix(matrix, m, n);

    return 0;
}
