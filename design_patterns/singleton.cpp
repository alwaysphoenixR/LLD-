#include <iostream>
using namespace std;

class Singleton {
private:
    // Private constructor prevents creating objects from outside.
    Singleton() {
        cout << "Singleton instance created\n";
    }

    // Prevent copying the Singleton.
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& GetInstance() {
        // Local static variable:
        // Created only once, on the first call.
        // Initialization is thread-safe in C++11 and later.
        static Singleton instance;

        // Every call returns a reference to the same object.
        return instance;
    }

    void ShowMessage() {
        cout << "Hello from Singleton!\n";
    }
};

int main() {
    // No need to create a Singleton object directly.
    Singleton& s1 = Singleton::GetInstance();
    s1.ShowMessage();

    Singleton& s2 = Singleton::GetInstance();
    s2.ShowMessage();

    // Both references point to the same object.
    cout << boolalpha << (&s1 == &s2) << '\n'; // true

    return 0;
}

//NOT THREAD SAFE THAT PART 

// #include <iostream>
// using namespace std;

// class Singleton {
// private:
//     // Shared pointer belonging to the class, not individual objects.
//     static Singleton* instance_;

//     // Private constructor prevents external object creation.
//     Singleton() {
//         cout << "Singleton instance created\n";
//     }

//     // Prevent copying the Singleton.
//     Singleton(const Singleton&) = delete;
//     Singleton& operator=(const Singleton&) = delete;

// public:
//     static Singleton* GetInstance() {
//         // Create the object only if it doesn't exist.
//         // WARNING: This check-and-create operation is not thread-safe.
//         if (instance_ == nullptr) {
//             instance_ = new Singleton();
//         }

//         // Return the address of the same instance.
//         return instance_;
//     }

//     void ShowMessage() {
//         cout << "Hello from Singleton!\n";
//     }
// };

// // Define and initialize the static data member outside the class.
// Singleton* Singleton::instance_ = nullptr;

// int main() {
//     // Get the Singleton instance.
//     Singleton* s1 = Singleton::GetInstance();
//     s1->ShowMessage();

//     Singleton* s2 = Singleton::GetInstance();
//     s2->ShowMessage();

//     // Both pointers should point to the same object.
//     cout << boolalpha << (s1 == s2) << '\n'; // true

//     // This simple implementation doesn't free the instance explicitly.
//     // It remains allocated until the program terminates.

//     return 0;
// }