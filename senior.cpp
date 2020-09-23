/* This is a program of online food ordering system which allowed user to make order more efficiently and accurately.
Admin is allowed to check the existing users,the purchase history and the feedbacks from user.
Users can signup as member to make their order more easily.
Users will get some discount when they have purchased up to a certain amount. */

void orderpage(char filename[], int sizefn);
void orderhistory(char filename[], int sizefn);
void review(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, char filename[], int sizefn);
void calculations(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, double &total1, double &total2, double &discount);
void payment(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, double total2, double discount, char filename[], int sizefn);
void creditcard(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, double total2, double discount, char filename[], int sizefn);
void receipt(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, double total2, double discount, char filename[], int sizefn);
void feedback();

/* The followings are declarations for some variables */

char f1[50] = "1) Black Paper Chicken Chop Rice";
char f2[50] = "2) BBQ Chicken Chop Rice";
char f3[50] = "3) Potato Salad Rice";
char f4[50] = "4) Chicken Burger";
char f5[50] = "5) French Fries";
char f6[50] = "6) Soft Drink - 100Plus";
char c1[50] = "1) Combo Set A";
char c2[50] = "2) Combo Set B";
char c3[50] = "3) Combo Set C";
char c4[50] = "4) Combo Set D";

const int sizefn = 110, size = 100;

/* This is the main menu to display welcome messages and the menu */

int main()
{
	char choice;
	
		cout << "      ****        **    ***                 *****            ****          ** " << endl;
		cout << "    **** ****     **     ** ****         **** ****        **** ****        ** " << endl;
		cout << "  ***       **           ****  ****     ***      **      ***     ***          " << endl;
		cout << " **               **     **      **    **               **         **      ** " << endl;
		cout << " **               **     **      **    **               **         **      ** " << endl;
		cout << " **               **     **      **    **               **         **      ** " << endl;
		cout << "  ***       **    **     **      **     ***      **      ***       **      ** " << endl;
		cout << "    **** ****     **     **      **      **** ****        **** ******      ** " << endl;
		cout << "      ****        **     **      ***        ****             ****  **      ** " << endl;
		cout << endl << endl;
		cout << "                             FAST-FOOD Delivary " << endl;
		cout << endl << endl;
		cout << "Please press ENTER to continue..." << endl;
		system("pause");
		system("cls");
	
	cout << "If this is your first time to visit us please press sign up as member (C/c)." << endl;
	cout << "if you wish to leave this program, you may enter (D/d) to exit, thank you." << endl << endl;
	cout << "\t A) Login as Admin" << endl;
	cout << "\t B) Login as Member" << endl;
	cout << "\t C) Signup as Member" << endl;
	cout << "\t D) Exit" << endl << endl;
	cout << "Please enter your choice: ";

	cin >> choice; // get choice from the user to proceed the following steps
	switch (choice) // compare the choice get from user to call specific function
	{
	case 'A':
	case 'a':
		cin.ignore();
		system("cls");
		adminlogin(); //adminlogin() function is called for the user to login
		break;
	case 'B':
	case 'b':
		cin.ignore();
		system("cls");
		loginpage(); //loginpage() function is called for the user to login
		break;
	case 'C':
	case 'c':
		cin.ignore();
		system("cls");
		signuppage(); //signuppage() function is called for new user to signup as member
		break;
	case 'D':
	case 'd':
		exit(0);
		break;
	default:
		cout << "You Have Entered an Invalid Choice, Please Try Again Thank You!!" << endl; //This stament will be display when the user key in an invalid input
		system("pause");
		system("cls");
		main(); //main() function is called for the user to enter another choice again
		break;
	}
	return 0;
}


/* This is the function for the user to login as member */

