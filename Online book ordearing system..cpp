# include <iostream>											                                       															
# include <fstream>
# include <string>
# include <sstream>
# include <conio.h>																										
# include <iomanip> 
# include <ctime> 

using namespace std;

const int Max_Items = 100;  
struct item{
	string name;
	float price;
	int quantity;
};


struct Nethra{
	std :: string b_name;
	int quantity;
	std :: string b_price;
};

struct BookItems{                                                                          
	string name;
	float price;
	int quantity;	
};

void login();
void dis_Menu();
void a_Infor();

void Menu();
void sub_Menu();
void print_Menu();
void print();

void addItem();
void updateItem();
void viewItem(); 
void searchItem();
void displayItem(); 	

void bill();
void print_Bill(); 	

string username = "";
string password = "";
bool isLoggedIn = false;

const double  Discount_RATE = 0.08;


int main (){
	int shop;  
	
   

	cout<<"*******************************WELCOME To NETHRA BOOK SHOP***********************************"<<endl;                                                  
	cout<<"Enter 1 for Login "<<endl;
	cout<<"Enter 2 for Menu  "<<endl;                                                    
	cout<<"Enter 3 for Contact the shop "<<endl;
	cout<<"Enter 4 for Exit "<<endl;
	cout<<"SELECT YOUR OPTION :";  
    cin>>shop;
    switch (shop)
	{
		case 1:
			login();
			break;
		case 2:
			dis_Menu();
			break;
		case 3:
			a_Infor();
			break;	
		case 4 :
				cout << " ************Are you sure, you want to Exit??? ***************** "<< endl;
			break;
		default :
		system("cls");
			while(true){
    				int log;
    				cout<<" Enter 1 to return Login page : ";
    				cin>> log;
    				if(log == 1);
    				system("cls");
    				main();
    				break;
    }
			
	} 
	  
}
void login(){
		while(true){
			
		        cout <<"ENTER USERNAME HERE: "<<endl;
                cin >> username; 
                cout <<"ENTER PASSWORD HERE: "<<endl;  
                cin>>password;
  			    char k;   
	 
       	while ((k= _getch())!= '\r')
       	{
	       	password += k;
	       	cout<<'*';
       	}
	
		
		if(username == "NethEbook" && password == "20153") {
			
        	system("cls");
        
            cout<<"****************** Login is successfull!!. ********************" << endl;
            username = username;
            password = password;
            isLoggedIn = true;
            void Menu();
            sub_Menu();
    			break;       
        }else{
        	
        	cout<<"**INVALID USERNAME AND PASSWORD>......** "<<endl;
        	username = username;
            password = password;
            isLoggedIn = false ;
			login();	
        }
    }
}

void dis_Menu(){
	system("cls");
	const int Max_Items = 100;
    Nethra Book [Max_Items];
    int numitem = 0;

    std::ifstream inFile("items.txt"); 

    if (!inFile) {
        std::cout << "ERROR OPENING FILE.\n";
    }
    std::string line;
    
    while (getline(inFile, line)) {
        std::istringstream one(line);
        one >> Book[numitem].b_name >> Book[numitem].b_price>> Book[numitem].quantity;
        numitem++;
    }
    inFile.close();

    cout << "*****************************SEE TODAY BOOK DETAILS IN NETHRA  BOOk SHOP************************** "<<endl;
    cout << "\n\t\t\t\t\t\t      Book NAME               Book  PRICE                   Book QUANTITY  "<<endl;
      
    for (int i = 0; i < numitem; i++) {
        std::cout << "\n\t\t\t\t\t\t\t" << Book[i].b_name<<"\t\t      "<< Book[i].b_price<<"\t\t\t    "<<Book[i].quantity<< "\n";
       
    }
    
    while(true){
    	int section;
    	cout<<" Enter 1 to return Login menu : ";
    	cin>> section;
    	if(section == 1);
    	system("cls");
    	main();
    	break;
    }

}	

void a_Infor(){
	        
       system("cls");   
     
      cout<<"********************************** Nethra Book shop  details ***********************************"<<endl;
	  cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
	  cout<<"**************        ADDRESS                     HOURS                     CALL US                    "<<endl;
	  cout<<"                      181/1A,                   Every Day                       0760084321             "<<endl; 
	  cout<<"                      Maha veediya road,         8.30 a.m - 5.30 p.m            0912277773             "<<endl;
	  cout<<"                      Kandy.                    poya day                                               "<<endl;
	  cout<<"                                                 Closed.                                               "<<endl;
	
	  while(true){
    	int details ;
    	cout<<" Enter 1 for return Login menu : ";
    	cin>> details;
    	if(details == 1);
    	system("cls");
    	main();
    	break;
    }
}

