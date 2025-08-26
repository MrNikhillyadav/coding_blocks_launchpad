const numbers = [2,4,6,8];
console.log(numbers);

// new numbers array -> [4,8,12,16]

const newNumbers = numbers.map(
    function(x){
        return   x * 2;
    }
)

console.log(newNumbers);



// const arr = [1,2,3,4];

// const newArr =  arr.map( 
//     function (x){
//         return x * 3
//     }
// )

// console.log(newArr);
// output :  [3,6,9,12]


// filter method

const nums = [1, 2, 3, 4, 5];

// filter out only even numbers,
const even = nums.filter(
    function(x){
        return x % 2 == 0;
    }
)

console.log(nums)
console.log(even)


const arr = ["hi", "good", "no", "yes", "okay"]

const newArr = arr.filter(
    function(x){
        return x.length == 2;
    }
)

console.log(newArr);

const Arr = arr.filter( x => x.length == 2)
console.log('newArr: ', Arr);



// setTimeout

setTimeout(function() {
  console.log("This prints after 5 seconds!");
}, 5* 1000);


setTimeout(() => {
  console.log("Time's up!");
}, 3000);



//setInterval() function

setInterval(
    function(){
        console.log("Drink water")
    },
    2*1000
)


let name = "Nikhil"; // global scope

function greet() {
    let message = "Hello"; // local scope
    console.log(message + " " + name);

}
greet();

console.log(message); // Error: not accessible here


if (true) {
    let y = 10;

}

console.log(y)



let a = "outside"; //global scope

function test() {
	let a = "inside"; // function/local scope
	console.log(a);
}

test();

console.log(a);


function foo() {
  let z = 7; // local scope
  console.log(z);
}

foo()

console.log(z) // error



let numStr = "123";
console.log(typeof(numStr))

let num = Number(numStr);
console.log(typeof(num))
