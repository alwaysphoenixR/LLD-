// 3. Create the Strategy interface
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DeliveryStrategy {
public:
    virtual double calculateFee(double distance) = 0;

    virtual ~DeliveryStrategy() = default;
};
// 4. Create individual strategies
// Standard
class StandardDelivery : public DeliveryStrategy {
public:
    double calculateFee(double distance) override {
        return distance * 5;
    }
};

// Express
class ExpressDelivery : public DeliveryStrategy {
public:
    double calculateFee(double distance) override {
        return distance * 10;
    }
};

// Same-day
class SameDayDelivery : public DeliveryStrategy {
public:
    double calculateFee(double distance) override {
        return distance * 20;
    }
};
// 5. Create the Context
// The Context is the class that uses the strategy.
class DeliveryService {
private:
    DeliveryStrategy& strategy;

public:
    DeliveryService(DeliveryStrategy& s)
        : strategy(s) {}

    double calculateFee(double distance) {
        return strategy.calculateFee(distance);
    }
};
int main() {

    StandardDelivery standard;
    ExpressDelivery express;

    DeliveryService service1(standard);
    cout << service1.calculateFee(10);

    DeliveryService service2(express);
    cout << service2.calculateFee(10);
}
//READ THIS IMPLICIT AND EXPLICIT CASE ALSO VERY IMPORTANT FOR INTERVIEWS 
// 1. First, imagine this constructor
// class Sorter {
// public:
//     Sorter(int x) {
//         cout << "Sorter created: " << x << endl;
//     }
// };


// You can create an object normally:
// Sorter s(10);  // Works


// Here, you are explicitly telling C++ to create a Sorter with 10.
// 2. What happens without explicit?
// class Sorter {
// public:
//     Sorter(int x) {
//         cout << "Sorter created: " << x << endl;
//     }
// };

// int main() {
//     Sorter s = 10;  // Also works!
// }


// Wait, 10 is an integer, not a Sorter. Why does this work?
// Because C++ automatically converts 10 into a Sorter object by calling the constructor.
// It's roughly equivalent to:
// Sorter s(10);


// C++ is doing the conversion for you.
// 3. Now add explicit
// class Sorter {
// public:
//     explicit Sorter(int x) {
//         cout << "Sorter created: " << x << endl;
//     }
// };

// int main() {
//     Sorter s(10);  // Works

//     // Sorter s2 = 10;  // Compilation error
// }


// Now C++ says: "You must explicitly ask me to construct a Sorter. I won't automatically convert an integer into one."
// That's the whole idea!
// 4. Now connect it to your Strategy Pattern
// Your original code was:
// explicit Sorter(SortingStrategy* strategy)
//     : strategy_(strategy) {}


// Here, instead of an integer, the constructor takes a pointer to a sorting strategy.
// With explicit:
// BubbleSort bubble;

// Sorter s(&bubble);  // Works: direct construction


// But this kind of implicit conversion is prohibited:
// void process(Sorter s);

// BubbleSort bubble;

// process(&bubble);  // Compilation error with explicit


// Without explicit, C++ could automatically create a temporary Sorter from &bubble and pass it to process().
// With explicit, you must write:
// process(Sorter(&bubble));  // Works