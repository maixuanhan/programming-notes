function cons(a, b) {
    function pair(f) {
        return f(a, b);
    }
    return pair;
}

function car(pair) {
    function first(a, b) {
        return a;
    }

    return pair(first);
}

function cdr(pair) {
    function last(a, b) {
        return b;
    }

    return pair(last);
}

console.log(car(cons(3, 4)) === 3);
console.log(cdr(cons(3, 4)) === 4);
