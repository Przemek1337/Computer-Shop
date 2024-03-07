#include "lib\inventory\inventory.h"

void Inventory::addPart(const ComputerPart& part) {
        parts.push_back(part);
    }
void Inventory::showInventory() {
        for (const auto& part : parts) {
            part.showDetails();
        }
    }
void Inventory::showSearchedInventory() {
        for (const auto& part : foundParts) {
            part.showDetails();
        }
    }
void Inventory::removePartByName(const std::string& name) {
    auto remove = std::find_if(parts.begin(), parts.end(), [&name](const ComputerPart& part) {
        return part.getName() == name;
    });

    if (remove != parts.end()) {
        parts.erase(remove);
    } else {
        std::cerr << "Part not found" << std::endl;
    }
}
void Inventory::searchPartByName(const std::string& name){

        for (const auto& part : parts) {
            if (part.getName().find(name) != std::string::npos) {
               part.showDetails();
            }
            
        }
        
        
}
void Inventory::updatePartDetails(const std::string& partName){
    for (auto& part: parts){
        if (part.getName() == partName){
            int choice;
            std::cout<< "Wybierz pole do aktualizacja dla " << partName << ":\n";
            std::cout<< "1. Nazwa \n";
            std::cout<< "2. Producent \n";
            std::cout<< "3. Model \n";
            std::cout<< "4. Kategoria \n";
            std::cout<< "5. Lb sztuk w magazynie \n";
            std::cout<< "6. Cena jednostkowa \n";
            std::cout<< "7. Przewidywana data dostawy \n";
            std::cout<< "8. Lb sztuk w dostawie \n";
            std::cout<< "9. Uwagi \n";
            std::cin >> choice;
            switch (choice){
                case 1:{
                    std::string newName;
                    std::cout<<"Nowa nazwa: ";
                    std::cin.ignore();
                    std::getline(std::cin,newName);
                    part.setName(newName);
                    break;
                }
                case 2:{
                    std::string newManufacturer;
                    std::cout<<"Nowy producent: ";
                    std::cin.ignore();
                    std::getline(std::cin,newManufacturer);
                    part.setManufacturer(newManufacturer);
                    break;
                }
                case 3:{
                    std::string newModel;
                    std::cout<<"Nowy model: ";
                    std::cin.ignore();
                    std::getline(std::cin,newModel);
                    part.setModel(newModel);
                    break;
                }
                case 4:{
                    std::string newCategory;
                    std::cout<<"Nowa kategoria: ";
                    std::cin.ignore();
                    std::getline(std::cin,newCategory);
                    part.setCategory(newCategory);
                    break;
                }
                case 5:{
                    unsigned int newStockQuantity;
                    std::cout<<"Nowa lb sztuk w magazynie: ";
                    std::cin.ignore();
                    std::cin>> newStockQuantity;
                    part.setStockQuantity(newStockQuantity);
                    break;
                }
                case 6:{
                    double newUnitPrice;
                    std::cout<<"Nowa cena jednostkowa: ";
                    std::cin.ignore();
                    std::cin>>newUnitPrice;
                    part.setUnitPrice(newUnitPrice);
                    break;
                }
                case 7:{
                    std::string newDeliveryDate;
                    std::cout<<"Nowa przewidywana data dostawy: ";
                    std::cin.ignore();
                    std::getline(std::cin,newDeliveryDate);
                    part.setDeliveryDate(newDeliveryDate);
                    break;
                }
                case 8:{
                    unsigned int newDeliveryQuantity;
                    std::cout<<"Nowa liczba sztuk w dostawie: ";
                    std::cin.ignore();
                    std::cin>> newDeliveryQuantity;
                    part.setDeliveryQuantity(newDeliveryQuantity);
                    break;
                }
                case 9:{
                    std::string newRemarks;
                    std::cout<<"Nowe uwagi: ";
                    std::cin.ignore();
                    std::getline(std::cin,newRemarks);
                    part.setRemarks(newRemarks);
                    break;
                }
                    
                
                default:
                    std::cerr << "Nieprawidłowa opcja" << std::endl;
                    return;
            }

        }
    }
}
void Inventory::menu()const{
        std::cout << "Witaj w sklepie komputerowym, wybierz co chcesz zrobic"<< std::endl;
        std::cout << "[1] Dodaj produkt" << std::endl;
        std::cout << "[2] Usuń produkt" << std::endl;
        std::cout << "[3] Zmień dane produktu" << std::endl;
        std::cout << "[4] Wyszukaj produkt" << std::endl;
        std::cout << "[5] Wczytaj baze z pliku" << std::endl;
        std::cout << "[6] Zapisz baze do pliku" << std::endl;
        std::cout << "[7] Wyjdź" << std::endl;
}
void Inventory::readDataFromFile(const std::string& filename){
        std::fstream file;
        std::string line;
        file.open("C:/Users/przem/Desktop/projekt_sklepkomputerowy/"+filename, std::ios_base::in);
        if (!file.is_open()) {
            std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
            return;
        }
        
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, manufacturer, model, category, remarks, deliveryDate;
            int stockQuantity, deliveryQuantity;
            double unitPrice;

            getline(iss, name, ',');
            getline(iss, manufacturer, ',');
            getline(iss, model, ',');
            getline(iss, category, ',');
            iss >> stockQuantity; iss.ignore();
            iss >> unitPrice; iss.ignore();
            getline(iss, deliveryDate, ',');
            iss >> deliveryQuantity; iss.ignore();
            getline(iss, remarks);

            ComputerPart part(name, manufacturer, model, category, stockQuantity, unitPrice, deliveryDate, deliveryQuantity, remarks);
            addPart(part);
        }

        file.close();
}


