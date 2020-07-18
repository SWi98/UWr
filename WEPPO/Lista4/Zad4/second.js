module.exports = {FooSecond}

let f = require("./first");

function FooSecond(n){
    if(n > 0){
        console.log(`second: ${n}`);
        f.FooFirst(n-1);
    }
}
