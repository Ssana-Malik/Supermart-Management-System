#include<iostream>
#include<conio.h>
using namespace std;
int Max_Supplier=20;
struct Supplier{
	int id ;
	string name;
	string status;
};
Supplier Suppliers[20];
struct Item{
	string name;
	int quantity;
};
struct Customer {
    int id;
    char name[50];
    char phonenumber[15];
    float totalPurchase;
};

// Structure for Employee
struct Employee {
    int id;
    char name[50];
    char phonenumber[15];
    char position[50];
    float salary;
};

// Global Arrays and Variables
Customer customers[100];
Employee employees[100];
int customerCount = 0, employeeCount = 0;

// Function Prototypes
void customerManagement();
void employeeManagement();
void addCustomer();
void editCustomer();
void deleteCustomer();
void searchCustomer();
void viewCustomers();
void addEmployee();
void editEmployee();
void deleteEmployee();
void searchEmployee();
void viewEmployees();
Item Inventory[20];

int i=0;
void AddItem(){
	if(i<20){
		cout<<"Enter the name of the item you want to add :"<<endl;
	          cin.ignore() ;
		getline(cin,Inventory[i].name)  ;
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
	getline(cin,names)  ;
	for(int j=0;j<i;j++){
	     if(names == Inventory[j].name){
		cout<<"Enter new name "<<endl;
		cin>>Inventory[j].name;
		cout<<"Enter new quantity "<<endl;
		cin>>Inventory[j].quantity;
	          return ;
              }    
	}
	cout<<"Item not found !"<<endl;
}
void SearchItem(){
	string names ;
	cout<<"Enter the name of the item you want to search :"<<endl;
	cin.ignore() ;
	getline(cin,names)  ;
	for(int j=0;j<i;j++){
	if(names == Inventory[j].name){
		cout<<"Item is found "<<endl;
		cout<<"Name     : "<<Inventory[j].name<<endl;
		cout<<"Quantity : "<<Inventory[j].quantity<<endl;
		return ;
	}
	}
	cout<<"Item not found !"<<endl;	
}
void DelItem(){
	string names ;
	cout<<"Enter the name of the item you want to delete :"<<endl;
	cin>>names  ;
	for(int j=0;j<i;j++){
	if(names == Inventory[j].name){
              for(int k=j;k<i-1;k++){
              	Inventory[k]=Inventory[k+1];
	    }
	    i--;
	    cout<<"Item deleted "<<endl;
	    return ;
	}
	}
	cout<<"Item not found !"<<endl;
}
void DisplayItem(){
	cout<<"Current Record "<<endl;

	for(int j=0;j<i;j++){
	cout<<"Name :     "<< Inventory[j].name<<endl;
	cout<<"Quantity : "<< Inventory[j].quantity<<endl;
	}
}

//            Sale 
void add_sale(float sale_arr[]){
	cout<<"** Insert Record **.\n\nEnter the new sales: $";
	cin>>sale_arr[i];
	i++;
}
void update_sale(float sale_arr[]){
	int n,new_value;
	cout<<"** Update Record **.\n\nEnter the record you want to update: $";
	cin>>n;
	bool search;
	for(int j=0;j<i;j++){
		if(n==sale_arr[j]){
			cout<<"Record before updation: $"<<sale_arr[j]<<endl<<"Now update the record: $ ";
			cin>>new_value;
			sale_arr[j]=new_value;
			cout<<"\nRecord after updation: $"<<sale_arr[j]<<"\nRecord is successfully updated. "<<endl;
			search=true;
			break;
		}
	}
	if(!search){
			cout<<"Record not found."<<endl;
	}
}
void search_sale(float sale_arr[]){
	int n;
	cout<<"** Search Record **.\n\nEnter the data you want to search: $";
	cin>>n;
	bool found;
    for (int j=0;j<i;j++) {
        if (n==sale_arr[j]) {
            cout<<"\nThe record is present." << endl;
            found=true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found." << endl;
    }
}
void del_sale(float sale_arr[]){
	int n;
	cout<<"** Delete Record **.\n\nEnter the record you want to delete: $";
	cin>>n;
	bool find;
	for(int j=0;j<i;j++){
		if(n==sale_arr[j]){
			for(int k=j;k<i-1;k++){
				sale_arr[k]=sale_arr[k+1];
			}
			cout<<"Value deleted successfully.";
			i--;
			find=true;
			break;
		}
   }
   if(!find){
			cout<<"Record not found."<<endl;
		}
}
void show_sale(float sale_arr[]){
	cout<<"**Show Record **.\n\nCurrent record "<<endl;
	for(int j=0;j<i;j++){
		cout<<"$"<<sale_arr[j]<<endl;
	}
}
void sales(float sale_arr[]){
	float sum=0;
	cout<<"Total Sales Section.";
	for(int j=0;j<i;j++){
		sum+=sale_arr[j];
	}
	cout<<"\n\nTotal sale of the day is: $"<<sum;
}

//             PURCHASE

void add_pur(float purchase_arr[]){
	cout<<"** Insert Record **.\n\nEnter the new purchase: $";
	cin>>purchase_arr[i];
	i++;
}
void update_pur(float purchase_arr[]){
	int n,new_value;
	cout<<"** Update Record **.\n\nEnter the record you want to update: $";
	cin>>n;
	bool search;
	for(int j=0;j<i;j++){
		if(n==purchase_arr[j]){
			cout<<"Record before updation: $"<<purchase_arr[j]<<endl<<"Now update the record: $ ";
			cin>>new_value;
			purchase_arr[j]=new_value;
			cout<<"\nRecord after updation: $"<<purchase_arr[j]<<"\n!!Record is successfully updated!!"<<endl;
			search=true;
			break;
		}
	}
	if(!search){
			cout<<"Record not found!!!!"<<endl;
	}
}
void search_pur(float purchase_arr[]){
	int n;
	cout<<"** Search Record **.\n\nEnter the record you want to search: $";
	cin>>n;
	bool found;
    for (int j=0;j<i;j++) {
        if (n==purchase_arr[j]) {
            cout<<"\nThe record is present." << endl;
            found=true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found!!!!" << endl;
    }
}
void del_pur(float purchase_arr[]){
	int n;
	cout<<"** Delete Record **.\n\nEnter the record you want to delete: $";
	cin>>n;
	bool find;
	for(int j=0;j<i;j++){
		if(n==purchase_arr[j]){
			for(int k=j;k<i-1;k++){
				purchase_arr[k]=purchase_arr[k+1];
			}
			cout<<"!!Record deleted successfully!!";
			i--;
			find=true;
			break;
		}
   }
   if(!find){
			cout<<"Record not found!!!!"<<endl;
		}
}
void show_pur(float purchase_arr[]){
	cout<<"**Show Record **.\n\nCurrent record "<<endl;
	for(int j=0;j<i;j++){
		cout<<"$"<<purchase_arr[j]<<endl;
	}
}
void total_pur(float purchase_arr[]){
	float sum=0;
	cout<<" Total Purchase ";
	for(int j=0;j<i;j++){
		sum+=purchase_arr[j];
	}
	cout<<"\n\nTotal purchase of the day is: $"<<sum;
} 

//          Customer

void addCustomer() {
    cout << "\nEnter Customer ID: ";
    cin >> customers[customerCount].id;
    cin.ignore();
    cout << "Enter Customer Name: ";
    cin.getline(customers[customerCount].name, 50);
    cout << "Enter Customer Phone number: ";
    cin.getline(customers[customerCount].phonenumber, 15);
    cout << "Enter Customer Purchase: ";
    cin >> customers[customerCount].totalPurchase;
    cin.ignore();
    customerCount++;
    cout << "\nCustomer added successfully!\n";
}

void editCustomer() {
    int id;
    cout << "\nEnter Customer ID to edit: ";
    cin >> id;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == id) {
            cin.ignore();
            cout << "Edit Customer Name: ";
            cin.getline(customers[i].name, 50);
            cout << "Edit Customer Phone number: ";
            cin.getline(customers[i].phonenumber, 15);
            cout << "Edit Customer Purchase: ";
            cin >> customers[i].totalPurchase;
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
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == id) {
            for (int j = i; j < customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            customerCount--;
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
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == id) {
            cout << "\nCustomer Found:\n";
            cout << "Name: " << customers[i].name << "\n";
            cout << "Phone number: " << customers[i].phonenumber << "\n";
            cout << "Total Purchase: " << customers[i].totalPurchase << "\n";
            return;
        }
    }
    cout << "\nCustomer not found!\n";
}

void viewCustomers() {
    if (customerCount == 0) {
        cout << "\nNo customers added yet.\n";
        return;
    }
    cout << "\nID\tName\t\t   Phone Number\t\tTotal Purchase\n";
    for (int i = 0; i < customerCount; i++) {
        cout << customers[i].id << "\t" << customers[i].name << "\t   " 
             << customers[i].phonenumber << " \t\t$" << customers[i].totalPurchase << "\n";
    }
}

//           Employee

void addEmployee() {
    cout << "\nEnter Employee ID: ";
    cin >> employees[employeeCount].id;
    cin.ignore();
    cout << "Enter Employee Name: ";
    cin.getline(employees[employeeCount].name, 50);
    cout << "Enter Employee Phone Number: ";
    cin.getline(employees[employeeCount].phonenumber, 15);
    cout << "Enter Employee Position: ";
    cin.getline(employees[employeeCount].position, 50);
    cout << "Enter Employee Salary: ";
    cin >> employees[employeeCount].salary;
    cin.ignore();
    employeeCount++;
    cout << "\nEmployee added successfully!\n";
}

void editEmployee() {
    int id;
    cout << "\nEnter Employee ID to edit: ";
    cin >> id;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            cin.ignore();
            cout << "Edit Employee Name: ";
            cin.getline(employees[i].name, 50);
            cout << "Edit Employee Phone Number: ";
            cin.getline(employees[i].phonenumber, 15);
            cout << "Edit Employee Position: ";
            cin.getline(employees[i].position, 50);
            cout << "Edit Employee Salary: ";
            cin >> employees[i].salary;
            cin.ignore();
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
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
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
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            cout << "\nEmployee Found:\n\n";
            cout << "Name: " << employees[i].name << "\n";
            cout << "Phone Number: " << employees[i].phonenumber << "\n";
            cout << "Position: " << employees[i].position << "\n";
            cout << "Salary: " << employees[i].salary << "\n";
            return;
        }
    }
    cout << "\nEmployee not found!\n";
}

