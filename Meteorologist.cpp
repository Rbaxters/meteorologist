#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// initializes the variables for the counters
int counter;
int totalRainy = 0;
int totalSunny = 0;
int totalCloudy = 0;

int juneRainy;
int juneSunny;
int juneCloudy;

int julyRainy;
int julySunny;
int julyCloudy;

int augustRainy;
int augustSunny;
int augustCloudy;
// declares the functions for the code
void readFiles(fstream& myfile, string& fileInput, string& fileData, int& counter, string (&days)[3][30]);
void countDays (string days[3][30]);
void reportFinal ();
void rainyMost();

int main()
{
    string days[3][30];// created the array

    fstream myfile;// reads the file and turns it into a string
    myfile.open("RainOrShine.txt");
    string fileInput;
    string fileData;

    readFiles(myfile, fileInput, fileData, counter, days);
    countDays(days);
    reportFinal();
    rainyMost();

    return 0;
}

void readFiles(fstream& myfile, string& fileInput, string& fileData, int& counter, string (&days)[3][30])
{
    while (myfile >> fileInput)
    {
        fileData = fileData + fileInput;
    }



    for (int i = 0; i < 3; i++) // turns the string into the array
    {
        for (int j = 0; j < 30; j++)
        {
            days[i][j] = fileData[counter];
            counter++;
        }
    }
}

void countDays (string days[3][30]) {
 // these are the conditions for counting each type of day
  for (int k = 0; k < 30; k++) {
        if (days[0][k] == "S") {
            juneSunny++;
        }
        else if (days[0][k] == "R") {
            juneRainy++;
        }
        else if (days[0][k] == "C") {
            juneCloudy++;
        }
    }

    for (int l = 0; l < 30; l++) {
        if (days[1][l] == "S") {
            julySunny++;
        }
        else if (days[1][l] == "R") {
            julyRainy++;
        }
        else if (days[1][l] == "C") {
            julyCloudy++;
        }
    }

    for (int m = 0; m < 30; m++) {
        if (days[2][m] == "S") {
            augustSunny++;
        }
        else if (days[2][m] == "R") {
            augustRainy++;
        }
        else if (days[2][m] == "C") {
            augustCloudy++;
        }


}
// total of the types of day
 totalCloudy = juneCloudy + julyCloudy + augustCloudy;
    totalRainy = juneRainy + julyRainy + augustRainy;
    totalSunny = juneSunny + julySunny + augustSunny;


}

void rainyMost () {
// final output for most rainy
  if (juneRainy > julyRainy && juneRainy > augustRainy) {
        cout << "\nJune had the highest number of rainy days.";
    }
    else if (julyRainy > juneRainy && julyRainy > augustRainy) {
        cout << "\nJuly had the highest number of rainy days.";
    }
    else if (augustRainy > juneRainy && augustRainy > julyRainy) {
        cout << "\nAugust had the highest number of rainy days.";
    }
    else if (juneRainy == julyRainy && juneRainy > augustRainy) {
        cout << "\nJune and July were tied for highest number of rainy days.";
    }
    else if (juneRainy == augustRainy && juneRainy > julyRainy) {
        cout << "\nJune and August were tied for highest number of rainy days.";
    }
    else if (julyRainy == augustRainy && julyRainy > juneRainy) {
        cout << "\nJuly and August were tied for highest number of rainy days.";
    }
    else if (juneRainy == julyRainy && juneRainy == augustRainy) {
        cout << "\nAll three months had the same number of rainy days.";
    }

}

void reportFinal () {
// final report for number of rainy, sunny, and clouds
    cout << "June had " << juneSunny << " sunny days, " << juneCloudy << " cloudy days, and " << juneRainy << " rainy days.\n";
    cout << "July had " << julySunny << " sunny days, " << julyCloudy << " cloudy days, and " << julyRainy << " rainy days.\n";
    cout << "August had " << augustSunny << " sunny days, " << augustCloudy << " cloudy days, and " << augustRainy << " rainy days.\n";

    cout << "In total, there were " << totalSunny << " sunny days, " << totalCloudy << " cloudy days, and " << totalRainy << " rainy days.";


}



