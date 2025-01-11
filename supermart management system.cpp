#include<iostream>
#include<conio.h>
using namespace std;
   //structures for all
struct Supplier{
	int id ;
	string name;
	string status;
};
struct Item{
	string name;
	int quantity;
};
struct Customer {
    int id;
    string name;
    string phonenumber;
    float totalPurchase;
};
struct Employee {
    int id;
    string name;
    string phonenumber;
    string position;
    float salary;
};

// Global Arrays and Variables
Supplier Suppliers[20];
Customer customers[70];
Employee employees[30];
Item Inventory[20];

int i=0;
void AddItem(){
	if(i<20){
		cout<<"Enter the name of the item you want to add :"<<endl;
	    cin.ignore() ;
		getline(cin,Inventory[i].name);
		cout<<"Enter the quantity of the items :"<<endl;
		cin>>Inventory[i].quantity;
		i++;
		cout<<"Item added successfully !"<<endl;
	}
	else{
		cout<<"Inventory is full can't add more items ";
	}
}
void EditItem(){
	string names ;
	cout<<"Enter the name of the item you want to edit :"<<endl;
	cin.ignore() ;
	getline(cin,names);
	for(int j=0;j<i;j++){
	    if(names == Inventory[j].name){
		    cout<<"Enter new name "<<endl;
	     	getline(cin,Inventory[j].name);
		    cout<<"Enter new quantity "<<endl;
		    cin>>Inventory[j].quantity;
	        return ;
        }    
	}
	cout<<"Item not found !"<<endl;
}
void SearchItem(){
	string names;
	cout<<"Enter the name of the item you want to search :"<<endl;
	cin.ignore();
	getline(cin,names);
	for(int j=0; j<i; j++){
	    if(names == Inventory[j].name){
		    cout<<"Item is found "<<endl;
		    cout<<"Name     :  "<<Inventory[j].name<<endl;
		    cout<<"Quantity :  "<<Inventory[j].quantity<<endl;
		    return ;
	    }
	}
	cout<<"Item not found !"<<endl;	
}
void DelItem(){
	string names;
	cout<<"Enter the name of the item you want to delete :"<<endl;
	cin.ignore();
	getline(cin ,names);
	for(int j=0; j<i; j++){
	    if(names == Inventory[j].name){
            for(int k=j; k<i-1; k++){
                Inventory[k] = Inventory[k+1];
	        }
	        i--;
	        cout<<"Item deleted "<<endl;
	        return ;
	   }
	}
	cout<<"Item not found !"<<endl;
}
void DisplayItem(){
	if (i == 0) {
        cout << "\nNo item added yet.\n";
        return;
    } 
	
	for(int j=0;j<i;j++){
	    cout<<"Name     :  "<< Inventory[j].name<<endl;
	    cout<<"Quantity :  "<< Inventory[j].quantity<<endl;
	}
}

//            Sale 
int x;
void add_sale(float sale_arr[]){
	cout<<"** Insert Record **\n\nEnter the new sales: $";
	cin>>sale_arr[x];
	x++;
}
void update_sale(float sale_arr[]){
	int n,new_value;
	cout<<"** Update Record **\n\nEnter the record you want to update: $";
	cin>>n;
	for(int y=0;y<x;y++){
		if(n==sale_arr[y]){
			cout<<"Record before updation: $"<<sale_arr[y]<<endl<<"Now update the record: $";
			cin>>new_value;
			sale_arr[y]=new_value;
			cout<<"\nRecord after updation: $"<<sale_arr[y]<<"\nRecord is successfully updated. "<<endl;
			return;
		}
	}
	cout<<"Record not found!!!"<<endl;
}
void search_sale(float sale_arr[]){
	int n;
	cout<<"** Search Record **\n\nEnter the data you want to search: $";
	cin>>n;
    for (int y=0;y<x;y++) {
        if (n==sale_arr[y]) {
            cout<<"\nThe record is present." << endl;
            return;
        }
    }
    cout << "Record not found!!!" << endl;
}
void del_sale(float sale_arr[]){
	int n;
	cout<<"** Delete Record **\n\nEnter the record you want to delete: $";
	cin>>n;
	for(int y=0;y<x;y++){
		if(n==sale_arr[y]){
			for(int z=y;z<x-1;z++){
				sale_arr[z]=sale_arr[z+1];
			}
			cout<<"Value deleted successfully...";
			x--;
			return ;
		}
    }
	cout<<"Record not found!!!"<<endl;
}
void show_sale(float sale_arr[]){
	cout<<"** Show Record **\n\nCurrent record "<<endl;
	for(int y=0;y<x;y++){
		cout<<"$"<<sale_arr[y]<<endl;
	}
}
void sales(float sale_arr[]){
	float sum=0;
	cout<<"** Total Sale **";
	for(int y=0;y<x;y++){
		sum+=sale_arr[y];
	}
	cout<<"\n\nTotal sale of the day is: $"<<sum;
}

