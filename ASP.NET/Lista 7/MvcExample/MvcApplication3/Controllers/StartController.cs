using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.Mvc;
using DataLibrary;
using MvcApplication3.Models;
using System.Linq.Dynamic;
using MvcApplication3.Custom;

namespace MvcApplication3.Controllers
{
    [Authorize]
    public class StartController : Controller
    {
        const int PAGESIZE = 10;
        //
        // GET: /Start/

        public ActionResult Index( string OrderBy, int CurrentPage = 1 )
        {
            UserPagedModel model = new UserPagedModel();

            model.Items          = DataLayer.Current.Users.OrderBy( OrderBy ).Skip( PAGESIZE * (CurrentPage-1) ).Take( PAGESIZE );
            model.CurrentPage    = CurrentPage;
            model.TotalItems     = DataLayer.Current.Users.Count();
            model.TotalPages     = (int)Math.Ceiling( (decimal)DataLayer.Current.Users.Count() / PAGESIZE );

            model.OrderBy = OrderBy;

            return this.View( model );
        }

        #region DownloadPDF

        public ActionResult DownloadPDF( int? id )
        {
            if ( id == null ) return Content( "brak parametrów" );

            // id ?
            var content = Encoding.UTF8.GetBytes( "użytkownik " + id.ToString() );
            return this.File( content, "text/plain", string.Format( "{0}.txt", id ) );
        }

        #endregion

        #region Edit

        /// <summary>
        /// GET
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        [HttpGet]
        public ActionResult Edit( int? id )
        {
            if ( id != null )
            {
                var user = DataLayer.Current.Users.FirstOrDefault( u => u.ID == id );
                if ( user != null )
                {
                    UserEditModel model = new UserEditModel();

                    model.Name          = user.Name;
                    model.Surname       = user.Surname;
                    model.IDMiejscowosc = user.ID_MIEJSCOWOSC.ToString();

                    model.Miejscowosci = DataLayer.Current.Miejscowoscs.Select(
                        m => new SelectListItem()
                        {
                            Text = m.Nazwa,
                            Value = m.ID.ToString(),
                            Selected = m.ID == user.ID_MIEJSCOWOSC
                        }
                        );

                    return View( model );
                }
            }

            return Content( "brak parametrów" );
        }

        [HttpPost]
        public ActionResult Edit( int? id, UserEditModel userModel )
        {
            if ( this.ModelState.IsValid )
            {
                if ( id != null )
                {
                    var user = DataLayer.Current.Users.FirstOrDefault( u => u.ID == id );
                    if ( user != null )
                    {
                        user.Surname = userModel.Surname;
                        user.Name = userModel.Name;
                        user.ID_MIEJSCOWOSC = int.Parse( userModel.IDMiejscowosc );

                        DataLayer.Current.SubmitChanges();

                        return RedirectToAction( "Index" );
                    }
                }
            }

            return View( userModel );
        }

        #endregion
    }
}
