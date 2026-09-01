#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ============================================================
// ABSTRACT BASE CLASS
// ============================================================

class Resource {
protected:
    int resourceID;
    string location;
    bool available;

public:
    Resource() {
        resourceID = 0;
        location = "Unknown";
        available = true;
    }

    Resource(int id, string loc) {
        resourceID = id;
        location = loc;
        available = true;
    }

    Resource(const Resource& r) {
        resourceID = r.resourceID;
        location = r.location;
        available = r.available;
    }

    virtual void display() const = 0;
    virtual string getType() const = 0;

    int getID() const {
        return resourceID;
    }

    bool isAvailable() const {
        return available;
    }

    void allocate() {
        available = false;
    }

    void release() {
        available = true;
    }

    virtual ~Resource() {
        cout << "Resource " << resourceID << " finalized.\n";
    }
};


// ============================================================
// AMBULANCE CLASS
// ============================================================

class Ambulance : public Resource {
private:
    string ambulanceType;
    int capacity;

public:
    Ambulance() : Resource() {
        ambulanceType = "Basic";
        capacity = 2;
    }

    Ambulance(int id, string loc, string type, int cap)
        : Resource(id, loc) {
        ambulanceType = type;
        capacity = cap;
    }

    Ambulance(const Ambulance& a)
        : Resource(a) {
        ambulanceType = a.ambulanceType;
        capacity = a.capacity;
    }

    void display() const override {
        cout << "Ambulance ID: " << resourceID
             << " | Type: " << ambulanceType
             << " | Capacity: " << capacity
             << " | Location: " << location
             << " | Status: "
             << (available ? "Available" : "Allocated") << endl;
    }

    string getType() const override {
        return "Ambulance";
    }

    ~Ambulance() {
        cout << "Ambulance " << resourceID << " destroyed.\n";
    }
};


// ============================================================
// VIRTUAL BASE CLASS
// ============================================================

class MedicalFacility {
protected:
    string hospitalName;

public:
    MedicalFacility() {
        hospitalName = "SmartCare Hospital";
    }

    MedicalFacility(string name) {
        hospitalName = name;
    }

    virtual void facilityInfo() const {
        cout << "Hospital: " << hospitalName << endl;
    }

    virtual ~MedicalFacility() {}
};


// ============================================================
// EMERGENCY BED CLASS
// Demonstrates multiple inheritance + virtual base
// ============================================================

class EmergencyBed : public Resource, virtual public MedicalFacility {
private:
    string bedType;
    int roomNumber;

public:
    EmergencyBed() : Resource(), MedicalFacility() {
        bedType = "General";
        roomNumber = 0;
    }

    EmergencyBed(int id, string loc, string type, int room)
        : Resource(id, loc), MedicalFacility("SmartCare Hospital") {
        bedType = type;
        roomNumber = room;
    }

    EmergencyBed(const EmergencyBed& b)
        : Resource(b), MedicalFacility(b.hospitalName) {
        bedType = b.bedType;
        roomNumber = b.roomNumber;
    }

    void display() const override {
        cout << "Bed ID: " << resourceID
             << " | Type: " << bedType
             << " | Room: " << roomNumber
             << " | Location: " << location
             << " | Status: "
             << (available ? "Available" : "Occupied") << endl;
    }

    string getType() const override {
        return "Emergency Bed";
    }

    ~EmergencyBed() {
        cout << "Emergency Bed " << resourceID << " destroyed.\n";
    }
};


// ============================================================
// MEDICAL EQUIPMENT CLASS
// ============================================================

class MedicalEquipment : public Resource {
private:
    string equipmentName;
    int quantity;

public:
    MedicalEquipment() : Resource() {
        equipmentName = "Unknown";
        quantity = 1;
    }

    MedicalEquipment(int id, string loc, string name, int qty)
        : Resource(id, loc) {
        equipmentName = name;
        quantity = qty;
    }

    MedicalEquipment(const MedicalEquipment& e)
        : Resource(e) {
        equipmentName = e.equipmentName;
        quantity = e.quantity;
    }

    void display() const override {
        cout << "Equipment ID: " << resourceID
             << " | Name: " << equipmentName
             << " | Quantity: " << quantity
             << " | Location: " << location
             << " | Status: "
             << (available ? "Available" : "Allocated") << endl;
    }

    string getType() const override {
        return "Medical Equipment";
    }

    ~MedicalEquipment() {
        cout << "Equipment " << resourceID << " destroyed.\n";
    }
};


// ============================================================
// RESPONSE TEAM CLASS
// ============================================================

class ResponseTeam : public Resource {
private:
    string teamName;
    int members;

public:
    ResponseTeam() : Resource() {
        teamName = "Emergency Team";
        members = 3;
    }

