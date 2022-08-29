using System;
using System.Collections.Generic;

namespace MD4._1.Models
{
    public partial class Titleauthor
    {
        public byte? AuOrd { get; set; }
        public int? TitleId { get; set; }
        public int Id { get; set; }
        public int? PersonId { get; set; }

        public virtual Author Person { get; set; }
        public virtual Titles Title { get; set; }
    }
}
