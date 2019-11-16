var Foo = (function(){
    var Qux = function(){
        console.log("Qux");
    };
    function Foo(){
    };
    Foo.prototype.Bar = function(){
        Qux();
    };
    return Foo;
}());

var test = new Foo();
test.Bar();
//test.Qux();