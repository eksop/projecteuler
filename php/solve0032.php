<?php

function check_pan($num)
{
    $match = array();
    //$num = $a.$b.$prod;
    $result = array();

    preg_match_all('!\d!', $num ,$match);

    foreach ($match[0] as $digit)
    {
        if($digit == 0)
        {
            return FALSE;
        }

        if(isset($result[$digit]))
        {
            return FALSE;
        }

        $result[$digit] = TRUE;
    }

    return TRUE;
}


function solve()
{
    $max1   = 10000;
    $max2   = 100000;
    $result = array();

    for ($i = 1; $i <= $max1; $i+=1)
    {
        if(!check_pan($i))
        {
            //echo "Not pan \$i = $i\n";
            continue;
        }

        for($j = 1; $j <= $max2; $j++)
        {
            $prod = $i * $j;
            $len = strlen($i.$j.$prod);

            if($len < 9)
            {
                continue;
            }

            if($len > 9)
            {
                break;
            }

            if(!check_pan($i.$j.$prod))
            {
                continue;
            }

            if(isset($result[$prod]))
            {
                echo "Dup \$i = $i, \$j = $j :: \$prod = $prod\n";
                $result[$prod] += 1;
                continue;
            }

            echo "New \$i = $i, \$j = $j :: \$prod = $prod\n";
            $result[$prod] = 1;
        }
    }

    return $result;
}

$sum = 0;
$ret = solve();

foreach ($ret as $key => $value)
{
    $sum += $key;
}

var_dump($ret);

var_dump($sum);
