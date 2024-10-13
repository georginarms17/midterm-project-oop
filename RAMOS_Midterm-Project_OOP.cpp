#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

const int max_items = 100;                                                                   //Maximum products per Category

//Pure Virtual Functions, Base Class
class Inventory {
    public:
        virtual void addItem() = 0;
        virtual void updateItem() = 0;
        virtual void removeItem() = 0;
        virtual void byCategory() = 0;
        virtual void displayAll() = 0;
        virtual void searchItem() = 0;
        virtual void sortItem() = 0;
        virtual void displayLow() = 0;

    string toUpperCase(string str) {                                                        //To convert the input to uppercase letters
        for (int i = 0; i < str.length(); i++) {
            str[i] = toupper(str[i]);
        }
        return str;
    }
};

//Class for Validation Functions
class Validation {
    public:
        bool isValidLetters (const string &input) {
            for (char c : input) {
                if (!isalpha(c) && c != ' ') {
                    return false;
                }
            }
            return true;
        }

        bool isAlphaNumeric (const string &input) {
            bool hasLetter = false;
            bool hasDigit = false;

            for (char c : input) {
                if (isalnum(c)) {
                    if (isalpha(c)) hasLetter = true;
                    if (isdigit(c)) hasDigit = true;
                }
                else {
                    return false;
                }
            }
            return hasLetter && hasDigit;
        }

        bool isValidIntNum (const string &input) {
            for (int c : input) {
                if (!isdigit(c) && c != ' ' && c != '.') {
                    return false;
                }
            }
            return true;
        }

        bool isValidDoubleNum (const string &input) {
            for (double c : input) {
                if (!isdigit(c) && c != ' ' && c != '.') {
                    return false;
                }
            }
            return true;
        }
};

//Class for Inventory implementation
class MenuOpe : public Inventory {
    private:
        struct Product {                                                                    //Product Details
            string category;
            string prodID;
            string prodName;
            int prodQty;
            double prodPrice;
    
            //Constructors to set value for each product details
            Product() : category(""), prodID(""), prodName(""), prodQty(0), prodPrice(0.0) {}
            Product(string pCategory, string pID, string pName, int pQty, double pPrice) : category(pCategory), prodID(pID), prodName(pName), prodQty(pQty), prodPrice(pPrice) {}  

            //To display the products in the inventory
            void displayProd() const {
                cout << left << setw(20) << category 
                     << left << setw(20) << prodID 
                     << left << setw(20) << prodName 
                     << right << setw(10) << prodQty 
                     << right << setw(15) << fixed << setprecision(2) << prodPrice << endl; 
            }
        };

        Product products[max_items];                                                        //Array to hold the added products
        int currentSize;                                                                    //Variable to hold the number of added products

        bool getProdID(string& prodID) const {                                              //Function to search for the Product ID
            for (int i = 0; i < currentSize; i++) {
                if (products[i].prodID == prodID) {
                    cout << "Product " << products[i].prodName << " (" << products[i].prodID << ") found.\n\n";
                    return true;
                }
            }
            return false;
        }

        //Sorting Ascending (Bubble Sort)
        void sortAscending(string choice, Product products[], int currentSize) {
            if (choice == "1") {                                                            //Sort by Quantity (ascending)              
                cout << "\n=============================== ASCENDING BY QUANTITY ===============================\n";
                for (int i = 0; i < currentSize - 1; i++) {
                    for (int j = 0; j < currentSize - i - 1; j++) {
                        if (products[j].prodQty > products[j + 1].prodQty) {
                            Product temp = products[j];
                            products[j] = products[j + 1];
                            products[j + 1] = temp;
                        }
                    }
                }
            }
            else if (choice == "2") {                                                       //Sort by Price (ascending)
                cout << "\n================================= ASCENDING BY PRICE =================================\n";
                for (int i = 0; i < currentSize - 1; i++) {
                    for (int j = 0; j < currentSize - i - 1; j++) {
                        if (products[j].prodPrice > products[j + 1].prodPrice) {
                            Product temp = products[j];
                            products[j] = products[j + 1];
                            products[j + 1] = temp;
                        }
                    }
                }
            }
            else {
                cout << "Invalid input. Kindly input numbers 1 (quantity) and 2 (price).\n\n";
                return;
            }

            cout << left << setw(20) << "CATEGORY" << left << setw(20) << "PRODUCT ID" << left << setw(20) << "NAME" << right << setw(10) << "QUANTITY" << right << setw(15) << "PRICE" << endl;
            for (int i = 0; i < currentSize; i++) {
                products[i].displayProd();
            }
        }

