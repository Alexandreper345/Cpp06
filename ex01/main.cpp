#include "Serializer.hpp"
#include <iostream>

int main() {
    Data myData;
    myData.id = 42;
    myData.s = "Exemplo da 42";
    myData.active = true;

    // 1. Pega o endereço original
    Data* ptrOriginal = &myData;
    std::cout << "Endereço Original:  " << ptrOriginal << std::endl;

    // 2. Serializa (vira número)
    uintptr_t raw = Serializer::serialize(ptrOriginal);
    std::cout << "Valor Serializado: " << raw << std::endl;

    // 3. Deserializa (vira ponteiro de novo)
    Data* ptrFinal = Serializer::deserialize(raw);
    std::cout << "Endereço Final:     " << ptrFinal << std::endl;

    // 4. Comparações exigidas pelo exercício
    if (ptrOriginal == ptrFinal) {
        std::cout << "Sucesso! Os ponteiros são iguais." << std::endl;
        std::cout << "Conteúdo: " << ptrFinal->s << " (ID: " << ptrFinal->id << ")" << std::endl;
    } else {
        std::cerr << "Erro! Os ponteiros são diferentes." << std::endl;
    }

    return 0;
}