#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<windows.h>

struct words
{
    char word[20];
    struct words*next;
};
struct players
{
    char* name ;
    double points;
    struct players*next;
};
struct words* wlist=NULL;
struct players* plist=NULL;



void address_maker(int a,char* input )
{
    char* asli=malloc(20);
    char* part1=malloc(10);
    char* part2=".txt";
    char array[30]="C:\\finp\\level-";
    sprintf(part1,"%d",a);
    strcat(part1,part2);
    strcat(array,part1);
    asli=array;
    strcpy(input,asli);
}
int file_counter(void)
{
    int i=1;
    char* address=malloc(20);
    FILE* handler;
    FILE* temp;
    do
    {
        address_maker(i,address);
        handler=fopen(address,"r");
        /*if(handler==NULL)
            printf("cant open the file\n");*/
        temp=handler;
        fclose(temp);
        i++;
    }
    while(handler!=NULL);

    return i-2;
}

void delete_node(struct words* cur)
{
    //struct words* tmp;
    //tmp=cur;
    cur=cur->next;

}
 struct words* creat_nw(char array[20])
 {
     struct words*pl;
     int i;
     pl=malloc(sizeof(struct words));
    for(i=0;i<20;i++)
         {
             pl->word[i]=array[i];
             if(array[i]=='\0')
                break;
         }
     pl->next=NULL;
     return pl;
 };
 struct player* creat_np(char *player_name,float p_points)
 {

     struct players* pp=malloc(sizeof(struct players));
     pp->name=player_name;
     pp->points=p_points;
     pp->next=NULL;
     return pp;
 };


 void F_to_list_w(char* fname)
 {

     char array[20];

     struct words* current;
     FILE* fp;
     fp=fopen(fname,"r");
     if(fp==NULL)
        printf("ay baba");
        fscanf(fp,"%s",array);
        current=creat_nw(array);
        wlist=current;
        //current=current->next;

        while(1)
        {if(feof(fp))
        break;
            fscanf(fp,"%s",array);
            current->next=creat_nw(array);
            current=current->next;


        }

     fclose(fp);

 };
 /*struct player* creat_np(char *player_name,int p_level,float p_points)
 {

     struct players* pp=malloc(sizeof(struct players));
     pp->name=player_name;
     pp->level=p_level;
     pp->points=p_points;
     pp->next=NULL;
     return pp;
 };*/
 struct words* select_word(void)
 {
     if(wlist->next==NULL)
        return NULL;
     struct words* index;
     struct words* selected;
     int go,j,i=1;
     double tmp;
     time_t t=NULL;
     srand(t);
     for(index=wlist;index->next!=NULL;index=index->next)
     {
         i++;
     }

     tmp=rand()/RAND_MAX;
     go=tmp*i;
     index=wlist;
     for(j=1;j<go-1;j++)
     {
         index=index->next;
     }

     selected=index->next;

     index->next=index->next->next;

     selected->next=NULL;
     return selected;
 }
 /*int F_to_list_p(void)
 {
     int i;
     char* check;
     struct players* current=plist;
     char* name;
     float point;
     char c;
     FILE* fp;
     fp=fopen("C:\\finp\\players.txt","r");
     if(fp==NULL)
     {
         printf("cannot open the file");
     }
         while(1)
         {
         check=fgets(name,30,fp);
         if(check==NULL)
            break;
         fscanf(fp,"%lf",point);
         current=creat_np(name[30],point);
         current=current->next;
         }
     fclose(fp);
     if(plist==NULL)
        return 0;
     else
        return 1;
 };*/
/* void F_to_list_p(void)
 {
     struct players * current;
     char* check;
     char name[20];
     double score;
     FILE* fp=fopen("C:\\finp\\players.txt","r");
     if(fp==NULL)
     {
         printf("cant open the file");
         return ;
     }
     check=fgets(name,20,fp);
     if(check==NULL)
     {
         printf("file is empty");
         return ;
     }
     fscanf(fp,"%lf",&score);
     current=creat_np(name,score);
     plist=current;
    fseek(fp,2,SEEK_CUR);
     while(1)
     {
         fgets(name,20,fp);
         fscanf(fp,"%lf",&score);
         fseek(fp,2,SEEK_CUR);
         current->next=creat_np(name,score);
         current=current->next;
         if(feof)
            break;
     }


 };*/
