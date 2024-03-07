#ifndef LIB_COMPUTER_PARTS_COMPUTER_PARTS_H
#define LIB_COMPUTER_PARTS_COMPUTER_PARTS_H
#include <string>
#include <iostream>
#include <vector>
class ComputerPart {
private:
    std::string name;
    std::string manufacturer;
    std::string model;
    std::string category;
    unsigned int stockQuantity;
    double unitPrice;
    std::string deliveryDate; 
    unsigned int deliveryQuantity;
    std::string remarks;
    std::string newDeliveryDate;
public:
    std::string getName() const{return name;}
    std::string getManufacturer() const {return manufacturer;}
    std::string getModel() const {return model;}
    std::string getCategory() const {return category;}
    unsigned int getStockQuantity() const {return stockQuantity;}
    double getUnitPrice() const {return unitPrice;}
    std::string getDeliveryDate() const {return deliveryDate;}
    unsigned int getDeliveryQuantity() const {return deliveryQuantity;}
    std::string getRemarks() const {return remarks;}
    std::string getNewDeliveryDate() const {return newDeliveryDate;}
    
    void setName(const std::string& newName){
        name = newName;
    }
    void setManufacturer(const std::string& newManufacturer){
        manufacturer = newManufacturer;
    }
    void setModel(const std::string& newModel){
        model = newModel;
    }
    void setCategory(const std::string& newCategory){
        category = newCategory;
    }
    void setStockQuantity(const unsigned int& newStockQuantity){
        stockQuantity = newStockQuantity;
    }
    void setUnitPrice(const double& newUnitPrice){
        unitPrice = newUnitPrice;
    }
    void setDeliveryDate(const std::string& newDeliveryDate){
        deliveryDate = newDeliveryDate;
    }
    void setDeliveryQuantity(const unsigned int& newDeliveryQuantity){
        deliveryQuantity = newDeliveryQuantity;
    }
    void setRemarks(const std::string& newRemarks){
        remarks = newRemarks;
    }
    void showDetails()const; 
    ComputerPart(std::string name, std::string manufacturer, std::string model, 
                 std::string category, unsigned int stockQuantity, double unitPrice, 
                 std::string deliveryDate, unsigned int deliveryQuantity, std::string remarks)
        : name(name), manufacturer(manufacturer), model(model), category(category),
          stockQuantity(stockQuantity), unitPrice(unitPrice), deliveryDate(deliveryDate),
          deliveryQuantity(deliveryQuantity), remarks(remarks) {}
};
#endif //LIB_COMPUTER_PARTS_COMPUTER_PARTS_H
