#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

struct Product
{
    int productID;
    string productName;
    string category;
    double price;
    double rating;
    int stockQuantity;
};

void displayProduct(const Product &p)
{
    cout << "\nProduct ID     : " << p.productID;
    cout << "\nProduct Name   : " << p.productName;
    cout << "\nCategory       : " << p.category;
    cout << "\nPrice          : Rs. " << fixed << setprecision(2) << p.price;
    cout << "\nRating         : " << p.rating;
    cout << "\nStock Quantity : " << p.stockQuantity << "\n";
}

void displayAllProducts(const vector<Product> &products)
{
    if (products.empty())
    {
        cout << "\nNo products available.\n";
        return;
    }

    cout << "\n================ PRODUCT LIST ================\n";

    cout << left
         << setw(8) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(12) << "Price"
         << setw(10) << "Rating"
         << setw(10) << "Stock"
         << "\n";

    cout << string(75, '-') << "\n";

    for (const Product &p : products)
    {
        cout << left
             << setw(8) << p.productID
             << setw(20) << p.productName
             << setw(15) << p.category
             << setw(12) << fixed << setprecision(2) << p.price
             << setw(10) << p.rating
             << setw(10) << p.stockQuantity
             << "\n";
    }
}

void addProducts(vector<Product> &products)
{
    int n;

    cout << "\nEnter number of products: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of products.\n";
        return;
    }

    products.clear();

    for (int i = 0; i < n; i++)
    {
        Product p;

        cout << "\n========== Product " << i + 1 << " ==========\n";

        cout << "Enter Product ID: ";
        cin >> p.productID;

        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, p.productName);

        cout << "Enter Category: ";
        getline(cin, p.category);

        cout << "Enter Price: ";
        cin >> p.price;

        cout << "Enter Rating: ";
        cin >> p.rating;

        cout << "Enter Stock Quantity: ";
        cin >> p.stockQuantity;

        products.push_back(p);
    }

    cout << "\nProducts added successfully!\n";
}

int linearSearch(const vector<Product> &products, int id)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].productID == id)
        {
            return i;
        }
    }

    return -1;
}

void sortProducts(vector<Product> &products)
{
    if (products.empty())
    {
        cout << "\nNo products available.\n";
        return;
    }

    sort(products.begin(), products.end(),
         [](const Product &a, const Product &b)
         {
             return a.price < b.price;
         });

    cout << "\nProducts sorted according to price successfully!\n";
}

int binarySearch(vector<Product> products, int id)
{
    sort(products.begin(), products.end(),
         [](const Product &a, const Product &b)
         {
             return a.productID < b.productID;
         });

    int low = 0;
    int high = products.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (products[mid].productID == id)
        {
            return mid;
        }
        else if (products[mid].productID < id)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

void cheapestProduct(const vector<Product> &products)
{
    if (products.empty())
    {
        cout << "\nNo products available.\n";
        return;
    }

    auto it = min_element(products.begin(), products.end(),
                          [](const Product &a, const Product &b)
                          {
                              return a.price < b.price;
                          });

    cout << "\n========== CHEAPEST PRODUCT ==========\n";
    displayProduct(*it);
}

void mostExpensiveProduct(const vector<Product> &products)
{
    if (products.empty())
    {
        cout << "\nNo products available.\n";
        return;
    }

    auto it = max_element(products.begin(), products.end(),
                          [](const Product &a, const Product &b)
                          {
                              return a.price < b.price;
                          });

    cout << "\n========== MOST EXPENSIVE PRODUCT ==========\n";
    displayProduct(*it);
}

void highestRatedProduct(const vector<Product> &products)
{
    if (products.empty())
    {
        cout << "\nNo products available.\n";
        return;
    }

    auto it = max_element(products.begin(), products.end(),
                          [](const Product &a, const Product &b)
                          {
                              return a.rating < b.rating;
                          });

    cout << "\n========== HIGHEST RATED PRODUCT ==========\n";
    displayProduct(*it);
}

void topFiveProducts(const vector<Product> &products)
{
    if (products.empty())
    {
        cout << "\nNo products available.\n";
        return;
    }

    vector<Product> temp = products;

    sort(temp.begin(), temp.end(),
         [](const Product &a, const Product &b)
         {
             return a.price > b.price;
         });

    int limit = min(5, (int)temp.size());

    cout << "\n========== TOP " << limit
         << " HIGHEST-PRICED PRODUCTS ==========\n";

    for (int i = 0; i < limit; i++)
    {
        cout << "\nRank " << i + 1 << "\n";
        displayProduct(temp[i]);
    }
}

void priceRangeSearch(const vector<Product> &products)
{
    if (products.empty())
    {
        cout << "\nNo products available.\n";
        return;
    }

    double minPrice, maxPrice;

    cout << "\nEnter minimum price: ";
    cin >> minPrice;

    cout << "Enter maximum price: ";
    cin >> maxPrice;

    if (minPrice > maxPrice)
    {
        cout << "\nInvalid price range.\n";
        return;
    }

    bool found = false;

    cout << "\n========== PRODUCTS IN PRICE RANGE ==========\n";

    for (const Product &p : products)
    {
        if (p.price >= minPrice && p.price <= maxPrice)
        {
            displayProduct(p);
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo products found in this price range.\n";
    }
}

int main()
{
    vector<Product> products;

    int choice;

    while (true)
    {
        cout << "\n\n==============================================\n";
        cout << "       E-COMMERCE PRODUCT MANAGEMENT\n";
        cout << "==============================================\n";
        cout << "1. Add Products\n";
        cout << "2. Display Products\n";
        cout << "3. Linear Search by Product ID\n";
        cout << "4. Sort Products by Price\n";
        cout << "5. Binary Search by Product ID\n";
        cout << "6. Cheapest Product\n";
        cout << "7. Most Expensive Product\n";
        cout << "8. Highest Rated Product\n";
        cout << "9. Top 5 Highest-Priced Products\n";
        cout << "10. Price Range Search\n";
        cout << "11. Exit\n";
        cout << "==============================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addProducts(products);
            break;

        case 2:
            displayAllProducts(products);
            break;

        case 3:
        {
            int id;

            cout << "\nEnter Product ID to search: ";
            cin >> id;

            int index = linearSearch(products, id);

            if (index != -1)
            {
                cout << "\nProduct found using Linear Search!\n";
                displayProduct(products[index]);
            }
            else
            {
                cout << "\nProduct not found.\n";
            }

            break;
        }

        case 4:
            sortProducts(products);
            break;

        case 5:
        {
            int id;

            cout << "\nEnter Product ID to search: ";
            cin >> id;

            int index = binarySearch(products, id);

            if (index != -1)
            {
                cout << "\nProduct found using Binary Search!\n";

                for (const Product &p : products)
                {
                    if (p.productID == id)
                    {
                        displayProduct(p);
                        break;
                    }
                }
            }
            else
            {
                cout << "\nProduct not found.\n";
            }

            break;
        }

        case 6:
            cheapestProduct(products);
            break;

        case 7:
            mostExpensiveProduct(products);
            break;

        case 8:
            highestRatedProduct(products);
            break;

        case 9:
            topFiveProducts(products);
            break;

        case 10:
            priceRangeSearch(products);
            break;

        case 11:
            cout << "\nProgram exited successfully.\n";
            return 0;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}