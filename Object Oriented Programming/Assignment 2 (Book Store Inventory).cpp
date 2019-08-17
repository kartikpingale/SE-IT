/*
A Book shop maintains the inventory of books that are being sold at the shop.
The list includes details such as title, author, publisher, price and available stock.
Write a program in C++ which will have a class called books with suitable member functions for
i. Add
ii. Update
iii. Search a book
iv. Purchase a book (update the stock and display the total cost)
v. Record number of successful/unsuccessful transactions (use static data members to keep count of transactions)
Use new operator in constructors to allocate memory space required.
*/


#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book					//defining class 
{
	char *author,*title,*publisher; 	//setting data members as pointers
	float *price;
	int * stock;
	public:
	book()
	{
		author = new char[50];
		title = new char[50];
		publisher = new char[50];
		price = new float;
		stock = new int;
	}
	void feedData();
	void editData();
	void showData();
	int search(char[],char[]);
	void buyBook();
};

void book :: feedData()				//function to get all the data
{
	cin.ignore();				//used cin.ignore(), as I have used getline funtion, so it is convinent for the user to input a string with spaces, and does not crash the program
	cout<<"\nEnter title: ";
	cin.getline(title,50);
	cout<<"\nEnter author: ";
	cin.getline(author,50);
	cout<<"\nEnter publisher: ";
	cin.getline(publisher,50);
	cout<<"\nEnter the price: ";
	cin>>*price;
	cout<<"\nEnter the stock: ";
	cin>>*stock;
	cout<<"\n\n";
}

void book :: editData()				//function to edit the data
{
	feedData();				//it is basically the feedData function called inside it
}

void book :: showData()				//function to display all the data of the book
{
	cout<<"\nTitle: "<<title;
	cout<<"\nAuthor: "<<author;
	cout<<"\nPublisher: "<<publisher;
	cout<<"\nPrice: Rs "<<*price;
	cout<<"\nStock: "<<*stock;
}

int book :: search(char tbuy[50],char abuy[50]) 		//function to search if a book and the author exists in stock or not 
{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0) 	//this funtion compares the title and the author string with help of strcmp funtion
		return 1;					//and if a book is found returns value 1, or else 0
	else return 0;
}

void book :: buyBook()				//function to buy book
{
	int count;
	cout<<"\nEnter the number of books to buy: ";
	cin>>count;				//this function first checks if the stock of the books are sufficient
	if(count<=*stock)			//if yes, then finds out the total cost of the books to be bought
	{
		*stock=*stock-count;
		cout<<"\nBooks bought successfully.";
		cout<<"\nAmount: Rs "<<(*price)*count;
	}
	else
		cout<<"\nRequired copies are not in stock.";
}

int main()
{
	book *B[100];				//objects initialized as array
	int i=0,t,choice;
	char titleBuy[50],authorBuy[50];
	while(1)
	{
		cout<<"\n\n\tMENU";
		cout<<"\n1. Entry of new book.\n2. Buy book.\n3. Search for book.\n4. Edit details of book.\n5. Exit\nEnter your choice: "; 	//menu
		cin>>choice;
		
		switch(choice)
		{
			case 1: B[i] = new book;
				B[i]->feedData();		//dot and arrow are used to refrence indivitial members in class
				i++;
				break;

			case 2: cin.ignore();
				cout<<"\nEnter title: ";
				cin.getline(titleBuy,50);
				cout<<"\nEnter author: ";
				cin.getline(authorBuy,50);

				for(t=0;t<i;t++)
				{
					if(B[t]->search(titleBuy,authorBuy))	//first checks if the book exists, then buys it
					{
						B[t]->buyBook();
						break;
					}
				}
				if(t==1)
					cout<<"\nThis book is not in stock.";
				break;

			case 3: cin.ignore();
				cout<<"\nEnter title: ";
				cin.getline(titleBuy,50);
				cout<<"\nEnter author: ";
				cin.getline(authorBuy,50);
				
				for(t=0;t<i;t++)
				{
					if(B[t]->search(titleBuy,authorBuy))
					{
						cout<<"\nBook found!";
						B[t]->showData();
						break;
					}
				}
				if(t==i)
					cout<<"\nbook not in stock.";
				break;

			case 4: cin.ignore();
			        cout<<"\nEnter title: ";
				cin.getline(titleBuy,50);
				cout<<"\nEnter author: ";
				cin.getline(authorBuy,50);	

				for(t=0;t<i;t++)
				{
					if(B[t]->search(titleBuy,authorBuy))	//first checks if the book exists, then edits it
					{
						cout<<"\nBook found";
						B[t]->editData();
						break;
					}
				}
				if(t==1)
					cout<<"\nBook not in stock.";
				break;

			case 5: exit(0);
			default: cout<<"\nInvalid choice.";
		}
	}
	return 0;
}
