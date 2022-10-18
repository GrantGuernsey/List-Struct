#include <iostream>
#include "List.h"
#include "Storage.h"

/*EVERYTHING IS PASSED BY VALUE FOR SIMPLICITY*/

int main(){
	bool looper = true;
	List<storage> list;
	while(looper){
		cout << "Pick member function" << endl;
		cout << "1. Add item" << endl;
		cout << "2. Get item" << endl;
		cout << "3. Is in list" << endl;
		cout << "4. Is empty" << endl;
		cout << "5. Size" << endl;
		cout << "6. See next item" << endl;
		cout << "7. See previous item" << endl;
		cout << "8. See item at" << endl;
		cout << "9. Reset" << endl;
		cout << "10. Destructor" << endl;
		cout << "11. Visualization" << endl;
    cout << "Enter a value 1-11: ";
    
		int option, SKU, quantity;
    double cost;
    string description, unitOfMeasure;
    
		cin >> option;
		if(option > 11 || option < 1){
			cout << "Please enter a correct value." << endl;
			continue;
    }

    switch(option){
			case 1: {
        cout << "Enter the SKU of the item you would like to enter: ";
        cin >> SKU;
        cout << "Enter a description of the item: ";
				cin.ignore();
        getline(cin, description);
        cout << "Enter the cost of the item: ";
        cin >> cost;
        cout << "Enter your unit of measurement: ";
				cin.ignore();
        getline(cin, unitOfMeasure);
        cout << "Enter the quantity of your item: ";
        cin >> quantity;
        storage item = storage(SKU, description, cost, unitOfMeasure, quantity);
        list.addItem(item);
        cout << endl;
				break;
				}
      
			case 2:{
				cout << "Enter the SKU of the item you would like to retreive:" << endl;
				int searchValue;
				cin >> searchValue;
				storage searcher(searchValue);
				storage *found;
				found = list.getItem(searcher);
				if(found == nullptr){
					cout << "An item with this SKU value was not found." << endl;
				}
				else{
					cout << endl << *found << endl;
        }
      	break;
			}
      
			case 3:{
				cout << "Enter the SKU of the item you want to find in the list: ";
				int skut;
				cin >> skut;
				storage inList(skut);
				bool isThere = list.isInList(inList);
				if(isThere){
					cout << "The item is in the list" << endl;
				}
				else{
					cout << "The item is not in the list" << endl;
				}
				break;
      }
      
			case 4:{
        bool val = list.isEmpty();
        if (val){
          cout << "Your list is empty!" << endl << endl;
        }
        else{
          cout << "Your list has values in it" << endl << endl;
        }
				break;
			}
			case 5:{
				cout << "The size of your list is: "<< list.size() << endl << endl;
				break;
			}
			case 6:{
				storage* s = list.seeNext();
				if(s == nullptr){
					cout << "nullptr" << endl;	
				}
				else{
					cout << *s << endl;
				}
				break;
			}
			case 7:{
				storage* s = list.seePrev();
				if(s == nullptr){
					cout << "nullptr" << endl;	
				}
				else{
					cout << *s << endl;
				}
				break;
			}
			case 8:{
				cout << "Enter the desired index: ";
				int indx;
				cin >> indx;
				storage* s = list.seeAt(indx);
				cout << *s;
				break;
			}
			case 9: {
				list.reset();
        cout << "Reset successful" << endl;				
				break;
      }
			case 10: {
				looper = false;
				break;
      }
			case 11: {
				list.display();
				break;
      } 
		}
	}
}

