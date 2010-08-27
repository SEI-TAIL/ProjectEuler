using System;
 
namespace ProjectEuler
{
        class Program
    {
        static void Main(string[] args)
        {
            new NO_0019().Run();
        }
    }
    
    class NO_0019
    {
        enum Month
        {
            January = 1,
            February,
            March,
            April,
            May,
            June,
            July,
            August,
            September,
            October,
            November,
            December
        }
 
        enum DaysOfMonth
        {
            January = 31,
            February = 28,
            March = 31,
            April = 30,
            May = 31,
            June = 30,
            July = 31,
            August = 31,
            September = 30,
            October = 31,
            November = 30,
            December = 31
        }
 
        public void Run(){
            int count=0, today= 1;
            int day = 1, month = 1, year = 1900;
            while(year < 2001){
                if (day == 1 && today % 7 == 0 && year > 1900)
                {
                    count++;
                }
 
                switch (month)
                {
                    case (int)Month.January:
                        if (day == (int)DaysOfMonth.January)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.February:
                        int febdays = (int)DaysOfMonth.February;
                        //閏年
                        if( year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
                            febdays++;
                        }
                        if (day == febdays)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.March:
                        if (day == (int)DaysOfMonth.March)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.April:
                        if (day == (int)DaysOfMonth.April)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.May:
                        if (day == (int)DaysOfMonth.May)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.June:
                        if (day == (int)DaysOfMonth.June)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.July:
                        if (day == (int)DaysOfMonth.July)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.August:
                        if (day == (int)DaysOfMonth.August)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.September:
                        if (day == (int)DaysOfMonth.September)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.October:
                        if (day == (int)DaysOfMonth.October)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.November:
                        if (day == (int)DaysOfMonth.November)
                        {
                            day = 0;
                            month++;
                        }
                        break;
                    case (int)Month.December:
                        if (day == (int)DaysOfMonth.December)
                        {
                            day = 0;
                            month = 1;
                            year++;
                        }
                        break;
                //defalut:
                //        Console.WriteLine("Month Error");
                //            break;
                }
                day++;
                today++;
            }
            Console.WriteLine(count);
        }
    }
}
