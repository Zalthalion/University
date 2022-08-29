//Darba autors:  Juris Freidenfelds (jf18017)
//Secinājumi pildot šo uzdevumu:
// 1)Es visticamāk nepareizi kontroldarbā izpildīju 3. uzdevumu
// 2)Pirmo reizi rakstot kodu, man nācās veidot monologu ar gumijas pīli un pārsteidzošā kārtā tas atrisināja problēmu
// 3)Šis noteikti ir ļoti piņķerīgs veids kā izpildīt šo uzdevumu, nemaz nerunājot par ātrdarbību, noteikti ir daudz, ko optimizēt, bet tas uzdevums citai dienai
//Rezultāti:
//abbabbbbaaaaaaaaaaabbbbabb pieder ģenerātajai valodai
//abbacaaaaacaaaabbbbbbbbbbbbbbbb pieder ģenerētajai valodai
//abbabbabbabbbbbcbcbbacabbabbabb pieder ģenerētajai valodai
//nedaudz šaubos par pareizību, jo visi 3 vārdi pieder valodai

using System;
using System.Collections.Generic;
using System.Linq;

namespace FG_NMD2.v._0._2
{
    class Program
    {
        //Objekts "Rule", kas kalpos kā izveduma likums
        struct Rule
        {
            public string left;     //Kreisajā pusē mums ir neterminālis
            public string right;    //Labajā pusē mums ir terminālis
            
            //Konstruktors, kurš pieprasa izveduma likuma abas puses
            public Rule(string Left, string Right)
            {
                left = Left;
                right = Right;
            }
        }

        //Objekts "Cell", kurš kalpo kā CYK algoritma, trijstūra tabulas šūna,
        //kura sastāv no apakšvirknes (substring) un List kolekcijas, kurā ir visi iespējamie netermināļi no kuriem var iegūt šo apakšvirkni
        struct Cell
        {
            public List<string> Terminals;
            public string SubString;

            //Konstruktors, kurš prasa tikai apakšvirkni
            public Cell(string subString)
            {
                SubString = subString;
                Terminals = new List<string>();
            }
        }

        //Funkcija, kura izveido visus iespējamos substring, no padotā vārda, garumā len
        //Atgriež sarakstu ar izveidotajiem substring
        static List<Cell> subString(string str, int len, List<Cell> Row)
        {
            //For cikls, kas apstaigā visu vārdu
            for (int i = 0; i <= str.Length - len; i++)
            {
                string temp = ""; 

                //for cikls, kurš pa vienam simbolam izveido substring garumā len
                for (int j = i; j < i + len; j++)
                    temp += str[j];

                Row.Add(new Cell(temp));    //izveidoto vārdu pievieno kolekcijai
            }
            return Row;
        }

        //Funkcija, kura atgriež VISUS iespējamos substrings
        //Nokopēts no StackOwerflow un veiktas izmaiņas, lai atgriež kolekciju
        static List<string> AllSubstrings(string str, int n, List<string> Row)
        {

            // Pick starting point 
            for (int len = 1; len <= n; len++)
            {
                // Pick ending point 
                for (int i = 0; i <= n - len; i++)
                {
                    int j = i + len - 1;
                    string temp = "";

                    for (int k = i; k <= j;k++)
                        temp += str[k];

                    Row.Add(temp);
                }
            }
            return Row;  
        }


