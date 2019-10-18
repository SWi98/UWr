function rec_fib(n){
    if (n == 1){
        return 1;
    }

    else if (n == 0){
        return 0;
    }

    return rec_fib(n-1) + rec_fib(n-2);
}

function iter_fib(n){
    var a = 0, b = 1;
    for (var i = 2; i <= n; i ++){
        b = a + b;
        a = b - a;
    }
    return b;
}

function test_rec(n){
    for(var i = 1; i <= n; i++){
        console.time();
        console.log("\n", "fib(", n, ") =", rec_fib(n));
        console.timeEnd();
    }
}

function test_iter(n){
    for(var i = 1; i <= n; i++){
        console.time();
        console.log("\n", "fib(", n, ") =", iter_fib(n));
        console.timeEnd();
    }
}


//IE dla 35