<?php

function is_prime($num) {

    //2 is prime (the only even number that is prime)
    if($num == 2)
    {
        return true;
    }

    //Negative numbers are never primes
    if($num < 0 OR $num == 1 OR $num % 2 == 0)
    {
        return false;
    }

    /**
     * Checks the odd numbers. If any of them is a factor, then it returns false.
     * The sqrt can be an aproximation, hence just for the sake of
     * security, one rounds it to the next highest integer value.
     */
    for($i = 3; $i <= ceil(sqrt($num)); $i = $i + 2) {
        if($num % $i == 0)
            return false;
    }

    //echo "\$num = $num is prime!\n";
    return true;
}
