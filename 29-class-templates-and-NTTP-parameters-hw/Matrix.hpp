template <typename T>
Matrix<T>::Matrix() {}

template <typename T>
Matrix<T>::Matrix(int rows, int cols) {
    this->rows = (rows < 0) ? 0 : rows;
    this->cols = (cols < 0) ? 0 : cols;

    if (this->rows > 0 && this->cols > 0) {
        dataMatrix = new T[this->rows * this->cols]();
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    dataMatrix = new T[rows * cols];
    for (int indexRows = 0; indexRows < rows * cols; indexRows++) {
        dataMatrix[indexRows] = other.dataMatrix[indexRows];
    }
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) {
        delete[] dataMatrix;
        rows = other.rows;
        cols = other.cols;
        dataMatrix = new T[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            dataMatrix[i] = other.dataMatrix[i];
        }
    }
    return *this;
}

template <typename T>
Matrix<T>::~Matrix() {
    delete[] dataMatrix;
    dataMatrix = nullptr;
}

template <typename T>
void Matrix<T>::set(int rows, int cols, const T& value) {
    if (0 > rows || this->rows <= rows || 0 > cols || this->cols <= cols) {
        std::cout << "ПОМИЛКА! Неправильні координати!\n";
        return;
    }
    dataMatrix[rows * this->cols + cols] = value;
}

template <typename T>
T Matrix<T>::get(int rows, int cols) const {
    if (0 > rows || this->rows <= rows || 0 > cols || this->cols <= cols) {
        std::cout << "ПОМИЛКА! Неправильні координати!\n";
        return T();
    }
    return dataMatrix[rows * this->cols + cols];
}

template <typename T>
void Matrix<T>::fillFromKeyboard() {
    std::cout << "Введіть елементи для матриці (" << rows << 'x' << cols << "):\n";

    for (int indexRows = 0; indexRows < rows; indexRows++) {
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            std::cout << "Елемент [" << indexRows << "][" << indexCols << "]:";

            T value;
            std::cin >> value;
            dataMatrix[indexRows * this->cols + indexCols] = value;
        }
    }
}

template <typename T>
void Matrix<T>::fillRandom() {
    std::srand(std::time(0));

    for (int indexRows = 0; indexRows < rows; indexRows++) {
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            T randomNumber = static_cast<T>(std::rand() % 100 + 1);
            set(indexRows, indexCols, randomNumber);
        }
    }
}

template <typename T>
void Matrix<T>::print() const {
    for (int indexRows = 0; indexRows < rows; indexRows++) {
        std::cout << "{ ";
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            std::cout << get(indexRows, indexCols) << ", ";
        }
        std::cout << "}\n";
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {

    if (this->rows != other.rows || this->cols != other.cols) {
        std::cout << "ПОМИЛКА! Розміри матриць не збігаються для операції! >:(\n";
        return Matrix<T>();
    }

    Matrix<T> result(rows, cols);

    for (int indexRows = 0; indexRows < rows; indexRows++) {
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            T sum = this->get(indexRows, indexCols) + other.get(indexRows, indexCols);
            result.set(indexRows, indexCols, sum);
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {

    if (this->rows != other.rows || this->cols != other.cols) {
        std::cout << "ПОМИЛКА! Розміри матриць не збігаються для операції! >:(\n";
        return Matrix<T>();
    }

    Matrix<T> result(rows, cols);

    for (int indexRows = 0; indexRows < rows; indexRows++) {
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            T sum = this->get(indexRows, indexCols) - other.get(indexRows, indexCols);
            result.set(indexRows, indexCols, sum);
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {

    if (this->rows != other.rows || this->cols != other.cols) {
        std::cout << "ПОМИЛКА! Розміри матриць не збігаються для операції! >:(\n";
        return Matrix<T>();
    }

    Matrix<T> result(rows, cols);

    for (int indexRows = 0; indexRows < rows; indexRows++) {
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            T sum = this->get(indexRows, indexCols) * other.get(indexRows, indexCols);
            result.set(indexRows, indexCols, sum);
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& other) const {

    if (this->rows != other.rows || this->cols != other.cols) {
        std::cout << "ПОМИЛКА! Розміри матриць не збігаються для операції! >:(\n";
        return Matrix<T>();
    }

    Matrix<T> result(rows, cols);

    for (int indexRows = 0; indexRows < rows; indexRows++) {
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            T sum = this->get(indexRows, indexCols) / other.get(indexRows, indexCols);
            result.set(indexRows, indexCols, sum);
        }
    }
    return result;
}

template <typename T>
T Matrix<T>::maxElement() const {
    if (rows <= 0 || cols <= 0 || dataMatrix == nullptr) {
        return T();
    }

    T maxElement = get(0, 0);

    for (int indexRows = 0; indexRows < rows; indexRows++) {
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            if (maxElement < get(indexRows, indexCols)) {
                maxElement = get(indexRows, indexCols);
            }
        }
    }
    return maxElement;
}

template <typename T>
T Matrix<T>::minElement() const {
    if (rows <= 0 || cols <= 0 || dataMatrix == nullptr) {
        return T();
    }

    T minElement = get(0, 0);

    for (int indexRows = 0; indexRows < rows; indexRows++) {
        for (int indexCols = 0; indexCols < cols; indexCols++) {
            if (minElement > get(indexRows, indexCols)) {
                minElement = get(indexRows, indexCols);
            }
        }
    }
    return minElement;
}