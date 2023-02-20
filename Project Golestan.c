#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define Max 1000

//color of false paragraph//
void red();

void reset();

//mainMenu//
void mainMenu();

void studentLogin();

void adminLogin();

void studentMenu(int);

void adminMenu();

//file function//
int readStudentFile();

int readTeacherFile();

int readCourseFile();

void writeFileCourse();

void writeFileStudent();

void writeFileTeacher();

void teacherManagement();

int getStudentCount();

int getTeacherCount();

int getCourseCount();

int increaseStudentCount();

int increaseTeacherCount();

int increaseCourseCount();

int decreaseStudentCount();

int decreaseTeacherCount();

int decreaseCourseCount();


//admin menu function//
void studentManagement();

void professorManagement();

void courseManagement();

//student menu function//
void addLessons(int);

void deleatLessons(int);

void studentCourseList(int);

void allCourseList(int);

//student Management function//
void addStudent();

void studentSettings();

void deleteStudent();

//teacher Management function//
void addTeacher();

void teacherSettings();

void deleteTeacher();

//chose Teacher of course//
int choseTeacher(int);

//course Management function//
void addCourse();

void courseSettings();

void deleteCourse();

//course settings function//
void courseStudentList(int);

void courseTeacherList(int);

//check function//
int checkID(int);

int checkMely(int);

int checkStudentID(char []);

int checkStudentMely(char []);

int checkTeacherID(int);

int checkTeacherIdLicense(char []);

int checkCourseID(int);

int checkCourseIdLicenceChar(char []);

int checkUnitCourse(int);

int checkName(char[]);


struct student {
    char id[Max], mely[Max];
    char firstname[20], lastname[20];
    //for student course//
    int courses[10];//
    int courseTeacher[10];
    int fullUnit;//
};
struct student pupil[Max];
struct professor {
    char id[Max];
    char firstname[20], lastname[20];
    //for teacher course//
    int course[5];
};
struct professor teacher[Max];
struct course {
    char id[Max];
    char name[20];
    char unitCourse[Max];
    //course student list//
    int courseStudents[30];
    int courseTeachers[Max];
    int choseTeacher;
};
struct course lesson[Max];

int chose[Max][Max];
int studentNumber = 0;
int teacherNumber = 0;
int courseNumber = 0;

int main() {
    studentNumber = getStudentCount();
    teacherNumber = getTeacherCount();
    courseNumber = getCourseCount();
    readStudentFile();
    readTeacherFile();
    readCourseFile();
    //option//
    int i, j;
    for (i = 0; i < courseNumber; i++) {
        for (j = 0; j < teacherNumber; j++) {
            chose[i][j] = 0;
        }
        lesson[i].choseTeacher = choseTeacher(i);
    }
    writeFileCourse();
    mainMenu();
}

void teacherManagement() {
	//option//
    int a;
    for (;;) {
        system("color B0");
        printf("\tStudent Management\n\n");
        do {
            printf("1: Add New Teacher\n");
            printf("2: Teacher Setting\n");
            printf("3: Delete Teacher\n");
            printf("4: Exit\n");
            scanf("%d", &a);
            if (a == 4) {
                system("cls");
                adminMenu();
            } else if (a == 1) {
                system("cls");
                addStudent();
            } else if (a == 2) {
                system("cls");
                studentSettings();
            } else if (a == 3) {
                system("cls");
                deleteStudent();
            } else {
                system("cls");
                printf("\tTeacher Management\n\n");
                red();
                printf("\nWrong. Please Try Again\n\n");
                reset();
            }
        } while (a != 1 || a != 2 || a != 3 || a != 4);
    }
}

void mainMenu() {
	//option//
    int a;
    for (;;) {
        system("color B0");
        printf("\tWelcome To Golestan\n");
        printf(" Which One You Want To Log In\n");
        printf("1: Log In As Student\n");
        printf("2: Log In As Admin\n");
        printf("3: Exit\n");
        do {
		//visitor should print one of the menu numbers//
            scanf("%d", &a);                
            getchar();
            if (a == 3) {
                system("cls");
				//if we got 3 golestan will be off //
                exit(0);                    
            } else if (a == 1) {
                system("cls");
                studentLogin();
            } else if (a == 2) {
                system("cls");
                adminLogin();
            } else {
                system("cls");
                printf("\tWelcome to Golestan\n");
                printf(" Which One You Want To Log In\n");
                printf("1: Log In As Student\n");
                printf("2: Log In As Admin\n");
                printf("3: Exit\n");
                red();
                printf("\nPlease Try Again: ");
                reset();
                system("color B0");
            }
        } while (a != 1 || a != 2 || a != 3);
    }
}

void studentLogin() {
    char ID[Max], Mely[Max];
    //option//
    int i;
    for (;;) {
        system("color B0");
        printf("\tWelcome To Golestan Student Log In\n\n");
        printf("Enter Your Student ID: ");
        gets(ID);
        printf("\nEnter Your Mely Code: ");
        gets(Mely);
		//check ID//
        if (checkStudentID(ID)) {                                        
            for (i = 0; i < Max; i++) {
                if (strcmp(ID, pupil[i].id) == 0) {
                    break;
                }
            }
            if (strcmp(ID, pupil[i].id) != 0) {
                system("cls");
                printf("\nUnavaible Student . Please Try Again\n\n");
                continue;
            }
			//check Mely//
            if (checkStudentMely(Mely)) {                                
                if (strcmp(Mely, pupil[i].mely) == 0) {
                    system("cls");
                    studentMenu(i);
                }
            } else {
                system("cls");
                red();
                printf("Wrong ID Or Mely Code Please Try Again\n");
                reset();
            }
        } else {
            system("cls");
            red();
            printf("Wrong ID Or Mely Code Please Try Again\n");
            reset();
        }
    }
}

void adminLogin() {
    char userName[13], password[12];
    //Admin User name//
    char trueUserName[13] = "Shayanzand82";
    //Admin password//
    char truePassword[12] = "Shayan1234";
    for (;;) {
        system("color B0");
        printf("\tWelcome To Golestan Admin Log In\n\n");
        printf("Enter User Name: ");
        gets(userName);
        printf("\nEnter Password: ");
        gets(password);
        if (strcmp(userName, trueUserName) == 0) {
            if (strcmp(password, truePassword) == 0) {
                system("cls");
                adminMenu();
            } else {
                system("cls");
                red();
                printf("Wrong User Name Or Password Please Try Again.\n\n");
                reset();
            }
        } else {
            system("cls");
            red();
            printf("Wrong User Name Or Password Please Try Again.\n\n");
            reset;
        }
    }
}

void studentMenu(int n) {
    system("color B0");
    //option//
    int a;
    for (;;) {
        system("color B0");
        printf("\tStudent Menu\n\n");
        printf("1: Add Course\n");
        printf("2: Delete Course\n");
        printf("3: Course List\n");
        printf("4: Course List Of This Term\n");
        printf("5: Exit\n");
        do {
            scanf("%d", &a);
            if (a == 5) {
                system("cls");
                mainMenu();
            } else if (a == 1) {
                system("cls");
                addLessons(n);
            } else if (a == 2) {
                system("cls");
                deleatLessons(n);
            } else if (a == 3) {
                system("cls");
                studentCourseList(n);
            } else if (a == 4) {
                system("cls");
                allCourseList(n);
            } else {
                system("cls");
                printf("\tStudent Menu\n\n");
                printf("1: Add Course\n");
                printf("2: Delete Course\n");
                printf("3: Course List\n");
                printf("4: Course List Of This Term\n");
                printf("5: Exit\n");
                red();
                printf("Wrong .Please Try Again\n\n");
                reset();
                system("color B0");
            }
        } while (a != 1 || a != 2 || a != 3 || a != 4 || a != 5);
    }
}

