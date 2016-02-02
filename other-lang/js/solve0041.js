var library = require('./library.js');

var solve = function ()
{
    var max = 9999999;

    for(var i = max; i > 0; i -= 2)
    {
        if(library.is_pandigital(i) && library.is_prime(i))
        {
            return i;
        }
    }
};

var sum = solve();
console.log(sum);

//var num = process.argv[2];
//console.log(library.is_pandigital(num));
