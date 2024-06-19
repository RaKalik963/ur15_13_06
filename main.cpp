#include <iostream>
#include <ctime>
using namespace std;





void inputArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool contains(const int* arr, int size, int elem) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == elem) {
            return true;
        }
    }
    return false;
}

int uniqueElementsAWithoutB(const int* A, int M, const int* B, int N, int* C) {
    int k = 0;
    for (int i = 0; i < M; ++i) {
        if (!contains(B, N, A[i]) && !contains(C, k, A[i])) {
            C[k++] = A[i];
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
    int* C = new int[M]; 

    cout << "Enter elements of array A: ";
    inputArray(A, M);

    cout << "Enter elements of array B: ";
    inputArray(B, N);

    int sizeC = uniqueElementsAWithoutB(A, M, B, N, C);

    cout << "Unique elements in A not in B: ";
    printArray(C, sizeC);

    delete[] A;
    delete[] B;
    delete[] C;

	return 0;
	system("pause");
}