#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;             // ID determining the product(product code)
    float price, dis;
    string pname;       // Name of the products
public:
    void menu();
    void adminstrator();
    void buyer();
    void add();         // To add products
    void edit();        // to add products
    void rem();
    void list();        // to list the products
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email, password;

    cout << "\t\t\t______________________________________" << endl;
    cout << "\t\t\t                                      " << endl;
    cout << "\t\t\t        Supermarket main menu         "<<endl;
    cout << "\t\t\t                                      "<<endl;
    cout << "\t\t\t______________________________________"<<endl;
    cout << "\t\t\t                                      "<<endl;

    cout << "\t\t\t| 1)Adminstrator \n";
    cout << "\t\t\t|                \n";
    cout << "\t\t\t| 2)Customer     \n";
    cout << "\t\t\t|                \n";
    cout << "\t\t\t| 3)Exit         \n";
    cout << "\t\t\t|                \n"<<endl;
    cout << "\t\t\t please select any of the option:";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "\t\t\t| You are required to login first:\n";
        cout << "Enter your email:";
        cin >> email;
        cout << "Enter your password:";
        cin >> password;

        if (email == "jayzstha15@gmail.com" && password == "passcode")
        {
            adminstrator();
        }
        else
        {
            cout << "Invalid email/password!!";
            break;
        }
    }
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please select from the given options!!!!" << endl;
    }
    }
    goto m;
}
void shopping ::adminstrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t Adminstrator menu";
    cout << "\n\t\t\t|-----1) Add the product--------|";
    cout << "\n\t\t\t|-----2) Modify the product-----|";
    cout << "\n\t\t\t|-----3) Delete the product-----|";
    cout << "\n\t\t\t|-----4) Back to the main menu--|";
    cout << "\n\n\t\t\t|---please enter your choice:";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        add();
        break;
    }
    case 2:
    {
        edit();
        break;
    }
    case 3:
    {
        rem();
        break;
    }
    case 4:
    {
        menu();
        break;
    }
    default:
        cout << "Invalid choice!!!!" << endl;
    }
    goto m;
}
void shopping ::buyer()
{
m:
    int choice;
    cout << "\t\t\t Buyer" << endl;
    cout << "\t\t\t ______________" << endl;
    cout << "\t\t\t 1) Buy product" << endl;
    cout << "\t\t\t 2) Show menu" << endl
         << endl;
    cout << "\t\t\t|---- Enter your choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        receipt();
        break;
    }
    case 2:
    {
        menu();
    }
    default:
    {
        cout << "Invalid choice!!!!!";
    }
    }
    goto m;
}
void shopping::add()
{
m:
    fstream data;
    int c=0, token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product:";
    cin >> pcode;
    cout << "\n\n\t Name of the product:";
    cin >> pname;
    cout << "\n\n\t Price of the product:";
    cin >> price;
    cout << "\n\n\t Discount on the product:";
    cin >> dis;

    data.open("Database.txt", ios::in);
    if (!data)
    {
        data.open("Database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
                token++;
            data >> c >> n >> p >> d;
        }
    }
    data.close();

    if (token == 1)
    {
        goto m;
    }
    else
    {
        data.open("Database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    cout << "\n\n\t\t\t|---Record insertion succesful-----|" << endl;
}
void shopping::edit()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "|--------Modify the product0---------|" << endl;
    cout << "\t\t\t Product code:";
    cin >> pcode;

    data.open("Database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nThe file doesnot exist!!!!";
    }
    else
    {
        data1.open("Database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product code>";
                cin >> c;
                cout << "\n\t\t Name of the product:";
                cin >> n;
                cout << "\n\t\t Price:";
                cin >> p;
                cout << "\n\t\t Discount:";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << endl;
                cout << "\n\n\n\t\t Data has been recorded...." << endl;
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("Database.txt");
        rename("Database1.txt", "Database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found!!!" << endl;
        }
    }
}
void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n \t\t Delete product" << endl;
    cout << "\n\n\t\t Enter the product code:";
    cin >> pkey;
    data.open("Database.txt", ios::in);
    if (!data)
    {
        cout << "The file doesnot exist!!!!" << endl;
    }
    else
    {
        data1.open("Database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t\tProduct deleted succesfully." << endl;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
        }
        data1.close();
        data.close();
        remove("Database.txt");
        rename("Database1.txt", "Database.txt");

        if (token == 0)
        {
            cout << "\n\n\t Record not found!!!!" << endl;
        }
    }
}
void shopping::list()
{
    fstream data;
    data.open("Database.txt", ios::in);
    cout << "\n\n|_________________________________" << endl;
    cout << "ProductNo. \t\t Name \t\t Price" << endl;
    cout << "\n\n|_________________________________" << endl;
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << price << "\t\t" << endl;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}
void shopping::receipt()
{

    fstream data;
    int arrc[100]; // array of codes
    int arrq[100]; // array of quantity
    char choice;
    int c = 0;
    float amount = 0, dis = 0;
    float total = 0;

    cout << "\n\n\t\t Receipt" << endl;
    cout << "\t\t_______________________" << endl;
    data.open("Database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database!!!!" << endl;
    }
    else
    {
        data.close();
        list();
        cout << "\n_______________________________" << endl;
        cout << "\n\n\t Please place the order:" << endl;
        cout << "\n_______________________________" << endl;
        do
        {   
            m:
            cout << "\n\t Enter the product code:";
            cin >> arrc[c];
            cout << "\n\t Enter the quantity:";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n\t Duplicate product code, Please try again!!!!" << endl;
                    goto m;
                }
            }
            c++;
            cout<<"Do you want to order again:(y/n):"<<endl;
            cin >> choice;

        } while (choice == 'y');
        cout << "\n\n\t\t\t_____________Receipt______________" << endl;
        cout << "Product no. \t Product name \t Product quantity \t Price \t Amount \t Amount after discount" << endl;

        for (int i = 0; i < c; i++)
        {
            data.open("Databse.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total += dis;
                    cout << endl
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        cout << "\n\n ___________________________________" << endl;
        cout << "Total amount : " << total;
    }
}
int main()
{
    shopping s;
    s.menu();
}