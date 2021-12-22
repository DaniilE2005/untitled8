#ifndef UNTITLED_MATRIX_H

#include <bits/stdc++.h>

using namespace std;

template <typename T>

class MATRIX {
    T** C;
    long long a, b;

public:
    MATRIX();
    MATRIX(long long x, long long y);
    MATRIX operator=(const MATRIX& D);
    MATRIX operator+(const MATRIX& D);
    MATRIX operator*(long long);
    MATRIX operator*(const MATRIX& D);
    MATRIX operator^(long long i);
    MATRIX operator&();
    const T* operator[](long long i) const {
        return C[i];
    }
    T* operator[](long long i) {
        return C[i];
    }
    int func1(long long i, long long j) {
        return C[i][j];
    }
    void func2(long long i, long long j, T z) {
        C[i][j] = z;
    }
    void func3() {
        for (long long i = 0; i < a; i++) {
            for (long long j = 0; j < b; j++) {
                cout << C[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << " " << "\n";
    }
};

template<typename T>
MATRIX<T>::MATRIX() {
    b = 0, a = 0;
}

template<typename T>
MATRIX<T>::MATRIX(long long x, long long y) {
    a = x, b = y, C = (T**) new T*[a];
    for (int i = 0; i < a; i++) {
        C[i] = (T *) new T[b];
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            C[i][j] = 0;
        }
    }
}

template<typename T>
MATRIX<T> MATRIX<T>::operator=(const MATRIX& D) {
    if (b > 0) {
        for (int i = 0; i < a; i++) {
            delete[] C[i];
        }
    }
    if (a > 0) {
        delete[] C;
    }
    a = D.a, b = D.b, C = (T**) new T*[a];
    for (int i = 0; i < a; i++) {
        C[i] = (T *) new T[b];
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            C[i][j] = D.C[i][j];
        }
    }
    return *this;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator+(const MATRIX& D) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            C[i][j] += D.C[i][j];
        }
    }
    return *this;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator*(long long a) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            C[i][j] *= a;
        }
    }
    return *this;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator*(const MATRIX& D) {
    MATRIX<T> E(a, D.b);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < D.b; j++) {
            E[i][j] = 0;
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < D.b; j++) {
            for (int l = 0; l < b; l++) {
                E[i][l] += C[i][l] * D[l][j];
            }
        }
    }
    return E;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator^(long long i) {
    MATRIX<T> E(a, b);
    MATRIX<T> D(a, b);
    for (int j = 0; j < a; j++) {
        for (int l = 0; l < b; l++) {
            E[j][l] = D[j][l] = C[j][l];
        }
    }
    for (int j = 0; j < i - 1; j++) {
        E *= D;
    }
    return E;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator&() {
    MATRIX<T> E(b, a);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            E[j][i] = C[i][j];
        }
    }
    return E;
}
#define UNTITLED_MATRIX_H

#endif //UNTITLED_MATRIX_H