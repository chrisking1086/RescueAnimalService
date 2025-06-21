//======================================================================
// Name			: RescueAnimalService.cpp
// Author		: Christopher King
// Version		: 1.0
// Description	: Base class for Binary Search Tree of Rescue Animals
//======================================================================

#include <iostream>
#include <time.h>
#include <string>
#include <limits>
#include <cctype>



// Forward declaration of RescueAnimalService
class RescueAnimalService;

// RescueAnimal structure definition
struct RescueAnimal {
    // Variables and methods common to all rescue animals
    enum class AnimalType {
        Unknown,
        Dog,
        Monkey
    };
    enum class Gender {
        Unknown,
        Female,
        Male
    };
    enum class TrainingStatus {
        Unknown,
        NotTrained,
        InTraining,
        Trained
    };
    std::string animalID = "";
    std::string name = "";
    std::string acquisitionDate = "";
    std::string acquisitionCountry = "";
    std::string inServiceCountry = "";
    bool isReserved = false;
    int age = 0;
    double weight = 0.0;
    AnimalType animalType = AnimalType::Unknown;
    Gender gender = Gender::Unknown;
    TrainingStatus trainingStatus = TrainingStatus::Unknown;

    // Setters
    void setName(const std::string& n) { this->name = n; }
    void setAnimalID(const std::string& id) { this->animalID = id; }
    void setAcquisitionDate(const std::string& date) { this->acquisitionDate = date; }
    void setAcquisitionCountry(const std::string& country) { this->acquisitionCountry = country; }
    void setInServiceCountry(const std::string& country) { this->inServiceCountry = country; }
    void setIsReserved(bool reserved) { this->isReserved = reserved; }
    void setAge(int a) { this->age = a; }
    void setWeight(double w) { this->weight = w; }
    void setAnimalType(AnimalType type) { this->animalType = type; }
    void setGender(Gender gender) { this->gender = gender; }
    void setTrainingStatus(TrainingStatus status) { this->trainingStatus = status; }

    // Getters
    std::string getAnimalID() const { return this->animalID; }
    bool getIsReserved() const { return this->isReserved; }
};

// Dog structure derived from RescueAnimal
struct Dog : public RescueAnimal {
    // Variables and methods specific to Dog
    std::string breed = "";

    // Setters for Dog specific attributes
    void setBreed(const std::string& b) { this->breed = b; }

    // Constructor to set animalType to Dog
    Dog() { animalType = AnimalType::Dog; }
};

// Monkey structure derived from RescueAnimal
struct Monkey : public RescueAnimal {
    // Variables and methods specific to Monkey
    enum class Species {
        Unknown,
        Capuchin,
        Guenon,
        Macaque,
        Marmoset,
        SquirrelMonkey,
        Tamarin
    };
    int tailLengthInches = 0;
    int bodyLengthInches = 0;
    int heightInches = 0;
    Species species = Species::Unknown;

    // Setters for Monkey specific attributes
    void setTailLengthInches(int length) { this->tailLengthInches = length; }
    void setBodyLengthInches(int length) { this->bodyLengthInches = length; }
    void setHeightInches(int height) { this->heightInches = height; }
    void setSpecies(Species s) { this->species = s; }
    // Constructor to set animalType to Monkey
    Monkey() { animalType = AnimalType::Monkey; }
};

// Node structure for Binary Search Tree
struct Node {
    RescueAnimal animal;
    Node* left;
    Node* right;

    Node(RescueAnimal a) : animal(a), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class definition
class BinarySearchTree {
public:

    Node* root;

    // Constructor and Destructor
    BinarySearchTree() : root(nullptr) {
        // NOTE: This is for demonstration purposes only.
        initializeAnimalList(); // Initialize with some animals
		std::cout << "Binary Search Tree initialized with sample animals.\n";
    }

    // Destructor to clean up the tree
    virtual ~BinarySearchTree() {
        deleteTree(root);
    }

