#include <iostream>
#include <string>
#include <windows.h>

// Объявление типа функции
typedef bool (*CheckSymbolsFunc)(const char*, const char*);

int main() {
    std::string inputStr;
    std::string symbols;

    // Запрос ввода от пользователя
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputStr);
    std::cout << "Введите символы для поиска: ";
    std::getline(std::cin, symbols);

    // Загрузка библиотеки
    HINSTANCE hinstLib = LoadLibrary(TEXT("MyLibrary.dll"));
    if (hinstLib == NULL) {
        std::cerr << "Не удалось загрузить библиотеку." << std::endl;
        return 1;
    }

    // Получение адреса функции
    CheckSymbolsFunc CheckSymbols = (CheckSymbolsFunc)GetProcAddress(hinstLib, "CheckSymbols");
    if (CheckSymbols == NULL) {
        std::cerr << "Не удалось найти функцию." << std::endl;
        FreeLibrary(hinstLib);
        return 1;
    }

    // Вызов функции
    bool result = CheckSymbols(inputStr.c_str(), symbols.c_str());

    // Вывод результата
    if (result) {
        std::cout << "Все символы найдены в строке." << std::endl;
    }
    else {
        std::cout << "Не все символы найдены в строке." << std::endl;
    }

    // Освобождение библиотеки
    FreeLibrary(hinstLib);

    return 0;


}
extern "C" __declspec(dllexport) bool CheckSymbols(const char* str, const char* symbols) {
    // Проверяем, не являются ли указатели нулевыми
    if (str == nullptr || symbols == nullptr) {
        return false;
    }

    // Преобразуем C-строки в строки std::string для удобства работы
    std::string strString(str);
    std::string symbolsString(symbols);

    // Проверяем каждый символ из symbolsString на наличие в strString
    for (char symbol : symbolsString) {
        if (strString.find(symbol) == std::string::npos) {
            // Если символ не найден, возвращаем false
            return false;
        }
    }

    // Все символы найдены, возвращаем true
    return true;
}


