#include <iostream>
#include <ctime>
using namespace std;


void unite_arrays(int* A, int M, int* B, int N, int* C) {
    for (int i = 0; i < M; i++) {
        C[i] = A[i];
    }
    for (int i = 0; i < N; i++) {
        C[M + i] = B[i];
    }
}


int main() 
{
    srand(time(0));

    int M, N;
    cout << "enter size of array A ";
    cin >> M;
    int* A = new int[M];

    for (size_t i = 0; i < M; i++)
    {
        A[i] = rand() % 10;
    }

    cout << "enter size of array B ";
    cin >> N;
    int* B = new int[N];

    for (size_t i = 0; i < N; i++)
    {
        B[i] = rand() % 10;
    }

    cout << "Array ";
    for (size_t i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Array ";
    for (size_t i = 0; i < M; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;


    int* C = new int[M + N];
    unite_arrays(A, M, B, N, C);

    cout << "combined array ";
    for (int i = 0; i < M + N; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
	system("pause");
}