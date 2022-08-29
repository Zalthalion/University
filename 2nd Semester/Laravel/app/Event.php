<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class Event extends Model
{
    protected $guarded =[];

    public function comment()
    {
        return $this->hasMany(Comment::class);
    }


}

