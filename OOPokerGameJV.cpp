// Author: Jose Villanueva 
// Course: COSC 1437
// Required Program
// References/Option: The poker PDF provider under the Program set 3 assignment 

#include <iostream> 
#include <string> 
#include <random> 
#include <random> 

using namespace std;

class PlayerHand
{
private:
    string PlayerName;

    //the three pointers below are used to dynamically allocate 
    //memory for three new arrays, two int array's and one string array
    string* Hand;
    int* RankValues;
    int* SuitValues;

    //the values below are used to keep track of special hand characteristics
    int handVal = 0;
    int HighCard = 0;
    int kindVal = 0;
    int kindVal2 = 0;
    int HouseVal = 0;
    int HouseVal2 = 0;
    int Total = 0;

    string HandMessage;

    //this private member function is used to create a series of new arrays
    void CreatePlayerHand()
    {
        Hand = new string[5];
        RankValues = new int[5];
        SuitValues = new int[5];
    }

public:

    //this public member function is used to create a new instacnes of the PlayerHand class
    //(this is the default constructor)
    PlayerHand()
    {
        CreatePlayerHand();
    }

    //this deconstructor is used to free the memory from the arrays
    ~PlayerHand()
    {
        delete[] Hand;
    }

    //this public member function is used to assign values to the arrays
    void setPlayerCards(int i, int a, int b, string c)
    {
        Hand[i] = c;
        RankValues[i] = a;
        SuitValues[i] = b;
    }

    //this public member function is used to assign a hand value
    void setHandVal(int i)
    {
        handVal = i;
    }

    //this public member function is used to assign a players name
    void setPlayerName(string n)
    {
        PlayerName = n;
    }

    //this public member function is used to assign a high card
    void setHighCard(int i)
    {
        HighCard = i;
    }

    //this public member function is used to assign a a hand message
    //(this will later be used to help determine a winning hand)
    void setHandMessage(string s)
    {
        HandMessage = s;
    }

    //this public member function is used to assign values for a full house
    void setHouseVal(int i, int i2)
    {
        HouseVal = i;
        HouseVal2 = i2;
    }

    //this public member function is used to assign values to any three, four, or pair hand
    void setKindVal(int i)
    {
        kindVal = i;
    }

    //this public member function is used to assign values to any two pair hand
    void setKindVals(int i, int i2)
    {
        kindVal = i;
        kindVal2 = i2;
    }

    //this public member function is used to assign a hands's total value
    void setTotal(int i)
    {
        Total = i;
    }

    //this public member function is used to return the a players name
    string getPlayerName() const
    {
        return PlayerName;
    }

    //this public member function is used to return a players hand
    void getPlayerCards() const
    {
        for (int i = 0; i < 5; i++)
        {
            cout << Hand[i] << " ";
        }
    }

    //this public member function is used to return a rank value
    int getRankValue(int i) const
    {
        return RankValues[i];
    }

    //this public member function is used to return a suit value
    int getSuitValue(int i) const
    {
        return SuitValues[i];
    }

    //this public member function is used to return a hand's value
    int getHandVal() const
    {
        return handVal;
    }

    //this public member function is used to return a high card
    int getHighCard() const
    {
        return HighCard;
    }

    //this public member function is used to return a hand's message
    string getHandMessage() const
    {
        return HandMessage;
    }

    //this public member function is used to return a full house value(three of a kind)
    int getHouseVal() const
    {
        return HouseVal;
    }

    //this public member function is used to return a full house value(pair)
    int getHouseVal2() const
    {
        return HouseVal2;
    }

    //this public member function is used to return a three of a kind, four of a kind, or a pair's value
    int getKindVal() const
    {
        return kindVal;
    }

    //this public member function is used to return a 2nd pair's value
    int getKindVal2() const
    {
        return kindVal2;
    }

    //this public member function is used to return a hand's total
    int getTotal() const
    {
        return Total;
    }
};


//function RandomizePlayerHands will randomize the poker hands or allow the user to input the hands
//function AssignHandType will asign each poker hand a hand type, ex: pair, two pair, etc
//function WinnerMessage will display and determine a winner from the two hands
void RandomizePlayerHands(PlayerHand[], int, int);
void AssignHandType(PlayerHand[], int);
void WinnerMessage(PlayerHand[]);


