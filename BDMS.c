#include <stdio.h>
#include <string.h>

// City structure definition
struct City {
    char name[50];
    int population;
    float averageTemperature;
};

// Function prototypes
void takeCitiesInfoFromKeyboard(struct City cities[], int n);
void findCityWithHighestTemperature(struct City cities[], int n);
void displayAllCitiesInfo(struct City cities[], int n);

int main() {
    const int N = 100; // Maximum size of the City structure array
    struct City cities[N];
    int n = 0; // Number of cities in the array

    char choice;

    do {
        // Display menu
        printf("\n\tBD Meteorological System\n\n");
        printf("1. Enter 'x' to take information of one city into the City structure array of size N.\n");
        printf("2. Enter 'y' to find and display the info of City with the highest temperature.\n");
        printf("3. Enter 'z' to display the information of Cities with less than half of the highest temperature in tabular format.\n");
        printf("4. Enter 'q' to quit/exit the menu system.\n");
        printf("5. For any other input, display \"Invalid Input\"\n");

        // User prompt
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'x':
                takeCitiesInfoFromKeyboard(cities, n);
                n++;
                break;
            case 'y':
                findCityWithHighestTemperature(cities, n);
                break;
            case 'z':
                displayAllCitiesInfo(cities, n);
                break;
            case 'q':
                // Exit the program
                printf("Exiting the menu system.\n");
                break;
            default:
                // Invalid input
                printf("Invalid Input\n");
        }

    } while (choice != 'q');

    return 0;
}

// Function to take information of one City from the keyboard
void takeCitiesInfoFromKeyboard(struct City cities[], int n) {
    printf("\nEnter information for City %d:\n", n + 1);
    printf("Name: ");
    scanf("%s", cities[n].name);
    printf("Population: ");
    scanf("%d", &cities[n].population);
    printf("Average Temperature: ");
    scanf("%f", &cities[n].averageTemperature);
}

// Function to find and display the City with the highest temperature
void findCityWithHighestTemperature(struct City cities[], int n) {
    if (n == 0) {
        printf("No cities to find. Add cities first.\n");
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (cities[i].averageTemperature > cities[maxIndex].averageTemperature) {
            maxIndex = i;
        }
    }

    printf("\nCity with the highest temperature:\n");
    printf("Name: %s\n", cities[maxIndex].name);
    printf("Population: %d\n", cities[maxIndex].population);
    printf("Average Temperature: %.2f\n", cities[maxIndex].averageTemperature);
}

// Function to display information of cities with less than half of the highest temperature
void displayAllCitiesInfo(struct City cities[], int n) {
    if (n == 0) {
        printf("No cities to display. Add cities first.\n");
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (cities[i].averageTemperature > cities[maxIndex].averageTemperature) {
            maxIndex = i;
        }
    }

    float halfMaxTemp = cities[maxIndex].averageTemperature / 2;

    printf("\nCities with less than half of the highest temperature:\n");
    printf("%-20s%-20s%-20s\n", "City Name", "City Population", "City Temperature");

    for (int i = 0; i < n; i++) {
        if (cities[i].averageTemperature < halfMaxTemp) {
            printf("%-20s%-20d%-20.2f\n", cities[i].name, cities[i].population, cities[i].averageTemperature);
        }
    }
}

