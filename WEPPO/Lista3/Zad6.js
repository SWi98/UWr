function createGenerator(end) {
    var _state = 0;
    return {
        next : function() {
            return {
                value : _state,
                done : _state++ >= end
            }
        }
    }
}

var foo1 = {
    [Symbol.iterator]() {
        return createGenerator(15);
    }
}

var foo2 = {
    [Symbol.iterator]() {
        return createGenerator(2);
    }
}


for (var f of foo1){
    console.log(f);
}

for (var f of foo2){
    console.log(f);
}
    