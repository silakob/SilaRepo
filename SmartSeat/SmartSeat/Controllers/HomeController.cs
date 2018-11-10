using System;
using System.Web.Mvc;
using SmartSeat.Models;
using System.Threading;

namespace SmartSeat.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home
        public ActionResult Index()
        {
            //var waitHandle = new AutoResetEvent(false);
            //DweetService.JsonDweet dweetObj = new DweetService.JsonDweet();
            //ThreadPool.RegisterWaitForSingleObject(
            //waitHandle,
            //// Method to execute
            //(state, timeout) =>
            //{
            //dweetObj = DweetService.checkDweetValue();
            //// dweetObj.with[0].content.value;

            //},
            //// optional state object to pass to the method
            //null,
            //// Execute the method after 5 seconds
            //TimeSpan.FromSeconds(1),
            //// Set this to false to execute it repeatedly every 5 seconds
            //false
            //);


            DweetService.JsonDweet dweetObj = new DweetService.JsonDweet();
            dweetObj = DweetService.checkDweetValue();


            return View(dweetObj.with == null?new DweetService.JsonDweet():dweetObj);
        }


        [HttpPost]
        public ActionResult CallAjax()
        {
            DweetService.JsonDweet dweetObj = new DweetService.JsonDweet();
            dweetObj = DweetService.checkDweetValue();


            return Json(dweetObj, JsonRequestBehavior.AllowGet);
        }
    }
}