/*Ramsha Bilal
bilal_week4_ps
Problem set 4
moneyclass.h file
PC
*/

#ifndef MONEY_CLASS_H 
#define MONEY_CLASS_H 

const int MAX_CENTS = 100, DEFAULT_DOLLARS = 0;
class Money
{
private:
	int m_cents, m_dollars;
public:
	Money(); 
	Money(const Money& moneyObject);
	void addMoney(int cents, int dollars = DEFAULT_DOLLARS);
	void showMoney();
	int getCents();
	int getDollars();
};


#endif

