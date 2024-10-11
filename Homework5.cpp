#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/*int main() {
    int rows, cols;
    unsigned long long num;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    cout << "Enter the starting number: ";
    cin >> num;

    unsigned long long** arr = new unsigned long long* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new unsigned long long[cols];
    }

    arr[0][0] = num;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) continue;
            if (j == 0) {
                arr[i][j] = arr[i - 1][cols - 1] * 2;
            }
            else {
                arr[i][j] = arr[i][j - 1] * 2;
            }

            if (arr[i][j] > 1e18) { // Limit the values to avoid overflow
                arr[i][j] = 0;
            }
        }
    }

    cout << "\nGenerated Array:\n";
    cout << "-------------------------------\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(18) << arr[i][j];
        }
        cout << endl;
    }
    cout << "-------------------------------\n";

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
*/

/*int main() {
    int rows, cols, num;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    cout << "Enter the starting number: ";
    cin >> num;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    arr[0][0] = num;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) continue;
            if (j == 0) {
                arr[i][j] = arr[i - 1][cols - 1] + 1;
            }
            else {
                arr[i][j] = arr[i][j - 1] + 1;
            }
        }
    }

    cout << "\nGenerated Array:\n";
    cout << "-------------------------------\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    cout << "-------------------------------\n";

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}*/

void printArray(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << "---------------------\n";
}

void shiftRight(vector<vector<int>>& arr, int shifts) {
    int rows = arr.size();
    int cols = arr[0].size();
    shifts %= cols;
    if (shifts == 0) return;

    for (int i = 0; i < rows; i++) {
        vector<int> newRow(cols);
        for (int j = 0; j < cols; j++) {
            newRow[(j + shifts) % cols] = arr[i][j];
        }
        arr[i] = newRow;
    }
}

void shiftLeft(vector<vector<int>>& arr, int shifts) {
    int rows = arr.size();
    int cols = arr[0].size();
    shifts %= cols;
    if (shifts == 0) return;

    for (int i = 0; i < rows; i++) {
        vector<int> newRow(cols);
        for (int j = 0; j < cols; j++) {
            newRow[j] = arr[i][(j + shifts) % cols];
        }
        arr[i] = newRow;
    }
}

void shiftDown(vector<vector<int>>& arr, int shifts) {
    int rows = arr.size();
    int cols = arr[0].size();
    shifts %= rows;
    if (shifts == 0) return;

    vector<vector<int>> newArr(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        newArr[(i + shifts) % rows] = arr[i];
    }
    arr = newArr;
}

void shiftUp(vector<vector<int>>& arr, int shifts) {
    int rows = arr.size();
    int cols = arr[0].size();
    shifts %= rows;
    if (shifts == 0) return;

    vector<vector<int>> newArr(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        newArr[i] = arr[(i + shifts) % rows];
    }
    arr = newArr;
}

int main() {
    int rows, cols, shifts;
    char direction;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> arr(rows, vector<int>(cols));

    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    cout << "Original Array:\n";
    printArray(arr);

    cout << "Enter the number of shifts: ";
    cin >> shifts;
    cout << "Enter the direction (L - left, R - right, U - up, D - down): ";
    cin >> direction;

    switch (direction) {
    case 'R': case 'r':
        shiftRight(arr, shifts);
        break;
    case 'L': case 'l':
        shiftLeft(arr, shifts);
        break;
    case 'D': case 'd':
        shiftDown(arr, shifts);
        break;
    case 'U': case 'u':
        shiftUp(arr, shifts);
        break;
    default:
        cout << "Invalid direction\n";
        return 1;
    }

    cout << "Shifted Array:\n";
    printArray(arr);

    return 0;
}