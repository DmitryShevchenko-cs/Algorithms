using System;
using System.IO;
using System.Diagnostics;

namespace Lab5
{
    internal class Program
    {
        private static void menu()
        {
            Console.WriteLine("1 - Поиск в массиве");
            Console.WriteLine("2 - Поиск подстроки");
        }
        static void Main(string[] args)
        {

            int[] arr = new int [20];
            int choice = -1;
            int key;
            string str;
            string podstr;

            var sw = new Stopwatch();
          

            while (true)
            {
                menu();
                choice = Convert.ToInt32(Console.ReadLine());
                switch (choice)
                {
                    case 1:
                        string[] lines = File.ReadAllLines("array.txt");
                        arr = new int[lines.Length];
                        int i = 0;
                        foreach (var item in lines)
                            arr[i++] = Convert.ToInt32(item);

                        foreach (var item in arr)
                            Console.Write(item + " ");
                        Console.WriteLine("");

                        Console.WriteLine("Введите число для поиска");
                        key = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Прямой поиск");
                        sw.Reset();
                        sw.Start();
                        Console.WriteLine(LinearSearch.Search(arr, key));
                        sw.Stop();
                        Console.WriteLine("Время: " + sw.Elapsed);
                        Console.WriteLine("");

                        Console.WriteLine("Поиск с барьером");
                        sw.Reset();
                        sw.Start();
                        Console.WriteLine(LinearSearch.SearchBarrier(arr, key));
                        sw.Stop();
                        Console.WriteLine("Время: " + sw.Elapsed);
                        Console.WriteLine("");

                        Console.WriteLine("Бинарный поиск");
                        BubbleSort.Sort(arr);
                        sw.Reset();
                        sw.Start();
                        Console.WriteLine(LinearSearch.BinarySearch(arr, key));
                        sw.Stop();
                        Console.WriteLine("Время: " + sw.Elapsed);
                        Console.WriteLine("");

                        break;

                    case 2:
                        Console.WriteLine("Введите строку");
                        str = Console.ReadLine();
                        Console.WriteLine("Введите подстроку");
                        podstr = Console.ReadLine();

                        Console.WriteLine("Прямой поиск подстроки");
                        sw.Reset();
                        sw.Start();
                        Console.WriteLine(FindStr.FindSubstring(podstr, str));
                        sw.Stop();
                        Console.WriteLine("Время: " + sw.Elapsed);
                        Console.WriteLine("");

                        int[] indexArr;

                        Console.WriteLine("Алгоритм Кнута-Морріса-Пратта");
                        sw.Reset();
                        sw.Start();
                        indexArr = FindStr.KnuthSearch(str, podstr);
                        sw.Stop();
                        foreach (var ind in indexArr)
                            Console.Write(ind + " ");
                        Console.WriteLine("\nВремя: " + sw.Elapsed);
                        Console.WriteLine("");

                        Console.WriteLine("алгоритм Бойера-Мура");
                        sw.Reset();
                        sw.Start();
                        indexArr = FindStr.BoyerSerch(str, podstr);
                        sw.Stop();
                        foreach (var ind in indexArr)
                            Console.Write(ind + " ");
                        Console.WriteLine("\nВремя: " + sw.Elapsed);
                        Console.WriteLine("");

                        Console.WriteLine("Алгоритм Рабина–Карпа");
                        sw.Reset();
                        sw.Start();
                        indexArr = FindStr.KarpSearch(str, podstr);
                        sw.Stop();
                        foreach (var ind in indexArr)
                            Console.Write(ind + " ");
                        Console.WriteLine("\nВремя: " + sw.Elapsed);
                        Console.WriteLine("");

                        break;

                    case 3:

                        break;
                    default:
                        Console.WriteLine("Невверный ввод");
                        break;
                }

            }
        

        }
    }
}
