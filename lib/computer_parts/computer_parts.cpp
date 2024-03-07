#include "lib\computer_parts/computer_parts.h"


void ComputerPart::showDetails() const{
                std::cout << "Nazwa: " << name << ", Producent: " << manufacturer
                      << ", Model: " << model << ", Kategoria: " << category
                      << ", Liczba sztuk: " << stockQuantity << ", Cena: " << unitPrice
                      << ", Data dostawy: " << deliveryDate << ", Liczba sztuk w dostawie: " << deliveryQuantity
                      << ", Uwagi: " << remarks << std::endl;
}


