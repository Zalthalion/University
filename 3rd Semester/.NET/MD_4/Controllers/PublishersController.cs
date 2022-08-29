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
    public class PublishersController : Controller
    {
        private readonly MD4_DBContext _context;

        public PublishersController(MD4_DBContext context)
        {
            _context = context;
        }

        // GET: Publishers
        public async Task<IActionResult> Index()
        {
            return View(await _context.Publishers.ToListAsync());
        }

        // GET: Publishers/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var publishers = await _context.Publishers
                .FirstOrDefaultAsync(m => m.Id == id);
            if (publishers == null)
            {
                return NotFound();
            }

            return View(publishers);
        }

        // GET: Publishers/Create
        [Authorize]
        public IActionResult Create()
        {
            return View();
        }

        // POST: Publishers/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        [Authorize]
        public async Task<IActionResult> Create([Bind("PubName,City,Country,Id")] Publishers publishers)
        {
            if (ModelState.IsValid)
            {
                _context.Add(publishers);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(publishers);
        }

        // GET: Publishers/Edit/5
        [Authorize]
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var publishers = await _context.Publishers.FindAsync(id);
            if (publishers == null)
            {
                return NotFound();
            }
            return View(publishers);
        }

        // POST: Publishers/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        [Authorize]
        public async Task<IActionResult> Edit(int id, [Bind("PubName,City,Country,Id")] Publishers publishers)
        {
            if (id != publishers.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(publishers);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!PublishersExists(publishers.Id))
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
            return View(publishers);
        }

        // GET: Publishers/Delete/5
        [Authorize]
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var publishers = await _context.Publishers
                .FirstOrDefaultAsync(m => m.Id == id);
            if (publishers == null)
            {
                return NotFound();
            }

            return View(publishers);
        }

        // POST: Publishers/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        [Authorize]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var publishers = await _context.Publishers.FindAsync(id);
            _context.Publishers.Remove(publishers);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool PublishersExists(int id)
        {
            return _context.Publishers.Any(e => e.Id == id);
        }
    }
}
