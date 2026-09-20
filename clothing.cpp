#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Base class for Clothing Items
class ClothingItem {
protected:
    int itemNumber;
    string itemName;
    double price;
    string category;

public:
    // Default constructor
    ClothingItem()
        : itemNumber(0), itemName(""), price(0), category("") {}

    // Parameterized constructor
    ClothingItem(int num, string name, double p, string cat)
        : itemNumber(num), itemName(name), price(p), category(cat) {}

    // Virtual destructor
    virtual ~ClothingItem() {}

    // Getter functions
    int getItemNumber() const {
        return itemNumber;
    }

    string getItemName() const {
        return itemName;
    }

    double getPrice() const {
        return price;
    }

    string getCategory() const {
        return category;
    }

    // Display item
    virtual void display() const {
        cout << itemNumber << ". " << itemName
             << " - Rs. " << price << endl;
    }

    // Pure virtual function
    virtual string getType() const = 0;
};


// Derived class for Men's Clothing
class MensClothing : public ClothingItem {
public:

    MensClothing() : ClothingItem() {}

    MensClothing(int num, string name, double p)
        : ClothingItem(num, name, p, "Men's") {}

    string getType() const override {
        return "Men's Clothing";
    }
};


// Derived class for Women's Clothing
class WomensClothing : public ClothingItem {
public:

    WomensClothing() : ClothingItem() {}

    WomensClothing(int num, string name, double p)
        : ClothingItem(num, name, p, "Women's") {}

    string getType() const override {
        return "Women's Clothing";
    }
};


// Derived class for Children's Clothing
class ChildrensClothing : public ClothingItem {
public:

    ChildrensClothing() : ClothingItem() {}

    ChildrensClothing(int num, string name, double p)
        : ClothingItem(num, name, p, "Children's") {}

    string getType() const override {
        return "Children's Clothing";
    }
};


// Bill Item class
class BillItem {
public:
    int itemNumber;
    string itemName;
    int quantity;
    double price;
    double totalPrice;

    // Default constructor
    BillItem()
        : itemNumber(0), itemName(""), quantity(0),
          price(0), totalPrice(0) {}

    // Parameterized constructor
    BillItem(int num, string name, int qty, double p)
        : itemNumber(num), itemName(name),
          quantity(qty), price(p) {

        totalPrice = price * quantity;
    }
};


// Main Clothing Store class
class ClothingStore {
private:

    ClothingItem* mensItems[20];
    ClothingItem* womensItems[20];
    ClothingItem* childrensItems[20];

    BillItem billItems[50];

    int mensCount;
    int womensCount;
    int childrensCount;
    int billCount;

    double GST_RATE;

public:

    // Constructor
    ClothingStore() {

        mensCount = 0;
        womensCount = 0;
        childrensCount = 0;
        billCount = 0;

        GST_RATE = 0.05; // 5% GST

        initializeProducts();
    }


    // Destructor
    ~ClothingStore() {

        for (int i = 0; i < mensCount; i++) {
            delete mensItems[i];
        }

        for (int i = 0; i < womensCount; i++) {
            delete womensItems[i];
        }

        for (int i = 0; i < childrensCount; i++) {
            delete childrensItems[i];
        }
    }


    // Initialize sample/demo products
    void initializeProducts() {

        // Men's clothing
        mensItems[0] =
            new MensClothing(101, "T-Shirt", 800);

        mensItems[1] =
            new MensClothing(105, "Hoodie", 1600);

        mensCount = 2;


        // Women's clothing
        womensItems[0] =
            new WomensClothing(201, "Saree", 1200);

        womensItems[1] =
            new WomensClothing(205, "Jumpsuit", 1900);

        womensCount = 2;


        // Children's clothing
        childrensItems[0] =
            new ChildrensClothing(301, "T-Shirt", 600);

        childrensItems[1] =
            new ChildrensClothing(305, "Raincoat", 950);

        childrensCount = 2;
    }


    // Display Men's Clothing
    void displayMensClothing() {

        cout << endl;
        cout << "========== MEN'S CLOTHING =========="
             << endl;

        for (int i = 0; i < mensCount; i++) {
            mensItems[i]->display();
        }
    }


