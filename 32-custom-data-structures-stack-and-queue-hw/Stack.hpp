template <typename T>
Stack<T>::Stack(int capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Ємність стека повинна бути додатною");
    }
    maxCapacity = capacity;
    data = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data;
    data = nullptr;
}

template <typename T>
void Stack<T>::push(const T &value) {
    if (isFull()) {
        throw std::overflow_error("Переповнення стека! Неможливо додати елемент!");
    }
    topIndex++;
    data[topIndex] = value;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Стек пустий! Неможливо видалити елемент!");
    }
    topIndex--;
}

template <typename T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Стек пустий! Немає останнього елемента!");
    }
    return data[topIndex];
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return topIndex == -1;
}

template <typename T>
bool Stack<T>::isFull() const {
    return topIndex == maxCapacity - 1;
}

template <typename T>
int Stack<T>::size() const {
    return topIndex + 1;
}

template <typename T>
int Stack<T>::capacity() const {
    return maxCapacity;
}

