/* A Vegetable and Fruit Mall wants to organize its vegetables
and fruit products in a combination of purchase pattern of customers.
Slove the problem by suggesting appropriate data
structures. Design necessary class. */

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Product
{
public:
    string name;
    string type;

    Product(string name, string type)
    {
        this->name = name;
        this->type = type;
    }
};

class Mall
{
private:
    map<int, vector<Product>> purchaseData;

public:
    void addPurchase(int customerID, const Product &product)
    {
        purchaseData[customerID].push_back(product);
    }

    void displayPurchases(int customerID)
    {
        if (purchaseData.find(customerID) == purchaseData.end())
        {
            cout << "No purchases found for Customer " << customerID << endl;
            return;
        }

        cout << "Customer " << customerID << " purchased:\n";

        vector<Product>::const_iterator it;
        for (it = purchaseData[customerID].begin(); it != purchaseData[customerID].end(); it++)
        {
            cout << "- " << it->name << " (" << it->type << ")\n";
        }
    }

    void displayAll()
    {
        map<int, vector<Product>>::const_iterator mit;

        for (mit = purchaseData.begin(); mit != purchaseData.end(); mit++)
        {
            cout << "\nCustomer " << mit->first << " purchased:\n";

            vector<Product>::const_iterator vit;
            for (vit = mit->second.begin(); vit != mit->second.end(); ++vit)
            {
                cout << "- " << vit->name << " (" << vit->type << ")\n";
            }
        }
    }
};

int main() {

    Mall mall;

    mall.addPurchase(101, Product("Apple", "Fruit"));
    mall.addPurchase(101, Product("Carrot", "Vegetable"));
    mall.addPurchase(102, Product("Banana", "Fruit"));
    mall.addPurchase(102, Product("Spinach", "Vegetable"));
    mall.addPurchase(103, Product("Mango", "Fruit"));

    mall.displayPurchases(101);
    mall.displayPurchases(102);

    cout << "\n=== All Purchase Patterns ===\n";
    mall.displayAll();

    return 0;
}