void loginpage()
{

	fstream infile;
	char txt[] = ".txt", choice;
	char username[size], filename[sizefn], confirmupdate;
	string pw, loginpw;// pw & loginpw in string so the compare job with the password enter by user will be easier

	cout << "Please enter username: ";
	cin.getline(username, size);

	strcpy(filename, username);
	strcat(filename, txt); //username entered by user is joined with string "txt"

	infile.open(filename, ios::in); //file is read depending on the username input
	if (infile.fail()) //if the file open failed, the following statements will be executed
	{
		cout << username << " username does not exist." << endl;//if the user does not used before, then it will display.
		system("pause");
		system("CLS");
		loginpage();
	}

	infile.getline(username, size);// load username but don't display.
	getline(infile, pw);// load password but don't display.

	for (int i = 3; i >= 0; i--) //conditions are set for the user to reenter the password for 3 times only if the user entered a wrong password
	{
		cout << "Password: ";
		getline(cin, loginpw);
		if (loginpw != pw)
		{
			cout << "You left " << i << " time(s) to enter your password" << endl; //to inform user how many times they can reenter the password
		}
		if (loginpw == pw)
		{
			do
			{
				system("cls");
				cout << "A) View Profile" << endl;
				cout << "B) Update Profile" << endl;
				cout << "C) Make Order" << endl;
				cout << "D) Order History" << endl;
				cout << "E) Exit" << endl << endl;
				cin >> choice;
				if (choice == 'A' || choice == 'a')
				{
					system("cls");
					viewprofile(filename, sizefn);
				}
				else if (choice == 'B' || choice == 'b')
				{
					cout << "________________________________________________________________________________" << endl;
					cout << "Are you sure you want to update your profile, your previous order history will be clear once you update." << endl << endl;
					cout << "Press Y to proceed or press any key to cancel and RE-LOGIN" << endl;
					cin >> confirmupdate;
					if (confirmupdate == 'Y' || confirmupdate == 'y')
					{
						system("cls");
						updateprofile(filename, sizefn);
					}
					else
					{
						cin.ignore();
						system("cls");
						loginpage();
					}
				}
				else if (choice == 'C' || choice == 'c')
				{
					system("cls");
					orderpage(filename, sizefn);
				}
				else if (choice == 'D' || choice == 'd')
				{
					system("cls");
					orderhistory(filename, sizefn);
				}
				else if (choice == 'E' || choice == 'e')
				{
					exit(0);
				}
				else
				{
					cout << "You have entered and invalid choice!Please try again!" << endl;
					system("pause");
				}

			} while (choice != 'A' || choice != 'a' || choice != 'B' || choice != 'b' || choice != 'C' || choice != 'c' || choice != 'D' || choice != 'd');
		}
	}




	infile.close();
}

/* This is the function for the user to sign up as new member */

