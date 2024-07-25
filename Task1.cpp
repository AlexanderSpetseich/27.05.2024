#include <iostream>
#include <vector>

using namespace std;

// Функция для транспонирования матрицы
vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int M = matrix.size(); // количество строк
    int N = matrix[0].size(); // количество столбцов

    vector<vector<int>> transposed(N, vector<int>(M)); // создаем новую матрицу N×M

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            transposed[j][i] = matrix[i][j]; // меняем строки и столбцы
        }
    }

    return transposed;
}

// Функция для вывода матрицы
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int M, N;
    cout << "Введите количество строк (M): ";
    cin >> M;
    cout << "Введите количество столбцов (N): ";
    cin >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    // Заполнение матрицы значениями
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> transposed = transpose(matrix);

    cout << "Транспонированная матрица:" << endl;
    printMatrix(transposed);

    return 0;
}