        //Sorting Descending (Bubble Sort)
        void sortDescending(string choice, Product products[], int currentSize) {
            if (choice == "1") {                                                            //Sort by Quantity (descending)
                cout << "\n=============================== DESCENDING BY QUANTITY ===============================\n";
                for (int i = 0; i < currentSize - 1; i++) {
                    for (int j = 0; j < currentSize - i - 1; j++) {
                        if (products[j].prodQty < products[j + 1].prodQty) {
                            Product temp = products[j];
                            products[j] = products[j + 1];
                            products[j + 1] = temp;
                        }
                    }
                }
            }
            else if (choice == "2") {                                                       //Sort by Price (descending)
                cout << "\n================================ DESCENDING BY PRICE ================================\n";
                for (int i = 0; i < currentSize - 1; i++) {
                    for (int j = 0; j < currentSize - i - 1; j++) {
                        if (products[j].prodPrice < products[j + 1].prodPrice) {
                            Product temp = products[j];
                            products[j] = products[j + 1];
                            products[j + 1] = temp;
                        }
                    }
                }
            }
            else {
                cout << "Invalid input. Kindly input numbers 1 (quantity) and 2 (price).\n\n";
                return;
            }

            cout << left << setw(20) << "CATEGORY" << left << setw(20) << "PRODUCT ID" << left << setw(20) << "NAME" << right << setw(10) << "QUANTITY" << right << setw(15) << "PRICE" << endl;
            for (int i = 0; i < currentSize; i++) {
                products[i].displayProd();
            }
        }
    
    public:
        MenuOpe() : currentSize(0) {}                                                       //Constructor to initialize the current size to 0
        Validation valid;                                                                   //Object for Validation class      