void adminMenu() {
	//option//
    int a;
    for (;;) {
        system("color B0");
        printf("\tAdmin Menu\n\n");
        do {
            printf("1: Student Management\n");
            printf("2: Teachers Management\n");
            printf("3: Course Management\n");
            printf("4: Exit\n");
            scanf("%d", &a);
            if (a == 4) {
                system("cls");
                mainMenu();
            } else if (a == 1) {
                system("cls");
                studentManagement();
            } else if (a == 2) {
                system("cls");
                professorManagement();
            } else if (a == 3) {
                system("cls");
                courseManagement();
            } else {
                system("cls");
                printf("\tAdmin Menu\n\n");
                red();
                printf("Wrong. Please Try Again\n\n");
                reset();
            }
        } while (a != 1 || a != 2 || a != 3 || a != 4);
    }
}

void studentManagement() {
    //option//
    int a;
    for (;;) {
        system("color B0");
        printf("\tStudent Management\n\n");
        do {
            printf("1: Add New Student\n");
            printf("2: Student Setting\n");
            printf("3: Delete Student\n");
            printf("4: Exit\n");
            scanf("%d", &a);
            if (a == 4) {
                system("cls");
                adminMenu();
            } else if (a == 1) {
                system("cls");
                addStudent();
            } else if (a == 2) {
                system("cls");
                studentSettings();
            } else if (a == 3) {
                system("cls");
                deleteStudent();
            } else {
                system("cls");
                printf("\tStudent Management\n\n");
                red();
                printf("\nWrong. Please Try Again\n\n");
                reset();
            }
        } while (a != 1 || a != 2 || a != 3 || a != 4);
    }
}

void professorManagement() {
	//option//
    int a;
    for (;;) {
        system("color B0");
        printf("\tTeacher Management\n\n");
        do {
            printf("1: Add New Teacher\n");
            printf("2: Teacher Setting\n");
            printf("3: Delete Teacher\n");
            printf("4: Exit\n");
            scanf("%d", &a);
            if (a == 4) {
                system("cls");
                adminMenu();
            } else if (a == 1) {
                system("cls");
                addTeacher();
            } else if (a == 2) {
                system("cls");
                teacherSettings();
            } else if (a == 3) {
                system("cls");
                deleteTeacher();
            } else {
                system("cls");
                printf("\tTeacher Management\n\n");
                red();
                printf("Wrong. Please Try Again\n\n");
                reset();
            }
        } while (a != 1 || a != 2 || a != 3 || a != 4);
    }
}

void courseManagement() {
	//option//
    int a;
    for (;;) {
        system("color B0");
        printf("\tCourse Management\n\n");
        printf("1: Add New Course\n");
        printf("2: Course Setting\n");
        printf("3: Delete Course\n");
        printf("4: Exit\n");
        do {
            scanf("%d", &a);
            if (a == 4) {
                system("cls");
                adminMenu();
            } else if (a == 1) {
                system("cls");
                addCourse();
            } else if (a == 2) {
                system("cls");
                courseSettings();
            } else if (a == 3) {
                system("cls");
                deleteCourse();
            } else {
                system("cls");
                red();
                printf("\nWrong. Please Try Again\n");
                reset();
            }
        } while (a != 1 || a != 2 || a != 3 || a != 4);
    }
}

int getStudentCount() {
    int count = 0;
    FILE *file = fopen("StudentCount.txt", "r");
    if (file == NULL) {
        printf("ERROR");
    } else {
        fscanf(file, "%d", &count);
        fclose(file);
        return count;
    }
}

int increaseStudentCount() {
    int count = studentNumber;
    FILE *file = fopen("StudentCount.txt", "w");
    if (file == NULL) {
        printf("ERROR");
    } else {
        count++;
        fprintf(file, "%d", count);
        fclose(file);
        return count;
    }
}

void writeFileStudent() {
//option//
    int i, j;
    FILE *file;
    file = fopen("Student.txt", "w");
    for (i = 0; i < studentNumber; i++) {
        for (j = 0; j < 10; j++)
            fprintf(file, "%d ", pupil[i].courses[j]);
        fprintf(file, " ");
        for (j = 0; j < 10; j++)
            fprintf(file, "%d ", pupil[i].courseTeacher[j]);
        fprintf(file, " ");
        fprintf(file, "%d ", pupil[i].fullUnit);
        fprintf(file, "%s ", pupil[i].firstname);
        fprintf(file, "%s ", pupil[i].lastname);
        fprintf(file, "%s ", pupil[i].id);
        fprintf(file, "%s\n", pupil[i].mely);
    }
    fclose(file);
}

void addStudent() {
	//option//
    int i = studentNumber, j, k;
    for (;;) {
        getchar();
        system("color B0");
        printf("\tPlease Compleate Student Information\n\n");
        printf("First Name: ");
        gets(pupil[i].firstname);
        printf("\nLast Name: ");
        gets(pupil[i].lastname);
        printf("\nEnter Student ID: ");
        gets(pupil[i].id);
        printf("\nEnter Student Mely Code: ");
        gets(pupil[i].mely);
        if (checkID(i) == 1) {
            for (j = 0; j < i; j++) {
                if (strcmp(pupil[j].id, pupil[i].id) == 0) {
                    system("cls");
                    printf("\nStudent Is Available.\n\n");
                    addStudent();
                }
            }
            if (checkMely(i) == 1) {
                for (j = 0; j < i; j++) {
                    if (strcmp(pupil[j].mely, pupil[i].mely) == 0) {
                        system("cls");
                        printf("Student Is Available.\n\n");
                        addStudent();
                    }
                }
                if (checkName(pupil[i].firstname) == 1) {
                    if (checkName(pupil[i].lastname) == 1) {

                        printf("Information Has Been Completed Successfully. ");
                        printf("%d", studentNumber + 1);
                        studentNumber = increaseStudentCount();
                        for (k = 0; k < 10; k++) {
                            pupil[i].courses[k] = 0;
                        }
                        pupil[i].fullUnit = 0;
                        writeFileStudent();
                        getchar();
                        system("cls");
                        studentManagement();
                    } else {
                        system("cls");
                        red();
                        printf("Wrong Name . Please Try Again\n\n");
                        reset();
                        system("color B0");
                        addStudent();
                    }
                } else {
                    system("cls");
                    red();
                    printf("Wrong Name . Please Try Again\n\n");
                    reset();
                    system("color B0");
                    addStudent();
                }
            } else {
                system("cls");
                red();
                printf("Wrong Mely Code. Try Again\n");
                reset();
                system("color B0");
                addStudent();
            }
        } else {
            system("cls");
            red();
            printf(" Wrong Student ID. Try Again\n");
            reset();
            system("color B0");
            addStudent();
        }
    }
}

