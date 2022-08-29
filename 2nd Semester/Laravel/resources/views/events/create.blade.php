@extends('layout')

@section('content')
    <h1 class="title">Create a project</h1>
    

    <form method="POST" action="/event">
    @csrf
        <div class="field">
            <label class="label" for="date">Date</label>

            <div class="control">
                <input type="date" class="form-control" name="date" placeholder="Date" value="{{ old('date') }}">
            </div>
        </div>


        <div class="field">
            <label class="label" for="place">Place</label>

            <div class="control">
                <input type="text" class="form-control" name="place" placeholder="Place" value="{{ old('place') }}">
            </div>
        </div>


        <div class="field">
            <label class="label" for="time_from">Time From</label>

            <div class="control">
                <input type="text" class="form-control" name="time_from" placeholder="Time from" value="{{ old('time_from') }}">
            </div>
        </div>
                

        <div class="field">
            <label class="label" for="time_to">Time To</label>

            <div class="control">
                <input type="text" class="form-control" name="time_to" placeholder="Time to" value="{{ old('time_to') }}">
            </div>
        </div>              
        
        <br>

        <div class="field">
            <div class="control">
                <button type="submit" class="btn">Create Event</button>
            </div>
        </div>
        
        <br>

        @include('errors')
        
    </form>
@endsection
