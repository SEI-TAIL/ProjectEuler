using System;
using System.Linq;
 
namespace ProjectEuler
{
    class NO_0022
    {
        public static void Main()
        {
            long sum = 0;
            using (System.IO.StreamReader sr = new System.IO.StreamReader(@"names.txt"))
            {
                var namelist = sr.ReadToEnd().Split(',').Select(name => name.Replace("\"", ""))
                    .OrderBy(name => name).Select((name,index) => new {index, name});
                foreach (var person in namelist)
                {
                    //Console.WriteLine("{0} {1}", person.index, person.name);
                    var score = (person.index + 1)
                        * person.name.ToCharArray().Aggregate(0, (nsum, chara) => nsum + ((int)chara - 'A' + 1));
                    sum += score;
                }
            }
            Console.WriteLine(sum);
        }
    }
}
