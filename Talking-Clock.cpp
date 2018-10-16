#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;

char* hour_char[] = {"twelve","one","two","three","four","five","six","seven","eight","nine","ten","eleven"};

char* tens[]= {"oh","","twenty","thirty","forty","fifty"};
char* ones[] = {"","one","two","three","four","five","six","seven","eight","nine"};


void writeout()
{
    for(int i=0; i < 7; i++)
        printf("%s",tens[i]);
}

void hour(int x)
{
    if(x<12)
        printf("%s",hour_char[x]);
    else
        printf("%s",hour_char[x-12]);
}
void minute(int x)
{
    int tensdigit, onesdigit;
    tensdigit = x/10;
    onesdigit = x%10;
    switch(tensdigit)
    {
    case 0:
    {
        switch (onesdigit)
        {
            case 0:
            printf("");
            break;
        default:
            printf(" %s %s",tens[tensdigit],ones[onesdigit]);
        }
    }
        break;
    case 1:
    {
         switch (onesdigit)
        {
        case 0:
            printf(" ten");
            break;
        case 1:
            printf(" eleven");
            break;
        case 2:
            printf(" twelve");
            break;
        case 3:
            printf(" thirteen");
            break;
        case 5:
            printf(" fifteen");
            break;
        default:
            {
                printf(" %s",ones[onesdigit]);
                printf("teen");
            }
        }
        break;
    }
    default:
        printf(" %s %s",tens[tensdigit],ones[onesdigit]);
    }
}

void put_in_time(char a[])
{
    int hour_num, minute_num;
    sscanf(a,"%d:%d",&hour_num,&minute_num);
    if(hour_num >= 12)
    {
        printf("It's ");
        hour(hour_num);
        minute(minute_num);
        printf(" pm");
    }else if((hour_num< 12) && (hour_num >=0))
    {
        printf("It's ");
        hour(hour_num);
        minute(minute_num);
        printf(" am");
    }
}
int main()
{
    char str[6];
    printf("Input an hour (0-23) followed by a colon followed by the minute (0-59)\n");
    gets(str);
    put_in_time(str);
    return 0;
}

