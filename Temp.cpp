//class Department;
//class Teacher
//{
//	string name;
//	string subject;
//	Department* departments[100];
//	int count = 0;
//public:
//	void input()
//	{
//		cout << "enter teacher name: " << endl;
//		cin >> name;
//		cout << "enter teacher subject: " << endl;
//		cin >> subject;
//	}
//
//	void display()
//	{
//		cout << "Name: " << name << endl;
//		cout << "Subject: " << subject << endl;
//	}
//
//	string getname()
//	{
//		return name;
//	}
//	string getcourse()
//	{
//		return subject;
//	}
//	void addDepartment(Department* d);
//	void displayDepartment();
//	void removeDepartment(Department* d);
//};
//
//
//class Department
//{
//	string name;
//	Teacher* teachers[10];
//	int count = 0;
//public:
//	void input()
//	{
//		cout << "enter department name: " << endl;
//		cin >> name;
//	}
//
//	void display()
//	{
//		cout << "Department name: " << name << endl;
//	}
//
//	void addTeacher(Teacher* t)
//	{
//		teachers[count++] = t;
//		cout << "Teacher " << t->getname() << " is assigned to department: " << name << endl;
//	}
//	void removeTeacher(Teacher* t)
//	{
//		for (int i = 0; i < count; i++)
//		{
//			if (teachers[i] == t)
//			{
//				for (int j = 1; j < count; j++)
//				{
//					teachers[j] = teachers[j + 1];
//				}
//				count--;
//				cout << t->getname() << " is removed from deparmtent: " << name << endl;
//				return;
//			}
//		}
//	}
//
//	void displayTeacher()
//	{
//		cout << name << " has following teachers: " << endl;
//		for (int i = 0; i < count; i++)
//		{
//			cout << teachers[i]->getname() << " teaching course: " << teachers[i]->getcourse()<<endl;
//		}
//	}
//
//	string getname()
//	{
//		return name;
//	}
//};
//
//
//void Teacher::addDepartment(Department* d)
//{
//	departments[count++] = d;
//	cout << d->getname() << " is assigned to teacher: " << name << endl;
//
//}
//
//void Teacher::displayDepartment()
//{
//	cout << "teacher " << name << " is assigned to follwing departments: " << endl;
//	for (int i = 0; i < count; i++)
//	{
//		cout << departments[i]->getname()<<endl;
//	}
//}
//
//void Teacher::removeDepartment(Department* d)
//{
//	for (int i = 0; i < count; i++)
//	{
//		if (departments[i] == d)
//		{
//			for (int j = 1; j < count; j++)
//			{
//				departments[j] = departments[j + 1];
//			}
//			count--;
//			cout << d->getname() << " is removed from deparmtent: " << name << endl;
//			return;
//		}
//	}
//}
//int main()
//{
//	Teacher t1;
//	Teacher t2;
//
//	Department d1;
//	Department d2;
//
//	t1.input();
//	t2.input();
//
//	d1.input();
//	d2.input();
//
//	t1.addDepartment(&d1);
//	t1.addDepartment(&d2);
//
//	t1.display();
//	t1.displayDepartment();
//
//
//	d1.addTeacher(&t1);
//	d1.addTeacher(&t2);
//
//	d1.display();
//	d1.displayTeacher();
//
//	t1.removeDepartment(&d1);
//	t1.displayDepartment();
//}