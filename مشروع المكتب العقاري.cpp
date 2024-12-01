#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Property {
    int id;
    string location;
    string type;
    int price;  
    int area;   
    int floors; 
    bool isForSale;
    Property* next;
};

Property* head = NULL;

void welcome() {
	cout<<"          _____________________________________                            \n";
	cout<<"         /                                   /|                            \n";
	cout<<"        /                                   / |                            \n";
	cout<<"       /                                   /  |                            \n";
	cout<<"      /__________________________________ /   |                            \n";
	cout<<"     |-----------------------------------|    |                            \n";
	cout<<"     |                                   |    |                            \n";
	cout<<"     |\033[30m    WELCOME TO THE REAL ESTATE   \033[33m  |   /|            \n";
	cout<<"     |\033[30m        AL-IBDA'A OFFICE       \033[33m    |  / |            \n";
	cout<<"     |                                   | /  |                            \n";
    cout<<"     |___________________________________|/   |                            \n";
    cout<<"     |-----------------------------------|    |                            \n";
    cout<<"     | _____    _______   _____    _____ |    | \033[92m^                  \n";
    cout<<"\033[92m ^^^\033[33m | |[ ]|    |  |  |   |[ ]|    |[ ]| |   /\033[92m ^*^ \n";
    cout<<"\033[92m^^^*\033[33m |          |  |  |                  |  /\033[92m ^^^^ \n";
    cout<<"\033[92m  ^^\033[33m |_ _ _ _ _ | .|. |_ _ _ _ _ _ _ _ _ | /\033[92m^^* ^^ \n";
    cout<<"\033[92m ^*^*\033[33m|_|_|_|_|_||__|__|_|_|_|_|_|_|_|_|_||/ \033[92m ^ ^^^ \n";
    cout<<"\033[92m ^*^^^^*^^^^^^ ^^^^*^^ ^^ ^^^^^  ^^^*^^*^^^^*^^ ^^\033[92m         \n";
    cout<<"\033[92m ^^* ^^^^^*^^^^ *^^^^^^ ^^^^^*^^^ *^^^*^^^^^ ^^^ \033[92m          \n";
   
}

void checknumber(int &input) {
	
	while(true)
	{cin>>input;
	if(cin.fail())
	{
	 cout <<"\033[33m The wrong entry . please enter number \n  \033[31m";
	 cin.clear();
	 cin.ignore(numeric_limits<streamsize>::max(),'\n'); }
	 
	else
	break;
	}
}

bool employeeLogin() {
    string password;
    int attempts = 3;

    while (attempts > 0) {
        cout << "\033[36m\n Enter the password : \033[31m";
        cin >> password;
        if (password == "12345") {
            cout << "\033[36m Logged in successfully .\n";
            return true;
        }
        attempts--;
        cout << "\033[36m The password is incorrect .you have " << attempts << " attempts remaining .\n";
    }
    cout << "\033[36m We apologize .you cannot proceed as an employee.\n";
    return false;
}

void addProperty(bool forSale) {
    Property* newProperty = new Property();
    int id = 1;
    Property* temp = head;

    while (temp != NULL) {
        id = temp->id + 1;
        temp = temp->next;
    }
    newProperty->id = id;
    
    cout << "\033[36m Enter the property location: \033[31m ";
    cin >> newProperty->location;
    cout << "\033[36m Enter the property type ( building / villa ): \033[31m ";
    cin >> newProperty->type;
    cout << "\033[36m Enter the property price in saudi riyals : \033[31m ";
    cin >> newProperty->price;
    int length, width;
    cout << "\033[36m Enter the property length in meters : \033[31m ";
    cin >> length;
    cout << "\033[36m Enter the property width in meters : \033[31m ";
    cin >> width;
    newProperty->area = length * width;
    cout << "\033[36m Enter the number of floors : \033[31m ";
    cin >> newProperty->floors;
    
    newProperty->isForSale = forSale;
    newProperty->next = NULL;

         if (head == NULL) {
        head = newProperty;}
		 else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProperty;  }
        cout << "\033[36m \n The property has been added successfully .\n";
}

void editProperty() {
    int id;
    cout << "\033[36m Enter the property number to edit : \033[31m  ";
    checknumber(id);

    Property* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "\033[36m What would you like to edit :\n 1. the location \n 2. the price \n 3. the area \n \033[31m";
            int choice;
           checknumber(choice);

            if (choice == 1) {
                cout << "\033[36m Enter the new location : \033[31m";
                cin >> temp->location; }
				 
			else if (choice == 2) {
                cout << "\033[36m Enter the new price : \033[31m";
                cin >> temp->price; } 
                
			else if (choice == 3) {
                int length, width;
                cout << "\033[36m Enter the new lengith in meters : \033[31m";
                cin >> length;
                cout << "\033[36m Enter the new width in meters : \033[31m";
                cin >> width;
                temp->area = length * width; }
					 
			else 
           { cout << "\033[36m Invalid option .\n";
             continue;
		   }
            
            cout << "\033[36m The property has been successfully updated .\n";
            return;
        }
        temp = temp->next;
    }
    cout << "\033[36m The property does not exist .\n";
}

 void deleteProperty() {
    int id;
    cout << "\033[36m Enter the property number to delete : \033[31m ";
    checknumber(id);

    Property* temp = head;
    Property* prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL) 
            head = temp->next; 
			else 
            prev->next = temp->next;
              
            delete temp;
            cout << "\033[36m The operation was successfuly.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
		 }		 
    cout << "\033[36m The property does not exist .\n";
}

