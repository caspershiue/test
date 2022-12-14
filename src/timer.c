#include "../inc/timer.h"
#include "../inc/shogi.h"

ev_io stop_watcher; 
ev_timer timeout_watcher;
time_t xtimestart,xtime,ytimestart,ytime,xusedtime,yusedtime;
int xhour, xminute, xsecond,yhour, yminute, ysecond;

void timer()
{
    struct ev_loop *loop = EV_DEFAULT;
    ev_io_init (&stop_watcher, stop_cb,0, EV_READ); //Call the call back function when io incident happen
    ev_io_start (loop, &stop_watcher);  //Start stop watcher
    ev_timer_init(&timeout_watcher, timeout_cb,0,1); //Call the call back function once for one second  
    ev_timer_start (loop, &timeout_watcher);  //Start timeout watcher
    if(player==1)
        xtimestart=time(NULL);  //Set start time of player X
    else
        ytimestart=time(NULL);  //Set start time of player Y
    ev_run(loop,0);  //Put the watcher into the libev loop and run
}
//The timer of move chess
void timerm()
{
    struct ev_loop *loop = EV_DEFAULT;
    ev_io_init (&stop_watcher, stop_cb,0, EV_READ);
    ev_io_start (loop, &stop_watcher);
    ev_timer_init(&timeout_watcher, timeout_cbm,0,1);
    ev_timer_start (loop, &timeout_watcher);
    if(player==1)
        xtimestart=time(NULL);
    else
        ytimestart=time(NULL);
    ev_run(loop,0);
}
//The timer of hit in before enter the select chess
void timerh1()
{
    struct ev_loop *loop = EV_DEFAULT;
    ev_io_init (&stop_watcher, stop_cb,0, EV_READ);
    ev_io_start (loop, &stop_watcher);
    ev_timer_init(&timeout_watcher, timeout_cbh1,0,1);
    ev_timer_start (loop, &timeout_watcher);
    if(player==1)
        xtimestart=time(NULL);
    else
        ytimestart=time(NULL);
    ev_run(loop,0);
}
//The timer of hit in before enter the location
void timerh2()
{
    struct ev_loop *loop = EV_DEFAULT;
    ev_io_init (&stop_watcher, stop_cb,0, EV_READ);
    ev_io_start (loop, &stop_watcher);
    ev_timer_init(&timeout_watcher, timeout_cbh2,0,1);
    ev_timer_start (loop, &timeout_watcher);
    if(player==1)
        xtimestart=time(NULL);
    else
        ytimestart=time(NULL);
    ev_run(loop,0);
}
//The timer of promote chess
void timerp()
{
    struct ev_loop *loop = EV_DEFAULT;
    ev_io_init (&stop_watcher, stop_cb,0, EV_READ);
    ev_io_start (loop, &stop_watcher);
    ev_timer_init(&timeout_watcher, timeout_cbp,0,1);
    ev_timer_start (loop, &timeout_watcher);
    if(player==1)
        xtimestart=time(NULL);
    else
        ytimestart=time(NULL);
    ev_run(loop,0);
}
//The callback of time
void timeout_cb (EV_P_ ev_timer *w, int revents)
{   
    //Compute the time pass by since timestart and change the seconds into hours, minutes, and second 
    if(player==1){ 
        xtime = time(NULL);
        xhour = (xtime - xtimestart + xusedtime) / 3600;
        xminute = (xtime - xtimestart + xusedtime - xhour * 3600)/60;
        xsecond = xtime - xtimestart + xusedtime - xhour * 3600 - xminute * 60;
    }
    else{
        ytime = time(NULL);
        yhour = (ytime - ytimestart + yusedtime) / 3600;
        yminute = (ytime - ytimestart + yusedtime - yhour * 3600)/60;
        ysecond = ytime - ytimestart + yusedtime - yhour * 3600 - yminute * 60;
    }
    system("clear");
    //Display the interface of the game
    printf(" ??????x???????????????%02d:%02d:%02d\n",xhour,xminute,xsecond);
    printf(" ??????y???????????????%02d:%02d:%02d\n\n",yhour,yminute,ysecond);
    chessprint();
    printf(" ?????????????????????H\n ???????????????0\n ?????????????????????????????????S\n ?????????????????????x\n");
    if(player==1)
        printf(" ??????X????????????????????? X ????????? Y ??????: ");
    else
        printf(" ??????y????????????????????? X ????????? Y ??????: ");
    fflush(stdout);
}
//The callback of timem
void timeout_cbm (EV_P_ ev_timer *w, int revents)
{   
    if(player==1){
        xtime = time(NULL);
        xhour = (xtime - xtimestart + xusedtime) / 3600;
        xminute = (xtime - xtimestart + xusedtime - xhour * 3600)/60;
        xsecond = xtime - xtimestart + xusedtime - xhour * 3600 - xminute * 60;
    }    
    else{
        ytime = time(NULL);
        yhour = (ytime - ytimestart + yusedtime) / 3600;
        yminute = (ytime - ytimestart + yusedtime - yhour * 3600)/60;
        ysecond = ytime - ytimestart + yusedtime - yhour * 3600 - yminute * 60;
    }
    system("clear");
    printf(" ??????x???????????????%02d:%02d:%02d\n",xhour,xminute,xsecond);
    printf(" ??????y???????????????%02d:%02d:%02d\n\n",yhour,yminute,ysecond);
    chessprint();
    if(player==1)
        printf(" ??????X???????????? X ????????? Y ??????: ");
    else
        printf(" ??????Y???????????? X ????????? Y ??????: ");
    fflush(stdout);  
}
//The callback of timeh1
void timeout_cbh1(EV_P_ ev_timer *w, int revents)
{   
    if(player==1){
        xtime = time(NULL);
        xhour = (xtime - xtimestart + xusedtime) / 3600;
        xminute = (xtime - xtimestart + xusedtime - xhour * 3600)/60;
        xsecond = xtime - xtimestart + xusedtime - xhour * 3600 - xminute * 60;
    }
    else{
        ytime = time(NULL);
        yhour = (ytime - ytimestart + yusedtime) / 3600;
        yminute = (ytime - ytimestart + yusedtime - yhour * 3600)/60;
        ysecond = ytime - ytimestart + yusedtime - yhour * 3600 - yminute * 60;
    }
    system("clear");
    printf(" ??????x???????????????%02d:%02d:%02d\n",xhour,xminute,xsecond);
    printf(" ??????y???????????????%02d:%02d:%02d\n\n",yhour,yminute,ysecond);
    chessprint();
    printf(" ??????????????????????????????????????????\n");
    fflush(stdout);
}
//The callback of timeh2
void timeout_cbh2(EV_P_ ev_timer *w, int revents)
{   
    if(player==1){
        xtime = time(NULL);
        xhour = (xtime - xtimestart + xusedtime) / 3600;
        xminute = (xtime - xtimestart + xusedtime - xhour * 3600)/60;
        xsecond = xtime - xtimestart + xusedtime - xhour * 3600 - xminute * 60;
    }
    else{
        ytime = time(NULL);
        yhour = (ytime - ytimestart + yusedtime) / 3600;
        yminute = (ytime - ytimestart + yusedtime - yhour * 3600)/60;
        ysecond = ytime - ytimestart + yusedtime - yhour * 3600 - yminute * 60;
    }
    system("clear");
    printf(" ??????x???????????????%02d:%02d:%02d\n",xhour,xminute,xsecond);
    printf(" ??????y???????????????%02d:%02d:%02d\n\n",yhour,yminute,ysecond);
    chessprint();
    printf(" ???????????????????????????\n");
    fflush(stdout);
}
//The callback of timet
void timeout_cbp(EV_P_ ev_timer *w, int revents)
{   
    if(player==1){
        xtime = time(NULL);
        xhour = (xtime - xtimestart + xusedtime) / 3600;
        xminute = (xtime - xtimestart + xusedtime - xhour * 3600)/60;
        xsecond = xtime - xtimestart + xusedtime - xhour * 3600 - xminute * 60;
    }
    else{
        ytime = time(NULL);
        yhour = (ytime - ytimestart + yusedtime) / 3600;
        yminute = (ytime - ytimestart + yusedtime - yhour * 3600)/60;
        ysecond = ytime - ytimestart + yusedtime - yhour * 3600 - yminute * 60;
    }
    system("clear");
    printf(" ??????x???????????????%02d:%02d:%02d\n",xhour,xminute,xsecond);
    printf(" ??????y???????????????%02d:%02d:%02d\n\n",yhour,yminute,ysecond);
    chessprint();
    printf("???????????????y\n??????????????????n\n");
    fflush(stdout);
}
//The callback of io incident happen that is able to stop counting time
void stop_cb (EV_P_ ev_io *w, int revents)
{
    //Save the used time
    if (player==1)
        xusedtime = xtime-xtimestart + xusedtime;
    else
        yusedtime = ytime - ytimestart + yusedtime;
    // Stop the watchers
    ev_io_stop (EV_A_ w);
    ev_timer_stop (loop, &timeout_watcher);
    // This causes all nested ev_run's to stop iterating
    ev_break (EV_A_ EVBREAK_ALL);
}