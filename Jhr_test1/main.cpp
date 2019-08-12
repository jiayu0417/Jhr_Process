#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/time.h>
int stdin_nonblock_init(){
    int flags;
    if(flags = fcntl(STDIN_FILENO,F_GETFL,0)<0){
        printf("F_GETFL error");
        exit(1);
    }
    flags |= O_NONBLOCK;
    if(fcntl(STDIN_FILENO,F_SETFL,flags)<0){
        printf("F_SETFL error");
        exit(2);
    }
    return 0;
}
/** 指定时间内执行一定的任务
 * @brief task_delay
 */
void task_delay(int dy){
    static struct  timeval static_time;
    struct  timeval curr_time;
    gettimeofday(&curr_time,NULL);
    unsigned  long diff = 1000 * (curr_time.tv_sec-static_time.tv_sec)+ (curr_time.tv_usec-static_time.tv_usec)/1000;
    if(diff < dy)return;
    gettimeofday(&static_time,NULL);
    printf("%d\n",diff);
}


int main(){
    char buf[1024];
    stdin_nonblock_init();
    while(1){
        ssize_t iLen;
        usleep(1000);
        iLen = read(STDIN_FILENO,buf,1023);
        if(iLen > 0 && iLen < sizeof(buf)-1){
            buf[iLen]=0;
            printf("rcv:%d  %s",iLen, buf);
        }
        task_delay(5000);
    }
}
