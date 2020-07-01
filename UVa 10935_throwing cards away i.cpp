//UVa 10935 throwing cards away i accepted - c++
/*
The Algorithm :
1- creating a queue with cards
2- save the discarded cards in an integer array
3- pop the front of the queue
4- push the front of the queue //ex : 2 3 4 then after pushing the front : 2 3 4 2
5- pop the front  // ex :  3  4  2
6- print the answer
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int x; 
	while (cin >> x)
	{
		if (x == 0)
			break;
		if (x == 1) //handling case of being 1 without spaces in the first ouput ,cause it gets a wrong presentation  
		{
			cout << "Discarded cards:" << endl;
			cout << "Remaining card: " << 1 << endl;
			continue;
		}
		queue <int> deck;
		for (int i = 1; i <= x; i++)
			deck.push(i);
		int arr[60] = { 0 }; //put in it the discarded card
		int i = 0;
		while (deck.size() >= 2)
		{
			arr[i] = deck.front();
			deck.pop();
			deck.push(deck.front());
			deck.pop();
			i++;
		}
		cout << "Discarded cards: ";
		for (int i = 0; i < x; i++)
		{

			if (arr[i] > 0)
				cout << arr[i];
			if (i < x - 2)
				cout << ", ";

		}
		cout << endl;
		cout << "Remaining card: " << deck.front() << endl;
	}
}