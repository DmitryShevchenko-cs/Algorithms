using System;
using System.Diagnostics;
namespace Lab_4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[10];
            Random rd = new Random();

            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = rd.Next(1, 10);
            }

            foreach(int i in arr)
                Console.Write($"{i} ");  
            Console.ReadLine();
            
            Stopwatch stopwatch = new Stopwatch();

            stopwatch.Start();

            //BubbleSort.Sort(arr);
            PyramidSort.Sort(arr);
            //CountingSort.Sort(arr);
         
            stopwatch.Stop();
            
            foreach (int i in arr)
                Console.Write($"{i} ");
            Console.WriteLine();

            Console.WriteLine(stopwatch.ElapsedMilliseconds);  

        }
    }
}
