using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    internal class search
    {
        public static int BinarySearch(int[] inputArray, int searchValue)
        {
            int min = 0;
            int max = inputArray.Length - 1;
            while (min <= max)
            {
                int mid = (min + max) / 2;
                if (searchValue == inputArray[mid])
                {
                    return mid;
                }
                else if (searchValue < inputArray[mid])
                {
                    max = mid - 1;
                }
                else
                {
                    min = mid + 1;
                }
            }
            return -1;
        }

        private static void CheckArray<T>(T[] a)
        {
            if (a == null)
            {
                throw new ArgumentNullException("Масив не може бути нульовим");
            }

            if (a.Length == 0)
            {
                throw new ArgumentException("Довжина масиву повинна бути більше нуля");
            }
        }
        public static int LinearSearch(int[] a, int key)
        {
            CheckArray(a);

            for (int i = 0; i < a.Length; ++i)
            {
                // порівнює поточне значення з ключем
                if (a[i].Equals(key))
                {
                    return i;
                }
            }
            //якщо нічого не знайдено
            return -1;
        }

        public static int LinearSearchBarrier(int [] arr, int key)
        {
            int last = arr[arr.Length - 1];//Сохраним прежний элемент массива
            arr[arr.Length - 1] = key;//Гарантируем, что value есть в массиве
                                  //Есть гарантия того, что элемент есть в массиве, значит индекс можно не проверять
            int i = 0;
            for (i = 0; arr[i] != key; ++i)
            {//Одно условие в цикле
            }
            arr[arr.Length - 1] = last;
            if (i != (key - 1) || key == last)
            {
                return i;
            }
            return -1;
        }

    }
}
