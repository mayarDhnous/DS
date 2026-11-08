
//q1;
//#include <iostream>
//using namespace std;
//void print(int a[], int size)
//{
//    for (int i = 0; i < 20; ++i) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
//}
//double Avg(int a[], int size) {
//    int sum = 0;
//    for (int i = 0; i < 20; ++i) {
//        sum += a[i];
//    }
//    return sum / 20;
//}
//void Max(int a[], int size) {
//    int max = a[0]; int maxi = 0;
//    for (int i = 1; i < 20; ++i) {
//        if (a[i] > max)
//        {
//           max = a[i];
//            maxi = i;
//        }
//    }
//    cout << max << "index is " << maxi;
//}
//int even(int a[], int size) {
//    int c=0;
//    for (int i = 0; i < 20; ++i) {
//        if (a[i]%2 == 0)
//            c++;
//
//
//    }
//    return c;
//}
//int BigThanAvg(int a[], int size) {
//    int c=0;
//    for (int i = 0; i < 20; ++i) {
//        if (a[i] > Avg(a,20))
//            c++;
//    }
//    return c;
//}
//void rev(int a[], int size) {
//    for (int i = 0; i < size/2; ++i) {
//        int temp;
//        temp = a[i];
//        a[i] = a[size - i - 1];
//        a[size - i - 1] = temp;
//
//    }
//    
//}
//int main()
//{
//    int arr[20];
//    for (int i = 0; i < 20; ++i) {
//        arr[i]=rand()%50+5;
//    }
//    print(arr, 20);
//    cout << "AVG" << Avg(arr, 20)<<endl;
//    Max(arr, 20);
//    cout << "there is " << even(arr, 20) << "even number "<<endl;
//    cout << "there is " << BigThanAvg(arr, 20) << "Bigger than Avg "<<endl;
//    rev(arr, 20);
//    print(arr, 20);
//}



//q2
//#include <iostream>
//using namespace std;
//struct employee {
//	double salary;
//	string name;
//	int id;
//
//};
//int main() {
//	employee a[4];
//	employee maxSalary = a[0];
//	int sum = 0;
//	
//	for (int i = 0; i < 4; ++i) {
//		cout << "info e" << i+1 << endl;
//		cin >> a[i].id;
//		cin >> a[i].name;
//		cin >> a[i].salary;
//		sum += a[i].salary;
//
//	}
//	for (int i = 1; i < 4; ++i) {
//		if (maxSalary.salary < a[i].salary)
//			maxSalary = a[i];
//	}
//	cout << maxSalary.name << maxSalary.id << maxSalary.salary;
//
//	cout << "Avg=" <<(double) sum / 4;
//	for (int i =0; i < 4; ++i) {
//		if (a[i].salary < (double)sum / 4)
//		{
//			cout << a[i].name << endl;
//			a[i].salary *= (1 + 0.1);
//
//		}
//		
//	}
//	for (int i = 0; i < 4; ++i) {
//		cout << "info e after" << i + 1 << endl;
//		cout<< a[i].id;
//		cout<< a[i].name;
//		cout<< a[i].salary<<endl;
//		
//
//	}
//}

//7. اﻣﺘﺤﺎن ﺗﺠﺮﻳﺒﻲ 5 اﻟﺸﺎﻣﻞ )75 دﻗﻴﻘﺔ(: class + menu ﻋﻠﻰ array دﻳﻨﺎﻣﻴﻜﻲ
#include <iostream>
using namespace std;
struct item {
		string name;
		double price;
		int qty;
};
class inventor
{
public:

	inventor(int ncap = 2)
	{
		m_size = 0;
		cap =ncap ;
		items = new item[cap];
	}

	~inventor()
	{
		delete[]items;
	}
	void addItem(string name,int price,int qty)
	{
		if (m_size == cap)
			grow();
		items[m_size ].name = name;
		items[m_size ].price = price;
		items[m_size ].qty = qty;
		m_size++;
	}
	
	void print() {
		if (m_size == 0)
			cout << "empty"<<endl;
		
		cout << "info for each item " << endl;
		for (int i = 0; i < m_size; i++)
		{
			cout<< "item  " << i+1<<endl;
			cout << items[i].name << " " << items[i].price<<" " << items[i].qty << endl;
		}
	}
	double totalValue(int i) {
		if (m_size <= i)
			return 0;
		else
			return items[i].price * items[i].qty + totalValue(i + 1);
	}

	void MostExpensive()
	{
		if (m_size == 0) {

	    cout << "empty" << endl;
		return;
		}
		item max = items[0];
		for (int  i = 1; i < m_size; i++)
		{
			if (items[i].price > max.price)
			{
				max = items[i];
			}
		}
		cout << "Most Expensiive is " << max.name << " " << max.price << " " << max.qty << endl;

	}
	int search(string name) {
		int nameIndex = 0;
		for (int i = 0; i < m_size; i++) {

			if (name == items[i].name)
			{
				return nameIndex = i;
		}
		}
			return 0;

	}
	void removeLast() {
		if (m_size == 0) {
        cout << "there is no items" << endl;
		return;
		}
			
		else
		{
       
		m_size--;
		}
			
	}
	int getsize( ) {
		return m_size;
	}
private:

	int m_size;
	int cap;
	item* items;

	void grow() {
		cap *= 2;
		item* bigger= new item[cap];
		for (int  i = 0; i < m_size; i++)
		{
			bigger[i] = items[i];
		}
		delete[]items;
		items = bigger;
	}
};

int main() {
    inventor ti(2);
	string name; int price, qty;
    string searchn;
	int choice;
	cout << "1.Add item، 2. Print items، 3. Total value، 4. Most expensive، 5. Search by name، 6.Remove last item 7. Exit "<<endl;
	do
	{
		cout<< "Enter Choice: " << endl;
	cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter name ,price ,qty";
		    cin >> name >> price >> qty;
			ti.addItem(name,price,qty);
			break;
		case 2:
			ti.print();
			break;

		case 3:
			cout << "total: " << ti.totalValue(0) << endl;
			break;
			
		case 4:
			ti.MostExpensive();
			break;
		case 5:
			cout << "enter a name:";
			cin >> searchn;

			if (ti.search(searchn))
				cout << "Found at index " << ti.search(searchn) << endl;
			else
				cout << "Not found" << endl;
			break;
		case 6:
			ti.removeLast();
			break;
		case 7:
			break;
		default:
			cout << "invalid"<<endl;

	 }

	} while (choice!=7);
	return 0;
}