    ResponseTeam(int id, string loc, string name, int count)
        : Resource(id, loc) {
        teamName = name;
        members = count;
    }

    ResponseTeam(const ResponseTeam& r)
        : Resource(r) {
        teamName = r.teamName;
        members = r.members;
    }

    void display() const override {
        cout << "Team ID: " << resourceID
             << " | Team: " << teamName
             << " | Members: " << members
             << " | Location: " << location
             << " | Status: "
             << (available ? "Available" : "Busy") << endl;
    }

    string getType() const override {
        return "Response Team";
    }

    ~ResponseTeam() {
        cout << "Response Team " << resourceID << " destroyed.\n";
    }
};


// ============================================================
// PATIENT CLASS
// ============================================================

class Patient {
private:
    int patientID;
    string name;
    int age;
    string condition;

public:
    Patient() {
        patientID = 0;
        name = "Unknown";
        age = 0;
        condition = "Unknown";
    }

    Patient(int id, string n, int a, string c) {
        patientID = id;
        name = n;
        age = a;
        condition = c;
    }

    Patient(const Patient& p) {
        patientID = p.patientID;
        name = p.name;
        age = p.age;
        condition = p.condition;
    }

    void display() const {
        cout << "Patient ID: " << patientID
             << " | Name: " << name
             << " | Age: " << age
             << " | Condition: " << condition << endl;
    }

    int getID() const {
        return patientID;
    }

    ~Patient() {
        // Destructor
    }
};


// ============================================================
// EMERGENCY CASE CLASS
// ============================================================

class EmergencyCase {
private:
    int caseID;
    int patientID;
    int urgency;
    string description;
    bool active;

public:

    // Default constructor
    EmergencyCase() {
        caseID = 0;
        patientID = 0;
        urgency = 1;
        description = "Unknown";
        active = false;
    }

    // Parameterized constructor
    EmergencyCase(int cid, int pid, int u, string d) {
        caseID = cid;
        patientID = pid;
        urgency = u;
        description = d;
        active = true;
    }

    // Copy constructor
    EmergencyCase(const EmergencyCase& e) {
        caseID = e.caseID;
        patientID = e.patientID;
        urgency = e.urgency;
        description = e.description;
        active = e.active;
    }

    int getCaseID() const {
        return caseID;
    }

    int getUrgency() const {
        return urgency;
    }

    bool isActive() const {
        return active;
    }

    void closeCase() {
        active = false;
    }

    void display() const {
        cout << "Case ID: " << caseID
             << " | Patient ID: " << patientID
             << " | Urgency: " << urgency
             << " | Description: " << description
             << " | Status: "
             << (active ? "Active" : "Closed") << endl;
    }

    // OPERATOR OVERLOADING 1
    // Compare emergency case priority
    bool operator>(const EmergencyCase& e) const {
        return urgency > e.urgency;
    }

    // OPERATOR OVERLOADING 2
    // Combine urgency scores
    int operator+(const EmergencyCase& e) const {
        return urgency + e.urgency;
    }

    ~EmergencyCase() {
        if (active) {
            cout << "Emergency Case " << caseID
                 << " finalized.\n";
        }
    }
};


// ============================================================
// SMART HOSPITAL SYSTEM
// ============================================================

class SmartHospitalSystem {
private:

    // Arrays of objects
    Patient patients[50];
    EmergencyCase cases[50];

    int patientCount;
    int caseCount;

    // Static shared information
    static int totalResources;
    static int activeCases;

    // Dynamic resource array
    Resource* resources[50];
    int resourceCount;

public:

    SmartHospitalSystem() {
        patientCount = 0;
        caseCount = 0;
        resourceCount = 0;
    }

    // --------------------------------------------------------
    // Register Patient
    // --------------------------------------------------------

    void registerPatient() {

        if (patientCount >= 50) {
            cout << "Patient storage is full.\n";
            return;
        }

        int id, age;
        string name, condition;

        cout << "\nEnter Patient ID: ";
        cin >> id;

        cout << "Enter Patient Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Medical Condition: ";
        cin.ignore();
        getline(cin, condition);

        patients[patientCount] =
            Patient(id, name, age, condition);

        patientCount++;

        cout << "Patient registered successfully.\n";
    }


    // --------------------------------------------------------
    // Register Resources
    // --------------------------------------------------------

