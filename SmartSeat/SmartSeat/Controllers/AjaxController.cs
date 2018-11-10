using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using static SmartSeat.Models.DweetService;

namespace SmartSeat.Controllers
{
    public class AjaxController : Controller
    {
        // GET: Ajax
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult FirstAjax()
        {
            return Json("chamara", JsonRequestBehavior.AllowGet);
        }

        [HttpPost]
        public JsonResult checkDweetValue()
        {
            return Json("ok");
        }
    }
}