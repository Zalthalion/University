using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Automātu_teorija_NMD2
{
    /*  */
    class Program
    {
        //Publiska klase "Parejas", kurā tiek saglabāts pārējas sākums, pārejas simbols un beigas
        public class Parejas
        {
            private string sakums;
            private string pareja;
            private string beigas;

            public string Sakums { get { return sakums; } set { sakums = value; } }
            public string Pareja { get { return pareja; } set { pareja = value; } }
            public string Beigas { get { return beigas; } set { beigas = value; } }
            public override string ToString()
            {
                return sakums + " " + pareja + " " + beigas;
            }
        }
        static void Main(string[] args)
        {
            List<string> stavokli = new List<string>();                 //List kolekcija, kurā tiks uzglabāti automāta stāvokļi
            List<string> alfabets = new List<string>();                 //List kolekcija, kurā tiks uzglabāts valodas alfabēts
            List<string> akceptejosie = new List<string>();             //List kolekcija, kurā tiks uzglabāti visi akceptējošie stāvokļi
            List<Parejas> parejas = new List<Parejas>();                //List kolekcija, kurā tiks uzglabātas visas definētās pārejas
            List<string> tagadejie = new List<string>();                //List kolekcija, kurā tiks uzglabāti visi tagadējie stāvokļi (visi - jo ir iespējams "pārlekt" ar epsilonu)
            List<string> tagadejiePecParejas = new List<string>();      //List kolekcija, kurā tiks uzglabāti īslaicīgi visi iespējamie stāvokļi pēc simbola nolasīšanas
            string sakums;          //String, kura vērtība ir automāta sākuma stāvoklis
            bool pieder = false;    //Bool, kurš parāda, vai vārds pieder vai nepieder valodai                                    
            string Stavokli;        //String, kurā būs visi stāvokļi, kuri ir nolasīti no faila
            string Alfabets;        //String, kurā būs visi valodas alfabēta simboli
            string Akceptejosie;    //String, kurā būs visi iespējamie akceptējošie stāvokļi
            string line;            //String, kurā būs viena definētā pāreja
            string vards;           //Ievadītais vārds
            string failaNos;        //Ievadītais faila nosaukums
            string ok1;
            string ok;
            //Ērtāk notestēt

            do
            {
                while (true)
                {
                    Console.WriteLine("Ievadi faila nosaukumu: ");
                    failaNos = Console.ReadLine();
                    Console.WriteLine();

                    //Nolasa visu informāciju no faila
                    string cepums = @"..\..\" + failaNos + ".txt";

                    if (File.Exists(cepums)) { break; }
                    else Console.WriteLine("Faila nosaukums neeksistē!");
                }
                StreamReader file = new StreamReader(@"..\..\" + failaNos + ".txt");



                Stavokli = file.ReadLine();     //Nolasa stāvokļu rindiņu
                Alfabets = file.ReadLine();     //Nolasa alfabēta rindiņu
                sakums = file.ReadLine();       //Nolasa sākuma stāvokļa rindiņu
                Akceptejosie = file.ReadLine(); //Nolasa akceptējošo stāvokļu rindiņu

                var punctuation = Stavokli.Where(Char.IsPunctuation).Distinct().ToArray();
                var stav = Stavokli.Split().Select(x => x.Trim(punctuation)).ToArray();         //sadala Stāvokļu rindiņu pa vārdiem un ievieto tos masīvā
                var punctuation1 = Alfabets.Where(Char.IsPunctuation).Distinct().ToArray();
                var alfa = Alfabets.Split().Select(x => x.Trim(punctuation1)).ToArray();        //Sadala Alfabēta rindiņu pa vārdiem un ievieto tos masīvā
                var punctuation2 = Akceptejosie.Where(Char.IsPunctuation).Distinct().ToArray();
                var akc = Akceptejosie.Split().Select(x => x.Trim(punctuation2)).ToArray();     //Sadala akceptējošo stāvokļu rindiņu pa vārdiem un ievieto tos masīvā

                //Pārējās rindiņas ir pārejas no stāvokļa uz stāvokli, tādēļ fails tiek lasīts līdz galam
                while ((line = file.ReadLine()) != null)
                {
                    var punctuationN = line.Where(Char.IsPunctuation).Distinct().ToArray();
                    var pareja = line.Split().Select(x => x.Trim(punctuationN)).ToArray();      //Sadala vienu pārejas rindiņu 3 daļās un ievada tās masīvā

                    Parejas jauns = new Parejas();      //Izveido jaunu pāreju
                    jauns.Sakums = pareja[0].ToString();           //Pārejas sākums ir rindiņas pirmā daļa
                    if (pareja.Length == 3)             //Ja iepriekš izveidotais masīvs ir ar garumu 3, tas nozīmē, ka tā nav epsilona pāreja
                    {
                        jauns.Pareja = pareja[1].ToString();       // simbols ar kuru veiks pāreju
                    }
                    else { jauns.Pareja = "epsilons"; jauns.Beigas = pareja[1].ToString(); parejas.Add(jauns); continue; }; //Ja garums nav 3, tad tā ir epsilona pāreja, tādēļ pie pārejas tiek ierakstīts "epsilons"
                    jauns.Beigas = pareja[2].ToString();           //Pievieno beigu stāvokli pārejai
                    parejas.Add(jauns);                 //Pievieno List jaunu pāreju
                }
                file.Close(); //Aizver failu

                foreach (string a in stav) stavokli.Add(a);     //Pievieno visus stāvokļus List
                foreach (string b in alfa) alfabets.Add(b);     //Pievieno visus alfabēta simbolus List
                foreach (string c in akc) akceptejosie.Add(c);  //Pievieno visus akceptējošos stāvokļus
                tagadejie.Add(sakums);                          //Pievieno sākuma stāvokli tagadējo stāvokļu List
                epsilonaParejuMekletajs(sakums, tagadejie, parejas); //Atrod visas iepriekš definētās epsilona pārejas un ievada tās "tagadējie" sarakstā
                print(stavokli, alfabets, sakums, akceptejosie);
                do
                {
                    pieder = false;
                    tagadejie.Add(sakums);                          
                    epsilonaParejuMekletajs(sakums, tagadejie, parejas);
                    Console.WriteLine("Ievadi vārdu, kuru vēlies pārbaudīt vai tas pieder valodai: ");
                    vards = Console.ReadLine();

                    //Pārstaigā ievadīto vārdu pa vienam simbolam
                    foreach (char k in vards)
                    {
                        //Pārbauda visus iespējamos stāvokļus, kuros var atrasties automāts
                        foreach (string s in tagadejie)
                        {
                            //Pārbauda visas pārejas no katra sākuma stāvokļa un gala stāvokļus ievada sarakstā "tagadejiePecParejas"
                            foreach (Parejas a in parejas)
                            {
                                if (k.ToString() == a.Pareja && a.Sakums == s)
                                {
                                    tagadejiePecParejas.Add(a.Beigas);
                                    epsilonaParejuMekletajs(a.Beigas, tagadejiePecParejas, parejas);
                                }
                            }
                        }
                        tagadejie = tagadejiePecParejas.Distinct().ToList(); //Aizpilda jauno tagadējo stāvokļu sarakstu, bez dublikātiem
                        tagadejiePecParejas.Clear();
                    }

                    tagadejie = tagadejie.Distinct().ToList(); //Aizpilda tagadējo sarakstu bez dublikātiem
                    
                    //Ja nav neviena gala stāvokļa, tas nozīmē, ka ir bijis sasniegts stāvoklis pēc kura nav bijis iespējams pārvietoties tālāk
                    if (tagadejie.Count == 0) { Console.WriteLine("Vārds nepieder valodai"); }
                    //Ja ir kāds gala stāvoklis, tad salīdzina to ar visiem definētajiem akceptējošajiem stāvokļiem
                    else
                    {
                        foreach (string a in tagadejie)
                        {
                            foreach (string b in akceptejosie)
                            {
                                if (a == b) pieder = true;
                            }
                        }

                        //Paziņojusm vai vārds pieder vai nepieder valodai
                        if (pieder)
                        {
                            Console.WriteLine("Ievadītais vārds pieder valodai");
                        }
                        else
                        {
                            Console.WriteLine("Vārds nepieder valodai");
                        }
                    }
                    Console.WriteLine();
                    tagadejie.Clear();
                    //Piedāvā ievadīt citu vārdu
                    Console.WriteLine("Vai vēlies pārbaudīt citu vārdu? (jā ==1 un nē == 0)");
                    ok1 = Console.ReadLine();

                } while (ok1 == "1");
                //Piedāvā ievadīt datus no cita faila
                Console.WriteLine("Vai vēlaties pārbaudīt citu failu? (jā == 1 un nē == 0) ");
                ok = Console.ReadLine();
                stavokli.Clear();
                alfabets.Clear();
                akceptejosie.Clear();
            } while (ok == "1");
            Console.ReadLine();
            
        }
        

        //rekursīva funkcija, kura atrod visas epsilona pārejas, no konkrēta stāvokļa
        public static void epsilonaParejuMekletajs(string tgd,  List<string> tagadejie, List<Parejas> parejas)
        {
            foreach (Parejas p in parejas)
            {
                if (tgd == p.Sakums && p.Pareja == "epsilons")
                {
                    foreach (string a in tagadejie) if (p.Beigas == a) return;
                    tagadejie.Add(p.Beigas);
                    epsilonaParejuMekletajs(p.Beigas,  tagadejie, parejas);
                }
            }   
        }        
        //Funkcija, kura izdrukā visus stāvokļus, alfabētu, sākuma stāvokli un visus akceptējošos stāvokļus
        public static void print(List<string> _stavokli, List<string> _alfabets, string _sakums, List<string> _akceptejosie)
        {
            Console.WriteLine("Definētie stāvokļi: ");
            foreach (string a in _stavokli) Console.Write(a + "; ");
            Console.WriteLine();
            Console.WriteLine("Definētias alfabēts: ");
            foreach (string b in _alfabets) Console.Write(b + "; ");
            Console.WriteLine();
            Console.WriteLine("Sākuma stāvoklis: ");
            Console.Write(_sakums);
            Console.WriteLine();
            Console.WriteLine("Definētie akceptējošie stāvokļi: ");
            foreach (string c in _akceptejosie) Console.Write(c + "; ");
            Console.WriteLine();

        }
    }
}
