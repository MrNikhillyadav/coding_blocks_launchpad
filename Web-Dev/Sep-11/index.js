const express = require('express');

const app = express();

//api route
app.get('/',(req,res)=> {

    res.json({
        message : "I am healthy"
    })
})


//localhost:3000/todo
app.get('/todo',(req,res)=> {
    //logic....

    res.json({
        message : "these are your todos"
    })
})

// METHODS : get, post, delete, put
app.post('/todo',(req,res)=> {
    //logic....

    res.json({
        message : "these are your todos"
    })
})


app.delete('/todo',(req,res)=> {
    //logic....

    res.json({
        message : "these are your todos"
    })
})


app.listen(3000,()=> {
    console.log("server is running on port 3000")
})