void signuppage()
{
	fstream infile, outfile;
	char txt[] = ".txt";
	char username[size], pw[size], name[size], ic[size], add[size], hp[size], emailadd[size], filename[sizefn];
	string testexist;
	bool exist = true;
	bool tfname = true, tfic = true, tfhp = true;

	cout << "Please enter username: ";
	cin.getline(username, size);
	infile.open("adminfile.txt", ios::in);
	for (int i = 0; i<strlen(username); i++)
	{
		username[i] = tolower(username[i]); //the username entered by the user is chaged to all lover case before saving into a file named "adminfile.txt"
	}
	while (!infile.fail())
	{
		getline(infile, testexist);
		if (testexist == username)
		{
			exist = false;
			cout << "The usename already exist... Please key in the other username." << endl;
			system("pause");
			break;
		}
	}
	infile.close();
	if (exist)
	{
	}
	else
	{
		system("CLS");
		signuppage();
	}
	strcpy(filename, username);
	strcat(filename, txt);

	outfile.open(filename, ios::out); //file is open to ready to save data
	outfile << username << endl;
	outfile.close();//close the filename to let the username store in adminfile
	outfile.open("adminfile.txt", ios::out | ios::app);//save for admin to check got how many user
	outfile << username << endl;
	outfile.close();

	outfile.open(filename, ios::out | ios::app);//open back to save in filename
	cout << "Please enter password: ";
	cin.getline(pw, size);
	outfile << pw << endl;

	do
	{
		cout << "Please enter your name(Only alphabet): ";
		cin.getline(name, size);
		for (int i = 0; i<strlen(name); i++)
		{
			if (!isalpha(name[i]))//to check whether is alphabet
			{
				if (name[i] == ' ')
				{
					continue;//if space, it will continue checking
				}
				tfname = false;
				cout << "Invalid name. Please key in only alphabet." << endl;
				break;
			}
			tfname = true;
		}
	} while (tfname == false);
	outfile << name << endl;

	do
	{
		cout << "Please enter I/C Number (Without dash): ";
		cin.getline(ic, size);
		for (int i = 0; i<strlen(ic); i++)
		{
			if (!isdigit(ic[i]))//to check whether is number
			{
				tfic = false;
				cout << "Invalid I/C. Please key in only numbers." << endl;
				break;
			}
			tfic = true;
		}
	} while (tfic == false);
	outfile << ic << endl;

	cout << "Please enter Address: ";
	cin.getline(add, size);
	outfile << add << endl;

	do
	{
		cout << "Please enter contact number (Without dash): ";
		cin.getline(hp, size);
		for (int i = 0; i<strlen(hp); i++)
		{
			if (!isdigit(hp[i]))//to check whether is number
			{
				tfhp = false;
				cout << "Invalid contact number. Please key in only numbers." << endl;
				break;
			}
			tfhp = true;
		}
	} while (tfhp == false);
	outfile << hp << endl;

	cout << "Please enter E-mail Address: ";
	cin.getline(emailadd, size);
	outfile << emailadd << endl;

	outfile.close();

	//The following statements are displayed to inform user that hey have successfully registered as a member
	cout << endl << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << "You have successfully registered as a member of our restaurant" << endl;
	cout << "Now you will be transfer to the main page and you're required to login as member to make your order" << endl;
	cout << "Thank you!!" << endl;
	cout << "________________________________________________________________________________" << endl;
	system("pause");
	system("CLS");
	main();
}

/* This is the function for the user to view their user profile */

void viewprofile(char filename[], int sizefn)
{

	fstream infile;
	char username[size], pw[size], name[size], ic[size], add[size], hp[size], emailadd[size];
	infile.open(filename, ios::in);

	infile.getline(username, size);
	infile.getline(pw, size);
	infile.getline(name, size);
	cout << "Name: " << name << endl << endl;
	infile.getline(ic, size);
	cout << "I/C Number (Without dash): " << ic << endl << endl;
	infile.getline(add, size);
	cout << "Delivery Address: " << add << endl << endl;
	infile.getline(hp, size);
	cout << "Contact Number (Without dash): " << hp << endl << endl;
	infile.getline(emailadd, size);
	cout << "E-mail Address: " << emailadd << endl << endl;
	infile.close();

	system("pause");
}

/* This is the function for the user to update their informations in the profile */

void updateprofile(char filename[], int sizefn)
{
	cin.ignore();
	system("CLS");

	fstream outfile;
	char txt[] = ".txt";
	char username[size], pw[size], name[size], ic[size], add[size], hp[size], emailadd[size];
	bool tfname = true, tfic = true, tfhp = true;

	cout << "Please enter username: ";
	cin.getline(username, size);
	strcpy(filename, username);
	strcat(filename, txt); //username entered by the user is joined with string "txt" for read file purpose

	outfile.open(filename, ios::out); //user file is open to ready to save datas
	outfile << username << endl;

	cout << "Please enter password: ";
	cin.getline(pw, size);
	outfile << pw << endl;

	do
	{
		cout << "Please enter your name(Only alphabet): ";
		cin.getline(name, size);
		for (int i = 0; i<strlen(name); i++)
		{
			if (!isalpha(name[i]))//to check whether is alphabet
			{
				if (name[i] == ' ')
				{
					continue;//if space, it will continue checking
				}
				tfname = false;
				cout << "Invalid name. Please key in only alphabet." << endl;
				break;
			}
			tfname = true;
		}
	} while (tfname == false);
	outfile << name << endl;

	do
	{
		cout << "Please enter I/C Number (Without dash): ";
		cin.getline(ic, size);
		for (int i = 0; i<strlen(ic); i++)
		{
			if (!isdigit(ic[i]))//to check whether is number
			{
				tfic = false;
				cout << "Invalid I/C. Please key in only numbers." << endl;
				break;
			}
			tfic = true;
		}
	} while (tfic == false);
	outfile << ic << endl;

	cout << "Please enter Address: ";
	cin.getline(add, size);
	outfile << add << endl;

	do
	{
		cout << "Please enter contact number (Without dash): ";
		cin.getline(hp, size);
		for (int i = 0; i<strlen(hp); i++)
		{
			if (!isdigit(hp[i]))//to check whether is number
			{
				tfhp = false;
				cout << "Invalid contact number. Please key in only numbers." << endl;
				break;
			}
			tfhp = true;
		}
	} while (tfhp == false);
	outfile << hp << endl;

	cout << "Please enter E-mail Address: ";
	cin.getline(emailadd, size);
	outfile << emailadd << endl;

	outfile.close();
}