void viewEmployees() {
    if (employeeCount == 0) {
        cout << "\nNo employees added yet.\n";
        return;
    }
    cout << "\n ID\t   Name\t\t   Phone Number\t\t  Position \t\t    Salary\n";
    for (int i = 0; i < employeeCount; i++) {
        cout <<" "<< employees[i].id << "\t" << employees[i].name << "\t    "
             << employees[i].phonenumber << "\t\t " << employees[i].position << "          \t$ "
             << employees[i].salary << "\n";
    }
}

//        Supply Chain

void AddSupplier(){
	if(i<20){
		cout<<"Enter  supplier id :"<<endl;
	          cin>>Suppliers[i].id;
		cout<<"Enter supplier name :"<<endl;
	          cin.ignore() ;
		getline(cin,Suppliers[i].name)  ;
		cout<<"Enter supplier status "<<endl;
		 cin.ignore() ;
		getline(cin,Suppliers[i].status)  ;
		i++;
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
	for(int j=0;j<i;j++){
	if(id == Suppliers[j].id){
		cout<<"Enter new supplier name "<<endl;
		cin.ignore() ;
	          getline(cin,Suppliers[i].name)  ;
		cout<<"Enter new supplier status "<<endl;
		cin.ignore() ;
            	getline(cin,Suppliers[i].status)  ;
            	
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
	for(int j=0;j<i;j++){
	if(id == Suppliers[j].id){
		cout<<"Supplier found ! "<<endl;
		cout<<"ID :     "<<Suppliers[j].id<<endl;
		cout<<"Name : "<<Suppliers[j].name<<endl;
		cout<<"Status : "<<Suppliers[j].status<<endl;
	}	
	}
	cout<<"Supplier not found ! "<<endl;
}
void DelSupplier(){
	int id ;
	cout<<"Enter the id of the supplier to delete :"<<endl;
	cin>>id;
	for(int j=0;j<i;j++){
	if(id == Suppliers[j].id){
              for(int k=j;k<i-1;k++){
              	Suppliers[k]=Suppliers[k+1];
	    }
	    i--;
          cout<<"Supplier deleted  "<<endl;
	}
   }
   cout<<"Supplier not found ! "<<endl;
}
void DisplaySupplier(){
	cout<<"Current Record "<<endl;
	for(int j=0;j<i;j++){
	cout<<" \n ";
	cout<<"Supplier Name   :"<<Suppliers[j].name<<endl;
	cout<<"Supplier Id     :"<<Suppliers[j].id<<endl;
	cout<<"Supplier Status :"<<Suppliers[j].status<<endl;
	}
}

int main() {
    int choice, function_choice;
    float sale_arr[50], purchase_arr[50];
    while (true) {
        system("cls");
        cout<<"*****   SUPER MART MANAGEMENT SYSTEM   *****\n\n";
        cout<<"-----  MENU  -----\n";
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
            case 1:  
                while (true) {
                    system("cls");
                    cout<<"*****   INVENTORY MANAGEMENT   *****\n\n";
                    cout<<"-----  MENU  -----\n";
                    cout<<"1.Add Record     "<<endl;
	                cout<<"2.Edit Record    "<<endl;
	                cout<<"3.Search Record  "<<endl;
	                cout<<"4.Delete Record  "<<endl;
	                cout<<"5.Display Record "<<endl;
	                cout<<"6.Go back to main menu "<<endl<<endl;
                    cout<<"Enter your function choice: ";
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
                    cout<<"-----  MENU  -----\n";
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
                    cout<<"-----  MENU  -----\n";
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
                    cout << "\n--- Customer Management ---\n\n";
                    cout << "...... MENU ...... \n";
                    cout << "1. Add Customer\n";
                    cout << "2. Edit Customer\n";
                    cout << "3. Delete Customer\n";
                    cout << "4. Search Customer\n";
                    cout << "5. View All Customers\n";
                    cout << "6. Back to Main Menu\n";
                    cout << "..................\n\n";
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
                getch();
            }
                break;
                
			case 5:
        	    while(true){
		            system("cls");
                    cout << "\n--- Employee Management ---\n\n";
                    cout << "...... MENU ...... \n";
                    cout << "1. Add Employee\n";
                    cout << "2. Edit Employee\n";
                    cout << "3. Delete Employee\n";
                    cout << "4. Search Employee\n";
                    cout << "5. View All Employees\n";
                    cout << "6. Back to Main Menu\n";
                    cout << "..................\n\n";
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
            		cout << "\n--- Supply Chain Management ---\n\n";
	                cout<<"**********MENU***********"<<endl;
	                cout<<"1.Add Record     "<<endl;
	                cout<<"2.Edit Record    "<<endl;
	                cout<<"3.Search Record  "<<endl;
	                cout<<"4.Delete Record  "<<endl;
	                cout<<"5.Display Record "<<endl;
	                cout<<"6.Exit           "<<endl;
	                cout<<"************************"<<endl<<endl;
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


    

