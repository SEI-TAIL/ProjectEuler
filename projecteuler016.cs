using System;
 
namespace ProjectEuler
{
    class NO_0016
    {
        public static void Main(){
                new NO_0016().Run();
        }
        
        public void Run()
        {
            int[] digits = new int[500];
            digits[0] = 1;
            int sum = 0;
            for (int i = 0; i < 1000; i++)
            {
                for (int j = 499; j >= 0; j--)
                {
                    if (digits[j] * 2 >= 10) digits[j + 1]++;
                    digits[j] = digits[j] * 2 % 10;
                }
            }
            for (int i = 0; i < 500; i++)
            {
                sum += digits[i];
            }
            Console.WriteLine(sum);
        }
    }
}