void studentSettings() {
    char idSearch[Max];
    //option//
    int i, a, b;
    for (;;) {
        getchar();
        printf("\tStudent Setting\n\n");
        printf("Please Enter Student ID: ");
        gets(idSearch);
        if (checkStudentID(idSearch)) {
            for (i = 0; i < Max; i++) {
                if (strcmp(pupil[i].id, idSearch) == 0) {
                    break;
                }
            }
            if (strcmp(pupil[i].id, idSearch) == 0) {
                system("cls");
                printf("\tStudent Information\n\n");
                printf("First Name: %s \n", pupil[i].firstname);
                printf("Last Name: %s \n", pupil[i].lastname);
                printf("Student ID: %s \n", pupil[i].id);
                printf("Student Mely Code: %s \n\n", pupil[i].mely);
                printf("1: Change Student Name\n");
                printf("2: Change Student ID\n");
                printf("3: Change Student Mely Code\n");
                printf("4: Exit\n");
                do {
                    scanf("%d", &a);
                    if (a == 4) {
                        system("cls");
                        studentManagement();
                    } else if (a == 1) {
                        system("cls");
						getchar();
						printf("\tEnter the new name\n\n");
						for( ; ; ){
							printf("First name: ");
							gets(pupil[i].firstname);
							if(checkName(pupil[i].firstname)){
								break;
							}else{
								red ();
								printf("\nWrong First name . Please try again\n\n");
								reset ();
								system("color B0");
								continue;
							}
						}
						for( ; ; ){
							printf("\nLast name: ");
							gets(pupil[i].lastname);
							if(checkName(pupil[i].firstname)){
								break;
							}else{
								red ();
								printf("\nWrong Last name . Please try again\n\n");
								reset ();
								system("color B0");
								continue;
							}
						}
						printf("\n\tChange name has been complet\n\n");
						printf("First name: %s \n",pupil[i].firstname);
						printf("Last name: %s \n\n",pupil[i].lastname);
						printf("Exit\n");
						getchar();
						system("cls");
						writeFileStudent();
						studentManagement();
                    } else if (a == 2) {
	                    system("cls");
						getchar();
						printf("\tEnter the new student ID\n\n");
						for( ; ; ){
							printf("ID: ");
							gets(pupil[i].id);
							if(checkID(i)){
								break;
							}else{
								red ();
								printf("\nWrong ID . Please try again\n\n");
								reset ();
								system("color B0");
								continue;
							}
						}
							
						printf("\n\tChange ID has been complet\n\n");
						printf("Student ID: %s \n\n\n",pupil[i].id);
						printf("Exit\n");
						getchar();
						system("cls");
						writeFileStudent();
						studentManagement();
                    } else if (a == 3) {
                        system("cls");
						getchar();
						printf("\tEnter the new student Mely code\n\n");
						for( ; ; ){
							printf("Mely code: ");
							gets(pupil[i].mely);
							if(checkMely(i)){
								break;
							}else{
								red ();
								printf("\nWrong Mely code . Please try again\n\n");
								reset ();
								system("color B0");
								continue;
							}
						}
							
						printf("\n\tChange Mely code has been complet\n\n");
						printf("Student Mely code: %s \n\n\n",pupil[i].mely);
						printf("Exit\n");
						getchar();
						system("cls");
						writeFileStudent();
						studentManagement();
					}
                } while (a != 1 || a != 2 || a != 3 || a != 4);
            } else {
                system("cls");
                red();
                printf("\nUnavaible ID . Please Try Again\n\n");
                reset();
                system("color B0");
                studentSettings();
            }
        } else {
            system("cls");
            red();
            printf("\nWrong ID . Please Try Again\n\n");
            reset();
            system("color B0");
            studentSettings();
        }
    }
}

void deleteStudent() {
    char idSearch[Max];
    //option//
    int i, a, j, k;
    for (;;) {
        getchar();
        printf("\tStudent Setting\n\n");
        printf("Please Enter Student ID: ");
        gets(idSearch);
        if (checkStudentID(idSearch)) {
            for (i = 0; i < Max; i++) {
                if (strcmp(pupil[i].id, idSearch) == 0) {
                    break;
                }
            }
            if (strcmp(pupil[i].id, idSearch) == 0) {
                system("cls");
                printf("\tStudent Information\n\n");
                printf("First Name: %s \n", pupil[i].firstname);
                printf("Last Name: %s \n", pupil[i].lastname);
                printf("Student ID: %s \n", pupil[i].id);
                printf("Student Mely Code: %s \n\n", pupil[i].mely);
                printf("1: Delete Student \n");
                printf("2: Exit\n");
                do {
                    scanf("%d", &a);
                    if (a == 2) {
                        system("cls");
                        studentManagement();
                    } else if (a == 1) {
                        for (j = i + 1; j < studentNumber; j++, i++) {
                            if (i == studentNumber) {
                                break;
                            }
                            strcpy(pupil[i].firstname, pupil[j].firstname);
                            strcpy(pupil[i].lastname, pupil[j].lastname);
                            strcpy(pupil[i].id, pupil[j].id);
                            strcpy(pupil[i].mely, pupil[j].mely);
                            for (k = 0; k < 10; k++) {
                                pupil[i].courses[k] = pupil[j].courses[k];
                            }
                            for (k = 0; k < 10; k++) {
                                pupil[i].courseTeacher[k] = pupil[j].courseTeacher[k];
                            }
                            pupil[i].fullUnit = pupil[j].fullUnit;

                        }
                        for (j = 0; j <= courseNumber; j++) {
                            for (k = 0; k < 30; k++) {
                                if (lesson[j].courseStudents[k] == i + 1) {
                                    lesson[j].courseStudents[k] = 0;
                                }
                                if (lesson[j].courseStudents[k] > i + 1) {
                                    lesson[j].courseStudents[k]--;
                                }
                                if (lesson[j].courseStudents[k] < i + 1) {
                                    continue;
                                }
                            }
                        }
                        writeFileStudent();
                        studentNumber = decreaseStudentCount();
                        system("cls");
                        printf("\n\nDelete Student Has Been Complet.\n");
                        printf("Exit\n");
                        getchar();
                        getchar();
                        system("cls");
                        studentManagement();
                    }
                } while (a != 1 || a != 2);
            } else {
                system("cls");
                red();
                printf("\nUnavaible ID . Please Try Again\n\n");
                reset();
                system("color B0");
                deleteStudent();
            }
        } else {
            system("cls");
            red();
            printf("\nWrong ID . Please Try Again\n\n");
            reset();
            system("color B0");
            deleteStudent();
        }
    }
}