    // NOTE: This is for demonstration purposes only.
void initializeAnimalList() {
		// Add some initial dogs
    for (int i = 0; i < 5; ++i) {
			Dog dog;
			dog.setAnimalID("dog" + std::to_string(i + 1));
			dog.setName("Dog" + std::to_string(i + 1));
			dog.setAge(rand() % 10 + 1); // Random age between 1 and 10
			dog.setWeight(rand() % 100 + 20); // Random weight between 20 and 120 lbs
			dog.setAcquisitionDate("2023-01-01");
			dog.setAcquisitionCountry("USA");
			dog.setInServiceCountry("USA");
			dog.setTrainingStatus(static_cast<RescueAnimal::TrainingStatus>(rand() % 3)); // Random training status
			dog.setBreed("Breed" + std::to_string(i + 1));
            if (i % 2 == 0) { // Alternate reserved status
                dog.setIsReserved(false);
            } else {
				dog.setIsReserved(true);
			}
			insertDog(dog);
		}

		// Add some initial monkeys
    for (int i = 0; i < 5; ++i) {
        Monkey monkey;
			monkey.setAnimalID("monkey" + std::to_string(i + 1));
			monkey.setName("Monkey" + std::to_string(i + 1));
			monkey.setAge(rand() % 10 + 1); // Random age between 1 and 10
			monkey.setWeight(rand() % 100 + 20); // Random weight between 20 and 120 lbs
			monkey.setAcquisitionDate("2023-01-01");
			monkey.setAcquisitionCountry("USA");
			monkey.setInServiceCountry("USA");
			monkey.setTrainingStatus(static_cast<RescueAnimal::TrainingStatus>(rand() % 3)); // Random training status
			monkey.setTailLengthInches(rand() % 30 + 10); // Random tail length between 10 and 40 inches
			monkey.setBodyLengthInches(rand() % 30 + 10); // Random body length between 10 and 40 inches
			monkey.setHeightInches(rand() % 30 + 10); // Random height between 10 and 40 inches
			monkey.setSpecies(static_cast<Monkey::Species>(rand() % 6)); // Random species
			if (i % 2 == 0) { // Alternate reserved status
				monkey.setIsReserved(false);
			} else {
				monkey.setIsReserved(true);
			}
			insertMonkey(monkey);
		}


	}

    // Delete the entire tree recursively
    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left); // Recursively delete left subtree
            deleteTree(node->right); // Recursively delete right subtree
            delete node;             // Delete the current node
        }
    }

    // Add a new animal to the binary search tree
    void addNode(Node* node, RescueAnimal animal) { // Pass animal by value to copy it
        if (node->animal.animalID.compare(animal.animalID) < 0) {
            if (node->right == nullptr) {
                node->right = new Node(animal);
            }
            else {
                addNode(node->right, animal);
            }
        }
        else if (node->animal.animalID.compare(animal.animalID) > 0) {
            if (node->left == nullptr) {
                node->left = new Node(animal);
            }
            else {
                addNode(node->left, animal);
            }
        }
        else {
            std::cout << "Animal with ID " << animal.animalID << " already exists." << std::endl;
        }
    }

    // Search for an animal by ID and return a pointer to it
    RescueAnimal* search(const std::string& animalID) {
        Node* current = root;

        while (current != nullptr) {
            if (current->animal.animalID == animalID) {
                return &current->animal; // Return the address of the found animal
            }
            else if (current->animal.animalID < animalID) {
                current = current->right; // Search in the right subtree
            }
            else {
                current = current->left; // Search in the left subtree
            }
        }
        return nullptr; // Return nullptr if not found
    }

    void printAllDogs(Node* node) {
        if (node != nullptr) {
            printAllDogs(node->left); // Traverse left subtree
            if (node->animal.animalType == RescueAnimal::AnimalType::Dog) {
                std::cout << "Dog ID: " << node->animal.animalID << ", Name: " << node->animal.name << std::endl;
            }
            printAllDogs(node->right); // Traverse right subtree
        }
    }
	
	// Print all monkeys in the binary search tree
    void printAllMonkeys(Node* node) {
        std::string reserveStatus = "Available"; // Default reserve status
		
        if (node != nullptr) {
            printAllMonkeys(node->left); // Traverse left subtree
            if (node->animal.animalType == RescueAnimal::AnimalType::Monkey) {
                if (node->animal.isReserved) {
                    std::string reserveStatus = "Reserved";
                }
				else {
					reserveStatus = "Available";
				}

                std::cout << "Monkey ID: " << node->animal.animalID << ", Name: " << node->animal.name << " Reserve Status: " << reserveStatus << std::endl;
            }
            printAllMonkeys(node->right); // Traverse right subtree
        }
    }

    // Prints all animals that are NOT reserved
    void printUnreservedAnimals(Node* node) {
        if (node != nullptr) {
            printUnreservedAnimals(node->left); // Traverse left subtree
            if (!node->animal.isReserved) { // Print if NOT reserved
                std::string currentAnimalType = "";
                if (node->animal.animalType == RescueAnimal::AnimalType::Dog) {
                    currentAnimalType = "Dog";
                }
                else if (node->animal.animalType == RescueAnimal::AnimalType::Monkey) {
                    currentAnimalType = "Monkey";
                }
                else {
                    currentAnimalType = "Unknown";
                }
                std::cout << "Animal ID: " << node->animal.animalID << ", Name: " << node->animal.name << ", Animal Type: " << currentAnimalType << std::endl;
            }
            printUnreservedAnimals(node->right); // Traverse right subtree
        }
    }

    void insertDog(Dog dog) { // Take Dog by value
        if (root == nullptr) {
            root = new Node(dog);
        }
        else {
            addNode(root, dog);
        }
    }
	
    void insertMonkey(Monkey monkey) { // Take Monkey by value
        if (root == nullptr) {
            root = new Node(monkey);
        }
        else {
            addNode(root, monkey);
        }
    }
};


