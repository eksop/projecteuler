var library = require('./library.js');

var lookup = '';

for (var i = 0; lookup.length <= 1000000; i++)
{
    lookup += i;
}

var get_digit = function(position)
{
    return lookup.charAt(position);
}

var solve = function ()
{
    var prod = 1;

    for(var i = 1; i <= 1000000; i *= 10)
    {
        prod *= parseInt(get_digit(i));
    }

    return prod;
};

var sum = solve();
console.log(sum);

//var num = process.argv[2];
//console.log(library.is_pandigital(num));
