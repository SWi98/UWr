using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using DataLibrary;

namespace MvcApplication3.Models
{
    public class UserEditModel
    {
        [Required( ErrorMessage="Nazwisko jest wymagane" )]
        public string Surname { get; set; }

        [Required( ErrorMessage = "Imię jest wymagane" )]
        public string Name { get; set; }

        [Required( ErrorMessage = "Miejscowośc jest wymagana" )]
        [Range(0, int.MaxValue, ErrorMessage="*")]
        public string IDMiejscowosc { get; set; }

        public IEnumerable<SelectListItem> Miejscowosci { get; set; }
    }
}