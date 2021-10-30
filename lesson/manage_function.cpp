    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    struct book_st{
        char name[30];
        char type[30];
        int price;
    };
    void enter(book_st *input);
    void enterBooks(book_st *input, int numberBooks);
    void addBook(book_st *input, int &numberBooks,const book_st book);
    void enterType(char search[30]);
    int comicBooks(book_st *input, int numberBooks);
    int swordHeroBooks(book_st *input, int numberBooks);
    void printTypeBooks(book_st *input, int numberBooks);
    book_st* findBookByType(book_st *input, int numberBooks, int totalBooks, char search[30]);
    int countBooksByType(book_st *input, int numberBooks, char search[30]);
    void print(book_st *input, int numberBooks);
    void arrangeBook(book_st *input, int numberBooks);
    void exportBook(FILE *file, char *path, book_st *output, int numberBooks);
    void menu(FILE *file, char *path, book_st *input, int numberBooks,int totalBooks,char search[30]);
    int main(){
        FILE *file;
        char *output_path="./src/baiTapLon/book.dat";
        book_st *bookList;
        int numberBooks = 3;
        int totalBooks;
        char search[30];
        bookList = (book_st*) calloc(numberBooks,sizeof(book_st)); // cấp phát đi 
        //enterBooks(bookList,numberBooks);
        // arrangeBook(bookList,numberBooks);
        // print(bookList, numberBooks);
        // printTypeBooks(bookList,numberBooks);
        // enterType(search);
        // print(findBookByType(bookList,numberBooks,totalBooks,search),countBooksByType(bookList,numberBooks,totalBooks,search));
        // exportBook(file,output_path,bookList,numberBooks);
        menu(file,output_path,bookList,numberBooks,totalBooks,search);
        return EXIT_SUCCESS;
    }
    void enter(book_st *input){
        printf("\nTen: ");
        fflush(stdin);
        gets(input->name);
        printf("The loai: ");
        gets(input->type);
        printf("Gia tien: ");
        scanf("%d", &input->price);
    }
    void enterBooks(book_st *input, int numberBooks){
        input = (book_st*)realloc(input,(numberBooks)*sizeof(book_st));
        for(int index=0;index<numberBooks;index++){
            printf("\nNhap quyen sach %d", index+1);
            enter(&*(input+index));

        }
    }
    int comicBooks(book_st *input, int numberBooks){
        int count = 0;
        for(int i=0; i < numberBooks; i++){
            if(strcmp((input+i)->type,"truyen tranh") ==0){
                count++;
            }
        }
        return count;
    }
    int swordHeroBooks(book_st *input, int numberBooks){
        int count = 0;
        for(int i=0; i < numberBooks; i++){
            if(strcmp((input+i)->type,"truyen kiem hiep") ==0){
                count++;
            }
        }
        return count;
    }
    void printTypeBooks(book_st *input, int numberBooks){
        printf("\nTruyen tranh co %d quyen sach", comicBooks(input, numberBooks));
        printf("\nTruyen kiem hiep co %d quyen sach\n", swordHeroBooks(input, numberBooks));
    }
    void addBook(book_st *input, int &numberBooks,const book_st book){
        numberBooks++;
        input = (book_st*) realloc(input,numberBooks*sizeof(book_st));
        *(input+numberBooks-1) = book;
    }
    void enterType(char search[30]){
        printf("\nNhap the loai: ");
        fflush(stdin);
        gets(search);
    }
    book_st* findBookByType(book_st *input, int numberBooks, int totalBooks, char search[30]){
        book_st *result;
        book_st temp;
        totalBooks = 0;
        result = (book_st*)calloc(totalBooks,sizeof(book_st));
        for(int index = 0; index < numberBooks; index++){
            if(strcmp((input+index)->type,search)==0){
                temp = *(input+index);
                addBook(result,totalBooks,temp);
            }
        }
        return result;
    }
    int countBooksByType(book_st *input, int numberBooks, char search[30]){
        int count =0;
        for(int i=0; i < numberBooks; i++){
            if(strcmp((input+i)->type, search)==0){
                count++;
            }
        }
        return count;
    }
    void print(book_st *input,int numberBooks){
        if(numberBooks==0){
            printf("Khong co quyen sach thuoc the loai nay");
        }else{
            printf("\nSTT||Ten\t\t||The loai\t\t||Gia tien");
            for(int index=0; index < numberBooks; index++){
                printf("\n00%d||%s\t\t||%s\t\t||%d",index+1,(input+index)->name,(input+index)->type,(input+index)->price);
            }
        }
    }
    void arrangeBook(book_st *input, int numberBooks){
        book_st temp;
        for(int i = 0; i < numberBooks-1; i++){
            for(int j = i+1; j <numberBooks; j++){
                if(strcmp((input+i)->name, (input+j)->name) < 0){
                    temp = *(input+i);
                    *(input+i)= *(input+j);
                    *(input+j) = temp;
                }
            }
        }
    }
    void exportBook(FILE *file, char *path, book_st *output, int numberBooks){
        char *mode = "a";
        file = fopen(path,mode);
        fprintf(file,"\nSTT||Ten\t\t||The loai\t\t||Gia tien");
            for(int index=0; index < numberBooks; index++){
                fprintf(file,"\n00%d||%s\t\t||%s\t\t||%d",index+1,(output+index)->name,(output+index)->type,(output+index)->price);
            }
        fclose(file);
    }
    void menu(FILE *file, char *path, book_st *input, int numberBooks,int totalBooks,char search[30]){
        int choise;
        do{
            printf("\n-----------------------Menu--------------------\n");
            printf("1. Nhap du lieu cua tung quyen sach.\n");
            printf("2. Sap xep, thong kê va hien thi thong tin chi tiet cua tung quyen sach theo the loai (Z->A).\n");
            printf("3. Tim  quyen sach theo the loai\n");
            printf("4. Ghi vao tap tin nhi phan book.dat.\n");
            printf("5. Thoat\n");
            printf("-------------------------------------------------\n");
            printf("Your choise: ");
            scanf("%d", &choise);
            switch (choise){
                case 1:
                enterBooks(input,numberBooks);
                break;
                case 2:
                arrangeBook(input,numberBooks);
                print(input, numberBooks);
                printTypeBooks(input,numberBooks);
                break;
                case 3:
                enterType(search);
                print(findBookByType(input,numberBooks,totalBooks,search),countBooksByType(input,numberBooks,search));
                break;
                case 4:
                exportBook(file,path,input,numberBooks);
                break;
                case 5:
                break;
                default:
                printf("Hay nhap lai\n");
                break;
            }    
        }while(choise!=5);
    }