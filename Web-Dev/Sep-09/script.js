// DOM Manipulation


// Accessing elements :

// let btn1 = document.getElementById('btn1');
console.log(btn1);

let title = document.getElementById('title')
console.log('title: ', title);

let desc = document.getElementsByClassName('description')
console.log('desc: ', desc[0]);


// queryselector

let title = document.querySelector("#title")
console.log(title);

let desc = document.querySelector(".description")
console.log(desc);



// addEventListener

let btn3 = document.querySelector("#btn3");
console.log(btn3);

btn3.addEventListener("click",function(){
    console.log("btn3 is clicked");
})

let btn2 = document.querySelector("#btn2");

btn2.addEventListener("mouseover",function(){
    console.log("mouse over btn2");
})




// Modifying / Manipulation DOM

// let title = document.querySelector("#title");
console.log('title: ', title);

// // modify the text inside an element
title.innerHTML = "Apple";

// // access
let btn1 = document.querySelector("#btn1");
btn1.innerText = "submit";


title.style.backgroundColor = "yellow"
title.style.padding = "20px"










