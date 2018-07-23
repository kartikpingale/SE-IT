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
	void getData(weatherReport day[50], int n)
	{
        int i;
        for(i=0; i<n; i++)
        {
            cout << "\nEnter high temperature: ";
            cin >> day[i].highTemp;
            cout << "Enter low temperature: ";
			cin >> day[i].lowTemp;
			cout << "Enter amount of rain: ";
			cin >> day[i].amountRain;
			cout << "Enter amount of snow: ";
			cin >> day[i].amountSnow;
        }
	}
	void modifyData(weatherReport day[50], int n)
	{
        int dayNumber, userDay;
		cout << "\nEnter day for which you want to modify the data: ";
		cin >> userDay;
        if(userDay<=n)
        {
            dayNumber=(userDay-1);
            cout << "Enter high temperature: ";
            cin >> day[dayNumber].highTemp;
            cout << "Enter low temperature: ";
		    cin >> day[dayNumber].lowTemp;
		    cout << "Enter amount of rain: ";
		    cin >> day[dayNumber].amountRain;
		    cout << "Enter amount of snow: ";
		    cin >> day[dayNumber].amountSnow;
        }
        else
        {
            cout << "Enter correct day to modify data!";
        }
	}
	void putData(weatherReport day[50], int n)
	{
        int i;
        for(i=0; i<n; i++)
        {
            cout << "\nDay " << (i+1) << ":\n";
            cout << "High temperature is " << day[i].highTemp << " C" << endl;
		    cout << "Low temperature is " << day[i].lowTemp << " C" << endl;
		    cout << "Amount of rain is " << day[i].amountRain << " mm" << endl;
		    cout << "Amount of snow is " << day[i].amountSnow << " mm" << endl;   
        }
	}
	void generateReport(weatherReport day[50], int n)
	{
        int i;
        float sumHigh=0, sumLow=0, sumRain=0, sumSnow=0;
        for(i=0; i<n; i++)
        {
            sumHigh+=day[i].highTemp;
            sumLow+=day[i].lowTemp;
            sumRain+=day[i].amountRain;
            sumSnow+=day[i].amountSnow;
        }
        avg_highTemp=(sumHigh/n);
        avg_lowTemp=(sumLow/n);
        avg_amountRain=(sumRain/n);
        avg_amountSnow=(sumSnow/n);
		cout << "\nDay\tHigh Temperature\tLow Temperature\t\tAmount of rain\t\tAmount of snow\n";
		for(i=0; i<n; i++)
        {
            cout << (i+1) << "\t\t" << day[i].highTemp << "\t\t\t" << day[i].lowTemp << "\t\t\t" << day[i].amountRain << "\t\t\t" << day[i].amountSnow << endl;
        }
        cout << "\nAverage high temperature: " << avg_highTemp;
        cout << "\nAverage low temperature: " << avg_lowTemp;
        cout << "\nAverage amount of rain: " << avg_amountRain;
        cout << "\nAverage amount of snow: " << avg_amountSnow << endl;
	}
};

int main()
{
	weatherReport today, day[50];
	int choice, countDays;
	char repeat='y';
    cout << "Enter no. of days: ";
    cin >> countDays;
	while(repeat=='y' || repeat=='Y')
	{
		cout << "\n1. Enter data\n2. Display data\n3. Modify data\n4. Generate report\nSelect the operation: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				{
					today.getData(day, countDays);
					break;
				}
			case 2:
				{
					today.putData(day, countDays);
					break;
				}
			case 3:
				{
					today.modifyData(day, countDays);
					break;
				}
			case 4:
				{
					today.generateReport(day, countDays);
					break;
				}
			default:
				{
					cout << "Invalid selection! Select a number between 1-3";
					break;
				}
		}
		cout << "\nDo you want to perform another operation? (y/n)";
		cin >> repeat;
	}
	
	return 0;
}
