#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define TRUE 1
int main() {

    int x = 0;
    int ret;

    int forked = fork();


    if(forked == 0){
        ret = execl ("/usr/bin/xclock", "myXclock",  (char *)0);
    }
    else{
        while(TRUE){
            char buff[100];
            time_t now = time (0);
            strftime (buff, 100, "[%Y-%m-%d] %H:%M:%S", localtime (&now));
            printf ("%s\n", buff);
            sleep(5);

            if(x%3==1){
              printf ("“This program has gone on for far too long. Type Ctrl+C to abort this silly application\n");
            }
            x++;
        }
    }

    return 0;
}
