<?php
use Illuminate\Support\Facades\DB;
namespace App\Http\Controllers;
use App\Event;
use Illuminate\Http\Request;

class FilterController extends Controller
{
    public function search(Request $request)
    {
        // DB::table('events')
        //     ->
        // $events = Event::where('id', 3)->get();
        // $eventdate = $events->date;
     
        $validatedData = request()->validate([
            'date_from' => ['required'],
            'date_to'   => ['required', 'after:date_from']  
        ]);

         $startDate = date($request->date_from);
         $endDate = date($request->date_to);
         
        $events = Event::whereDate('date','>=', $startDate)
                       ->whereDate('date', '<=', $endDate)
                       ->get();
        
         return view('events.index', compact('events'));
    }
}