    void registerResource() {

        if (resourceCount >= 50) {
            cout << "Resource storage is full.\n";
            return;
        }

        int choice;
        int id;
        string location;

        cout << "\n===== RESOURCE REGISTRATION =====\n";
        cout << "1. Ambulance\n";
        cout << "2. Emergency Bed\n";
        cout << "3. Medical Equipment\n";
        cout << "4. Response Team\n";
        cout << "Enter choice: ";
        cin >> choice;

        cout << "Enter Resource ID: ";
        cin >> id;

        cout << "Enter Location: ";
        cin.ignore();
        getline(cin, location);

        if (choice == 1) {

            string type;
            int capacity;

            cout << "Enter Ambulance Type: ";
            getline(cin, type);

            cout << "Enter Capacity: ";
            cin >> capacity;

            resources[resourceCount] =
                new Ambulance(id, location, type, capacity);
        }

        else if (choice == 2) {

            string type;
            int room;

            cout << "Enter Bed Type: ";
            cin.ignore();
            getline(cin, type);

            cout << "Enter Room Number: ";
            cin >> room;

            resources[resourceCount] =
                new EmergencyBed(id, location, type, room);
        }

        else if (choice == 3) {

            string name;
            int quantity;

            cout << "Enter Equipment Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Quantity: ";
            cin >> quantity;

            resources[resourceCount] =
                new MedicalEquipment(
                    id, location, name, quantity);
        }

        else if (choice == 4) {

            string name;
            int members;

            cout << "Enter Team Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Number of Members: ";
            cin >> members;

            resources[resourceCount] =
                new ResponseTeam(
                    id, location, name, members);
        }

        else {
            cout << "Invalid resource type.\n";
            return;
        }

        resourceCount++;
        totalResources++;

        cout << "Resource registered successfully.\n";
    }


    // --------------------------------------------------------
    // Display Resources
    // --------------------------------------------------------

    void displayResources() const {

        if (resourceCount == 0) {
            cout << "\nNo resources registered.\n";
            return;
        }

        cout << "\n========== RESOURCE LIST ==========\n";

        // Base-class pointer + runtime polymorphism
        for (int i = 0; i < resourceCount; i++) {
            resources[i]->display();
        }
    }


    // --------------------------------------------------------
    // Create Emergency Case
    // --------------------------------------------------------

    void createEmergencyCase() {

        if (caseCount >= 50) {
            cout << "Case storage is full.\n";
            return;
        }

        int caseID, patientID, urgency;
        string description;

        cout << "\nEnter Case ID: ";
        cin >> caseID;

        cout << "Enter Patient ID: ";
        cin >> patientID;

        cout << "\nUrgency Level\n";
        cout << "1 - Low\n";
        cout << "2 - Moderate\n";
        cout << "3 - High\n";
        cout << "4 - Critical\n";
        cout << "5 - Life Threatening\n";

        cout << "Enter urgency: ";
        cin >> urgency;

        if (urgency < 1 || urgency > 5) {
            cout << "Invalid urgency level.\n";
            return;
        }

        cout << "Enter Case Description: ";
        cin.ignore();
        getline(cin, description);

        cases[caseCount] =
            EmergencyCase(
                caseID,
                patientID,
                urgency,
                description);

        caseCount++;
        activeCases++;

        cout << "Emergency case created successfully.\n";
    }


    // --------------------------------------------------------
    // Compare Case Priorities
    // --------------------------------------------------------

    void compareCases() {

        if (caseCount < 2) {
            cout << "At least two cases are required.\n";
            return;
        }

        int id1, id2;
        int index1 = -1;
        int index2 = -1;

        cout << "Enter first Case ID: ";
        cin >> id1;

        cout << "Enter second Case ID: ";
        cin >> id2;

        for (int i = 0; i < caseCount; i++) {

            if (cases[i].getCaseID() == id1)
                index1 = i;

            if (cases[i].getCaseID() == id2)
                index2 = i;
        }

        if (index1 == -1 || index2 == -1) {
            cout << "Case not found.\n";
            return;
        }

        if (cases[index1] > cases[index2]) {
            cout << "Case " << id1
                 << " has higher priority.\n";
        }
        else if (cases[index2] > cases[index1]) {
            cout << "Case " << id2
                 << " has higher priority.\n";
        }
        else {
            cout << "Both cases have equal priority.\n";
        }

        // Demonstrating second operator
        int combined =
            cases[index1] + cases[index2];

        cout << "Combined urgency score: "
             << combined << endl;
    }


    // --------------------------------------------------------
    // Allocate Resource
    // --------------------------------------------------------

    void allocateResource() {

        if (resourceCount == 0) {
            cout << "No resources available.\n";
            return;
        }

        int id;

        cout << "\nEnter Resource ID to allocate: ";
        cin >> id;

        for (int i = 0; i < resourceCount; i++) {

            if (resources[i]->getID() == id) {

                if (resources[i]->isAvailable()) {
                    resources[i]->allocate();

                    cout << "Resource " << id
                         << " allocated successfully.\n";
                }
                else {
                    cout << "Resource is already allocated.\n";
                }

                return;
            }
        }

        cout << "Resource not found.\n";
    }


