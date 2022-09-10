#include <iostream>

int main() {
    int fact{1};
    std::cout << "\nIntroduzca un numero entero y se devolverá su factorial: ";
    std::cin >> fact;
    std::cout << "\n";

    std::cout << fact << "\n\n";

    const int kLimit{fact};

    for(int i{1}; kLimit > i; i++) {
        fact *= i;
    }

    std::cout << "El factorial es: " << fact << "\n\n";

    return 0;
}