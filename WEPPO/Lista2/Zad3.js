//console.log( (![]+[])[+[]]+(![]+[])[+!+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]] );
console.log()
console.log("![]+[]", ![]+[]) // false converted to string because of '+' operator
console.log("[+[]]", [+[]])  // '+' converts [] into number (0)
console.log("(![]+[])[+[]]", (![]+[])[+[]]) // "false"[0]
console.log("![]+[]", ![]+[], "\n") // '+' converts ![] to string and adds [] to it -> "false"

console.log("[+!+[]]", [+!+[]])    // !+[] negates 0 - we get true, '+' converts true to 1
console.log("(![]+[])[+!+[]]", (![]+[])[+!+[]], "\n") // "false"[1]

console.log("[][[]]", [][[]])     // undefined (there's no property [[]] in [] (?))
console.log("([![]]+[][[]])", ([![]]+[][[]])) // (false + undefined) == "falseundefined"
console.log("[+!+[]+[+[]]]", [+!+[]+[+[]]]) // [] + [+[]] == '00'; +!+[] == 1 => [+!+[]+[+[]]] == ['10'] 
console.log("([![]]+[][[]])[+!+[]+[+[]]]", ([![]]+[][[]])[+!+[]+[+[]]], "\n") // "falseundefined"['10'] == 'i'

console.log("[!+[]+!+[]]", [!+[]+!+[]]) // [1 + 1]
console.log("(![]+[])[!+[]+!+[]]", (![]+[])[!+[]+!+[]]) // "false"[2] == "l

console.log("([] + [][[]])[5]", ([] + [][[]])[5])
