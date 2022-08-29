using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace MD4._1.Models
{
    public partial class Titles
    {
        public Titles()
        {
            Titleauthor = new HashSet<Titleauthor>();
        }
        [StringLength(80)]
        [Required]
        public string Title { get; set; }
        [StringLength(12)]
        [Required]
        public string TitleType { get; set; }
        
        public decimal? Price { get; set; }
        [DataType(DataType.DateTime)]
        [Required]
        public DateTime Pubdate { get; set; }
        public int Id { get; set; }
        [ForeignKey("Id")]
        public int? PubId { get; set; }

        public virtual Publishers Pub { get; set; }
        public virtual ICollection<Titleauthor> Titleauthor { get; set; }
    }
}