        void addItem() override {
            char tryAgain;
            
            do {
                if (currentSize >= max_items) {
                    cout << "Inventory full! Unable to add more items.\n";
                    cout << "Returning to the Inventory Menu...\n";
                    system("pause");
                    system("cls");
                    return;
                }

                string category, prodID, prodName;
                string prodQtyInput, prodPriceInput;
                int prodQty;
                double prodPrice;
                bool prodFound = false;
                
                cout << "=================================== ADD ===================================\n";
                cout << "Kindly choose a category and input the needed information for the product.\n";
                cout << "   - Clothing\n" 
                     << "   - Electronics\n"
                     << "   - Entertainment\n\n";
                do {                                                                        //To ask for the category and validate if the input are letters
                    cout << "Category: ";
                        if (cin.peek() == '\n') {
                            cin.ignore();
                        }
                    getline(cin, category);
                        
                    if (category.empty()) {
                        cout << "The CATEGORY should not be empty.\n\n";
                        continue;
                    }
                    
                    if (!valid.isValidLetters(category)) {
                        cout << "Only letters are allowed as an input. Kindly retry.\n\n";
                        continue;
                    }
                    
                    category = toUpperCase(category);                                       //Convert the input to uppercase letters

                    if (category == "CLOTHING" || category == "ELECTRONICS" || category == "ENTERTAINMENT") {
                        do {
                            cout << "Product ID: ";                                         //To ask for the product ID and validate if it contains letters and numbers
                            getline(cin, prodID);
                            prodID = toUpperCase(prodID);                                   //Convert the input to uppercase letters

                            if (!valid.isAlphaNumeric(prodID)) {
                                cout << "The Product ID should contain letters and numbers and there should be no spaces and should not be empty. Kindly retry.\n\n";
                            }
                            else if (valid.isAlphaNumeric(prodID)) {
                                prodFound = getProdID(prodID);

                                if (prodFound) {
                                    cout << "Kindly input another PRODUCT ID as there exists a product of the SAME product ID.\n\n";
                                }
                                else if (!prodFound) {
                                    break;
                                }
                            }
                        } while (true);

                        do {                                                                //To ask for the product name and validate if the input are letters
                            cout << "Name: ";
                            getline(cin, prodName);
                            prodName = toUpperCase(prodName);
                                
                            if (prodName.empty()) {
                                cout << "The PRODUCT NAME cannot be empty.\n\n";
                            }
                            else if (!valid.isValidLetters(prodName)) {                          
                                cout << "Only letters are allowed as an input. Kindly retry.\n\n";
                            }
                        } while (prodName.empty() || !valid.isValidLetters(prodName));
                                
                        do {                                                                //To ask for the product quantity and validate if the input are numbers
                            cout << "Quantity: ";
                            cin >> prodQtyInput;
                                    
                            if (valid.isValidIntNum(prodQtyInput)) {
                                prodQty = stoi(prodQtyInput);                               //To convert string to int
                                    
                                if (prodQty <= 0) {
                                    cout << "The QUANTITY of the product cannot be less than or equal to 0.\n\n";
                                }
                            }
                            else {
                                cout << "Only numbers are allowed as an input. Kindly retry.\n\n";      
                            }
                        } while (!valid.isValidIntNum(prodQtyInput) || prodQty <= 0);
                                    
                        do {                                                                //To ask for the product price and validate if the input are numbers
                            cout << "Price: ";
                            cin >> prodPriceInput;
                                    
                            if (valid.isValidDoubleNum(prodPriceInput)) {
                                prodPrice = stod(prodPriceInput);                           //To convert string to double
                                        
                                if (prodPrice <= 0.0) {
                                    cout << "The PRICE of the product cannot be less than or equal to 0.\n\n";
                                }
                            }
                            else {
                                cout << "Only numbers are allowed as an input. Kindly retry.\n\n";
                            }
                        } while (!valid.isValidDoubleNum(prodPriceInput) || prodPrice <= 0.0);

                        products[currentSize] = Product(category, prodID, prodName, prodQty, prodPrice);    //To add into the array of products
                        currentSize++;                                                                      //Update the size of the array
                        cout << "\nItem added successfully!\n\n";
                        cout << "=============== DETAILS ===============\n";
                        cout << "Category: " << category << endl
                             << "Product ID: " << prodID << endl
                             << "Name: " << prodName << endl
                             << "Quantity: " << prodQty << endl
                             << "Price: " << fixed << setprecision(2) << prodPrice << endl << endl;
                        break;
                        }
                    else {
                        cout << "Category " << category << " does not exist.\n\n";
                    }
                } while (true);
            
                do {                                                                        //To ask if user wants to add another item
                    cout << "Would you like to add another product? (Y/N): ";
                    cin >> tryAgain;
                    tryAgain = toupper(tryAgain);
                    cout << endl;

                    if (tryAgain != 'Y' && tryAgain != 'N') {
                        cout << "Invalid input. Kindly input 'Y' (YES) or 'N' (NO).\n\n";
                    }
                } while (tryAgain != 'Y' && tryAgain != 'N');
            } while (tryAgain == 'Y');

            cout << "Returning to the Inventory Menu...\n";
            system("pause");
            system("cls");
        }

