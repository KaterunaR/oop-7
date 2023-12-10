#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;

public:
    Matrix() {}
    Matrix(size_t rows, size_t cols) : data(rows, vector<T>(cols)) {}

    // input
    friend istream& operator>>(istream& in, Matrix& matrix) {
        for (auto& row : matrix.data) {
            for (auto& element : row) {
                in >> element;
            }
        }
        return in;
    }

    // output
    friend ostream& operator<<(ostream& out, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& element : row) {
                out << element << ' ';
            }
            out << '\n';
        }
        return out;
    }

    // matrix + matrix
    Matrix operator+(const Matrix& other) const {
        Matrix result(data.size(), data[0].size());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // matrix * matrix
    Matrix operator*(const Matrix& other) const {
        size_t m = data.size();
        size_t n = data[0].size();
        size_t p = other.data[0].size();

        Matrix result(m, p);

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < p; ++j) {
                result.data[i][j] = 0;
                for (size_t k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // matrix * vector
    vector<T> operator*(const vector<T>& vector) const {
        size_t m = data.size();
        size_t n = data[0].size();

        std::vector<T> result(m, 0);

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                result[i] += data[i][j] * vector[j];
            }
        }

        return result;
    }
};

int main() {
    // ---int---
    Matrix<int> Matrix1(2, 2);
    Matrix<int> Matrix2(2, 2);

    cout << "Enter elements for intMatrix1:\n";
    cin >> Matrix1;

    cout << "Enter elements for intMatrix2:\n";
    cin >> Matrix2;

    Matrix<int> intAdd = Matrix1 + Matrix2;
    Matrix<int> intMult = Matrix1 * Matrix2;
    vector<int> intVector{ 1, 2 };
    vector<int> intVectorMult = Matrix1 * intVector;

    cout << "Addition Result:\n" << intAdd << '\n';
    cout << "Multiplication Result:\n" << intMult << '\n';
    cout << "Vector Multiplication Result:\n";
    for (const auto& element : intVectorMult) {
        cout << element << ' ';
    }
    cout << '\n';

    // ---float---
    Matrix<float> Matrix3(2, 2);
    Matrix<float> Matrix4(2, 2);

    cout << "Enter elements for floatMatrix1:\n";
    cin >> Matrix3;

    cout << "Enter elements for floatMatrix2:\n";
    cin >> Matrix4;

    Matrix<float> floatAdd = Matrix3 + Matrix4;
    Matrix<float> floatMult = Matrix3 * Matrix4;
    vector<float> floatVector{ 1.0, 2.0 };
    vector<float> floatVectorMult = Matrix3 * floatVector;

    cout << "Addition Result:\n" << floatAdd << '\n';
    cout << "Multiplication Result:\n" << floatMult << '\n';
    cout << "Vector Multiplication Result:\n";
    for (const auto& element : floatVectorMult) {
        cout << element << ' ';
    }
    cout << '\n';

    return 0;
}
