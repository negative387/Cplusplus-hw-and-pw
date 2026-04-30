/*
Завдання 2: Рівні доступу до PIN-коду (Вказівники та const) Є змінна int
adminPin = 1234;. Оголосіть три різні вказівники на неї, дотримуючись суворих
правил. Код має лише компілюватися (без логіки в main).
*/


int main() {
    int adminPin = 1234;
    int userPin = 0000;

    // 1. "Гість": Може дивитися на adminPin та перемикатися на userPin,
    // але не може змінювати самі паролі.
    const int *guestPtr = &adminPin;
    guestPtr = &userPin;

    // 2. "Молодший адмін": Може змінити пароль adminPin,
    // але вказівник намертво прив'язаний до adminPin (не може перейти на userPin).
    int * const juniorPtr = &adminPin;

    // 3. "Заблокований лог": Намертво прив'язаний до adminPin
    // і може тільки читати (жодних змін).
    const int * const logPtr = &adminPin;

    return 0;
}