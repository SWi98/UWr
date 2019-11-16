module.exports = {}

let f = require("./first");

module.exports.FooSecond = function(n){
    if(n > 0){
        console.log(`second: ${n}`);
        f.FooFirst(n-1);
    }
}
