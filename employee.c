#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define FILE_NAME  "employee.txt"
#define maxName 50
#define maxID 20
 #define maxSurname 50
#define FILE_HEADER_SIZE  sizeof(sFileHeader)

typedef struct
{
  
    char name[maxName];
   char surname[maxSurname];
    int age;
    int ID; 
    float salary;
} s_EmployeesInfo;

typedef struct
{
   
} sFileHeader;

void update(){
	
    	
    int found = 0;
    int employeeUPDATE = 0;
    sFileHeader fileHeaderInfo = {0};
    
    s_EmployeesInfo add = {0};
    FILE *dosya = NULL;
    FILE *tmpFp = NULL;
    
    dosya = fopen(FILE_NAME,"rb");
  
    tmpFp = fopen("employee3.txt","wb");
   
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, dosya);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter employee ID NO. for UPDATE:");
    scanf("%d",&employeeUPDATE);
    while (fread (&add, sizeof(add), 1, dosya))
    {
        if(add.ID == employeeUPDATE)
        {
        	printf("\n\t\t\t To update; please enter updated infos ");
        	printf("\n\t\t\tEmployee updated Salary =   ");
        	fflush(stdin);
        	scanf("%f",&add.salary);
        	printf("\n\t\t\tEmployee new  Age =   ");
        	fflush(stdin);
        	scanf("%d",&add.age);
        	
        	
            fwrite(&add,sizeof(add), 1, tmpFp);
        }
      
    }
    printf("\n\t\t\tRecord UPDATED successfully.....");
    fclose(dosya);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("employee3.txt",FILE_NAME);
    columnMenu();
}

void delete(){
	

	
    int found = 0;
    int employeeDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    s_EmployeesInfo add = {0};
    FILE *dosya = NULL;
    FILE *tmpFp = NULL;
    
    dosya = fopen(FILE_NAME,"rb");
  
    tmpFp = fopen("employee2.txt","wb");
   
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, dosya);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter employee ID number to delete:");
    scanf("%d",&employeeDelete);
    while (fread (&add, sizeof(add), 1, dosya))
    {
        if(add.ID != employeeDelete)
        {
            fwrite(&add,sizeof(add), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(dosya);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("employee2.txt",FILE_NAME);
    columnMenu();
}



void list(){
	int found = 0;
    int searchID =0;
    s_EmployeesInfo add = {0};
    FILE *dosya=NULL;
    dosya = fopen(FILE_NAME,"rb");
    
    printf("\n\t\t\tEnter employee ID   to list =  ");
    fflush(stdin);
    scanf("%d",&searchID);
    
    while (fread (&add, sizeof(add), 1, dosya))
    {
        if(add.ID == searchID)
        {
        	printf("\n\t\t\tOne employee has been matched with this ID! \n");
            found = 1;
            break;
        }
    }
     if(found)
    {
    	
        printf("\n\t\t\tEmployee Id = %d\n",add.ID);
        printf("\n\t\t\tEmployee Name = %s\n",add.name);
        printf("\t\t\tEmployee Surname = %s\n",add.surname);
        printf("\t\t\tEmployee Age = %d\n",add.age);
        printf("\t\t\tEmployee Salary = %f\n",add.salary);
     
    }
      else
    {
        printf("\n\t\t\tNo Record");
    }
    
    fclose(dosya);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
    columnMenu();
}


void add(){

s_EmployeesInfo add = {0};

FILE *dosya=NULL;
	
dosya = fopen(FILE_NAME,"ab++");
	
	  printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tEmployee ID  = ");
    fflush(stdin);
    scanf("%u",&add.ID);
    
    //
     printf("\n\t\t\tEmployee Name  = ");
        fflush(stdin);
        fgets(add.name,50,stdin);
        //
         printf("\n\t\t\tEmployee Surname  = ");
        fflush(stdin);
        fgets(add.surname,50,stdin);
        //
         printf("\n\t\t\tEmployee Salary  = ");
    fflush(stdin);
    scanf("%f",&add.salary);
    //
     printf("\n\t\t\tEmployee age  = ");
    fflush(stdin);
    scanf("%d",&add.age);
  fwrite(&add,sizeof(add), 1, dosya);
    fclose(dosya);
    columnMenu();
        

}

void columnMenu(){
	int choice=0;
	printf("\n\t\t\t1-ADD ------ 2-LIST ----- 3- DELETE ----- 4-UPDATE ");
	scanf("%d",&choice);
	switch(choice)
        {
        case 1:
            add();
            break;
       case 2:
           list();
            break;
       case 3:
            delete();
            break;
      case 4:
         update();
            break;
        default:
        	printf("LOOKS INVALID INPUT,TRY AGAIN!");
	
}
}
int main() {
	printf("\t\t--------------------------------------------------------------------------\n");
	printf("------------------------------WELCOME TO EMPLOYEE REGISTRATION SYSTEM! ----------------------- \n");
	printf("\t\t--------------------------------------------------------------------------\n");
	
	columnMenu();
	
	return 0;
}