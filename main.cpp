#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to populate the 2D array with characters based on x and y coordinates
void populateArray(
    const vector<int>& xValues,
    const vector<string>& characterValues,
    const vector<int>& yValues,
    vector<vector<string>>& answerArray)
{
    // Iterate through the coordinates and characters to populate the array
    for (size_t i = 0; i < xValues.size(); ++i)
    {
        int x = xValues[i];
        int y = yValues[i];
        // Check if the coordinates are within the bounds of the array
        if (x >= 0 &&
            x < static_cast<int>(answerArray[0].size()) &&
            y >= 0 &&
            y < static_cast<int>(answerArray.size()))
        {
            // Assign the character to the corresponding position in the array
            answerArray[y][x] = characterValues[i];
        }
    }
}

// Function to print the 2D array
void printArray(const vector<vector<string>>& array)
{
    for (const auto& row : array)
    {
        for (const auto& cell : row)
        {
            cout << cell;
        }

        cout << '\n';
    }
}

int main()
{
    // Open the input file
    ifstream inFile("data_proj.txt");

    // Check if the file was opened successfully
    if (!inFile.is_open())
    {
        cerr << "Error: Could not open the file!\n";
        return 1;
    }

    // Declare variables to hold the coordinates and characters
    int xCoord;
    string character;
    int yCoord;

    // Vectors to store the coordinates and characters read from the file
    vector<int> xValues;
    vector<string> characterValues;
    vector<int> yValues;

    // Read the coordinates and characters from the file 
    while (inFile >> xCoord >> character >> yCoord)
    {
        xValues.push_back(xCoord);
        characterValues.push_back(character);
        yValues.push_back(yCoord);
    }


    // Check if any data was read from the file
    if (xValues.empty())
    {
        cerr << "Error: The input file contains no data.\n";
        return 1;
    }

    // Find the maximum x and y values to determine the size of the 2D array
    int maxXVal = *max_element(xValues.begin(), xValues.end());
    int maxYVal = *max_element(yValues.begin(), yValues.end());

    // Create a 2D array (vector of vectors) initialized with spaces
    vector<vector<string>> answerArray(
        maxYVal + 1,
        vector<string>(maxXVal + 1, " ")
    );

    // Populate the 2D array with the characters based on the coordinates
    populateArray(
        xValues,
        characterValues,
        yValues,
        answerArray
    );

    // Print the populated 2D array
    printArray(answerArray);

    // Close the input file
    inFile.close();

    return 0;
}
