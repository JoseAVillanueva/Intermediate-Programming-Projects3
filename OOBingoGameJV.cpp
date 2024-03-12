//Jose Villanueva Vigil
//COSC 1437
//Program set 3, problem 2 (OOBingoGame)
//For references, I used the PDF covering program set 3

#include <iostream>
#include <iomanip>
#include <string>
#include <random>

using namespace std;


class BingoCards
{
private:

    //the private member variables are used to create a new Bingo card
    //for a player
    //there is a bool (Winner) to indicate if a player has won
    //a 2-D array of string value
    //and 2 strings (PlayerName and WinMsg)
    //which help to retrieve data for a player and their win status
    bool Winner = false;
	string BingoCard[5][5];
	string PlayerName;
    string WinMsg;

public:

    //the setPlayerName function is used to set a players name
	void setPlayerName(string s)
	{
		PlayerName = s;
	}

    //the setBingoCard function is used to change a given value within a player's bingo card
    void setBingoCard(int i, int i2, string s)
    {
        BingoCard[i][i2] = s;
    }

    //the setWinner function is used to change the win status of a player
    void setWinner(bool s)
    {
        Winner = s;
    }

    //the setWinMsg function is used to set the win message for a player
    void setWinMsg(string s)
    {
        WinMsg = s;
    }

    //the getPlayerName function is used to return a player's name
	string getPlayerName() const
	{
		return PlayerName;
	}

    //the getBingoCard function is used to format and display the contents of a players bingo card
    void getBingoCard() const
    {
        cout << "--------------------------" << endl;
        for (int i = 0; i < 5; i++)
        {
            for (int i2 = 0; i2 < 5; i2++)
            {
                //if any of the players values are less than 1 digit, then the
                //value is formated with an extra space
                if (BingoCard[i][i2] == "1" ||
                    BingoCard[i][i2] == "2" ||
                    BingoCard[i][i2] == "3" ||
                    BingoCard[i][i2] == "4" ||
                    BingoCard[i][i2] == "5" ||
                    BingoCard[i][i2] == "6" ||
                    BingoCard[i][i2] == "7" ||
                    BingoCard[i][i2] == "8" ||
                    BingoCard[i][i2] == "9" ||
                    BingoCard[i][i2] == "X")
                {
                    cout << "|  " << BingoCard[i][i2] << " ";
                }

                //if the value is anything but 1 digit, then the value is fomrated without the additional space
                else
                {
                    cout << "| " << BingoCard[i][i2] << " ";
                }
            }
            cout << "| " << endl;
        }
        cout << "--------------------------" << endl;
    }

    //the getBingoSquare function is used to return a single bingo square
    string getBingoSquare(int i, int i2) const
    {
        return BingoCard[i][i2];
    }

    //the getWinner function is used to return the bool Winner 
    //to determine a winner (this is done later in the program)
    bool getWinner() const
    {
        return Winner;
    }

    //the getWinMsg is used to return a player's win message
    string getWinMsg() const
    {
        return WinMsg;
    }

};

void RandomCard(BingoCards[], int);
void RandomNumbers(BingoCards[], int, int);
void PatternChecker(BingoCards[], int);

