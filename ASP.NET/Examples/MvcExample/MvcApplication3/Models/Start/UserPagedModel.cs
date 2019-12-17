using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using DataLibrary;

namespace MvcApplication3.Models
{
    public class UserPagedModel
    {
        public int TotalPages   { get; set; }
        public int TotalItems   { get; set; }
        public int? CurrentPage { get; set; }

        public string OrderBy { get; set; }

        public IEnumerable<User> Items { get; set; }
    }
}