//this is where the program starts
int main()
{
    string player_name = "PlayerOne";
    string computer_name = "Computer";

    int NumPlayers = 2;
    PlayerHand* Hptr;

    //a pointer with the data type of PlayerHand is used to create 
    //two valid poker hands
    Hptr = new PlayerHand[NumPlayers];
    Hptr[0].setPlayerName(player_name);
    Hptr[1].setPlayerName(computer_name);

    int GameMode;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "IMPORTANT NOTICE: If you would like to play/input a low Ace, type a(n)" << endl;
    cout << "lowercase 'a' followed by the cards suit" << endl;
    cout << "Example: aS, aC, aD, aH" << endl;
    cout << "IMPORTANT NOTICE: When inputting a card, avoid typing lowercase" << endl;
    cout << "charaters for the suits " << endl;
    cout << "Example: As, Td, 6c, 9h" << endl;
    cout << "----------------------------------------------------------------------" << endl;

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
    //where they will have to input the cards manually 
    if (GameMode == 1)
    {
        for (int i = 0; i < NumPlayers; i++)
        {
            RandomizePlayerHands(Hptr, i, GameMode);
        }

        for (int i = 0; i < NumPlayers; i++)
        {
            AssignHandType(Hptr, i);
        }
    }

    //if the mode entered is 2, then the player is sent into game mode
    //where the program will assign the two PlayerHand's random cards
    else if (GameMode == 2)
    {
        for (int i = 0; i < NumPlayers; i++)
        {
            RandomizePlayerHands(Hptr, i, GameMode);
        }

        for (int i = 0; i < NumPlayers; i++)
        {
            AssignHandType(Hptr, i);
        }

    }

    //if the mode entered is 3, then the program will terminate 
    else if (GameMode == 3)
    {
        return 0;
    }

    //WinnerMessage function is called to display/determine a winner
    WinnerMessage(Hptr);

    return 0;
}

/*-------------------------------------------------------------

The RandomizePlayerHands function is used to randomly 
generate player hands, or allow for a user to input 
player hands manually

-if the option selected is 1, then the player will have to 
manually enter the hands

-if the option selected is 2, then the player will be given a
set of randomly generated hands.

-------------------------------------------------------------*/

void RandomizePlayerHands(PlayerHand H[], int X, int mode)
{
    int rank_val;
    int suit_val;
    int t = 0;

    bool flag = false;

    //these arrays are used to help assign a random card
    string suits[4] = {"H","S","C","D"};
    string ranks[15] = {"","a","2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
    string cardType;
    string card;

    //min and max values for a random suit
    const int Min_one = 0;
    const int Max_two = 3;

    //min and max values for a random rank
    const int Min_One = 1;
    const int Max_Two = 14;

    //creating a random numbers genertor to get the numbers
    //needed to get a random card
    random_device engine;
    uniform_int_distribution<int> RandomSuit(Min_one, Max_two);
    uniform_int_distribution<int> RandomRank(Min_One, Max_Two);


    //if the mode's value is one, then the manual process of entering the cards will begin
    if (mode == 1)
    {
        cout << "Select cards for " << H[X].getPlayerName() << endl;


        //this for loop is used to monitor invalid and valid cards
        //for each hand, when a valid card is found then the flag(bool)
        //is set to true, once this is done, the loop will end and 
        //the user will be prompted to input another card
        //However, is the card is invalid, then the program will
        //continue to loop until the user enters a valid card
        for (int i = 0; i < 5; i++)
        {
            flag = false;

            cout << "Enter a Card: ";
            cin >> card;

            while (flag == false)
            {
                for (int i2 = 0; i2 < 4; i2++)
                {
                    for (int i3 = 0; i3 < 15; i3++)
                    {

                        //checks for a valid card
                        if (card == ranks[i3] + suits[i2])
                        {
                            rank_val = i3;
                            suit_val = i2;
                            H[X].setPlayerCards(i, rank_val, suit_val, card);

                            flag = true;
                        }
                    }
                }

                //if none of the condtions are met then the 
                //player is prompted to try again
                if (flag == false)
                {
                    cout << "Bad Card. Try Again.\n";
                    cout << "Enter a card: ";
                    cin >> card;
                }
            }
        }
    }

    //if the mode's value is 2, then the randomize process for the players hands 
    //will begin
    else if (mode == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            //the values of suit_val and rank_val are set to be random
            suit_val = RandomSuit(engine);
            rank_val = RandomRank(engine);

            //this assigns the cardType from the random values
            cardType = (ranks[rank_val] + suits[suit_val]);

            //all arguements are passed through the setPlayerCards member function
            //thats located within the PlayerHand class
            H[X].setPlayerCards(i, rank_val, suit_val, cardType);
        }
    }

    //this loop is used to get the total 
    //value of each card and sum them up, this 
    //will later be used to determine a winner
    //in the event of a draw.
    for (int i = 0; i < 5; i++)
    {
        t += H[X].getRankValue(i);
    }

    H[X].setTotal(t);
}