void Inventory::saveDataToFile(const std::string& filename){
        std::fstream file;
        file.open("C:/Users/przem/Desktop/projekt_sklepkomputerowy/"+filename, std::ios_base::out);

        if (!file.is_open()) {
            std::cerr << "Nie udało się otworzyć pliku do zapisu." << std::endl;
            return;
        }

        for (const auto& part : parts) {
            file << part.getName() << ","
                 << part.getManufacturer() << ","
                 << part.getModel() << ","
                 << part.getCategory() << ","
                 << part.getStockQuantity() << ","
                 << part.getUnitPrice() << ","
                 << part.getDeliveryDate() << ","
                 << part.getDeliveryQuantity() << ","
                 << part.getRemarks() << std::endl;
        }

        file.close();
        std::cout << "Dane zostały zapisane do pliku " << filename << std::endl;
    }
void Inventory::cos(const std::string& chwilowy, std::string& tempstring)const{
            std::cout<<chwilowy;
            std::cin.ignore();
            std::getline(std::cin, tempstring);
}
ComputerPart Inventory::init_computerpart()const{
            std::string Inputname= "";;
            std::string Inputmanufacturer= "";;
            std::string Inputmodel= "";;
            std::string Inputcategory= "";;
            unsigned int InputstockQuantity{0};
            double InputunitPrice{0};
            std::string InputdeliveryDate= "";; 
            unsigned int InputdeliveryQuantity{0};
            std::string Inputremarks= "";;
            
            std::cout<<"Nazwa: ";
            std::cin>>Inputname;

            std::cout<<"Producent: ";
            std::cin>>Inputmanufacturer;

            std::cout<<"Model: ";
            std::cin>>Inputmodel;

            std::cout<<"Kategoria: ";
            std::cin>>Inputcategory;

            std::cout<<"Stock: ";
            std::cin>>InputstockQuantity;

            std::cout<<"UnitPrice: ";
            std::cin>>InputunitPrice;

            std::cout<<"DeliveryDate: ";
            std::cin>>InputdeliveryDate;

            std::cout<<"DeliveryQuantity: ";
            std::cin>>InputdeliveryQuantity;

            std::cout<<"Remarks: ";
            std::cin>>Inputremarks;
            
            ComputerPart local(Inputname,Inputmanufacturer, Inputmodel, Inputcategory, InputstockQuantity, InputunitPrice, InputdeliveryDate, InputdeliveryQuantity, Inputremarks);
            return local;
}
void Inventory::mainApp(){
    bool loop{true};
    int choice{0};
    std::string tempstring = "";
    while(loop){
        std::cout << "Aktualny stan: " << std::endl;
        showInventory();
        menu();
        std::cout<<"Wybierz opcje: "<< std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            addPart(init_computerpart());
            break;
        case 2:
            cos("Podaj nazwę przedmiotu do usunięcia: ", tempstring);
            removePartByName(tempstring);
            break;
        case 3:
            cos("Podaj nazwę przedmiotu do zmiany danych: ", tempstring);
            updatePartDetails(tempstring);
            break;
        case 4:  
            cos("Wyszukaj produkt po nazwie: ", tempstring);
            searchPartByName(tempstring);
            
            break;
        case 5:
            cos("Wprowadź nazwe pliku z .txt, którym chcesz wczytać rekordy: ", tempstring);
            readDataFromFile(tempstring);
            break;
        case 6:
            cos("Wprowadź nazwe pliku z .txt, gdzie chcesz zapisać bazę: ", tempstring);
            saveDataToFile(tempstring);
            break;
        case 7:
            std::cout<<"Wyszedłeś ze sklepu: ";
            loop = false;
        default:
            break;
        }
    }
}