<?php

namespace App\Http\Controllers;
use Illuminate\Support\Facades\Date;
use Illuminate\Http\Request;
use App\Event;
use Carbon\Carbon;
class EventsController extends Controller
{
    
    public function index(Request $request)
    {
        $events = Event::all();
        return view('events.index', compact('events'));
    }

    public function __construct()
    {
        $this->middleware('auth')->except(['index']);
    }

    public function create()
    {
        return view('events.create');
    }

    public function store(Event $event)
    {
        $atributes = request()->validate([
            'date' => ['required'],
            'place' => ['required','max:40', 'min:4'],
            'time_from' => ['required', 'date_format:H:i'],
            'time_to' => ['required', 'date_format:H:i', 'after:time_from']
        ]);

        $atributes['owner_id'] = auth()->id();
        Event::create($atributes);
        
        return redirect('/home');
    }

    public function show(Event $event)
    {
        return view('events.show', compact('event'));
    }

    public function edit(Event $event)
    {
        if(auth()->id() == 1)
        {
            return view('events.edit', compact('event'));
        }
        else
        {
        abort_if($event->owner_id !== auth()->id(), 403);
        return view('events.edit', compact('event'));
        }
    }

    public function update(Event $event)
    {
        if(auth()->id() == 1)
        {
            $event->update(request()->validate([
                'date' => ['required'],
                'place' => ['required','max:40', 'min:4'],
                'time_from' => ['required', 'date_format:H:i'],
                'time_to' => ['required', 'date_format:H:i', 'after:time_from']
            ]));
        }
        else
        {
        abort_if($event->owner_id !== auth()->id(), 403);
        $event->update(request()->validate([
            'date' => ['required'],
            'place' => ['required','max:40', 'min:4'],
            'time_from' => ['required', 'date_format:H:i'],
            'time_to' => ['required', 'date_format:H:i', 'after:time_from']
        ]));
        }
        return redirect('/event');
    }

    public function destroy(Event $event)
    {
        if(auth()->id() == 1)
        {
            $event->delete();
        }
        else
        {
            abort_if($event->owner_id !== auth()->id(), 403);
            $event->delete();
        }

        return redirect('/event');
    }
}
