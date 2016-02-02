var binary = function( num )
{
    var xx = num;
    var result = '';

    while ( xx > 0 )
    {
        console.log( "xx = " + xx );
        result += Math.floor( xx % 2 );
        xx = Math.floor( xx / 2 );
    }

    console.log( "result " + result );
    return result.split( '' ).reverse().join( '' );
};

var palindrome = function( num )
{
    rev = num.toString().split( '' ).reverse().join( '' );

    if ( num == rev )
    {
        return true;
    }

    return false;
};

var solve = function()
{
    var sum = 0;
    var total = 1000000;

    for ( var i = 1; i < total; i++ )
    {
        if ( palindrome( i ) && palindrome( binary( i ) ) )
        {
            console.log( "\$i = " + i );
            sum += i;
        }
    }

    return sum;
};

var sum = solve();
console.log( sum );

//var num = process.argv[2];
//console.log(binary(num));
