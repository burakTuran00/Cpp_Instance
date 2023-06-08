#include <iostream>

class Room
{
private:
    int feet;
    double inch;

public:
    Room() : feet(0), inch(0.0) {}

    Room(int ft, double in) : feet(ft), inch(in) {}

    int getFeet() const
    {
        return feet;
    }

    double getInch() const
    {
        return inch;
    }

    void setFeet(int ft)
    {
        feet = ft;
    }

    void setInch(double in)
    {
        inch = in;
    }

    void calculateArea() const
    {
        std::cout << "Room Area: " << feet << "' " << inch << "\"" << std::endl;
    }

    friend Room operator+(const Room &room1, const Room &room2);
    friend Room operator*(const Room &room, double scalar);
    friend bool operator==(const Room &room1, const Room &room2);

    friend void calculateAreaImperial(const Room *house, int roomCount);
    friend void calculateAreaMetric(const Room *house, int roomCount);
};

Room operator+(const Room &room1, const Room &room2)
{
    int totalFeet = room1.feet + room2.feet;
    double totalInch = room1.inch + room2.inch;

    if (totalInch >= 12.0)
    {
        totalFeet++;
        totalInch -= 12.0;
    }

    return Room(totalFeet, totalInch);
}

Room operator*(const Room &room, double scalar)
{
    int totalFeet = static_cast<int>(room.feet * scalar);
    double totalInch = room.inch * scalar;

    if (totalInch >= 12.0)
    {
        totalFeet += static_cast<int>(totalInch / 12.0);
        totalInch = fmod(totalInch, 12.0);
    }

    return Room(totalFeet, totalInch);
}

bool operator==(const Room &room1, const Room &room2)
{
    return (room1.feet == room2.feet) && (room1.inch == room2.inch);
}

void calculateAreaImperial(const Room *house, int roomCount)
{
    Room totalRoomArea;

    for (int i = 0; i < roomCount; i++)
    {
        totalRoomArea = totalRoomArea + house[i];
    }

    std::cout << "Total Area of the House (Imperial): " << totalRoomArea.getFeet() << "' " << totalRoomArea.getInch() << "\"" << std::endl;
}

void calculateAreaMetric(const Room *house, int roomCount)
{
    Room totalRoomArea;

    for (int i = 0; i < roomCount; i++)
    {
        totalRoomArea = totalRoomArea + house[i];
    }

    std::cout << "Total Area of the House (Metric): " << totalRoomArea.getFeet() << "' " << totalRoomArea.getInch() << "\"" << std::endl;
}
