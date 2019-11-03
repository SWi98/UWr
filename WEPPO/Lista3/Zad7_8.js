function fib() {
    var _prev = 0;
    var _current = 1;
    return {
        next : function() {
            _current += _prev;
            _prev = _current - _prev;

            return {
                value : _current,
                done : false
            }
        }
    }
}

function *fib2() {
    var _prev = 0;
    var _current = 1;
    while(true){
        _current += _prev;
        _prev = _current - _prev;
        yield _current;
    }
}

function* take(it, top) {
    for(let i = 0; i < top; i++){
        yield it.next();
    }
}
// zwróć dokładnie 10 wartości z potencjalnie
// "nieskończonego" iteratora/generatora

for (let num of take( fib(), 10 ) ) {
    console.log(num["value"]);
}
    

/*var _it1 = {
    [Symbol.iterator] : fib
}

var _it2 = fib2();

for(var i of _it1){
    console.log(i);
}

/*for ( var _result; _result = _it.next(), !_result.done; ) {
    console.log( _result.value );
}*/
    