    // --------------------------------------------------------
    // Release Resource
    // --------------------------------------------------------

    void releaseResource() {

        int id;

        cout << "\nEnter Resource ID to release: ";
        cin >> id;

        for (int i = 0; i < resourceCount; i++) {

            if (resources[i]->getID() == id) {

                resources[i]->release();

                cout << "Resource released successfully.\n";
                return;
            }
        }

        cout << "Resource not found.\n";
    }


    // --------------------------------------------------------
    // Close Emergency Case
    // --------------------------------------------------------

    void closeEmergencyCase() {

        int id;

        cout << "\nEnter Case ID to close: ";
        cin >> id;

        for (int i = 0; i < caseCount; i++) {

            if (cases[i].getCaseID() == id) {

                if (cases[i].isActive()) {
                    cases[i].closeCase();

                    if (activeCases > 0)
                        activeCases--;

                    cout << "Emergency case closed.\n";
                }
                else {
                    cout << "Case is already closed.\n";
                }

                return;
            }
        }

        cout << "Case not found.\n";
    }


    // --------------------------------------------------------
    // Display Patients
    // --------------------------------------------------------

    void displayPatients() const {

        if (patientCount == 0) {
            cout << "\nNo patients registered.\n";
            return;
        }

        cout << "\n========== PATIENT LIST ==========\n";

        for (int i = 0; i < patientCount; i++) {
            patients[i].display();
        }
    }


    // --------------------------------------------------------
    // Display Cases
    // --------------------------------------------------------

    void displayCases() const {

        if (caseCount == 0) {
            cout << "\nNo emergency cases registered.\n";
            return;
        }

        cout << "\n========== EMERGENCY CASES ==========\n";

        for (int i = 0; i < caseCount; i++) {
            cases[i].display();
        }
    }


    // --------------------------------------------------------
    // Coordination Report
    // --------------------------------------------------------

    void generateReport() const {

        int available = 0;

        for (int i = 0; i < resourceCount; i++) {

            if (resources[i]->isAvailable())
                available++;
        }

        cout << "\n";
        cout << "========================================\n";
        cout << " SMART EMERGENCY COORDINATION REPORT\n";
        cout << "========================================\n";

        cout << "Registered Patients : "
             << patientCount << endl;

        cout << "Registered Resources: "
             << totalResources << endl;

        cout << "Active Emergency Cases: "
             << activeCases << endl;

        cout << "Available Resources : "
             << available << endl;

        cout << "Allocated Resources : "
             << resourceCount - available << endl;

        if (totalResources > 0) {

            double utilization =
                ((double)(resourceCount - available)
                 / totalResources) * 100;

            cout << fixed << setprecision(2);

            cout << "Resource Utilization : "
                 << utilization << "%\n";
        }

        cout << "========================================\n";
    }


    // --------------------------------------------------------
    // Destructor
    // Releases dynamically allocated resources
    // --------------------------------------------------------

    ~SmartHospitalSystem() {

        for (int i = 0; i < resourceCount; i++) {
            delete resources[i];
        }

        cout << "\nSmart Hospital System closed.\n";
    }
};


// ============================================================
// STATIC MEMBER INITIALIZATION
// ============================================================

int SmartHospitalSystem::totalResources = 0;
int SmartHospitalSystem::activeCases = 0;


// ============================================================
// MAIN FUNCTION
// ============================================================

int main() {

    SmartHospitalSystem system;

    int choice;

    do {

        cout << "\n\n";
        cout << "==============================================\n";
        cout << " SMART EMERGENCY MEDICAL RESOURCE SYSTEM\n";
        cout << "==============================================\n";

        cout << "1. Register Patient\n";
        cout << "2. Register Resource\n";
        cout << "3. Display Patients\n";
        cout << "4. Display Resources\n";
        cout << "5. Create Emergency Case\n";
        cout << "6. Display Emergency Cases\n";
        cout << "7. Allocate Resource\n";
        cout << "8. Release Resource\n";
        cout << "9. Compare Case Priorities\n";
        cout << "10. Close Emergency Case\n";
        cout << "11. Generate Coordination Report\n";
        cout << "0. Exit\n";

        cout << "----------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            system.registerPatient();
            break;

        case 2:
            system.registerResource();
            break;

        case 3:
            system.displayPatients();
            break;

        case 4:
            system.displayResources();
            break;

        case 5:
            system.createEmergencyCase();
            break;

        case 6:
            system.displayCases();
            break;

        case 7:
            system.allocateResource();
            break;

        case 8:
            system.releaseResource();
            break;

        case 9:
            system.compareCases();
            break;

        case 10:
            system.closeEmergencyCase();
            break;

        case 11:
            system.generateReport();
            break;

        case 0:
            cout << "\nThank you for using the system!\n";
            break;

        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