void addTeacher() {
	//option//
    int i = teacherNumber, j, k;
    for (;;) {
        getchar();
        system("color B0");
        printf("\tPlease Compleate Teacher Information\n\n");
        printf("First Name: ");
        gets(teacher[i].firstname);
        printf("\nLast Name: ");
        gets(teacher[i].lastname);
        printf("\nEnter Teacher ID: ");
        gets(teacher[i].id);
        if (checkTeacherID(i) == 1) {
            for (j = 0; j < i; j++) {
                if (strcmp(teacher[j].id, teacher[i].id) == 0) {
                    system("cls");
                    printf("\nTeacher Is Available.\n\n");
                    addTeacher();
                }
            }
            if (checkName(teacher[i].firstname) == 1) {
                if (checkName(teacher[i].lastname) == 1) {
                    printf("Information Has Been Completed Successfully. ");
                    printf("%d", teacherNumber + 1);
                    teacherNumber = increaseTeacherCount();
                    for (k = 0; k < 5; k++) {
                        teacher[i].course[k] = 0;
                    }
                    writeFileTeacher();
                    getchar();
                    system("cls");
                    professorManagement();
                } else {
                    system("cls");
                    red();
                    printf("Wrong Name . Please Try Again\n\n");
                    reset();
                    system("color B0");
                    addTeacher();
                }
            } else {
                system("cls");
                red();
                printf("Wrong Name . Please Try Again\n\n");
                reset();
                system("color B0");
                addTeacher();
            }
        } else {
            system("cls");
            red();
            printf(" Wrong Teacher ID. Try Again\n");
            reset();
            system("color B0");
            addTeacher();
        }
    }
}

void teacherSettings() {
    char idSearch[Max], courseSearch[Max];
    //option//
    int i, a, b, j, k;
    for (;;) {
        getchar();
        printf("\tTeacher Setting\n\n");
        printf("Please Enter Teacher ID: ");
        gets(idSearch);
        if (checkTeacherIdLicense(idSearch)) {
            for (i = 0; i < Max; i++) {
                if (strcmp(teacher[i].id, idSearch) == 0) {
                    break;
                }
            }
            if (strcmp(teacher[i].id, idSearch) == 0) {
                system("cls");
                printf("\tTeacher Information\n\n");
                printf("First Name: %s \n", teacher[i].firstname);
                printf("Last Name: %s \n", teacher[i].lastname);
                printf("Teacher ID: %s \n\n", teacher[i].id);
                printf("1: Change Teacher Name\n");
                printf("2: Change Teacher ID\n");
                printf("3: Assign Teacher To A Course\n");
                printf("4: Exit\n");
                do {
                    scanf("%d", &a);
                    getchar();
                    if (a == 4) {
                        system("cls");
                        professorManagement();
                    } else if (a == 1) {
                       	system("cls");
						getchar();
						printf("\tEnter the new name\n\n");
						for( ; ; ){
							printf("First name: ");
							gets(teacher[i].firstname);
							if(checkName(teacher[i].firstname)){
								break;
							}else{
								red ();
								printf("\nWrong First name . Please try again\n\n");
								reset ();
								system("color B0");
								continue;
							}
						}
						for( ; ; ){
							printf("\nLast name: ");
							gets(teacher[i].lastname);
							if(checkName(teacher[i].firstname)){
								break;
							}else{
								red ();
								printf("\nWrong First name . Please try again\n\n");
								reset ();
								system("color B0");
								continue;
							}
						}
						printf("\n\tChange name has been complet\n\n");
						printf("First name: %s \n",teacher[i].firstname);
						printf("Last name: %s \n\n",teacher[i].lastname);
						printf("Exit\n");
						getchar();
						system("cls");
						writeFileTeacher();
						professorManagement();
                    } else if (a == 2) {
                        system("cls");
						getchar();
						for( ; ; ){
							printf("\tEnter the new student ID\n\n");
							printf("ID: ");
							gets(teacher[i].id);
							if(checkTeacherID(i)){
								break;
							}else{
								system("cls");	
								red ();
								printf("\nWrong ID . Please try again\n\n");
								reset ();
								system("color B0");
								continue;
							}
						}	
						printf("\n\tChange ID has been complet\n\n");
						printf("Teacher ID: %s \n\n\n",teacher[i].id);
						printf("Exit\n");
						getchar();
						system("cls");
						writeFileTeacher();
						professorManagement();
                    } else if (a == 3) {
                    	//Assign teacher to a Course
						system("cls");
						printf("Enter the course id: ");
						gets(courseSearch);
						if(checkCourseIdLicenceChar(courseSearch)){
							for(j=0 ; j<Max ; j++){
								if(strcmp(lesson[j].id,courseSearch) == 0){
									break;
								}
								if(strcmp(lesson[j].id,courseSearch) == 0){
									for(k=0 ; k<5 ; k++){
										if(teacher[i].course[k] != 0){
											continue;
										}
										if(teacher[i].course[k] == 0){
											for(k=0 ; k<Max ; k++){
											if(lesson[j].courseTeachers[k] != 0){
												continue;
											}
											lesson[j].courseTeachers[k] = i;
											writeFileCourse();
											writeFileTeacher();
											break;
											}
										}else{
											system("cls");
											red ();
											printf("\nTeacher course is full number .\n\n");
											reset ();
											system("color B0");
											teacherSettings();
										}
									}
								}else{
									system("cls");
									red ();
									printf("\nUnavaible course . Please Try Again\n\n");
									reset ();
									system("color B0");
									teacherSettings();
								}
							}
							}else{
								system("cls");
								red ();
								printf("\nWrong course . Please try again\n\n");
								reset ();
								system("color B0");
								teacherSettings();
							}
                        }else{
                            system("cls");
                            red();
                            printf("\nWrong Course ID . Please Try Again\n\n");
                            reset();
                            system("color B0");
                            teacherSettings();
                        }
                    
                } while (a != 1 || a != 2 || a != 3 || a != 4);
            } else {
                system("cls");
                red();
                printf("\nUnavaible ID . Please Try Again\n\n");
                reset();
                system("color B0");
                teacherSettings();
            }
        } else {
            system("cls");
            red();
            printf("\nWrong ID . Please Try Again\n\n");
            reset();
            system("color B0");
            teacherSettings();
        }
    }
}

void deleteTeacher() {
    int exitLoop = 0;
    char idSearch[Max];
    //option//
    int i, a, j, k;
    for (;;) {
        getchar();
        printf("\tTeacher Setting\n\n");
        printf("Please Enter Teacher ID: ");
        gets(idSearch);
        if (checkTeacherIdLicense(idSearch)) {
            for (i = 0; i < Max; i++) {
                if (strcmp(teacher[i].id, idSearch) == 0) {
                    break;
                }
            }
            if (strcmp(teacher[i].id, idSearch) == 0) {
                system("cls");
                printf("\tTeacher Information\n\n");
                printf("First Name: %s \n", teacher[i].firstname);
                printf("Last Name: %s \n", teacher[i].lastname);
                printf("Teacher ID: %s \n\n", teacher[i].id);
                printf("1: Delete Teacher \n");
                printf("2: Exit\n");
                do {
                    scanf("%d", &a);
                    if (a == 2) {
                        system("cls");
                        professorManagement();
                    } else if (a == 1) {
                        for (j = i + 1; j < teacherNumber; j++, i++) {
                            if (i == teacherNumber) {
                                break;
                            }
                            strcpy(teacher[i].firstname, teacher[j].firstname);
                            strcpy(teacher[i].lastname, teacher[j].lastname);
                            strcpy(teacher[i].id, teacher[j].id);
                            for (k = 0; k < 5; k++) {
                                teacher[i].course[k] = teacher[j].course[k];
                            }
                        }
                        for (j = 0; j <= studentNumber; j++) {
                            for (k = 0; k < 10; k++) {
                                if (pupil[j].courseTeacher[k] == i + 1) {
                                    pupil[j].courseTeacher[k] = 0;
                                }
                                if (pupil[j].courseTeacher[k] > i + 1) {
                                    pupil[j].courseTeacher[k]--;
                                }
                                if (pupil[j].courseTeacher[k] < i + 1) {
                                    continue;
                                }
                            }
                        }
                        writeFileStudent();
                        for (j = 0; j <= courseNumber; j++) {
                            for (k = 0; k < Max; k++) {
                                if (lesson[j].courseTeachers[k] == i + 1) {
                                    lesson[j].courseTeachers[k] = 0;
                                }
                                if (lesson[j].courseTeachers[k] > i + 1) {
                                    lesson[j].courseTeachers[k]--;
                                }
                                if (lesson[j].courseTeachers[k] < i + 1) {
                                    continue;
                                }
                            }
                            if (lesson[j].choseTeacher == i + 1) {
                                lesson[j].choseTeacher = 0;
                            }
                            if (lesson[j].choseTeacher > i + 1) {
                                lesson[j].choseTeacher--;
                            }
                            if (lesson[j].choseTeacher < i + 1) {
                                continue;
                            }
                        }
                        writeFileCourse();
                        teacherNumber = decreaseTeacherCount();
                        writeFileTeacher();
                        system("cls");
                        printf("\n\nDelete Teacher Has Been Complet.\n");
                        printf("Exit\n");
                        getchar();
                        getchar();
                        system("cls");
                        teacherManagement();
                        exitLoop = 1;
                        break;
                    }
                } while (a == 1 || a == 2);
                if (exitLoop == 1) {
                    break;
                }
            } else {
                system("cls");
                red();
                printf("\nUnavaible ID . Please Try Again\n\n");
                reset();
                system("color B0");
                deleteTeacher();
            }
		}else{
            system("cls");
            red();
            printf("\nWrong ID . Please Try Again\n\n");
            reset();
            system("color B0");
            deleteTeacher();
        }
    }
}

