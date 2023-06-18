

# City Distance Calculation

This program offers a convenient and efficient way to calculate distances between cities and find cities within a certain distance of a given city. The program reads a list of cities from a file and stores them in a CityDatabase for fast and efficient queries.

## Key Features

1. **Different Distance Calculations**: The program supports Euclidean, Chebyshev, and Manhattan distance calculations. This allows users to choose the method that best suits their needs.

2. **Efficient Database Operations**: The CityDatabase uses a hash map (std::unordered_map) for city storage. This data structure provides constant time complexity for add, remove, and get operations, ensuring high performance even with large city datasets.

3. **Flexible City Queries**: Users can find nearby cities within a specified radius using any of the available distance calculation methods. The results are sorted by distance from the specified city, providing a convenient list for users.

4. **Error Handling**: The program includes robust error handling. If a user tries to query a city not present in the database, an informative error message is displayed, and the program continues running.

## Code Structure

- `City`: A simple class that represents a city with its name and coordinates.

- `DistanceCalculator` and its subclasses `EuclideanCalculator`, `ChebyshevCalculator`, and `ManhattanCalculator`: These classes calculate the distance between two cities using different metrics.

- `CityDatabase`: This class stores a collection of cities in an unordered_map for fast access. It also provides a method to find nearby cities within a certain radius.

- `CityReader`: This class reads cities from a file and adds them to the CityDatabase.

- `main.cpp`: This file contains the main function that interacts with the user, takes their input, and performs operations on the CityDatabase.

This program provides a flexible, user-friendly, and efficient way to work with cities and calculate distances. It demonstrates good practices in object-oriented design, error handling, and usage of STL containers and algorithms.

## How to Run

Compile the C++ files with a C++17 compliant compiler and run the resulting executable. Provide the name of a city, desired radius, and the norm for distance calculation when prompted. Enter '0' as the city name to stop the program.
