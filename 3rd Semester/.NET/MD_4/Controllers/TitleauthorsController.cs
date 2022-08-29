using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using MD4._1.Models;

namespace MD4._1.Controllers
{
    public class TitleauthorsController : Controller
    {
        private readonly MD4_DBContext _context;

        public TitleauthorsController(MD4_DBContext context)
        {
            _context = context;
        }

        // GET: Titleauthors
        public async Task<IActionResult> Index()
        {
            var mD4_DBContext = _context.Titleauthor.Include(t => t.Person).Include(t => t.Title);
            //var mD4_DBContext1 = _context.Titleauthor.Include(t => t.Person).Include(t => t.Title);
            return View(await mD4_DBContext.ToListAsync());
        }

        // GET: Titleauthors/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var titleauthor = await _context.Titleauthor
                .Include(t => t.Person)
                .Include(t => t.Title)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (titleauthor == null)
            {
                return NotFound();
            }

            return View(titleauthor);
        }

        // GET: Titleauthors/Create
        public IActionResult Create()
        {
            ViewData["PersonId"] = new SelectList(_context.Author, "Id", "Phone");
            ViewData["TitleId"] = new SelectList(_context.Titles, "Id", "Title");
            return View();
        }

        // POST: Titleauthors/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("AuOrd,TitleId,Id,PersonId")] Titleauthor titleauthor)
        {
            if (ModelState.IsValid)
            {
                _context.Add(titleauthor);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["PersonId"] = new SelectList(_context.Author, "Id", "Phone", titleauthor.PersonId);
            ViewData["TitleId"] = new SelectList(_context.Titles, "Id", "Title", titleauthor.TitleId);
            return View(titleauthor);
        }

        // GET: Titleauthors/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var titleauthor = await _context.Titleauthor.FindAsync(id);
            if (titleauthor == null)
            {
                return NotFound();
            }
            //var mD4_DBContext = _context.Titleauthor
            //    .Include(t => t.Person)
            //    .Include(t => t.Title).Where(t=> t.Id == id);
            //await mD4_DBContext.ToListAsync();
            //return View(await mD4_DBContext.ToListAsync());

            ViewData["PersonId"] = new SelectList(_context.Author, "Id", "Phone", titleauthor.PersonId);
            ViewData["TitleId"] = new SelectList(_context.Titles, "Id", "Title", titleauthor.TitleId);
            return View(titleauthor);
        }

        // POST: Titleauthors/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("AuOrd,TitleId,Id,PersonId")] Titleauthor titleauthor)
        {
            if (id != titleauthor.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(titleauthor);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!TitleauthorExists(titleauthor.Id))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));
            }
            ViewData["PersonId"] = new SelectList(_context.Author, "Id", "Phone", titleauthor.PersonId);
            ViewData["TitleId"] = new SelectList(_context.Titles, "Id", "Title", titleauthor.TitleId);
            return View(titleauthor);
        }

        // GET: Titleauthors/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var titleauthor = await _context.Titleauthor
                .Include(t => t.Person)
                .Include(t => t.Title)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (titleauthor == null)
            {
                return NotFound();
            }

            return View(titleauthor);
        }

        // POST: Titleauthors/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var titleauthor = await _context.Titleauthor.FindAsync(id);
            _context.Titleauthor.Remove(titleauthor);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool TitleauthorExists(int id)
        {
            return _context.Titleauthor.Any(e => e.Id == id);
        }
    }
}

