#include <iostream>
#include <ctime>
using namespace std;



bool contains(const int* arr, int size, int elem) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == elem) {
            return true;
        }
    }
    return false;
}

int uniqueElementsAandB(const int* A, int M, const int* B, int N, int* C) {
    int k = 0;

    for (int i = 0; i < M; ++i) {
        if (!contains(B, N, A[i]) && !contains(C, k, A[i])) {
            C[k++] = A[i];
        }
    }

    for (int i = 0; i < N; ++i) {
        if (!contains(A, M, B[i]) && !contains(C, k, B[i])) {
            C[k++] = B[i];
        }
    }

    return k;
}

int main() {
    int M, N;

    cout << "Enter the size of array A: ";
    cin >> M;
    cout << "Enter the size of array B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];
    int* C = new int[M + N]; 

    for (size_t i = 0; i < M; i++)
    {
        A[i] = rand() % 15;
    }

    for (size_t i = 0; i < N; i++)
    {
        B[i] = rand() % 15;
    }

    cout << "Array1: ";
    for (size_t i = 0; i < M; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;


    cout << "Array2: ";
    for (size_t i = 0; i < N; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;


    int sizeC = uniqueElementsAandB(A, M, B, N, C);

    cout << "Unique elements in A and B not common: ";
    for (int i = 0; i < sizeC; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;
	return 0;
	system("pause");
}