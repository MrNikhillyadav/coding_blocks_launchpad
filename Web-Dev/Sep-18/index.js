const express = require('express')
const cors = require('cors')
const app = express()

app.use(cors());

//localhost:3000/
app.get('/health', (req, res) => {

  res.json({
    message :"server is healthy"
  })
})

//localhost:3000/todo
app.post('/todo', (req, res) => {
      // logic for posting todo....

  res.json({
    message :"todo added"
  })

})

app.get('/todo', (req, res) => {
    // logic for fetching todo....

  res.json({
    message :"todo is recieved"
  })

})

app.delete('/todo/:id', (req, res) => {
    // logic for fetching todo....

  res.json({
    message :"todo is deleted"
  })

})

app.put('/todo/:id', (req, res) => {
    // logic for fetching todo....

  res.json({
    message :"todo is updated"
  })

})



app.listen(3000, () => {
  console.log(`Example app listening on port 3000`)
})