void purchaseOrRent(){
	int id  , phone;
    checknumber(id);
    char name [ 100 ];
    char location [ 100 ];
    char password [ 100 ];
    Property* temp = head;
    Property* prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL) 
            head = temp->next;
            else 
            prev->next = temp->next;
             
             cout << "\033[32m Enter your data to confirm the reservation of the property .\n    name : \033[31m ";
             cin.ignore(); 
             gets ( name );
             cout << "\033[32m    password : \033[31m ";
             gets ( password ) ;
             cout <<"\033[32m    location : \033[31m ";
             gets ( location );
             cout <<"\033[32m    phone : \033[31m ";
             cin >>phone ;
             
            delete temp;
            cout << "\033[32m \n The operation was successfuly . Employee phone to connect whith him (747509183) \n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\033[32m The property does not exist .\n";
}

 void displayclient() {
 	
    Property* temp = head;
    while (temp != NULL) 
	{      cout << "\033[107m \033[32mThe Property number: " << temp->id << ", The location : " << temp->location
                << ", The type: " << temp->type << ", The price: " << temp->price
                << ", The area: " << temp->area << " square meter , The floors: " << temp->floors
                << ", The status: " << (temp->isForSale ? "for sale " : "for rent ") << endl;
            temp = temp->next;  }
    cout <<"\033[103m \033[32m \n 1. Approval of completion \n 2. Return \n\033[31m ";
    int a;
    checknumber(a);
    switch(a)
    {case 1:
    {     cout << "\033[32m Enter the property number : \033[31m ";
    	  purchaseOrRent() ;  }
   	 case 2:
	 break;
	 
	}
}

 void displayemployee() {
    Property* temp = head;
    
    while (temp != NULL) 
	{  cout << "\033[107m \033[34mTheProperty number: " << temp->id << ", The location : " << temp->location
            << ", The type: " << temp->type << ", The price: " << temp->price
            << ", The area: " << temp->area << " square meter , The floors: " << temp->floors
            << ", The status: " << (temp->isForSale ? "for sale " : "for rent ") << endl;
            temp = temp->next;  
    }
	}

 void seedData() {
    head = new Property{1, "Al-Mukalla", "house", 200000, 250, 1, true, NULL};
    head->next = new Property{2, "Ghayl-bawazir", "villa", 500000, 350, 2, true, NULL};
    head->next->next = new Property{3, "Al-Shihr", "house", 300000, 150, 1, true, NULL};
    head->next->next->next = new Property{4, "Al-Mukalla", "house", 2500, 120, 1, false, NULL};
    head->next->next->next->next = new Property{5, "Ghayl-bawazir", "villa ", 4000, 300, 2, false, NULL};
    head->next->next->next->next->next = new Property{6, "Ghayl-bawazir", "house", 2000, 180, 1, false, NULL};
   
 }

void mainMenu() {
    while (true) {
    	int f;
        cout << endl<< "\033[30m Are you a client or an employee ? \n";
        cout <<" (1) employee \n";
        cout <<" (2) client \n";
        cout <<" (3) Exit \033[31m\n   ";
	    int choice;
        checknumber(choice);
        if (choice == 1) {
            if (employeeLogin()) {
                while (true) {
                    cout << " \033[103m \033[36m\n Choose an option :\n 1. add property \n 2. edit property \n 3. delete property \n 4. display properties \n 5. Return \n  \033[31m";
                    int empchoice;
                    checknumber(empchoice);
                    
                    if (empchoice == 1) {
                      cout << "\033[36m Do you want to add to selling or rent ? \n  0. for rent \n  1. for sale \n  2. Return \n  \033[31m";
                      int subchoice;
                      checknumber(subchoice);
                      if( subchoice==0 || subchoice==1)
                      addProperty(subchoice == 1); 
                      else if(subchoice == 2)
                      continue;
					  else
					  {cout <<"\033[36m  incorrect sellection \n";
					   continue;  } 
					   }
                   
					 else if (empchoice == 2) 
					 editProperty(); 
                        
					 else if (empchoice == 3)
                     deleteProperty(); 
                      
                     else if (empchoice == 4)
				     displayemployee();
                      
					 else if (empchoice == 5) 
                     break; 

					 else 
					 cout << "\033[36m Incorrect selection.\n";
					   
                }
            }
        } else if (choice == 2) {
            while (true) {
                cout << "\033[32m\n Choose an option :\n 1. inquiry about property \n 2. Exit \n  \033[31m";
                int clientchoice;
                checknumber(clientchoice);

            if (clientchoice == 1) {
            displayclient();
            } 
			else if (clientchoice == 2) {
            break;
              } 
			else  
             cout << "\033[32m Incorrect selection.\n";
                
            }
           
        }
		 else if(choice ==3){	
         cout <<"\033[30m\n Thanks for using our application \n "; 
         break; }
        	
		else 
        cout << "\033[30m Incorrect selection.\n";
    }
}

int main() {
	
    seedData();
    system("color e6");
    welcome();
    mainMenu();
}