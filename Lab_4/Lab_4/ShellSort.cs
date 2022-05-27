using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4
{
    internal class ShellSort
    {
        static void Swap(ref int a, ref int b)
        {
            var t = a;
            a = b;
            b = t;
        }
        public static void Sort(int[] array)
        {
            var d = array.Length / 2;
            while (d >= 1)
            {
                for (var i = d; i < array.Length; i++)
                {
                    var j = i;
                    while ((j >= d) && (array[j - d] > array[j]))
                    {
                        Swap(ref array[j], ref array[j - d]);
                        j = j - d;
                    }
                }

                d = d / 2;
            }
        }
    }
}