void addCourse() {
	//option//
    int i = courseNumber, j, k;
    for (;;) {
        getchar();
        system("color B0");
        printf("\tPlease Compleate Course Information\n\n");
        printf("Name: ");
        gets(lesson[i].name);
        printf("\nEnter Course ID: ");
        gets(lesson[i].id);
        printf("\nEnter Course unit: ");
        gets(lesson[i].unitCourse);
        if (checkCourseID(i) == 1) {
            for (j = 0; j < i; j++) {
                if (strcmp(lesson[j].id, lesson[i].id) == 0) {
                    system("cls");
                    printf("\nCourse Is Available.\n\n");
                    addCourse();
                }
            }
            if (checkUnitCourse(i) == 0) {
                system("cls");
                red();
                printf(" Wrong Unit Course . Try Again\n");
                reset();
                system("color B0");
                addCourse();
            }
            if (checkName(lesson[i].name) == 1) {
                printf("Information Has Been Completed Successfully. ");
                printf("%d", courseNumber + 1);
                courseNumber = increaseCourseCount();
                lesson[i].choseTeacher = 0;
                for (k = 0; k < 30; k++) {
                    lesson[i].courseStudents[k] = 0;
                }
                for (k = 0; k < Max; k++) {
                    lesson[i].courseTeachers[k] = 0;
                }
                writeFileCourse();
                getchar();
                system("cls");
                courseManagement();
            } else {
                system("cls");
                red();
                printf("Wrong Name . Please Try Again\n\n");
                reset();
                system("color B0");
                addCourse();
            }
        } else {
            system("cls");
            red();
            printf(" Wrong Course ID. Try Again\n");
            reset();
            system("color B0");
            addCourse();
        }
    }
}

void courseSettings() {
    char idSearch[Max];
    //option//
    int i, a, b = 1;
    for (;;) {
        getchar();
        printf("\tCourse Setting\n\n");
        printf("Please Enter Course ID: ");
        gets(idSearch);
        if (checkCourseIdLicenceChar(idSearch)) {
            for (i = 0; i < Max; i++) {
                if (strcmp(lesson[i].id, idSearch) == 0) {
                    break;
                }
            }
            if (strcmp(lesson[i].id, idSearch) == 0) {
                system("cls");
                printf("\tCourse Information\n\n");
                printf("Name: %s \n", lesson[i].name);
                printf("Course ID: %s \n\n", lesson[i].id);
                printf("1: Change Course Name\n");
                printf("2: Change Course ID\n");
                printf("3: Course Student List\n");
                printf("4: Course Teacher List\n");
                printf("5: Exit\n");
                do {
                    scanf("%d", &a);
                    if (a == 5) {
                        system("cls");
                        courseManagement();
                    } else if (a == 1) {
                    	system("cls");
						getchar();
						printf("\tEnter the new name\n\n");
						for( ; ; ){
							printf("Name: ");
							gets(lesson[i].name);
							if(checkName(lesson[i].name)){
								break;
							}else{
								red ();
								printf("\nWrong name . Please try again\n\n");
								reset ();
								system("color B0");
								continue;
							}
						}
						printf("\n\tChange name has been complet\n\n");
						printf("Name: %s \n",lesson[i].name);
						printf("Exit\n");
						getchar();
						system("cls");
						courseManagement();
                    } else if (a == 2) {
                    	system("cls");
						getchar();
						printf("\tEnter the new course ID\n\n");
						for( ; ; ){
							printf("ID: ");
							gets(lesson[i].id);
							if(checkCourseID(i)){
								break;
							}else{
								red ();
								printf("\nWrong ID . Please try again\n\n");
								reset ();
								system("color B0");
								continue;
							}
						}
							
						printf("\n\tChange ID has been complet\n\n");
						printf("Course ID: %s \n\n\n",lesson[i].id);
						printf("Exit\n");
						getchar();
						system("cls");
						courseManagement();
                    } else if (a == 3) {
                        system("cls");
                        courseStudentList(i);
                    } else if (a == 4) {
                        system("cls");
                        courseTeacherList(i);
                    }
                } while (a != 1 || a != 2 || a != 3 || a != 4 || a != 5);
            } else {
                system("cls");
                red();
                printf("\nUnavaible ID . Please Try Again\n\n");
                reset();
                system("color B0");
                courseSettings();
            }
        } else {
            system("cls");
            red();
            printf("\nWrong ID . Please Try Again\n\n");
            reset();
            system("color B0");
            courseSettings();
        }
    }
}

int getCourseCount() {
    int count = 0;
    FILE *file = fopen("CourseCount.txt", "r");
    if (file == NULL) {
        printf("ERROR");
    } else {
        fscanf(file, "%d", &count);
        fclose(file);
        return count;
    }
}

int increaseCourseCount() {
    int count = courseNumber;
    FILE *file = fopen("CourseCount.txt", "w");
    if (file == NULL) {
        printf("ERROR");
    } else {
        count++;
        fprintf(file, "%d", count);
        fclose(file);
        return count;

    }
}

void writeFileCourse() {
//option//
    int i, j;
    FILE *file;
    file = fopen("Course.txt", "w");
    for (i = 0; i < courseNumber; i++) {
        for (j = 0; j < 30; j++)
            fprintf(file, "%d ", lesson[i].courseStudents[j]);
        fprintf(file, " ");
        for (j = 0; j < Max; j++)
            fprintf(file, "%d ", lesson[i].courseTeachers[j]);
        fprintf(file, " ");
        fprintf(file, "%d ", lesson[i].choseTeacher);
        fprintf(file, "%s ", lesson[i].name);
        fprintf(file, "%s ", lesson[i].id);
        fprintf(file, "%s \n", lesson[i].unitCourse);
    }
    fclose(file);
}

