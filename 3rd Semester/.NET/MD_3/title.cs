//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace MD_3
{
    using System;
    using System.Collections.Generic;
    
    public partial class title
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public title()
        {
            this.titleauthors = new HashSet<titleauthor>();
        }
    
        public string title1 { get; set; }
        public string titleType { get; set; }
        public Nullable<decimal> price { get; set; }
        public System.DateTime pubdate { get; set; }
        public int ID { get; set; }
        public Nullable<int> pubID { get; set; }
    
        public virtual publisher publisher { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<titleauthor> titleauthors { get; set; }
    }
}