//             PURCHASE
int a=0;
void add_pur(float purchase_arr[]){
	cout<<"** Insert Record **\n\nEnter the new purchase: $";
	cin>>purchase_arr[a];
	a++;
}
void update_pur(float purchase_arr[]){
	int n,new_value;
	cout<<"** Update Record **\n\nEnter the record you want to update: $";
	cin>>n;
	for(int b=0;b<a;b++){
		if(n==purchase_arr[b]){
			cout<<"Record before updation: $"<<purchase_arr[b]<<endl<<"Now update the record: $";
			cin>>new_value;
			purchase_arr[b]=new_value;
			cout<<"\nRecord after updation: $"<<purchase_arr[b]<<"\n!!Record is successfully updated!!"<<endl;
			return ;
		}
	}
	cout<<"Record not found!!!"<<endl;
}
void search_pur(float purchase_arr[]){
	int n;
	cout<<"** Search Record **\n\nEnter the record you want to search: $";
	cin>>n;
    for (int b=0;b<a;b++) {
        if (n==purchase_arr[b]) {
            cout<<"\nThe record is present." << endl;
            return ;
        }
    }
    cout << "Record not found!!!" << endl;
}
void del_pur(float purchase_arr[]){
	int n;
	cout<<"** Delete Record **\n\nEnter the record you want to delete: $";
	cin>>n;
	for(int b=0;b<a;b++){
		if(n==purchase_arr[b]){
			for(int c=b;c<a-1;c++){
				purchase_arr[c]=purchase_arr[c+1];
			}
			cout<<"Record deleted successfully...";
			a--;
			return;
		}
    }
	cout<<"Record not found!!!"<<endl;
}
void show_pur(float purchase_arr[]){
	cout<<"** Show Record **\n\nCurrent record "<<endl;
	for(int b=0;b<a;b++){
		cout<<"$"<<purchase_arr[b]<<endl;
	}
}
void total_pur(float purchase_arr[]){
	float sum=0;
	cout<<"** Total Purchase **";
	for(int b=0;b<a;b++){
		sum+=purchase_arr[b];
	}
	cout<<"\n\nTotal purchase of the day is: $"<<sum;
} 
//          Customer
int l=0;
void addCustomer() {
    cout << "\nEnter Customer ID: ";
    cin >> customers[l].id;
    cin.ignore();
    cout << "Enter Customer Name: ";
    getline(cin, customers[l].name);
    cout << "Enter Customer Phone number: ";
    getline(cin, customers[l].phonenumber);
    cout << "Enter Customer Purchase: ";
    cin >> customers[l].totalPurchase;
    l++;
    cout << "\nCustomer added successfully!\n";
}
void editCustomer() {
    int id;
    cout << "\nEnter Customer ID to edit: ";
    cin >> id;
    for (int m = 0; m < l; m++) {
        if (customers[m].id == id) {
            cin.ignore();
            cout << "Edit Customer Name: ";
            getline(cin, customers[m].name);
            cout << "Edit Customer Phone number: ";
            getline(cin, customers[m].phonenumber);
            cout << "Edit Customer Purchase: ";
            cin >> customers[m].totalPurchase;
            cout << "\nCustomer updated successfully!\n";
            return;
        }
    }
    cout << "\nCustomer not found!\n";
}
void deleteCustomer() {
    int id;
    cout << "\nEnter Customer ID to delete: ";
    cin >> id;
    for (int m = 0; m < l; m++) {
        if (customers[m].id == id) {
            for (int n = m; n < l - 1; n++) {
                customers[n] = customers[n + 1];
            }
            l--;
            cout << "\nCustomer deleted successfully!\n";
            return;
        }
    }
    cout << "\nCustomer not found!\n";
}
void searchCustomer() {
    int id;
    cout << "\nEnter Customer ID to search: ";
    cin >> id;
    for (int m = 0; m < l; m++) {
        if (customers[m].id == id) {
            cout << "\nCustomer Found:\n";
            cout << "Name: " << customers[m].name << "\n";
            cout << "Phone number: " << customers[m].phonenumber << "\n";
            cout << "Total Purchase: " << customers[m].totalPurchase << "\n";
            return;
        }
    }
    cout << "\nCustomer not found!\n";
}
void viewCustomers() {
    if (l == 0) {
        cout << "\nNo customers added yet.\n";
        return;
    }
    cout << "\nID\tName\t\t   Phone Number\t\tTotal Purchase\n";
    for (int m = 0; m < l; m++) {
        cout << customers[m].id << "\t" << customers[m].name << "\t   " 
             << customers[m].phonenumber << " \t\t$" << customers[m].totalPurchase << "\n";
    }
}
//           Employee
int o=0;
void addEmployee() {
    cout << "\nEnter Employee ID: ";
    cin >> employees[o].id;
    cin.ignore();
    cout << "Enter Employee Name: ";
    getline(cin, employees[o].name);
    cout << "Enter Employee Phone Number: ";
    getline(cin, employees[o].phonenumber);
    cout << "Enter Employee Position: ";
    getline(cin, employees[o].position);
    cout << "Enter Employee Salary: ";
    cin >> employees[o].salary;
    o++;
    cout << "\nEmployee added successfully!\n";
}
void editEmployee() {
    int id;
    cout << "\nEnter Employee ID to edit: ";
    cin >> id;
    for (int p = 0; p < o; p++) {
        if (employees[p].id == id) {
            cin.ignore();
            cout << "Edit Employee Name: ";
            getline(cin, employees[p].name);
            cout << "Edit Employee Phone Number: ";
            getline(cin, employees[p].phonenumber);
            cout << "Edit Employee Position: ";
            getline(cin, employees[p].position);
            cout << "Edit Employee Salary: ";
            cin >> employees[p].salary;
            cout << "\nEmployee updated successfully!\n";
            return;
        }
    }
    cout << "\nEmployee not found!\n";
}
void deleteEmployee() {
    int id;
    cout << "\nEnter Employee ID to delete: ";
    cin >> id;
    for (int p = 0; p < o; p++) {
        if (employees[p].id == id) {
            for (int q = p; q < o - 1; q++) {
                employees[q] = employees[q + 1];
            }
            o--;
            cout << "\nEmployee deleted successfully!\n";
            return;
        }
    }
    cout << "\nEmployee not found!\n";
}
void searchEmployee() {
    int id;
    cout << "\nEnter Employee ID to search: ";
    cin >> id;
    for (int p = 0; p < o; p++) {
        if (employees[p].id == id) {
            cout << "\nEmployee Found:\n\n";
            cout << "Name: " << employees[p].name << "\n";
            cout << "Phone Number: " << employees[p].phonenumber << "\n";
            cout << "Position: " << employees[p].position << "\n";
            cout << "Salary: " << employees[p].salary << "\n";
            return;
        }
    }
    cout << "\nEmployee not found!\n";
}