int main()
{
    int GameMode = 0;

    BingoCards* Bptr;
    int NumPlayers = 2;

    string Name1 = "Human";
    string Name2 = "Computer";
    
    //a pointer with the data type of BingoCards is used to create 
    //two valid Bingo Cards
    Bptr = new BingoCards[NumPlayers];
    Bptr[0].setPlayerName(Name1);
    Bptr[1].setPlayerName(Name2);

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "IMPORTANT NOTICE: When entering bingo numbers, please avoid using" << endl;
    cout << "lowercase characters as the program does not accept lowercase characters" << endl;
    cout << "Example: b1, b13, o74" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << "To play Demo mode, enter 1." << endl;
    cout << "To play Game mode, enter 2." << endl;
    cout << "To exit the program, enter 3." << endl;
    cout << "Enter choice : ";
    cin >> GameMode;

    //this checks for a valid game input, if the input is invalid then 
    //an error message is displayed until a valid choice is made
    while (GameMode != 1 && GameMode != 2 && GameMode != 3)
    {
        cout << "An invalid choice was made, please try again." << endl;
        cout << "To play Demo mode, enter 1." << endl;
        cout << "To play Game mode, enter 2." << endl;
        cout << "To exit the program, enter 3." << endl;
        cout << "Enter choice : ";
        cin >> GameMode;
    }
    
    //if the mode entered is 1, then the player will be sent into demo mode
    //where they will have to input the bingo numbers manually 
    if (GameMode == 1)
    {
        for (int i = 0; i < NumPlayers; i++)
        {
            cout << Bptr[i].getPlayerName() << endl;
            RandomCard(Bptr, i);
            Bptr[i].getBingoCard();
            cout << " " << endl;
        }

        while (Bptr[0].getWinner() == false && Bptr[1].getWinner() == false)
        {
            RandomNumbers(Bptr, NumPlayers, GameMode);
            PatternChecker(Bptr, 0);
            PatternChecker(Bptr, 1);
        }

    }

    //if the mode entered is 2, then the player is sent into game mode
    //where the program will assign the two Bingo Cards random bingo numbers
    else if (GameMode == 2)
    {
        for (int i = 0; i < NumPlayers; i++)
        {
            cout << Bptr[i].getPlayerName() << endl;
            RandomCard(Bptr, i);
            Bptr[i].getBingoCard();
            cout << " " << endl;
        }

        while (Bptr[0].getWinner() == false && Bptr[1].getWinner() == false)
        {
            RandomNumbers(Bptr, NumPlayers, GameMode);
            PatternChecker(Bptr, 0);
            PatternChecker(Bptr, 1);
        }
    }

    //if the mode entered is 3, then the program will terminate 
    else if (GameMode == 3)
    {
        return 0;
    }

    //the following if statments are used to display a winner

    //if the first player won, then the player 1 win message is displayed
    if (Bptr[0].getWinner() == true)
    {
        cout << " " << endl;
        Bptr[0].getBingoCard();
        cout << "CONGRATULATIONS " << Bptr[0].getPlayerName() << " you WON!" << endl;
        cout << Bptr[0].getWinMsg() << endl;
    }

    //if the second player won, then the player 2 win message is displayed
    else if (Bptr[1].getWinner() == true)
    {
        cout << " " << endl;
        Bptr[1].getBingoCard();
        cout << "CONGRATULATIONS " << Bptr[1].getPlayerName() << " you WON!" << endl;
        cout << Bptr[1].getWinMsg() << endl;
    }

	return 0;
}

/*-------------------------------------------------

The RandomCard function is used to populate a
a player's bingo card with random values that range
from 1-75, with no reoccuring values

-------------------------------------------------*/

