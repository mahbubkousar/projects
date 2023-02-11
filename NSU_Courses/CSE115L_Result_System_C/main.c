/*
 *                  DOCUMENTATION
 *
 *                    PROJECT
 *             CSE 115 LAB - SECTION 6
 *
 *    Submitted by :
 *                  Mahbubur Rahman Khan
 *                  NSU ID : 221804042
 *                  Email : mahbubur.khan@northsouth.edu
 *
 *  Project Details :
 *                  > A program using C Porgramming Language to store student information
 *                  > It will also calculate students' new Grade & CGPA
 *                  > Finding highest total from the data-set
 *                  > Finding student information for a custom search
 *                  > Creating new text files to store all data
 *
 *   Limitations : I have calculated all students' information only for one course.
 *
 *   Ideone link : https://ideone.com/Nje2AN
 *
 */


#include <stdio.h>
#include <string.h>

#define MAX_STUDENT 100



//Functions used in this program:

void create_new_file (void);
void input_data(void);
void add_new(void);
void student_grade(void);
void student_cgpa(void);
void highest_total(void);
void selected_grade(void);
void delete_all (void);




// Main Structure for this program
struct Student_information
{
    struct Basic_information
    {
        char name[30];
        char id[20];
        char email[30];
        char phone[20];
        char address[30];
        char dob[20];
    } basic;

    struct Previous_Education_information
    {
        char ssc_institution[20];
        int ssc_year_of_exam;
        float ssc_grade;
        char hsc_institution[20];
        int hsc_year_of_exam;
        float hsc_grade;
    } previous;

    struct NSU_Information
    {
        char department[20];
        int number_sem;
        float prev_cgpa;
        float new_cgpa;

        struct Semester
        {
            char semester_name[20];
            int number_of_courses;
            float cgpa;  //Not user input, will be calculated later
            char grade[3];  //Not user input, will be calculated later
            float avg_total;

            struct Course
            {
                char course_name[20];
                char faculty_name[20];
                int credit_number;
                float course_cgpa;
                float course_grade;
                struct Exam
                {
                    float quiz1;
                    float quiz2;
                    float quiz3;
                    float quiz_avg; //Not user input, will be calculated later
                    float mid1;
                    float mid2;
                    float mid_avg;  //Not user input, will be calculated later
                    float assignment;
                    float mark_final;
                    float total; //Not user input, will be calculated later
                    char course_grade[3]; //Not user input, will be calculated later
                    float course_cgpa; //Not user input, will be calculated later
                } exam;
            } course[3];
        } semester;
    } nsu;

};






int main(void)
{

    //Documentation Area starts
    printf("\n\n");
    printf("\t\t\tCSE115 LAB : SECTION 6     |   Submitted by : \n");
    printf("\t\t\t                           |   Mahbubur Rahman Khan  \n");
    printf("\t\t\t    P R O J E C T          |   NSU Id : 2211804042 \n");
    printf("\t\t       -------------------------------------------------------- \n\n\n");
    //Documentation Area ends



    //Main menu section
    int choice;
    do
    {
        printf("\n\n\n\t\t\t------------------------------------------------------------------\n");
        printf("\t\t\t|           >>>>>>>>>>>  Main Menu  <<<<<<<<<<<<                 |\n");
        printf("\t\t\t|                                                                |\n");
        printf("\t\t\t|  |1| Create new blank file      \t|5| Get student grade    |\n");
        printf("\t\t\t|  |2| Input student data         \t|6| Get student CGPA     |\n");
        printf("\t\t\t|  |3| Add a new data             \t|7| Get highest total    |\n");
        printf("\t\t\t|  |4| Selected grade list        \t|8| Delete all data      |\n");
        printf("\t\t\t|  |0| Exit program                                              |\n");
        printf("\t\t\t------------------------------------------------------------------\n");
        printf("\t\t\t|  >>> Your choice : ");
        scanf("%d",&choice);
        printf("\n\t\t\t|----------------------------------------------------------------|\n");



        switch (choice)
        {
        case 1:
            system("cls");
            create_new_file();
            break;
        case 2:
            system("cls");
            input_data();
            break;
        case 3:
            system("cls");
            add_new();
            break;
        case 4:
            system("cls");
            selected_grade();
            break;
        case 5:
            system("cls");
            student_grade();
            break;
        case 6:
            system("cls");
            student_cgpa();
            break;
        case 7:
            system("cls");
            highest_total();
            break;
        case 8:
            system("cls");
            delete_all();
            break;
            system("cls");
        case 0:
            break;

        default :
        {
            printf("\n\n\t\t\t\tWrong input, re-run the program.\n\n\n");

        }
        }
    }
    while(choice!=0);

    return 0;
}

// Functions :



void create_new_file (void)
{
    FILE *fp;
    fp = fopen("student_info.txt","w");
    if(fp)
    {
        printf("\n\n\n\t\t\t\t\tNew blank file created successfully.\n");
        printf("\t\t\t\t\t       (stuednt_info.txt) \n\n");
    }
    else printf("\n\n\t\t\tERROR : New file creation failed!  \n\n");
    fclose(fp);
}


