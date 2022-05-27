using System;
using System.IO;

namespace Lab5
{
    internal class Program
    {
        private static void menu()
        {
            Console.WriteLine("1 - Ввести інформацію в масив з файлу");//+
            Console.WriteLine("2 - Виконати лінійний пошук в масиві");//+
            Console.WriteLine("3 - Виконати пошук з бар'єром");//+
            Console.WriteLine("4 - Упорядкувати елементи масиву функцією сортування і виконати бінарний пошук");//+
            Console.WriteLine("5 - Виконати прямий пошук підрядка");
            Console.WriteLine("6 - Виконати алгоритм Кнута - Морріса - Пратта");//+
            Console.WriteLine("7 - Виконати алгоритм Бойера - Мура");
            Console.WriteLine("8 - Виконати алгоритм Рабина – Карпа");
        }
        static void Main(string[] args)
        {

            int[] arr = new int [20];
            int choice = -1;
            int key;
            string str;
            string podstr;
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
                        break;

                    case 2:
                        key = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(search.LinearSearch(arr, key));
                        break;

                    case 3:
                        key = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(search.LinearSearchBarrier(arr, key));
                        break;

                    case 4:
                        BubbleSort.Sort(arr);
                        key = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(search.BinarySearch(arr, key));
                        break;

                    case 5:
                        Console.WriteLine("Введите строку");
                        str = Console.ReadLine();
                        Console.WriteLine("Введите подстроку");
                        podstr = Console.ReadLine();
                        Console.WriteLine(str.IndexOf(podstr));
                        break;

                    case 6:
                        Console.WriteLine("Введите строку");
                        str = Console.ReadLine();
                        Console.WriteLine("Введите подстроку");
                        podstr = Console.ReadLine();
                        Console.WriteLine(FIndStr.FindSubstring(podstr,str));
                        break;

                    case 7:
                        Console.WriteLine("Введите строку");
                        str = Console.ReadLine();
                        Console.WriteLine("Введите подстроку");
                        podstr = Console.ReadLine();
                        Console.WriteLine(FIndStr.FindSubstring(podstr, str));
                        break;
                }

            }
        

        }
    }
}
