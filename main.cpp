#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void COUT(int mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << mas[i] << " ";
    COUT(mas, size, i + 1);
}

template <typename T>
void Sort(T* a, const int size, int i = 0) {
    T max = a[i];
    int imax = i;

    for (int j = i + 1; j < size; j++) {
        if (max < a[j]) {
            max = a[j];
            imax = j;
        }
    }

    a[imax] = a[i];
    a[i] = max;

    if (i < size - 2)
        Sort(a, size, i + 1);
}


int main() {
    srand((unsigned)time(0));
    setlocale(LC_CTYPE, "ukr");

    const int SIZE = 10;
    int a[SIZE];


    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 100;
    }

    cout << "Початковий масив: " << endl;
    COUT(a, SIZE);


    Sort(a, SIZE, 0);

    cout << "Вiдсортований масив за спаданням: " << endl;
    COUT(a, SIZE);

    return 0;
}