void viewEmployees() {
    if (o == 0) {
        cout << "\nNo employees added yet.\n";
        return;
    }
    cout << "\n ID\t   Name\t\t   Phone Number\t\t  Position \t\tSalary\n";
    for (int p = 0; p < o; p++) {
        cout <<" "<< employees[p].id << "\t" << employees[p].name << "\t    "
             << employees[p].phonenumber << "\t  " << employees[p].position << "  \t\t$"<< employees[p].salary << "\n";
    }
}
//        Supply Chain
int u=0;
void AddSupplier(){
	if(u<20){
		cout<<"Enter  supplier id :"<<endl;
	    cin>>Suppliers[u].id;
		cout<<"Enter supplier name :"<<endl;
	    cin.ignore() ;
		getline(cin,Suppliers[u].name);
		cout<<"Enter supplier status "<<endl;
		getline(cin,Suppliers[u].status);
		u++;
		cout<<"Supplier added successfully !"<<endl;
	}
	else{
		cout<<"Supplier list is full can't add more items ";
	}
}
void EditSupplier(){
	int id ;
	cout<<"Enter the id of the supplier you want to edit :"<<endl;
	cin>>id;
	for(int v=0; v<u; v++){
	    if(id == Suppliers[v].id){
		    cout<<"Enter new supplier name "<<endl;
		    cin.ignore();
	        getline(cin,Suppliers[v].name);
		    cout<<"Enter new supplier status "<<endl;
            getline(cin,Suppliers[v].status);
           	cout<<" Supplier updated successfully ";
            return;
        }
    }
    cout<<"Supplier not found ! "<<endl;
}
void SearchSupplier(){
	int id ;
	cout<<"Enter the id of the supplier to search :"<<endl;
	cin>>id;
	for(int v=0;v<u;v++){
	    if(id == Suppliers[v].id){
		    cout<<"Supplier found ! "<<endl;
		    cout<<"ID     :  "<<Suppliers[v].id<<endl;
		    cout<<"Name   :  "<<Suppliers[v].name<<endl;
		    cout<<"Status :  "<<Suppliers[v].status<<endl;
		    return;
	    }	
	}
	cout<<"Supplier not found ! "<<endl;
}
void DelSupplier(){
	int id ;
	cout<<"Enter the id of the supplier to delete :"<<endl;
	cin>>id;
	for(int v=0;v<u;v++){
	    if(id == Suppliers[v].id){
            for(int w=v; w<u-1; w++){
            Suppliers[w] = Suppliers[w+1];
	        }
	        u--;
            cout<<"Supplier deleted  "<<endl;
            return;
	    }
    }
    cout<<"Supplier not found ! "<<endl;
}
void DisplaySupplier(){
	    if (u == 0) {
        cout << "\nNo record added yet.\n";
        return;
    }	
	for(int v=0; v<u; v++){
	cout<<" \n";
	cout<<"Supplier Name   :"<<Suppliers[v].name<<endl;
	cout<<"Supplier Id     :"<<Suppliers[v].id<<endl;
	cout<<"Supplier Status :"<<Suppliers[v].status<<endl;
	}
	
}
 //main function