void deleteCourse() {
    char idSearch[Max];
    //option//
    int i, a, j, k;
    for (;;) {
        getchar();
        printf("\tCourse Setting\n\n");
        printf("Please Enter Course ID: ");
        gets(idSearch);
        if (checkCourseIdLicenceChar(idSearch)) {
            for (i = 0; i < Max; i++) {
                if (strcmp(lesson[i].id, idSearch) == 0) {
                    break;
                }
            }
            if (strcmp(lesson[i].id, idSearch) == 0) {
                system("cls");
                printf("\tCourse Information\n\n");
                printf("Name: %s \n", lesson[i].name);
                printf("Course ID: %s \n\n", lesson[i].id);
                printf("1: Delete Course \n");
                printf("2: Exit\n");
                do {
                    scanf("%d", &a);
                    if (a == 2) {
                        system("cls");
                        courseManagement();
                    } else if (a == 1) {
                        for (j = i + 1; j < courseNumber; j++, i++) {
                            if (i == courseNumber) {
                                break;
                            }
                            strcpy(lesson[i].name, lesson[j].name);
                            strcpy(lesson[i].id, lesson[j].id);
                            strcpy(lesson[i].unitCourse, lesson[j].unitCourse);
                            for (k = 0; k < 30; k++) {
                                lesson[i].courseStudents[k] = lesson[j].courseStudents[k];
                            }
                            for (k = 0; k < Max; k++) {
                                lesson[i].courseTeachers[k] = lesson[j].courseTeachers[k];
                            }
                            lesson[i].choseTeacher = lesson[j].choseTeacher;

                        }
                        for (j = 0; j <= studentNumber; j++) {
                            for (k = 0; k < 10; k++) {
                                if (pupil[j].courses[k] == i + 1) {
                                    pupil[j].courses[k] = 0;
                                    pupil[j].courseTeacher[k] = 0;
                                    pupil[j].fullUnit -= lesson[i].unitCourse[0] - 48;
                                }
                                if (pupil[j].courses[k] > i + 1) {
                                    pupil[j].courses[k]--;
                                }
                                if (pupil[j].courses[k] < i + 1) {
                                    continue;
                                }
                            }
                        }
                        writeFileStudent();
                        for (j = 0; j <= teacherNumber; j++) {
                            for (k = 0; k < 5; k++) {
                                if (teacher[j].course[k] == i + 1) {
                                    teacher[j].course[k] = 0;
                                }
                                if (teacher[j].course[k] > i + 1) {
                                    teacher[j].course[k]--;
                                }
                                if (teacher[j].course[k] < i + 1) {
                                    continue;
                                }
                            }
                        }
                        writeFileTeacher();
                        courseNumber = decreaseCourseCount();
                        writeFileCourse();
                        system("cls");
                        printf("\n\nDelete Course Has Been Complet.\n");
                        printf("Exit\n");
                        getchar();
                        getchar();
                        system("cls");
                        courseManagement();
                    }
                } while (a != 1 || a != 2);
            } else {
                system("cls");
                red();
                printf("\nUnavaible ID . Please Try Again\n\n");
                reset();
                system("color B0");
                deleteCourse();
            }
        } else {
            system("cls");
            red();
            printf("\nWrong ID . Please Try Again\n\n");
            reset();
            system("color B0");
            deleteCourse();
        }
    }
}

int choseTeacher(int i) {
	//option//
    int k, j, t, count = -1;
    for (k = 0; k < 30; k++) {
        if (lesson[i].courseStudents[k] == 0)
            continue;
        for (j = 0; j < 10; j++) {
            if (pupil[lesson[i].courseStudents[k] - 1].courses[j] == i) {
                t = pupil[lesson[i].courseStudents[k] - 1].courseTeacher[j];
                chose[i][t]++;
            }
        }
    }
    for (k = 0; k < Max; k++) {
        if (chose[i][k] == 0)
            continue;
        for (j = 0; j < Max; j++) {
            if (chose[i][j] == 0)
                continue;
            if (chose[i][k] < chose[i][j]) {
                count = j;
            } else {
                count = k;
            }
        }
    }
    return count;
}

int checkName(char name[]) {
	//option//
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            printf("Wrong Name");
            return 0;
        }
    }
    return 1;
}

int checkID(int i) {
	//option//
    int j;
    for (j = 0; j < 11; j++) {
        if (isdigit(pupil[i].id[j])) {
            continue;
        } else {
            return 0;
        }
    }
    if (strlen(pupil[i].id) == 11) {
        return 1;
    } else {
        return 0;
    }
}

int checkMely(int i) {
	//option//
    int j;
    for (j = 0; j < 10; j++) {
        if (isdigit(pupil[i].mely[j])) {
            continue;
        } else {
            return 0;
        }
    }
    if (strlen(pupil[i].mely) == 10) {
        return 1;
    } else {
        return 0;
    }

}

int checkStudentID(char id[]) {
	//option//
    int j;
    for (j = 0; j < 11; j++) {
        if (isdigit(id[j])) {
            continue;
        } else {
            return 0;
        }
    }
    if (strlen(id) == 11) {
        return 1;
    } else {
        return 0;
    }
}

int checkStudentMely(char mely[]) {
	//option//
    int j;
    for (j = 0; j < 10; j++) {
        if (isdigit(mely[j])) {
            continue;
        } else {
            return 0;
        }
    }
    if (strlen(mely) == 10) {
        return 1;
    } else {
        return 0;
    }
}

int checkTeacherID(int i) {
	//option//
    int j;
    for (j = 0; j < 7; j++) {
        if (isdigit(teacher[i].id[j])) {
            continue;
        } else {
            return 0;
        }
    }
    if (strlen(teacher[i].id) == 7) {
        return 1;
    } else {
        return 0;
    }
}

int checkTeacherIdLicense(char id[]) {
	//option//
    int j;
    for (j = 0; j < 7; j++) {
        if (isdigit(id[j])) {
            continue;
        } else {
            return 0;
        }
    }
    if (strlen(id) == 7) {
        return 1;
    } else {
        return 0;
    }
}

int checkCourseID(int i) {
	//option//
    int j;
    for (j = 0; j < 4; j++) {
        if (isdigit(lesson[i].id[j])) {
            continue;
        } else {
            return 0;
        }
    }
    if (strlen(lesson[i].id) == 4) {
        return 1;
    } else {
        return 0;
    }
}

int checkCourseIdLicenceChar(char id[]) {
	//option//
    int j;
    for (j = 0; j < 4; j++) {
        if (isdigit(id[j])) {
            continue;
        } else {
            return 0;
        }
    }
    if (strlen(id) == 4) {
        return 1;
    } else {
        return 0;
    }
}

int checkUnitCourse(int i) {
	//option//
    int j = 0;
    if (isdigit(lesson[i].unitCourse[j])) {
        if (strlen(lesson[i].unitCourse) == 1) {
            return 1;
        } else { return 0; }
    } else {
        return 0;
    }
}

