#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
using namespace std;
char mov[50];
class Seats
{
public:
	int seat;
	//for changing number of seats
	Seats()
	{
		seat = 0;
	}
	void operator++()
	{
		++seat;
	}
	void operator--()
	{
		--seat;
	}
};
class Movie
{
protected:
	char Movie1[50], Director1[50], Lang1[10], type1[3];
	char Movie2[50], Director2[50], Lang2[10], type2[3];
	char Movie3[50], Director3[50], Lang3[10], type3[3];
public:
	friend void create(Movie);
	Movie()
	{
		//creating file with movie details
		strcpy(Movie1, "Bhediya"); strcpy(Director1, "Amar Kaushik"); strcpy(Lang1, "Hindi"); strcpy(type1, "3D");
		strcpy(Movie2, "Avatar: The Way of Water"); strcpy(Director2, "James Cameron"); strcpy(Lang2, "English"); strcpy(type2, "3D");
		strcpy(Movie3, "Drishyam 2"); strcpy(Director3, "Abhishek Pathak"); strcpy(Lang3, "Hindi"); strcpy(type3, "2D");
	}
};
void create(Movie m)
{
	//writes to file
	ofstream file(m.Movie1);
	file << m.Movie1 << endl;
	file << m.Director1 << endl;
	file << m.Lang1 << endl;
	file << m.type1 << endl;
	file.close();
	ofstream out(m.Movie2);
	out << m.Movie2 << endl;
	out << m.Director2 << endl;
	out << m.Lang2 << endl;
	out << m.type2 << endl;
	out.close();
	ofstream filee(m.Movie3);
	filee << m.Movie3 << endl;
	filee << m.Director3 << endl;
	filee << m.Lang3 << endl;
	filee << m.type3 << endl;
	filee.close();
}
class Price :public Seats, public Movie
{
protected:
	double total = 0, price;
public:
	Price()
	{
		price = 0; //initializes price
	}
	Price(int p)
	{
		price = p; //prices for different movies 
		if (strcmp(mov, Movie1) == 0)
		{
			if (strcmp(type1, "3D") == 0)
				price = price + 30;
			else
				price += 0;
		}
		else if (strcmp(mov, Movie2) == 0)
		{
			if (strcmp(type2, "3D") == 0)
				price = price + 30;
			else
				price += 0;
		}
		else
		{
			if (strcmp(type3, "3D") == 0)
				price = price + 30;
		}
		cout << "Enter no. of seats: ";
		cin >> seat;
		check(); 
	}
	void display(double a)
	{
		cout << "\nMovie:" << mov << endl;
		cout << "Seats booked:" << seat << endl;
		total = seat * price;
		cout << "Total:" << total << endl;
	}
	void check() { //checks if too many or too few seats
		if (seat > 100 || seat == 0) {
			cout << "Seats in range (1-100)\n" << "Enter no. of seats:";
			cin >> seat;
			check();
		}
		else { //calculates price
			cout << "\nprice per seat:" << price << endl;
			total = seat * price;
			cout << "total amount:" << total << endl;
		}
	}
};
class Bill : public Movie
{
public:
	Bill()
	{
		cout << "MOVIE BOOKING SYSTEM\n";
		cout << "Price for 2D movies:Rs 250\nPrice for 3D movies 250+30 i.e Rs 280\n";
	}
	void display(char c)
	{
		cout << "Movie details in the format Movie name, Director,Language and type\n\n";
		char ch[70];
		ifstream outf;
		outf.open(mov);
		while (outf)
		{ //reading from file
			outf.getline(ch, 70);
			cout << ch << endl;
		}
		outf.close();
	}
	void display(int b)
	{
		cout << "\nAvailable movies:\n";
		cout << "1." << Movie1 << endl << "2." << Movie2 << endl << "3." << Movie3 << endl;

	}
};
int main()
{
	//initialize
	Movie m;
	//creates files
	create(m);
	//display movie list
	Bill b1;
	b1.display(1);
	int a;
	int c = 0;
	while (c = 1) { 
		cout << "\nEnter option 1,2 or 3:";
		cin >> a;
		if (a == 1) {
			strcpy(mov, "Bhediya");
			break;
		}
		else if (a == 2) {
			strcpy(mov, "Avatar: The Way of Water");
			break;
		}
		else if (a == 3) {
			strcpy(mov, "Drishyam 2");
			break;
		}
		else {
			cout << "Invalid" << endl;
			c = 1;
		}
	}
	//display file
	cout << endl;
	b1.display('c');
	//calculate price
	Price p1(250);
	int lim = 0, b = 0;
	while (1)
	{
		int n;
		cout << "\nEnter option\n1.Display movie details\n2.Change no of seats\n3.Display Bill\n4.Stop\n";
		cin >> n;
		switch (n)
		{
		case 1:
			b1.display('a');
			break;
		case 2:
			int change, num;
			Seats* ptr;
			ptr = &p1;
			b = ptr->seat;
			lim = 100 - b;
			cout << "\n1.Increase seats\n2.Decrease seats\n";
			cin >> change;
			if (change == 1) {
				cout << "Increase by:";
				cin >> num;
				if (num > lim) { //calculate remaining seats
					cout << "Limit is " << lim;
					break;
				}
				else {
					for (int r = 0; r < num; r++)
						++p1;
				}
			}
			else {
				cout << "Decrease by:";
				cin >> num;
				if ((ptr->seat) - num != 0) { //calculate remaining seats
					for (int r = 0; r < num; r++)
						--p1;
				}
				else {
					cout << "Enter smaller value\n";
					break;
				}
			}
			cout << "\nBill details updated\nNo. of seats is:" << ptr->seat << endl;;
			break;
		case 3:
			p1.display(1.0);
			break;
		case 4:
			exit(0);
		}
	}
	return 0;
}