int main() {
    int choice, function_choice;
    float sale_arr[50], purchase_arr[50];
    while (true) {
        system("cls");    //for clear screen                                      
        cout<<"******** SUPER MART MANAGEMENT SYSTEM ********\n\n";
        cout<<" **** MENU **** \n";
        cout<<"1. Inventory Mangement\n";
		cout<<"2. Sales Mangement\n";
        cout<<"3. Purchases Mangement\n";
        cout<<"4. Customer Mangement\n";
        cout<<"5. Employee Mangement\n";
        cout<<"6. Supply Chain Mangement\n";
        cout<<"7. Exit\n";
        cout<<"------------------\n\n";

        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:  // Inventory management
                while (true) {
                    system("cls");
                    cout<<"*****   INVENTORY MANAGEMENT   *****\n\n";
                    cout<<"**** MENU **** \n";
                    cout<<"1. Add Record     "<<endl;
	                cout<<"2. Edit Record    "<<endl;
	                cout<<"3. Search Record  "<<endl;
	                cout<<"4. Delete Record  "<<endl;
	                cout<<"5. Display Record "<<endl;
	                cout<<"6. Go back to main menu "<<endl;
	                cout<<"------------------\n\n";
                    cout<<"Enter your choice: ";
                    cin>>function_choice;
                    switch(function_choice){
            
					    case 1:
			                AddItem();
		                    break;
					    case 2:
			                EditItem();
		                    break;
		                case 3:
		            	    SearchItem();
		                    break;
		                case 4:
			                DelItem();
		                    break;
					    case 5:
		                    DisplayItem();
		                    break;
		                case 6:
		                    break;
		                default :
		                    cout<<"Invalid Choice "<<endl;
	                }
	                if (function_choice == 6){
					    break;
                    }
	                cout<<"Press any key to continue "<<endl;
	                getch();    
	            }
                break; 
			
		    case 2:  // Sales Management
                while (true) {
                    system("cls");
                    cout<<"*****   SALES MANAGEMENT   *****\n\n";
                    cout<<"**** MENU ****\n";
                    cout<<"1. Insert Record\n";
                    cout<<"2. Update Record\n";
                    cout<<"3. Search Record\n";
                    cout<<"4. Delete Record\n";
                    cout<<"5. Show Record\n";
                    cout<<"6. Total Sales\n";
                    cout<<"7. Go Back to Main Menu\n";
                    cout<<"------------------\n\n";
                    cout<<"Enter your choice: ";
                    cin>>function_choice;
                    switch(function_choice) {
                    	
                        case 1: 
						    add_sale(sale_arr); 
							break;
						case 2: 
						    update_sale(sale_arr); 
							break;
						case 3: 
						    search_sale(sale_arr); 
							break;
						case 4: 
						    del_sale(sale_arr); 
						    break;
						case 5: 
						    show_sale(sale_arr); 
						    break;
						case 6: 
						    sales(sale_arr); 
							break;
						case 7: 
						    break;  // Go back to the main menu
						default: 
						    cout<<"Enter correct option.\n";
                    }
                    if (function_choice == 7){
					    break;
                    }  
					cout << "\nPress any key to continue....";
                    getch();
                }
                break;   
            
			case 3:  
                while (true) {
                    system("cls");
                    cout<<"*****   PURCHASE MANAGEMENT   *****\n\n";
                    cout<<"**** MENU ****\n";
                    cout<<"1. Insert Record\n";
                    cout<<"2. Update Record\n";
                    cout<<"3. Search Record\n";
                    cout<<"4. Delete Record\n";
                    cout<<"5. Show Record\n";
                    cout<<"6. Total Purchase\n";
                    cout<<"7. Go Back to Main Menu\n";
                    cout<<"------------------\n\n";
                    cout<<"Enter your choice: ";
                    cin>>function_choice;
                    switch(function_choice) {
                    	
                        case 1: 
						    add_pur(purchase_arr); 
							break;
						case 2: 
						    update_pur(purchase_arr); 
							break;
						case 3: 
						    search_pur(purchase_arr); 
							break;
						case 4: 
						    del_pur(purchase_arr); 
							break;
						case 5: 
						    show_pur(purchase_arr); 
						    break;
						case 6: 
						    total_pur(purchase_arr); 
							break;
						case 7: 
						    break;  
						default: 
						    cout<<"Enter correct option.\n";
                    }
                    if (function_choice == 7){
					    break;
                    }    
					cout<<"\nPress any key to continue....";
                    getch();
                }
                break;
                
            case 4:
            	while(true){
				    system("cls");
                    cout << "\n-***** Customer Management *****\n\n";
                    cout << "**** MENU **** \n";
                    cout << "1. Add Customer\n";
                    cout << "2. Edit Customer\n";
                    cout << "3. Delete Customer\n";
                    cout << "4. Search Customer\n";
                    cout << "5. View All Customers\n";
                    cout << "6. Go Back to Main Menu\n";
                    cout<<"------------------\n\n";
                    cout << "Enter your choice: ";
                    cin >> function_choice;
                    switch (function_choice) {
                    	
                        case 1:
                            addCustomer();
                            break;       
	                    case 2:
                            editCustomer();
                            break;       
		                case 3:
                            deleteCustomer();
                            break;
        		        case 4:
                            searchCustomer();
                            break;
		                case 5:
                            viewCustomers();
                            break;
		                case 6:
                            break;                 
				     	default:
                            cout << "\nInvalid choice! Try again.\n";
                    }
                    if (function_choice == 6){
					    break;
                    }
                    cout << "\n\nPress any key to continue...";
                    getch();      //to hold console screen for a second.
                }
                break;   
                
			case 5:
        	    while(true){
		            system("cls");
                    cout << "\n***** Employee Management *****\n\n";
                    cout << "**** MENU **** \n";
                    cout << "1. Add Employee\n";
                    cout << "2. Edit Employee\n";
                    cout << "3. Delete Employee\n";
                    cout << "4. Search Employee\n";
                    cout << "5. View All Employees\n";
                    cout << "6. Go Back to Main Menu\n";
                    cout<<"------------------\n\n";
                    cout << "Enter your choice: ";
                    cin >> function_choice;
                    switch (function_choice) {
                    	
                        case 1:
                            addEmployee();
                            break;                        
						case 2:
                            editEmployee();
                            break;   
		                case 3:
                            deleteEmployee();
                            break;                      
						case 4:
                            searchEmployee();
                            break;
		                case 5:
                            viewEmployees();
                            break;
		                case 6:
                            break;       
		                default:
                            cout << "\nInvalid choice! Try again.\n";
                    }
                    if (function_choice == 6){
					    break;
                    }
                    cout << "\n\nPress any key to continue...";
                    getch();
                }
                break;
            
			case 6:
            	while(true){
            		system("cls");
            		cout << "\n***** Supply Chain Management *****\n\n";
	                cout<<"**** MENU ****"<<endl;
	                cout<<"1. Add Record     "<<endl;
	                cout<<"2. Edit Record    "<<endl;
	                cout<<"3. Search Record  "<<endl;
	                cout<<"4. Delete Record  "<<endl;
	                cout<<"5. Display Record "<<endl;
	                cout<<"6. Go back to main menu "<<endl;
	                cout<<"------------------\n\n";
	                cout<<" Enter your choice "<<endl;
	                cin>>function_choice;
					switch(function_choice){
		                case 1:
			                AddSupplier();
		                    break;		
		                case 2:
			                EditSupplier();
		                    break;		
		                case 3:
			                SearchSupplier();
		                    break;		
		                case 4:
			                DelSupplier();
		                    break;		
		                case 5:
		                    DisplaySupplier();
		                    break;		
		                case 6:
                            break;			
		                default :
		                    cout<<"Invalid Choice "<<endl;		
                    }
                    if (function_choice == 6){
					    break;
                    }    
					cout<<"\nPress any key to continue....";
                    getch();
                }
                break;

            case 7: 
			    exit(0); 
			    break;  // Exit the program
            
			default: 
			    cout << "Enter correct option.\n";
        }
    }
    
    return 0;
}    


    

