using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using SmartLabel.Models;

namespace SmartLabel.Controllers
{
    public class PromotionsController : Controller
    {
        private SmartDeviceEntities db = new SmartDeviceEntities();

        // GET: Promotions
        public ActionResult Index()
        {
            var promotions = db.Promotions.Include(p => p.User).Include(p => p.User1);
            return View(promotions.ToList());
        }

        // GET: Promotions/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Promotion promotion = db.Promotions.Find(id);
            if (promotion == null)
            {
                return HttpNotFound();
            }
            return View(promotion);
        }

        // GET: Promotions/Create
        public ActionResult Create()
        {
            ViewBag.CreateBy = new SelectList(db.Users, "UserKey", "UserName");
            ViewBag.ModifyBy = new SelectList(db.Users, "UserKey", "UserName");
            return View();
        }

        // POST: Promotions/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "PromotionKey,PromotionName,IssueDate,ExpireDate,DiscountRate,DiscountPrice,Description,CreateDate,CreateBy,ModifyDate,ModifyBy,Active,FileName,PhysicalPath,IISPath")] Promotion promotion)
        {
            if (ModelState.IsValid)
            {
                db.Promotions.Add(promotion);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.CreateBy = new SelectList(db.Users, "UserKey", "UserName", promotion.CreateBy);
            ViewBag.ModifyBy = new SelectList(db.Users, "UserKey", "UserName", promotion.ModifyBy);
            return View(promotion);
        }

        // GET: Promotions/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Promotion promotion = db.Promotions.Find(id);
            if (promotion == null)
            {
                return HttpNotFound();
            }
            ViewBag.CreateBy = new SelectList(db.Users, "UserKey", "UserName", promotion.CreateBy);
            ViewBag.ModifyBy = new SelectList(db.Users, "UserKey", "UserName", promotion.ModifyBy);
            return View(promotion);
        }

        // POST: Promotions/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "PromotionKey,PromotionName,IssueDate,ExpireDate,DiscountRate,DiscountPrice,Description,CreateDate,CreateBy,ModifyDate,ModifyBy,Active,FileName,PhysicalPath,IISPath")] Promotion promotion)
        {
            if (ModelState.IsValid)
            {
                db.Entry(promotion).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.CreateBy = new SelectList(db.Users, "UserKey", "UserName", promotion.CreateBy);
            ViewBag.ModifyBy = new SelectList(db.Users, "UserKey", "UserName", promotion.ModifyBy);
            return View(promotion);
        }

        // GET: Promotions/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Promotion promotion = db.Promotions.Find(id);
            if (promotion == null)
            {
                return HttpNotFound();
            }
            return View(promotion);
        }

        // POST: Promotions/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Promotion promotion = db.Promotions.Find(id);
            db.Promotions.Remove(promotion);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
