const express = require('express')
const mongoose = require('mongoose');
const cors = require('cors');
const Jwt = require("jsonwebtoken");
const bcrypt = require("bcrypt")
const { TodoModel, UserModel } = require('./model');

const app = express()

app.use(cors());
app.use(express.json())

mongoose.connect("mongodb+srv://nikyadav20032003:e0u1Gam4rdA2ap6f@cluster0.orazjtw.mongodb.net/todo-demo")
.then(()=> {
  console.log("db connected")
})


async function auth(req, res, next) {
 const token = req.headers.token;
 try {
   const decodedPayload = await Jwt.verify(token,"JWT_SECRET");
   console.log('decodedPayload: ', decodedPayload);
 
    if(!decodedPayload){
      res.json( {
        message  : "invalid token"
      })
      return;
    }
    
    // attaching userId in request object
    req.userId = decodedPayload._id;
      next();   
 }
 catch(e){
  res.json({
    error : "error"
  })}
}


app.post('/signup', async(req,res)=> {
  const email =  req.body.email;
  const password = req.body.password;

  const hashedPassword = await bcrypt.hash(password,5);
  console.log('hashedPassword: ', hashedPassword);
  
  await UserModel.create({
    email : email,
    password : hashedPassword
  })

  res.json({
    message : "signed up"
  })
})


app.post('/signin',async(req,res)=> {
  const email = req.body.email; //john@gmail.com
  const password = req.body.password; // 12345

  try {
    // Step 1 : checked the user in the DB
    const user = await UserModel.findOne({
      email : email,
    })

    if(!user){
        res.json({
          message : "user not signed up"
        })
    }

    // step 2 : check password using bcrypt.compare()
    const decodedPassword = await bcrypt.compare(password,user.password);

    if(!decodedPassword){
      res.json({
        message : "wrong password"
      })
    }

    //step3 : sign the token using jwt.sign() method
    const token = await Jwt.sign({
      id : user._id
    },"JWT_SECRET")


    res.json({
        message : "signed in successful",
        token : token
      })

  }
  catch(e){
    res.json({
      error : "wrong credentials"
    })
  }

  


 
})


// using middleware to protect todo routes
app.use(auth)

console.log("before todo route")

app.post('/todo', async(req, res) => {
  console.log("reached todo route")

  const title = req.body.title;
  const done = req.body.done;

    await TodoModel.create({
    title : title,
    done : done
   })

  
  res.json({
    response : "added todo"
  })

})

app.put('/todo/:id', async(req, res) => {
  const todoId = req.params.id;
  const title = req.body.title;
  const done = req.body.done;
  
    await TodoModel.findByIdAndUpdate(
      todoId,
    {
    title : title,
    done : done
   })

  
  res.json({
    response : "updated todo"
  })

})

app.get('/todo', async(req, res) => {

    const todos = await TodoModel.find()

  res.json({
    response : todos
  })

})


app.delete('/todo/:id', async(req, res) => {
  const todoId = req.params.id    

    const todos = await TodoModel.deleteOne({
      _id : todoId
    })

  res.json({
    response : "todo deleted!"
  })

})


app.listen(3000, () => {
  console.log(`Example app listening on port 3000`)
})
