.pragma library

var placeHolders    = []
var creatures       = []

function shuffle(anArray) {
    for(var j, x, i = anArray.length; i; j = parseInt(Math.random() * i), x = anArray[--i], anArray[i] = anArray[j], anArray[j] = x);
    return anArray;
};
