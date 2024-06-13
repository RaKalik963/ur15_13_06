#include <iostream>
#include <ctime>
using namespace std;




bool exists(int* arr, int size, int value) 
{
    if (size == 0) return false;
    if (arr[size - 1] == value) return true;
    return exists(arr, size - 1, value);
}

void findCommon(int* A, int M, int* B, int N, int* common, int& commonSize, int i = 0, int j = 0) 
{
    if (i >= M) return;
    if (j >= N) {
        findCommon(A, M, B, N, common, commonSize, i + 1, 0);
        return;
    }
    if (A[i] == B[j] && !exists(common, commonSize, A[i])) {
        common[commonSize++] = A[i];
    }
    findCommon(A, M, B, N, common, commonSize, i, j + 1);
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    int M, N;

    cout << "Enter the size of array A: ";
    cin >> M;
    cout << "Enter the size of array B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    for (size_t i = 0; i < M; i++)
    {
        A[i] = rand() % 10;
    }


    for (size_t i = 0; i < N; i++)
    {
        B[i] = rand() % 10;
    }


    cout << "Array ";
    for (size_t i = 0; i < M; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Array ";
    for (size_t i = 0; i < N; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;

    int maxCommonSize = (M < N) ? M : N;
    int* common = new int[maxCommonSize];
    int commonSize = 0;

    findCommon(A, M, B, N, common, commonSize);

    cout << "Common elements  repetition: ";
    printArray(common, commonSize);

    delete[] A;
    delete[] B;
    delete[] common;

	return 0;
	system("pause");
}