        void updateItem() override {
            char tryAgain;
            
            do {
                if (currentSize == 0) {
                    cout << "There are no items in the inventory.\n\n";
                    cout << "Returning to the Inventory Menu...\n";
                    system("pause");
                    system("cls");
                    return;
                }

                string prodID, choice;
                bool prodFound = false;

                cout << "=============== UPDATE ===============\n";
                cout << "Kindly input the needed information.\n\n";
                do {
                    cout << "Product ID: ";                                                 //To ask for the product ID and validate if it contains letters and numbers
                        if (cin.peek() == '\n') {
                            cin.ignore();
                        }
                    getline(cin, prodID);
                    prodID = toUpperCase(prodID);                                           //Convert the input to uppercase letters

                    if (prodID.empty()) {
                        cout << "The PRODUCT ID should not be empty.\n\n";
                    }
                    else if (!valid.isAlphaNumeric(prodID)) {
                        cout << "The Product ID should contain letters and numbers adn there should be no spaces.\n\n";
                    }
                    else if (valid.isAlphaNumeric(prodID)) {
                        prodFound = getProdID(prodID);

                        if (!prodFound) {
                            cout << "Product not found. Kindly retry.\n\n";
                        }
                        else {
                            break;
                        }
                    }
                } while (true);

                cout << "Field to update:" << endl;
                cout << "   1 - Quantity" << endl
                     << "   2 - Price" << endl << endl;
                do {
                    cout << "Choice: ";
                    cin >> choice;
                    
                    if (valid.isValidIntNum(choice)) {
                        if (choice == "1") {                                                //For updating the product's quantity
                            int prodQty, prevQty;
                            string newQty;

                            for (int i = 0; i < currentSize; i++) {                         //To hold the previous value and display later
                                if (products[i].prodID == prodID) {
                                    prevQty = products[i].prodQty;
                                }
                            }

                            do {                                                            //To ask for the product quantity and validate if the input are numbers
                                cout << "New Quantity: ";
                                cin >> newQty;
                                
                                if (valid.isValidIntNum(newQty)) {
                                    prodQty = stoi(newQty);                                 //To convert string to int
                                    
                                    if (prodQty <= 0) {
                                        cout << "The QUANTITY of the product cannot be less than or equal to 0.\n\n";
                                    }
                                }
                                else {
                                    cout << "Only numbers are allowed as an input. Kindly retry.\n\n";      
                                }
                            } while (!valid.isValidIntNum(newQty) || prodQty <= 0);

                            for (int i = 0; i < currentSize; i++) {
                                if (products[i].prodID == prodID) {
                                    products[i].prodQty = prodQty;
                                    cout << "\n======== UPDATED PRODUCT INFORMATION ========" << endl;            //To display the updated product information
                                    cout << "Product ID: " << products[i].prodID << endl;
                                    cout << "Product Name: " << products[i].prodName << endl;
                                    cout << "Quantity: " << prevQty << " ---> " << prodQty << endl << endl;
                                }
                            }
                            break;
                        }
                        else if (choice == "2") {                                           //For updating the product's price
                            double prodPrice, prevPrice;
                            string newPrice;
                            
                            for (int i = 0; i < currentSize; i++) {                         //To hold the previous value and display later
                                if (products[i].prodID == prodID) {
                                    prevPrice = products[i].prodPrice;
                                }
                            }

                            do {                                                            //To ask for the product price and validate if the input are numbers
                                cout << "New Price: ";
                                cin >> newPrice;
                                
                                if (valid.isValidDoubleNum(newPrice)) {
                                    prodPrice = stod(newPrice);                             //To convert string to double
                                    
                                    if (prodPrice <= 0) {
                                        cout << "The PRICE of the product cannot be less than or equal to 0.\n\n";
                                    }
                                }
                                else {
                                    cout << "Only numbers are allowed as an input. Kindly retry.\n\n";      
                                }
                            } while (!valid.isValidDoubleNum(newPrice) || prodPrice <= 0);

                            for (int i = 0; i < currentSize; i++) {
                                if (products[i].prodID == prodID) {
                                    products[i].prodPrice = prodPrice;
                                    cout << "\n======== UPDATED PRODUCT INFORMATION ========" << endl;            //To display the updated product information
                                    cout << "Product ID: " << products[i].prodID << endl;
                                    cout << "Product Name: " << products[i].prodName << endl;
                                    cout << "Price: " << fixed << setprecision(2) << prevPrice << " ---> " 
                                                      << fixed << setprecision(2) << prodPrice << endl << endl;
                                }
                            }
                            break;
                        }
                        else {
                            cout << "Invalid input. Kindly input numbers 1 (quantity) and 2 (price).\n\n";
                        }
                    }
                    else {
                        cout << "Only numbers are allowed as an input. Kindly retry.\n\n";
                    }
                } while (!valid.isValidIntNum(choice) || choice != "1" || choice != "2");
                
                do {
                    cout << "Would you like to update another product? (Y/N): ";
                    cin >> tryAgain;
                    tryAgain = toupper(tryAgain);
                    cout << endl;

                    if (tryAgain != 'Y' && tryAgain != 'N') {
                        cout << "Invalid input. Kindly input 'Y' (YES) or 'N' (NO).\n\n";
                    }
                } while (tryAgain != 'Y' && tryAgain != 'N');
            } while (tryAgain == 'Y');

            cout << "Returning to the Inventory Menu...\n";
            system("pause");
            system("cls");
        }

