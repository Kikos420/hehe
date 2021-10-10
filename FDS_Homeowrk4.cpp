#include <iostream>
#include <string>
#include <vector>
#include<unordered_set>
using namespace std;
enum condition { New, Refurbished }; //we are making enum as global to have easier access 
//Vehicle class
class Vehicle {
private:
    unordered_set<string> listMake{ "Porsche","Subaru","Honda","Nissan","Lamborghini","Audi" }; //List of chosen cars we gonna use
    string carMaker; //carMaker
    string model;
    int year; //The year when car is published
public:
    Vehicle() { //Constructor
        carMaker = "";
        model = "";
        year = 0;
    }
    Vehicle(string modelMake, string modelName, int modelYear) {
        setMake(modelMake);
        model = modelName;
        setYear(modelYear);
    }
    void setMake(string n) {
        if (listMake.find(n) != listMake.end())
        {
            carMaker = n;
        }
        else
        {
            cout << "This car is not supported!" << endl;
        }
    }
    void setYear(int t) {
        if (t >= 1950 && t <= 2030) {
            year = t;
        }
        else {
            cout << "This production year is not supported!" << endl;
        }
    }
    int getYear() {
        return year;
    }
    string getModel() {
        return model;
    }
    string getMake() {
        return carMaker;
    }
};
class SparePart {
protected:

    string id;
    string name;
    string description;
    Vehicle* a;
    int occurrences;
    double price;
    float replacementTime;
    double replacementWage;
    string instructions;
    condition cond;
public:
    SparePart() {
        id = "";
        name = "";
        description = "";
        price = 0;
        replacementTime = 0;
        replacementWage = 0;
        instructions = "";
        occurrences = 0;
        cond = condition::New;
    }
    //We are using getters in this Constructor
    SparePart(string id1, string name1, string description1, Vehicle* v, double price1, condition c, float replacementtime1, float replacementwage1, int occurrences1, string instructions1) {
        id = id1;
        name = name1;
        description = description1;
        a = v;
        price = price1;
        cond = c;
        replacementTime = replacementtime1;
        replacementWage = replacementwage1;
        instructions = instructions1;
        occurrences = occurrences1;
    }
    int getWarranty() { //if the condition is new we give only 36 months  warranty otherwise we give only 3 months
        if (cond == New) {
            return 36;
        }
        else {
            return 3;
        }
    }
    virtual int SetOccurrences(int o)=0;
    virtual int GetOccurrences() = 0;
    virtual double getTotalPrice() = 0;  //Abstract method for total price
    
    
    


    string getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getDescription() {
        return description;
    }
    string getInstructions() {
        return instructions;
    }
    int getReplacementTime() {
        return replacementTime;
    }
    double getReplacementWage() {
        return replacementWage;
    }
    int GetOccurrences() {
        return occurrences;

    }
    int SetOccurrences(int o) {
        return 0;
    }

    virtual void Output() = 0;
    virtual int SetOccurrences(int o) = 0;


};
class AvailableSparePart : public SparePart {
private:
 
