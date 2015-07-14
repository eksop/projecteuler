<?php

require_once 'library.php';

function solve()
{
    $max   = 1000000;
    $result = array();

    for ($i = 1; $i <= $max; $i+=1)
    {
        if(is_prime($i))
        {
            echo "Prime \$i = $i\n";
            continue;
        }
    }

    return $result;
}

$sum = 0;
$ret = solve();

var_dump($ret);
var_dump($sum);
