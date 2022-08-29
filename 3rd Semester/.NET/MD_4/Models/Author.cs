using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MD4._1.Models
{
    public partial class Author
    {
        public Author()
        {
            Titleauthor = new HashSet<Titleauthor>();
        }
        [Required]
        [StringLength(12)]
        public string Phone { get; set; }
        [StringLength(40)]
        public string Address { get; set; }
        [StringLength(20)]
        public string City { get; set; }
        [StringLength(2)]
        public string State { get; set; }
        [StringLength(5)]
        public string Zip { get; set; }
        public bool Contract { get; set; }
        [Required]
        public int Id { get; set; }
        [StringLength(20)]
        public string Fname { get; set; }
        [StringLength(40)]
        public string Lname { get; set; }

        public virtual ICollection<Titleauthor> Titleauthor { get; set; }
    }
}
