function z1(){
    var res = [];
    
    for(var i = 1; i < 1000; i += 1){
        var digits = i.toString().split('').map((x) => parseInt(x));
        var sum = digits.reduce( (x, y) => x + y);
        var add = true;
        if (i % sum != 0) {
            add = false;
            continue;
        }

        for (var j = 0; j < digits.length; j++){
            if (i % digits[j] != 0){
                add = false; 
                break;
            }
        }

        if(add){
            res.push(i);
        }
    }

    console.log(res);
}

function z2(){
    var is_prime = [];
    var primes = [];
    var n = 100;

    for (var i = 2; i < n; i += 1){
        is_prime[i] = true; 
    }

    for (var i = 2; i < Math.sqrt(n); i += 1){
        if (is_prime[i]){
            for (var j = 2; (j * i) < n; j += 1){
                is_prime[j * i] = false;
            }
        }
    }
    
    for(var i = 2; i < n; i += 1){
        if (is_prime[i]){
            primes.push(i);
        }
    }

    console.log(primes);
}

z1();