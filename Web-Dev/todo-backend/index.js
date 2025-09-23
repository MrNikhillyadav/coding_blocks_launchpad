const express = require('express')
const mongoose = require('mongoose');
const cors = require('cors');
const { TodoModel, UserModel } = require('./model');

const app = express()

app.use(cors());
app.use(express.json())

mongoose.connect("mongodb+srv://nikyadav20032003:e0u1Gam4rdA2ap6f@cluster0.orazjtw.mongodb.net/todo-demo")
.then(()=> {
  console.log("db connected")
})

//# TODO: Create a signup and signin route

app.post('/signup',(req,res)=> {
 // capture this data
  const email =  req.body.email;
  const password = req.body.password;

 // store it to database
  UserModel.create({
    email : email,
    password : password
  })

  res.json({
    message : "signed up"
  })
})


app.post('/signin',async(req,res)=> {
  // capture the data
  const email = req.body.email;
  const password = req.body.password;

  // verify
  try {
    const user = await UserModel.findOne({
      email : email,
      password : password
    })

    if(!user){
        res.json({
          message : "wrong credentials"
        })
    }

    res.json({
        message : "signed in successful"
      })

  }
  catch(e){
    res.json({
      error : "error"
    })
  }

  


 
})


app.post('/todo', async(req, res) => {

  const title = req.body.title;
  const done = req.body.done;

    await TodoModel.create({
    title : title,
    done : done
   })

  
  res.json({
    message : "added todo"
  })

})

app.get('/todo', async(req, res) => {

    const todos = await TodoModel.find()

  res.json({
    respnse : todos
  })

})


app.delete('/todo/:id', async(req, res) => {
  const todoId = req.params.id    

    const todos = await TodoModel.deleteOne({
      _id : todoId
    })

  res.json({
    respnse : "todo deleted!"
  })

})




app.listen(3000, () => {
  console.log(`Example app listening on port 3000`)
})