void input_data(void)
{
    FILE *fp;
    fp = fopen("student_info.txt","a");
    int i,n;
    printf("\n\n\t\t\tTotal number of students : ");
    scanf("%d",&n);
    struct Student_information s[n];
    printf("\n\n\t\t\tStudent information >\n");
    printf("\n\t\t\t-------------------\n\n");
    for(i=0; i<n; i++)
    {
        printf("\t\t\t Student %d :\n",i+1);
        printf("\n\t\t\t  Basic Information >\n\n");
        printf("\t\t\t  Name : ");
        scanf("%s",&s[i].basic.name);

        printf("\t\t\t  NSU Id : ");
        scanf("%s",&s[i].basic.id);

        printf("\t\t\t  Email : ");
        scanf("%s",&s[i].basic.email);

        printf("\t\t\t  Phone : ");
        scanf("%s",&s[i].basic.phone);

        printf("\t\t\t  Address : ");
        scanf("%s",&s[i].basic.address);

        printf("\t\t\t  Date of Birth : ");
        scanf("%s",&s[i].basic.dob);

        printf("\n\n\t\t\t  Previous Education Information >\n\n");
        printf("\t\t\t  SSC/O-Level Institution : ");
        scanf("%s",&s[i].previous.ssc_institution);

        printf("\t\t\t  SSC/O-Level Year of exam : ");
        scanf("%d",&s[i].previous.ssc_year_of_exam);

        printf("\t\t\t  SSC/O-Level Grade : ");
        scanf("%f",&s[i].previous.ssc_grade);

        printf("\t\t\t  HSC/A-Level Institution : ");
        scanf("%s",&s[i].previous.hsc_institution);

        printf("\t\t\t  HSC/A-Level Year of exam : ");
        scanf("%d",&s[i].previous.hsc_year_of_exam);

        printf("\t\t\t  HSC/A-Level Grade : ");
        scanf("%f",&s[i].previous.hsc_grade);

        printf("\n\n\t\t\t  NSU Information >\n\n");
        printf("\t\t\t  Department : ");
        scanf("%s",&s[i].nsu.department);

        printf("\t\t\t  Number of completed semester : ");
        scanf("%d",&s[i].nsu.number_sem);

        printf("\t\t\t  Previous CGPA : ");
        scanf("%f",&s[i].nsu.prev_cgpa);

        printf("\n\n\t\t\t    Semester >\n\n");

        printf("\t\t\t      Semester Name : ");
        scanf("%s",&s[i].nsu.semester.semester_name);

        printf("\t\t\t      No of Courses : 2 (By Default)\n");
        s[i].nsu.semester.number_of_courses = 3;

        printf("\n\n\t\t\t      Course >\n\n");
        printf("\t\t\t        Course #1 :  \n");
        printf("\t\t\t        Course Name :  ");
        scanf("%s",&s[i].nsu.semester.course[0].course_name);

        printf("\t\t\t        Faculty Name :  ");
        scanf("%s",&s[i].nsu.semester.course[0].faculty_name);

        printf("\t\t\t        Credit Number :  ");
        scanf("%d",&s[i].nsu.semester.course[0].credit_number);

        printf("\n\n\t\t\t          Exams of course #1 > \n\n");
        printf("\t\t\t            Quiz1 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.quiz1);

        printf("\t\t\t            Quiz2 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.quiz2);

        printf("\t\t\t            Quiz3 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.quiz3);

        s[i].nsu.semester.course[0].exam.quiz_avg = ((s[i].nsu.semester.course[0].exam.quiz1 + s[i].nsu.semester.course[0].exam.quiz2 + s[i].nsu.semester.course[0].exam.quiz3) / 3.0) * 0.20 ;


        printf("\t\t\t            Mid1 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.mid1);
        printf("\t\t\t            Mid2 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.mid2);
        s[i].nsu.semester.course[0].exam.mid_avg = ((s[i].nsu.semester.course[0].exam.mid1 + s[i].nsu.semester.course[0].exam.mid2 ) /2.0) * .30;


        printf("\t\t\t            Assignment : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.assignment);

        s[i].nsu.semester.course[0].exam.assignment = s[i].nsu.semester.course[0].exam.assignment * 0.20;

        printf("\t\t\t            Final : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.mark_final);

        s[i].nsu.semester.course[0].exam.mark_final = s[i].nsu.semester.course[0].exam.mark_final * 0.30;

        s[i].nsu.semester.course[0].exam.total = s[i].nsu.semester.course[0].exam.quiz_avg + s[i].nsu.semester.course[0].exam.mid_avg + s[i].nsu.semester.course[0].exam.assignment + s[i].nsu.semester.course[0].exam.mark_final;

        printf("\n\t\t\t            Total Marks (Course#1 : %s)  : %.2f\n\n\n",s[i].nsu.semester.course[0].course_name,s[i].nsu.semester.course[0].exam.total);




        printf("\n\n\t\t\t       \n\n");
        printf("\t\t\t        Course #2 :  \n");
        printf("\t\t\t        Course Name :  ");
        scanf("%s",&s[i].nsu.semester.course[1].course_name);

        printf("\t\t\t        Faculty Name :  ");
        scanf("%s",&s[i].nsu.semester.course[1].faculty_name);

        printf("\t\t\t        Credit Number :  ");
        scanf("%d",&s[i].nsu.semester.course[1].credit_number);

        printf("\n\n\t\t\t          Exams of course #2 > \n\n");
        printf("\t\t\t            Quiz1 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.quiz1);

        printf("\t\t\t            Quiz2 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.quiz2);

        printf("\t\t\t            Quiz3 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.quiz3);

        s[i].nsu.semester.course[1].exam.quiz_avg = ((s[i].nsu.semester.course[1].exam.quiz1 + s[i].nsu.semester.course[1].exam.quiz2 + s[i].nsu.semester.course[1].exam.quiz3) / 3.0) * 0.20 ;


        printf("\t\t\t            Mid1 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.mid1);
        printf("\t\t\t            Mid2 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.mid2);
        s[i].nsu.semester.course[1].exam.mid_avg = ((s[i].nsu.semester.course[1].exam.mid1 + s[i].nsu.semester.course[1].exam.mid2 ) /2.0) * .30;


        printf("\t\t\t            Assignment : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.assignment);

        s[i].nsu.semester.course[1].exam.assignment = s[i].nsu.semester.course[1].exam.assignment * 0.20;

        printf("\t\t\t            Final : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.mark_final);

        s[i].nsu.semester.course[1].exam.mark_final = s[i].nsu.semester.course[1].exam.mark_final * 0.30;

        s[i].nsu.semester.course[1].exam.total = s[i].nsu.semester.course[1].exam.quiz_avg + s[i].nsu.semester.course[1].exam.mid_avg + s[i].nsu.semester.course[1].exam.assignment + s[i].nsu.semester.course[1].exam.mark_final;

        printf("\n\t\t\t            Total Marks (Course#2 : %s)  : %.2f\n\n\n",s[i].nsu.semester.course[1].course_name,s[i].nsu.semester.course[1].exam.total);


    }
    for(i=0; i<n; i++)
    {
        fprintf(fp,"%s %s %s %s %s %s %s %d %f %s %d %f %s %d %f %s %d %s %s %d %f %f %f %f %f %s %s %d %f %f %f %f %f\n",s[i].basic.name,s[i].basic.id,s[i].basic.email,s[i].basic.phone,s[i].basic.address,s[i].basic.dob,s[i].previous.ssc_institution,s[i].previous.ssc_year_of_exam,s[i].previous.ssc_grade,s[i].previous.hsc_institution,s[i].previous.hsc_year_of_exam,s[i].previous.hsc_grade,s[i].nsu.department,s[i].nsu.number_sem,s[i].nsu.prev_cgpa,s[i].nsu.semester.semester_name,s[i].nsu.semester.number_of_courses,s[i].nsu.semester.course[0].course_name,s[i].nsu.semester.course[0].faculty_name,s[i].nsu.semester.course[0].credit_number,s[i].nsu.semester.course[0].exam.quiz_avg,s[i].nsu.semester.course[0].exam.mid_avg,s[i].nsu.semester.course[0].exam.assignment,s[i].nsu.semester.course[0].exam.mark_final,s[i].nsu.semester.course[0].exam.total,s[i].nsu.semester.course[1].course_name,s[i].nsu.semester.course[1].faculty_name,s[i].nsu.semester.course[1].credit_number,s[i].nsu.semester.course[1].exam.quiz_avg,s[i].nsu.semester.course[1].exam.mid_avg,s[i].nsu.semester.course[1].exam.assignment,s[i].nsu.semester.course[1].exam.mark_final,s[i].nsu.semester.course[1].exam.total);

    }

    fclose(fp);
}

void add_new(void)
{
    FILE *fp;
    fp = fopen("student_info.txt","a");
    int i,n;
    printf("\n\n\t\t\tTotal number of students : ");
    scanf("%d",&n);
    struct Student_information s[n];
    printf("\n\n\t\t\tStudent information >\n");
    printf("\n\t\t\t-------------------\n\n");
    for(i=0; i<n; i++)
    {
        printf("\t\t\t Student %d :\n",i+1);
        printf("\n\t\t\t  Basic Information >\n\n");
        printf("\t\t\t  Name : ");
        scanf("%s",&s[i].basic.name);

        printf("\t\t\t  NSU Id : ");
        scanf("%s",&s[i].basic.id);

        printf("\t\t\t  Email : ");
        scanf("%s",&s[i].basic.email);

        printf("\t\t\t  Phone : ");
        scanf("%s",&s[i].basic.phone);

        printf("\t\t\t  Address : ");
        scanf("%s",&s[i].basic.address);

        printf("\t\t\t  Date of Birth : ");
        scanf("%s",&s[i].basic.dob);

        printf("\n\n\t\t\t  Previous Education Information >\n\n");
        printf("\t\t\t  SSC/O-Level Institution : ");
        scanf("%s",&s[i].previous.ssc_institution);

        printf("\t\t\t  SSC/O-Level Year of exam : ");
        scanf("%d",&s[i].previous.ssc_year_of_exam);

        printf("\t\t\t  SSC/O-Level Grade : ");
        scanf("%f",&s[i].previous.ssc_grade);

        printf("\t\t\t  HSC/A-Level Institution : ");
        scanf("%s",&s[i].previous.hsc_institution);

        printf("\t\t\t  HSC/A-Level Year of exam : ");
        scanf("%d",&s[i].previous.hsc_year_of_exam);

        printf("\t\t\t  HSC/A-Level Grade : ");
        scanf("%f",&s[i].previous.hsc_grade);

        printf("\n\n\t\t\t  NSU Information >\n\n");
        printf("\t\t\t  Department : ");
        scanf("%s",&s[i].nsu.department);

        printf("\t\t\t  Number of completed semester : ");
        scanf("%d",&s[i].nsu.number_sem);

        printf("\t\t\t  Previous CGPA : ");
        scanf("%f",&s[i].nsu.prev_cgpa);

        printf("\n\n\t\t\t    Semester >\n\n");

        printf("\t\t\t      Semester Name : ");
        scanf("%s",&s[i].nsu.semester.semester_name);

        printf("\t\t\t      No of Courses : 2 (By Default)\n");
        s[i].nsu.semester.number_of_courses = 3;

        printf("\n\n\t\t\t      Course >\n\n");
        printf("\t\t\t        Course #1 :  \n");
        printf("\t\t\t        Course Name :  ");
        scanf("%s",&s[i].nsu.semester.course[0].course_name);

        printf("\t\t\t        Faculty Name :  ");
        scanf("%s",&s[i].nsu.semester.course[0].faculty_name);

        printf("\t\t\t        Credit Number :  ");
        scanf("%d",&s[i].nsu.semester.course[0].credit_number);

        printf("\n\n\t\t\t          Exams of course #1 > \n\n");
        printf("\t\t\t            Quiz1 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.quiz1);

        printf("\t\t\t            Quiz2 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.quiz2);

        printf("\t\t\t            Quiz3 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.quiz3);

        s[i].nsu.semester.course[0].exam.quiz_avg = ((s[i].nsu.semester.course[0].exam.quiz1 + s[i].nsu.semester.course[0].exam.quiz2 + s[i].nsu.semester.course[0].exam.quiz3) / 3.0) * 0.20 ;


        printf("\t\t\t            Mid1 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.mid1);
        printf("\t\t\t            Mid2 : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.mid2);
        s[i].nsu.semester.course[0].exam.mid_avg = ((s[i].nsu.semester.course[0].exam.mid1 + s[i].nsu.semester.course[0].exam.mid2 ) /2.0) * .30;


        printf("\t\t\t            Assignment : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.assignment);

        s[i].nsu.semester.course[0].exam.assignment = s[i].nsu.semester.course[0].exam.assignment * 0.20;

        printf("\t\t\t            Final : ");
        scanf("%f",&s[i].nsu.semester.course[0].exam.mark_final);

        s[i].nsu.semester.course[0].exam.mark_final = s[i].nsu.semester.course[0].exam.mark_final * 0.30;

        s[i].nsu.semester.course[0].exam.total = s[i].nsu.semester.course[0].exam.quiz_avg + s[i].nsu.semester.course[0].exam.mid_avg + s[i].nsu.semester.course[0].exam.assignment + s[i].nsu.semester.course[0].exam.mark_final;

        printf("\n\t\t\t            Total Marks (Course#1 : %s)  : %.2f\n\n\n",s[i].nsu.semester.course[0].course_name,s[i].nsu.semester.course[0].exam.total);




        printf("\n\n\t\t\t       \n\n");
        printf("\t\t\t        Course #2 :  \n");
        printf("\t\t\t        Course Name :  ");
        scanf("%s",&s[i].nsu.semester.course[1].course_name);

        printf("\t\t\t        Faculty Name :  ");
        scanf("%s",&s[i].nsu.semester.course[1].faculty_name);

        printf("\t\t\t        Credit Number :  ");
        scanf("%d",&s[i].nsu.semester.course[1].credit_number);

        printf("\n\n\t\t\t          Exams of course #2 > \n\n");
        printf("\t\t\t            Quiz1 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.quiz1);

        printf("\t\t\t            Quiz2 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.quiz2);

        printf("\t\t\t            Quiz3 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.quiz3);

        s[i].nsu.semester.course[1].exam.quiz_avg = ((s[i].nsu.semester.course[1].exam.quiz1 + s[i].nsu.semester.course[1].exam.quiz2 + s[i].nsu.semester.course[1].exam.quiz3) / 3.0) * 0.20 ;


        printf("\t\t\t            Mid1 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.mid1);
        printf("\t\t\t            Mid2 : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.mid2);
        s[i].nsu.semester.course[1].exam.mid_avg = ((s[i].nsu.semester.course[1].exam.mid1 + s[i].nsu.semester.course[1].exam.mid2 ) /2.0) * .30;


        printf("\t\t\t            Assignment : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.assignment);

        s[i].nsu.semester.course[1].exam.assignment = s[i].nsu.semester.course[1].exam.assignment * 0.20;

        printf("\t\t\t            Final : ");
        scanf("%f",&s[i].nsu.semester.course[1].exam.mark_final);

        s[i].nsu.semester.course[1].exam.mark_final = s[i].nsu.semester.course[1].exam.mark_final * 0.30;

        s[i].nsu.semester.course[1].exam.total = s[i].nsu.semester.course[1].exam.quiz_avg + s[i].nsu.semester.course[1].exam.mid_avg + s[i].nsu.semester.course[1].exam.assignment + s[i].nsu.semester.course[1].exam.mark_final;

        printf("\n\t\t\t            Total Marks (Course#2 : %s)  : %.2f\n\n\n",s[i].nsu.semester.course[1].course_name,s[i].nsu.semester.course[1].exam.total);


    }
    for(i=0; i<n; i++)
    {
        fprintf(fp,"%s %s %s %s %s %s %s %d %f %s %d %f %s %d %f %s %d %s %s %d %f %f %f %f %f %s %s %d %f %f %f %f %f\n",s[i].basic.name,s[i].basic.id,s[i].basic.email,s[i].basic.phone,s[i].basic.address,s[i].basic.dob,s[i].previous.ssc_institution,s[i].previous.ssc_year_of_exam,s[i].previous.ssc_grade,s[i].previous.hsc_institution,s[i].previous.hsc_year_of_exam,s[i].previous.hsc_grade,s[i].nsu.department,s[i].nsu.number_sem,s[i].nsu.prev_cgpa,s[i].nsu.semester.semester_name,s[i].nsu.semester.number_of_courses,s[i].nsu.semester.course[0].course_name,s[i].nsu.semester.course[0].faculty_name,s[i].nsu.semester.course[0].credit_number,s[i].nsu.semester.course[0].exam.quiz_avg,s[i].nsu.semester.course[0].exam.mid_avg,s[i].nsu.semester.course[0].exam.assignment,s[i].nsu.semester.course[0].exam.mark_final,s[i].nsu.semester.course[0].exam.total,s[i].nsu.semester.course[1].course_name,s[i].nsu.semester.course[1].faculty_name,s[i].nsu.semester.course[1].credit_number,s[i].nsu.semester.course[1].exam.quiz_avg,s[i].nsu.semester.course[1].exam.mid_avg,s[i].nsu.semester.course[1].exam.assignment,s[i].nsu.semester.course[1].exam.mark_final,s[i].nsu.semester.course[1].exam.total);

    }

    fclose(fp);
}


void student_grade(void)
{
    FILE *fp;
    fp = fopen("student_info.txt","r");
    int n=MAX_STUDENT,i=0;
    struct Student_information s[n];
    while(fscanf(fp,"%s%s%s%s%s%s%s%d%f%s%d%f%s%d%f%s%d%s%s%d%f%f%f%f%f%s%s%d%f%f%f%f%f\n",&s[i].basic.name,&s[i].basic.id,&s[i].basic.email,&s[i].basic.phone,&s[i].basic.address,&s[i].basic.dob,&s[i].previous.ssc_institution,&s[i].previous.ssc_year_of_exam,&s[i].previous.ssc_grade,&s[i].previous.hsc_institution,&s[i].previous.hsc_year_of_exam,&s[i].previous.hsc_grade,&s[i].nsu.department,&s[i].nsu.number_sem,&s[i].nsu.prev_cgpa,&s[i].nsu.semester.semester_name,&s[i].nsu.semester.number_of_courses,&s[i].nsu.semester.course[0].course_name,&s[i].nsu.semester.course[0].faculty_name,&s[i].nsu.semester.course[0].credit_number,&s[i].nsu.semester.course[0].exam.quiz_avg,&s[i].nsu.semester.course[0].exam.mid_avg,&s[i].nsu.semester.course[0].exam.assignment,&s[i].nsu.semester.course[0].exam.mark_final,&s[i].nsu.semester.course[0].exam.total,&s[i].nsu.semester.course[1].course_name,&s[i].nsu.semester.course[1].faculty_name,&s[i].nsu.semester.course[1].credit_number,&s[i].nsu.semester.course[1].exam.quiz_avg,&s[i].nsu.semester.course[1].exam.mid_avg,&s[i].nsu.semester.course[1].exam.assignment,&s[i].nsu.semester.course[1].exam.mark_final,&s[i].nsu.semester.course[1].exam.total) != EOF)

    {
        i++;
    }
    int j,x,y,z;
    char a[3] = "A";
    char b[3] = "A-";
    char c[3] = "B+";
    char d[3] = "B";
    char e[3] = "B-";
    char f[3] = "C+";
    char g[3] = "C";
    char h[3] = "C-";
    char ii[3] = "D+";
    char jj[3] = "D";
    char k[3] = "F";
    for(j=0; j<i; j++)
    {
        x = s[j].nsu.semester.course[0].exam.total;
        if(x>=93)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,a);
        else if(x>=90 && x<=92)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,b);
        else if(x>=87 && x<=89)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,c);
        else if(x>=83 && x<=86)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,d);
        else if(x>=80 && x<=82)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,e);
        else if(x>=77 && x<=79)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,f);
        else if(x>=73 && x<=76)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,g);
        else if(x>=70 && x<=72)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,h);
        else if(x>=67 && x<=69)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,ii);
        else if(x>=60 && x<=66)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,jj);
        else if(x<60)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,k);


        y = s[j].nsu.semester.course[1].exam.total;
        if(y>=93)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,a);
        else if(y>=90 && y<=92)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,b);
        else if(y>=87 && y<=89)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,c);
        else if(y>=83 && y<=86)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,d);
        else if(y>=80 && y<=82)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,e);
        else if(y>=77 && y<=79)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,f);
        else if(y>=73 && y<=76)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,g);
        else if(y>=70 && y<=72)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,h);
        else if(y>=67 && y<=69)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,ii);
        else if(y>=60 && y<=66)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,jj);
        else if(y<60)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,k);

        z = (s[j].nsu.semester.course[0].exam.total + s[j].nsu.semester.course[1].exam.total) / 2;

        if(z>=93)
            strcpy(s[j].nsu.semester.grade,a);
        else if(z>=90 && z<=92)
            strcpy(s[j].nsu.semester.grade,b);
        else if(z>=87 && z<=89)
            strcpy(s[j].nsu.semester.grade,c);
        else if(z>=83 && z<=86)
            strcpy(s[j].nsu.semester.grade,d);
        else if(z>=80 && z<=82)
            strcpy(s[j].nsu.semester.grade,e);
        else if(z>=77 && z<=79)
            strcpy(s[j].nsu.semester.grade,f);
        else if(z>=73 && z<=76)
            strcpy(s[j].nsu.semester.grade,g);
        else if(z>=70 && z<=72)
            strcpy(s[j].nsu.semester.grade,h);
        else if(z>=67 && z<=69)
            strcpy(s[j].nsu.semester.grade,ii);
        else if(z>=60 && z<=66)
            strcpy(s[j].nsu.semester.grade,jj);
        else if(z<60)
            strcpy(s[j].nsu.semester.grade,k);
    }

    FILE *fp1;
    fp1 = fopen("Student_grade.txt","w");

    for(j=0; j<i; j++)
    {
        fprintf(fp1,"Student #%d\n",j+1);
        fprintf(fp1,"\tName : %s\n",s[j].basic.name);
        fprintf(fp1,"\tNSU ID : %s  | Department : %s\n",s[j].basic.id,s[j].nsu.department);
        fprintf(fp1,"\tCourse1(%s) Grade : %s | Course2(%s) Grade : %s \n",s[j].nsu.semester.course[0].course_name,s[j].nsu.semester.course[0].exam.course_grade,s[j].nsu.semester.course[1].course_name,s[j].nsu.semester.course[1].exam.course_grade);
        fprintf(fp1,"\tCurrent Semester(%s) Grade : %s\n\n",s[j].nsu.semester.semester_name,s[j].nsu.semester.grade);
    }

    printf("\n\n\n\t\t\t\t\tStudent_grade.txt file created successfully.\n\n");
    printf("\t\t\t\t\t        File Contents \n\n");
    char t1[20] = "Name";
    char t2[20] = "ID";
    char t3[20] = "Course#1";
    char t4[20] = "Grade";
    char t5[20] = "Course#2";
    char t6[20] = "Grade";
    char t7[20] = "Grade";
    printf("\t%-10s %-12s %7s:Grade \t %7s:Grade \t Semester Grade\n\n",t1,t2,t3,t5);
    for(j=0; j<i; j++)
    {
        printf("\t%-10s %-12s %7s:%s \t %7s:%s \t\t %s\n",s[j].basic.name,s[j].basic.id,s[j].nsu.semester.course[0].course_name,s[j].nsu.semester.course[0].exam.course_grade,s[j].nsu.semester.course[1].course_name,s[j].nsu.semester.course[1].exam.course_grade,s[j].nsu.semester.grade);
    }


    fclose(fp1);
    fclose(fp);


}



void student_cgpa(void)
{
    FILE *fp;
    fp = fopen("student_info.txt","r");
    int n=MAX_STUDENT,i=0;
    struct Student_information s[n];
    while(fscanf(fp,"%s%s%s%s%s%s%s%d%f%s%d%f%s%d%f%s%d%s%s%d%f%f%f%f%f%s%s%d%f%f%f%f%f\n",&s[i].basic.name,&s[i].basic.id,&s[i].basic.email,&s[i].basic.phone,&s[i].basic.address,&s[i].basic.dob,&s[i].previous.ssc_institution,&s[i].previous.ssc_year_of_exam,&s[i].previous.ssc_grade,&s[i].previous.hsc_institution,&s[i].previous.hsc_year_of_exam,&s[i].previous.hsc_grade,&s[i].nsu.department,&s[i].nsu.number_sem,&s[i].nsu.prev_cgpa,&s[i].nsu.semester.semester_name,&s[i].nsu.semester.number_of_courses,&s[i].nsu.semester.course[0].course_name,&s[i].nsu.semester.course[0].faculty_name,&s[i].nsu.semester.course[0].credit_number,&s[i].nsu.semester.course[0].exam.quiz_avg,&s[i].nsu.semester.course[0].exam.mid_avg,&s[i].nsu.semester.course[0].exam.assignment,&s[i].nsu.semester.course[0].exam.mark_final,&s[i].nsu.semester.course[0].exam.total,&s[i].nsu.semester.course[1].course_name,&s[i].nsu.semester.course[1].faculty_name,&s[i].nsu.semester.course[1].credit_number,&s[i].nsu.semester.course[1].exam.quiz_avg,&s[i].nsu.semester.course[1].exam.mid_avg,&s[i].nsu.semester.course[1].exam.assignment,&s[i].nsu.semester.course[1].exam.mark_final,&s[i].nsu.semester.course[1].exam.total) != EOF)

    {
        i++;
    }
    int j,x,y,z;

    for(j=0; j<i; j++)
    {
        x = s[j].nsu.semester.course[0].exam.total;
        if(x>=93)
            s[j].nsu.semester.course[0].exam.course_cgpa = 4.00;
        else if(x>=90 && x<=92)
            s[j].nsu.semester.course[0].exam.course_cgpa = 3.70;
        else if(x>=87 && x<=89)
            s[j].nsu.semester.course[0].exam.course_cgpa = 3.30;
        else if(x>=83 && x<=86)
            s[j].nsu.semester.course[0].exam.course_cgpa = 3.00;
        else if(x>=80 && x<=82)
            s[j].nsu.semester.course[0].exam.course_cgpa = 2.70;
        else if(x>=77 && x<=79)
            s[j].nsu.semester.course[0].exam.course_cgpa = 2.30;
        else if(x>=73 && x<=76)
            s[j].nsu.semester.course[0].exam.course_cgpa = 2.00;
        else if(x>=70 && x<=72)
            s[j].nsu.semester.course[0].exam.course_cgpa = 1.70;
        else if(x>=67 && x<=69)
            s[j].nsu.semester.course[0].exam.course_cgpa = 1.30;
        else if(x>=60 && x<=66)
            s[j].nsu.semester.course[0].exam.course_cgpa = 1.00;
        else if(x<60)
            s[j].nsu.semester.course[0].exam.course_cgpa = 0.00;

        y = s[j].nsu.semester.course[1].exam.total;
        if(y>=93)
            s[j].nsu.semester.course[1].exam.course_cgpa = 4.00;
        else if(y>=90 && y<=92)
            s[j].nsu.semester.course[1].exam.course_cgpa = 3.70;
        else if(y>=87 && y<=89)
            s[j].nsu.semester.course[1].exam.course_cgpa = 3.30;
        else if(y>=83 && y<=86)
            s[j].nsu.semester.course[1].exam.course_cgpa = 3.00;
        else if(y>=80 && y<=82)
            s[j].nsu.semester.course[1].exam.course_cgpa = 2.70;
        else if(y>=77 && y<=79)
            s[j].nsu.semester.course[1].exam.course_cgpa = 2.30;
        else if(y>=73 && y<=76)
            s[j].nsu.semester.course[1].exam.course_cgpa = 2.00;
        else if(y>=70 && y<=72)
            s[j].nsu.semester.course[1].exam.course_cgpa = 1.70;
        else if(y>=67 && y<=69)
            s[j].nsu.semester.course[1].exam.course_cgpa = 1.30;
        else if(y>=60 && y<=66)
            s[j].nsu.semester.course[1].exam.course_cgpa = 1.00;
        else if(y<60)
            s[j].nsu.semester.course[1].exam.course_cgpa = 0.00;

        z = ((s[j].nsu.semester.course[0].exam.total * s[i].nsu.semester.course[0].credit_number) + (s[j].nsu.semester.course[1].exam.total * s[i].nsu.semester.course[1].credit_number) / (s[i].nsu.semester.course[0].credit_number+s[i].nsu.semester.course[1].credit_number));


        z = s[j].nsu.semester.course[0].exam.total;
        if(z>=93)
            s[j].nsu.semester.cgpa = 4.00;
        else if(z>=90 && z<=92)
            s[j].nsu.semester.cgpa = 3.70;
        else if(z>=87 && z<=89)
            s[j].nsu.semester.cgpa = 3.30;
        else if(z>=83 && z<=86)
            s[j].nsu.semester.cgpa = 3.00;
        else if(z>=80 && z<=82)
            s[j].nsu.semester.cgpa = 2.70;
        else if(z>=77 && z<=79)
            s[j].nsu.semester.cgpa = 2.30;
        else if(z>=73 && z<=76)
            s[j].nsu.semester.cgpa = 2.00;
        else if(z>=70 && z<=72)
            s[j].nsu.semester.cgpa = 1.70;
        else if(z>=67 && z<=69)
            s[j].nsu.semester.cgpa = 1.30;
        else if(z>=60 && z<=66)
            s[j].nsu.semester.cgpa = 1.00;
        else if(z<60)
            s[j].nsu.semester.cgpa = 0.00;
    }

    for(j=0; j<i; j++)
    {
        s[j].nsu.new_cgpa = (s[j].nsu.prev_cgpa + s[j].nsu.semester.cgpa)/2.0;

    }
    FILE *fp1;
    fp1 = fopen("Student_cgpa.txt","w");

    for(j=0; j<i; j++)
    {
        fprintf(fp1,"Student #%d\n",j+1);
        fprintf(fp1,"\tName : %s\n",s[j].basic.name);
        fprintf(fp1,"\tNSU ID : %s  | Department : %s\n",s[j].basic.id,s[j].nsu.department);
        fprintf(fp1,"\tCourse1(%s) GPA : %.2f | Course2(%s) GPA : %.2f \n",s[j].nsu.semester.course[0].course_name,s[j].nsu.semester.course[0].exam.course_cgpa,s[j].nsu.semester.course[1].course_name,s[j].nsu.semester.course[1].exam.course_cgpa);
        fprintf(fp1,"\tPrevious CGPA : %.2f\n",s[j].nsu.prev_cgpa);
        fprintf(fp1,"\tNew CGPA : %.2f\n\n",s[j].nsu.new_cgpa);
    }

    printf("\n\n\n\t\t\t\t\tStudent_cgpa.txt file created successfully.\n\n");
    printf("\t\t\t\t\t        File Contents \n\n");
    char t1[20] = "Name";
    char t2[20] = "ID";
    char t3[20] = "Previous CGPA";
    char t4[20] = "New CGPA";

    printf("\t\t\t%-15s %-15s %-15s %-15s\n\n",t1,t2,t3,t4);
    for(j=0; j<i; j++)
    {
        printf("\t\t\t%-15s %-15s %-15.2f %-15.2f\n",s[j].basic.name,s[j].basic.id,s[j].nsu.prev_cgpa,s[j].nsu.new_cgpa);
    }


    fclose(fp1);
    fclose(fp);


}





void highest_total(void)
{

    FILE *fp;
    fp = fopen("student_info.txt","r");
    int n=MAX_STUDENT,i=0;
    struct Student_information s[n];
    while(fscanf(fp,"%s%s%s%s%s%s%s%d%f%s%d%f%s%d%f%s%d%s%s%d%f%f%f%f%f%s%s%d%f%f%f%f%f\n",&s[i].basic.name,&s[i].basic.id,&s[i].basic.email,&s[i].basic.phone,&s[i].basic.address,&s[i].basic.dob,&s[i].previous.ssc_institution,&s[i].previous.ssc_year_of_exam,&s[i].previous.ssc_grade,&s[i].previous.hsc_institution,&s[i].previous.hsc_year_of_exam,&s[i].previous.hsc_grade,&s[i].nsu.department,&s[i].nsu.number_sem,&s[i].nsu.prev_cgpa,&s[i].nsu.semester.semester_name,&s[i].nsu.semester.number_of_courses,&s[i].nsu.semester.course[0].course_name,&s[i].nsu.semester.course[0].faculty_name,&s[i].nsu.semester.course[0].credit_number,&s[i].nsu.semester.course[0].exam.quiz_avg,&s[i].nsu.semester.course[0].exam.mid_avg,&s[i].nsu.semester.course[0].exam.assignment,&s[i].nsu.semester.course[0].exam.mark_final,&s[i].nsu.semester.course[0].exam.total,&s[i].nsu.semester.course[1].course_name,&s[i].nsu.semester.course[1].faculty_name,&s[i].nsu.semester.course[1].credit_number,&s[i].nsu.semester.course[1].exam.quiz_avg,&s[i].nsu.semester.course[1].exam.mid_avg,&s[i].nsu.semester.course[1].exam.assignment,&s[i].nsu.semester.course[1].exam.mark_final,&s[i].nsu.semester.course[1].exam.total) != EOF)

    {
        i++;
    }
    int j;
    for(j=0; j<i; j++)
    {
        s[j].nsu.semester.avg_total = (s[j].nsu.semester.course[0].exam.total + s[j].nsu.semester.course[1].exam.total) / 2.0;
    }
    float temp;
    temp = s[0].nsu.semester.avg_total;
    for(j=0; j<i; j++)
    {
        if(temp<s[j].nsu.semester.avg_total)
        {
            temp = s[j].nsu.semester.avg_total;
        }
    }

    FILE *fp1;
    fp1 = fopen("Highest_total.txt","w");
    char n1[10] = "Name";
    char n2[8] = "Courses";
    char n3[20] = "Highest Average";


    fprintf(fp1,"%-20s %-5s   %s\n\n",n1,n2,n3);
    for(j=0; j<i; j++)
    {
        if(s[j].nsu.semester.avg_total==temp)
        {
            fprintf(fp1,"%-20s %-5s,%s %7.2f\n",s[j].basic.name,s[j].nsu.semester.course[0].course_name,s[j].nsu.semester.course[1].course_name,s[j].nsu.semester.avg_total);
        }
    }
    printf("\n\n\n\t\t\t\t\tHighest_total.txt file created successfully.\n");
    printf("\t\t\t\t\t       File Content \n\n");
    for(j=0; j<i; j++)
    {
        if(s[j].nsu.semester.avg_total==temp)
        {
            printf("\t\t\t\tName : %s | Courses :  %s,%s  |  Mark : %.2f\n",s[j].basic.name,s[j].nsu.semester.course[0].course_name,s[j].nsu.semester.course[1].course_name,s[j].nsu.semester.avg_total);
        }
    }


    fclose(fp);

}



void selected_grade(void)
{

    FILE *fp;
    fp = fopen("student_info.txt","r");



    int n=MAX_STUDENT,i=0;
    struct Student_information s[n];
    while(fscanf(fp,"%s%s%s%s%s%s%s%d%f%s%d%f%s%d%f%s%d%s%s%d%f%f%f%f%f%s%s%d%f%f%f%f%f\n",&s[i].basic.name,&s[i].basic.id,&s[i].basic.email,&s[i].basic.phone,&s[i].basic.address,&s[i].basic.dob,&s[i].previous.ssc_institution,&s[i].previous.ssc_year_of_exam,&s[i].previous.ssc_grade,&s[i].previous.hsc_institution,&s[i].previous.hsc_year_of_exam,&s[i].previous.hsc_grade,&s[i].nsu.department,&s[i].nsu.number_sem,&s[i].nsu.prev_cgpa,&s[i].nsu.semester.semester_name,&s[i].nsu.semester.number_of_courses,&s[i].nsu.semester.course[0].course_name,&s[i].nsu.semester.course[0].faculty_name,&s[i].nsu.semester.course[0].credit_number,&s[i].nsu.semester.course[0].exam.quiz_avg,&s[i].nsu.semester.course[0].exam.mid_avg,&s[i].nsu.semester.course[0].exam.assignment,&s[i].nsu.semester.course[0].exam.mark_final,&s[i].nsu.semester.course[0].exam.total,&s[i].nsu.semester.course[1].course_name,&s[i].nsu.semester.course[1].faculty_name,&s[i].nsu.semester.course[1].credit_number,&s[i].nsu.semester.course[1].exam.quiz_avg,&s[i].nsu.semester.course[1].exam.mid_avg,&s[i].nsu.semester.course[1].exam.assignment,&s[i].nsu.semester.course[1].exam.mark_final,&s[i].nsu.semester.course[1].exam.total) != EOF)

    {
        i++;
    }

    int j,x,y,z;
    char a[3] = "A";
    char b[3] = "A-";
    char c[3] = "B+";
    char d[3] = "B";
    char e[3] = "B-";
    char f[3] = "C+";
    char g[3] = "C";
    char h[3] = "C-";
    char ii[3] = "D+";
    char jj[3] = "D";
    char k[3] = "F";
    for(j=0; j<i; j++)
    {
        x = s[j].nsu.semester.course[0].exam.total;
        if(x>=93)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,a);
        else if(x>=90 && x<=92)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,b);
        else if(x>=87 && x<=89)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,c);
        else if(x>=83 && x<=86)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,d);
        else if(x>=80 && x<=82)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,e);
        else if(x>=77 && x<=79)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,f);
        else if(x>=73 && x<=76)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,g);
        else if(x>=70 && x<=72)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,h);
        else if(x>=67 && x<=69)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,ii);
        else if(x>=60 && x<=66)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,jj);
        else if(x<60)
            strcpy(s[j].nsu.semester.course[0].exam.course_grade,k);


        y = s[j].nsu.semester.course[1].exam.total;
        if(y>=93)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,a);
        else if(y>=90 && y<=92)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,b);
        else if(y>=87 && y<=89)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,c);
        else if(y>=83 && y<=86)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,d);
        else if(y>=80 && y<=82)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,e);
        else if(y>=77 && y<=79)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,f);
        else if(y>=73 && y<=76)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,g);
        else if(y>=70 && y<=72)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,h);
        else if(y>=67 && y<=69)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,ii);
        else if(y>=60 && y<=66)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,jj);
        else if(y<60)
            strcpy(s[j].nsu.semester.course[1].exam.course_grade,k);

          z = (s[j].nsu.semester.course[0].exam.total + s[j].nsu.semester.course[1].exam.total) / 2;

        if(z>=93)
            strcpy(s[j].nsu.semester.grade,a);
        else if(z>=90 && z<=92)
            strcpy(s[j].nsu.semester.grade,b);
        else if(z>=87 && z<=89)
            strcpy(s[j].nsu.semester.grade,c);
        else if(z>=83 && z<=86)
            strcpy(s[j].nsu.semester.grade,d);
        else if(z>=80 && z<=82)
            strcpy(s[j].nsu.semester.grade,e);
        else if(z>=77 && z<=79)
            strcpy(s[j].nsu.semester.grade,f);
        else if(z>=73 && z<=76)
            strcpy(s[j].nsu.semester.grade,g);
        else if(z>=70 && z<=72)
            strcpy(s[j].nsu.semester.grade,h);
        else if(z>=67 && z<=69)
            strcpy(s[j].nsu.semester.grade,ii);
        else if(z>=60 && z<=66)
            strcpy(s[j].nsu.semester.grade,jj);
        else if(z<60)
            strcpy(s[j].nsu.semester.grade,k);
    }



    char cname[10];
    FILE *fp1;
    fp1 = fopen("Selected_grade_list.txt","a+");
    printf("\n\n\t\t\t\t\tEnter a course name : ");

    scanf("%s",&cname);

    fprintf(fp1,"Searching for : %s\n",cname);
    for(j=0; j<i; j++)
    {
        if((strcmp(s[j].nsu.semester.course[0].course_name,cname)==0) || (strcmp(s[j].nsu.semester.course[1].course_name,cname)==0))
        {

            fprintf(fp1,"\tName : %s | Course : %s, %s  |  Grade : %s\n",s[j].basic.name,s[j].nsu.semester.course[0].course_name,s[j].nsu.semester.course[1].course_name,s[j].nsu.semester.grade);
        }
    }
    fprintf(fp1, "\n\n\n");

    printf("\n\n\n\t\t\t\t\tSelected_grade_list.txt file created successfully.\n");
    printf("\t\t\t\t\t       File Content \n\n");

    for(j=0; j<i; j++)
    {
        if((strcmp(s[j].nsu.semester.course[0].course_name,cname)==0) || (strcmp(s[j].nsu.semester.course[1].course_name,cname)==0))
        {
            printf("\t\t\tName : %s | Courses : %s, %s  |  Grade : %s\n",s[j].basic.name,s[j].nsu.semester.course[0].course_name,s[j].nsu.semester.course[1].course_name,s[j].nsu.semester.grade);
        }
    }

    fclose(fp1);
    fclose(fp);

}



