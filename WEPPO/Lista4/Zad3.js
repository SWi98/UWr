var Foo = (function(){
    var Qux = function(){
        console.log("Qux");
    };
    function _Foo(name){
        this.name = name;
    };
    _Foo.prototype.Bar = function(){
        Qux();
    };
    return _Foo;
})();

var test = new Foo("xyz");
test.Bar();
console.log(test.name)
//test.Qux();