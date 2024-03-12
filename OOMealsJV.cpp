//Jose Villanueva Vigil
//COSC 1437
//Program set 3, problem 1 (OOMeals)
//For references, I used the PDF covering program set 3

#include <iostream> 
#include <string> 
#include <iomanip> 

using namespace std;

class Meals
{
private:

    //these private member variables are used to store
    //a meals name, calories, and track a daily caloric total
    string MealName;
    int Calories;
    int DailyTotal = 0;

public:

    //this public member function (default constructor) is used to create 
    //a default meal that consist of a default meal name with zero calories
    Meals()
    {
        MealName = "Default Meal";
        Calories = 0;
    }

    //this public member function (2nd default constructor) is used to create
    //a series of meals with a name and an amount of calories
    Meals(string s, int i)
    {
        MealName = s;
        Calories = i;
    }

    //this public member function is used to return a the daily amount of calories
    int getDailyTotal() const
    {
        return DailyTotal;
    }

    //here is the overloaded opertor used to add the calory values of each meal
    void operator+(const Meals &right)
    {
        int d = 0;
        d = DailyTotal + right.DailyTotal;
        DailyTotal = d;
    }


    //these are the friend functions used to call the insertion and extraction operators 
    friend ostream& operator << (ostream&, const Meals&);
    friend istream& operator >> (istream&, Meals&);

};

//this is the insertion operator  
ostream& operator << (ostream& strm, const Meals& obj)
{
    strm << "Meal Name: " << obj.MealName << endl;
    strm << "Calories: " << obj.Calories << endl;
    return strm;
}

//this is the extraction operator 
istream& operator >> (istream& strm, Meals& obj)
{
    cout << "Meal Name: ";
    strm >> obj.MealName;
    cout << "Calories: ";
    strm >> obj.Calories;

    obj.DailyTotal = obj.Calories;

    return strm;
}

//this is where the program starts 
int main()
{

    //a pointer with the data type of Meals is created
    Meals* Mptr;
    int NumMeals = 0;
    int counter1 = 0;
    int counter2 = 1;

    cout << "---------------------------------------------------------------------" << endl;
    cout << "IMPORTANT NOTICE: When entering the meal names, please use a (_)" << endl;
    cout << "to indicate a space, if you use an actual space ( ) then the" << endl;
    cout << "program will not allow you to enter in any data and will terminate" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "Enter the amount of meals you would like to enter: ";
    cin >> NumMeals;
    NumMeals = NumMeals;

    //an series of dynamically allocated arrays is created using the Mptr pointer and the NumMeals value
    Mptr = new Meals[NumMeals];


    //the for loop is used to input data for each Meal class
    //this is done using the extraction operator
    for (int i = 0; i < NumMeals; i++)
    {
        cout << "Enter the Meal's name and the Calories." << endl;
        cin >> Mptr[i];
    }

    cout << " " << endl;

    //this for loop is used to display the a Meals name's and calories
    //as well as the daily calory total
    //this is done using an insertion operator
    for (int i = 0; i < NumMeals; i++)
    {

        //the if statement is used to display the day
        if (counter1 == 0)
        {
            cout << "--------------------------------------" << endl;
            cout << "Meals for Day " << counter2 << endl;
            cout << "--------------------------------------" << endl;
        }

        //this is used to display a Meal
        cout << "Meal information for Meal " << (i + 1) << "." << endl;
        cout << Mptr[i];

        //counter is incremented
        counter1++;

        //if a counters value is three, then the last three meals are added using an
        //overloaded operator, and then the daily caloric amount is dispaleyd
        //counter is then set to zero and counter2 is incremented
        if (counter1 == 3)
        {
            Mptr[i] + Mptr[i - 1];
            Mptr[i] + Mptr[i - 2];
            cout << "--------------------------------------" << endl;
            cout << "Daily Calorie Total: ";
            cout << Mptr[i].getDailyTotal() << endl;
            cout << "--------------------------------------" << endl;
            counter1 = 0;
            counter2++;

            cout << " " << endl;
        }

        //if there is an odd number of meals(not divisible by 3)
        //then this else if statement(and the statement after this one)
        //is used to dispaly the last 1 or 2 Meals as well as their daily caloric values
        else if (counter1 == 2 && i == NumMeals - 1)
        {
            Mptr[i] + Mptr[i - 1];
            cout << "--------------------------------------" << endl;
            cout << "Daily Calorie Total: ";
            cout << Mptr[i].getDailyTotal() << endl;
            cout << "--------------------------------------" << endl;
        }
        else if (counter1 == 1 && i == NumMeals - 1)
        {
            cout << "--------------------------------------" << endl;
            cout << "Daily Calorie Total: ";
            cout << Mptr[i].getDailyTotal() << endl;
            cout << "--------------------------------------" << endl;
        }
    }
    return 0;
}