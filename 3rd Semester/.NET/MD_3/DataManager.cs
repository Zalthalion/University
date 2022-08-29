using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MD_3
{
    class DataManager
    {
        //Šeit ir database connection string, lai man nav katru reizi jāveido string mainīgais
        //Un last ID priekš jauna autora izveides, jo tam automātiski neiet ID uz priekšu
        static private int LastID;
        static private string ConString = ConfigurationManager.ConnectionStrings["MD_3.Properties.Settings.Setting"].ConnectionString;
        static public int lastID { get { return LastID; } set { LastID = value; } }
        static public string conString { get { return ConString; } }
    }
}