void write_p(void)
{
    FILE* fp=fopen("C:\\finp\\players.txt","w");
    if(fp==NULL)
        printf("cant open players");
    struct players* cur=plist;
    while(cur!=NULL)
    {
        fputs(cur->name,fp);
        fputc('\n',fp);
        fprintf(fp,"%lf",cur->points);
        fputc('\n',fp);
        cur=cur->next;
    }
    fclose(fp);
}
/*void show_results(void)
{
    int i,j,size;
    struct players* index;
    struct players bridge;
    if(plist==NULL)
    {
        printf("there is nothing to be shown");

    }
    else
    {
        for(size=0,index=plist;index!=NULL;size++,index=index->next);
        struct players p_tmp[size];
        for(i=0,index=plist;i<size;index=index->next,i++)
        {
            p_tmp[i]=*index;
        }
        for(i=0;i<size-1;i++)
        {
            for(j=i+1;j<size;j++)
            {
                if(p_tmp[i].points<p_tmp[j].points)
                {
                    bridge=p_tmp[i];
                    p_tmp[i]=p_tmp[j];
                    p_tmp[j]=bridge;
                }
            }
        }
        i=1;
        if(size<10)
        {
            for(j=size-1;j>=-1;j--)
            {
                printf("%d=> %s: %d",i,p_tmp[j].name,p_tmp[j].points);
                i++;
            }
        }
        else
        {
            for(j=size-1;j>=size-10;j--)
            {
                printf("%d=> %s: %d",i,p_tmp[j].name,p_tmp[j].points);
                i++;
            }
        }
    }
    /*for(i=size-1;i>=size-10;i--)
    {
        printf("%d. %s : %d",i+1,p_tmp[i].name,p_tmp[i].points);
    }
    if(size<10)
    {
        for(i=0;i<size;i++)
        {
            printf("%d. %s : %d",i+1,p_tmp[i].name,p_tmp[i].points);
        }
        for(i=size+1;i<=10;i++)
        {
            printf("%d.",i);
        }
    }*/



void enter_zan(char* input)
{
    char array[30];
    strcpy(array,input);
    strcat(array,"\n");
    input=array;

}



void F_to_list_p(void)
 {
     struct players * current;
     char* check;
     char name[20];
     double score;
     FILE* fp=fopen("C:\\finp\\players.txt","r");
     if(fp==NULL)
     {
         printf("cant open the file");
         return ;
     }
     check=fgets(name,20,fp);
     if(check==NULL)
     {
         printf("file is empty");
         return ;
     }
     fscanf(fp,"%lf",&score);
     current=creat_np(name,score);
     plist=current;
    // current=current->next;
    fseek(fp,2,SEEK_CUR);
     while(1)
     {
         fgets(name,20,fp);
         if(feof(fp))
            break;
         fscanf(fp,"%lf",&score);
         fseek(fp,2,SEEK_CUR);
         current->next=creat_np(name,score);
         current=current->next;
         if(feof(fp))
            break;
     }


 };


  /*  struct players* search_player(char* testn)
    {
        int ans;
        struct players* index;
        for(index=plist;index!=NULL;index=index->next)
        {
            ans=strcmpi(index->name,testn);
            if(ans==0)
            {
                return index;
            }
        }
        return NULL;
    };*/
/*int game (int level)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    clock_t start_t,end_t;
    int i,c_cnt=0,w_cnt=0;
    double estimated_time,points;
    struct words* index;
    char in;
    char* address=malloc(25);
    address_maker(level,address);
    F_to_list_w(address);
    system("color 2");
    start_t=clock();

    i=0;
    index=select_word();
    while(wlist!=NULL)
    {

        SetConsoleTextAttribute(hConsole, 15);
        printf("%s\n",index->word);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        scanf("%c",&in);
printf("i am here");


            if(in==index->word[i])
               {
                c_cnt++;
                index->word[i]=index->word[i]-32;
               }
            else
                w_cnt++;

        i++;
        if(index->word[i]=='\0')
        {
            free(index);
            index=select_word();

        }
        printf("%d%d",w_cnt,c_cnt);
    }
    end_t=clock();
    estimated_time=(end_t - start_t)/CLOCKS_PER_SEC;
    points=((3*c_cnt)-(w_cnt))/estimated_time;
    return points;
}*/



void show_results(void)
{
    int i,j,size;
    struct players* index;
    struct players bridge;
    if(plist==NULL)
    {
        printf("there is nothing to be shown");
     }
    else
    {
        for(size=0,index=plist;index!=NULL;size++,index=index->next);
        struct players p_tmp[size];
        for(i=0,index=plist;i<size;index=index->next,i++)
        {
            p_tmp[i]=*index;
        }
        for(i=0;i<size-1;i++)
        {
            for(j=i+1;j<size;j++)
            {
                if(p_tmp[i].points>p_tmp[j].points)
                {
                    bridge=p_tmp[i];
                    p_tmp[i]=p_tmp[j];
                    p_tmp[j]=bridge;
                }
            }
        }
        i=1;
        if(size<10)
        {
            for(j=size-1;j>-1;j--)
            {
                printf("%d %s=> %lf\n",i,p_tmp[j].name,p_tmp[j].points);
                i++;
            }
        }
        else
        {
            for(j=size-1;j>=size-10;j--)
            {
                printf("%d %s=> %lf\n",i,p_tmp[j].name,p_tmp[j].points);
                i++;
            }
        }
    }
}


