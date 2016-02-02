/**
 * Primality test
 */
var is_prime = function (num)
{
    if(num == 2)
    {
        return true;
    }

    if(num < 0 || num == 1 || num % 2 == 0)
    {
        return false;
    }

    if(num % 2 == 0)
    {
        return false;
    }

    for(var i = 3; i <= Math.ceil(Math.sqrt(num)); i = i + 2)
    {
        if(num % i == 0)
        {
            return false;
        }
    }

    return true;
};

/**
 * Truncatable Prime
 */
var is_truncatable_prime = function (num)
{
    if(!is_prime(num))
    {
        return false;
    }

    var left  = num;
    var right = num;

    //console.log("Num = " + num);

    do
    {
        //console.log("L = " + left);

        if(!is_prime(left))
        {
            return false;
        }

        var left = left.toString().substring(1, left.length);
    }
    while(left);

    do
    {
        if(!is_prime(right))
        {
            return false;
        }

        var right = right.toString().slice(0, -1);
    }
    while(right);

    return true;
}

/**
 * Circular Prime
 */
var is_circular_prime = function (num)
{
    var rot = num;

    do
    {
        if(!is_prime(rot))
        {
            return false;
        }

        var digits = rot.toString().split('');
        digits.push(digits.shift());
        //var rot = arr.unshift(arr.pop());
        var rot = digits.join('');
    }
    while(rot != num);

    return true;
}

/**
 * Pandigital
 */
var is_all_unique = function (num)
{
    var digits = num.toString().split('');
    var result = {};

    var len = digits.length;

    for (var i = 0; i < len; i++)
    {
        if(digits[i] == 0)
        {
            return false;
        }

        if ((digits[i] in result))
        {
            return false;
        }

        result[digits[i]] = true;
    }

    return true;
}

/**
 * Pandigital
 */
var is_pandigital = function (num, start)
{
    start   = (typeof start !== 'undefined') ? start : 1;
    var digits = num.toString().split('');
    var result = {};
    var len    = digits.length;

    for (var i = 0; i < len; i++)
    {
        if(digits[i] < start)
        {
            return false;
        }

        if ((digits[i] in result))
        {
            return false;
        }

        result[digits[i]] = true;
    }

    var keys = {};

    for(var i = start; i < len + start; i++)
    {
        if (!(i.toString() in result))
        {
            return false;
        }
    }

    return true;
}

/**
 * Pandigital
 */
var is_pandigital_v2 = function (num, start)
{
    start   = (typeof start !== 'undefined') ? start : 1;

    var lookup = [false, false, false, false, false, false, false, false, false, false];
    var digits = num.toString().split('');
    var len    = digits.length;

    for (var i = 0; i < len; i++)
    {
        if(digits[i] < start)
        {
            return false;
        }

        if (lookup[digits[i]])
        {
            return false;
        }

        lookup[digits[i]] = true;
    }

    for(var i = start; i < len + start; i++)
    {
        if (!lookup[i])
        {
            return false;
        }
    }

    return true;
}


/**
 *
 */
 var sieve_of_erato = function (n)
 {
     // Eratosthenes algorithm to find all primes under n
     var array = [], upperLimit = Math.sqrt(n), output = [];

     // Make an array from 2 to (n - 1)
     for (var i = 0; i < n; i++)
     {
         array.push(true);
     }

     // Remove multiples of primes starting from 2, 3, 5,...
     for (var i = 2; i <= upperLimit; i++)
     {
         if (array[i])
         {
             for (var j = i * i; j < n; j += i)
             {
                 array[j] = false;
             }
         }
     }

     // All array[i] set to true are primes
     for (var i = 2; i < n; i++)
     {
         if(array[i])
         {
             output.push(i);
         }
     }

     return output;
 };

exports.is_prime = is_prime;
exports.is_circular_prime = is_circular_prime;
exports.is_truncatable_prime = is_truncatable_prime;
exports.is_all_unique = is_all_unique;
exports.is_pandigital = is_pandigital;
exports.is_pandigital_v2 = is_pandigital_v2;
exports.sieve_of_erato = sieve_of_erato;