void addLessons(int n) {
    char idSearch[Max];
    //option//
    int i, j, a, b, t;
    int s[Max], k = 0;
    for (;;) {
        getchar();
        system("color B0");
        printf("\tStudent Add Course\n\n");
        printf("Enter Course ID: ");
        gets(idSearch);
        if (checkCourseIdLicenceChar(idSearch)) {
            for (i = 0; i < Max; i++) {
                if (strcmp(lesson[i].id, idSearch) == 0) {
                    break;
                }
            }
            if (strcmp(lesson[i].id, idSearch) == 0) {
                system("cls");
                printf("\tCourse Information\n\n");
                printf("Name: %s \n", lesson[i].name);
                printf("Course ID: %s \n", lesson[i].id);
                printf("Course Unit: %s \n\n", lesson[i].unitCourse);
                printf("1: Add Course\n");
                printf("2: Exit\n");
                do {
                    scanf("%d", &a);
                    getchar();
                    if (a == 2) {
                        system("cls");
                        studentMenu(n);
                    } else if (a == 1) {
                        system("cls");
                        printf("\t\tCourse Teachers\n\n");
                        printf("First Name\tLast Name\tTeacher ID\n\n");
                        for (j = 0; j < Max; j++) {
                            if (lesson[i].courseTeachers[j] != 0) {
                                b = lesson[i].courseTeachers[j] - 1;
                                s[k] = b;
                                k++;
                                if (strlen(teacher[j].id) == 0) {
                                    continue;
                                }
                                printf("%-14s", teacher[b].firstname);
                                printf("%-13s", teacher[b].lastname);
                                printf("%-14s\n", teacher[b].id);
                            }
                        }

                        printf(".......Empty.......\n\n");
                        printf("Enter The ID Of The Teacher You Chose: ");
                        gets(idSearch);
                        if (checkTeacherIdLicense(idSearch)) {
                            for (k = 0; k < Max; k++) {
                                if (strcmp(teacher[s[k]].id, idSearch) == 0) {
                                    break;
                                }
                            }
                            if (strcmp(teacher[s[k]].id, idSearch) == 0) {
                                pupil[n].fullUnit += (lesson[i].unitCourse[0] - 48);
                                if (pupil[n].fullUnit > 24) {
                                    pupil[n].fullUnit -= (lesson[i].unitCourse[0] - 48);
                                    system("cls");
                                    red();
                                    printf("\nSorry Your Number Of Units Is More Than 24 Unit\n\n");
                                    getchar();
                                    reset();
                                    system("cls");
                                    system("color B0");
                                    studentMenu(n);
                                }
                                t = s[k];
                                for (k = 0; k < 10; k++) {
                                    if (pupil[n].courses[k] != 0) {
                                        if (k == 9) {
                                            system("cls");
                                            red();
                                            printf("\nSorry You Have The Maximum Course\n\n");
                                            getchar();
                                            reset();
                                            system("cls");
                                            system("color B0");
                                            studentMenu(n);
                                        }
                                        continue;
                                    } else if (pupil[n].courses[k] == 0) {
                                        pupil[n].courses[k] = i + 1;
                                        pupil[n].courseTeacher[k] = t + 1;
                                        break;
                                    }
                                }
                                for (k = 0; k < 30; k++) {
                                    if (lesson[i].courseStudents[k] != 0) {
                                        if (k == 29) {
                                            system("cls");
                                            red();
                                            printf("\nSorry Course Student Number Is Full\n\n");
                                            getchar();
                                            reset();
                                            system("cls");
                                            system("color B0");
                                            studentMenu(n);
                                        }
                                        continue;
                                    } else if (lesson[i].courseStudents[k] == 0) {
                                        lesson[i].courseStudents[k] = n + 1;
                                        break;
                                    }
                                }
                                writeFileStudent();
                                lesson[i].choseTeacher = choseTeacher(i);
                                writeFileCourse();
                                printf("\nAdd Lesson Has Been Complet\n\n");
                                printf("Exit\n");
                                getchar();
                                studentMenu(n);
                            }

                        } else {
                            system("cls");
                            red();
                            printf("\nWrong Teacher ID \n");
                            getchar();
                            system("cls");
                            reset();
                            system("color B0");
                            studentMenu(n);
                        }
                    }
                } while (a != 1 || a != 2);
            } else {
                system("cls");
                red();
                printf("\nUnavaible ID \n");
                getchar();
           	    system("cls");
                reset();
                system("color B0");
                studentMenu(n);
            }
        } else {
            system("cls");
            red();
            printf("\nWrong Course ID \n");
            getchar();
            system("cls");
            reset();
            system("color B0");
            studentMenu(n);
        }
    }
}

void deleatLessons(int n) {
    char idSearch[Max];
    //option//
    int i, j, a, k;
    int s[Max];
    for (;;) {
        getchar();
        system("color B0");
        printf("\tStudent Add Course\n\n");
        printf("Enter course ID: ");
        gets(idSearch);
        if (checkCourseIdLicenceChar(idSearch)) {
            for (i = 0; i < Max; i++) {
                if (strcmp(lesson[i].id, idSearch) == 0) {
                    break;
                }
            }
            if (strcmp(lesson[i].id, idSearch) == 0) {
                system("cls");
                printf("\tCourse Information\n\n");
                printf("Name: %s \n", lesson[i].name);
                printf("Course ID: %s \n", lesson[i].id);
                printf("Course Unit: %s \n\n", lesson[i].unitCourse);
                printf("1: Delete Course\n");
                printf("2: Exit\n");
                do {
                    scanf("%d", &a);
                    getchar();
                    if (a == 2) {
                        system("cls");
                        studentMenu(n);
                    } else if (a == 1) {
                        for (j = 0; j < 10; j++) {
                            if (pupil[n].courses[j] == i + 1) {
                                pupil[n].courses[j] = 0;
                                pupil[n].courseTeacher[j] = 0;
                                pupil[n].fullUnit -= lesson[i].unitCourse[0] - 48;
                            }
                        }
                        for (k = 0; k < 30; k++) {
                            if (lesson[i].courseStudents[k] == n + 1) {
                                lesson[i].courseStudents[k] = 0;
                            }
                        }
                        writeFileCourse();
                        writeFileStudent();
                    }
                } while (a != 1 || a != 2);
            } else {
                system("cls");
                red();
                printf("\nWrong Course ID \n");
                getchar();
                system("cls");
                reset();
                system("color B0");
                studentMenu(n);
            }
        } else {
            system("cls");
            red();
            printf("\nWrong Course ID \n");
            getchar();
            system("cls");
            reset();
            system("color B0");
            studentMenu(n);
        }
    }
}

void studentCourseList(int n) {
	//option//
    int j, i, b, t, k, c;
    for (;;) {
        getchar();
        system("color B0");
        printf("\tStudent Course List\n\n");
        printf("Course Name\tCourse ID\tRecommend Teacher\tUnit Number\tChose Teacher\n\n");
        for (j = 0; j < courseNumber; j++) {
            if (pupil[n].courses[j] != 0) {
                b = pupil[n].courses[j] - 1;
                t = pupil[n].courseTeacher[j];
                if (strlen(lesson[b].id) == 0) {
                    continue;
                }
                printf("%-16s", lesson[b].name);
                printf("%-16s", lesson[b].id);
                for (i = 0; i < Max; i++) {
                    if ((lesson[b].courseTeachers[i] - 1) == t) {
                        printf("%-11s ", teacher[t].firstname);
                        printf("%-11s ", teacher[t].lastname);
                        break;
                    }
                }
                if ((lesson[b].courseTeachers[i] - 1) != t) {
                    printf("%-16s", "Not Exist");
                }
                printf("%-14s", lesson[b].unitCourse);
                c = choseTeacher(b);
                printf("%-8s ", teacher[c].firstname);
                printf("%-8s\n", teacher[c].lastname);
            }
        }
        printf(".......Empty.......\n\n");
        printf("Exit\n");
        getchar();
        system("cls");
        system("color B0");
        studentMenu(n);
    }
}

