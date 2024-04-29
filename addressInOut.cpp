
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

class Address
{
private:
    int numberAppartment;
    int numberHous;
    std::string street;
    std::string city;
public:
   
    Address(const std::string city, const std::string street, const int numberHous, const int numberAppartment)
    {
        this->city = city;
        this->street = street;
        this->numberHous = numberHous;
        this->numberAppartment = numberAppartment;
    }
    std::string PrintAddress()
    {
        return city + ", " + street + ", " + std::to_string(numberAppartment) + ", " + std::to_string(numberHous);
    }

};
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int numberApartment=0;
    int numberHouse=0;
    std::string street;
    std::string city;
    int counter = 0;
   
   
    std::ifstream inFile("in.txt");
    if (!inFile.is_open())
    {
        std::cout << "Not found INfile in this address!"<< std::endl;
        return 0;
    }
    inFile >> counter;
    
    Address* address = static_cast<Address*>(calloc(counter, sizeof(Address)));
    for (int i = 0; i < counter; i++)
    {
        inFile >> city;
        inFile >> street;
        inFile >> numberHouse;
        inFile >> numberApartment;
        address[i] = Address(city, street, numberHouse, numberApartment);
       
    }
    inFile.close();
    std::ofstream outFile("out.txt", std::ios::app);
    if (!outFile.is_open())
    {
        std::cout << "Not found OUTfile in this address!" << std::endl;
        return 0;
    }
    for (int i = counter-1; 0 <= i; i--)
    {
        outFile << address[i].PrintAddress() << std::endl;
    }
    outFile.close();
    free(address);
    
    
    return 0;

    
}
