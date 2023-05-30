#include <iostream>

using namespace std;

class Fuel
{
private:
    double distance; // Distance (km)
    double fuel;     // Fuel amount (liters)

public:
    // Constructor
    Fuel(double distance = 0.0)
    {
        this->distance = distance;
        fuel = 0.0;
    }

    // Getter and setter functions
    double getDistance() const
    {
        return distance;
    }

    double getFuel() const
    {
        return fuel;
    }

    void setDistance(double distance)
    {
        this->distance = distance;
    }

    void setFuel(double fuel)
    {
        this->fuel = fuel;
    }

    // Cost() friend function
    friend double Cost(const Fuel &obj);

    // + overloaded operator
    Fuel operator+(const Fuel &obj)
    {
        Fuel result;
        result.distance = distance + obj.distance;
        result.fuel = fuel + obj.fuel;
        return result;
    }

    // = overloaded operator
    void operator=(const Fuel &obj)
    {
        distance = obj.distance;
        fuel = obj.fuel;
    }
};

// Cost() friend function
double Cost(const Fuel &obj)
{
    return obj.getFuel();
}

int main()
{
    double windSpeed;     // Wind speed (km/h)
    double windDirection; // Wind direction (degrees)

    // Getting wind speed and wind direction from the user
    cout << "Enter the wind speed (km/h): ";
    cin >> windSpeed;
    cout << "Enter the wind direction (degrees): ";
    cin >> windDirection;

    // Calculating distances for A-B-A route
    double distanceAB = 100.0;
    double distanceBA = 2.0 * distanceAB;

    // Creating Fuel objects for the A-B-A route
    Fuel fuelAB(distanceAB);
    Fuel fuelBA(distanceBA);

    // Updating fuel amount based on wind speed
    if (windSpeed >= 0)
    {
        // Updating fuel amount based on wind direction
        if (windDirection == 0)
        {
            fuelAB.setFuel(fuelAB.getDistance() * 7.0); // Moving against the wind
            fuelBA.setFuel(fuelBA.getDistance() * 7.0); // Moving against the wind
        }
        else if (windDirection == 180)
        {
            fuelAB.setFuel(fuelAB.getDistance() * 6.5); // Moving with the wind
            fuelBA.setFuel(fuelBA.getDistance() * 6.5); // Moving with the wind
        }
        else
        {
            fuelAB.setFuel(fuelAB.getDistance() * 6.85); // Moving with the wind at an angle
            fuelBA.setFuel(fuelBA.getDistance() * 6.85); // Moving with the wind at an angle
        }
    }

    // Calculating total fuel amount for A-B-A route
    Fuel totalFuel = fuelAB + fuelBA;

    // Displaying the total fuel amount
    cout << "Total fuel amount for the A-B-A route: " << Cost(totalFuel) << " liters" << endl;

    return 0;
}
