#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
FILE *fp;
int count=0;
struct node{
int id;
char owner_name[20];
char car_no[20];
time_t start_t, end_t;
struct node *next;
};
const char* curr_time(){
     struct tm* local;
    time_t t = time(NULL);
    // Get the localtime
    local = localtime(&t);
           return asctime(local);
}
struct node* create()
{
   //FILE *fp;
if(fp==NULL){
    printf("error");
    getch();
    exit(0);
}
fseek(fp, 0, SEEK_END);
fputs("\n\nCAR PARKED AT ",fp);
fputs(curr_time(),fp);
time_t start_t;
int a;
struct node *new_n,*curr,*head;
head = NULL;
char name[20],car_no[20];
new_n=(struct node*)malloc(sizeof(struct node));
printf("enter id: ");
fflush(stdin);
scanf("%d",&a);
fputs("id is: ",fp);
fprintf(fp,"%d",a);
printf("enter owner name ");
fflush(stdin);
fprintf(fp,"%s","\nowner_name is  ");
gets(name);
fputs(name,fp);
printf("enter car no. ");
fflush(stdin);
gets(car_no);
fputs("\ncar_no is  ",fp);
fputs(car_no,fp);
new_n->id=a;
strcpy(new_n->car_no,car_no);
strcpy(new_n->owner_name,name);
new_n->start_t=time(&start_t);
new_n->next=NULL;
if(head==NULL)
{
head=new_n;
curr=new_n;
}
else
{
curr->next=new_n;
curr=new_n;
}
//fclose(fp);
}
void add(struct node* head)
{
time_t start_t;
int a;
//FILE *fp;
//fp=fopen("parking_data.txt","a+");
if(fp==NULL){
    printf("error");
    getch();
    exit(0);
}
struct node *new_n,*curr;
char c,name[20],car_no[20];
new_n=(struct node*)malloc(sizeof(struct node));
curr=head;
 fseek(fp, 0, SEEK_END);
 fputs("\n\nCAR PARKED AT ",fp);
fputs(curr_time(),fp);
printf("\nenter id: ");
fflush(stdin);
fputs("id is: ",fp);
scanf("%d",&a);
fprintf(fp,"%d",a);
printf("enter owner name ");
fflush(stdin);
fputs("\nowner_name is ",fp);
gets(name);
fputs(name,fp);
printf("enter car no.");
fflush(stdin);
gets(car_no);
fputs("\ncar_no  ",fp);
fputs(car_no,fp);
//fclose(fp);
new_n->id=a;
strcpy(new_n->car_no,car_no);
strcpy(new_n->owner_name,name);
new_n->start_t=time(&start_t);
new_n->next=NULL;
for(curr=head;;curr=curr->next){
if(curr->next!=NULL)
    continue;
else{
curr->next=new_n;
curr=new_n;
break;
}
}
}
struct node* del(struct node* head){
time_t end_t;
char c,name[20],car_no[20];
double diff_t;
int a,flag=0;
struct node* temp,*curr_n;
 fseek(fp, 0, SEEK_END);
fputs("\n\nCAR DEPARTURE AT ",fp);
fputs(curr_time(),fp);
printf("enter id: ");
fflush(stdin);
scanf("%d",&a);
fputs("id is: ",fp);
fprintf(fp,"%d",a);
printf("enter owner name ");
fputs("\nowner_name is ",fp);
fflush(stdin);
gets(name);
fputs(name,fp);
printf("enter car no. ");
fputs("\ncar no. ",fp);
fflush(stdin);
gets(car_no);
fputs(car_no,fp);
time(&end_t);
temp=head;
for(curr_n=head;curr_n!=NULL;curr_n=curr_n->next)
{
    if(curr_n->id==a&&strcmp(curr_n->car_no,car_no)==0&&strcmp(curr_n->owner_name,name)==0){
            flag=1;
            count--;
        if(curr_n==head){
        diff_t = difftime(end_t, curr_n->start_t);
         printf("your car is parked for %f seconds\n",diff_t);
         printf("So your charges is %f rupees\n",(0.02*diff_t));
        temp=head;
        head=head->next;
        temp=NULL;
        curr_n=head;
        return head;
        }
        else{
        diff_t = difftime(end_t, curr_n->start_t);
         printf("your car is parked for %f seconds\n",diff_t);
          printf("So your charges is %f rupees\n",(0.02*diff_t));
        temp->next=curr_n->next;
        return head;
    }
    temp=curr_n;
    }
}
if(flag==0){
    printf("your car is not in the parking\n");
    return(head);
}
}
void search(struct node* head){
struct node* temp;
int a,flag=0;
char name[20],car_no[20];
printf("enter id: ");
fflush(stdin);
scanf("%d",&a);
printf("enter owner name");
fflush(stdin);
gets(name);
printf("enter car no.");
gets(car_no);
for(temp=head;temp!=NULL;temp=temp->next){
    if(temp->id==a&&strcmp(temp->car_no,car_no)==0&&strcmp(temp->owner_name,name)==0){
        printf("yes...your car is in parking\n");
        flag=1;
    }
}
if(flag==0)
    printf("your car is not in parking\n");
}
void display(struct node* head){
struct node* temp;
if(head==NULL){
    printf("there is no car in parking\n");
    return;
}
printf("id\towner_name\tcar_no\n");
for(temp=head;temp!=NULL;temp=temp->next){
    printf("%d\t",temp->id);
    fputs(temp->owner_name,stdout);
    printf("\t\t");
    fputs(temp->car_no,stdout);
    printf("\n");
}
}
void main(){
int n,a;
struct node* head;
head=NULL;
fp=fopen("parking_data.txt","a+");
if(fp==NULL){
    printf("error");
    getch();
    exit(0);
}
printf("%s",curr_time());
printf("enter total space in parking\n");
scanf("%d",&n);
printf("parking rate is 0.01rupees per second\n");

while(1){
printf("enter choice \n");
printf("1. if u want to park your car\n");
printf("2. if u want to take away your car from parking\n");
printf("3. if u want to know that your car is in parking or not\n");
printf("4. if u want to display all the cars in parking\n");
printf("5. if u want to exit the program\n");
scanf("%d",&a);
switch(a){
case 1:
    {if(count==n){
        printf("sorry ...parking is full.. \n ");
         continue;
    }
    if(count==0){
        count++;
      head=create();
      break;
    }
     else{
         count++;
        add(head);
    break;}
    }
case 2:
    {if(count==0){
        printf("there is no car in parking\n");
        continue;
        }
    else{

        head=del(head);
    break;}
    }
case 3:
    {
        search(head);
        break;
    }
case 4:  {
    display(head);
    break;
}
default:
    {fclose(fp);
        exit(1);
    }
}
}
}
