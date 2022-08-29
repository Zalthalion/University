@extends('layout')

@section('content')
    <h1 class="title">Reservation</h1>

    <table class="table table-striped table-bordered">
        <thead>
            <tr>
                <th width="33%">Place</th>
                <th width="33%">Time: from - to</th>
                <th width="33%">Date</th>
            </tr>
        </thead>

        <tbody>
            <tr>
                <td> {{$event->place}} </td>
                <td> {{$event->time_from}} - {{$event->time_to}}</td>
                <td> {{$event->date}} </td>
            </tr>            
        </tbody>
    </table>
        

    <div>
        <button class="btn"><a href="/event/{{$event->id}}/edit">Edit</a></button>
            <br>
            <br>
        <form method="POST" action="/event/{{$event->id}}" >
            @method('DELETE')
            @csrf
            <div class="field">
                <div class="control">
                    <button type="submit" class="btn" onclick="return confirm('Are you sure?')" >Delete</button>
                </div>
            </div>
        </form>
    </div>

    <div> 
        <form method="POST" action="/event/{{$event->id}}/comment/">
        @csrf
            <div class="label" for="comment">New comment</div>
                <br>
            <div>
                <textarea class="form-control" name="comment" placeholder="Add a comment"></textarea>
            </div>
                <br>
            <button class="btn" type="submit">Add a comment</button>
        </form>
                <br>

    @include('errors')
        <br>


    @if($event->comment->count())
    <table class="table table-striped table-bordered">
        <thead>
            <tr>
                <th width="20%">Name</th>
                <th width="70%">Comment</th>
            </tr>
        </thead>
        
        <tbody>
            @foreach ($event->comment as $evnt)
            <tr>
                    
                @php
                    $user = App\User::where('id', $evnt->owner_id)->first();
                    $name = $user->name;
                    @endphp
                    <td> {{$name}} </td>
                    <td> {{$evnt->comment}} </td>
                    </tr>
                @endforeach
        </tbody>
    </table>
    @endif
    
</div>
@endsection

