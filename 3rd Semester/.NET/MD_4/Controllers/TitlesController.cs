using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using MD4._1.Models;
using Microsoft.AspNetCore.Authorization;

namespace MD4._1.Controllers
{
    public class TitlesController : Controller
    {
        private readonly MD4_DBContext _context;

        public TitlesController(MD4_DBContext context)
        {
            _context = context;
        }

        // GET: Titles
        public async Task<IActionResult> Index()
        {
            var mD4_DBContext = _context.Titles.Include(t => t.Pub);
            return View(await mD4_DBContext.ToListAsync());
        }

        // GET: Titles/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }


            var titles = await _context.Titles
                .Include(t => t.Pub)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (titles == null)
            {
                return NotFound();
            }
            ViewData["Test"] = new SelectList(_context.Author, "Fname", "Lname");
            return View(titles);
        }

        // GET: Titles/Create
        [Authorize]
        public IActionResult Create()
        {
            ViewData["PubId"] = new SelectList(_context.Publishers, "Id", "PubName");
            return View();
        }

        // POST: Titles/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        [Authorize]
        public async Task<IActionResult> Create([Bind("Title,TitleType,Price,Pubdate,Id,PubId")] Titles titles)
        {
            if (ModelState.IsValid)
            {
                _context.Add(titles);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["PubId"] = new SelectList(_context.Publishers, "Id", "PubName", titles.PubId);
            return View(titles);
        }

        // GET: Titles/Edit/5
        [Authorize]
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var titles = await _context.Titles.FindAsync(id);
            if (titles == null)
            {
                return NotFound();
            }
            ViewData["PubId"] = new SelectList(_context.Publishers, "Id", "PubName", titles.PubId);
            return View(titles);
        }

        // POST: Titles/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        [Authorize]
        public async Task<IActionResult> Edit(int id, [Bind("Title,TitleType,Price,Pubdate,Id,PubId")] Titles titles)
        {
            if (id != titles.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(titles);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!TitlesExists(titles.Id))
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
            ViewData["PubId"] = new SelectList(_context.Publishers, "Id", "Id", titles.PubId);
            return View(titles);
        }

        // GET: Titles/Delete/5
        [Authorize]
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            List<string> dropDown = new List<string>();
            dropDown.Add("Undecided");
            dropDown.Add("Test1");
            dropDown.Add("Undecided");
            dropDown.Add("Undecided");

            ViewBag.DropDown = dropDown;

            var titles = await _context.Titles
                .Include(t => t.Pub)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (titles == null)
            {
                return NotFound();
            }

            return View(titles);
        }

        // POST: Titles/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        [Authorize]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var titles = await _context.Titles.FindAsync(id);
            _context.Titles.Remove(titles);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool TitlesExists(int id)
        {
            return _context.Titles.Any(e => e.Id == id);
            
        }
    }
}
