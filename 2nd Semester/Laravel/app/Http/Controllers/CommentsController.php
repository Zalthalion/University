<?php

namespace App\Http\Controllers;

use Illuminate\Support\Facades\DB;
use Illuminate\Http\Request;
use App\Comment;
Use App\Event;
Use App\User;
class CommentsController extends Controller
{
    

    public function __construct()
    {
        $this->middleware('auth');
    }

    public function store(Comment $comment, Event $event)
    {
        if(auth()->id() == 1)
        {
            $atributes = request()->validate([
                'comment' => ['required', 'max:255'],
            ]);
            $atributes['owner_id'] = auth()->id();
            $atributes['event_id'] = $event->id;

            Comment::create($atributes);
            return back();
        }
        else 
        {
            abort_if($event->owner_id !== auth()->id(), 403);
            $atributes = request()->validate([
                'comment' => ['required', 'max:255'],
            ]);
        $atributes['owner_id'] = auth()->id();
        $atributes['event_id'] = $event->id;

        Comment::create($atributes);
        return back();
        }
    }
    
 

    public function edit(Comment $comment, Event $event)
    {
        abort_if($event->owner_id !== auth()->id(), 403);
        $comment->update(request()->validate([
            'comment' => ['required', 'max:255'],            
        ]));

        return back();
    }

}
