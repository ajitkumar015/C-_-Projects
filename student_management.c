#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[100];
    float marks;
};

void addStudent() {
    FILE *fp;
    struct Student s;

    fp = fopen("students.txt","a");
    if(fp == NULL){
        printf("Error opening file\n");
        
        return;
    }
    printf("Enter rollNo. : ");
    scanf("%d",&s.rollNo);
    printf("Enter name : ");
    scanf(" %[^\n]s", s.name);
    printf("Enter marks : ");
    scanf("%f",&s.marks);

    fwrite(&s, sizeof(s),1,fp);
    fclose(fp);

    printf("Student added succesfully.\n");
    
}

void viewStudents(){
    FILE *fp;
    struct Student s;

    fp = fopen("students.txt","r");
    if(fp == NULL){
        printf("No student Records found.\n");
        return;
    }

    printf("\n--- All Student Records ---\n");
    while(fread(&s, sizeof(s), 1, fp)){

        printf("Roll no. : %d\n", s.rollNo);
        printf("Name : %s\n", s.name);
        printf("Marks : %.2f\n", s.marks);

        printf("------------------------------\n");
    }

    fclose(fp);
}

void searchStudent(){
    FILE *fp;
    struct Student s;
    int rollNo, found = 0;

    printf("Search by rollNo.: ");
    scanf("%d",&rollNo);

    fp = fopen("students.txt","r");
    if(fp == NULL){
        printf("Student record not Found!\n");
        return ;
    }
    while(fread(&s, sizeof(s), 1, fp)){
        if(s.rollNo == rollNo){
            printf("\nStudent found: \n");
            printf("Roll no : %d\n",s.rollNo);
            printf("Name: %s\n",s.name);
            printf("Marks: %.2f\n",s.marks);

            found = 1;
            break;
        }
    }
    if(!found){
        printf("Student with rollNo. %d not found. \n",rollNo);
    
    }
    fclose(fp);
}
void updateStudent() {
    FILE *fp, *temp;
    struct Student s;
    int rollNo,found = 0;

    printf("Enter rollNo. to update: ");
    scanf("%d",&rollNo);

    fp = fopen("students.txt","r");
    temp = fopen("temp.txt","w");

    if(fp == NULL || temp == NULL){
        printf("Error opening File\n");
        return;
    }
    while(fread(&s, sizeof(s), 1, fp)){
        if(s.rollNo == rollNo){
            printf("Enter new name: ");
            scanf(" %[^\n]s",s.name);
            printf("Enter new marks: ");
            scanf("%f",&s.marks);
            found = 1;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }
    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt","students.txt");

    if(found == 1) {
         printf("Student Record updated Successfully. \n");
    } else {
         printf("Student with rollNo.%d not found.\n",rollNo);
    }
}
void deleteStudent() {
    FILE *fp, *temp;
    struct Student s;
    int rollNo, found = 0;

    printf("Enter rollNo to delete: ");
    scanf("%d",&rollNo);

    fp = fopen("students.txt","r");
    temp = fopen("temp.txt","w");

    if(fp == NULL || temp == NULL){
        printf("Error! \n");
        return;
    }
    while(fread(&s, sizeof(s), 1, fp)){
        if(s.rollNo == rollNo) {
            found = 1;
            continue; // skip writing this record
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");
    if(found)
        printf("Student record deleted Successfully.\n");
    else
        printf("Student with rollNo. %d not found.\n",rollNo);
          printf("Student with rollNo. %d not found.\n",rollNo);


}
void menu() {
    int choice;
    while(1) {
        printf("\n--- Student management System ---\n");
        printf("1. Add Student\n");
        printf("2.View Students\n");
        printf("3.Search Student\n");
        printf("4.Update Student\n");
        printf("5.Delete Student\n");
        printf("6.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
         switch(choice){
            case 1: 
                  addStudent();
                  break;
            case 2:
                 viewStudents();
                 break;
            case 3:
                 searchStudent();
                 break;
            case 4:
                 updateStudent();
                 break;
            case 5:
                 deleteStudent();
                 break;
            case 6:
                 printf("Exiting program.\n");
                 exit(0);
            default:
                 printf("Invalid choice. Please try again.\n");               
         }
    }
}
int main() {
    menu();
    return 0;
}