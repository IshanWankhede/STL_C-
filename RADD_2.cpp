#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Package {
    int packageID;
    string destination;
    float distance;
    int deadline;
    float shippingCost;
};

void display(const vector<Package>& arr, string mode) {
    cout << "\nSorted in " << mode << " Mode:\n";
    cout << "ID\tDestination\t\tDistance\tDeadline\tCost\n";
    for (auto &p : arr) {
        cout << p.packageID << "\t" << p.destination << "\t"
             << p.distance << " km\t" << p.deadline << " hrs\t$"
             << p.shippingCost << "\n";
    }
}

int main() {
    vector<Package> packages = {
        {101, "Downtown", 15.5, 4, 25.00},
        {102, "North Suburb", 42.0, 12, 85.50},
        {103, "Airport District", 8.2, 2, 15.00},
        {104, "West Valley", 23.1, 6, 45.00},
        {105, "East Pier", 19.8, 3, 60.00}
    };

    // Emergency Mode (deadline ascending)
    auto emergency = packages;
    sort(emergency.begin(), emergency.end(),
         [](const Package &a, const Package &b) {
             return a.deadline < b.deadline;
         });
    display(emergency, "Emergency");

    // Fuel-Saving Mode (distance ascending)
    auto fuel = packages;
    sort(fuel.begin(), fuel.end(),
         [](const Package &a, const Package &b) {
             return a.distance < b.distance;
         });
    display(fuel, "Fuel-Saving");

    // Revenue Mode (shippingCost descending)
    auto revenue = packages;
    sort(revenue.begin(), revenue.end(),
         [](const Package &a, const Package &b) {
             return a.shippingCost > b.shippingCost;
         });
    display(revenue, "Revenue");

    return 0;
}
