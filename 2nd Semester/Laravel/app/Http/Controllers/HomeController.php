<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Event;
use App\User;
use Illuminate\Support\Facades\Auth;
class HomeController extends Controller
{
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct()
    {
        $this->middleware('auth');
    }

    /**
     * Show the application dashboard.
     *
     * @return \Illuminate\Contracts\Support\Renderable
     */


    public function index(Event $event)
    {
        $events = Event::where('owner_id', auth()->id())->get();
        return view('home', compact('events'));
    }
    
    public function getUsers()
    {
        $users = User::all();
        return view('user', compact('users'));
    }
    

}
