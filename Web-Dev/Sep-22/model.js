const mongoose = require("mongoose");

// Step 1 : Creating a schema
const todo = new mongoose.Schema({
    title : String,
    done : Boolean
})

// Step 2 : Creating a model
const TodoModel = mongoose.model("Todo",todo);

// Step 3 : Exporting the model
module.exports = {
    TodoModel
}