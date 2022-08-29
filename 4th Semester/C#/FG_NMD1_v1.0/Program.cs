using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

//Juris Freidenfelds (jf18017)
//Programma izveido 17 443 Dažādus vārdus

namespace FG_NMD1_v1._0
{
    class Program
    {
        //HashSet kolekcija, kurā uzglabāsies izveidotie vārdi
        //Liels atklājums, sākumā liku List<T>. Bet palasot kā pārbaudīt vai elements jau eksistē sarakstā
        //Atklāju, ka HashSet<T> to izdara O(1), kamēr List O(n)
        //Leciens no 1.40 min līdz drukāšanas sākšanai uz 2 sekundēm
        static public HashSet<String> AllWords = new HashSet<String>();

        //Vārdi, kuri jau ir bijuši izveidoti (Optimizē rekursiju)
        static public HashSet<String> almostreadywords = new HashSet<String>();
        

        static void Main(string[] args)
        {
            //Funkcijai tiek padots pirmais simbols (kā definēts gramatikā)
            CreateWords("E");

            //Izdrukā visus izveidotos vārdus
            foreach(string a in AllWords)
            {
                Console.WriteLine(a);
            }

            //Izdrukā izveidoto vārdu skaitu
            Console.WriteLine("Kopā izveidoti " + AllWords.Count.ToString() + " vārdi");

            AllWords.Clear();
            almostreadywords.Clear();
        }


        /// Funkcija, kura ar padoto vārdu, izsauc visus iespējamos izvedumus
        static void CreateWords(string E)
        {
            //Pārbauda, vai vārds jau nav iepriekš bijis izveidots (optimizācija)
            if (!almostreadywords.Contains(E))
            {
                //Pievieno vārdu kolekcijai (Lai nebūtu jāizsauc rekursija uz jau apstrādātu gadījumu)
                almostreadywords.Add(E); 

                AddItteration(1, E);    //Izsauc izvedumu E => E+E
                AddItteration(2, E);    //Izsauc izvedumu E => E-E
                AddItteration(3, E);    //Izsauc izvedumu E => (E)
                AddItteration(4, E);    //Izsauc izvedumu E => I
            }
            else
                return;
        }

        /// Funkcija, kura ar padoto vārdu, izsauc visus iespējamos izvedumus
        static void insertX(string E)
        {

            //Ja vārds nesatur I, tātad tas ir gatavs
                if (!E.Contains("I"))
                {
                    // Un var pārbaudīt, vai tāds jau ir bijis izveidots iepriekš
                    if (!AllWords.Contains(E)) AllWords.Add(E);
                    
                }

            insX(1, E); //Izsauc izvedumu I => x
            insX(2, E); //Izsauc izvedumu I => aI
            insX(3, E); //Izsauc izvedumu I => bI
        }

