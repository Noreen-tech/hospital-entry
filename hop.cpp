#include <iostream>
#include <vector>
#include <string>

// Class to represent a patient
class Patient {
private:
    std::string name;
    int age;
    std::string gender;
    std::string address;
    std::string contactNumber;
    std::string ailment;

public:
    // Constructor
    Patient(const std::string& name, int age, const std::string& gender, const std::string& address, const std::string& contactNumber, const std::string& ailment)
        : name(name), age(age), gender(gender), address(address), contactNumber(contactNumber), ailment(ailment) {}

    // Function to display patient details
    void display() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Gender: " << gender << "\n";
        std::cout << "Address: " << address << "\n";
        std::cout << "Contact Number: " << contactNumber << "\n";
        std::cout << "Ailment: " << ailment << "\n\n";
    }
};

// Class to manage patient records
class Hospital {
private:
    std::vector<Patient> patients;

public:
    // Function to add a new patient
    void addPatient() {
        std::string name, gender, address, contactNumber, ailment;
        int age;

        std::cin.ignore(); // To clear the input buffer
        std::cout << "Enter patient's name: ";
        std::getline(std::cin, name);

        std::cout << "Enter patient's age: ";
        std::cin >> age;
        std::cin.ignore();

        std::cout << "Enter patient's gender: ";
        std::getline(std::cin, gender);

        std::cout << "Enter patient's address: ";
        std::getline(std::cin, address);

        std::cout << "Enter patient's contact number: ";
        std::getline(std::cin, contactNumber);

        std::cout << "Enter patient's ailment: ";
        std::getline(std::cin, ailment);

        //patients.emplace_back(name, age, gender, address, contactNumber, ailment);
        patients.push_back(Patient(name, age, gender, address, contactNumber, ailment));
        std::cout << "Patient added successfully!\n";
    }

    // Function to display all patients
    void displayPatients() const {
        if (patients.empty()) {
            std::cout << "No patient records available.\n";
            return;
        }

        std::cout << "\nPatient Details:\n";
        for (size_t i = 0; i < patients.size(); ++i) {
            std::cout << "Patient " << i + 1 << ":\n";
            patients[i].display();
        }
    }
};

int main() {
    Hospital hospital;
    int choice;

    do {
        std::cout << "\nHospital Patient Entry System\n";
        std::cout << "1. Add Patient\n";
        std::cout << "2. Display Patients\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            hospital.addPatient();
            break;
        case 2:
            hospital.displayPatients();
            break;
        case 3:
            std::cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}