        void removeItem() override {
            char tryAgain;
            
            do {
                if (currentSize == 0) {                                                     //To display when there are no added products in the inventory
                    cout << "There are no items in the inventory.\n\n";
                    cout << "Returning to the Inventory Menu...\n";
                    system("pause");
                    system("cls");
                    return;
                }

                string prodID;
                bool prodFound = false;
                int prodIndex = -1;

                cout << "=============== REMOVE ===============\n";
                cout << "Kindly input the needed information.\n\n";
                do {
                    cout << "Product ID: ";                                                 //To ask for the product ID and validate if it contains letters and numbers
                        if (cin.peek() == '\n') {
                            cin.ignore();
                        }
                    getline(cin, prodID);
                    prodID = toUpperCase(prodID);                                           //Convert the input to uppercase letters

                    if (prodID.empty()) {
                        cout << "The PRODUCT ID should not be empty.\n\n";
                    }
                    else if (!valid.isAlphaNumeric(prodID)) {
                        cout << "The Product ID should contain letters and numbers and there should be no spaces.\n\n";
                    }
                    else if (valid.isAlphaNumeric(prodID)) {
                        for (int i = 0; i < currentSize; i++) {
                            if (products[i].prodID == prodID) {
                                prodIndex = i;
                                prodFound = true;
                                cout << "Product " << products[i].prodName << " is found and will be removed from the inventory.\n\n";
                                break;
                            }
                        }

                        if (!prodFound) {
                            cout << "Product not found. Kindly retry.\n\n";
                        }
                        else {
                            break;
                        }
                    }
                } while (true);

                if (prodIndex != -1) {
                    for (int i = prodIndex; i < currentSize - 1; i++) {                         //To shift the remaining products to the left 
                        products[i] = products[i + 1];
                    }
                    products[currentSize - 1] = Product();                                      //To reset the last element
                    currentSize--;

                    cout << "Product has been removed from the inventory!.\n\n";
                }

                do {
                    cout << "Would you like to remove another product? (Y/N): ";
                    cin >> tryAgain;
                    tryAgain = toupper(tryAgain);
                    cout << endl;

                    if (tryAgain != 'Y' && tryAgain != 'N') {
                        cout << "Invalid input. Kindly input 'Y' (YES) or 'N' (NO).\n\n";
                    }
                } while (tryAgain != 'Y' && tryAgain != 'N');
            } while (tryAgain == 'Y');

            cout << "Returning to the Inventory Menu...\n";
            system("pause");
            system("cls");
        }

        void byCategory() override {
            char tryAgain;

            do {
                if (currentSize == 0) {
                    cout << "There are no items in the inventory.\n\n";                         //To display when there are no added products in the inventory
                    cout << "Returning to the Inventory Menu...\n";
                    system("pause");
                    system("cls");
                    return;
                }

                string category;
                bool prodFound = false;

                cout << "=============== BY CATEGORY ===============\n";
                cout << "Categories:\n"
                    << "   - Clothing\n"
                    << "   - Electronics\n"
                    << "   - Entertainment\n\n"; 
                do {                                                                            //To ask for the category and validate if the input are letters
                    cout << "Category of Choice: ";
                        if (cin.peek() == '\n') {
                            cin.ignore();
                        }
                    cin >> category;

                    if (!valid.isValidLetters(category)) {
                        cout << "Only letters are allowed as an input. Kindly retry.\n\n";
                    }
                    else {
                        category = toUpperCase(category);                                       //Convert the input to uppercase letters

                        for (int i = 0; i < currentSize; i++) {                                 //To check if category is found and if there are products
                            if (products[i].category == category) {
                                prodFound = true;
                                break;
                            }
                        }

                        if (!prodFound) {
                            cout << "Category " << category << " does not exist or there are no products within that category.\n\n";
                        }
                    }
                } while (category.empty() || !valid.isValidLetters(category) || (!prodFound));

                cout << endl;
                cout << left << setw(20) << "CATEGORY" << left << setw(20) << "PRODUCT ID" << left << setw(20) << "NAME" << right << setw(10) << "QUANTITY" << right << setw(15) << "PRICE" << endl;
                    for (int i = 0; i < currentSize; i++) {
                        if (products[i].category == category) {
                            products[i].displayProd();
                            prodFound = true;
                        }
                    }

                do {
                    cout << "\nWould you like to display products by categories again? (Y/N): ";
                    cin >> tryAgain;
                    tryAgain = toupper(tryAgain);
                    cout << endl;

                    if (tryAgain != 'Y' && tryAgain != 'N') {
                        cout << "Invalid input. Kindly input 'Y' (YES) or 'N' (NO).\n\n";
                    }
                } while (tryAgain != 'Y' && tryAgain != 'N');
            } while (tryAgain == 'Y');

            cout << "\nReturning to the Inventory Menu...\n";
            system("pause");
            system("cls");
        }

