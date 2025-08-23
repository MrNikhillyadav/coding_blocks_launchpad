
// array declaration
let fruits = ["Mango","Banana","Pear","Apple"];

console.log(fruits);

//updating/replacing the elements
fruits[2] = "Guava";

console.log(fruits);

//length of the array
console.log(fruits.length);

// insert element in an array
fruits.push("cherry");

console.log(fruits);
// console.log(fruits.length);

// printing all element of array
let arr = ["Apple", "Orange", "Pear"];

for (let i = 0; i < arr.length; i++) {
  console.log( arr[i] );
}


type casting

let numStr = "123";
console.log(typeof(numStr))

string -> number is called typecasting

let num = Number(numStr);
console.log(typeof(num))

let val = 15;
console.log(typeof(val));

let valStr = String(val);
console.log("Type is:", typeof valStr); 


let a = "456";

let b = Number(a) 
let res = b + 44;
console.log(res)


function showMessage() {
  console.log( 'Hello world!' );
}

showMessage();
showMessage();
showMessage();
showMessage();

function greet(name) {
  console.log( name );
}
greet('ram');


function sum(a,b){
    console.log(a+b);
}

sum(5,2)

function showMessage(name, message) {
  console.log(name + ': ' + message);
}

showMessage('Ann', "What's up?"); 



function checkAge(age) {
  if( age >= 18 ) {
     console.log('Access granted');
    } 
    else {
        console.log( 'Access denied' );
    }
}

let age = 10;
checkAge(age)



//arrow function
const sum = (a,b) => {
    console.log(a+b)
}

sum(5,5)


//higher order function
function sayHello() {
  console.log("Hello!");
}

function callFunction(fn) {
  fn(); 
}

callFunction(sayHello);  


function makeGreeter() {

  return function() {
    console.log("Hi there!");
  };

}

const greeter = makeGreeter();
greeter(); 
