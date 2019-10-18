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

for(var i = 1; i <= 5; i++){
    console.time();
    console.log("\n", i, "fib(", 30, ") =", rec_fib(30));
    console.timeEnd();
}

//IE dla 35