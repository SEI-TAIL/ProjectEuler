using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProjectEuler
{
    class NO_0017
    {
        public void Run()
        {
            // one two three four five six seven eight nine ten
            // eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen
            // twenty thirty forty fifty sixty seventy eighty ninety
            // hundred thousand and
            Dictionary<string,int> letters = new Dictionary<string,int>()
            {
                {"0",0},{"1",3},{"2",3},{"3",5},{"4",4},{"5",4},{"6",3},{"7",5},{"8",5},{"9",4},
                {"10",3},{"11",6},{"12",6},{"13",8},{"14",8},{"15",7},{"16",7},{"17",9},{"18",8},{"19",8},
                {"20",6},{"30",6},{"40",5},{"50",5},{"60",5},{"70",7},{"80",6},{"90",6}
            };
            int sum = 0;
            for (int i = 1; i <= 1000; i++)
            {
                if (i == 1000)
                {
                    sum += 11;//one thousand
                    continue;
                }
                //100の位
                if (i / 100 != 0)
                {
                    sum += letters[(i/100).ToString()] + 7;//n hundred
                    if (i % 100 != 0) sum += 3;//and
                }
                if (i % 100 == 0) continue;
                //下2桁
                var str = i.ToString();
                if (i % 100 >= 20)
                {
                    sum += letters[str[str.Length - 2] + "0"];
                    sum += letters[str.Substring(str.Length-1, 1)];
                }
                else if (10 <= i%100 && i%100 < 20) sum += letters[str.Substring(str.Length - 2, 2)];
                else sum += letters[str.Substring(str.Length-1, 1)];
            }
            Console.WriteLine(sum);
        }
    }
}
