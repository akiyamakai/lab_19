#include <iostream>

template <typename T, size_t rows, size_t cols>
T findMinElement(T(&matrix)[rows][cols]) {
    T minElement = matrix[0][0];
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
            }
        }
    }
    return minElement;
}

template <typename T, size_t rows, size_t cols>
void sortMainDiagonal(T(&matrix)[rows][cols]) {
    size_t minDimension = std::min(rows, cols);


    for (size_t i = 0; i < minDimension; ++i) {
        for (size_t j = 0; j < minDimension - i - 1; ++j) {
            if (matrix[j][j] > matrix[j + 1][j + 1]) {
                T temp = matrix[j][j];
                matrix[j][j] = matrix[j + 1][j + 1];
                matrix[j + 1][j + 1] = temp;
            }
        }
    }
}

int main() {
    int matrix[4][3] = {
        {16, 2,  3},
        {5,  11, 10},
        {9,  7,  6},
        {4,  14, 15}
    };

    std::cout << "Initial matrix:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int minElement = findMinElement(matrix);
    std::cout << "Minimum element: " << minElement << std::endl;

    sortMainDiagonal(matrix);

    std::cout << "Matrix after sorting the main diagonal:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