/* This is the function for a user to check their order history */

void orderhistory(char filename[], int sizefn)
{
	fstream infile;
	char username[size], pw[size], name[size], ic[size], add[size], hp[size], emailadd[size];
	string orderdetail;
	infile.open(filename, ios::in); //file is open to ready

	infile.getline(username, size);
	infile.getline(pw, size);
	infile.getline(name, size);
	infile.getline(ic, size);
	infile.getline(add, size);
	infile.getline(hp, size);
	infile.getline(emailadd, size);
	while (!infile.eof()) //informations will get continuous reading until the end of file
	{
		getline(infile, orderdetail);
		cout << orderdetail << endl;
	}
	infile.close();
	system("pause");
}

/* This is the function for the user to make their food orders */

void orderpage(char filename[], int sizefn)
{
	int choice;
	int quan1 = 0, quan2 = 0, quan3 = 0, quan4 = 0, quan5 = 0, quan6 = 0, quana = 0, quanb = 0, quanc = 0, quand = 0;

	cout << "1) A La Carte" << endl;
	cout << "2) Combo" << endl;
	cout << "Please choose the type of order you want to make:";
	cin >> choice;
	system("cls");

	switch (choice) //choice from user is compared to proceed the following steps
	{
	case 1: //informations of available food choices are displayed for the user to choose
		cout << "A La Carte :" << endl;
		cout << "*If spend more than RM30.00 will get 5% of discount of total expenses." << endl;
		cout << "*If spend more than RM50.00 will get 10% of discount of total expenses." << endl << endl;
		cout << setw(35) << left << "Menu" << setw(10) << left << "Price" << setw(10) << endl;

		cout << setw(35) << left << f1 << setw(10) << "RM 6.00" << setw(10) << endl;

		cout << setw(35) << left << f2 << setw(10) << "RM 6.00" << setw(10) << endl;

		cout << setw(35) << left << f3 << setw(10) << "RM 4.50" << setw(10) << endl;

		cout << setw(35) << left << f4 << setw(10) << "RM 5.50" << setw(10) << endl;

		cout << setw(35) << left << f5 << setw(10) << "RM 3.00" << setw(10) << endl;

		cout << setw(35) << left << f6 << setw(10) << "RM 2.00" << setw(10) << endl;

		//quantity for each type of food is get from user
		cout << "Please Enter The Quantity for Youce Choice(s):" << endl;
		cout << "Reminder: If you are not choosing for that particular choice, please enter '0' for the quantity." << endl;
		cout << "Quantity For Choice 1: ";
		cin >> quan1;
		cout << endl;
		cout << "Quantity For Choice 2: ";
		cin >> quan2;
		cout << endl;
		cout << "Quantity For Choice 3: ";
		cin >> quan3;
		cout << endl;
		cout << "Quantity For Choice 4: ";
		cin >> quan4;
		cout << endl;
		cout << "Quantity For Choice 5: ";
		cin >> quan5;
		cout << endl;
		cout << "Quantity For Choice 6: ";
		cin >> quan6;
		cout << endl;
		break;
	case 2: //available food choices are displayed for user to choose
		cout << "Combo:" << endl;
		cout << "*If spend more than RM30.00 will get 5% of discount of total expenses." << endl;
		cout << "*If spend more than RM50.00 will get 10% of discount of total expenses." << endl << endl;
		cout << setw(35) << left << "Menu(Combo Set)" << setw(10) << left << "Price" << setw(10) << endl;

		cout << setw(35) << left << c1 << setw(10) << left << "RM 9.50" << endl;
		cout << "Description: BBQ Chicken Chop Rice + French Fries + Soft Drink" << endl << endl;

		cout << setw(35) << left << c2 << setw(10) << left << "RM 9.00" << endl;
		cout << "Description: Tomato Sauce Spaghetti + Mushroom Soup + Soft Drink" << endl << endl;

		cout << setw(35) << left << c3 << setw(10) << left << "RM 8.00" << endl;
		cout << "Description: Potato Salad Rice + French Fries + Soft Drink" << endl << endl;

		cout << setw(35) << left << c4 << setw(10) << left << "RM 12.00" << endl;
		cout << "Description: Chicken Burger + French Fries + Mushroom Soup + Soft Drink" << endl << endl;

		//quantity for each type of food is asked from the user
		cout << "Please Enter The Quantity for Youce Choice(s):" << endl;
		cout << "Reminder: If you are not choosing for that particular combo set, please enter '0' for the quantity." << endl;
		cout << "Quantity For Combo A: ";
		cin >> quana;
		cout << endl;
		cout << "Quantity For Combo B: ";
		cin >> quanb;
		cout << endl;
		cout << "Quantity For Combo C: ";
		cin >> quanc;
		cout << endl;
		cout << "Quantity For Combo D: ";
		cin >> quand;
		cout << endl;
		break;
	default: //error message is displayed when the user entered an invalid choice
		cout << "You have entered an invalid choice, please try again.Thank you." << endl;
		orderpage(filename, sizefn);
		break;
	}
	cout << "Press Enter to review your order. Thank you!!" << endl;
	system("pause");
	system("cls");
	review(quan1, quan2, quan3, quan4, quan5, quan6, quana, quanb, quanc, quand, filename, sizefn);

}

