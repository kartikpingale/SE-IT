#include<iostream>

using namespace std;

class weatherReport
{
	int day;
	int highTemp, lowTemp, amountRain, amountSnow;
	float avg_highTemp, avg_lowTemp, avg_amountRain, avg_amountSnow;
	public:
	weatherReport()
	{
		highTemp=0;
		lowTemp=0;
		amountRain=0;
		amountSnow=0;
		avg_highTemp=0.0;
		avg_lowTemp=0.0;
		avg_amountRain=0.0;
		avg_amountSnow=0.0;
	}
	void getData(weatherReport day[][32], int month)
	{
        int i, maxDays, date=1;
        char repeat='y';
        maxDays=getDays(month);
        
        while(repeat=='y' || repeat=='Y')
        {
        	do
			{
				if(date<1 || date>maxDays)
				{
					cout << "Invalid selection! Enter a date between 1-"<< maxDays <<"!\n";
				}
				cout << "\nEnter date: ";
				cin >> date;
				if(date>=1 && date<=maxDays)
				{
					cout << "\nEnter high temperature: ";
            		cin >> day[month][date].highTemp;
            		cout << "Enter low temperature: ";
					cin >> day[month][date].lowTemp;
					cout << "Enter amount of rain: ";
					cin >> day[month][date].amountRain;
					cout << "Enter amount of snow: ";
					cin >> day[month][date].amountSnow;
					cout << "\nDo you want to enter data for another day? (y/n)";
					cin >> repeat;
				}
			}
            while(date<1 || date>maxDays);
        }
	}
    void putData(weatherReport day[][32], int month)
    {
        int maxDays, date;
        maxDays=getDays(month);
        cout << "\nEnter date: ";
        cin >> date;
        if(date>=1 && date<=maxDays)
        {
            cout << "\nHigh temperature: " << day[month][date].highTemp << endl;
            cout << "Low temperature: " << day[month][date].lowTemp << endl;
			cout << "Amount of rain: " << day[month][date].amountRain << endl;
			cout << "Amount of snow: " << day[month][date].amountSnow << endl;
        }
        else
        {
            cout << "Invalid selection! Enter a date between 1-"<< maxDays <<"!\n";
        }
    }
    void modifyData(weatherReport day[][32], int month)
	{
        int i, maxDays, date=1;
        char repeat='y';
        maxDays=getDays(month);
        
        while(repeat=='y' || repeat=='Y')
        {
        	do
			{
				if(date<1 || date>maxDays)
				{
					cout << "Invalid selection! Enter a date between 1-"<< maxDays <<"!\n";
				}
				cout << "\nEnter date to modify data: ";
				cin >> date;
				if(date>=1 && date<=maxDays)
				{
					cout << "\nEnter high temperature: ";
            		cin >> day[month][date].highTemp;
            		cout << "Enter low temperature: ";
					cin >> day[month][date].lowTemp;
					cout << "Enter amount of rain: ";
					cin >> day[month][date].amountRain;
					cout << "Enter amount of snow: ";
					cin >> day[month][date].amountSnow;
					cout << "\nDo you want to modify data for another day? (y/n)";
					cin >> repeat;
				}
			}
            while(date<1 || date>maxDays);
        }
        cout << "Data has been modified!"
	}
    void generateReport(weatherReport day[][32], int month)
    {
        int i, maxDays, days=0;
        maxDays=getDays(month);
        float sumHigh=0, sumLow=0, sumRain=0, sumSnow=0;
        for(i=1; i<=maxDays; i++)
        {
            sumHigh+=day[month][i].highTemp;
            sumLow+=day[month][i].lowTemp;
            sumRain+=day[month][i].amountRain;
            sumSnow+=day[month][i].amountSnow;
            if(day[month][i].highTemp!=0 && day[month][i].lowTemp!=0 && day[month][i].amountRain!=0 && day[month][i].amountSnow!=0)
            {
                days++;
            }
        }
        avg_highTemp=(sumHigh/days);
        avg_lowTemp=(sumLow/days);
        avg_amountRain=(sumRain/days);
        avg_amountSnow=(sumSnow/days);
		cout << "\nDay\tHigh Temperature\tLow Temperature\t\tAmount of rain\t\tAmount of snow\n";
		for(i=1; i<=maxDays; i++)
        {
            cout << (i) << "\t\t" << day[month][i].highTemp << "\t\t\t" << day[month][i].lowTemp << "\t\t\t" << day[month][i].amountRain << "\t\t\t" << day[month][i].amountSnow << endl;
        }
        cout << "\nAverage high temperature: " << avg_highTemp;
        cout << "\nAverage low temperature: " << avg_lowTemp;
        cout << "\nAverage amount of rain: " << avg_amountRain;
        cout << "\nAverage amount of snow: " << avg_amountSnow << endl;
    }
    int getDays(int month)
    {
        int maxDays;
        switch(month)
        {
        	case 1:
        	case 3:
        	case 5:
        	case 7:
        	case 8:
        	case 10:
        	case 12:
        	{
        		maxDays=31;
        		break;
        	}
        	case 4:
        	case 6:
        	case 9:
        	case 11:
        	{
        		maxDays=30;
        		break;
        	}
        	case 2:
        	{
        		maxDays=29;
        		break;
        	}
        }
        return maxDays;
    }
};

int main()
{
	weatherReport today, day[13][32];
	int choice, month=1;
	char repeat='y';
	
	do
	{
		if(month<1 || month>12)
		{
			cout << "Invalid selection! Enter a month between 1-12!\n";
		}
		cout << "Enter month (1-12): ";
		cin >> month;
	}
	while(month<1 || month>12);
	
	while(repeat=='y' || repeat=='Y')
	{
		cout << "\n1. Enter data\n2. Display data\n3. Modify data\n4. Generate report\nSelect the operation: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				{
					today.getData(day, month);
					break;
				}
			case 2:
				{
					today.putData(day, month);
					break;
				}
			case 3:
				{
					today.modifyData(day, month);
					break;
				}
			case 4:
				{
					today.generateReport(day, month);
					break;
				}
			default:
				{
					cout << "Invalid selection! Select a number between 1-4";
					break;
				}
		}
		cout << "\nDo you want to perform another operation? (y/n)";
		cin >> repeat;
	}
	
	return 0;
}
