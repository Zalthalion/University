@extends('layout')

@section('content')
    <h1 class="title">Edit event</h1>

        <form method="POST" action="/event/{{$event->id}}" style="margin-bottom:10px">
            @method('PATCH')
            @csrf 
            <div class="field">
                <label class="label" for="date">Date</label>

                <div class="control">
                    <input type="text" class="form-control" name="date" placeholder="Date" value="{{ $event->date}}">
                </div>
            </div>

            <div class="field">
                <label class="label" for="place">Place</label>

                <div class="control">
                    <input type="text" class="form-control" name="place" placeholder="Place" value="{{ $event->place}}">
                </div>
            </div>

            <div class="field">
                <label class="label" for="time_from">Time From</label>

                <div class="control">
                    <input type="text" class="form-control" name="time_from" placeholder="Time From" value="{{ $event->time_from}}">
                </div>
            </div>

            <div class="field">
                <label class="label" for="time_to">Time To</label>

                <div class="control">
                    <input type="text" class="form-control" name="time_to" placeholder="Time To" value="{{ $event->time_to}}">
                </div>
            </div>
            
            <br>

            <div class="field">
                <div class="control">
                    <button type="submit" class="btn">Update event</button>
                </div>
            </div>
        </form>
        
        <form method="POST" action="/event/{{$event->id}}">
        @method('DELETE')
        @csrf
        <div class="field">
                <div class="control">
                        <button type="submit" class="btn" onclick="return confirm('Are you sure?')" >Delete</button>
                </div>

        </div>
            <br>
            
            @include('errors')

        </form>
       

@endsection