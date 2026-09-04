#include <stdio.h>
#include <string.h>

struct Package {
    int packageID;
    char destination[50];
    float distance;
    int deadline;
    float shippingCost;
};

// Bubble sort by deadline (Emergency Mode)
void sortByDeadline(struct Package arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j].deadline > arr[j+1].deadline) {
                struct Package temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Bubble sort by distance (Fuel-Saving Mode)
void sortByDistance(struct Package arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j].distance > arr[j+1].distance) {
                struct Package temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Bubble sort by shipping cost (Revenue Mode)
void sortByRevenue(struct Package arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j].shippingCost < arr[j+1].shippingCost) {
                struct Package temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Display function
void display(struct Package arr[], int n, char mode[]) {
    printf("\nSorted in %s Mode:\n", mode);
    printf("ID\tDestination\t\tDistance\tDeadline\tCost\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%-15s\t%.1f km\t%d hrs\t$%.2f\n",
               arr[i].packageID, arr[i].destination,
               arr[i].distance, arr[i].deadline, arr[i].shippingCost);
    }
}

int main() {
    struct Package packages[5] = {
        {101, "Downtown", 15.5, 4, 25.00},
        {102, "North Suburb", 42.0, 12, 85.50},
        {103, "Airport District", 8.2, 2, 15.00},
        {104, "West Valley", 23.1, 6, 45.00},
        {105, "East Pier", 19.8, 3, 60.00}
    };

    int choice;
    printf("Choose Sorting Mode:\n");
    printf("1. Emergency Mode (Deadline)\n");
    printf("2. Fuel-Saving Mode (Distance)\n");
    printf("3. Revenue Mode (Shipping Cost)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            sortByDeadline(packages, 5);
            display(packages, 5, "Emergency");
            break;
        case 2:
            sortByDistance(packages, 5);
            display(packages, 5, "Fuel-Saving");
            break;
        case 3:
            sortByRevenue(packages, 5);
            display(packages, 5, "Revenue");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
