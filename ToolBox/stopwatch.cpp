//http://www.codebaoku.com/it-c/it-c-yisu-720221.html

#include <stdio.h>
#include <conio.h>    //kbhit()/_kbhit() getch()
#include <Windows.h>  //Sleep(ms)
#include <sys/time.h> //struct timeval
#include <unistd.h>   //struct timeval

/******************************************************************************
 * @brief       获取系统当前秒数和毫秒(1970-1-1 0:0:0到现在)
 * @param tv    timeval结构体变量
 * @param tv_s  返回的秒数
 * @param tv_ms 返回的毫秒数
 ******************************************************************************/
void Get_Current_Timeval(struct timeval *tv, long *tv_s, long *tv_ms)
{
    gettimeofday(tv, NULL);      //获取1970-1-1到现在的时间保存到timeval变量
    *tv_s = tv->tv_sec;          //获取秒
    *tv_ms = tv->tv_usec / 1000; //获取毫秒
}

/******************************************************************************
 * @brief            获取两个timeval成员的差值，通过tv_s_diff和tv_ms_diff返回
 * @param tv_s_cur   当前系统时间秒数
 * @param tv_ms_cur  当前系统时间毫秒数
 * @param tv_s_old   计时初始时间(s)
 * @param tv_ms_old  计时初始时间(ms)
 * @param tv_s_diff  秒数的差值
 * @param tv_ms_diff 毫秒的差值
 ******************************************************************************/
void Get_Diff_Timeval(long tv_s_cur, long tv_ms_cur,
                      long tv_s_old, long tv_ms_old,
                      long *tv_s_diff, long *tv_ms_diff)
{
    if (tv_ms_cur < tv_ms_old)
    {
        *tv_ms_diff = tv_ms_cur + 1000 - tv_ms_old; //获取这段时间的毫秒数
        *tv_s_diff = tv_s_cur - tv_s_old - 1;       //获取这段时间的秒数(自上次暂停或自初始时间)
    }
    else
    {
        *tv_ms_diff = tv_ms_cur - tv_ms_old; //获取这段时间的毫秒数(自上次暂停或自初始时间)
        *tv_s_diff = tv_s_cur - tv_s_old;    //获取这段时间的秒数(自上次暂停或自初始时间)
    }
}

/******************************************************************************
 * 主函数
 * ****************************************************************************/
int main(void)
{
    struct timeval tv;
    long tv_s_cur = 0, tv_ms_cur = 0;   //当前系统时间
    long tv_s_old = 0, tv_ms_old = 0;   //计时初始时间
    long tv_s_diff = 0, tv_ms_diff = 0; //存放时间的差值
    int sec_cnt = 0, msec_cnt = 0;      //当前累计计时时长
    int hour = 0, min = 0, sec = 0, msec = 0;
    int timer_step = 0; //计时步骤 0：未开始，
                        // 1：开始，2：暂停
    char key = 0;

    /**************** 菜单打印 ****************/
    // printf("| 空格:开始/暂停 R:清零 Q:退出 |\n");
    // printf("================================\n"); //菜单
    
    system("color 0F");
    system("mode con cols=50  lines=20");
    system("title Stopwatch");

    printf("===========================================\n"); //菜单
    printf("| Num 0/1: Start/Pause   2: Clear   3: Quit |\n");
    printf("===========================================\n");
    printf("\t%02d:%02d:%02d %02d\r", 0, 0, 0, 0);
    while (1)
    {
        /**************** 键盘按键扫描+操作 ****************/
        key = 0;
        if (_kbhit())      //检测到按键按下
            key = getch(); //读取按键
        switch (key)
        {
        case '0':
        case '1':                //按空格键开始/暂停计时
            if (timer_step == 0) //如果还未开启计时
            {
                //获取当前秒和毫秒作为计时初始时间
                Get_Current_Timeval(&tv, &tv_s_old, &tv_ms_old);
                timer_step = 1; //开始计时
            }
            else if (timer_step == 1) //如果正在计时
            {
                timer_step = 2; //暂停计时
                //获取当前秒和毫秒
                Get_Current_Timeval(&tv, &tv_s_cur, &tv_ms_cur);
                //获取当前系统时间与计时初始时间的差值
                Get_Diff_Timeval(tv_s_cur, tv_ms_cur, tv_s_old,
                                 tv_ms_old, &tv_s_diff, &tv_ms_diff);
                msec_cnt += tv_ms_diff; //更新总累计计时时长(ms)
                if (msec_cnt >= 1000)
                {
                    msec_cnt -= 1000;
                    sec_cnt += tv_s_diff + 1; //更新总累计计时时长(s)
                }
                else
                    sec_cnt += tv_s_diff;
            }
            else if (timer_step == 2)
            {
                timer_step = 1; //继续计时
                //获取当前秒和毫秒
                Get_Current_Timeval(&tv, &tv_s_cur, &tv_ms_cur);
                tv_s_old = tv_s_cur;   //更新计时初始时间(s)
                tv_ms_old = tv_ms_cur; //更新计时初始时间(ms)
            }
            break;
        // case 'r': //按r/R清零计时时间
        // case 'R':
        case '2':
            sec_cnt = msec_cnt = 0; //总累计计时值清零
            tv_s_old = tv_s_cur;    //更新计时初始时间(s)
            tv_ms_old = tv_ms_cur;  //更新计时初始时间(ms)
            timer_step = 0;         //回到步骤0(未开始计时)
            printf("\t%02d:%02d:%02d %02d\r", 0, 0, 0, 0);
            break;
        // case '3':
        case '3':
            printf("程序退出\n");
            return 0;
        }

        /**************** 计时操作 ****************/
        if (timer_step == 1)
        {
            //获取当前秒和毫秒
            Get_Current_Timeval(&tv, &tv_s_cur, &tv_ms_cur);
            //获取当前系统时间与计时初始时间的差值
            Get_Diff_Timeval(tv_s_cur, tv_ms_cur, tv_s_old,
                             tv_ms_old, &tv_s_diff, &tv_ms_diff);
            tv_ms_diff += msec_cnt; //当前累计计时时长(ms)
            if (tv_ms_diff >= 1000)
            {
                tv_ms_diff -= 1000;
                tv_s_diff += sec_cnt + 1; //当前累计计时时长(s)
            }
            else
                tv_s_diff += sec_cnt;
            hour = tv_s_diff / 3600; //获取计时小时数
            min = tv_s_diff / 60;    //获取计时分钟数
            sec = tv_s_diff % 60;    //获取计时秒数
            msec = tv_ms_diff / 10;  //获取毫秒(单位10ms)
            //打印当前累计计时时长
            printf("\t%02d:%02d:%02d %02d\r", hour, min, sec, msec);
        }
        Sleep(60); // 10ms延时，防止打印太快导致显示效果不佳
    }
    return 0;
}


