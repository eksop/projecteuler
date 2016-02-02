var library = require('./library.js');

var solve = function ()
{
    var largest = 0;
    var total = 100000;

    for(var i = 1; i < total; i++)
    {
        var num = '';

        for(var j = 1; j <= 9; j ++)
        {
            num += i * j;

            digits = num.toString().split('');

            if(digits.length > 9)
            {
                break;
            }

            if(digits.length < 9)
            {
                continue;
            }

            if(library.is_pandigital(num))
            {
                if(largest < num)
                {
                    largest = num;
                    console.log(largest);
                }
            }
        }
    }

    return largest;
};

var sum = solve();
console.log(sum);

//var num = process.argv[2];
//console.log(library.is_pandigital(num));
