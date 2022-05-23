#include <iostream>
#include <queue>
#include <time.h>
#include <string>

#define ORDER_TERM 15

#define COMBINATION 0
#define BULGOGI 1
#define SWEET_POTATO 2

#define COMBINATION_TERM 23
#define BULGOGI_TERM 14
#define SWEET_POTATO_TERM 13

#define COMBINATION_PRICE 29000
#define BULGOGI_PRICE 21000
#define SWEET_POTATO_PRICE 23000

using namespace std;

int main(void) {
	int makePizza = 0;

	int CombinationPizza = 0;
	int CombinationPizzaTotalPrice = 0;

	int BULGOGIPizza = 0;
	int BULGOGIPizzaTotalPrice = 0;

	int SweetPotatoPizza = 0;
	int SweetPotatoPizzaTotalPrice = 0;

	queue<int> q;

	srand((unsigned)time(NULL));

	for (int sec = 0; sec < 3600; sec += 20) {
		if (sec % ORDER_TERM == 0) {
			switch (rand() % 3)
			{
			case COMBINATION:
				q.push(COMBINATION_TERM);
				CombinationPizza++;
				break;
			case BULGOGI:
				q.push(BULGOGI_TERM);
				BULGOGIPizza++;
				break;
			case SWEET_POTATO:
				q.push(SWEET_POTATO_TERM);
				SweetPotatoPizza++;
				break;
			default:
				break;
			}
		}

		if (makePizza <= 0 && !q.empty()) {
			makePizza = q.front();
			q.pop();
		}
		makePizza--;
	}

	CombinationPizzaTotalPrice = CombinationPizza * COMBINATION_PRICE;
	BULGOGIPizzaTotalPrice = BULGOGIPizza * BULGOGI_PRICE;
	SweetPotatoPizzaTotalPrice = SweetPotatoPizza * SWEET_POTATO_PRICE;
	int totalPrice = CombinationPizzaTotalPrice + BULGOGIPizzaTotalPrice + SweetPotatoPizzaTotalPrice;

	cout << "PizzaMakeSimulator" << endl;
	cout << "======OrderCount======" << endl;
	cout << "CombinationPizza : " << CombinationPizza << endl;
	cout << "BulbobiPizza : " << BULGOGIPizza << endl;
	cout << "SweetPotatoPizza : " << SweetPotatoPizza << endl;
	cout << "TotalOrder : " << CombinationPizza + BULGOGIPizza + SweetPotatoPizza << endl;
	cout << "TotalPrice : " << totalPrice << " Won" << endl;
	cout << "¡Ø Waiting room size: " << q.size() << endl;
}