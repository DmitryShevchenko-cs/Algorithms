using System;
using System.Diagnostics;
namespace Lab_4
{
    internal class Program
    {

        public static void menu()
        {
            Console.WriteLine("1 - Заполнить массив в ручную");
            Console.WriteLine("2 - Заполнить массив из файла");
            Console.WriteLine("3 - Заполнить массив случайными числами");
            Console.WriteLine("4 - Пузырьковая сорттировка");
            Console.WriteLine("5 - Пирамидальная сортировка");
            Console.WriteLine("6 - Сортировка счетом");
            Console.WriteLine("7 - Выход");
        } 

        static void Main(string[] args)
        {
            int size;
            int[] arr = new int[0];
            var sw = new Stopwatch();
            int choice = -1;
            while (true)
            {
                Program.menu();
                choice = Convert.ToInt32(Console.ReadLine());
                switch (choice)
                {
                    case 1:
                        
                        Console.WriteLine("Введите размер массива: ");
                        size = Convert.ToInt32(Console.ReadLine());
                        arr = new int[size];
                        Console.WriteLine("Ввод массива");

                        for (int i = 0; i < arr.Length; i++)
                        {
                            arr[i] = Convert.ToInt32(Console.ReadLine());
                        }
                        Console.WriteLine();
                        break;

                    case 2:
                        Console.WriteLine("Введите размер массива: ");
                        size = Convert.ToInt32(Console.ReadLine());
                        arr = new int[size];
                        break;

                    case 3:
                        Console.WriteLine("Введите размер массива: ");
                        size = Convert.ToInt32(Console.ReadLine());
                        arr = new int[size];
                        Random rd = new Random();
                        for (int i = 0; i < arr.Length; i++)
                        {
                            arr[i] = rd.Next(0, 50);
                        }
                        foreach (int i in arr)
                            Console.Write($"{i} ");
                        Console.WriteLine();
                        break;

                    case 4:
                        if (arr.Length > 0)
                        {
                            sw.Reset();
                            sw.Start();
                            BubbleSort.Sort(arr);
                            sw.Stop();

                            foreach (int i in arr)
                                Console.Write($"{i} ");
                            Console.WriteLine();
                            Console.WriteLine($"Время потрачено : {sw.Elapsed}");
                            Console.WriteLine(new string('_', 40));
                            Console.WriteLine();
                            Array.Clear(arr, 0, arr.Length);
                        }
                        else
                            Console.WriteLine("Массив пуст");
                            break;

                    case 5:
                        if (arr.Length > 0)
                        {
                            sw.Reset();
                            sw.Start();
                            PyramidSort.Sort(arr);
                            sw.Stop();

                            foreach (int i in arr)
                                Console.Write($"{i} ");
                            Console.WriteLine();
                            Console.WriteLine($"Время потрачено : {sw.Elapsed}\n");
                            Console.WriteLine(new string('_', 40));
                            Console.WriteLine();
                            Array.Clear(arr, 0, arr.Length);
                        }
                        else
                            Console.WriteLine("Массив пуст");
                        break;

                    case 6:
                        if (arr.Length > 0)
                        {
                            sw.Reset();
                            sw.Start();
                            CountingSort.Sort(arr);
                            sw.Stop();

                            foreach (int i in arr)
                                Console.Write($"{i} ");
                            Console.WriteLine();
                            Console.WriteLine($"Время потрачено : {sw.Elapsed}\n");
                            Console.WriteLine(new string('_', 40));
                            Console.WriteLine();
                            Array.Clear(arr, 0, arr.Length);
                        }
                        else
                            Console.WriteLine("Массив пуст");
                        break;

                    case 7:
                        return;

                    default:
                        Console.WriteLine("Ошибка ввода\n");
                        break;
                }


            }




        }
    }
}