        void displayAll() override {
            if (currentSize == 0) {
                cout << "There are no items in the inventory.\n\n";                             //To display when there are no added products in the inventory
                cout << "Returning to the Inventory Menu...\n";
                system("pause");
                system("cls");
                return;
            }
            
            cout << "======================================= ITEMS =======================================\n";
            cout << left << setw(20) << "CATEGORY" << left << setw(20) << "PRODUCT ID" << left << setw(20) << "NAME" << right << setw(10) << "QUANTITY" << right << setw(15) << "PRICE" << endl;
                for (int i = 0; i < currentSize; i++) {
                    products[i].displayProd();
                }
            
            cout << "\nReturning to the Inventory Menu...\n";
            system("pause");
            system("cls");
        }

        void searchItem() override {
            char tryAgain;
            
            do {
                if (currentSize == 0) {
                    cout << "There are no items in the inventory.\n\n";                        //To display when there are no added products in the inventory
                    cout << "Returning to the Inventory Menu...\n";
                    system("pause");
                    system("cls");
                    return;
                }
                
                string prodID;
                bool prodFound = false;

                cout << "=============== SEARCH ===============\n";
                cout << "Kindly input the needed information.\n\n";
                do {
                    cout << "Product ID: ";                                                    //To ask for the product ID and validate if it contains letters and numbers
                        if (cin.peek() == '\n') {
                            cin.ignore();
                        }
                    getline(cin, prodID);
                    prodID = toUpperCase(prodID);                                              //Convert the input to uppercase letters

                    if (prodID.empty()) {
                        cout << "The PRODUCT ID should not be empty.\n\n"; 
                    }
                    else if (!valid.isAlphaNumeric(prodID)) {
                        cout << "The Product ID should contain letters and numbers and there should be no spaces.\n\n";
                    }
                    else if (valid.isAlphaNumeric(prodID)) {
                        prodFound = getProdID(prodID);

                        if (!prodFound) {
                            cout << "Product not found. Kindly retry.\n\n";
                        }
                        else {
                            break;
                        }
                    }
                } while (true);

                cout << left << setw(20) << "CATEGORY" << left << setw(20) << "PRODUCT ID" << left << setw(20) << "NAME" << right << setw(10) << "QUANTITY" << right << setw(15) << "PRICE" << endl;
                for (int i = 0; i < currentSize; i++) {
                    if (products[i].prodID == prodID) {
                        products[i].displayProd();
                        prodFound = true;
                    }
                }
                
                do {                                                                            //To ask if user wants to search another product
                    cout << "\nWould you like to search another product? (Y/N): ";
                    cin >> tryAgain;
                    tryAgain = toupper(tryAgain);
                    cout << endl;

                    if (tryAgain != 'Y' && tryAgain != 'N') {
                        cout << "Invalid input. Kindly input 'Y' (YES) or 'N' (NO).\n\n";
                    }
                } while (tryAgain != 'Y' && tryAgain != 'N');
            } while (tryAgain == 'Y');

            cout << "\nReturning to the Inventory Menu...\n";
            system("pause");
            system("cls");
        }