    // Display Women's Clothing
    void displayWomensClothing() {

        cout << endl;
        cout << "========== WOMEN'S CLOTHING =========="
             << endl;

        for (int i = 0; i < womensCount; i++) {
            womensItems[i]->display();
        }
    }


    // Display Children's Clothing
    void displayChildrensClothing() {

        cout << endl;
        cout << "========== CHILDREN'S CLOTHING =========="
             << endl;

        for (int i = 0; i < childrensCount; i++) {
            childrensItems[i]->display();
        }
    }


    // Add item to bill
    bool addItemToBill(int itemNum, int quantity) {

        if (quantity <= 0) {

            cout << "Invalid quantity!" << endl;
            return false;
        }

        if (billCount >= 50) {

            cout << "Bill is full! Please generate or clear the current bill."
                 << endl;

            return false;
        }


        // Search Men's items
        for (int i = 0; i < mensCount; i++) {

            if (mensItems[i]->getItemNumber() == itemNum) {

                billItems[billCount] =
                    BillItem(
                        itemNum,
                        mensItems[i]->getItemName(),
                        quantity,
                        mensItems[i]->getPrice()
                    );

                billCount++;

                cout << "Item added successfully!" << endl;

                return true;
            }
        }


        // Search Women's items
        for (int i = 0; i < womensCount; i++) {

            if (womensItems[i]->getItemNumber() == itemNum) {

                billItems[billCount] =
                    BillItem(
                        itemNum,
                        womensItems[i]->getItemName(),
                        quantity,
                        womensItems[i]->getPrice()
                    );

                billCount++;

                cout << "Item added successfully!" << endl;

                return true;
            }
        }


        // Search Children's items
        for (int i = 0; i < childrensCount; i++) {

            if (childrensItems[i]->getItemNumber() == itemNum) {

                billItems[billCount] =
                    BillItem(
                        itemNum,
                        childrensItems[i]->getItemName(),
                        quantity,
                        childrensItems[i]->getPrice()
                    );

                billCount++;

                cout << "Item added successfully!" << endl;

                return true;
            }
        }


        cout << "Item not found!" << endl;

        return false;
    }


    // Display current bill
    void displayCurrentBill() {

        if (billCount == 0) {

            cout << endl;
            cout << "No items in bill yet!" << endl;

            return;
        }


        cout << endl;
        cout << "========== CURRENT BILL =========="
             << endl;

        cout << "Item Name                 Qty     Price"
             << endl;

        cout << "--------------------------------------------"
             << endl;


        for (int i = 0; i < billCount; i++) {

            cout << billItems[i].itemName;

            for (int j = billItems[i].itemName.length();
                 j < 27; j++) {

                cout << " ";
            }

            cout << billItems[i].quantity;

            for (int j = 1; j < 9; j++) {
                cout << " ";
            }

            cout << billItems[i].price << endl;
        }
    }


