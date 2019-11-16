module.exports = {FooFirst};

function FooFirst(n){
    if(n > 0){
        console.log(`first: ${n*n}`);
        let s = require("./second");
        s.FooSecond(n-1);
    }
}