/*-------------------------------------------------------------

The AssignHandType function is used to a assign a hand type, 
a(n) hand value, and a hand's special characteristics as well 
as a hands total value (determined by add a hands rank values)

-------------------------------------------------------------*/

void AssignHandType(PlayerHand H[], int X)
{
    int counter = 0;
    int min_val = 100;
    int max_val = 0;
    int position = 0;
    int position2 = 0;

    int four_val = 0;
    int full3 = 0;
    int full2 = 0;
    int Onep = 0;
    int Twop = 0;

    int house1 = 0;
    int house2 = 0;


    int HighC = 0;

    //keep this here just incase
    string suits[4] = { "H","S","C","D" };
    string ranks[15] = { "","a","2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
    string Msg;
    string Msg2;


    //the loops with the arrays
    //check for the number value of the suits and ranks
    //the strings are not needed to check the arrays since they are int

    //this is to look for a high card
    for (int i = 0; i < 1; i++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (H[X].getRankValue(i) > max_val)
            {
                max_val = H[X].getRankValue(i);
            }
        }

        for (int i = 0; i < 15; i++)
        {
            if (max_val == i)
            {
                position2 = i;
                position = i;
            }
        }

        if (H[X].getHandVal() < 1)
        {
            H[X].setHandVal(1);
            H[X].setHighCard(max_val);

            Msg = "HIGH CARD";
            Msg = Msg + ", " + ranks[position] + " High ";

            H[X].setHandMessage(Msg);
        }
    }

    //this is to look for a royal flush
    for (int i = 0; i < 4; i++)
    {
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (H[X].getSuitValue(i2) == i)
            {
                counter++;
            }

            if (counter == 5)
            {
                if (H[X].getSuitValue(i2) == 0)
                {
                    Msg2 = "Hearts ";
                }
                else if (H[X].getSuitValue(i2) == 1)
                {
                    Msg2 = "Spades ";
                }
                else if (H[X].getSuitValue(i2) == 2)
                {
                    Msg2 = "Clubs ";
                }
                else if (H[X].getSuitValue(i2) == 3)
                {
                    Msg2 = "Diamonds ";
                }

                if (counter == 5)
                {
                    counter = 0;

                    for (int i3 = 0; i3 < 5; i3++)
                    {
                        for (int i4 = 0; i4 < 5; i4++)
                        {
                            if (H[X].getRankValue(i4) == (10 + i3))
                            {
                                counter++;
                                i4 = i4 + 100;
                            }
                        }
                        if (counter == 5)
                        {
                            if (H[X].getHandVal() < 10)
                            {
                                H[X].setHandVal(10);

                                Msg = "ROYAL FLUSH";
                                Msg = Msg + ", " + Msg2;

                                H[X].setHandMessage(Msg);
                            }
                        }
                    }
                }
            }
        }
        counter = 0;
    }

    //this is to look for a straight flush
    for (int i = 0; i < 4; i++)
    {
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (H[X].getSuitValue(i2) == i)
            {
                counter++;
            }

            if (counter == 5)
            {
                if (H[X].getSuitValue(i2) == 0)
                {
                    Msg2 = "Hearts";
                }
                else if (H[X].getSuitValue(i2) == 1)
                {
                    Msg2 = "Spades";
                }
                else if (H[X].getSuitValue(i2) == 2)
                {
                    Msg2 = "Clubs";
                }
                else if (H[X].getSuitValue(i2) == 3)
                {
                    Msg2 = "Diamonds";
                }

                if (counter == 5)
                {

                    for (int i3 = 0; i3 < 5; i3++)
                    {
                        if (H[X].getRankValue(i3) < min_val)
                        {
                            min_val = H[X].getRankValue(i3);
                        }
                    }

                    counter = 0;

                    for (int i3 = 0; i3 < 5; i3++)
                    {
                        for (int i4 = 0; i4 < 5; i4++)
                        {
                            if (H[X].getRankValue(i4) == (min_val + i3))
                            {
                                counter++;
                                i4 = i4 + 100;
                            }
                        }
                        if (counter == 5)
                        {
                            if (H[X].getHandVal() < 9)
                            {
                                H[X].setHandVal(9);

                                Msg = "STRAIGHT FLUSH";
                                Msg = Msg + ", " + Msg2 + ", " + ranks[position] + " high ";

                                H[X].setHandMessage(Msg);
                            }
                        }
                    }   
                }
            }
        }
        counter = 0;
    }

    //this looks for a four of a kind
    for (int i = 0; i < 15; i++)
    {
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (H[X].getRankValue(i2) == i)
            {
                counter++;
            }
        }

        if (counter >= 4)
        {
            if (H[X].getHandVal() < 8)
            {
                position2 = i;
                four_val = i;

                H[X].setKindVal(i);
                H[X].setHandVal(8);

                Msg = "FOUR OF A KIND";
                Msg = Msg + ", " + ranks[position2] + "'s ";

                H[X].setHandMessage(Msg);
            }
        }

        counter = 0;
    }

    //this looks for a full house
    for (int i = 0; i < 15; i++)
    {
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (H[X].getRankValue(i2) == i)
            {
                counter++;
            }
        }

        if (counter == 2)
        {
            full2++;

            house2 = i;
        }

        if (counter == 3)
        {
            full3++;

            house1 = i;
        }

        if (full2 == 1 && full3 == 1)
        {
            if (H[X].getHandVal() < 7)
            {

                H[X].setHouseVal(house1, house2);
                H[X].setHandVal(7);

                Msg = "FULL HOUSE";
                Msg = Msg + ", " + ranks[house1] + "'s full of " + ranks[house2] + "'s ";
                H[X].setHandMessage(Msg);
            }
        }
    
        counter = 0;
    }


    //this looks for a flush
    for (int i = 0; i < 4; i++)
    {
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (H[X].getSuitValue(i2) == i)
            {
                counter++;
            }

            if (counter == 5)
            {
                if (H[X].getSuitValue(i2) == 0)
                {
                    Msg = "Hearts";
                }
                else if (H[X].getSuitValue(i2) == 1)
                {
                    Msg = "Spades";
                }
                else if (H[X].getSuitValue(i2) == 2)
                {
                    Msg = "Clubs";
                }
                else if (H[X].getSuitValue(i2) == 3)
                {
                    Msg = "Diamonds";
                }

                if (H[X].getHandVal() < 6)
                {
                    position2 = i;
                    H[X].setHandVal(6);

                    Msg = "FLUSH, " + Msg + ", " + ranks[max_val] + " high ";
                    H[X].setHandMessage(Msg);
                }
            }
        }
        counter = 0;
    }

    //this looks for a straight
    //this also resets the min_val
    //to its original amount
    min_val = 100;
    for (int i = 0; i < 4; i++)
    {
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (H[X].getSuitValue(i2) == i)
            {
                counter++;
            }
        }

        if (counter >= 2)
        {
            for (int i3 = 0; i3 < 5; i3++)
            {
                if (H[X].getRankValue(i3) < min_val)
                {
                    min_val = H[X].getRankValue(i3);
                }
            }

            counter = 0;

            for (int i3 = 0; i3 < 5; i3++)
            {
                for (int i4 = 0; i4 < 5; i4++)
                {
                    if (H[X].getRankValue(i4) == (min_val + i3))
                    {
                        counter++;
                        i4 = i4 + 100;
                        
                    }
                }
                if (counter == 5)
                {
                    if (H[X].getHandVal() < 5)
                    {
                        H[X].setHandVal(5);

                        Msg = "STRAIGHT, ";
                        Msg = Msg + ranks[position2] + " high ";
                        
                        H[X].setHandMessage(Msg);
                    }
                }
            }

        }
    }

    counter = 0;


    //this looks for  three of a kind
    for (int i = 0; i < 15; i++)
    {
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (H[X].getRankValue(i2) == i)
            {
                counter++;
            }
        }

        if (counter >= 3)
        {
            if (H[X].getHandVal() < 4)
            {
                full3 = i;
                H[X].setKindVal(i);
                H[X].setHandVal(4);

                Msg = "THREE OF A KIND";
                Msg = Msg + ", " + ranks[i] + "'s ";

                H[X].setHandMessage(Msg);
            }
        }

        counter = 0;

    }

    //this looks for two pair
    for (int i = 0; i < 15; i++)
    {
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (H[X].getRankValue(i2) == i)
            {
                counter++;
            }
        }

        if (counter == 2)
        {
            Twop++;
            counter = 0;

            if (Twop == 1)
            {
                Onep = i;
            }
        }

        if (Twop == 2)
        {
            if (H[X].getHandVal() < 3)
            {
                Twop = i;
                H[X].setHandVal(3);
                H[X].setKindVals(Onep, Twop);

                Msg = "TWO PAIR";
                Msg = Msg + ", " + ranks[Twop] + "'s and " + ranks[Onep] + "'s ";

                H[X].setHandMessage(Msg);
            }
        }

        counter = 0;
    }

    //this looks for a pair
    for (int i = 0; i < 15; i++)
    {
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (H[X].getRankValue(i2) == i)
            {
                counter++;
            }
        }

        if (counter == 2)
        {
            if (H[X].getHandVal() < 2)
            {
                Onep = i;
                H[X].setKindVal(Onep);
                H[X].setHandVal(2);

                Msg = "ONE PAIR";
                Msg = Msg + ", " + ranks[i] + "'s ";
                H[X].setHandMessage(Msg);
            }
        }
        counter = 0;
    }

}