void delete_all (void)
{
    FILE *fp;
    fp = fopen("student_info.txt","w");
    if(fp)
    {
        printf("\n\n\n\t\t\t\t\tFile Contents deleted successfully.\n");
        printf("\t\t\t\t\t       (stuednt_info.txt) \n\n");
    }
    else printf("\n\n\t\t\tERROR : New file creation failed!  \n\n");
    fclose(fp);
}






/*

Mahbub 2211804 mahbubkousar@gmail.com 01753019520 Dhaka 17_May_2002 AAGHS 2018 5.000000 ACC 2020 5.000000 ECE 2 3.450000 spring_22 3 CSE115 MLE 3 18.133333 25.799999 20.000000 27.900000 91.833328 MAT116 SDT 3 19.533333 23.100000 20.000000 26.100000 88.733337
Siam 2211805 sharif@gmail.com 01830835840 Netrokona 01_jan_2000 AAGHS 2018 4.700000 NGC 2020 4.800000 BBA 3 3.000000 spring_22 3 ENG103 TAA 3 16.533333 27.900000 17.600000 24.299999 96.333328 CSE115 MLE 3 16.866667 23.250000 17.600000 20.700001 88.416672
Rakib 2218072 rakib@gmail.com 01939596976 Sylhet 19_may_2003 AAGHS 2018 4.600000 NDC 2020 4.500000 EEE 4 2.870000 spring_22 3 CSE115 MLE 3 14.000000 23.250000 17.400000 20.700001 75.349998 MAT116 SDT 3 16.133333 15.150000 15.200000 23.100000 69.583336
Tutul 2211908 tutul@gmail.com 01553735025 Durgapur 18_May_2003 AAGHS 2018 5.000000 NGC 2020 5.000000 CSE 4 3.670000 spring22 3 CSE115 MLE 3 18.866667 29.549999 19.799999 26.700001 94.916664 ENG103 TAA 3 17.533333 26.400000 15.600000 29.700001 89.233337
Ashik 2221806 ashik@gmail.com 01969598978 Netrokona 17_June_2002 AAGHS 2018 5.000000 4.45 2020 5.000000 BBA 2 3.880000 spring22 3 MAT116 SDT 3 19.133333 28.200001 19.200001 27.000000 93.533333 ENG103 TAA 3 19.400000 28.049999 19.000000 27.600000 94.050003

*/