void allCourseList(int n) {
	//option//
    int i;
    for (;;) {
        getchar();
        system("color B0");
        printf("\tCourse List Of This Term\n\n");
        printf("Course Name\tCourse ID\tUnit Number\n\n");
        for (i = 0; i < Max; i++) {
            if (strlen(lesson[i].id) == 0) {
                continue;
            }
            printf("%-15s", lesson[i].name);
            printf("%-13s", lesson[i].id);
            printf("%-13s\n", lesson[i].unitCourse);
        }
        printf(".......Empty.......\n\n");
        printf("Exit\n");
        getchar();
        system("cls");
        system("color B0");
        studentMenu(n);
    }
}

void courseStudentList(int i) {
	//option//
    int j, b;
    for (;;) {
        getchar();
        system("color B0");
        printf("\tStudent Course List\n\n");
        printf("First Name\tLast Name\tStudent ID\tMely Code\n\n");
        for (j = 0; j < 30; j++) {
            if (lesson[i].courseStudents[j] != 0) {
                b = lesson[i].courseStudents[j] - 1;
                if (strlen(pupil[j].id) == 0) {
                    continue;
                }
                printf("%-14s", pupil[j].firstname);
                printf("%-14s", pupil[j].lastname);
                printf("%-14s", pupil[j].id);
                printf("%-14s\n", pupil[j].mely);
            }
        }
        printf(".......Empty.......\n\n");
        printf("Exit\n");
        getchar();
        system("cls");
        system("color B0");
        courseManagement();
    }
}

void courseTeacherList(int i) {
	//option//
    int j, b;
    for (;;) {
        getchar();
        system("color B0");
        printf("\tTeacher Course List\n\n");
        printf("First Name\tLast Name\tTeacher ID\n\n");
        for (j = 0; j < Max; j++) {
            if (lesson[i].courseTeachers != 0) {
                b = lesson[i].courseTeachers[j] - 1;
                if (strlen(teacher[j].id) == 0) {
                    continue;
                }
                printf("%-14s", teacher[j].firstname);
                printf("%-14s", teacher[j].lastname);
                printf("%-14s\n", teacher[j].id);
            }
        }
        printf(".......Empty.......\n\n");
        printf("Exit\n");
        getchar();
        system("cls");
        system("color B0");
        courseManagement();
    }
}

void red() {
    printf("\033[1;31m");
}

void reset() {
    printf("\033[0m");
}

int readStudentFile() {
    FILE *file = fopen("Student.txt", "r");
    //option//
    int n = 0;
    int c, j;

    if (file == NULL) {
	//could not open file
        return 0; 
    }
    char temp[100];
    while (!feof(file)) {
        for (n = 0; n < studentNumber; n++) {
            for (j = 0; j < 10; j++) {
                fscanf(file, "%d", &pupil[n].courses[j]);
            }
            for (j = 0; j < 10; j++) {
                fscanf(file, "%d", &pupil[n].courseTeacher[j]);
            }
            fscanf(file, "%d", &pupil[n].fullUnit);
            fscanf(file, "%s", pupil[n].firstname);
            fscanf(file, "%s", pupil[n].lastname);
            fscanf(file, "%s", pupil[n].id);
            fscanf(file, "%s", pupil[n].mely);
        }
        fgets(temp, 100, file);
    }
    fclose(file);
    return 1;
}

int readCourseFile() {
    FILE *file = fopen("Course.txt", "r");
    //option//
    int n = 0;
    int c, j;

    if (file == NULL) {
	//could not open file
        return 0; 
    }
    char temp[100];
    while (!feof(file)) {
        for (n = 0; n <= courseNumber; n++) {
            for (j = 0; j < 30; j++) {
                fscanf(file, "%d", &lesson[n].courseStudents[j]);
        	}
            for (j = 0; j < Max; j++) {
                fscanf(file, "%d", &lesson[n].courseTeachers[j]);
            }
            fscanf(file, "%d", &lesson[n].choseTeacher);
            fscanf(file, "%s", lesson[n].name);
            fscanf(file, "%s", lesson[n].id);
            fscanf(file, "%s", lesson[n].unitCourse);
        }
        fgets(temp, 100, file);
    }
    fclose(file);
    return 1;
}

int readTeacherFile() {
    FILE *file = fopen("Teacher.txt", "r");
    //option//
    int n = 0;
    int c, j;

    if (file == NULL) {
        return 0;
    }
    char temp[100];
    while (!feof(file)) {
        for (n = 0; n < teacherNumber; n++) {
            for (j = 0; j < 5; j++) {
                fscanf(file, "%d", &teacher[n].course[j]);
            }
            fscanf(file, "%s", teacher[n].firstname);
            fscanf(file, "%s", teacher[n].id);
            fscanf(file, "%s", teacher[n].lastname);
        }
        fgets(temp, 100, file);
    }
    fclose(file);
    return 1;
}

int getTeacherCount() {
    int count = 0;
    FILE *file = fopen("TeacherCount.txt", "r");
    if (file == NULL) {
        printf("ERROR");
    } else {
        fscanf(file, "%d", &count);
        fclose(file);
        return count;
    }
}

int increaseTeacherCount() {
    int count = teacherNumber;
    FILE *file = fopen("TeacherCount.txt", "w");
    if (file == NULL) {
        printf("ERROR");
    } else {
        count++;
        fprintf(file, "%d", count);
        fclose(file);
        return count;

    }
}

int decreaseStudentCount() {
    int count = studentNumber;
    FILE *file = fopen("StudentCount.txt", "w");
    if (file == NULL) {
        printf("ERROR");
    } else {
        count--;
        fprintf(file, "%d", count);
        fclose(file);
        return count;
    }
}

int decreaseTeacherCount() {
    int count = teacherNumber;
    FILE *file = fopen("TeacherCount.txt", "w");
    if (file == NULL) {
        printf("ERROR");
    } else {
        count--;
        fprintf(file, "%d", count);
        fclose(file);
        return count;

    }
}

int decreaseCourseCount() {
    int count = courseNumber;
    FILE *file = fopen("CourseCount.txt", "w");
    if (file == NULL) {
        printf("ERROR");
    } else {
        count--;
        fprintf(file, "%d", count);
        fclose(file);
        return count;

    }
}

void writeFileTeacher() {
	//option//
    int i, j;
    FILE *file;
    file = fopen("Teacher.txt", "w");
    for (i = 0; i < teacherNumber; i++) {
        for (j = 0; j < 5; j++)
            fprintf(file, "%d ", teacher[i].course[j]);
        fprintf(file, " ");
        fprintf(file, "%s ", teacher[i].firstname);
        fprintf(file, "%s ", teacher[i].lastname);
        fprintf(file, "%s \n", teacher[i].id);
    }
    fclose(file);
}
