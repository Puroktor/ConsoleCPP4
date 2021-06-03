#include <iostream>
#include <time.h>
#include <stdlib.h>

using std::cin;
using std::endl;
using std::cout;

int** generateMatrix(int n, int m) {
    int** mat = new int* [n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[m];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = rand();
    return mat;
}

int** newMatrix(int** mat, int n) {
    int** newMat = new int* [n/2];
    for (int i = 0; i < n / 2; i++) {
        newMat[i] = mat[i * 2+1];
    }
    return newMat;
}
void printMatrix(int** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << "------------------------------"<<endl;
}

void deleteMatrix(int** mat, int n, int m) {
    for (int i = 0; i < n; i++) 
        delete[] mat[i];
    delete[] mat;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Russian");
    int n, m;
    cout << "Введите количество строк:\n";
    cin >> n;
    cout << "Введите количество столбцов:\n";
    cin >> m;
    int** mat = generateMatrix(n,m);
    printMatrix(mat, n, m);
    int** newMat = newMatrix(mat,n);
    printMatrix(newMat, n / 2, m);
    deleteMatrix(mat, n, m);
    delete[] newMat;
}