let ob = {
    _value : 10,

    get val(){
        return this._value;
    },
    set val(x){
        this._value = x;
    },

    mult : function(x){
        return x * this._value;
    }
}

/*Object.defineProperty(ob, '_str', {
    value : 'zzz'
});*/

ob._str = "zzz";

Object.defineProperty(ob, 'str', {
    get : function(){
        return this._str;
    },
    set : function(x){
        this._str = x;
    }
});

Object.defineProperty(ob, 'add', {
    value : function(x){
        this._str += x;
    }
});

console.log(ob.val, ob.str);
ob.str = "xxx";
console.log(ob.str);
ob.add("yyyy");
console.log(ob.str);
