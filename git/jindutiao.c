#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
    int i = 0;
    char bar[102];
    memset(bar,'\0',sizeof(bar));
    const char *a="|/-\\";
    for(;i<=100;i++)
        {
            bar[i] = '*';
            if(i%4 == 1)
            {
            printf("\e[40;33m[%-101s]\e[0m[%d%%][\e[34m%c\e[0m]\r",bar,i,a[i%4]);
            }
            if(i%4 == 2)
            {
            printf("\e[40;35m[%-101s]\e[0m[%d%%][\e[33m%c\e[0m]\r",bar,i,a[i%4]);
            }
            if(i%4 == 3)
            {
            printf("\e[40;31m[%-101s]\e[0m[%d%%][\e[32m%c\e[0m]\r",bar,i,a[i%4]);
            }
            else
            {
            printf("\e[40;37m[%-101s]\e[0m[%d%%][\e[31m%c\e[0m]\r",bar,i,a[i%4]);
            }
            fflush(stdout);
            sleep(1);
        }
    printf("\n");

}
