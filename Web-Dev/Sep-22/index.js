const express = require('express')
const mongoose = require('mongoose');
const cors = require('cors')

const app = express()

app.use(cors());
app.use(express.json())

mongoose.connect("mongodb+srv://nikyadav20032003:e0u1Gam4rdA2ap6f@cluster0.orazjtw.mongodb.net/todo-demo")
.then(()=> {
  console.log("db connected")
})
.catch((e) => {
  console.log("error connecting to database")
})




app.post('/todo', (req, res) => {

  const {title,done} = req.body;
  console.log('title: ', title);
  console.log("done",done)

  // logic to insert it to database
  
  res.json({
    title : title,
    done : done
  })

})

app.get('/todo', (req, res) => {
    // logic for fetching todo....

  res.json({
    message :"todo is recieved"
  })

})



app.listen(3000, () => {
  console.log(`Example app listening on port 3000`)
})
