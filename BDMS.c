#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define City structure
struct City {
    char name[50];
    int population;
    float averageTemperature;
};

// Function to take city information from keyboard
void takeCitiesInfoFromKeyboard(struct City cities[], int n) {
    printf("Enter information for %d cities:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("City %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", cities[i].name);
        printf("Population: ");
        scanf("%d", &cities[i].population);
        printf("Average Temperature: ");
        scanf("%f", &cities[i].averageTemperature);
    }
}

// Function to find and display city with the highest temperature
void findCityWithHighestTemperature(struct City cities[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (cities[i].averageTemperature > cities[maxIndex].averageTemperature) {
            maxIndex = i;
        }
    }
    printf("City with the highest temperature:\n");
    printf("Name: %s, Population: %d, Average Temperature: %.2f\n",
           cities[maxIndex].name, cities[maxIndex].population, cities[maxIndex].averageTemperature);
}

// Function to display cities with less than half of the highest temperature
void displayAllCitiesInfo(struct City cities[], int n) {
    float highestTemperature = cities[0].averageTemperature;
    for (int i = 1; i < n; ++i) {
        if (cities[i].averageTemperature > highestTemperature) {
            highestTemperature = cities[i].averageTemperature;
        }
    }

    printf("Cities with less than half of the highest temperature:\n");
    printf("%-20s %-20s %-20s\n", "City Name", "City Population", "City Temperature");
    for (int i = 0; i < n; ++i) {
        if (cities[i].averageTemperature < (highestTemperature / 2)) {
            printf("%-20s %-20d %-20.2f\n",
                   cities[i].name, cities[i].population, cities[i].averageTemperature);
        }
    }
}

int main() {
    int N; // Size of the array
    printf("Enter the size of the City structure array: ");
    scanf("%d", &N);

    struct City *cities = (struct City *)malloc(N * sizeof(struct City));

    char choice;
    do {
        printf("\nBD Meteorological System\n");
        printf("1. Enter 'x', to take information of one city into the City structure array of size %d.\n", N);
        printf("2. Enter 'y', to find and display the info of City with the highest temperature.\n");
        printf("3. Enter 'z', to display the information of Cities with less than half of the highest temperature in tabular format.\n");
        printf("4. Enter 'q', quit/exit the menu system.\n");
        printf("5. For any other input, display \"Invalid Input\"\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'x':
                takeCitiesInfoFromKeyboard(cities, N);
                break;
            case 'y':
                findCityWithHighestTemperature(cities, N);
                break;
            case 'z':
                displayAllCitiesInfo(cities, N);
                break;
            case 'q':
                printf("Exiting the menu system.\n");
                break;
            default:
                printf("Invalid Input\n");
        }
    } while (choice != 'q');

    // Free allocated memory
    free(cities);

    return 0;
}