void sub_Menu(){                                                                                                                                
	
    system ("cls");
	int choice;
    
	                                                  
	cout<<"  1.ADD BOOK ITEM  "<<endl;
	cout<<"  2.UPDATE BOOK ITEM  "<<endl;                                                                                                                       
	cout<<"  3.DISPLAY BOOK ITEM  "<<endl;
	cout<<"  4.SEARCH BOOK ITEM  "<<endl;
	cout<<"  5.PRINT BILL "<<endl;
	cout<<" Please Select Your  Option :"; 
	cin>>choice;
	switch(choice){
		    case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                displayItem();
                break;
            case 4:
            	searchItem();
            	break;
           	case 5:
            	print_Bill();
           	case 6:
      	     	cout << " EXITING PROGRAM...\n";
                break;
            default:
            	
                cout << " INVALID CHOICE.PLEASE TRY AGIN\n";
                break; 
        }
     while (choice != 5);
     
}
item items[Max_Items];
int numItems = 0;
void addItem(){
	item newItem; 
	cout <<" ENTER BOOK ITEM NAME HERE  :: ";
    cin >> newItem.name; 
    cout <<"ENTER BOOK ITEM PRICE HERE  :: ";
    cin>>newItem.price;
    cout <<"ENTER BOOK ITEM QUANTITY HERE  :: ";
    cin >> newItem.quantity;                
 
   		         bool found = false;
                   for (int i = 0; i < numItems; i++) {
                        if (items[i].name == newItem.name) {
                  found = true;
                  items[i].price = newItem.price;
                   break;
      }
    }
    			if (!found) {
     			 items[numItems] = newItem;
     			 numItems++;
   }
   				 ofstream fout("items.txt", ios::app);
    				fout << newItem.name << " " << newItem.price << " " << newItem.quantity << endl;
    				fout.close();
 		        cout <<"******************ITEM ADDED SUCCESSFULLY ! ************************** "<<endl;
 		        
        while(true){
    	          int add ;
    	          cout<<" Enter 2 for return submenu : ";
                  cin>> add;
                	if(add == 2);
                	system("cls");
                	sub_Menu();
                 	break;
    }
 		        
}


void updateItem(){
	
string name;

    bool found = false;
    cout <<"ENTER BOOK ITEM NAME : "<<endl;
    cin >> name;
    for (int i = 0; i < numItems; i++) {
        if (items[i].name == name) {
            cout <<"ENTER  BOOK ITEM PRICE : "<<endl;
            cin >> items[i].price;
            cout <<"ENTER  BOOK ITEM QUANTITY : "<<endl;
            cin >> items[i].quantity;
            found = true;
            ofstream fout("temp.txt");
            for (int j = 0; j < numItems; j++) {
                fout << items[j].name << " " << items[j].price << " " << items[j].quantity << endl;
            }
            fout.close();
            rename("temp.txt", "items.txt");
            cout <<"***********************************ITEM UPDATE SUCCESSFULLY ! ************************************"<<endl;
            while(true){
    	int update ;
    	cout<<" Enter 2 for return sub menu : ";
    	cin>> update;
    	if(update == 2);
    	system("cls");
    	sub_Menu();
    	break;
    }
            }
    }
    if (!found) {
        cout <<"******** ITEM NOT FOUND...... ********* "<<endl;
       while(true){
    	int update ;
    	cout<<" Enter 2 for return submenu : ";
    	cin>> update;
    	if(update == 2);
    	system("cls");
    	sub_Menu();
    	break;
    }
    }
}

void displayItem(){
	
	ifstream fin("items.txt");
    item displayedItem;
    cout << "              BOOK NAME              BOOK  PRICE                    BOOK QUANTITY  "<<endl;
    while (fin >> displayedItem.name >> displayedItem.price >> displayedItem.quantity) {
        cout<< "\n\t\t\t\t\t\t\t" << displayedItem.name<<"\t\t      "<< displayedItem.price<<"\t\t\t    "<<displayedItem.quantity<<endl;
    }
    fin.close();
    while(true){
    	int display;
    	cout<<" Enter 2 for return submenu : ";
    	cin>> display;
    	if(display == 2);
    	system("cls");
    	sub_Menu();
    	break;
    }  
 }
 
void searchItem(){
	
	string name;
    bool found = false;
    cout <<" ENTER ITEM NAME TO SEARCH : ";
    cin >> name;
    for (int i = 0; i < numItems; i++) {
        if (items[i].name == name) {
            found = true;
            cout<< "               BOOK NAME              BOOK  PRICE            BOOK QUANTITY  "<<endl;
            cout<<"\n\t\t\t\t\t\t\t"<<items[i].name <<"\t\t       "<<items[i].price <<"\t\t      "<< items[i].quantity << endl;
        }
    }
    if (!found) {
        cout <<"********* ITEM NOT FOUND.... ************* : "<<endl;
       
    }
     while(true){
    	int check;
    	cout<<" Enter 2 for return submenu : "<<endl;
    	cin>> check;
    	if(check == 2);
    	system("cls");
    	sub_Menu();
    	break;
    }  
}
	
void print_Bill(){
	
    int quantity;
    string b_name;
    double price,subtotal,discount,total;
    
    
    
    cout<<"Enter the book name :  "<<endl;
    cin>>  b_name;
    cout<<"Enter the quantity : "<<endl;
    cin>>quantity;
    cout<<"Enter the price of one  : "<<endl;
    cin>>price;
    
    
    
    subtotal = quantity * price;
    discount = subtotal * Discount_RATE;
    total = subtotal - discount;
    time_t now = time(0);
    char* dt = ctime(&now);
   
    


    cout << fixed<< setprecision(2);  
    cout << " ************* BILL **************" << endl;
    cout << "\t\t\tDate: " << dt << endl;
    cout << "\t\t\tQuantity : "  << quantity << endl;
    cout << "\t\t\tPrice per item   : RS" << price    << endl;
    cout << "\t\t\tSubtotal         : RS" << subtotal << endl;
    cout << "\t\t\tdiscount              : RS" << discount      << endl;
    cout << "\t\t\tTotal            : RS" << total    << endl;
    cout << "******************************************************" << endl;
    
}                           
