using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MD_2
{
    [Serializable()] //Atzīmē klasi kā serializējamu - Lekciju materiāli: 4. lekcija - sintakse
    public class Publisher
    {
        
        private string Name;
        public Publisher() { } //Default konstruktors
        public Publisher(string _name) { Name = _name; }
        public string name { set { Name = value; } get { return Name; } }
        public override string ToString()
        {
            return name.ToString();
        }
    }
}

/*  5. Izveidot  klasi "Publisher" ar
*       •	Īpašību "name" ar tipu teksts;
*/