// RescueAnimalService class definition
class RescueAnimalService
{
public:
    BinarySearchTree* bst = new BinarySearchTree();

    // Constructor to seed random number generator
    RescueAnimalService() {
        srand(static_cast<unsigned int>(time(NULL)));
    }

    // Destructor to clean up BinarySearchTree
    ~RescueAnimalService() {
        delete bst;
    }

    void menu() {
        int menuInput = 0;
        while (menuInput != 9) {
            std::cout << "\n--- Rescue Animal Service Menu ---\n";
            std::cout << "1. Intake new dog\n";
            std::cout << "2. Intake new monkey\n";
            std::cout << "3. Reserve an animal\n";
            std::cout << "4. Print a list of all dogs\n";
            std::cout << "5. Print a list of all monkeys\n";
            std::cout << "6. Print a list of all animals that are not reserved\n";
            std::cout << "9. Exit\n";
            std::cout << "Enter your choice: ";

            // Input validation for menu choice
            while (!(std::cin >> menuInput)) {
                std::cout << "Invalid input. Please enter a number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer after number input

            switch (menuInput)
            {
            case 1:
                intakeNewAnimal(1); // 1 for dog
                break;
            case 2:
                intakeNewAnimal(2); // 2 for monkey
                break;
            case 3:
                reserveAnimal();
                break;
            case 4:
                printAnimals(1); // Print all dogs
                break;
            case 5:
                printAnimals(2); // Print all monkeys
                break;
            case 6:
                printAnimals(3); // Print all animals that are not reserved
                break;
            case 9:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
            }
        }
    }

    void printAnimals(int displayType) {
        std::cout << "\n--- Printing Animals ---\n";

        if (bst->root == nullptr) {
            std::cout << "No animals in the system.\n";
            return;
        }

        if (displayType == 1) {
            std::cout << "--- List of All Dogs ---\n";
            bst->printAllDogs(bst->root);
        }
        else if (displayType == 2) {
            std::cout << "--- List of All Monkeys ---\n";
            bst->printAllMonkeys(bst->root);
        }
        else if (displayType == 3) {
            std::cout << "--- List of All Unreserved Animals ---\n";
            bst->printUnreservedAnimals(bst->root);
        }
        else {
            std::cout << "Invalid display type." << std::endl;
        }
    }

    void intakeNewAnimal(int animalMenuType) {
        std::cout << "\n--- Intake New Animal ---\n";

        std::string name, acquisitionDate, acquisitionCountry, inServiceCountry, breed, animalID;
        int age, tailLengthInches, bodyLengthInches, heightInches;
        double weight;
        RescueAnimal::TrainingStatus trainingStatus = RescueAnimal::TrainingStatus::Unknown;
        RescueAnimal::Gender gender = RescueAnimal::Gender::Unknown;
        Monkey::Species species = Monkey::Species::Unknown;
        bool isReserved;

        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        while (name.empty()) {
            std::cout << "Name cannot be empty. Please enter a valid name: ";
            std::getline(std::cin, name);
        }
        animalID = generateAnimalID(name);

        std::string genderInput;
        while (gender == RescueAnimal::Gender::Unknown) {
            std::cout << "Enter animal Gender (Male or Female): ";
            std::getline(std::cin, genderInput);
            for (char& c : genderInput) {
                c = static_cast<char>(tolower(c));
            }
            if (genderInput == "male" || genderInput == "m") {
                gender = RescueAnimal::Gender::Male;
            }
            else if (genderInput == "female" || genderInput == "f") {
                gender = RescueAnimal::Gender::Female;
            }
            else {
                std::cout << "Invalid gender. Please enter either 'Male' or 'Female'.\n";
            }
        }

        std::cout << "Enter Animal age as a whole number (ex: 25): ";
        while (!(std::cin >> age) || age < 0) {
            std::cout << "Invalid input. Age must be a non-negative whole number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter Animal weight: ";
        while (!(std::cin >> weight) || weight <= 0) {
            std::cout << "Invalid input. Weight must be a positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter acquisition date (YYYY-MM-DD): ";
        std::getline(std::cin, acquisitionDate);
        while (acquisitionDate.empty()) {
            std::cout << "Acquisition date cannot be empty. Please enter a valid date: ";
            std::getline(std::cin, acquisitionDate);
        }

        std::cout << "Enter acquisition country: ";
        std::getline(std::cin, acquisitionCountry);
        while (acquisitionCountry.empty()) {
            std::cout << "Acquisition country cannot be empty. Please enter a valid country: ";
            std::getline(std::cin, acquisitionCountry);
        }

        std::cout << "Enter in service country: ";
        std::getline(std::cin, inServiceCountry);
        while (inServiceCountry.empty()) {
            std::cout << "In service country cannot be empty. Please enter a valid country: ";
            std::getline(std::cin, inServiceCountry);
        }

        int trainingStatusInput;
        std::cout << "Enter training status (0 for Not Trained, 1 for Trained, 2 for In Training): ";
        while (!(std::cin >> trainingStatusInput) || (trainingStatusInput < 0 || trainingStatusInput > 2)) {
            std::cout << "Invalid input. Please enter 0, 1, or 2: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (trainingStatusInput == 0) trainingStatus = RescueAnimal::TrainingStatus::NotTrained;
        else if (trainingStatusInput == 1) trainingStatus = RescueAnimal::TrainingStatus::Trained;
        else if (trainingStatusInput == 2) trainingStatus = RescueAnimal::TrainingStatus::InTraining;

        int isReservedInput;
        std::cout << "Is the animal reserved? (1 for Yes, 0 for No): ";
        while (!(std::cin >> isReservedInput) || (isReservedInput != 0 && isReservedInput != 1)) {
            std::cout << "Invalid input. Please enter 0 or 1: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        isReserved = (isReservedInput == 1);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Intake new dog logic
        if (animalMenuType == 1) {
            std::cout << "Enter dog breed: ";
            std::getline(std::cin, breed);
            while (breed.empty()) {
                std::cout << "Breed cannot be empty. Please enter a valid breed: ";
                std::getline(std::cin, breed);
            }

            Dog newDog;
            newDog.setAnimalID(animalID);
            newDog.setName(name);
            newDog.setAnimalType(RescueAnimal::AnimalType::Dog);
            newDog.setGender(gender);
            newDog.setAge(age);
            newDog.setWeight(weight);
            newDog.setAcquisitionDate(acquisitionDate);
            newDog.setAcquisitionCountry(acquisitionCountry);
            newDog.setInServiceCountry(inServiceCountry);
            newDog.setTrainingStatus(trainingStatus);
            newDog.setBreed(breed);
            newDog.setIsReserved(isReserved);

            bst->insertDog(newDog);
            std::cout << "Dog with ID " << animalID << " added successfully.\n";
        }
        // Intake new monkey logic
        else if (animalMenuType == 2) {
            std::string speciesInput;
            while (species == Monkey::Species::Unknown) {
                std::cout << "Enter monkey species (Capuchin, Guenon, Macaque, Marmoset, Squirrel Monkey, Tamarin): ";
                std::getline(std::cin, speciesInput);
                for (char& c : speciesInput) {
                    c = static_cast<char>(tolower(c));
                }

                if (speciesInput == "capuchin") species = Monkey::Species::Capuchin;
                else if (speciesInput == "guenon") species = Monkey::Species::Guenon;
                else if (speciesInput == "macaque") species = Monkey::Species::Macaque;
                else if (speciesInput == "marmoset") species = Monkey::Species::Marmoset;
                else if (speciesInput == "squirrel monkey") species = Monkey::Species::SquirrelMonkey;
                else if (speciesInput == "tamarin") species = Monkey::Species::Tamarin;
                else {
                    std::cout << "Invalid species. Please enter a valid monkey species from the list.\n";
                }
            }

            std::cout << "Enter tail length in inches: ";
            while (!(std::cin >> tailLengthInches) || tailLengthInches < 0) {
                std::cout << "Invalid input. Please enter a non-negative number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter body length in inches: ";
            while (!(std::cin >> bodyLengthInches) || bodyLengthInches < 0) {
                std::cout << "Invalid input. Please enter a non-negative number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter height in inches: ";
            while (!(std::cin >> heightInches) || heightInches < 0) {
                std::cout << "Invalid input. Please enter a non-negative number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            Monkey newMonkey;
            newMonkey.setAnimalID(animalID);
            newMonkey.setName(name);
            newMonkey.setAnimalType(RescueAnimal::AnimalType::Monkey);
            newMonkey.setGender(gender);
            newMonkey.setAge(age);
            newMonkey.setWeight(weight);
            newMonkey.setAcquisitionDate(acquisitionDate);
            newMonkey.setAcquisitionCountry(acquisitionCountry);
            newMonkey.setInServiceCountry(inServiceCountry);
            newMonkey.setTrainingStatus(trainingStatus);
            newMonkey.setTailLengthInches(tailLengthInches);
            newMonkey.setBodyLengthInches(bodyLengthInches);
            newMonkey.setHeightInches(heightInches);
            newMonkey.setSpecies(species);
            newMonkey.setIsReserved(isReserved);

            bst->insertMonkey(newMonkey);
            std::cout << "Monkey with ID " << animalID << " added successfully.\n";
        }
        else {
            std::cout << "Invalid animal type selected for intake." << std::endl;
        }
    }

    std::string generateAnimalID(const std::string& name) {
        int randomNumber = rand() % 10000;
        std::string idPrefix = name.substr(0, std::min((size_t)3, name.length())); // Take up to 3 chars, or less if name is shorter
        return idPrefix + std::to_string(randomNumber);
    }

    void reserveAnimal() {
        std::string animalIDToReserve;
        std::cout << "\nEnter the animal ID to reserve: ";
        std::getline(std::cin, animalIDToReserve);

        RescueAnimal* animalToReserve = bst->search(animalIDToReserve);

        if (animalToReserve == nullptr) {
            std::cout << "Animal with ID " << animalIDToReserve << " not found.\n";
            return;
        }

        if (!animalToReserve->getIsReserved()) {
            animalToReserve->setIsReserved(true);
            std::cout << "Animal with ID " << animalIDToReserve << " has been reserved.\n";
        }
        else {
            std::cout << "Animal with ID " << animalIDToReserve << " is already reserved.\n";
        }
    }
};


// Global main function
int main() {
    std::cout << "Welcome to the Rescue Animal Service!\n";
    std::cout << "Initializing service...\n";

    RescueAnimalService service; // Create an instance of the service
    service.menu(); // Call the menu method on the instance


    return 0;
}
