<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return redirect('event');
});

Auth::routes();
Route::resource('event', 'EventsController');
Route::post('/event/{event}/comment', 'CommentsController@store');
Route::get('/home', 'HomeController@index')->name('home');
Route::post('/event/filter', 'FilterController@search');
Route::get('/home/users', 'HomeController@getUsers');