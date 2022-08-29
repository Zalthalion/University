using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MD_1
{
    [Serializable()] //Atzīmē klasi kā serializējamu - Lekciju materiāli: 4. lekcija - sintakse
    public enum TitleType
    {
        business,
        psychology,
        mod_cook,
        trad_cook,
        popular_comp,
        UNDECICED
    }
}
