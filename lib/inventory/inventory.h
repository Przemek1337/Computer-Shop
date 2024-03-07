
#ifndef LIB_INVENTORY_INVENTORY_H
#define LIB_INVENTORY_INVENTORY_H 
#include "lib\computer_parts\computer_parts.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
class Inventory {
private:
    std::vector<ComputerPart> parts;
    std::vector<ComputerPart> foundParts;
public:
    void addPart(const ComputerPart& part); 
    void removePartByName(const std::string& name);
    void searchPartByName(const std::string& name);
    void showInventory();
    void showSearchedInventory();
    void updatePartDetails(const std::string& partName);
    void readDataFromFile(const std::string& filename);
    void saveDataToFile(const std::string& filename);
    void mainApp();
    void menu()const;
    void cos(const std::string& chwilowy, std::string& tempstring)const;
    ComputerPart init_computerpart()const;
};
#endif //LIB_INVENTORY_INVENTORY_H