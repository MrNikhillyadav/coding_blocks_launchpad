// Promises

let myPromise = new Promise(function(resolve) {
		setTimeout(function() {
			resolve();
	}, 2000);
});

myPromise.then(function() {
	console.log("Data loaded"); 
});


// sleep for 5 sec
const p = new Promise(function(resolve) {
    setTimeout(() => {
        console.log("5 sec passed")
        resolve()
    },5000)
})

p.then(()=> {
    console.log("after promise resolved ")
}).catch(() => {
    console.log("error in promise")
})



function AsyncOperation(resolve){
    setTimeout(() => {
        console.log("expensive operation")
        resolve()
    },5000)
}

function callback(){
    console.log("some callback")
}

const p2 = new Promise(AsyncOperation)
p2.then(callback)


// setTimeout promisified
function setTimeoutPromisified(){
    function doAsyncOperation(resolve){
        setTimeout(() => {
            console.log('expensive call')
            resolve()
        },5000)
    }
    return new Promise(doAsyncOperation)
}

const p3 = setTimeoutPromisified()
p3.then(callback)



// Async-await examples:
function fetchData() {
    return new Promise(resolve => {
        setTimeout(() => resolve("Data loaded!"), 1000);
    });
}

fetchData()
.then(result => {
    console.log(result); 
})
.catch(function(){
console.log('error')
});

// using async-await
async function getData() {
    let result = await fetchData();
    console.log(result); 
}
getData();



// example 2:
function wait2Sec() {
    return new Promise(res => setTimeout(res, 2000));
}
async function doWait() {
    await wait2Sec();
    console.log("Done waiting!");
}
doWait();



// example 3 : fetching data

fetch('https://jsonplaceholder.typicode.com/todos/1')
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(e => console.log("Error:", e));


// using async await
async function getTodo() {
        let data= await fetch('https://jsonplaceholder.typicode.com/todos/1');
        console.log(data);
}

getTodo();


// DOM Manipulation


// Accessing elements :

let btn1 = document.getElementById('btn1');
console.log(btn1);

let title = document.getElementById('title')
console.log('title: ', title);

let desc = document.getElementsByClassName('description')
console.log('desc: ', desc);
