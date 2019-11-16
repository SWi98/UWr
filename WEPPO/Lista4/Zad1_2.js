var Tree = function(val, l, r){
    this.value = val;
    this.left = l;
    this.right = r; 
}

Tree.prototype[Symbol.iterator] = function*(){
    function * helper(node){
        if(node.left != null){
            yield* helper(node.left);       // The yield* is used to delegate to another generator or iterable object.
        }                                   // The yield* expression iterates over the operand and yields each value returned by it.
        yield node.value;                   // The value of yield* expression itself is the value returned by that iterator     
        if(node.right != null){             // when it's closed (i.e., when done is true).
            yield* helper(node.right);
        }
    }

    for(let val of helper(this)){
        yield val;
    }
}

var leaf1 = new Tree(1, null, null);
var leaf2 = new Tree(2, null, null);
var leaf3 = new Tree(3, null, null);
var node1 = new Tree(10, leaf1, leaf2);
var node2 = new Tree(20, leaf3, null);
var highest_node = new Tree(100, node1, node2);

console.log(highest_node.left.value);
console.log(highest_node.right.right)
//console.log(highest_node.right.right.value);
for(var x of highest_node){
    console.log(x);
}