/* This is the function to display the users' orders for them to confirm their orders */

void review(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, char filename[], int sizefn)
{
	char confirm;
	double total1, discount, total2;

	//all the ordered informations will be showed for the user to confirm their order
	if (quan1 != 0 && quan1 >= 0)
	{
		cout << setw(35) << left << "Black Paper Chicken Chop Rice" << setw(6) << "x " << quan1 << endl << endl;
	}
	if (quan2 != 0 && quan2 >= 0)
	{
		cout << setw(35) << left << "BBQ Chicken Chop Rice" << setw(6) << "x " << quan2 << endl << endl;
	}
	if (quan3 != 0 && quan3 >= 0)
	{
		cout << setw(35) << left << "Potato Salad Rice" << setw(6) << "x " << quan3 << endl << endl;
	}
	if (quan4 != 0 && quan4 >= 0)
	{
		cout << setw(35) << left << "Chicken Burger" << setw(6) << "x " << quan4 << endl << endl;
	}
	if (quan5 != 0 && quan5 >= 0)
	{
		cout << setw(35) << left << "French Fries" << setw(6) << "x " << quan5 << endl << endl;
	}
	if (quan6 != 0 && quan6 >= 0)
	{
		cout << setw(35) << left << "Soft Drink - 100Plus" << setw(6) << "x " << quan6 << endl << endl;
	}
	if (quana != 0 && quana >= 0)
	{
		cout << setw(35) << left << "Combo A" << setw(6) << "x " << quana << endl;
		cout << "Description: BBQ Chicken Chop Rice + French Fries + Soft Drink" << endl << endl;
	}
	if (quanb != 0 && quanb >= 0)
	{
		cout << setw(35) << left << "Combo B" << setw(6) << "x " << quanb << endl;
		cout << "Description: Tomato Sauce Spaghetti + Mushroom Soup + Soft Drink" << endl << endl;
	}
	if (quanc != 0 && quanc >= 0)
	{
		cout << setw(35) << left << "Combo C" << setw(6) << "x " << quanc << endl;
		cout << "Description: Potato Salad Rice + French Fries + Soft Drink" << endl << endl;
	}
	if (quand != 0 && quand >= 0)
	{
		cout << setw(35) << left << "Combo D" << setw(6) << "x " << quand << endl;
		cout << "Description: Chicken Burger + French Fries + Mushroom Soup + Soft Drink" << endl << endl;
	}

	cout << "Are you confirm this is your order?(Y/N)" << endl;
	cout << "*Enter 'N/n' you will be able to reenter quantity for your order" << endl;
	cin >> confirm;
	cin.ignore();
	system("cls");

	switch (confirm) //choice is compared from the user's input to execute following statements
	{
	case 'Y':
	case 'y': //total amount of purchasing are showed to the user after they confirm their orders
		calculations(quan1, quan2, quan3, quan4, quan5, quan6, quana, quanb, quanc, quand, total1, total2, discount);
		cout << fixed << setprecision(2) << setw(35) << left << "Your total purchased is:" << setw(15) << right << "RM" << total1 << endl;
		cout << fixed << setprecision(2) << setw(35) << left << "Your discount is:" << setw(15) << right << "RM" << discount << endl;
		cout << fixed << setprecision(2) << setw(35) << left << "Your purchased after discount is:" << setw(15) << right << "RM" << total2 << endl;
		system("pause");
		system("cls");
		payment(quan1, quan2, quan3, quan4, quan5, quan6, quana, quanb, quanc, quand, total2, discount, filename, sizefn);
		break;
	case 'N':
	case 'n': //user is allowed to enter the quantity for food orders after found out there is something wrong with their orders
		cout << "Your order has been cancelled, you may now reenter your puchases. thank you!" << endl;
		system("pause");
		orderpage(filename, sizefn);
	default: //error message is displayed when the user entered an invalid input
		cout << "You have entered an invalid choice, please try again!";
		system("pause");
		system("cls");
		review(quan1, quan2, quan3, quan4, quan5, quan6, quana, quanb, quanc, quand, filename, sizefn);
		break;
	}

}

