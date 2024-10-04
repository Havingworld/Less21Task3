#include <iostream>
#include <cmath>

struct strVector2D {    //Структура вектора
    double x{ 0.0 };
    double y{ 0.0 };
};
    
strVector2D add(strVector2D vec1, strVector2D vec2) {   // Сложение векторов
    strVector2D answer;
    answer.x = vec1.x + vec2.x;
    answer.y = vec1.y + vec2.y;
    return  answer;
};

    
strVector2D subtract(strVector2D vec1, strVector2D vec2) {  // Вычитание векторов
    strVector2D answer;
    answer.x = vec1.x - vec2.x;
    answer.y = vec1.y - vec2.y;
    return  answer;
};
    
double length(strVector2D vec) {    // Длина вектора
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
};

    
strVector2D normalize(strVector2D vec) {    // Нормализация вектора
    double len = length(vec);
    if (len == 0.0) {
        vec.x = vec.y = 0.0;
        return vec;
    }
    strVector2D answer;
    answer.x = vec.x / len;
    answer.y = vec.y / len;
    return answer;
};

    
strVector2D scale(strVector2D vec, double scalar) {    // Умножение вектора на скаляр
    strVector2D answer;
    answer.x = vec.x * scalar;
    answer.y = vec.y * scalar;
    return answer;
}

    
void print(strVector2D vec) {   // Вывод вектора
    std::cout << "(" << vec.x << ", " << vec.y << ")";
}

int main() {
    std::string sCommand{""};
    strVector2D vec1, vec2;
    double dScalar{ 0.0 };

    while (sCommand != "exit") {
        std::cout << "Enter command (add, subtract, scale, length, normalize, exit): ";
        std::cin >> sCommand;

        if (sCommand == "exit") {
            break;
        }
        else if (sCommand == "add" || sCommand == "subtract") {
            std::cout << "Введите вектор 1 (x y): ";
            std::cin >> vec1.x >> vec1.y;
            std::cout << "Введите вектор 2 (x y): ";
            std::cin >> vec2.x >> vec2.y;

            if (sCommand == "add") {
                std::cout << "Результат сложения: ";
                print(add(vec1, vec2));
                std::cout << std::endl;
            }
            else if (sCommand == "subtract") {
                std::cout << "Результат вычитания: ";
                print(subtract(vec1, vec2));
                std::cout << std::endl;
            }
        }
        else if (sCommand == "scale") {
            std::cout << "Введите вектор (x y): ";
            std::cin >> vec1.x >> vec1.y;
            std::cout << "Введите скаляр: ";
            double dScalar;
            std::cin >> dScalar;
            std::cout << "Результат умножения на скаляр: ";
            print(scale(vec1, dScalar));
            std::cout << std::endl;
        }
        else if (sCommand == "length") {
            std::cout << "Введите вектор (x y): ";
            std::cin >> vec1.x >> vec1.y;
            std::cout << "Длина вектора: " << length(vec1) << std::endl;
        }
        else if (sCommand == "normalize") {
            std::cout << "Введите вектор (x y): ";
            std::cin >> vec1.x >> vec1.y;
            std::cout << "Нормализованный вектор: ";
            print(normalize(vec1));
            std::cout << std::endl;
        }
        else {
            std::cout << "Неизвестная команда. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}
