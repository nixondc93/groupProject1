#include <iostream>
using namespace std;

class Contact{
  public:
    string name = "";
    string address;
    string phoneNumber;
};

int linearSearch(Contact arr[], string value){
  int pos=0;
  int size = 100;
  bool isFound = false;



  while(!isFound && pos < size)
  {
    if(arr[pos].name == value){
      isFound= true;
    }
    pos++;
  }

  if(isFound){
    return pos - 1;
  }

  return -1;
}

void printContact(Contact contact){
  cout << "Name: " << contact.name << endl;
  cout << "Address: " << contact.address << endl;
  cout << "Phone number: " << contact.phoneNumber << endl;
  cout << endl;
}

void swap(int &x, int &y){
  x = x + y;
  y = x - y;
  x = x - y;
}

// TODO: Derry
void sortContacts(Contact arr[]){
  for(int i = 0; i < 100 - 1; ++i){
    int minValue = i;
    for(int j = i + 1; j < 100; ++j){
      if(arr[j].name > arr[minValue].name){
        minValue = j;
      }
    }
    swap(arr[i], arr[minValue]);
  }
}

//TODO: JOSE
void searchContacts(Contact arr[]){
  string value;
  cout << "Who do you want to search for?" << endl;
  cout << "Enter their name: ";
  cin >> value;

  int result = linearSearch(arr, value);

  if(result == -1){
    cout << "Contact not found";
  } else {
    printContact(arr[result]);
  }
}

//TODO: JOSE
void addContact(Contact arr[]){
  string name;
  string address;
  string phoneNumber;

  cout << "Enter Name" << endl;
  cin >> name;

  cout << "Enter Address" << endl;
  cin >> address;

  cout << "Enter Phone Number" << endl;
  cin >> phoneNumber;

  Contact a;
  a.name = name;
  a.address = address;
  a.phoneNumber = phoneNumber;


  for(int i = 0; i <= 100; i++){
    if(arr[i].name == ""){
      arr[i] = a;
      break;
    }
  }
  sortContacts(arr);
}

//TODO: Daniel
void updateContact(Contact arr[]){
  string name;
  cout << "Which Contact would you like to update." << endl;
  cout << "Enter their name: ";
  cin >> name;

  int result = linearSearch(arr, name);

  if(result == -1){
    cout << "Contact not found";
  }else{
    string name, address, phone;
    cout << "Enter new info for this contact";
    cout << "Name: ";
    cin >> name;
    cout << "Address: ";
    cin >> address;
    cout << "Phone number: ";
    cin >> phone;
    arr[result].name = name;
    arr[result].address = address;
    arr[result].phoneNumber = phone;
  }
}

//TODO: Cheuk
void listAllContacts(Contact arr[]){

  for(int i = 0; i < 100; i++){
    if(arr[i].name == ""){
      break;
    }
    printContact(arr[i]);
  }
}

//TODO: Derry
void deleteContact(Contact arr[]){
  string contactName;
  cout << "Which contact would you like to delete? Enter their name." << endl;
  cin >> contactName;

  for(int i = 0; i < 100; i++){
    if(arr[i].name == contactName){
      Contact a;
      arr[i] = a;
    }
  }

}

//TODO: Derry
void menu(Contact contactList[]){
  int userChoice;
  cout << endl;
  cout << "Welcome to your contact list" << endl;
  cout << "What would you like to do?" << endl;
  cout << "Add a contact? (1)" << endl;
  cout << "Update a contact (2)" << endl;
  cout << "Delete Contact (3)" << endl;
  cout << "List all contacts (4)" << endl;
  cout << "Search contacts (5)" << endl;
  cout << "Quit Contact List (6)" << endl;
  cout << "Enter an option to continue" << endl;
  cin >> userChoice;
  cout << endl;

  switch(userChoice){
    case 1:
      addContact(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 2:
      updateContact(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 3:
      deleteContact(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 4:
      listAllContacts(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 5:
      searchContacts(contactList);
      sortContacts(contactList);
      menu(contactList);
      break;
    case 6:
      exit(0);
      break;
    default:
      cout << "Invalid Option. Enter a number 1 through 6." << endl;
      menu(contactList);
      break;
  }
}

int main() {
	Contact contactList[100];

  menu(contactList);
  return 0;
}