/* This is the function where the calculations is performed for sales, total sales, discount */

void calculations(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, double &total1, double &total2, double &discount)
{
	double amt1, amt2, amt3, amt4, amt5, amt6, amta, amtb, amtc, amtd;

	//following are the amount of purchasing for each type of food
	amt1 = quan1 * 6.0;
	amt2 = quan2 * 6.0;
	amt3 = quan3 * 4.5;
	amt4 = quan4 * 5.5;
	amt5 = quan5 * 3.0;
	amt6 = quan6 * 2.0;
	amta = quana * 9.5;
	amtb = quanb * 9.0;
	amtc = quanc * 8.0;
	amtd = quand * 12.0;
	total1 = amt1 + amt2 + amt3 + amt4 + amt5 + amt6 + amta + amtb + amtc + amtd; //total sales are calculated

	if (total1<30) //conditions are set for calculating discount purpose
	{
		discount = 0;
		total2 = total1 - 0;
	}
	if (total1 >= 30 && total1<50)
	{
		discount = total1 * 0.05;
		total2 = total1 - discount;
	}
	if (total1 >= 50)
	{
		discount = total1 * 0.1;
		total2 = total1 - discount;
	}
}

/* This is the function for the user to choose their way of payment */

void payment(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, double total2, double discount, char filename[], int sizefn)
{
	fstream infile;
	char paymentchoice, detail[size];

	cout << "Which way you want to pay?" << endl << endl << endl << endl;
	cout << "(A) Cash on Date" << setw(35) << "(B) Credit card" << endl;
	cin >> paymentchoice;

	switch (paymentchoice) //way of payment is get from the user to proceed
	{
	case'a':
	case'A':
		system("CLS");
		receipt(quan1, quan2, quan3, quan4, quan5, quan6, quana, quanb, quanc, quand, total2, discount, filename, sizefn);
		break;
	case'b':
	case'B':
		system("CLS");
		creditcard(quan1, quan2, quan3, quan4, quan5, quan6, quana, quanb, quanc, quand, total2, discount, filename, sizefn);
		break;
	default: //error message is displayed when the user key in an invalid input
		cout << "Invalid choice... Please key in again..." << endl;
		break;
		system("CLS");
		payment(quan1, quan2, quan3, quan4, quan5, quan6, quana, quanb, quanc, quand, total2, discount, filename, sizefn);
		system("pause");
	}
}

