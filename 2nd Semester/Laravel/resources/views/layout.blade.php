<!DOCTYPE html>
<html lang="{{ str_replace('_', '-', app()->getLocale()) }}">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" />
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
 
        <title>Laravel</title>
        
    </head>
<body>
        <div class="flex-center position-ref full-height">
            
            <nav class="navbar navbar-default">
                <div class="container-fluid">
                      <div class="navbar-header">
                        
                      </div>
                      <ul class="nav navbar-nav">
                        <li>
                                @if (Route::has('login'))
                    
                        @auth
                            <a href="{{ url('/home') }}">Home</a>
                        @else
                            <li><a href="{{ route('login') }}">Login</a></li>
    
                            @if (Route::has('register'))
                                <li><a href="{{ route('register') }}">Register</a></li>
                            @endif
                        @endauth
                    
                    @endif
                        </li>
                        <li><a href ="/event/create">Create a reservation</a></li>
                        <li><a href="/event">List of reservations</a></li>
                        
                      </ul>
                </div>
            </nav>
        </div>
    <div class="container">
        @yield('content')
    </div>
</body>
</html>