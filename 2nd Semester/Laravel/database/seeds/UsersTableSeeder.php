<?php

use Illuminate\Database\Seeder;
use App\User;
use App\Role;
class UsersTableSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        User::truncate();

        // $adminRole = Role::where('name', 'admin')->first();
        // $authorRole = Role::where('name', 'author')->first();
        // $userRole = Role::where('name', 'user')->first();

        User::create([
            'name' => 'Admin',
            'email' => 'admin@admin.com',
            'password' => bcrypt('admin'),
            'role' => 'admin',
        ]);

        User::create([
            'name' => 'Juris Freidenfelds',
            'email' => 'freidenfeldsjuris@gmail.com',
            'password' => bcrypt('kaut vai3'),
        ]);

        User::create([
            'name' => 'Samanta pļaviņa',
            'email' => 'samanta.plavina@gmail.com',
            'password' => bcrypt('kaut vai3'),
        ]);

    }
}
