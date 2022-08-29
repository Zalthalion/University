@extends('layout')

@section('content')
    <h1 class="date">Edit event</h1>
        <form method="POST" action="/event/{{$event->id}}" style="margin-bottom:10px">
            @method('PATCH')
            @csrf 
            <div class="field">
                <label class="label" for="date">Date</label>

                <div class="control">
                    <input type="text" class="input" name="date" placeholder="date" value="{{ $event->date}}">
                </div>
            </div>

            <div class="field">
                <label class="label" for="place">Place</label>

                <div class="control">
                    <textarea name="place" class="textarea">{{ $event->place }}</textarea>
                </div>
            </div>

            <div class="field">
                <label class="label" for="time_from">Time From</label>

                <div class="control">
                    <textarea name="time_from" class="textarea">{{ $event->time_from }}</textarea>
                </div>
            </div>

            <div class="field">
                <label class="label" for="time_to">Time to</label>

                <div class="control">
                    <textarea name="time_to" class="textarea">{{ $event->time_to }}</textarea>
                </div>
            </div>
            
            
            
            <div class="field">
                <div class="control">
                    <button type="submit" class="button is-link">Update event</button>
                </div>
            </div>

        </form>
        
        <form method="POST" action="/event/{{$event->id}}">
        @method('DELETE')
        @csrf
        <div class="field">
                <div class="control">
                    <button type="submit" class="button">Delete</button>
                </div>
            </div>

        </form>
        

@endsection