    int quantity;
    string location;

public:
    AvailableSparePart() :SparePart() {
        quantity = 0;
        location = "";
    }
    //constructor
    AvailableSparePart(int w, string r, string id1, string name1, string description1, Vehicle* v, double price1, condition c, float replacementtime1, float replacementwage1, string instructions1) : SparePart(id1, name1, description1, v, price1, c, replacementtime1, replacementwage1, occurrences, instructions1)
    {
        quantity = w;
        location = r;
    }
    int getQuantity() { //we are using this getter for quantity
        return quantity;
    }
    string getLocation() { //we are using this getter for location
        return location;
    }
    double getTotalPrice() { //we are using this getter for price
        return (price + replacementTime * replacementWage);
    }
    int getDeliveryTime() { //we are using this getter for DeliveryTime
        return 0;
    }
    int GetOccurrences() {
        return occurrences;

    }
    int SetOccurrences(int o) {
        return 0;
    }
    void Output() {
        cout << "Quantity:" << endl;
        cout << "Location:" << endl;
        cout << getId() << endl;
        cout << getName() << endl;
        cout << getDescription() << endl;
        cout << getInstructions() << endl;
        cout << getReplacementTime() << endl;
        cout << getReplacementWage() << endl;
        cout << GetOccurrences() << endl;

        cout << getWarranty() << endl; //output 
    }
};
class ContractedSparePart : public SparePart { //inheriting class "SparePart class"
private:
    string vendor;
    double deliveryPrice;
    int deliveryTime;
public:
    ContractedSparePart() :SparePart() {
        vendor = "";
        deliveryPrice = 0;
        deliveryTime = 0;
    }
    //constructor
    ContractedSparePart(string vendor1, double dp, int dt, string id1, string name1, string description1, Vehicle* v, double price1, condition c, float replacementtime1, float replacementwage1, string instructions1) : SparePart(id1, name1, description1, v, price1, c, replacementtime1, replacementwage1,occurrences, instructions1)
    {
        vendor = vendor1;
        deliveryPrice = dp;
        deliveryTime = dt;
    }
    string getVendor() {
        return vendor;
    }
    double getDeliveryPrice() {
        return deliveryPrice;
    }
    int getDeliveryTime() {
        return deliveryTime;
    }
    double getTotalPrice() {

        return (price + replacementTime * replacementWage + deliveryPrice);
    }
    int GetOccurrences() {
        return occurrences;

    }
    int SetOccurrences(int o) {
        return 0;
    }
    void Output() {
        cout << vendor << endl;
        cout << getId() << endl;
        cout << getName() << endl;
        cout << getDescription() << endl;
        cout << getInstructions() << endl;
        cout << getReplacementTime() << endl;
        cout << getReplacementWage() << endl;
        cout << getWarranty() << endl;
        cout << GetOccurrences() << endl;
        cout << deliveryTime << endl;
        cout << deliveryPrice << endl;
    }
};
int max(int a, int b)
{
    return (a > b) ? a : b;
}
{
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    search(txt, pat);
    return 0;
}
void badCharHeuristic(char* str, int size, int badchar[])
{
    int ;

    // Initialize all occurrences as -1
    for (i = 0; i < ; i++)
        badchar[i] = -1;


    for (i = 0; i < ; i++)
        badchar[(int)str[i]] = i;
}

void search(char* txt, char* pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[Oc];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            printf("\n pattern occurs at shift = %d", s);

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }
}

int main() { //Main function of driver
    vector <Vehicle*> vehicle;// Three pointers that we gonna use as requested
    vector <SparePart*>Parts;// Vector which holds pointers to istances of AbailbableSpareParts and ContractedParts
    vehicle.push_back(new Vehicle("Porsche", "911s", 1998));
    vehicle.push_back(new Vehicle("Subaru", "Impreza", 1998));
    vehicle.push_back(new Vehicle("Honda", "Civic Coupe Si (", 2020));
    vehicle.push_back(new Vehicle("Nissan", "370z", 2017));
    vehicle.push_back(new Vehicle("Lamborghini", "murcielago", 2006));
    vehicle.push_back(new Vehicle("Audi", "RS5", 2007));
   

    Parts.push_back(new AvailableSparePart(7, "London", "914", "Engine", "Dont try to replace it alone only in service", vehicle[1], 452.76, Refurbished, 45.46, 84.98, "When the yellow indicator lights up go to sercvice."));
    Parts.push_back(new AvailableSparePart(7, "Munich", "751", "Wheel", "Object that takes energy from engine to spin around and make the car drive forward or backward", vehicle[2], 241.26, New, .46, 75.45, "Can be replaced by yourself"));
    Parts.push_back(new AvailableSparePart(7, "Amsterdam", "842", "Head Lamp", "Object to illuminate the road ahead also takes energy from engine.", vehicle[3], 12.34, Refurbished, 62.66, 21.88, "You can controll using only the dashboard."));
    Parts.push_back(new ContractedSparePart("Sofia", 48.23, 6, "440", "AC", "Cooling device that takes energy from engine and fuel from the car to make you feel better while drivin", vehicle[4], 45.12, New, 10.45, 94.2, "Press the button on dashboard only works when radiator is on"));
    Parts.push_back(new ContractedSparePart("Tokyo", 38.45, 5, "29", "GearBox", "Tool which help the car to move and work properly while driving", vehicle[5], 854.6, New, 239.1, 26.8, "Only visible thing is the stick which helps you to change the gear"));


    for (int i = 0; i < Parts.size(); i++) {
        cout << Parts[i]->getName() << " for the price of: $" << Parts[i]->getDescription() << endl;
    }
   
        return 0;
    }
