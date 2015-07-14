<?php

$table = array();
$result = array();
$start = 1;
$end = 1000;
$x = 5;

function get_recurring($num)
{
    $result = '';
    $rem = 1;
    $xx = 1;
    $count = 0;
    $pattern = '';

    while($rem !== 0 AND empty($pattern))
    {
        for($i = 0; $xx < $num; $i++)
        {
            if($i !== 0)
            {
                $result .= "0";
            }

            $xx = $xx * 10;
        }

        $val = floor($xx / $num);
        $rem = $xx % $num;

        //echo "$val\t";
        //echo "$rem\n";
        $result .= $val;
        $xx = $rem;
        $count ++;

        preg_match_all( '/(\S{2,}?)\1+/', $result, $matches );

        $matches[0] = array_unique( $matches[0] );

        if(empty($matches[0]))
        {

        }
        else
        {
            foreach ( $matches[0] as $key => $value )
            {
                if ( strlen( $value ) > 6 )
                {
                    $pattern = $matches[1][$key];
                    break;
                }
            }
        }
    }

    if(!empty($pattern))
    {
        return $pattern;
    }

    return $result;
}

//$ret = get_recurring($argv[1]);

$largest = 0;
$num = 0;

for($i = 2; $i < $end; $i++)
{
    $result[$i] = get_recurring($i);

    if (strlen($largest) < strlen($result[$i]))
    {
        $largest = $result[$i];
        $num = $i;
    }

    echo "NUM = [$i] : {$result[$i]}\n\n";
}

echo "\n***************\nLargest \$i = $num\nPattern =>";
var_dump($largest);