    // Generate bill
    void generateBill() {

        if (billCount == 0) {

            cout << endl;
            cout << "No items in bill!" << endl;

            return;
        }


        double subtotal = 0;


        // -------------------------------
        // FILE HANDLING
        // Create/Open bill.txt
        // -------------------------------

        ofstream file("bill.txt");


        if (!file) {

            cout << "Error opening bill.txt!" << endl;

            return;
        }


        // Bill heading on screen
        cout << endl;

        cout << "-----------------------------------------------------------"
             << endl;

        cout << "                  CLOTHING STORE - BILL"
             << endl;

        cout << "-----------------------------------------------------------"
             << endl;

        cout << "Item Name                 Qty     Price        Total"
             << endl;

        cout << "-----------------------------------------------------------"
             << endl;


        // Bill heading in file
        file << "-----------------------------------------------------------"
             << endl;

        file << "                  CLOTHING STORE - BILL"
             << endl;

        file << "-----------------------------------------------------------"
             << endl;

        file << "Item Name                 Qty     Price        Total"
             << endl;

        file << "-----------------------------------------------------------"
             << endl;


        // Display and save items
        for (int i = 0; i < billCount; i++) {

            // Display on screen
            cout << billItems[i].itemName;

            for (int j = billItems[i].itemName.length();
                 j < 27; j++) {

                cout << " ";
            }

            cout << billItems[i].quantity;

            for (int j = 1; j < 9; j++) {
                cout << " ";
            }

            cout << billItems[i].price;

            for (int j = 0; j < 12; j++) {
                cout << " ";
            }

            cout << billItems[i].totalPrice
                 << endl;


            // Save item in file
            file << billItems[i].itemName
                 << "    "
                 << billItems[i].quantity
                 << "    "
                 << billItems[i].price
                 << "    "
                 << billItems[i].totalPrice
                 << endl;


            // Calculate subtotal
            subtotal += billItems[i].totalPrice;
        }


        // Calculate GST
        double gst = subtotal * GST_RATE;

        // Calculate final total
        double total = subtotal + gst;


        // Display totals on screen
        cout << "-----------------------------------------------------------"
             << endl;

        cout << "                       Subtotal: Rs. "
             << subtotal << endl;

        cout << "                       GST (5%): Rs. "
             << gst << endl;

        cout << "-----------------------------------------------------------"
             << endl;

        cout << "                       Total: Rs. "
             << total << endl;

        cout << "-----------------------------------------------------------"
             << endl;

        cout << endl;
        cout << "            Thank You! Visit Again."
             << endl << endl;


        // Save totals to file
        file << "-----------------------------------------------------------"
             << endl;

        file << "Subtotal: Rs. "
             << subtotal << endl;

        file << "GST (5%): Rs. "
             << gst << endl;

        file << "Total: Rs. "
             << total << endl;

        file << "-----------------------------------------------------------"
             << endl;

        file << "Thank You! Visit Again."
             << endl;


        // Close the file
        file.close();


        cout << "Bill has been saved to bill.txt"
             << endl;
    }


    // Clear bill
    void clearBill() {

        billCount = 0;

        cout << "Bill cleared!" << endl;
    }


    // Display menu
    void displayMenu() {

        cout << endl;

        cout << "========== CLOTHING STORE MENU =========="
             << endl;

        cout << "1. View Men's Clothing" << endl;

        cout << "2. View Women's Clothing" << endl;

        cout << "3. View Children's Clothing" << endl;

        cout << "4. Add Item to Bill" << endl;

        cout << "5. View Current Bill" << endl;

        cout << "6. Generate Bill" << endl;

        cout << "7. Clear Bill" << endl;

        cout << "8. Exit" << endl;

        cout << "========================================"
             << endl;

        cout << "Enter your choice: ";
    }


    // Run the store
    void run() {

        int choice;

        cout << "\n*** Welcome to Clothing Store ***"
             << endl;


        while (true) {

            displayMenu();

            cin >> choice;


            // Check invalid input
            if (cin.fail()) {

                cin.clear();

                cin.ignore(10000, '\n');

                cout << "Invalid input! Please enter a number."
                     << endl;

                continue;
            }


            switch (choice) {

                case 1:

                    displayMensClothing();

                    break;


                case 2:

                    displayWomensClothing();

                    break;


                case 3:

                    displayChildrensClothing();

                    break;


                case 4: {

                    int itemNum;
                    int qty;

                    cout << endl;
                    cout << "Enter Item Number: ";

                    cin >> itemNum;

                    cout << "Enter Quantity: ";

                    cin >> qty;

                    addItemToBill(itemNum, qty);

                    break;
                }


                case 5:

                    displayCurrentBill();

                    break;


                case 6:

                    generateBill();

                    break;


                case 7:

                    clearBill();

                    break;


                case 8:

                    cout << endl;
                    cout << "Thank you for shopping! Goodbye!"
                         << endl;

                    return;


                default:

                    cout << "Invalid choice! Please try again."
                         << endl;
            }
        }
    }
};


// Main function
int main() {

    ClothingStore store;

    store.run();

    return 0;
}