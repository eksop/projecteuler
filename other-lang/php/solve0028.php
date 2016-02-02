<?php

function solve()
{
    $max  = 1001;
    $last = 1;
    $sum  = 1;
    $int  = 2;

    for ($i = 3; $i <= $max; $i+=2)
    {
        $sum  += 4 * $last + 10 * $int;
        $last  = $last + 4 * $int;
        $int  += 2;
    }

    return $sum;
}

$ret = solve();

var_dump($ret);
