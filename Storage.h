using namespace std;
#include <iostream>;

class storage{
private:
	int sku;
	string description;
	double price;
	string uom;
	int quantityOnHand;
	int leadTime;

public:
	storage(){
		sku = 0;
	};
	storage(int SKU){
		sku = SKU;
	};
	storage(int SKU, string descrip, double cost, string unitOfMeasure, int quant = 0){
		sku = SKU;
		description = descrip;
		price = cost;
		uom = unitOfMeasure;
		quantityOnHand = quant;
		leadTime = 0;
	}

  string GetPartInfo(){
    string returnString = to_string(sku) + ": " + description; 
    return (returnString);
  }

	double GetPrice(){
		return price;
	}

	bool inStock(){
		return quantityOnHand > 0;
	}

	bool Avaliable(int date){
		if (inStock()){
      return true; 
    }
    else{
      if (date > leadTime){
        return true;
      }
      else{
        return false;
      }
    }
	}

	bool operator<(const storage& s){
		return sku < s.sku;
	}
	bool operator>(const storage& s){
		return sku > s.sku;
	}
	bool operator==(const storage& s){
		return sku == s.sku;
	}
	bool operator!=(const storage& s){
		return sku != s.sku;
	}
	friend ostream& operator<<(ostream& os, const storage& s)
	{
    os << "SKU: " << s.sku << endl << "Description: " << s.description << endl << "Price: " << s.price << endl << 
			"Quantity on hand: " << s.quantityOnHand << endl;
    return os;
	}
};