<?php

$start = 1901;
$end = 2000;
$sum = 0;

for ($i = $start; $i <= $end; $i ++)
{
    for($j = 1; $j <= 12; $j++)
    {
        $date = '01-'.$j.'-'.$i;
        $day = date('D', strtotime($date));

        if($day === 'Sun')
        {
            //echo "$date\n";
            $sum++;
        }
    }
}

var_dump($sum);
