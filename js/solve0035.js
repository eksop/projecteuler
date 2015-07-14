var library = require('./library.js');

var solve = function ()
{
    var sum   = 0;
    var total = 1000000;

    for(var i = 1; i < total; i++)
    {
        var ret = library.is_circular_prime(i);

        if(ret)
        {
            //console.log(x);
            sum++;
        }
    }

    return sum;
};

var sum = solve();

console.log(sum);

//var num = process.argv[2];
//console.log(num);
//console.log(is_circular_prime(num));
