let pizza = {
    toppings: ['cheese', 'sauce', 'pepperoni'],
    crust: 'deep dish',
    serves: 2,
    "3" : 10,
    3 : 9
}

let arr = [1, 2, 3, 4, 5, 6]
let test = [3]
let test2 = [3, 4, 5]

console.log("pizza[\"1+2\"] = ", pizza["1+2"])
console.log("pizza[1+2] = ", pizza[1+2])  // using [], firstly the argument in [] is evaluated
//console.log(pizza."toppings") // When working with dot notation, property identifies can only be alphanumeric (and _ and $).
console.log("pizza.toppings = ", pizza.toppings)     // Properties can’t start with a number.
//console.log(pizza.3) 

console.log(pizza[3], " ",  pizza["3"], " ", pizza[test], " ", pizza[test2])

pizza[3] = 999 
console.log(pizza[3])
pizza[test] = 111
console.log(pizza[3])

console.log(arr["2"], " ", arr.length, " ", arr["length"])
arr.length = 7
console.log(arr.length, arr[7])
arr.length = 4
console.log(arr.length, arr[5])

console.log()


// ZAD4 
let x = 10 
let y = new String("zzzz")
let z = "zzzzzzzz"

//console.log(Object.getPrototypeOf(pizza), Object.prototype)
console.log("pizza instanceof Object", pizza instanceof Object, "; typeof pizza =", typeof pizza, "\n")

//console.log(Object.getPrototypeOf([]), Array.prototype)
console.log("[] instanceof Array", [] instanceof Array, "; typeof [] =", typeof [], "\n")

//console.log(Object.getPrototypeOf(x), Number.prototype)
console.log("x instanceof Number", x instanceof Number, "; typeof x =", typeof x, "\n")

//console.log(Object.getPrototypeOf(y), String.prototype)
console.log("y instanceof String", y instanceof String, "; typeof y =", typeof y, "\n")

//console.log(Object.getPrototypeOf(z), String.prototype)
console.log("z instanceof String", z instanceof String, "; typeof z =", typeof z, "\n")

// prototype is associated with every function and object. it includes "constructor" property which returns a function that created the instance