using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    internal class FindStr
    {
        static int[] GetPrefix(string s)
        {
            int[] result = new int[s.Length];
            result[0] = 0;
            int index = 0;

            for (int i = 1; i < s.Length; i++)
            {
                while (index >= 0 && s[index] != s[i]) { index--; }
                index++;
                result[i] = index;
            }

            return result;
        }
        public static int FindSubstring(string pattern, string text)
        {
            int[] pf = GetPrefix(pattern);
            int index = 0;

            for (int i = 0; i < text.Length; i++)
            {
                while (index > 0 && pattern[index] != text[i]) { index = pf[index - 1]; }
                if (pattern[index] == text[i]) index++;
                if (index == pattern.Length)
                {
                    return i - index + 1;
                }
            }

            return -1;
        }

        public static int[] KarpSearch(string str, string podstr)
        {
            List<int> retVal = new List<int>();
            ulong siga = 0;
            ulong sigb = 0;
            ulong Q = 100007;
            ulong D = 256;

            for (int i = 0; i < podstr.Length; ++i)
            {
                siga = (siga * D + (ulong)str[i]) % Q;
                sigb = (sigb * D + (ulong)podstr[i]) % Q;
            }

            if (siga == sigb)
                retVal.Add(0);

            ulong pow = 1;

            for (int k = 1; k <= podstr.Length - 1; ++k)
                pow = (pow * D) % Q;

            for (int j = 1; j <= str.Length - podstr.Length; ++j)
            {
                siga = (siga + Q - pow * (ulong)str[j - 1] % Q) % Q;
                siga = (siga * D + (ulong)str[j + podstr.Length - 1]) % Q;

                if (siga == sigb)
                    if (str.Substring(j, podstr.Length) == podstr)
                        retVal.Add(j);
            }

            return retVal.ToArray();
        }

        public static int[] BoyerSerch(string str, string pat)
        {
            List<int> retVal = new List<int>();
            int m = pat.Length;
            int n = str.Length;

            int[] badChar = new int[256];

            BadCharHeuristic(pat, m, ref badChar);

            int s = 0;
            while (s <= (n - m))
            {
                int j = m - 1;

                while (j >= 0 && pat[j] == str[s + j])
                    --j;

                if (j < 0)
                {
                    retVal.Add(s);
                    s += (s + m < n) ? m - badChar[str[s + m]] : 1;
                }
                else
                {
                    s += Math.Max(1, j - badChar[str[s + j]]);
                }
            }

            return retVal.ToArray();
        }        
        private static void BadCharHeuristic(string str, int size, ref int[] badChar)
        {
            int i;

            for (i = 0; i < 256; i++)
                badChar[i] = -1;

            for (i = 0; i < size; i++)
                badChar[(int)str[i]] = i;
        }

        public static int[] KnuthSearch(string str, string pat)
        {
            List<int> retVal = new List<int>();
            int M = pat.Length;
            int N = str.Length;
            int i = 0;
            int j = 0;
            int[] lps = new int[M];

            ComputeLPSArray(pat, M, lps);

            while (i < N)
            {
                if (pat[j] == str[i])
                {
                    j++;
                    i++;
                }

                if (j == M)
                {
                    retVal.Add(i - j);
                    j = lps[j - 1];
                }

                else if (i < N && pat[j] != str[i])
                {
                    if (j != 0)
                        j = lps[j - 1];
                    else
                        i = i + 1;
                }
            }

            return retVal.ToArray();
        }

        private static void ComputeLPSArray(string pat, int m, int[] lps)
        {
            int len = 0;
            int i = 1;

            lps[0] = 0;

            while (i < m)
            {
                if (pat[i] == pat[len])
                {
                    len++;
                    lps[i] = len;
                    i++;
                }
                else
                {
                    if (len != 0)
                    {
                        len = lps[len - 1];
                    }
                    else
                    {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }

    }
}
