@extends('layouts.app')

@section('content')

    @php
    $user = App\User::where('id', auth()->id())->first();
    $role = $user->role;
    @endphp

@if($user->role === 'admin')
<table class="table table-striped table-bordered" style="width:80%; margin-right: auto; margin-left:auto;">
    <thead>
        <tr>
            <th width="25%">Place</th>
            <th width="25%">Date</th>
            <th width="25%">Name</th>
            <th width="25%">E-mail</th>
        </tr>
    </thead>
    <tbody>
        @php
        $events = App\Event::all();
        @endphp
        @foreach ($events as $event)
            <tr>
                <td><a href="/event/{{$event->id}}"> {{ $event->place }}</a></td>
                <td>{{$event->date}}</td>
                @php
                $user = App\User::where('id', $event->owner_id)->first();
                @endphp
                <td>{{$user->name}}</td>
                <td>{{$user->email}}</td>
            </tr>
       @endforeach
                  
    </tbody>
</table>
@else
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-8">
                <div class="card">
                    <div class="card-header">My reservations</div>

                <div class="card-body">
                    @if (session('status'))
                        <div class="alert alert-success" role="alert">
                            {{ session('status') }}
                        </div>
                    @endif

                   
                    <table class="table table-striped table-bordered">
                            <thead>
                                <tr>
                                    <th width="33%">Place</th>
                                    <th width="33%">Time: from - to</th>
                                    <th width="33%">Date</th>

                                </tr>
                            </thead>
                            <tbody>
                                    @foreach($events as $event)
                                     <tr>
                                         <td> <a href="/event/{{$event->id}}">{{$event->place}}</a> </td>
                                         <td> {{$event->time_from}} - {{$event->time_to}}</td>
                                         <td> {{$event->date}} </td>
                                     </tr>
                                    @endforeach
                              </tbody>
                        </table>

                </div>
            </div>
        </div>
    </div>
</div>
@endif
@endsection
