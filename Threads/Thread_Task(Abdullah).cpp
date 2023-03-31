#include<iostream>
#include<fstream>
#include<pthread.h>
#include<unistd.h>
#include<string>

using namespace std;

struct Student_GPA
{
	float Grade_Point[5];
	string name;
};

void* Take_Input(void* arg)
{
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	float *obtained_marks = new float[5];

	cout << "Enter Marks Obtained in Sports Analysis: ";
	cin >> obtained_marks[0];

	cout << "Enter Marks Obtained in Statistics: ";
	cin >> obtained_marks[1];
	
	cout << "Enter Marks Obtained in Entreprenaurship: ";
	cin >> obtained_marks[2];

	cout << "Enter Marks Obtained in Crowd Funding: ";
	cin >> obtained_marks[3];

	cout << "Enter Marks Obtained in Social Marketing: ";
	cin >> obtained_marks[4];

	pthread_exit((void*)(obtained_marks));
}

void* calculate_points(void* arg)
{

	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	Student_GPA *record = (Student_GPA*)(arg);
	float temp = 0;	

	cout << "In function: ";
	
	for(int i = 0; i < 5; i++)
	{
		temp = record->Grade_Point[i]/100 * 4;
		if(temp > 3.5) 
			record->Grade_Point[i] = 4;
		else if(temp < 3.5 and temp > 2.5)
			record->Grade_Point[i] = 3;
		else if(temp < 2.5 and temp > 1.5)
			record->Grade_Point[i] = 2;
		else
			record->Grade_Point[i] = 0;	

	}

	for(int i = 0; i < 5; i++)
	{
		cout << record->Grade_Point[i] << " "; 
	}
	
	cout << endl;

	pthread_exit((void*)(record));
}

int main()
{
	void* status = NULL;
	
	Student_GPA student1;	
	cout << "Enter Student Name: ";
	getline(cin,student1.name);

	pthread_t thr1;
	pthread_attr_t thread_attr1;	
	pthread_attr_init(&thread_attr1);
	pthread_attr_setdetachstate(&thread_attr1, PTHREAD_CREATE_JOINABLE);

	pthread_create(&thr1,&thread_attr1,Take_Input,NULL);		
	pthread_join(thr1, &status);
	
	

	cout << endl << endl << "Student: " << student1.name << endl << "Marks: ";	
	
	float *returned_inputs = (float*)(status);

	for(int i = 0; i < 5; i++)
	{
		student1.Grade_Point[i] = returned_inputs[i];
		cout << student1.Grade_Point[i] << " "; 
	}

	cout << endl;	

	pthread_t thr2;
	pthread_attr_t thread_attr2;	
	pthread_attr_init(&thread_attr2);
	pthread_attr_setdetachstate(&thread_attr2, PTHREAD_CREATE_JOINABLE);

	pthread_create(&thr2,&thread_attr2,calculate_points,&student1);		
	pthread_join(thr2, &status);
		
	Student_GPA *returned_obj = (Student_GPA*)(status);

	cout << endl << endl << "Main has: ";
	for(int i = 0; i < 5; i++)
	{
		cout << returned_obj->Grade_Point[i] << " "; 
	}
	
	cout << endl << "Student name: " << returned_obj->name << endl;

	float GPA = 0;
	for(int i = 0; i < 5; i++)
	{
		GPA += returned_obj->Grade_Point[i] * 4;
	}

	GPA = GPA / (4*5);

	fstream FileName;
	FileName.open("21I-2477_grade-points.txt", ios :: out);
	if(FileName)
	{
		FileName << returned_obj->name << '\n';
		
		for(int i = 0; i < 5; i++)
		{
			if(returned_obj->Grade_Point[i] == 4)
			{
				FileName << "A = ";
			}
			else if(returned_obj->Grade_Point[i] == 3)
			{
				FileName << "C = ";
			}
			else if(returned_obj->Grade_Point[i] == 2)
			{
				FileName << "B = ";
			}
			else
			{
				FileName << "F = ";
			}
			FileName << returned_obj->Grade_Point[i];
			FileName << '\n';
		}

		FileName << '\n' << '\n';
		FileName << "GPA = " << GPA;	
	}
		
	else
	{
		cout << "Error Opening File" << endl;
	}
	
	FileName.close();




	sleep(1);
	exit(0);
	
	return 0;
	
}