double game (int level)
{   system("color 2");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    clock_t start_t,middle1,middle2,end_t;
    middle1=0;
    middle2=0;
    int i,c_cnt=0,w_cnt=0;
    double estimated_time,points;
    struct words* index;
    char in;
    char* address=malloc(25);
    address_maker(level,address);
    F_to_list_w(address);

    start_t=clock();

    i=0;
    index=select_word();
    while(wlist!=NULL)
    {

        SetConsoleTextAttribute(hConsole, 15);
        printf("%s\n",index->word);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        in=getche();

        printf("\n");
        if(in=='Q')
            return -1;
        if(in=='P')
        {
            printf("game paused\n");
            middle1=clock();
            printf("press R for resume\n");
            in=getche();
            if(in=='R');
            {
                middle2=clock();
                continue ;
            }
        }

            if(in==index->word[i])
               {
                c_cnt++;
                index->word[i]=index->word[i]-32;
                i++;
               }
            else
                {
                    w_cnt++;
                }


        if(index->word[i]=='\0')
        {
            free(index);

            i=0;
            index=select_word();

            if(index==NULL)
                break;

        }

    }
    end_t=clock();

    estimated_time=(double)(end_t - start_t)/CLOCKS_PER_SEC;
    printf("%lf",estimated_time);
    points=((3*c_cnt)-(w_cnt))/estimated_time;
    printf("%lf",points);

    return points;
}



int all_of_levels(int size,int array[size])
{
    int i;
    for(i=0;i<size;i++)
        {
            if(array[i]==0)
                return 0;
        }
        printf("you played all levels your progress hasbeen saved\n");
        write_p();
        return 1;
}

struct players* search_player(char* testn)
    {
        int ans;
        struct players* index;
        for(index=plist;index!=NULL;index=index->next)
        {
            ans=strcmpi(index->name,testn);
            printf("%s",testn);
            printf("%s",index->name);
            if(ans==0)
            {
                return index;
            }
        }
        return NULL;
    };

int main(void)
{
    int lev,i,number_of_files=file_counter();
    double game_score;
    int check_levels[number_of_files];
    for(i=0;i<number_of_files;i++)
        check_levels[i]=0;
    struct players* current;
    struct words* index;
    char* esm,address;
    char dastoor;
    F_to_list_p();
    printf("press: \n h for hint \n q for quit game \n L for load game \n n for new game and p for show the greatest ranks \n");
    scanf(" %c",&dastoor);
    if(dastoor=='h')
    {
        printf("press: \n h for hint \n q for quit game \n l for load game \n n for new game and p for show the greatest ranks\n ");
        printf("this game is about typing.\n I show a word to you and you have to type it correctly each correct letter will be converted to capital if you press a wrong key your score will be decresed");
    }
    else if(dastoor=='q')
    {
        write_p();
        printf("GAME OVER");
        return 0;
    }
    else if(dastoor=='p')
    {
        show_results();
    }
    else if(dastoor=='l')
    {

        printf("enter your name \n");
        scanf("%s",esm);
        enter_zan(esm);

        current=search_player(esm);
        if(current==NULL )
        {
            printf("NOT FOUND please try again \n");
        }
        else
        {
            while(1)
            {
                printf("now which level do you want to play I have at most %d levels\n",number_of_files);
                scanf("%d",&lev);
                if(lev>number_of_files)
                {
                    printf("invalid input try again\n");
                }
                else
                {
                    game_score=game(lev);
                    if(game_score==-1)
                        return 0;
                    check_levels[lev-1]=1;
                    i=all_of_levels(number_of_files,check_levels);
                    if(i==1)
                        return 0;
                    current->points=current->points + game_score;
                    printf("you finished this level now you have %lf points\n",current->points);
                    printf("now press s to save and quit or l to play another level");
                    scanf(" %c",&dastoor);
                    if(dastoor=='s')
                    {
                        write_p();
                        return 0;
                    }
                    if(dastoor=='l')
                    {
                        continue;
                    }
                    else
                    {
                        printf("wrong input your information has been saved");
                        write_p();
                        return 0;
                    }

                }
            }
        }

    }
    else if(dastoor=='n')
    {
        printf("please enter your name\n");
        scanf("%s",&esm);
        for(current=plist;current!=NULL;current=current->next);
        current=creat_np(esm,0);
        while(1)
            {
                printf("now which level do you want to play I have at most %d levels\n",number_of_files);
                scanf("%d",&lev);
                if(lev>number_of_files)
                {
                    printf("invalid input try again");
                }
                else
                {
                    game_score=game(lev);
                    if(game_score==-1)
                        return ;
                    check_levels[lev-1]=1;
                    i=all_of_levels(number_of_files,check_levels);
                    if(i==1)
                        return 0;
                    current->points=current->points +game_score;
                    printf("this level was finished \n");
                    printf("your score is %lf by now\n",current->points);
                    printf("now press s to save and quit or press c to continue\n");
                    scanf(" %c",&dastoor);
                    if(dastoor=='s')
                    {
                        write_p();
                        return 0;
                    }
                    if(dastoor=='c')
                    {
                        continue;
                    }
                    else
                    {
                        printf("wrong input your information has been saved\n");
                        write_p();
                        return 0;
                    }
                }
            }

    }
}