        static void insX(int i, string E)
        {

            //Switch, kurā katrs case ir attiecīgs izveduma likums
            switch (i)
            {
                //I => x
                case 1:
                    //Palīgskaitītājs, kurš norādīs, kuru no visiem I ir jāaizvieto
                    int ICounter = 0;

                    //Pārstaigā visu padoto vārdu
                    for (int a = 0; a < E.Length; a++)
                    {
                        //Ja satapts 'I', tad to aizvieto ar izveduma likumu
                        if (E[a] == 'I')
                        {
                            ICounter++;

                            //Nokopēta funkcija no StackOwerflow, kura aizveto konkrētu simbolu ar citu string
                            var regex = new Regex(Regex.Escape("I"));
                            //Aizvieto Icounter (kārtas skaitu) I ar "x"
                            var newE = regex.Replace(E, "x", ICounter);

                            //Ja jaunā vārda garums ir lielāks par 10, tad tālāk vārdu neveidojam
                            if (newE.Length > 10) return;

                            //Ja nav garāks, tad varam vēlreiz izsaukt pārveidojuma funkciju
                            insertX(newE);
                        }
                    }
                    break;

                //I => aI
                case 2:
                    //Palīgskaitītājs, kurš norādīs, kuru no visiem I ir jāaizvieto
                    int ICounter1 = 0;

                    //Pārstaigā visu padoto vārdu
                    for (int a = 0; a < E.Length; a++)
                    {
                        if (E[a] == 'I')
                        {
                            ICounter1++;

                            //Nokopēta funkcija no StackOwerflow, kura aizveto konkrētu simbolu ar citu string
                            var regex = new Regex(Regex.Escape("I"));
                            //Aizvieto Icounter (kārtas skaitu) I ar "aI"
                            var newE = regex.Replace(E, "aI", ICounter1);

                            //Ja jaunā vārda garums ir lielāks par 10, tad tālāk vārdu neveidojam
                            if (newE.Length > 10) return;

                            //Ja nav garāks, tad varam vēlreiz izsaukt pārveidojuma funkciju
                            insertX(newE);
                        }
                    }
                    break;
                
                //I => bI
                case 3:
                    //Palīgskaitītājs, kurš norādīs, kuru no visiem I ir jāaizvieto
                    int ICounter2 = 0;

                    //Pārstaigā visu padoto vārdu
                    for (int a = 0; a < E.Length; a++)
                    {
                        //Ja satapts 'I', tad to aizvieto ar izveduma likumu
                        if (E[a] == 'I')
                        {
                            ICounter2++;

                            //Nokopēta funkcija no StackOwerflow, kura aizveto konkrētu simbolu ar citu string
                            var regex = new Regex(Regex.Escape("I"));

                            //Aizvieto Icounter (kārtas skaitu) I ar "bI"
                            var newE = regex.Replace(E, "bI", ICounter2);

                            //Ja jaunā vārda garums ir lielāks par 10, tad tālāk vārdu neveidojam
                            if (newE.Length > 10) return;

                            //Ja nav garāks, tad varam vēlreiz izsaukt pārveidojuma funkciju
                            insertX(newE);
                        }
                    }
                    break;
            }
        }
        static void AddItteration(int i, string E)
        {

            //Switch, kurā katrs case ir attiecīgs izveduma likums
            switch (i)
            {
                //E => E+E
                case 1:

                    //Palīgskaitītājs, kurš norādīs, kuru no visiem E ir jāaizvieto
                    int ECounter1 = 0;

                    //Pārstaigā visu padoto vārdu
                    for (int a = 0; a < E.Length; a++)
                    {
                        //Ja satapts 'E', tad to aizvieto ar izveduma likumu
                        if (E[a] == 'E')
                        {
                            ECounter1++;

                            //Nokopēta funkcija no StackOwerflow, kura aizveto konkrētu simbolu ar citu string
                            var regex = new Regex(Regex.Escape("E"));
                            //Aizvieto Ecounter (kārtas skaitu) E ar "E+E"
                            var newE = regex.Replace(E, "E+E", ECounter1);

                            //Ja jaunā vārda garums ir lielāks par 10, tad tālāk vārdu neveidojam
                            if (newE.Length > 10) return;

                            //Ja nav garāks, tad varam vēlreiz izsaukt pārveidojuma funkciju
                            CreateWords(newE);
                        }
                    }
                    break;
                //E => E-E
                case 2:
                    //Palīgskaitītājs, kurš norādīs, kuru no visiem E ir jāaizvieto
                    int ECounter = 0;

                    //Pārstaigā visu padoto vārdu
                    for (int a = 0; a<E.Length; a++)
                    {
                        //Ja satapts 'E', tad to aizvieto ar izveduma likumu
                        if (E[a] == 'E')
                        {
                            ECounter++;

                            //Nokopēta funkcija no StackOwerflow, kura aizveto konkrētu simbolu ar citu string
                            var regex = new Regex(Regex.Escape("E"));
                            //Aizvieto Ecounter (kārtas skaitu) E ar "E-E"
                            var newE = regex.Replace(E, "E-E", ECounter);

                            //Ja jaunā vārda garums ir lielāks par 10, tad tālāk vārdu neveidojam
                            if (newE.Length > 10) return;

                            //Ja nav garāks, tad varam vēlreiz izsaukt pārveidojuma funkciju
                            CreateWords(newE);
                            
                        }
                    }
                    break;
                //E => (E)
                case 3:

                    //Palīgskaitītājs, kurš norādīs, kuru no visiem E ir jāaizvieto
                    int ECounter2 = 0;

                    //Pārstaigā visu padoto vārdu
                    for (int a = 0; a < E.Length; a++)
                    {
                        //Ja satapts 'E', tad to aizvieto ar izveduma likumu
                        if (E[a] == 'E')
                        {
                            ECounter2++;

                            //Nokopēta funkcija no StackOwerflow, kura aizveto konkrētu simbolu ar citu string
                            var regex = new Regex(Regex.Escape("E"));
                            //Aizvieto Ecounter (kārtas skaitu) E ar "(E)"
                            var newE = regex.Replace(E, "(E)", ECounter2);

                            //Ja jaunā vārda garums ir lielāks par 10, tad tālāk vārdu neveidojam
                            if (newE.Length > 10) return;

                            //Ja nav garāks, tad varam vēlreiz izsaukt pārveidojuma funkciju
                            CreateWords(newE);

                        }
                    }
                    break;

                //E => I
                case 4:

                    //Palīgskaitītājs, kurš norādīs, kuru no visiem E ir jāaizvieto
                    int ECounter3 = 0;

                    //Pārstaigā visu padoto vārdu
                    for (int a = 0; a < E.Length; a++)
                    {
                        //Ja satapts 'E', tad to aizvieto ar izveduma likumu
                        if (E[a] == 'E')
                        {
                            ECounter3++;

                            //Nokopēta funkcija no StackOwerflow, kura aizveto konkrētu simbolu ar citu string
                            var regex = new Regex(Regex.Escape("E"));
                            //Aizvieto Ecounter (kārtas skaitu) E ar "I"
                            var newE = regex.Replace(E, "I", ECounter3);

                            //Ja jaunā vārda garums ir lielāks par 10, tad tālāk vārdu neveidojam
                            if (newE.Length > 10) return;

                            //Ja vārds vairs nesatur E, tad tiek izsaukta fukcija, kura aizvieto visus vārdā sastaptos I
                            if (!newE.Contains("E")) insertX(newE);

                            //Ja nav garāks par 10 simboliem un satur E, tad izsauc vēlreiz E aizvietošanu
                            CreateWords(newE);
                            
                        }
                    }
                    break;   
            }
        }
    }
}
