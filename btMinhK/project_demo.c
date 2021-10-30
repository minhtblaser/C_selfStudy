#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct Marks{
    char C[10], web[10], software[10];
};
struct Student{
    char id[30];
    char id_subject[30];
    char first_name[100];
    char last_name[100];
    char gender[30];
    char date_of_birth[100];
    char classname[30];
    char country[30];
    struct Marks marks;
};
void printValue(struct Student student[]){
    int i;
    for(i=0; i<3; i++){
        printf("%s,%s,%s,%s,%s,%s,%s\n",student[i].id,
                                        student[i].first_name,
                                        student[i].last_name,
                                        student[i].gender,
                                        student[i].date_of_birth,
                                        student[i].classname,
                                        student[i].country);
    }
}
void printScore(struct Student student[]){
    int i;
    int val;
    for(i=0; i<9; i++){
        val = atoi(student[i].id_subject);
        if(val == 1){
        printf("%s,%s,%s\n",student[i].id,
                            student[i].id_subject,
                            student[i].marks.web);
        } else if (val == 2) {
            printf("%s,%s,%s\n",student[i].id,
                            student[i].id_subject,
                            student[i].marks.C);
        } else {
            printf("%s,%s,%s\n",student[i].id,
                            student[i].id_subject,
                            student[i].marks.software);
        }
    }
}
float average(struct Marks marks){
    float score_web = atof(marks.web);
    float score_C = atof(marks.C);
    float score_software = atof(marks.software);
    return ((score_web + score_C + score_software)/3.0);
}
void swap(struct Student first, struct Student second){
    struct Student temp = first;
    first = second;
    second = temp;
}
void sortAverage(struct Student output[]){ //insertion sort
	int i, j;
    for(i=0; i<2; i++){
        for(j=i+1; j<3;j++){
            if(average(output[i].marks) < average(output[j].marks)){
                swap(output[i],output[j]);
            }
        }
    }
}
void printClassName(struct Student student[]){
    char search_class_name[30];
    fflush(stdin);
    gets(search_class_name);
    for(int i = 0; i < 3; i++){
        if(strcmp(search_class_name,student[i].classname)==0){
            printf("%s,%s,%s,%s,%s,%s,%s\n",student[i].id,
                                            student[i].first_name,
                                            student[i].last_name,
                                            student[i].gender,
                                            student[i].date_of_birth,
                                            student[i].classname,
                                            student[i].country);
        }
    }
}
void countGenders(struct Student check[]){
    int count_male = 0, count_female = 0;
    int i;
    for(i=0; i<3; i++){
        if(strcmp(check[i].gender,"Male") == 0) count_male++;
        else count_female++;
    }
    printf("Male: %d, Female: %d\n", count_male, count_female);
}
void ascSortByNameDes(struct Student source[]){
    struct Student temp;
    for(int pre=0; pre < 2; pre++){
        for(int next = pre+1; next < 3; next++){
            if(strcmp(source[pre].last_name, source[next].last_name) == -1){
                temp = source[pre];
                source[pre] = source[next];
                source[next] = temp;
            } else if (strcmp(source[pre].last_name, source[next].last_name) == 0){
                if(strcmp(source[pre].date_of_birth, source[next].date_of_birth) == -1){
                    temp = source[pre];
                    source[pre]  = source[next];
                    source[next] = temp;
                }
            }
        }
    }
}
void ascSortByNameAsc(struct Student source[]){
    struct Student temp;
    for(int pre=0; pre < 2; pre++){
        for(int next = pre+1; next < 3; next++){
            if(strcmp(source[pre].last_name, source[next].last_name) == 1){
                temp = source[pre];
                source[pre] = source[next];
                source[next] = temp;
            } else if (strcmp(source[pre].last_name, source[next].last_name) == 0){
                if(strcmp(source[pre].date_of_birth, source[next].date_of_birth) == 1){
                    temp = source[pre];
                    source[pre]  = source[next];
                    source[next] = temp;
                }
            }
        }
    }
}
void findStudent(struct Student find[]){
    int check = 0;
    char name[100], temp[100];
    printf("\nenter name need to find: ");
    fflush(stdin);
    gets(name);
    char space[10] = " ";
    int i;
    for(i=0; i<3; i++){
        strcpy(temp,strcat(find[i].first_name,space));
        strcpy(temp,strcat(find[i].first_name,find[i].last_name));
        if(strcmp(strlwr(temp),strlwr(name))==0){ //change A -> a
            printf("%s,%s,%s,%s,%s,%s\n",find[i].id,
                                        find[i].first_name,
                                        find[i].gender,
                                        find[i].date_of_birth,
                                        find[i].classname,
                                        find[i].country);
            printf("\n");
            check = 1;
        }
    }
    if(check==0) printf("Not found\n");
}
void menu(struct Student student[]){
    int choice ;
    do{
        printf("1. List <classname>\n");
        printf("2. Count male\nCount female\n");
        printf("3. Top n\n");
        printf("4. Sort asc\nSort desc\n");
        printf("5. Search <keyword>\n");
        printf("Your choise: ");
        scanf("%d", &choice);
        switch (choice){
            case 1: 
            {
                printClassName(student);
                break;
            };
            case 2: 
            {
                countGenders(student);
                break;
            }
            case 3: 
            {
                sortAverage(student);
                printValue(student);
                break;
            };
            case 4:
            {
                fflush(stdin);
                int choice_sort;
                scanf("%d", &choice_sort);
                if(choice_sort == 1){
                    ascSortByNameAsc(student);
                    printValue(student);
                } else if(choice_sort == 2){
                    ascSortByNameDes(student);
                    printValue(student);
                }
                break;
            }
            case 5: 
            {
                findStudent(student);
                break;
            }
        }
    } while(choice != 0);
}
int main(){
    struct Student student[100]; // array to struct to store data 
    int row_count = 0;
    int field_count = 0;
    char search_class_name[30];
    char *path = "./btMinhK/name.csv";
    FILE *the_file = fopen(path,"r");
    if (the_file == NULL){
        perror("Unable to open the file");
        return 1;
    }
    char line[100];
    int i = 0;
    while(fgets(line,100,the_file)){
        field_count = 0;
        row_count++;
        if(row_count == 1){
            continue;// we did not want to take the first lable
        }
        char *field = strtok(line,",");
        while(field){
            if(field_count == 0)
                strcpy(student[i].id,field); 
            if (field_count == 1)
                strcpy(student[i].first_name,field); 
            if (field_count == 2)
                strcpy(student[i].last_name,field); 
            if (field_count == 3)
                strcpy(student[i].gender,field); 
            if (field_count == 4)
                strcpy(student[i].date_of_birth,field); 
            if (field_count == 5)
                strcpy(student[i].classname,field); 
            if (field_count == 6)
                strcpy(student[i].country,field); 
            field = strtok(NULL, ","); // update field value;
            field_count++;
        }
        i++;
    }
    fclose(the_file);
    char *path_score = "./btMinhK/score.csv";
    the_file = fopen(path_score,"r");
    char line_score[100];
    int j = 0;
    int val;
    row_count = 0;
    //input score to struct
    while(fgets(line_score,100,the_file)){
        field_count = 0;
        row_count++;
        if(row_count == 1){
            continue;// we did not want to take the first lable
        }
        char *field_score = strtok(line_score,",");
        while(field_score){
            if (field_count == 0)
                strcpy(student[j].id,field_score); 
            if (field_count == 1)
                strcpy(student[j].id_subject,field_score); 
            if (field_count == 2){
                val = atoi(student[j].id_subject);
                if(val == 1){
                    strcpy(student[j].marks.web,field_score); 
                } else if (val == 2){
                    strcpy(student[j].marks.C,field_score); 
                } else {
                    strcpy(student[j].marks.software,field_score); 
                }
            } 
            field_score = strtok(NULL, ","); // update field value;
            field_count++;
        }
        j++;
    }
    fclose(the_file);
    menu(student);
    return 0;
}
