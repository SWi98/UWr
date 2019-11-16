function sump(x){
    var _sum = x;
    var _f = function(y){
        _sum += y;
        return _f;
    }

    _f.valueOf = function(){
        return _sum;
    }
    return _f; 
}

function sum2(x, y){
    console.log(x, y)
    return x + y;
}

function partial(fn, ...args){
    console.log(args);
    return function(...brgs){
        console.log(brgs)
        return fn(...args, ...brgs);    //sum2([1, 8], 3)??
    }
}

var sum = partial(sum2, 1, 8);
console.log(partial(sum2, 1, 8)(3))
var s2 = partial(sum2, 1);
console.log(s2(3, 4), "\n_____________________\n");

function sum3(x, y, z){
    return x + y + z;
}

function rec(fn, i, args){
    if(fn.length == 0){
        return fn;
    }
    if(i < fn.length){
        return(x) => {
            args.push(x);
            return rec(fn, i + 1, args)
        }
    }
    else{
        return fn(...args);
    }
}

function curry(fn){
    return rec(fn, 0, []);
}

var currysum3 = curry(sum3);
var currysum3_2 = curry(sum3);
console.log(currysum3(1));
console.log(currysum3(2));
console.log(currysum3(3));              //  whats the difference between currysum3
console.log(currysum3_2(1)(2)(3));      // and currysum3_2?
console.log("__________________\n");

var counter = (function(){
    var i = 0;

    return{
        get: function(){
            return i;
        },
        increment: function(){
            return ++i;
        }
    };
}())                                   // bez nawiasów?

console.log(counter.get())
counter.increment();
console.log(counter.get());
console.log("___________________\n");

//  strona 5/10 wyklad 5

var Person = function(){
    var nameSymbol = Symbol("name");

    function Person(name){
        this[nameSymbol] = name;
    }

    Person.prototype.getName = function(){
        return this[nameSymbol];
    }

    return Person;
}();

var p1 = new Person("tomasz");
var p2 = new Person("adam");
console.log(p1.getName())
console.log(p2.getName())
console.log(p1.nameSymbol)

// strona 3/4 wyklad 6