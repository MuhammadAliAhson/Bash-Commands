#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include "fstream"
using namespace std;

#define NUM_SUBJECTS 5

struct student_info {
    char name[50];
    int course[5];
    
   
};

struct grade_info {
    char name[50];
    int grade_points[5];
};

void *calculate_grades(void *arg) {
    struct student_info *student = (struct student_info *)arg;
   struct grade_info *grades = new grade_info();
    for(int i=0;i<5;i++){
    grades->grade_points[i]=   (student->course[i]/100) * 4;
    }
    for(int i=0;i<50;i++){
    grades->name[i]=student->name[i];
    }
    return (void *)grades;
}

void *calculate_gpa(void *arg) {
    struct grade_info *grades = (struct grade_info *)arg;
    int i,total_grade_points;
    for (i = 0; i < 5; i++) {
        total_grade_points += grades->grade_points[i];
    }
    float gpa = total_grade_points / NUM_SUBJECTS;
    char filename[50];
    sprintf(filename, "21i-2535_GPA");
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%s %.2f\n", grades->name, gpa);
    fclose(fp);
    return NULL;
}

int main() {
    pthread_t input_thread, grade_thread, gpa_thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    struct student_info student;
    cout<<"Enter student name: ";
    cin.getline(student.name, 50);

    int i;
    for (i = 0; i < 5; i++) {
        cout<<"Enter marks for subject  "<< i+1;
        cin>>student.course[i];
    }

    pthread_create(&grade_thread, &attr, calculate_grades, (void *)&student);
    
    
    void * status;
    
    pthread_join(grade_thread, &status);

    struct grade_info *grades = (grade_info *)status;



  char filename[50] = "20i-2535_grade-points";
    ofstream outfile("20i-2535_grade-points", std::ios_base::app);
    outfile << grades->name << " ";
    for (i = 0; i < 5; i++) {
        outfile << student.course[i] << "/" << grades->grade_points[i] << " ";
    }
    outfile << std::endl;
    outfile.close();

    pthread_create(&gpa_thread, &attr, calculate_gpa, (void *)&grades);
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
    return 0;
}

