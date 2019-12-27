#include<cstdio>
#include<algorithm>
using namespace std;
int isyeap(int x)
{
    if(x%4==0&&x%100!=0||x%400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int dayofMonth[13][2] = {
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};
int buf[3001][13][32]; //表示第i年第j月第k天距离0-1-1的天数
struct Data
{
    int year;
    int month;
    int day;
    void nextDay()
    {
        day++;
        if (day>dayofMonth[month][isyeap(year)])
        {
            day=1;
            month++;
            if(month>12)
            {
                month=1;
                year++;
            }
        }
    }
};
int main()
{
    Data tmp;
    tmp.year=0;
    tmp.month=1;
    tmp.day=1;
    int cnt=0;
    while (tmp.year<3001)
    {
        buf[tmp.year][tmp.month][tmp.day]=cnt;
        tmp.nextDay();
        cnt++;
        
    }
    int y1,m1,d1;
    int y2,m2,d2;
    while (scanf("%4d%2d%2d",&y1,&m1,&d1)==3)
    {
        scanf("%4d%2d%2d",&y2,&m2,&d2);
        printf("%d",abs(buf[y1][m1][d1]-buf[y2][m2][d2])+1);
    }
    return 0;   
}