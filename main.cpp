#include <iostream>
#include <ctime>
using namespace std;



int main() {
    int M;

    cout << "Enter the size of the array ";
    cin >> M;

    int* A = new int[M];
    int* C = new int[M];  

    for (size_t i = 0; i < M; i++)
    {
        A[i] = rand() % 100;
    }

    int choice;
    cout << "Enter 1 to delete even numbers or 2 to delete odd numbers ";
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "Wrong choise enter again ";
        cin >> choice;
    }

    cout << "Array: ";
    for (size_t i = 0; i < M; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    int k = 0;
    for (int i = 0; i < M; i++) {
        if ((choice == 1 && A[i] % 2 != 0) || (choice == 2 && A[i] % 2 == 0)) {
            C[k++] = A[i];
        }
    }

    cout << "Result: ";
    for (size_t i = 0; i < k; i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] C;
    system("pause");
    return 0;
}
