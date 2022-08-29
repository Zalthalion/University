@extends('layout')

@section('content')
    <body>
        
        <div class="container box">
                <h3>Already made reservations</h3>
                <br>
                <form method="POST" action="/event/filter">
                    @csrf
                    <p>Start Date:</p>
                    <input class="form-control" type="date" name="date_from">
                    
                    <br>
                    
                    <p>End Date:</p>
                    <input class="form-control" type="date" name="date_to">
                    
                    <br>
                    
                    <input class="btn" type="submit">
                  </form>
                  <br>
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
                        @csrf
                        </div>
                    </div>
                </div>
                
        </div>
        @include('errors')
    </body>
@endsection   


