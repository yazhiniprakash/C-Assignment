#include <iostream>

using namespace std;



// Unit definitions

struct Meter
{



     static constexpr double factor = 1.0;

};



struct Kilometer

{

     static constexpr double factor = 1000.0;

};


struct Centimeter

{

     static constexpr double factor = 0.01;

};



// Template class for type-safe quantity

template <typename Unit>

class Quantity

{

private:

     double value;



public:

     constexpr Quantity(double v) : value(v) {}


     constexpr double getValue() const

     {

         return value;

     }


};



// Template conversion function

template <typename ToUnit, typename FromUnit>

constexpr Quantity<ToUnit> convert(

     const Quantity<FromUnit>& quantity)

{

     // Convert source unit to base unit (meter)
     double baseValue =

       quantity.getValue() * FromUnit::factor;



     // Convert base unit to target unit

     double convertedValue =

       baseValue / ToUnit::factor;



     return Quantity<ToUnit>(convertedValue);

}



int main()

{

     // Create quantity in meters

     constexpr Quantity<Meter> distance(5000);


     // Compile-time conversion

     constexpr auto km =

       convert<Kilometer>(distance);




    constexpr auto cm =

      convert<Centimeter>(distance);



    cout << "Distance in Meters: "

       << distance.getValue() << " m" << endl;



    cout << "Distance in Kilometers: "

       << km.getValue() << " km" << endl;


    cout << "Distance in Centimeters: "

       << cm.getValue() << " cm" << endl;



    return 0;

}

OUTPUT:
Distance in Meters: 5000 m
Distance in Kilometers: 5 km
Distance in Centimeters: 500000 cm