        static void Main(string[] args)
        {
            List<Rule> Grammar = new List<Rule>();      //Kolekcija, kurā tiks uzglabāti visi gramatikas izveduma likumi

            //Pievieno visus gramatikas likumus
            Grammar.Add(new Rule("S", "MY"));
            Grammar.Add(new Rule("S", "XY"));
            Grammar.Add(new Rule("S", "TT"));
            Grammar.Add(new Rule("S", "SY"));
            Grammar.Add(new Rule("S", "JY"));
            Grammar.Add(new Rule("S", "RQ"));
            Grammar.Add(new Rule("S", "OU"));
            Grammar.Add(new Rule("S", "HU"));
            Grammar.Add(new Rule("S", "HQ"));
            Grammar.Add(new Rule("S", "FE"));
            Grammar.Add(new Rule("S", "WU"));
            Grammar.Add(new Rule("A", "EX"));
            Grammar.Add(new Rule("A", "WW"));
            Grammar.Add(new Rule("A", "YS"));
            Grammar.Add(new Rule("A", "LT"));
            Grammar.Add(new Rule("E", "EX"));
            Grammar.Add(new Rule("E", "WW"));
            Grammar.Add(new Rule("E", "YS"));
            Grammar.Add(new Rule("F", "JU"));
            Grammar.Add(new Rule("F", "RQ"));
            Grammar.Add(new Rule("F", "OU"));
            Grammar.Add(new Rule("F", "HU"));
            Grammar.Add(new Rule("F", "HQ"));
            Grammar.Add(new Rule("F", "FE"));
            Grammar.Add(new Rule("F", "WU"));
            Grammar.Add(new Rule("X", "WW"));
            Grammar.Add(new Rule("Y", "TT"));
            Grammar.Add(new Rule("O", "AW"));
            Grammar.Add(new Rule("R", "AA"));
            Grammar.Add(new Rule("H", "WA"));
            Grammar.Add(new Rule("L", "TU"));
            Grammar.Add(new Rule("Q", "AU"));
            Grammar.Add(new Rule("P", "OR"));
            Grammar.Add(new Rule("J", "WE"));
            Grammar.Add(new Rule("M", "JW"));
            Grammar.Add(new Rule("W", "a"));
            Grammar.Add(new Rule("T", "b"));
            Grammar.Add(new Rule("U", "c"));


            List<List<Cell>> CYK = new List<List<Cell>>();      //Izveido kolekiju, kura sastāv no sarakstiem. Šeit tiks uzglabāta CYK tabula
            List<Rule> CheckedWords = new List<Rule>();         //Kolekcija, kurā tiks uzglabāti visi pārbaudītie vārdi un to netermināļi


            string word = "abbabbbbaaaaaaaaaaabbbbabb"; // pieder
            //string word = "abbacaaaaacaaaabbbbbbbbbbbbbbbb"; //Pieder
            //string word = "abbabbabbabbbbbcbcbbacabbabbabb"; //Pieder


            //Aizpilda CYK tabulu ar visiem substring
            for (int i = 1; i <= word.Length; i++)
            {
                List<Cell> row = subString(word, i, new List<Cell>());
                CYK.Add(row);
            }

            
            //Pievieno tabulas pirmajai rindai visus netermināļus (1. rindas substring ir garumā 1) 
            
            //Pārstaigā pirmas rindas visas šūnas
            for (int i = 0; i < CYK[0].Count; i++)
            {   
                //Iet cauri visiem izveduma likumiem
                foreach (Rule rule in Grammar)
                {
                    //Ja substring ir vienāds ar termināli
                    if (CYK[0][i].SubString == rule.right)
                    {
                        //Tad šīs šunas netermināļu kopai pievieno izveduma likuma netermināli
                        CYK[0][i].Terminals.Add(rule.left);

                        //Pie reizes pārbauda vai šāds likums jau nav bijis pārbaudīts
                        if (CheckedWords.Contains(rule) == false)
                        {
                            //Un ja nav, tad šo izveduma likumu pievieno pārbaudīto vārdu kopai
                            CheckedWords.Add(rule);
                        }
                    }
                }
            }

            //Dekarta reizinājuma palīg-kolekcijas
            List<string> LabaPuse = new List<string>();
            List<string> KreisaPuse = new List<string>();

            //Šeit aizpilda pārējās visas CYK tabulas rindas
            
            //Pārstaigā CYK tabulas rindas
            for (int row = 1; row < CYK.Count; row++)
            {
                //Pārstaigā konkrētas rindas visas šūnas
                for (int cell = 0; cell < CYK[row].Count; cell++)
                {
                    //Šūnai izveido visus iespējamos substring
                    List<string> Substrings = AllSubstrings(CYK[row][cell].SubString, CYK[row][cell].SubString.Length, new List<string>());

                    //Šai kolekcijai noņem pēdējo vārdu, kas ir pats šūnas substring
                    Substrings.RemoveAt(Substrings.Count - 1);

                    //Šai kolekcijai noņem duplicātus
                    Substrings = Substrings.Distinct().ToList();

                    //No šīs kolekcijas iegūtajiem substring izveido visas iespējamās kolekcijas
                    var CartesianProduct = Substrings.SelectMany(x => Substrings, (x, y) => new { x, y });

                    //Pārstaigā visas unikālās kombinācijas
                    foreach (var production in CartesianProduct.Distinct())
                    {
                        //String, kurš tiks izmantot, lai pārbaudītu, vai kombinācija veido pašreizējās šūnas substring
                        string testString = "";
                        testString += production.x;
                        testString += production.y;
                        
                        //Ja iegūtā kombinācija neveido vēlamo vārdu, tiek izlaista iterācija
                        if (testString != CYK[row][cell].SubString) continue;

                        //Pārstaigā visus iepriekš pārbaudītos vārdus
                        //Needs more info
                        foreach (Rule rule in CheckedWords)
                        {
                            //Ja kombinācijas labā puse sakrīt ar jau iepriekš pārbaudītu likumu,
                            if (production.x == rule.right)
                            {
                                //Tad dekarta reizinājuma labajai pusei pievieno šī likuma kreiso pusi
                                LabaPuse.Add(rule.left);
                            }
                            //Ja kombinācijas kreisā puse sakrīt ar jau iepriekš pārbaudītu likumu,
                            if (production.y == rule.right)
                            {
                                //Tad dekarta reizinājuma kreisajai pusei pievieno šī likuma kreiso pusi
                                KreisaPuse.Add(rule.left);
                            }   
                        }

                        //Noņem visus duplikātus, gan no reizinājuma labās, gan kreisās puses
                        LabaPuse = LabaPuse.Distinct().ToList();
                        KreisaPuse = KreisaPuse.Distinct().ToList();
                        
                        //Izveido visas iespējamās netermināļu kombinācijas
                        var CartesianTerminals = LabaPuse.SelectMany(x => KreisaPuse, (x, y) => new { x, y });

                        //Pārstiagā visas izveidotās kombinācijas
                        foreach (var BiTerminal in CartesianTerminals.ToList())
                        {
                            //Pārstiagā visus gramatikas izveduma likumus
                            foreach (Rule rule in Grammar)
                            {
                                //String, kurā ir salikti abi netermināļi kopā
                                string temp = "";
                                temp += BiTerminal.x;
                                temp += BiTerminal.y;
                                
                                //Ja gramatikā ir sastopams šāds izveduma likums
                                if (rule.right == temp)
                                {
                                    bool exists = false;

                                    //Pārstaigā visus iepriekš pārbaudītos vārdus
                                    foreach (Rule r in CheckedWords)
                                    {
                                        //Ja šāds likums jau ir sastaps, tad to nepievieno pārbaudīto vārdu kolekcijai
                                        if (rule.left == r.left && CYK[row][cell].SubString == r.right)
                                        {
                                            exists = true;
                                            break;
                                        }
                                    }

                                    //Ja nav sastapts, tad pievieno pārbaudīto vārdu kolekcijai
                                    if (exists == false)
                                    {
                                        CheckedWords.Add(new Rule(rule.left, CYK[row][cell].SubString));
                                    }
                                }
                            }
                        }

                        //"Notīra" gan labo, gan kreiso pusi no dekarta reizinājuma
                        KreisaPuse.Clear();
                        LabaPuse.Clear();
                    }

                    //Pārstiagā visus pārbaudītos vārdus
                    foreach(var adding in CheckedWords)
                    {
                        //Ja kāds no pārbaudītajiem vārdiem sakrīt ar pašreizējās šūnas substring
                        if(adding.right == CYK[row][cell].SubString)
                        {
                            //Tad šai šūnai tiek pievienots attiecīgā vārda neterminālis
                            CYK[row][cell].Terminals.Add(adding.left);
                        }
                    }
                }
            }

            Console.WriteLine("Ja gala rezultātā ir sastopams sākums simbols 'S', tad šis vārds pieder valodai :)");
            Console.WriteLine("Ja nav sastopams tad nepieder :(");
            Console.Write("Rezultāts: ");
            foreach(var finish in CYK[CYK.Count-1][0].Terminals)
            {
                Console.Write(finish + " ");
            }
            

        }

    }
}
