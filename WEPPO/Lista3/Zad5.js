function sum() {
    return Array.prototype.slice.call(arguments).reduce((acc, x) => acc + x);
}
console.log(sum(1,2,3));
// 6
console.log(sum(1,2,3,4,5));
// 15

    