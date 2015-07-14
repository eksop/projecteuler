var library = require('./library.js');

var solve = function ()
{
    var sum   = 0;
    var total = 1000000;

    for(var i = 10; i < total; i++)
    {
        if(library.is_truncatable_prime(i))
        {
            console.log("\$i = " + i);
            sum += i;
        }
    }

    return sum;
};

var sum = solve();
console.log(sum);

//var num = process.argv[2];
//console.log(binary(num));
