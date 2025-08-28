// console.log(a);

// var a = 10;


// function test() {

//   console.log(x);
//   var x = 5;  //undefined

//   console.log(y);
//   let y = 10; // reference error
// }

// test();





// ####### closures ########

// function outer() {
//   var a = 5; 
  
//   function inner() {
//     console.log(a); 
//   }

//   return inner; 
// }

// // console.log(a); // error

// var x = outer(); 
// x();
// x();
// x();
// x();


// function outer() {
//   let count = 0;
  
//   function inner() {
//     count++;
//     console.log(count);
//   }
  
//   return inner;
// }

// let counter = outer();

// counter(); 
// counter(); 
// counter(); 
// counter(); 


// function sample() {
//   let num = 10; 
  
//   function showNum() {
//     console.log(num); 
//   }
  
//   num = 42; 
//   return showNum; 
// }

// const result = sample(); 
// result();   // What is the output?


// function mystery() {
//   let value = 20;
  
//   function logValue() {
//     console.log(value);
//   }
  
//   value = 99;
//   return logValue;
// }

// const fn = mystery();
// fn(); // What will be printed?


// class Student {

//   constructor(name, id) {
//     this.name = name;    
//     this.id = id;
//   }
  
//   introduce() {          
//     console.log("Hi, I am " + this.name + "with id:" + this.id);
//   }
// }

// let s1 = new Student("Nikhil ", 64); 
// let s2 = new Student("Ram ", 42); 

// s1.introduce(); 

// s2.introduce();  



// class Car {
//   constructor(model, year) {
//     this.model = model;
//     this.year = year;
//   }

//   displayInfo() {
//     console.log(`This car is a ${this.year} ${this.model}.`);
//   }
// }

// const myCar = new Car("Toyota", 2022);

// myCar.displayInfo(); 


// try {
//   let sum = y + 1; // error

// } catch(e) {

//   console.log("Error occurred:", e.message);
// }


try {
		let a = 1;
		let b = a + z;
} 
catch(err) {
		console.log("Error is: " + err.message);
}