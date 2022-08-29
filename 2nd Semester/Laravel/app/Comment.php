<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Comment extends Model
{
    protected $guarded =[];

    public function event()
    {
        return $this->hasOne(Event::class);
    }
    public function user()
    {
        return $this->hasOne(User::class);
    }
}
