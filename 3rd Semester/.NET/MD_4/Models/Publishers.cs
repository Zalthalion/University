using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MD4._1.Models
{
    public partial class Publishers
    {
        public Publishers()
        {
            Titles = new HashSet<Titles>();
        }

        [StringLength(40)]
        public string PubName { get; set; }
        [StringLength(20)]
        public string City { get; set; }
        [StringLength(30)]
        public string Country { get; set; }
        public int Id { get; set; }

        public virtual ICollection<Titles> Titles { get; set; }
    }
}