        void sortItem() override {
            char tryAgain;
            
            do {
                if (currentSize == 0) {                                                         //To display when there are no added products in the inventory
                    cout << "There are no products in the inventory.\n\n";
                    cout << "Returning to the Inventory Menu...\n";
                    system("pause");
                    system("cls");
                    return;
                }
                
                string choice, order;
                bool validChoice = false, validOrder = false;
                
                cout << "=============== SORT ===============\n";
                cout << "Kindly input the needed information.\n\n";
                cout << "Sort by:" << endl
                    << "   1 - Quantity" << endl
                    << "   2 - Price" << endl;
                do {
                    cout << "Choice: ";                                                         //To ask whether to sort by quantity or price
                    cin >> choice;
                    
                    if (valid.isValidIntNum(choice)) {
                        if (choice == "1" || choice == "2") {
                            validChoice = true;
                        }
                        else {
                            cout << "Invalid input. Kindly input numbers 1 (quantity) and 2 (price).\n\n";
                        }
                    }
                    else {
                        cout << "Only numbers are allowed as an input. Kindly retry.\n\n";
                    }
                } while (!validChoice);
                
                cout << "\nOrder: " << endl
                    << "   1 - Ascending" << endl
                    << "   2 - Descending" << endl;
                do {    
                    cout << "Order: ";                                                          //To ask what the order of sorting
                    cin >> order;

                    if (valid.isValidIntNum(order)) {
                        if (order == "1") {                                                     //To sort the products in ascending order
                            sortAscending(choice, products, currentSize);
                            validOrder = true;
                        }
                        else if (order == "2") {                                                //To sort the products in descending order
                            sortDescending(choice, products, currentSize);
                            validOrder = true;
                        }
                        else {
                            cout << "Invalid input. Kindly input numbers 1 (ascending) and 2 (descending).\n\n";
                        }
                    }
                    else {
                        cout << "Only numbers are allowed as an input. Kindly retry.\n\n";
                    }
                } while (!validOrder);

                do {                                                                            //To ask if user wants to sort the products again
                    cout << "\nWould you like to sort the products again? (Y/N): ";
                    cin >> tryAgain;
                    tryAgain = toupper(tryAgain);
                    cout << endl;

                    if (tryAgain != 'Y' && tryAgain != 'N') {
                        cout << "Invalid input. Kindly input 'Y' (YES) or 'N' (NO).\n\n";
                    }
                } while (tryAgain != 'Y' && tryAgain != 'N');
            } while (tryAgain == 'Y');

            cout << "\nReturning to the Inventory Menu...\n";
            system("pause");
            system("cls");
        }

        void displayLow() override {
            if (currentSize == 0) {
                cout << "There are no items in the inventory.\n\n";                             //To display when there are no added products in the inventory
                cout << "Returning to the Inventory Menu...\n";
                system("pause");
                system("cls");
                return;
            }
            
            cout << "================================== LOW STOCK ITEMS ==================================\n";
            bool prodFound = false;

            cout << left << setw(20) << "CATEGORY" << left << setw(20) << "PRODUCT ID" << left << setw(20) << "NAME" << right << setw(10) << "QUANTITY" << right << setw(15) << "PRICE" << endl;           
            for (int i = 0; i < currentSize; i++) {
                if (products[i].prodQty <= 5) {
                    products[i].displayProd();
                    prodFound = true;
                }
            }

            if (!prodFound) {
                cout << "\nThere are no low stock items.\n\n";
            }
            
            cout << "\nReturning to the Inventory Menu...\n";
            system("pause");
            system("cls");
        }
};

int main () {
    MenuOpe menu;
    int choice;

    do {
        cout << "=============== INVENTORY ===============\n";
        cout << "1 - Add Item\n"
             << "2 - Update Item\n"
             << "3 - Remove Item\n"
             << "4 - Display by Category\n"
             << "5 - Display All Items\n"
             << "6 - Search Item\n"
             << "7 - Sort Items\n"
             << "8 - Display Low Stock Items\n"
             << "9 - Exit\n\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {                                                                 //Validation if the input is a number 
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Kindly enter numbers 1 to 9 only.\n\n";
            system("pause");
            system("cls");
            continue;
        }
        system("cls");

        switch (choice) {
            case 1: 
                menu.addItem();
                break;
                            
            case 2: 
                menu.updateItem();
                break;
            
            case 3: 
                menu.removeItem();
                break;            

            case 4: 
                menu.byCategory();
                break;            
                        
            case 5: 
                menu.displayAll();
                break;
            
            case 6: 
                menu.searchItem();
                break;
            
            case 7: 
                menu.sortItem();
                break;
            
            case 8: 
                menu.displayLow();
                break;
            
            case 9:
                cout << "Thank you!\n\nExiting from the inventory system...\n";
                break;
                            
            default: 
                cout << "Invalid input. Kindly enter numbers 1 to 9 only.\n\n";
                cout << "Returning to the Inventory Menu...\n";
                system("pause");
                system("cls");
        }
    } while (choice != 9);
    
    return 0;
}