void RandomCard(BingoCards s[], int x)
{
    bool flag = false;

    int checker = 0;
    int Num2;
    //these arrays are used to help assign a random value to each slot 
    string NUMBERS1[16] = { "X", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", };
    string NUMBERS2[16] = { "X", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", };
    string NUMBERS3[16] = { "X", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", };
    string NUMBERS4[16] = { "X", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", };
    string NUMBERS5[16] = { "X", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", };

    //min and max for a random number
    const int Min_One = 1;
    const int Max_Two = 15;

    //creating a random numbers genertor to get the numbers
    //needed to get a random card
    random_device engine;
    uniform_int_distribution<int> RandomNUMBER(Min_One, Max_Two);
        
        //all of the for loops below this comment are used
        //to assign a vlue to each bingo square, the for loops
        //also ensure that there are no duplicate values in a 
        //given bingo card
        for (int i2 = 0; i2 < 5; i2++)
        {
            Num2 = RandomNUMBER(engine);

            while (flag != true)
            {
                for (int i3 = 0; i3 < 5; i3++)
                {
                    if (s[x].getBingoSquare(i3, 0) == NUMBERS1[Num2])
                    {
                        checker++;
                    }
                }
                if (checker >= 1)
                {
                    Num2 = RandomNUMBER(engine);
                    checker = 0;
                }
                else if (checker == 0)
                {
                    s[x].setBingoCard(i2, 0, NUMBERS1[Num2]);
                    flag = true;
                }
            }
            flag = false;
        }

        for (int i2 = 0; i2 < 5; i2++)
        {
            Num2 = RandomNUMBER(engine);

            while (flag != true)
            {
                for (int i3 = 0; i3 < 5; i3++)
                {
                    if (s[x].getBingoSquare(i3, 1) == NUMBERS2[Num2])
                    {
                        checker++;
                    }
                }
                if (checker >= 1)
                {
                    Num2 = RandomNUMBER(engine);
                    checker = 0;
                }
                else if (checker == 0)
                {
                    s[x].setBingoCard(i2, 1, NUMBERS2[Num2]);
                    flag = true;
                }
            }
            flag = false;
        }

        for (int i2 = 0; i2 < 5; i2++)
        {
            Num2 = RandomNUMBER(engine);

            while (flag != true)
            {
                for (int i3 = 0; i3 < 5; i3++)
                {
                    if (s[x].getBingoSquare(i3, 2) == NUMBERS3[Num2])
                    {
                        checker++;
                    }
                }
                if (checker >= 1)
                {
                    Num2 = RandomNUMBER(engine);
                    checker = 0;
                }
                else if (checker == 0)
                {
                    s[x].setBingoCard(i2, 2, NUMBERS3[Num2]);
                    flag = true;
                }
            }
            flag = false;
        }

        for (int i2 = 0; i2 < 5; i2++)
        {
            Num2 = RandomNUMBER(engine);

            while (flag != true)
            {
                for (int i3 = 0; i3 < 5; i3++)
                {
                    if (s[x].getBingoSquare(i3, 3) == NUMBERS4[Num2])
                    {
                        checker++;
                    }
                }
                if (checker >= 1)
                {
                    Num2 = RandomNUMBER(engine);
                    checker = 0;
                }
                else if (checker == 0)
                {
                    s[x].setBingoCard(i2, 3, NUMBERS4[Num2]);
                    flag = true;
                }
            }
            flag = false;
        }

        for (int i2 = 0; i2 < 5; i2++)
        {
            Num2 = RandomNUMBER(engine);

            while (flag != true)
            {
                for (int i3 = 0; i3 < 5; i3++)
                {
                    if (s[x].getBingoSquare(i3, 4) == NUMBERS5[Num2])
                    {
                        checker++;
                    }
                }
                if (checker >= 1)
                {
                    Num2 = RandomNUMBER(engine);
                    checker = 0;
                }
                else if (checker == 0)
                {
                    s[x].setBingoCard(i2, 4, NUMBERS5[Num2]);
                    flag = true;
                }
            }
            flag = false;
        }

        //this sets the free space for the middle square
        s[x].setBingoCard(2, 2, "X");
}

/*-------------------------------------------------

The RandomNumbers function is used to search/validate
a given value from the program or from a player, if 
either values are true(and the value is found
on a player's card), then the square will be marked
with an X

-------------------------------------------------*/

void RandomNumbers(BingoCards s[], int x, int mode)
{
    bool flag = false;

    int checker = 0;
    string Value;

    int Num2;
    int Num1;

    string BINGO[5] = { "B","I","N","G","O" };
    //these arrays are used to help assign a random value to each slot 
    string NUMBERS[16][5] =   {"X", "X", "X", "X", "X",
                                "1", "16","31","46","61",
                                "2", "17","32","47","62",
                                "3", "18","33","48","63",
                                "4", "19","34","49","64",
                                "5", "20","35","50","65",
                                "6", "21","36","51","66",
                                "7", "22","37","52","67",
                                "8", "23","38","53","68",
                                "9", "24","39","54","69",
                                "10","25","40","55","70",
                                "11","26","41","56","71",
                                "12","27","42","57","72",
                                "13","28","43","58","73",
                                "14","29","44","59","74",
                                "15","30","45","60","74"};
    //min and max for a random number

    const int Min_One = 0;
    const int Max_One = 4;

    const int Min_Two = 1;
    const int Max_Two = 15;

    random_device engine;
    uniform_int_distribution<int> Rone(Min_One, Max_One);
    uniform_int_distribution<int> Rtwo(Min_Two, Max_Two);

    //the following nested for loop is used to randomly call out bingo numbers 
    if (mode == 2)
    {


        Num1 = Rone(engine);
        Num2 = Rtwo(engine);

        cout << "Enter A Number: " << BINGO[Num1] + NUMBERS[Num2][Num1] << endl;

        //this for loop is used to move through the player's array
        for (int i = 0; i < x; i++)
        {
            //the next two for loops are used to move through a players bingo card
            for (int i2 = 0; i2 < 5; i2++)
            {
                for (int i3 = 0; i3 < 5; i3++)
                {
                    //if the given value is found in the players card
                    //then the value is change to an X
                    if (NUMBERS[Num2][Num1] == s[i].getBingoSquare(i3, i2))
                    {
                        s[i].setBingoCard(i3, i2, "X");
                    }
                }
            }
        }
    }

    //the following for loop is used to manually enter in bingo numbers
    else if (mode == 1)
    {
        cout << "Enter A Bingo Number: ";
        cin >> Value;

        //the while loop checks for a valid bingo number, while the flag is not true
        //then the while loop will continue to repeat
        while (flag != true)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int i2 = 0; i2 < 16; i2++)
                {

                    //if the value found is a valid bingo number option
                    //then the values are saved into num1 and num2
                    //and the flag is changed to true
                    if (Value == BINGO[i] + NUMBERS[i2][i])
                    {
                        flag = true;
                        Num1 = i;
                        Num2 = i2;
                    }
                }
            }

            if (flag == false)
            {
                cout << "An invalid value was entered, please try again." << endl;
                cout << "Enter A Bingo Number: ";
                cin >> Value;
            }
        }

        //the nested for loops are used to look for the given bingo number in a player's card
        for (int i = 0; i < x; i++)
        {
            for (int i2 = 0; i2 < 5; i2++)
            {
                for (int i3 = 0; i3 < 5; i3++)
                {
                    //if the given value matches a value on the players card
                    //then the value is changed to an X
                    if (NUMBERS[Num2][Num1] == s[i].getBingoSquare(i3, i2))
                    {
                        s[i].setBingoCard(i3, i2, "X");
                    }
                }
            }
        }
    }
}

/*-------------------------------------------------

The PatternChecker function is used to look for
specific patterns within a given bingo card.

-There are four different patterns that the 
program searches for, if a pattern is found, then
a player's bool condition is changed to true 
and their winning message is set to indicate
that pattern they won with as well as the win 
message

-------------------------------------------------*/

void PatternChecker(BingoCards s[], int x)
{
    int counter = 0;
    string BINGO;


    //this for loop is used to search for a (-)
    //in the player's bingo card
    for (int i = 0; i < 5; i++)
    {
        //if a value is found within that square then the counter is incremented 
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (s[x].getBingoSquare(i, i2) == "X")
            {
                counter++;
            }
        }

        //if the counter's value is 5, then the conditions for a win are met
        //and the player's win status is changed to indicate that they won
        if (counter == 5)
        {
            s[x].setWinner(true);
            BINGO = s[x].getPlayerName() + " won with a - pattern!";
            s[x].setWinMsg(BINGO);
        }

        counter = 0;
    }

    //this for loop is used to search for a (|)
    //in the player's bingo card
    for (int i = 0; i < 5; i++)
    {

        //if a value is found within that square then the counter is incremented 
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (s[x].getBingoSquare(i2, i) == "X")
            {
                counter++;
            }
        }
       
        //if the counter's value is 5, then the conditions for a win are met
        //and the player's win status is changed to indicate that they won
        if (counter == 5)
        {
            s[x].setWinner(true);
            BINGO = s[x].getPlayerName() + " won with a | pattern!";
            s[x].setWinMsg(BINGO);
        }

        counter = 0;
    }

    //this if statement is used to search for a (\) or a (/)
    //in the player's bingo card
    if((s[x].getBingoSquare(0,0) == "X" &&
        s[x].getBingoSquare(1,1) == "X" &&
        s[x].getBingoSquare(2,2) == "X" && 
        s[x].getBingoSquare(3,3) == "X" &&
        s[x].getBingoSquare(4,4) == "X") ||
        (s[x].getBingoSquare(0, 4) == "X" &&
        s[x].getBingoSquare(1, 3) == "X" &&
        s[x].getBingoSquare(2, 2) == "X" &&
        s[x].getBingoSquare(3, 1) == "X" &&
        s[x].getBingoSquare(4, 0) == "X"))
    {
        counter = 5;

        //if the counter's value is 5, then the conditions for a win are met
        //and the player's win status is changed to indicate that they won
        if (counter == 5)
        {
            s[x].setWinner(true);

            BINGO = s[x].getPlayerName() + " won with a / pattern!";
            s[x].setWinMsg(BINGO);
        }

        counter = 0;
    }

    //this if statement is used to search for a (::)
    //in the player's bingo card
    if (s[x].getBingoSquare(0, 0) == "X" &&
        s[x].getBingoSquare(0, 4) == "X" &&
        s[x].getBingoSquare(4, 0) == "X" &&
        s[x].getBingoSquare(4, 4) == "X" )
    {
        counter = 5;

        //if the counter's value is 5, then the conditions for a win are met
        //and the player's win status is changed to indicate that they won
        if (counter == 5)
        {
            s[x].setWinner(true);
            BINGO = s[x].getPlayerName() + " won with a :: pattern!";
            s[x].setWinMsg(BINGO);
        }

        counter = 0;
    }
}