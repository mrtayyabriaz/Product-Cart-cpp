#include<iostream>
#include<math.h>
#include<cstdlib>//liberary for finding randem number  rand() srand()
#include<time.h>
#include<string.h>
using namespace std;
class user_data{
	private:
	  	int id,age,temp_balance;
	  	string gender;
	    string password;
	protected:
		char name[50];
	public:
		int balance;
		string username;
	user_data(){
		balance=0;
	}
	void create_account(){
	  	cout<<"Welcome to Shoping City Create an account For shoping. "<<endl;
	  	cout<<"Enter Your Name: ";
	  	gets(name);
	  	username = name;
//	  	cout<<username;
	  	cout<<"Enter Your Age: ";
	  	cin>>age;
	  	cout<<"Enter Your Gender (1 for male | 2 for female): ";
	  	cin>>gender;
	  	if(gender=="1"){
	  		gender="Male";
		  }
		  else if(gender=="2") {
		  	gender="female";
		  }
		  else{
		  	gender = "You did not specified. ";
		  }
	  	cout<<endl;
	  	cout<<"Enter Password for security of your account: ";
	  	cin>>password;
	  	srand(time(0));		//to get randem number every time program runs, using time for randemness
		id=rand();
		cout<<"Account craeated successfully."<<endl<<endl;
	  }
	void show_user_data(){		
	    cout<<"Your login ID is: "<<id<<endl;	
	  	cout <<"Your name is: "<<name<<endl;
	  	cout <<"Your age is: "<<age<<endl;
	  	cout <<"Your gender is: "<<gender<<endl;
	  	cout <<"Your password is: "<<"*******"<<endl<<endl;
	  }
	void  login(){
		cout<<endl<<"Welcome to login section. "<<endl;
		cout<<"Enter your ID:";
		int temp_id;
		cin>>temp_id;
		cout<<"Enter Your Password: ";
		string temp_password;
		cin>>temp_password;
		if (id==temp_id && password == temp_password){     //check if id password is same
			cout<<"login successfull"<<endl<<endl;
		}
		else {
			cout<<"incorrect LOGIN ID or password Please enter correct login ID password to continue."<<endl;
			login();
		}
			
	}
	deposit(){
		cout<<"Enter how much money you want to deposit: ";
		cin>>temp_balance;
		balance=temp_balance+balance;
		cout<<"processing payment..... "<<endl;
		cout<<"Deposit successful :)"<<endl<<endl;
	}
};


class store_items:private user_data{
	private:
		int selected_items_no,selected_temp,total_price,balance,tempbalance,input,remove_no,item_id_arrar[20],item_price_array[20];
		string item_name_array[20];	
		char yorn;
	public:
		int total_items,selected_items[20];
//		string 
		store_items(user_data customer){
			selected_items_no =total_items = total_price = 0;
			cout<<"Welcome "<<customer.username<<" here is a list of available items on Shoping City "<<endl<<endl;
			balance=customer.balance;
		}
	
	void show_item(string item_name,int item_id,int item_price){
			cout<<"item name:    "<<item_name<<endl;
			cout<<"item ID:      "<<item_id<<endl;
			cout<<"item price:   "<<item_price<<endl<<endl;
			item_name_array[total_items] = item_name;
			item_id_arrar[total_items] = item_id;
			item_price_array[total_items] = item_price;
//			cout<<item_name_array[total_items]<<endl<<item_id_arrar[total_items]<<endl<<item_price_array[total_items]<<endl;
			total_items++;
	}
	
	void show_cart(){
		cout<<"Here is list of Products you selected: "<<endl;
		tempbalance=balance;
		total_price=0;
			for(int i=0;i<selected_items_no;i++){
//				cout<<selected_items[i];
//				selected_temp=selected_items[i];
				cout<<"item name:  "<<item_name_array[selected_items[i]]<<endl;
				cout<<"item Price: "<<item_price_array[selected_items[i]]<<endl;
				cout<<"item ID:    "<<item_id_arrar[selected_items[i]]<<endl<<endl;	
			total_price = total_price + item_price_array[selected_items[i]];
		}
		cout<<"Total Price= "<<total_price<<endl;
		
		
		if(total_price<=tempbalance){
			tempbalance=tempbalance-total_price;
			cout<<"Remaining Balance = "<<tempbalance<<endl<<endl;
		}
		else if(total_price>tempbalance){
			tempbalance=tempbalance-total_price;
			cout<<"Remaining Balance = "<<tempbalance<<endl<<endl;
			cout<<"Your Balance is less then total price drop something from cart to continue."<<endl<<endl;
		}
//			select_items();
			menu();
	}
	
	void selection(){
		cout<<"Enter item ID to selcet: ";
		cin>>selected_items[selected_items_no];
		selected_items_no++;
		select_items();
	}
	void select_items(){
		cout<<"Do you want add an item to cart ( y/n ): ";
		cin>>yorn;
		if(yorn=='y'){
			selection();
		}
		else{
			show_cart();
		}
	}
	void remove_items(){
		cout<<"Enter item ID to remove item: ";
		cin>>remove_no;
		int i,j,found=0;
		for(i=0; i<selected_items_no; i++){
        	if(selected_items[i]==remove_no){
   	        	for(j=i; j<(selected_items_no-1); j++){
                	selected_items[j] = selected_items[j+1];
				}
            	found=1;
            	i--;
           		selected_items_no--;
        	}
    	}
    	if(found==0){
    		cout<<"ID not found in cart. :( tyr again. ";
		}
		else{
		cout<<"item has been removed :)"<<endl;
		}
		menu();
	}
	void confirm_order(){
		cout<<"Your order has been confirmed. "<<endl<<"Thanks for shoping here :)"<<endl;
	}
	void menu(){
		cout<<endl<<"Enter number according to option: "<<endl;
		cout<<"1. Add items"<<endl;
		cout<<"2. Remove Items"<<endl;
		cout<<"3. Go to cart"<<endl;
		cout<<"4. Confirm order"<<endl;
		cout <<"Enter Value: ";
		cin>>input;
		cout<<endl;
		if(input==1){
			select_items();
		}
		if(input==2){
			remove_items();
		}
		if(input==3){
			show_cart();
		}
		if(input==4){
			confirm_order();
		}
	}
};

int main()
{
	user_data customer;
	customer.create_account();
	customer.show_user_data();
	  customer.login();
    customer.deposit();

store_items items(customer);

	items.show_item("COOKING OIL /liter",0,400);
	items.show_item("Soap /1 piece",1,100);
	items.show_item("Milk /KG",2,120);
	items.show_item("Sugar /KG",3,100);
	items.show_item("Tea /KG",4,250);
	items.select_items();
	
	return 0;
}