/* This is the function when user choose to pay with credit card */

void creditcard(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, double total2, double discount, char filename[], int sizefn)
{
	string fullname, creditno;
	cout << "Please key in your full name: ";
	getline(cin, fullname);
	cin.ignore();
	cout << endl;
	cout << "Please key in 10 digit credit card number: ";
	getline(cin, creditno);
	cin.ignore();
	system("CLS");
	receipt(quan1, quan2, quan3, quan4, quan5, quan6, quana, quanb, quanc, quand, total2, discount, filename, sizefn);
	system("pause");
}

/* This is the function to show the receipt to show the overall orders and thanks user for the orders after all the purchasing processes */

void receipt(int quan1, int quan2, int quan3, int quan4, int quan5, int quan6, int quana, int quanb, int quanc, int quand, double total2, double discount, char filename[], int sizefn)
{
	fstream outfile;
	char feedbackchoice;

	//thank you messages are displayed to thank the user for making purchases
	cout << "Dear Customer, Thank You for Making Purchases from CinCai Restaurant" << endl;
	cout << "We Appreciate Your Purchases from Our Restaurant" << endl;
	cout << "Hope You Will Enjoy Your Meal..." << endl;
	cout << "If You Have Any Comment On Our Service, You May Proceed to The Feedback Page to Leave Your Comment." << endl;
	cout << "Thank You Very Much and Have A Nice Day!" << endl;
	cout << "********************************************************************************" << endl;

	outfile.open(filename, ios::out | ios::app); //file is opened to save all the purchase informations
	cout << setw(35) << left << "Payment Description" << setw(23) << right << "Price" << endl << endl;
	outfile << setw(35) << left << "Payment Description" << setw(23) << right << "Price" << endl << endl;
	if (quan1 != 0 && quan1 >= 0)
	{
		cout << setw(35) << left << "Black Paper Chicken Chop Rice " << " x " << quan1 << setw(15) << right << "RM " << quan1*6.00 << endl << endl;
		outfile << setw(35) << left << "Black Paper Chicken Chop Rice " << " x " << quan1 << setw(15) << right << "RM " << quan1*6.00 << endl << endl;
	}
	if (quan2 != 0 && quan2 >= 0)
	{
		cout << setw(35) << left << "BBQ Chicken Chop Rice " << " x " << quan2 << setw(15) << right << "RM " << quan2*6.00 << endl << endl;
		outfile << setw(35) << left << "BBQ Chicken Chop Rice " << " x " << quan2 << setw(15) << right << "RM " << quan2*6.00 << endl << endl;
	}
	if (quan3 != 0 && quan3 >= 0)
	{
		cout << setw(35) << left << "Potato Salad Rice " << " x " << quan3 << setw(15) << right << "RM " << quan3*4.50 << endl << endl;
		outfile << setw(35) << left << "Potato Salad Rice " << " x " << quan3 << setw(15) << right << "RM " << quan3*4.50 << endl << endl;
	}
	if (quan4 != 0 && quan4 >= 0)
	{
		cout << setw(35) << left << "Chicken Burger " << " x " << quan4 << setw(15) << right << "RM " << quan4*5.50 << endl << endl;
		outfile << setw(35) << left << "Chicken Burger " << " x " << quan4 << setw(15) << right << "RM " << quan4*5.50 << endl << endl;
	}
	if (quan5 != 0 && quan5 >= 0)
	{
		cout << setw(35) << left << "French Fries " << " x " << quan5 << setw(15) << right << "RM " << quan5*3.00 << endl << endl;
		outfile << setw(35) << left << "French Fries " << " x " << quan5 << setw(15) << right << "RM " << quan5*3.00 << endl << endl;
	}
	if (quan6 != 0 && quan6 >= 0)
	{
		cout << setw(35) << left << "Soft Drink - 100Plus " << " x " << quan6 << setw(15) << right << "RM " << quan6*2.00 << endl << endl;
		outfile << setw(35) << left << "Soft Drink - 100Plus " << " x " << quan6 << setw(15) << right << "RM " << quan6*2.00 << endl << endl;
	}
	if (quana != 0 && quana >= 0)
	{
		cout << setw(35) << left << "Combo A " << " x " << quana << setw(15) << right << "RM " << quana*9.50 << endl << endl;
		outfile << setw(35) << left << "Combo A " << " x " << quana << setw(15) << right << "RM " << quana*9.50 << endl << endl;
	}
	if (quanb != 0 && quanb >= 0)
	{
		cout << setw(35) << left << "Combo B " << " x " << quanb << setw(15) << right << "RM " << quanb*9.00 << endl << endl;
		outfile << setw(35) << left << "Combo B " << " x " << quanb << setw(15) << right << "RM " << quanb*9.00 << endl << endl;
	}
	if (quanc != 0 && quanc >= 0)
	{
		cout << setw(35) << left << "Combo C " << " x " << quanc << setw(15) << right << "RM " << quanc*8.00 << endl << endl;
		outfile << setw(35) << left << "Combo C " << " x " << quanc << setw(15) << right << "RM " << quanc*8.00 << endl << endl;
	}
	if (quand != 0 && quand >= 0)
	{
		cout << setw(35) << left << "Combo D " << " x " << quand << setw(15) << right << "RM " << quand*12.00 << endl << endl;
		outfile << setw(35) << left << "Combo D " << " x " << quand << setw(15) << right << "RM " << quand*12.00 << endl << endl;
	}
	cout << setw(35) << left << "Discount " << setw(19) << right << "RM " << discount << endl << endl;
	outfile << setw(35) << left << "Discount " << setw(19) << right << "RM " << discount << endl << endl;
	cout << "________________________________________________________________________________" << endl;
	outfile << "________________________________________________________________________________" << endl;
	cout << setw(35) << left << "Total price " << setw(19) << right << "RM " << total2 << endl;
	outfile << setw(35) << left << "Total price " << setw(19) << right << "RM " << total2 << endl;
	cout << "________________________________________________________________________________" << endl << endl;
	outfile << "________________________________________________________________________________" << endl << endl;
	outfile.close(); //file is closed after all the necessary informations are saved
	cin.ignore(100, '\n');
	cout << "Do you want to leave us some feedback? Press Y if want or Press any key to exit.." << endl;
	cin >> feedbackchoice;
	system("pause");
	if (feedbackchoice == 'Y' || feedbackchoice == 'y')
	{
		cin.ignore();
		system("CLS");
		feedback(); //feedback() function is called for the user to enter their comments 
	}
	else
	{
		exit(0); //the program will be ended if the user don't have any feedback
	}


}

/* This is the function where the feedback from users is recorded */

void feedback()
{
	fstream outfile;
	string feedback;
	char choice;

	outfile.open("feedback.txt", ios::out | ios::app); //file is opened to save user's feedbacks

	cout << "To our dearest customer, if you have any dissatisfaction, please leave us some precious opinion to let us improve. Thanks for your coorperation:" << endl << endl;
	getline(cin, feedback);
	outfile << feedback << endl << endl;
	outfile << "********************************************************************************" << endl;
	outfile.close(); //file is closed after saving user's feedbacks

	cout << "Do You Want To make another order?(Y/N)" << endl;
	cin >> choice;

	if (choice == 'Y' || choice == 'y')
	{
		system("CLS");
		main(); //main() functions is called if the user want to make another purchase
	}
	else
	{
		exit(0); //program will be ended if the user don't want to make another purchase
	}

	system("pause");
}