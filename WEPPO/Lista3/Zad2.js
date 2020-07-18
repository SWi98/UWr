function rec_fib(n){
    if (n == 1 || n == 0){
        return n;
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

function rec_mem_fib(n){
    var cache = {};

    function _fib(n){
        if(n in cache){
            return cache[n];
        }
        else if(n == 0 || n == 1){
            cache[n] = n;
            return cache[n];
        }
        else{
            cache[n] = _fib(n-1) + _fib(n-2);
            return cache[n];
        }
    }

     _fib(n);
}

function auto_mem(fn){
    var cache = {};
    var slice = Array.prototype.slice;
    return function(n){
        var args = slice.call(arguments);
        if(args in cache){
            return cache[args];
        }
        else{
            cache[args] = fn.apply(this, args);
            return cache[args];
        }
    }
}

function test_rec(n){
    console.log("RECURSIVE");
    for(var i = 1; i <= n; i++){
        console.time();
        console.log("\n", "fib(", i, ") =", rec_fib(i));
        console.timeEnd();
    }
    console.log("\n\n");
}

function test_iter(n){
    console.log("ITERATIVE");
    for(var i = 1; i <= n; i++){
        console.time();
        console.log("\n", "fib(", i, ") =", iter_fib(i));
        console.timeEnd();
    }
    console.log("\n\n");
}

function test_mem(n){
    console.log("MEMOIZATION");
    for(var i = 1; i <= n; i++){
        console.time();
        console.log("\n", "fib(", i, ") =", rec_mem_fib(i));
        console.timeEnd();
    }
    console.log("\n\n");
}

function test_auto_mem(n){
    console.log("AUTO MEMOIZATION");
    let foo = auto_mem(rec_fib);
    for(var i = 1; i <= n; i++){
        console.time();
        console.log("\n", "fib(", i, ") =", foo(i));
        console.timeEnd();
    }
    console.log("__________________");
    for(var i = 1; i <= n; i++){
        console.time();
        console.log("\n", "fib(", i, ") =", foo(i));
        console.timeEnd();
    }
    console.log("\n\n");
}

function foo(y, z){
    return this.A + y + z;
}

let context = {
    A : 5
}
var _foo = foo.bind(context);
console.log(_foo(1, 2));

//IE dla 35