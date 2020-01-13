using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using MvcApplication3.Custom;
using MVCControlsToolkit.DataAnnotations;

namespace MvcApplication3.Models.Account
{
    public class LogOnModel
    {
        [OurCustomValidation("foo")]
        [Required]
        public string UserName { get; set; }
        [Required]
        public string Password { get; set; }

        [DateRange( SMaximum = "2015-1-1", SMinimum = "2008-1-1" )]
        public DateTime TheDate { get; set; }
    }
}