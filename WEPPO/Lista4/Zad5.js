console.log("Podaj imię");

function _once(){
    process.stdin.on('data', (name) => {
        console.log(name.toString());
        process.stdin.pause();
    });
}

function _on(){
    process.stdin.on('readable', function(){
        let name;                               //  'readable' event allows us to read the data whenever we want
        name = this.read();                     //  The readable.read() method pulls some data out of the internal buffer and returns it. 
        console.log(name.toString());           //  If no data available to be read, null is returned. 
        //process.stdin.pause();
    })
}

_on();