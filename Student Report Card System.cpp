#include <stdio.h>

struct student{
    int roll;
    char name[51];
    int bangla, english, math;
    float average;
    char grade;
};

FILE *file;

char grade_calculate(float average){
    if(average >= 70) return 'A';
    else if (average >= 55) return 'B';
    else if(average >= 45) return 'C';
    else if (average >= 40) return 'D';
    else return 'F';
}

void input(struct student *s){
    printf("\nEnter the Roll of Student : ");
    scanf("%d", &s->roll);
    fflush(stdin);
    printf("Enter the Name of Student : ");
    gets(s->name);
    printf("Enter the Marks in Bangla : ");
    scanf("%d", &s->bangla);
    printf("Enter the Marks in English : ");
    scanf("%d", &s->english);
    printf("Enter the Marks in Mathematics : ");
    scanf("%d", &s->math);
    s->average = (s->bangla + s->english + s->math)/3.0;
    s->grade = grade_calculate(s->average);
}

void display(struct student st){
    printf("\a\nRoll Number of Student : %d", st.roll);
    printf("\nName of Student : %s", st.name);
    printf("\nMarks in Bangla : %d", st.bangla);
    printf("\nMarks in English : %d", st.english);
    printf("\nMarks in Mathematics : %d", st.math);
    printf("\nAverage : %0.2f%%", st.average);
    printf("\nGrade : %c", st.grade);
}

void write(){
    struct student data;
    file = fopen("student.dat", "ab");
    printf("\a\nPlease Enter Required Details of the Student\n");
    input(&data);
    fwrite(&data, sizeof(data), 1, file);
    fclose(file);
    printf("\nStudent Record Has Been Created\n\a");
}

void all(){
    struct student data;
    printf("\a\nAll Student's Report Card Record\n");
    printf("------------------------------------\n");
    file = fopen("student.dat", "rb");
    while((fread(&data, sizeof(data), 1, file)) > 0){
        display(data);
        printf("\n------------------------------------\n");
    }
    fclose(file);
}

void specific(int n){
    struct student data;
    int flag = 0;
    file = fopen("student.dat", "rb");
    while ((fread(&data, sizeof(data), 1, file)) > 0){
        if (data.roll == n){
            display(data);
            flag = 1;
        }
    }
    fclose(file);
    if (flag == 0) printf("\nRecord Not Exist.\a");
}

void mmodify(){
    struct student data;
    int no, found = 0;
    printf("\a\nTo Modify Please Enter the Roll Number of Student: ");
    scanf("%d", &no);
    file = fopen("student.dat", "rb+");
    while ((fread(&data, sizeof(data), 1, file)) > 0 && found == 0){
        if (data.roll == no){
            printf("\a\nOriginal Details\n-------------------");
            display(data);
            printf("\n\nPlease Enter the New Details of Student\n");
            input(&data);
            fseek(file,  -(long)sizeof(data), 1);
            fwrite(&data, sizeof(data), 1, file);
            printf("\nRecord Updated\n");
            found = 1;
        }
    }
    fclose(file);
    if (found == 0) printf("\n\aRecord Not Found\n");
}

void ddelete(){
    int no;
    struct student data;
    FILE *file2;
    printf("\a\nDelete Student Report Card Record\n");
    printf("\nPlease Enter the Roll Number You want to Delete: ");
    scanf("%d", &no);
    file = fopen("student.dat", "rb");
    file2 = fopen("temp.dat", "wb");
    rewind(file);
    while ((fread(&data, sizeof(data), 1, file)) > 0){
        if (data.roll != no){
            fwrite(&data, sizeof(data), 1, file2);
        }
    }
    fclose(file2);
    fclose(file);
    remove("student.dat");
    rename("temp.dat", "student.dat");
    printf("\nRecord deleted\n");
}

void grade(){
    struct student data;
    file = fopen("student.dat", "rb");
    if (file == NULL){
        printf("\nFile is Null. Please Create Record First.\n");
        return;
    }
    printf("\nAll Student's Grade Report\n");
    printf("-------------------------------------------------------------------\n");
    printf("R.No.\tName\t\tBangla\tEnglish\tMath\tAverage\tGrade\n");
    printf("-------------------------------------------------------------------\n");

    while ((fread(&data, sizeof(data), 1, file)) > 0)
    {
        printf("%-7d %-15s %-7d %-7d %-7d %-7.2f  %-1c\n", data.roll, data.name, data.bangla, data.english, data.math,
        data.average, data.grade);
    }
    fclose(file);
}

void result(){
    int rno;
    char select;
    do{
        printf("\a\nEnter Roll Number of Student: ");
        scanf("%d", &rno);
        specific(rno);
        printf("\nDo You Want to See More Result (Y/N)?: ");
        fflush(stdin);
        scanf("%c", &select);
    }while (select == 'y' || select == 'Y');
    return;
}

int main(){
    printf("\t\tStudent Report Card System");
Main:
    printf("\a\nMain Menu");
    printf("\n1. Create Student Report Card Record");
    printf("\n2. Display All Student's Report Card Record");
    printf("\n3. Display Specific Student's Report Card Record");
    printf("\n4. Display All Student's Grade Report");
    printf("\n5. Modify Student Report Card Record");
    printf("\n6. Delete Student Report Card Record");
    printf("\n7. Exit");
again:
    printf("\nPlease Select Your select (1 to 7): ");
    int select;
    scanf("%d", &select);
    if(select == 1){
        write(); goto Main;
    }
    else if(select == 2){
        all(); goto Main;
    }
    else if(select == 3){
        result(); goto Main;
    }
    else if(select == 4){
        grade(); goto Main;
    }
    else if(select == 5){
        mmodify(); goto Main;
    }
    else if(select == 6){
        ddelete(); goto Main;
    }
    else if(select == 7){
        printf("\a"); return 0;
    }
    else{
        printf("\nWrong input, please select again.");
        goto again;
    }
}