/*-------------------------------------------------------------

The WinnerMessage function is used to determine a winner
from both of the hands and will print a winning message for 
the winning hand, if a tie occurs, then a tie message will 
be dispalyed as well as both hands

-------------------------------------------------------------*/

void WinnerMessage(PlayerHand H[])
{
    //this entire code segment is used to determine the winning and losing hands
    //the if statements check to see which hand has a greater hand value
    //if the hand values are equal then a seperate series of if statements are used to 
    //compare the special characteristics of each hand.
    //if the characteristics of those hands are equal, then another series of if statements
    //are used to compare the hand totals to determine a winner

    //this compares the handvalues
    if (H[0].getHandVal() > H[1].getHandVal())
    {
        cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
        cout << "CONGRATULATIONS ";
        cout << H[0].getPlayerName();
        cout << " ,you WON!" << endl;
        cout << H[0].getPlayerName() << " Won with the following hand: ";
        H[0].getPlayerCards();
        cout << " " << endl;
    }
    //this compares the handvalues
    else if (H[0].getHandVal() < H[1].getHandVal())
    {
        cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
        cout << "CONGRATULATIONS ";
        cout << H[1].getPlayerName();
        cout << " ,you WON!" << endl;
        cout << H[1].getPlayerName() << " Won with the following hand: ";
        H[1].getPlayerCards();
        cout << " " << endl;
    }
    //this compares equal hands values 
    else if (H[0].getHandVal() == H[1].getHandVal())
    {
        //this is used to break a tie breaker between a high card and a flush
        if (H[0].getHandVal() == 1 || H[0].getHandVal() == 6)
        {
            if (H[0].getHighCard() > H[1].getHighCard())
            {
                cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[0].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[0].getPlayerName() << " Won with the following hand: ";
                H[0].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getHighCard() < H[1].getHighCard())
            {
                cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[1].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[1].getPlayerName() << " Won with the following hand: ";
                H[1].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getHighCard() == H[1].getHighCard())
            {
                if (H[0].getTotal() > H[1].getTotal())
                {
                    cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                    cout << "CONGRATULATIONS ";
                    cout << H[0].getPlayerName();
                    cout << " ,you WON!" << endl;
                    cout << H[0].getPlayerName() << " Won with the following hand: ";
                    H[0].getPlayerCards();
                    cout << " " << endl;
                }
                if (H[0].getTotal() < H[1].getTotal())
                {
                    cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                    cout << "CONGRATULATIONS ";
                    cout << H[1].getPlayerName();
                    cout << " ,you WON!" << endl;
                    cout << H[1].getPlayerName() << " Won with the following hand: ";
                    H[1].getPlayerCards();
                    cout << " " << endl;
                }
                if (H[0].getTotal() == H[1].getTotal())
                {
                    cout << H[0].getHandMessage() << "ties " << H[1].getHandMessage() << endl;
                    cout << "This game is a draw!" << endl;
                    cout << "Here are the hands for both players." << endl;
                    cout << H[0].getPlayerName() << "'s Hand: ";
                    H[0].getPlayerCards();
                    cout << " " << endl;
                    cout << H[1].getPlayerName() << "'s Hand: ";
                    H[1].getPlayerCards();
                    cout << " " << endl;
                }
            }
        }

        //this is used to break a tie between a two pair
        else if (H[0].getHandVal() == 3)
        {
            if (H[0].getKindVal2() > H[1].getKindVal2())
            {
                cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[0].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[0].getPlayerName() << " Won with the following hand: ";
                H[0].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getKindVal2() < H[1].getKindVal2())
            {
                cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[1].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[1].getPlayerName() << " Won with the following hand: ";
                H[1].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getKindVal2() == H[1].getKindVal2())
            {
                if (H[0].getKindVal() > H[1].getKindVal())
                {
                    cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                    cout << "CONGRATULATIONS ";
                    cout << H[0].getPlayerName();
                    cout << " ,you WON!" << endl;
                    cout << H[0].getPlayerName() << " Won with the following hand: ";
                    H[0].getPlayerCards();
                    cout << " " << endl;
                }
                else if (H[0].getKindVal() < H[1].getKindVal())
                {
                    cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                    cout << "CONGRATULATIONS ";
                    cout << H[1].getPlayerName();
                    cout << " ,you WON!" << endl;
                    cout << H[1].getPlayerName() << " Won with the following hand: ";
                    H[1].getPlayerCards();
                    cout << " " << endl;
                }
                else if (H[0].getKindVal() == H[1].getKindVal())
                {
                    if (H[0].getTotal() > H[1].getTotal())
                    {
                        cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                        cout << "CONGRATULATIONS ";
                        cout << H[0].getPlayerName();
                        cout << " ,you WON!" << endl;
                        cout << H[0].getPlayerName() << " Won with the following hand: ";
                        H[0].getPlayerCards();
                        cout << " " << endl;
                    }
                    else if (H[0].getTotal() < H[1].getTotal())
                    {
                        cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                        cout << "CONGRATULATIONS ";
                        cout << H[1].getPlayerName();
                        cout << " ,you WON!" << endl;
                        cout << H[1].getPlayerName() << " Won with the following hand: ";
                        H[1].getPlayerCards();
                        cout << " " << endl;
                    }
                    else if (H[0].getTotal() == H[1].getTotal())
                    {
                        cout << H[0].getHandMessage() << "ties " << H[1].getHandMessage() << endl;
                        cout << "This game is a draw!" << endl;
                        cout << "Here are the hands for both players." << endl;
                        cout << H[0].getPlayerName() << "'s Hand: ";
                        H[0].getPlayerCards();
                        cout << " " << endl;
                        cout << H[1].getPlayerName() << "'s Hand: ";
                        H[1].getPlayerCards();
                        cout << " " << endl;
                    }
                }
            }
        }

        //this is used to break a tie between a four of a kind, three of a kind, and a pair
        else if (H[0].getHandVal() == 4 || H[0].getHandVal() == 8 || H[0].getHandVal() == 2)
        {
            if (H[0].getKindVal() > H[1].getKindVal())
            {
                cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[0].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[0].getPlayerName() << " Won with the following hand: ";
                H[0].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getKindVal() < H[1].getKindVal())
            {
                cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[1].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[1].getPlayerName() << " Won with the following hand: ";
                H[1].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getKindVal() == H[1].getKindVal())
            {
                if (H[0].getTotal() > H[1].getTotal())
                {
                    cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                    cout << "CONGRATULATIONS ";
                    cout << H[0].getPlayerName();
                    cout << " ,you WON!" << endl;
                    cout << H[0].getPlayerName() << " Won with the following hand: ";
                    H[0].getPlayerCards();
                    cout << " " << endl;
                }
                else if (H[0].getTotal() < H[1].getTotal())
                {
                    cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                    cout << "CONGRATULATIONS ";
                    cout << H[1].getPlayerName();
                    cout << " ,you WON!" << endl;
                    cout << H[1].getPlayerName() << " Won with the following hand: ";
                    H[1].getPlayerCards();
                    cout << " " << endl;
                }
                if (H[0].getTotal() == H[1].getTotal())
                {
                    cout << H[0].getHandMessage() << "ties " << H[1].getHandMessage() << endl;
                    cout << "This game is a draw!" << endl;
                    cout << "Here are the hands for both players." << endl;
                    cout << H[0].getPlayerName() << "'s Hand: ";
                    H[0].getPlayerCards();
                    cout << " " << endl;
                    cout << H[1].getPlayerName() << "'s Hand: ";
                    H[1].getPlayerCards();
                    cout << " " << endl;
                }
            }
        }

        //this is used to break a tie between a straight and a straight flush
        else if (H[0].getHandVal() == 5 || H[0].getHandVal() == 9)
        {
            if (H[0].getHighCard() > H[1].getHighCard())
            {
                cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[0].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[0].getPlayerName() << " Won with the following hand: ";
                H[0].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getHighCard() < H[1].getHighCard())
            {
                cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[1].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[1].getPlayerName() << " Won with the following hand: ";
                H[1].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getHighCard() == H[1].getHighCard())
            {
                cout << H[0].getHandMessage() << "ties " << H[1].getHandMessage() << endl;
                cout << "This game is a draw!" << endl;
                cout << "Here are the hands for both players." << endl;
                cout << H[0].getPlayerName() << "'s Hand: ";
                H[0].getPlayerCards();
                cout << " " << endl;
                cout << H[1].getPlayerName() << "'s Hand: ";
                H[1].getPlayerCards();
                cout << " " << endl;
            }
        }

        //this is used to break a tie between a full house 
        else if (H[0].getHandVal() == 7)
        {
            if (H[0].getHouseVal() > H[1].getHouseVal())
            {
                cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[0].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[0].getPlayerName() << " Won with the following hand: ";
                H[0].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getHouseVal() < H[1].getHouseVal())
            {
                cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                cout << "CONGRATULATIONS ";
                cout << H[1].getPlayerName();
                cout << " ,you WON!" << endl;
                cout << H[1].getPlayerName() << " Won with the following hand: ";
                H[1].getPlayerCards();
                cout << " " << endl;
            }
            else if (H[0].getHouseVal() == H[1].getHouseVal())
            {
                if (H[0].getHouseVal2() > H[1].getHouseVal2())
                {
                    cout << H[0].getHandMessage() << "beats " << H[1].getHandMessage() << endl;
                    cout << "CONGRATULATIONS ";
                    cout << H[0].getPlayerName();
                    cout << " ,you WON!" << endl;
                    cout << H[0].getPlayerName() << " Won with the following hand: ";
                    H[0].getPlayerCards();
                    cout << " " << endl;
                }
                if (H[0].getHouseVal2() < H[1].getHouseVal2())
                {
                    cout << H[0].getHandMessage() << "loses to " << H[1].getHandMessage() << endl;
                    cout << "CONGRATULATIONS ";
                    cout << H[1].getPlayerName();
                    cout << " ,you WON!" << endl;
                    cout << H[1].getPlayerName() << " Won with the following hand: ";
                    H[1].getPlayerCards();
                    cout << " " << endl;
                }
                if (H[0].getHouseVal2() == H[1].getHouseVal2())
                {
                    cout << H[0].getHandMessage() << "ties " << H[1].getHandMessage() << endl;
                    cout << "This game is a draw!" << endl;
                    cout << "Here are the hands for both players." << endl;
                    cout << H[0].getPlayerName() << "'s Hand: ";
                    H[0].getPlayerCards();
                    cout << " " << endl;
                    cout << H[1].getPlayerName() << "'s Hand: ";
                    H[1].getPlayerCards();
                    cout << " " << endl;
                }
            }
        }

        //this is used to display a tie between two royal flush
        else if (H[0].getHandVal() == 10)
        {
            cout << H[0].getHandMessage() << "ties " << H[1].getHandMessage() << endl;
            cout << "This game is a draw!" << endl;
            cout << "Here are the hands for both players." << endl;
            cout << H[0].getPlayerName() << "'s Hand: ";
            H[0].getPlayerCards();
            cout << " " << endl;
            cout << H[1].getPlayerName() << "'s Hand: ";
            H[1].getPlayerCards();
            cout << " " << endl;
        }
    }
}